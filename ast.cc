#include "ast.hh"
using namespace std;

// Variable Node
VarNode::VarNode(const string &n) : name(n) {}
void VarNode::print() const { cout << name; }

// Number Node
NumNode::NumNode(int v) : value(v) {}
void NumNode::print() const { cout << value; }

// Global Variable Reference Node
GlobalVarRefNode::GlobalVarRefNode(const string &n) : name(n) {}
void GlobalVarRefNode::print() const { cout << name; }

// Binary Operation Node
BinaryOpNode::BinaryOpNode(OpType operation, unique_ptr<ExprNode> leftExpr, unique_ptr<ExprNode> rightExpr)
    : op(operation), left(std::move(leftExpr)), right(std::move(rightExpr)) {}

void BinaryOpNode::print() const {
    cout << "(";
    left->print();
    
    switch (op) {
        case ADD: cout << " + "; break;
        case SUBTRACT: cout << " - "; break;
        case MULTIPLY: cout << " * "; break;
        case DIVIDE: cout << " / "; break;
        case EQ: cout << " = "; break;
        case NEQ: cout << " != "; break;
        case LT: cout << " < "; break;
        case GT: cout << " > "; break;
        case AND_OP: cout << " AND "; break;
        case OR_OP: cout << " OR "; break;
    }
    
    right->print();
    cout << ")";
}

// Map Access Node
MapAccessNode::MapAccessNode(const string& mapName, unique_ptr<ExprNode> keyExpr)
    : name(mapName), key(std::move(keyExpr)) {}

    void MapAccessNode::print() const {
        std::cout << name << "[";
        if (key) key->print();  // Safe check for null
        std::cout << "]";
    }

// Map Update Node
MapUpdateNode::MapUpdateNode(const string &map, unique_ptr<ExprNode> index, unique_ptr<ExprNode> val)
    : mapName(map), key(std::move(index)), value(std::move(val)) {}

void MapUpdateNode::print() const {
    cout << mapName << "[";
    key->print();
    cout << " -> ";
    value->print();
    cout << "]";
}

// Set Operation Node
SetOpNode::SetOpNode(OpType operation, unique_ptr<ExprNode> leftExpr, unique_ptr<ExprNode> rightExpr)
    : op(operation), left(std::move(leftExpr)), right(std::move(rightExpr)) {}

void SetOpNode::print() const {
    left->print();
    switch (op) {
        case UNION: cout << " union "; break;
        case INTERSECTION: cout << " intersection "; break;
        case DIFFERENCE: cout << " - "; break;
        case IN: cout << " in "; break;
    }
    right->print();
}

// Function Call Node
FuncCallNode::FuncCallNode(const string &name, vector<unique_ptr<ExprNode>> args)
 : funcName(name), arguments(std::move(args)) {}

void FuncCallNode::print() const {
    cout << funcName << "(";
    for (size_t i = 0; i < arguments.size(); ++i) {
        if (arguments[i]) {
            arguments[i]->print();
        } else {
            cout << "null";
        }
        if (i < arguments.size() - 1) cout << ", ";
    }
    cout << ")";
}

// API Call Node
APICallNode::APICallNode(unique_ptr<FuncCallNode> call)
 : funcCall(std::move(call)) {}

void APICallNode::print() const {
    cout << "APICall: ";
    if (funcCall) {
        funcCall->print();
    } else {
        cout << "null function call";
    }
}

// Type Expression Node
TypeExprNode::TypeExprNode(const string &t) : type(t) {}
void TypeExprNode::print() const { cout << type; }

// Map Type Node
MapTypeNode::MapTypeNode(const string &key, const string &value)
    : TypeExprNode("map"), keyType(key), valueType(value) {}

void MapTypeNode::print() const {
    cout << "(" << keyType << " -> " << valueType << ") map";
}

// Set Type Node
SetTypeNode::SetTypeNode(const string &elemType)
    : TypeExprNode("set"), elementType(elemType) {}

void SetTypeNode::print() const {
    cout << elementType << " set";
}

// Nested Set Type Node
NestedSetTypeNode::NestedSetTypeNode(const string &base)
    : TypeExprNode("set set"), baseType(base) {}

void NestedSetTypeNode::print() const {
    cout << baseType << " set set";
}

// HTTP Response Node
ResponseNode::ResponseNode(unique_ptr<ExprNode> resp, const string &code)
 : responseExpr(std::move(resp)), httpCode(code) {}

void ResponseNode::print() const {
    cout << "Response: ";
    if (responseExpr) {
        responseExpr->print();
    } else {
        cout << "null";
    }
    cout << ", HTTP Code: " << httpCode;
}

// Block Node
BlockNode::BlockNode(unique_ptr<ExprNode> pre, unique_ptr<APICallNode> call, unique_ptr<ResponseNode> resp)
 : precondition(std::move(pre)), apiCall(std::move(call)), response(std::move(resp)) {}

void BlockNode::print() const {
    cout << "Block {" << endl;
    cout << " Precondition: ";
    if (precondition) {
        precondition->print();
    } else {
        cout << "none";
    }
    cout << endl;
    
    if (apiCall) {
        apiCall->print();
    } else {
        cout << "No API call";
    }
    cout << endl;
    
    if (response) {
        response->print();
    } else {
        cout << "No response";
    }
    cout << endl << "}" << endl;
}

// Function Declaration Node
FuncDeclNode::FuncDeclNode(const string &name, const string &param, const string &ret)
 : funcName(name), paramType(param), returnType(ret) {}

void FuncDeclNode::print() const {
    cout << "Function " << funcName << "(" << paramType << ") -> " << returnType;
}

// Set Element List Node
SetElementListNode::SetElementListNode(const vector<string> &elems)
    : elements(elems) {}

void SetElementListNode::print() const {
    cout << "{ ";
    for (size_t i = 0; i < elements.size(); ++i) {
        cout << elements[i];
        if (i < elements.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }";
}

// Nested Set List Node
NestedSetListNode::NestedSetListNode() {}

void NestedSetListNode::addSet(unique_ptr<SetElementListNode> set) {
    setElements.push_back(std::move(set));
}

void NestedSetListNode::print() const {
    cout << "{" << endl;
    for (size_t i = 0; i < setElements.size(); ++i) {
        cout << "  ";
        setElements[i]->print();
        if (i < setElements.size() - 1) {
            cout << "," << endl;
        }
    }
    cout << endl << "}";
}

// Global Variable Node
GlobalVarNode::GlobalVarNode(const string &n, unique_ptr<TypeExprNode> t, unique_ptr<ExprNode> init)
    : name(n), type(std::move(t)), initialValue(std::move(init)) {}

void GlobalVarNode::print() const {
    cout << "Global Variable: " << name;
    if (type) {
        cout << " : ";
        type->print();
    }
    if (initialValue) {
        cout << " = ";
        initialValue->print();
    }
}

// Map Declaration Node
MapDeclNode::MapDeclNode(const string &name, unique_ptr<MapTypeNode> type)
    : mapName(name), mapType(std::move(type)) {}

void MapDeclNode::print() const {
    cout << "MapDecl: " << mapName << " : ";
    mapType->print();
}

// API Specification Node
ApiSpecNode::ApiSpecNode(const string &n, 
                       unique_ptr<ExprNode> pre, 
                       unique_ptr<FuncCallNode> call,
                       unique_ptr<ExprNode> res,
                       unique_ptr<ExprNode> post)
    : name(n), precondition(std::move(pre)), apiCall(std::move(call)), 
      result(std::move(res)), postcondition(std::move(post)) {}

void ApiSpecNode::print() const {
    cout << "API Specification: " << name << endl;
    cout << "  PRECONDITION: ";
    if (precondition) {
        precondition->print();
    } else {
        cout << "none";
    }
    cout << endl << "  ";
    
    if (apiCall) {
        apiCall->print();
    } else {
        cout << "No API call";
    }
    
    cout << " ==> ";
    
    if (result) {
        result->print();
    } else {
        cout << "No result";
    }
    
    cout << endl << "  POSTCONDITION: ";
    
    if (postcondition) {
        postcondition->print();
    } else {
        cout << "none";
    }
    
    cout << endl;
}
// Set Literal Node
SetLiteralNode::SetLiteralNode(unique_ptr<ExprNode> elem) {
    elements.push_back(std::move(elem));
}

SetLiteralNode::SetLiteralNode(vector<unique_ptr<ExprNode>> elems) 
    : elements(std::move(elems)) {}

void SetLiteralNode::print() const {
    cout << "{";
    for (size_t i = 0; i < elements.size(); ++i) {
        elements[i]->print();
        if (i < elements.size() - 1) cout << ", ";
    }
    cout << "}";
}

// Constructor Node
ConstructorNode::ConstructorNode(const string &type, vector<unique_ptr<ExprNode>> args)
    : typeName(type), arguments(std::move(args)) {}

void ConstructorNode::print() const {
    cout << typeName << "{";
    for (size_t i = 0; i < arguments.size(); ++i) {
        arguments[i]->print();
        if (i < arguments.size() - 1) cout << ", ";
    }
    cout << "}";
}
// Property Access Node
PropertyAccessNode::PropertyAccessNode(const string &obj, const string &prop)
    : objectName(obj), propertyName(prop) {}

void PropertyAccessNode::print() const {
    cout << objectName << "." << propertyName;
}

// Exists Node
ExistsNode::ExistsNode(const string &var, const string &set, unique_ptr<ExprNode> cond)
    : varName(var), setName(set), condition(std::move(cond)) {}

void ExistsNode::print() const {
    cout << "exists " << varName << " in " << setName << " s.t. ";
    condition->print();
}

// Specification Node (Root)
SpecNode::SpecNode(
    vector<unique_ptr<FuncDeclNode>> funcs, 
    vector<unique_ptr<BlockNode>> blks,
    vector<unique_ptr<GlobalVarNode>> globs,
    vector<unique_ptr<MapDeclNode>> mapDecls,
    vector<unique_ptr<ApiSpecNode>> specs
) : functions(std::move(funcs)), blocks(std::move(blks)), 
    globals(std::move(globs)), maps(std::move(mapDecls)),
    apiSpecs(std::move(specs)) {}

void SpecNode::print() const {
    cout << "Specification {" << endl;
    
    // Print function declarations
    for (const auto &func : functions) {
        func->print();
        cout << endl;
    }
    
    // Print global variables
    for (const auto &global : globals) {
        global->print();
        cout << endl;
    }
    
    // Print map declarations
    for (const auto &map : maps) {
        map->print();
        cout << endl;
    }
    
    // Print blocks
    for (const auto &block : blocks) {
        block->print();
        cout << endl;
    }
    
    // Print API specifications
    for (const auto &api : apiSpecs) {
        api->print();
        cout << endl;
    }
    
    cout << "}" << endl;
}
