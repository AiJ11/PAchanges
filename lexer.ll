%{
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "ast.hh"
#include "parser.tab.hh"

extern std::istream* input_stream;
#define YY_INPUT(buf, result, max_size) \
    { \
        int c = input_stream->get(); \
        result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
    }

void yyerror(const char *s);

%}

    /* Define token types */
%option noyywrap
%option outfile="lexer.yy.cc" header="lexer.yy.hh"

    /* Define regular expressions for different token types */
%%

    /* Keywords */
"string"             { return STRING; }
"int"                { return INT; }
"HTTPResponseCode"   { return HTTP_RESPONSE_CODE; }
"HTTP_OK"            { return HTTP_OK; }

    /* Function declarations and API calls */
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = new std::string(yytext);  
    return IDENTIFIER;
}

    /* Symbols */
"("        { return LPAREN; }
")"        { return RPAREN; }
","        { return COMMA; }
"->"       { return ARROW; }

    /* numbers */
[0-9]+     { yylval.ival = atoi(yytext); return NUMBER; }

    /* Comments (ignore) */
"//".*     { /* Ignore single-line comments */ }

    /* multi line comments */
"/*"       { /* Start of multi-line comment */
              int c;
              while((c = input_stream->get()) != EOF) {
                if(c == '*' && input_stream->peek() == '/') {
                  input_stream->get(); /* consume the '/' */
                  break;
                }
              }
            }

    /* Whitespace (ignore) */
[\t\r\n ]+  { /* Ignore whitespace */ }

    /* Catch-all for unrecognized characters */
. { printf("Unknown character: %s\n", yytext); return UNKNOWN; }

%%


