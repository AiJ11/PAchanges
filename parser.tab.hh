/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    NUMBER = 259,                  /* NUMBER  */
    STRING = 260,                  /* STRING  */
    INT = 261,                     /* INT  */
    MAP = 262,                     /* MAP  */
    TOKEN = 263,                   /* TOKEN  */
    ROLE = 264,                    /* ROLE  */
    PROGRAM = 265,                 /* PROGRAM  */
    TYPE = 266,                    /* TYPE  */
    HTTP_RESPONSE_CODE = 267,      /* HTTP_RESPONSE_CODE  */
    HTTP_OK = 268,                 /* HTTP_OK  */
    NIL = 269,                     /* NIL  */
    OK = 270,                      /* OK  */
    LPAREN = 271,                  /* LPAREN  */
    RPAREN = 272,                  /* RPAREN  */
    LANGLE = 273,                  /* LANGLE  */
    RANGLE = 274,                  /* RANGLE  */
    LBRACKET = 275,                /* LBRACKET  */
    RBRACKET = 276,                /* RBRACKET  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    COMMA = 279,                   /* COMMA  */
    COLON = 280,                   /* COLON  */
    ARROW = 281,                   /* ARROW  */
    MAPARROW = 282,                /* MAPARROW  */
    IMPL_ARROW = 283,              /* IMPL_ARROW  */
    EQUALS = 284,                  /* EQUALS  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    MULTIPLY = 287,                /* MULTIPLY  */
    DIVIDE = 288,                  /* DIVIDE  */
    EQ = 289,                      /* EQ  */
    NEQ = 290,                     /* NEQ  */
    UNION = 291,                   /* UNION  */
    IN = 292,                      /* IN  */
    AND = 293,                     /* AND  */
    OR = 294,                      /* OR  */
    SUCH_THAT = 295,               /* SUCH_THAT  */
    NOT_EXISTS = 296,              /* NOT_EXISTS  */
    PRIME = 297,                   /* PRIME  */
    PIPE = 298,                    /* PIPE  */
    UNKNOWN = 299,                 /* UNKNOWN  */
    TYPES_HEADER = 300,            /* TYPES_HEADER  */
    GLOBAL_DATA_HEADER = 301,      /* GLOBAL_DATA_HEADER  */
    APIS_HEADER = 302,             /* APIS_HEADER  */
    INIT_HEADER = 303,             /* INIT_HEADER  */
    PRECONDITION = 304,            /* PRECONDITION  */
    POSTCONDITION = 305,           /* POSTCONDITION  */
    SET = 306,                     /* SET  */
    ADMIN = 307,                   /* ADMIN  */
    DOT = 308,                     /* DOT  */
    EXISTS = 309,                  /* EXISTS  */
    FACULTY = 310,                 /* FACULTY  */
    APPLICATION = 311,             /* APPLICATION  */
    PROFILE_DATA = 312,            /* PROFILE_DATA  */
    REFERRAL = 313,                /* REFERRAL  */
    PENDING = 314                  /* PENDING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "parser.yy"

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

#line 144 "parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HH_INCLUDED  */
