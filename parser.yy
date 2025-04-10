%{
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <unordered_set>
#include "ast.hh"
#include "lexer.yy.hh"
extern int yylineno;

void yyerror(const char *s);
int yylex();
extern char* yytext;
using namespace std;
unique_ptr<SpecNode> root; // Root node of AST

// Add a symbol table for global variables
std::unordered_set<std::string> knownGlobals = {"U", "T", "L", "P"};
%}

// Define union for token values
%union {
    int ival;                      // integer values
    std::string *sval;             // string values (identifiers)
    ExprNode *expr;                // expression nodes
    FuncCallNode *funcCall;        // function call nodes
    APICallNode *apiCall;          // API call nodes
    ResponseNode *response;        // response nodes
    BlockNode *block;              // block nodes
    FuncDeclNode *funcDecl;        // function declaration nodes
    TypeExprNode *typeExpr;        // type expression nodes
    MapTypeNode *mapType;          // map type nodes
    SetTypeNode *setType;          // set type nodes
    GlobalVarNode *globalVar;      // global variable nodes
    MapDeclNode *mapDecl;          // map declaration nodes
    SetElementListNode *setElems;  // set element list nodes
    NestedSetListNode *nestedSet;  // nested set list nodes
    ApiSpecNode *apiSpec;          // API specification nodes
    SpecNode *spec;                // specification nodes
    ASTNode *node;                 // base class for any AST node
}

// Define token types
%token <sval> IDENTIFIER                //var,func names etc
%token <ival> NUMBER
%token STRING INT MAP TOKEN ROLE PROGRAM TYPE
%token HTTP_RESPONSE_CODE HTTP_OK NIL
%token OK
%token LPAREN RPAREN LANGLE RANGLE LBRACKET RBRACKET LBRACE RBRACE
%token COMMA COLON ARROW MAPARROW IMPL_ARROW EQUALS
%token PLUS MINUS MULTIPLY DIVIDE EQ NEQ            //logical operators
%token UNION IN AND OR SUCH_THAT NOT_EXISTS
%token PRIME PIPE UNKNOWN
%token TYPES_HEADER GLOBAL_DATA_HEADER APIS_HEADER INIT_HEADER
%token PRECONDITION POSTCONDITION SET
%token ADMIN
%token DOT EXISTS FACULTY APPLICATION PROFILE_DATA REFERRAL PENDING 

// Define non-terminals and their types
%type <spec> start
%type <expr> expr set_expr map_access map_update
%type <funcCall> func_call
%type <apiCall> api_call
%type <apiSpec> api_spec
%type <response> response result_expr
%type <block> block
%type <funcDecl> func_decl
%type <typeExpr> type_expr
%type <mapType> map_type
%type <setType> set_type
%type <node> global_decl
%type <globalVar> global_var
%type <setElems> element_list set_init
%type <nestedSet> nested_set_init set_init_list
%type <expr> precondition_expr postcondition_expr
%type <response> api_response
%type <funcCall> api_function_call

// Precedence rules
%left OR
%left AND
%left EQUALS EQ NEQ
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left MAPARROW
%left ARROW

%%

// Start rule that initializes the specification
start:
    /* empty */ {
        // Initialize with empty vectors
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
    | start func_decl {
        // Add function declaration to the root
        root->functions.push_back(unique_ptr<FuncDeclNode>($2));
    }
    | start block {
        // Add block to the root
        root->blocks.push_back(unique_ptr<BlockNode>($2));
    }
    | start global_decl {
        // Handle based on actual type
        if (auto mapDecl = dynamic_cast<MapDeclNode*>($2)) {
            root->maps.push_back(unique_ptr<MapDeclNode>(mapDecl));
        } else if (auto varDecl = dynamic_cast<GlobalVarNode*>($2)) {
            root->globals.push_back(unique_ptr<GlobalVarNode>(varDecl));
        }
    }
    | start api_spec {
        // Add API specification to root
        root->apiSpecs.push_back(unique_ptr<ApiSpecNode>($2));
    }
    | start global_var {
        // Add global variable to the root
        root->globals.push_back(unique_ptr<GlobalVarNode>($2));
    }
    | func_decl {
        // Start directly with a function declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        functions.push_back(unique_ptr<FuncDeclNode>($1));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
    | block {
        // Start directly with a block
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        blocks.push_back(unique_ptr<BlockNode>($1));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
    | global_decl {
        // Start with a global declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        
        if (auto mapDecl = dynamic_cast<MapDeclNode*>($1)) {
            maps.push_back(unique_ptr<MapDeclNode>(mapDecl));
        } else if (auto varDecl = dynamic_cast<GlobalVarNode*>($1)) {
            globals.push_back(unique_ptr<GlobalVarNode>(varDecl));
        }
        
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
    | api_spec {
        // Start with an API specification
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        specs.push_back(unique_ptr<ApiSpecNode>($1));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }

    | global_var {
        // Start with a global variable declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        globals.push_back(unique_ptr<GlobalVarNode>($1));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                      std::move(globals), std::move(maps), std::move(specs)));
    }
;

// Type expression (string, int, etc.)
type_expr:
    STRING { $$ = new TypeExprNode("string"); }
    | INT { $$ = new TypeExprNode("int"); }
    | HTTP_RESPONSE_CODE { $$ = new TypeExprNode("HTTPResponseCode"); }
    | TOKEN { $$ = new TypeExprNode("token"); }
    | ROLE { $$ = new TypeExprNode("Role"); }
    | PROGRAM { $$ = new TypeExprNode("Program"); }
    | IDENTIFIER { $$ = new TypeExprNode(*$1); delete $1; }
    | NUMBER { $$ = new TypeExprNode(std::to_string($1)); }
    | map_type { $$ = $1; }
    | set_type { $$ = $1; }
;

// Map type
map_type:
    LPAREN type_expr ARROW type_expr RPAREN MAP {
        // Map type: (keyType -> valueType) map
        TypeExprNode* keyType = $2;
        TypeExprNode* valueType = $4;
        $$ = new MapTypeNode(keyType->type, valueType->type);
        delete keyType;
        delete valueType;
    }
    | MAP LANGLE type_expr COMMA type_expr RANGLE {
        // Map type: map<keyType, valueType>
        TypeExprNode* keyType = $3;
        TypeExprNode* valueType = $5;
        $$ = new MapTypeNode(keyType->type, valueType->type);
        delete keyType;
        delete valueType;
    }
;

// Set type
set_type:
    type_expr SET {
        // Set type: elementType set
        TypeExprNode* elemType = $1;
        $$ = new SetTypeNode(elemType->type);
        delete elemType;
    }
;

// Function Declaration
func_decl:
    IDENTIFIER LPAREN type_expr COMMA type_expr RPAREN ARROW type_expr {
        // Get type names from type expressions
        TypeExprNode* type1 = $3;
        TypeExprNode* type2 = $5;
        TypeExprNode* returnType = $8;
        
        $$ = new FuncDeclNode(*$1, type1->type + ", " + type2->type, returnType->type);
        delete $1;
        
        // TypeExprNode objects are owned by unique_ptr after this point
        delete type1;
        delete type2;
        delete returnType;
    }
;

// Global variable declaration
global_var:
    IDENTIFIER EQUALS expr {
        $$ = new GlobalVarNode(*$1, nullptr, unique_ptr<ExprNode>($3));
        delete $1;
    }
    | IDENTIFIER {
        $$ = new GlobalVarNode(*$1);
        delete $1;
    }
;

// Global data declaration
global_decl:
    IDENTIFIER COLON map_type {
        // For declarations like: U : (string -> string) map
        std::string name = *$1;
        knownGlobals.insert(name); // Add to known globals
        $$ = new MapDeclNode(*$1, unique_ptr<MapTypeNode>($3));
        delete $1;
    }
    | IDENTIFIER COLON set_type {
        // For declarations like: L : string set
        std::string name = *$1;
        knownGlobals.insert(name); // Add to known globals
        $$ = new GlobalVarNode(*$1, unique_ptr<TypeExprNode>($3));
        delete $1;
    }
    | IDENTIFIER COLON type_expr {
        // For declarations like: P : Program
        std::string name = *$1;
        knownGlobals.insert(name); // Add to known globals
        $$ = new GlobalVarNode(*$1, unique_ptr<TypeExprNode>($3));
        delete $1;
    }
;

// Nested set initialization
nested_set_init:
    LBRACE set_init_list RBRACE {
        $$ = $2;
    }
;

// List of set initializations
set_init_list:
    set_init {
        $$ = new NestedSetListNode();
        $$->addSet(unique_ptr<SetElementListNode>($1));
    }
    | set_init_list COMMA set_init {
        $1->addSet(unique_ptr<SetElementListNode>($3));
        $$ = $1;
    }
;

// Single set initialization
set_init:
    LBRACE element_list RBRACE {
        $$ = $2;
    }
;

// List of elements in a set
element_list:
    IDENTIFIER {
        vector<string> elements;
        elements.push_back(*$1);
        $$ = new SetElementListNode(elements);
        delete $1;
    }
    | element_list COMMA IDENTIFIER {
        $1->elements.push_back(*$3);
        $$ = $1;
        delete $3;
    }
;

// Map access expression (e.g., U[uid])
map_access:
    IDENTIFIER LBRACKET expr RBRACKET {
        $$ = new MapAccessNode(*$1, unique_ptr<ExprNode>($3));
        delete $1;
    }
;

// Map update expression (e.g., U[uid -> p])
map_update:
    IDENTIFIER LBRACKET expr ARROW expr RBRACKET {
        $$ = new MapUpdateNode(*$1, unique_ptr<ExprNode>($3), unique_ptr<ExprNode>($5));
        delete $1;
    }
;

// Set expressions
set_expr:
    expr UNION LBRACE expr RBRACE {
        $$ = new SetOpNode(SetOpNode::UNION, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($4));
    }
    | expr UNION expr {
        $$ = new SetOpNode(SetOpNode::UNION, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3));
    }
;

// Result expression for API responses
result_expr:
    LPAREN OK RPAREN {
        // Handle (OK) response format
        $$ = new ResponseNode(unique_ptr<ExprNode>(new VarNode("OK")), "OK");
    }
    | LPAREN OK COMMA IDENTIFIER RPAREN {
        // Handle (OK, t) response format
        $$ = new ResponseNode(unique_ptr<ExprNode>(new VarNode("OK")), *$4);
        delete $4;
    }
    | LPAREN OK COMMA expr RPAREN {
        // Handle (OK, id) response format with expressions
        $$ = new ResponseNode(unique_ptr<ExprNode>(new VarNode("OK")), "TUPLE");
    }
;

// Precondition expression
precondition_expr:
    expr { $$ = $1; }
;

// API function call (used in API specs)
api_function_call:
    IDENTIFIER LPAREN IDENTIFIER COMMA IDENTIFIER RPAREN {
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>(new VarNode(*$3)));
        args.push_back(unique_ptr<ExprNode>(new VarNode(*$5)));
        $$ = new FuncCallNode(*$1, std::move(args));
        delete $1; delete $3; delete $5;
    }
;

// API response (used in API specs)
api_response:
    result_expr { $$ = $1; }
;

// Postcondition expression
postcondition_expr:
    expr { $$ = $1; }
;

// API Specification rule broken down into components
api_spec:
    IDENTIFIER COLON 
    PRECONDITION COLON precondition_expr
    api_function_call IMPL_ARROW api_response
    POSTCONDITION COLON postcondition_expr
    {
        // Build the API specification
        $$ = new ApiSpecNode(
            *$1,                         // API name
            unique_ptr<ExprNode>($5),    // Precondition
            unique_ptr<FuncCallNode>($6), // API function call
            unique_ptr<ExprNode>($8),    // API response
            unique_ptr<ExprNode>($11)    // Postcondition
        );
        
        delete $1;
    }
;

// Expression
expr:
    IDENTIFIER { 
        std::string name = *$1;
        if (knownGlobals.count(name) > 0) {
            // This is a known global variable
            $$ = new GlobalVarRefNode(name);
        } else {
            // This is a regular variable
            $$ = new VarNode(name);
        }
        delete $1;
    }
    | NUMBER { $$ = new NumNode($1); }
    | NIL { $$ = new VarNode("NIL"); }
    | UNKNOWN { $$ = new VarNode("NIL"); }  // Handle UNKNOWN token as NIL for flexibility
    | IDENTIFIER PRIME {
        // For variables with prime, like U'
        $$ = new VarNode(*$1 + "'");
        delete $1;
    }
    | map_access { $$ = $1; }
    | map_update { $$ = $1; }
    | set_expr { $$ = $1; }
    | IDENTIFIER DOT IDENTIFIER {
        // Property access like program.id
        $$ = new PropertyAccessNode(*$1, *$3);
        delete $1; delete $3;
    }
    | NOT_EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr {
        // Not exists quantifier
        $$ = new ExistsNode(*$2, *$4, unique_ptr<ExprNode>($6));
        // Note: We're using ExistsNode for simplicity
        // In a more comprehensive implementation, this would have a dedicated NotExistsNode
        delete $2; delete $4;
    }
    | EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr {
        // Existential quantifier: exists x in S s.t. <condition>
        $$ = new ExistsNode(*$2, *$4, unique_ptr<ExprNode>($6));
        delete $2; delete $4;
    }
    | LPAREN EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr RPAREN {
        // Parenthesized existential
        $$ = new ExistsNode(*$3, *$5, unique_ptr<ExprNode>($7));
        delete $3; delete $5;
    }
    | LPAREN NOT_EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr RPAREN {
        // Parenthesized not exists
        $$ = new ExistsNode(*$3, *$5, unique_ptr<ExprNode>($7));
        // Note: We're using ExistsNode for simplicity
        delete $3; delete $5;
    }
    // New rules for set literals and operations
    | LBRACE expr RBRACE {
        // Create a set literal node with single element
        vector<unique_ptr<ExprNode>> elements;
        elements.push_back(unique_ptr<ExprNode>($2));
        $$ = new SetLiteralNode(std::move(elements));
    }
    | LBRACE expr COMMA expr RBRACE {
        // Create a set literal node with multiple elements
        vector<unique_ptr<ExprNode>> elements;
        elements.push_back(unique_ptr<ExprNode>($2));
        elements.push_back(unique_ptr<ExprNode>($4));
        $$ = new SetLiteralNode(std::move(elements));
    }
    | expr MINUS LBRACE expr RBRACE {
        // For set difference: P - {programId}
        vector<unique_ptr<ExprNode>> elements;
        elements.push_back(unique_ptr<ExprNode>($4));
        $$ = new SetOpNode(SetOpNode::DIFFERENCE, 
                           unique_ptr<ExprNode>($1), 
                           unique_ptr<ExprNode>(new SetLiteralNode(std::move(elements))));
    }
    | IDENTIFIER LBRACE expr COMMA expr RBRACE {
        // For constructions like Program{id, programName}
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>($3));
        args.push_back(unique_ptr<ExprNode>($5));
        $$ = new ConstructorNode(*$1, std::move(args));
        delete $1;
    }
    | expr ARROW expr IN IDENTIFIER {
        // For expressions like "t -> u in T"
        // This can be interpreted as "T[t] = u"
        $$ = new BinaryOpNode(BinaryOpNode::EQ, 
                           unique_ptr<ExprNode>(new MapAccessNode(*$5, unique_ptr<ExprNode>($1))), 
                           unique_ptr<ExprNode>($3));
        delete $5;
    }
    
    | expr IN expr {
        $$ = new SetOpNode(SetOpNode::IN, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3));
    }
    | expr UNION expr { 
        $$ = new SetOpNode(SetOpNode::UNION, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr PLUS expr { 
        $$ = new BinaryOpNode(BinaryOpNode::ADD, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr MINUS expr { 
        $$ = new BinaryOpNode(BinaryOpNode::SUBTRACT, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr MULTIPLY expr { 
        $$ = new BinaryOpNode(BinaryOpNode::MULTIPLY, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr DIVIDE expr { 
        $$ = new BinaryOpNode(BinaryOpNode::DIVIDE, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr EQUALS expr { 
        $$ = new BinaryOpNode(BinaryOpNode::EQ, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr EQ expr { 
        $$ = new BinaryOpNode(BinaryOpNode::EQ, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr NEQ expr { 
        $$ = new BinaryOpNode(BinaryOpNode::NEQ, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr AND expr { 
        $$ = new BinaryOpNode(BinaryOpNode::AND_OP, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | expr OR expr { 
        $$ = new BinaryOpNode(BinaryOpNode::OR_OP, unique_ptr<ExprNode>($1), unique_ptr<ExprNode>($3)); 
    }
    | LPAREN expr RPAREN { $$ = $2; }
    | func_call { $$ = $1; }  // Allow function calls as expressions
;

// API Call
api_call:
    func_call ARROW response {
        $$ = new APICallNode(unique_ptr<FuncCallNode>($1));
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

// Response
response:
    NUMBER COMMA IDENTIFIER {
        $$ = new ResponseNode(unique_ptr<ExprNode>(new NumNode($1)), *$3);
        delete $3;
    }
    | NUMBER COMMA HTTP_OK {
        $$ = new ResponseNode(unique_ptr<ExprNode>(new NumNode($1)), "HTTP_OK");
    }
    | LPAREN expr COMMA expr RPAREN {
        // For responses like (OK, t)
        $$ = new ResponseNode(unique_ptr<ExprNode>($2), "TUPLE");
    }
;

// Block (Precondition + API Call + Response)
block:
    IDENTIFIER IDENTIFIER LPAREN expr COMMA expr RPAREN ARROW NUMBER COMMA HTTP_OK {
        // Directly match the exact pattern for the API call
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>($4));
        args.push_back(unique_ptr<ExprNode>($6));
        
        FuncCallNode* funcCall = new FuncCallNode(*$2, std::move(args));
        ResponseNode* response = new ResponseNode(unique_ptr<ExprNode>(new NumNode($9)), "HTTP_OK");
        
        $$ = new BlockNode(
            unique_ptr<ExprNode>(new VarNode(*$1)),
            unique_ptr<APICallNode>(new APICallNode(
                unique_ptr<FuncCallNode>(funcCall)
            )),
            unique_ptr<ResponseNode>(response)
        );
        
        delete $1; delete $2;
    }
    | PRECONDITION COLON expr
      IDENTIFIER LPAREN expr COMMA expr RPAREN
      IMPL_ARROW LPAREN expr COMMA expr RPAREN
      POSTCONDITION COLON expr {
        // For blocks with explicit PRECONDITION/POSTCONDITION
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>($6));
        args.push_back(unique_ptr<ExprNode>($8));
        
        FuncCallNode* funcCall = new FuncCallNode(*$4, std::move(args));
        ResponseNode* response = new ResponseNode(unique_ptr<ExprNode>($12), "TUPLE");
        
        $$ = new BlockNode(
            unique_ptr<ExprNode>($3),
            unique_ptr<APICallNode>(new APICallNode(
                unique_ptr<FuncCallNode>(funcCall)
            )),
            unique_ptr<ResponseNode>(response)
        );
        
        delete $4;
    }
;

%%

// Error handling
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at or near token '%s' (line %d)\n", s, yytext, yylineno);
}
