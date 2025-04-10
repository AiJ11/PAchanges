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
%option noyywrap
%option yylineno
%option outfile="lexer.yy.cc" header="lexer.yy.hh"
%%
    /* Section headers */
"TYPES"            { return TYPES_HEADER; }
"GLOBAL DATA"      { return GLOBAL_DATA_HEADER; }
"APIs"             { return APIS_HEADER; }
"INITIALISATION"   { return INIT_HEADER; }
    /* Keywords (case-insensitive where applicable) */
"string"           { return STRING; }
"int"              { return INT; }
"map"              { return MAP; }
"set"              { return SET; }
"token"            { return TOKEN; }
"Token"            { return TOKEN; }
"Role"             { return ROLE; }
"Program"          { return PROGRAM; }
"type"             { return TYPE; }
"HTTPResponseCode" { return HTTP_RESPONSE_CODE; }
"HTTP_OK"          { return HTTP_OK; }
"OK"               { return OK; }          /* Added for OK token */
"NIL"              { return NIL; }         /* Added for NIL token */
"ADMIN"            { return ADMIN; }       /* Added for ADMIN role */
    /* Special patterns for case-insensitive tokens */
"exists"|[eE][xX][iI][sS][tT][sS]         { return EXISTS; }
"not_exists"|[nN][oO][tT]_[eE][xX][iI][sS][tT][sS] { return NOT_EXISTS; }
"union"|[uU][nN][iI][oO][nN]             { return UNION; }
"in"|[iI][nN]                         { return IN; }
"and"|[aA][nN][dD]                     { return AND; }
"or"|[oO][rR]                         { return OR; }
"s.t."|"s.t"                         { return SUCH_THAT; }
    /* Special keywords */
"PRECONDITION"|[pP][rR][eE][cC][oO][nN][dD][iI][tT][iI][oO][nN]     { return PRECONDITION; }
"POSTCONDITION"|[pP][oO][sS][tT][cC][oO][nN][dD][iI][tT][iI][oO][nN] { return POSTCONDITION; }
    /* Operators and symbols */
"("        { return LPAREN; }
")"        { return RPAREN; }
"<"        { return LANGLE; }
">"        { return RANGLE; }
"["        { return LBRACKET; }
"]"        { return RBRACKET; }
"{"        { return LBRACE; }
"}"        { return RBRACE; }
","        { return COMMA; }
":"        { return COLON; }
"->"       { return ARROW; }
"=>"       { return MAPARROW; }
"==>"      { return IMPL_ARROW; }
"="        { return EQUALS; }
"=="       { return EQ; }
"!="       { return NEQ; }
"+"        { return PLUS; }
"-"        { return MINUS; }
"*"        { return MULTIPLY; }
"/"        { return DIVIDE; }
"'"        { return PRIME; }
"|"        { return PIPE; }
"."        { return DOT; }
    /* Function declarations and API calls */
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = new std::string(yytext);  
    return IDENTIFIER;
}
    /* Numbers */
[0-9]+     { yylval.ival = atoi(yytext); return NUMBER; }
    /* Comments (ignore) */
"//".*     { /* Ignore single-line comments */ }
    /* Multi-line comments */
"/*"       { 
              int c;
              while((c = input_stream->get()) != EOF) {
                if(c == '*' && input_stream->peek() == '/') {
                  input_stream->get(); /* consume the '/' */
                  break;
                }
              }
           }
    /* Whitespace (ignore) */
[\t\r\n ]+ { /* Ignore whitespace */ }
    /* Catch-all for unrecognized characters */
. { 
    printf("Unknown character: '%s' (ASCII %d) at line %d\n", yytext, (int)yytext[0], yylineno); 
    return UNKNOWN; 
}
%%
