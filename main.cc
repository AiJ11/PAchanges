#include <iostream>
#include <fstream>
#include "ast.hh"
#include "parser.tab.hh"

// Define the input_stream variable
std::istream* input_stream = &std::cin; // Default to standard input

extern int yyparse();
extern unique_ptr<SpecNode> root;
extern char* yytext; // Current lexeme
extern int yylex(); // Get next token

std::ifstream file_input;

// For debugging - map token numbers to names
const char* token_name(int token) {
  switch(token) {
      case IDENTIFIER: return "IDENTIFIER";
      case NUMBER: return "NUMBER";
      case STRING: return "STRING";
      case INT: return "INT";
      case HTTP_RESPONSE_CODE: return "HTTP_RESPONSE_CODE";
      case HTTP_OK: return "HTTP_OK";
      case OK: return "OK";
      case LPAREN: return "LPAREN";
      case RPAREN: return "RPAREN";
      case LBRACKET: return "LBRACKET";
      case RBRACKET: return "RBRACKET";
      case LBRACE: return "LBRACE";
      case RBRACE: return "RBRACE";
      case COMMA: return "COMMA";
      case COLON: return "COLON";
      case ARROW: return "ARROW";
      case EQUALS: return "EQUALS";
      case IMPL_ARROW: return "IMPL_ARROW";
      case PRECONDITION: return "PRECONDITION";
      case POSTCONDITION: return "POSTCONDITION";
      case PRIME: return "PRIME";
      case AND: return "AND";
      case UNION: return "UNION";
      case IN: return "IN";
      case DOT: return "DOT";
      case UNKNOWN: return "UNKNOWN";
      case 0: return "END_OF_FILE";
      default: return "UNKNOWN_TOKEN";
  }
}

int main(int argc, char* argv[]) {
  int debug_level = 0; // 0=none, 1=basic, 2=verbose
  
  // Parse command line arguments
  if (argc > 2 && strcmp(argv[2], "--debug") == 0) {
    debug_level = 1;
  } else if (argc > 2 && strcmp(argv[2], "--verbose") == 0) {
    debug_level = 2;
  }

  if (argc > 1) {
    file_input.open(argv[1]); // Open input file if provided
    if (!file_input) {
      std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
      return 1;
    }
    input_stream = &file_input; // Set input stream to file
  }

  // Always show token debug info - REMOVED THE CONDITION
  std::cout << "DEBUG: Printing all tokens from input:\n";
  int token;
  while ((token = yylex()) != 0) {
    std::cout << "Token: " << token_name(token) << " (" << token << ") - Text: " << yytext << std::endl;
  }
  
  // Reopen the file for actual parsing
  if (argc > 1) {
    file_input.close();
    file_input.open(argv[1]);
    input_stream = &file_input;
  }
  
  // Parse the input
  int parseResult = yyparse();

  if (parseResult == 0 && root) { // 0 indicates successful parsing
    std::cout << "\nAbstract Syntax:\n";
    root->print();
  } else {
    std::cout << "Parsing failed! No AST generated.\n";
  }
  
  return 0;
}
