%{
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include "ast.hh"

void yyerror(const char *s);
int yylex();
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
;

// Function Declaration
func_decl:
    IDENTIFIER LPAREN IDENTIFIER COMMA IDENTIFIER RPAREN ARROW IDENTIFIER {
        $$ = new FuncDeclNode(*$1, *$3 + ", " + *$5, *$8);
        delete $1; delete $3; delete $5; delete $8;
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
;

// Block (Precondition + API Call + Response)
block:
    IDENTIFIER api_call response {
        $$ = new BlockNode(unique_ptr<ExprNode>(new VarNode(*$1)), unique_ptr<APICallNode>($2), unique_ptr<ResponseNode>($3));
        delete $1;
    }
;

%%

// Error handling
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
