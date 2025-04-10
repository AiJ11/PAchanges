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
    public:
        virtual ~ExprNode() = default;
        virtual void print() const = 0;  
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

// Global Variable Reference Node
class GlobalVarRefNode : public ExprNode {
public:
    string name;
    GlobalVarRefNode(const string &n);
    void print() const override;
};

// Binary Operation Node
class BinaryOpNode : public ExprNode {
public:
    enum OpType { 
        ADD, SUBTRACT, MULTIPLY, DIVIDE,
        EQ, NEQ, LT, GT,
        AND_OP, OR_OP
    };
    
    OpType op;
    unique_ptr<ExprNode> left;
    unique_ptr<ExprNode> right;
    
    BinaryOpNode(OpType operation, unique_ptr<ExprNode> leftExpr, unique_ptr<ExprNode> rightExpr);
    void print() const override;
};

// Map Access Node (e.g., U[uid])
class MapAccessNode : public ExprNode {
    public:
        MapAccessNode(const string& mapName, unique_ptr<ExprNode> keyExpr);
        void print() const override;
    private:
        string name;
        unique_ptr<ExprNode> key;
    };

// Map Update Node (e.g., U[uid -> p])
class MapUpdateNode : public ExprNode {
public:
    string mapName;
    unique_ptr<ExprNode> key;
    unique_ptr<ExprNode> value;
    
    MapUpdateNode(const string &map, unique_ptr<ExprNode> index, unique_ptr<ExprNode> val);
    void print() const override;
};

// Set Operation Node (e.g., L union {uid})
class SetOpNode : public ExprNode {
public:
    enum OpType { UNION, INTERSECTION, DIFFERENCE, IN };
    OpType op;
    unique_ptr<ExprNode> left;
    unique_ptr<ExprNode> right;
    
    SetOpNode(OpType operation, unique_ptr<ExprNode> leftExpr, unique_ptr<ExprNode> rightExpr);
    void print() const override;
};

// Type Expression Node
class TypeExprNode : public ExprNode {
public:
    string type;
    TypeExprNode(const string &t);
    void print() const override;
};

// Map Type Node
class MapTypeNode : public TypeExprNode {
public:
    string keyType;
    string valueType;
    
    MapTypeNode(const string &key, const string &value);
    void print() const override;
};

// Set Type Node
class SetTypeNode : public TypeExprNode {
public:
    string elementType;
    
    SetTypeNode(const string &elemType);
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

// API Call Node
class APICallNode : public ASTNode {
public:
    unique_ptr<FuncCallNode> funcCall;
    
    APICallNode(unique_ptr<FuncCallNode> call);
    void print() const override;
};

// HTTP Response Code Node
class ResponseNode : public ExprNode {
public:
    unique_ptr<ExprNode> responseExpr;
    string httpCode;
    ResponseNode(unique_ptr<ExprNode> resp, const string &code);
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

// Set Element List Node (for initializing sets of values)
class SetElementListNode : public ExprNode {
public:
    vector<string> elements;
    
    SetElementListNode(const vector<string> &elems);
    void print() const override;
};

// Nested Set Type Node
class NestedSetTypeNode : public TypeExprNode {
public:
    string baseType;
    
    NestedSetTypeNode(const string &base);
    void print() const override;
};

// Nested Set List Node (for initializing sets of sets)
class NestedSetListNode : public ExprNode {
public:
    vector<unique_ptr<SetElementListNode>> setElements;
    
    NestedSetListNode();
    void addSet(unique_ptr<SetElementListNode> set);
    void print() const override;
};

// Global Variable Node
class GlobalVarNode : public ASTNode {
public:
    string name;
    unique_ptr<TypeExprNode> type;
    unique_ptr<ExprNode> initialValue; // Can be null if not initialized
    
    GlobalVarNode(const string &n, unique_ptr<TypeExprNode> t = nullptr, unique_ptr<ExprNode> init = nullptr);
    void print() const override;
};

// Map Declaration Node
class MapDeclNode : public ASTNode {
public:
    string mapName;
    unique_ptr<MapTypeNode> mapType;
    
    // Constructor for map declarations
    MapDeclNode(const string &name, unique_ptr<MapTypeNode> type);
    
    void print() const override;
};

// API Specification Node
class ApiSpecNode : public ASTNode {
public:
    string name;
    unique_ptr<ExprNode> precondition;
    unique_ptr<FuncCallNode> apiCall;
    unique_ptr<ExprNode> result;
    unique_ptr<ExprNode> postcondition;
    
    ApiSpecNode(const string &n, 
               unique_ptr<ExprNode> pre, 
               unique_ptr<FuncCallNode> call,
               unique_ptr<ExprNode> res,
               unique_ptr<ExprNode> post);
    void print() const override;
};

// Specification Node (root node)
class SpecNode : public ASTNode {
public:
    vector<unique_ptr<FuncDeclNode>> functions;
    vector<unique_ptr<BlockNode>> blocks;
    vector<unique_ptr<GlobalVarNode>> globals;
    vector<unique_ptr<MapDeclNode>> maps;
    vector<unique_ptr<ApiSpecNode>> apiSpecs;
    
    SpecNode(
        vector<unique_ptr<FuncDeclNode>> funcs = {}, 
        vector<unique_ptr<BlockNode>> blks = {},
        vector<unique_ptr<GlobalVarNode>> globs = {},
        vector<unique_ptr<MapDeclNode>> mapDecls = {},
        vector<unique_ptr<ApiSpecNode>> specs = {}
    );
    
    void print() const override;
};

// Set Literal Node (for {expr} expressions)
class SetLiteralNode : public ExprNode {
    public:
        vector<unique_ptr<ExprNode>> elements;
        
        // For single element set
        SetLiteralNode(unique_ptr<ExprNode> elem);
        
        // For multi-element set
        SetLiteralNode(vector<unique_ptr<ExprNode>> elems);
        
        void print() const override;
    };
    
    // Constructor Node (for Program{id, name} expressions)
    class ConstructorNode : public ExprNode {
    public:
        string typeName;
        vector<unique_ptr<ExprNode>> arguments;
        
        ConstructorNode(const string &type, vector<unique_ptr<ExprNode>> args);
        void print() const override;
    };
    // Property Access Node (for program.id, etc.)
    class PropertyAccessNode : public ExprNode {
    public:
        string objectName;
        string propertyName;
        
        PropertyAccessNode(const string &obj, const string &prop);
        void print() const override;
    };
    
    class StringLiteralNode : public ExprNode {
        std::string value;
    public:
        StringLiteralNode(const std::string& val) : value(val) {}
        void print() const override {
            std::cout << "StringLiteral(" << value << ")";
        }
    };
    

    // Exists Node (for exists x in S s.t. <condition>)
    class ExistsNode : public ExprNode {
    public:
        string varName;
        string setName;
        unique_ptr<ExprNode> condition;
        
        ExistsNode(const string &var, const string &set, unique_ptr<ExprNode> cond);
        void print() const override;
    };

#endif // AST_HH
