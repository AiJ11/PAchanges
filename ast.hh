#ifndef AST_HH
#define AST_HH
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// Base class for all AST nodes
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print() const = 0; // Print the AST structure
};

// Expression Node
class ExprNode : public ASTNode {
};

// Variable Node
class VarNode : public ExprNode {
public:
    string name;
    VarNode(const string &n);
    void print() const override;
};

// Number Node
class NumNode : public ExprNode {
public:
    int value;
    NumNode(int v);
    void print() const override;
};

// Function Call Node
class FuncCallNode : public ExprNode {
public:
    string funcName;
    vector<unique_ptr<ExprNode>> arguments;
    FuncCallNode(const string &name, vector<unique_ptr<ExprNode>> args);
    void print() const override;
};

// HTTP Response Code Node
class ResponseNode : public ExprNode {  // Changed to inherit from ExprNode
public:
    unique_ptr<ExprNode> responseExpr;
    string httpCode;
    ResponseNode(unique_ptr<ExprNode> resp, const string &code);
    void print() const override;
};

// API Call Node
class APICallNode : public ASTNode {
public:
    unique_ptr<FuncCallNode> funcCall;
    unique_ptr<ExprNode> response;
    APICallNode(unique_ptr<FuncCallNode> call, unique_ptr<ExprNode> resp);
    void print() const override;
};

// Block Node (represents a complete API block)
class BlockNode : public ASTNode {
public:
    unique_ptr<ExprNode> precondition;
    unique_ptr<APICallNode> apiCall;
    unique_ptr<ResponseNode> response;
    BlockNode(unique_ptr<ExprNode> pre, unique_ptr<APICallNode> call, unique_ptr<ResponseNode> resp);
    void print() const override;
};

// Function Declaration Node
class FuncDeclNode : public ASTNode {
public:
    string funcName;
    string paramType;
    string returnType;
    FuncDeclNode(const string &name, const string &param, const string &ret);
    void print() const override;
};

// Type Expression Node
class TypeExprNode : public ASTNode {
public:
    string type;
    TypeExprNode(const string &t);
    void print() const override;
};

// Specification Node (root node)
class SpecNode : public ASTNode {
public:
    vector<unique_ptr<FuncDeclNode>> functions;
    vector<unique_ptr<BlockNode>> blocks;
    SpecNode(vector<unique_ptr<FuncDeclNode>> funcs, vector<unique_ptr<BlockNode>> blks);
    void print() const override;
};
#endif // AST_HH
