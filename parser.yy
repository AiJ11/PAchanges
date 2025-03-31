%{
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include "ast.hh"

void yyerror(const char *s);
int yylex();
extern char* yytext;  // Add this line to declare yytext
using namespace std;
unique_ptr<SpecNode> root; // Root node of AST
%}

// Define union for token values
%union {
    int ival;
    std::string *sval;
    ExprNode *expr;
    FuncCallNode *funcCall;
    APICallNode *apiCall;
    ResponseNode *response;
    BlockNode *block;
    FuncDeclNode *funcDecl;
    TypeExprNode *typeExpr;
    SpecNode *spec;
}

// Define token types
%token <sval> IDENTIFIER
%token <ival> NUMBER
%token STRING INT HTTP_RESPONSE_CODE HTTP_OK
%token LPAREN RPAREN COMMA ARROW UNKNOWN

// Define non-terminals and their types
%type <expr> expr
%type <funcCall> func_call
%type <apiCall> api_call
%type <response> response
%type <block> block
%type <funcDecl> func_decl
%type <expr> type_expr

%left ARROW

%%

// Start rule that initializes the specification
start:
    /* empty */ {
        // Initialize with empty vectors
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        root = make_unique<SpecNode>(std::move(functions), std::move(blocks));
    }
    | start func_decl {
        // Add function declaration to the root
        root->functions.push_back(unique_ptr<FuncDeclNode>($2));
    }
    | start block {
        // Add block to the root
        root->blocks.push_back(unique_ptr<BlockNode>($2));
    }
    | func_decl {
        // Start directly with a function declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        functions.push_back(unique_ptr<FuncDeclNode>($1));
        root = make_unique<SpecNode>(std::move(functions), std::move(blocks));
    }
    | block {
        // Start directly with a block
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        blocks.push_back(unique_ptr<BlockNode>($1));
        root = make_unique<SpecNode>(std::move(functions), std::move(blocks));
    }
;

// Type expression (string, int, etc. or type variables)
type_expr:
    STRING { $$ = new TypeExprNode("string"); }
    | INT { $$ = new TypeExprNode("int"); }
    | HTTP_RESPONSE_CODE { $$ = new TypeExprNode("HTTPResponseCode"); }
    | IDENTIFIER { $$ = new TypeExprNode(*$1); delete $1; }  // doubt if i can add identifiers as type?
    | NUMBER { $$ = new TypeExprNode(std::to_string($1)); }  // to accept numbers in parameters 
;

// Function Declaration
func_decl:
    IDENTIFIER LPAREN type_expr COMMA type_expr RPAREN ARROW IDENTIFIER {
        // Get type names from type expressions
        TypeExprNode* type1 = static_cast<TypeExprNode*>($3);
        TypeExprNode* type2 = static_cast<TypeExprNode*>($5);
        
        $$ = new FuncDeclNode(*$1, type1->type + ", " + type2->type, *$8);
        delete $1; delete $8;
        
        // TypeExprNode objects are owned by unique_ptr after this point
        delete type1;
        delete type2;
    }
    | IDENTIFIER LPAREN type_expr COMMA type_expr RPAREN ARROW type_expr {
        // Get type names from type expressions
        TypeExprNode* type1 = static_cast<TypeExprNode*>($3);
        TypeExprNode* type2 = static_cast<TypeExprNode*>($5);
        TypeExprNode* returnType = static_cast<TypeExprNode*>($8);
        
        $$ = new FuncDeclNode(*$1, type1->type + ", " + type2->type, returnType->type);
        delete $1;
        
        // TypeExprNode objects are owned by unique_ptr after this point
        delete type1;
        delete type2;
        delete returnType;
    }
;

// API Call
api_call:
    func_call ARROW response {
        $$ = new APICallNode(unique_ptr<FuncCallNode>($1), unique_ptr<ExprNode>($3));
    }
;

// Function Call
func_call:
    IDENTIFIER LPAREN expr COMMA expr RPAREN {
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>($3));
        args.push_back(unique_ptr<ExprNode>($5));
        $$ = new FuncCallNode(*$1, std::move(args));
        delete $1;
    }
;

// Expression (Variables and Numbers)
expr:
    IDENTIFIER { $$ = new VarNode(*$1); delete $1; }
  | NUMBER { $$ = new NumNode($1); }
;

// Response
response:
    NUMBER COMMA IDENTIFIER {
        $$ = new ResponseNode(unique_ptr<ExprNode>(new NumNode($1)), *$3);
        delete $3;
    }
    | NUMBER COMMA HTTP_OK {
        $$ = new ResponseNode(unique_ptr<ExprNode>(new NumNode($1)), "HTTP_OK");
    }
;

// Block (Precondition + API Call + Response)
block:
    IDENTIFIER IDENTIFIER LPAREN IDENTIFIER COMMA IDENTIFIER RPAREN ARROW NUMBER COMMA HTTP_OK {
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>(new VarNode(*$4)));
        args.push_back(unique_ptr<ExprNode>(new VarNode(*$6)));
        
        FuncCallNode* funcCall = new FuncCallNode(*$2, std::move(args));
        ResponseNode* response = new ResponseNode(unique_ptr<ExprNode>(new NumNode($9)), "HTTP_OK");
        
        $$ = new BlockNode(
            unique_ptr<ExprNode>(new VarNode(*$1)),
            unique_ptr<APICallNode>(new APICallNode(
                unique_ptr<FuncCallNode>(funcCall)
            )),
            unique_ptr<ResponseNode>(response)
        );
        
        delete $1; delete $2; delete $4; delete $6;
    }
;

%%

// Error handling
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at or near token '%s'\n", s, yytext);
}
