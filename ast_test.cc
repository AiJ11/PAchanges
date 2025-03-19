#include "ast.hh"

int main() {
    // Creating a simple API Call manually for testing
    auto funcArgs = vector<unique_ptr<ExprNode>>();
    funcArgs.push_back(make_unique<VarNode>("userID"));
    funcArgs.push_back(make_unique<VarNode>("password"));

    auto funcCall = make_unique<FuncCallNode>("login", std::move(funcArgs));
    auto response = make_unique<NumNode>(200);  // HTTP 200 OK
    auto apiCall = make_unique<APICallNode>(std::move(funcCall), std::move(response));

    // Creating a response
    auto httpResponse = make_unique<ResponseNode>(make_unique<NumNode>(200), "HTTP_OK");

    // Creating a block (precondition, API call, response)
    auto precondition = make_unique<VarNode>("isAuthenticated");
    auto block = make_unique<BlockNode>(std::move(precondition), std::move(apiCall), std::move(httpResponse));

    // Creating a function declaration
    auto funcDecl = make_unique<FuncDeclNode>("login", "string, string", "HTTPResponseCode");

    // Creating a specification (Root Node)
    vector<unique_ptr<FuncDeclNode>> functions;
    functions.push_back(std::move(funcDecl));

    vector<unique_ptr<BlockNode>> blocks;
    blocks.push_back(std::move(block));

    auto spec = make_unique<SpecNode>(std::move(functions), std::move(blocks));

    // Printing AST
    spec->print();

    return 0;
}
