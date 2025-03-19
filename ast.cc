#include "ast.hh"

using namespace std;

// Variable Node
VarNode::VarNode(const string &n) : name(n) {}
void VarNode::print() const { cout << name; }

// Number Node
NumNode::NumNode(int v) : value(v) {}
void NumNode::print() const { cout << value; }

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
 : funcCall(std::move(call)) {}  // No response field
void APICallNode::print() const {
    cout << "APICall: ";
    if (funcCall) {
        funcCall->print();
    } else {
        cout << "null function call";
    }
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

// Type Expression Node
TypeExprNode::TypeExprNode(const string &t) : type(t) {}
void TypeExprNode::print() const { cout << type; }

// Specification Node (Root)
SpecNode::SpecNode(vector<unique_ptr<FuncDeclNode>> funcs, vector<unique_ptr<BlockNode>> blks)
    : functions(std::move(funcs)), blocks(std::move(blks)) {}

void SpecNode::print() const {
    cout << "Specification {" << endl;
    for (const auto &func : functions) {
        func->print();
        cout << endl;
    }
    for (const auto &block : blocks) {
        block->print();
        cout << endl;
    }
    cout << "}" << endl;
}
