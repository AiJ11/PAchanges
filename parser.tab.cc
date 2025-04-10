/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yy"

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

#line 91 "parser.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_MAP = 7,                        /* MAP  */
  YYSYMBOL_TOKEN = 8,                      /* TOKEN  */
  YYSYMBOL_ROLE = 9,                       /* ROLE  */
  YYSYMBOL_PROGRAM = 10,                   /* PROGRAM  */
  YYSYMBOL_TYPE = 11,                      /* TYPE  */
  YYSYMBOL_HTTP_RESPONSE_CODE = 12,        /* HTTP_RESPONSE_CODE  */
  YYSYMBOL_HTTP_OK = 13,                   /* HTTP_OK  */
  YYSYMBOL_NIL = 14,                       /* NIL  */
  YYSYMBOL_OK = 15,                        /* OK  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LANGLE = 18,                    /* LANGLE  */
  YYSYMBOL_RANGLE = 19,                    /* RANGLE  */
  YYSYMBOL_LBRACKET = 20,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 21,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_COLON = 25,                     /* COLON  */
  YYSYMBOL_ARROW = 26,                     /* ARROW  */
  YYSYMBOL_MAPARROW = 27,                  /* MAPARROW  */
  YYSYMBOL_IMPL_ARROW = 28,                /* IMPL_ARROW  */
  YYSYMBOL_EQUALS = 29,                    /* EQUALS  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 32,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 33,                    /* DIVIDE  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NEQ = 35,                       /* NEQ  */
  YYSYMBOL_UNION = 36,                     /* UNION  */
  YYSYMBOL_IN = 37,                        /* IN  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_SUCH_THAT = 40,                 /* SUCH_THAT  */
  YYSYMBOL_NOT_EXISTS = 41,                /* NOT_EXISTS  */
  YYSYMBOL_PRIME = 42,                     /* PRIME  */
  YYSYMBOL_PIPE = 43,                      /* PIPE  */
  YYSYMBOL_UNKNOWN = 44,                   /* UNKNOWN  */
  YYSYMBOL_TYPES_HEADER = 45,              /* TYPES_HEADER  */
  YYSYMBOL_GLOBAL_DATA_HEADER = 46,        /* GLOBAL_DATA_HEADER  */
  YYSYMBOL_APIS_HEADER = 47,               /* APIS_HEADER  */
  YYSYMBOL_INIT_HEADER = 48,               /* INIT_HEADER  */
  YYSYMBOL_PRECONDITION = 49,              /* PRECONDITION  */
  YYSYMBOL_POSTCONDITION = 50,             /* POSTCONDITION  */
  YYSYMBOL_SET = 51,                       /* SET  */
  YYSYMBOL_ADMIN = 52,                     /* ADMIN  */
  YYSYMBOL_DOT = 53,                       /* DOT  */
  YYSYMBOL_EXISTS = 54,                    /* EXISTS  */
  YYSYMBOL_FACULTY = 55,                   /* FACULTY  */
  YYSYMBOL_APPLICATION = 56,               /* APPLICATION  */
  YYSYMBOL_PROFILE_DATA = 57,              /* PROFILE_DATA  */
  YYSYMBOL_REFERRAL = 58,                  /* REFERRAL  */
  YYSYMBOL_PENDING = 59,                   /* PENDING  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_start = 61,                     /* start  */
  YYSYMBOL_type_expr = 62,                 /* type_expr  */
  YYSYMBOL_map_type = 63,                  /* map_type  */
  YYSYMBOL_set_type = 64,                  /* set_type  */
  YYSYMBOL_func_decl = 65,                 /* func_decl  */
  YYSYMBOL_global_var = 66,                /* global_var  */
  YYSYMBOL_global_decl = 67,               /* global_decl  */
  YYSYMBOL_map_access = 68,                /* map_access  */
  YYSYMBOL_map_update = 69,                /* map_update  */
  YYSYMBOL_set_expr = 70,                  /* set_expr  */
  YYSYMBOL_result_expr = 71,               /* result_expr  */
  YYSYMBOL_precondition_expr = 72,         /* precondition_expr  */
  YYSYMBOL_api_function_call = 73,         /* api_function_call  */
  YYSYMBOL_api_response = 74,              /* api_response  */
  YYSYMBOL_postcondition_expr = 75,        /* postcondition_expr  */
  YYSYMBOL_api_spec = 76,                  /* api_spec  */
  YYSYMBOL_expr = 77,                      /* expr  */
  YYSYMBOL_func_call = 78,                 /* func_call  */
  YYSYMBOL_block = 79                      /* block  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   710

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,   102,   106,   110,   118,   122,   126,   137,
     148,   165,   177,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   206,   214,   226,   236,   254,   258,   266,
     273,   280,   332,   340,   348,   351,   358,   362,   367,   375,
     380,   391,   396,   401,   421,   432,   433,   434,   435,   440,
     441,   442,   443,   448,   455,   460,   465,   472,   478,   485,
     493,   501,   510,   513,   516,   519,   522,   525,   528,   531,
     534,   537,   540,   543,   544,   556,   582,   601
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "NUMBER",
  "STRING", "INT", "MAP", "TOKEN", "ROLE", "PROGRAM", "TYPE",
  "HTTP_RESPONSE_CODE", "HTTP_OK", "NIL", "OK", "LPAREN", "RPAREN",
  "LANGLE", "RANGLE", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COMMA",
  "COLON", "ARROW", "MAPARROW", "IMPL_ARROW", "EQUALS", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "EQ", "NEQ", "UNION", "IN", "AND", "OR",
  "SUCH_THAT", "NOT_EXISTS", "PRIME", "PIPE", "UNKNOWN", "TYPES_HEADER",
  "GLOBAL_DATA_HEADER", "APIS_HEADER", "INIT_HEADER", "PRECONDITION",
  "POSTCONDITION", "SET", "ADMIN", "DOT", "EXISTS", "FACULTY",
  "APPLICATION", "PROFILE_DATA", "REFERRAL", "PENDING", "$accept", "start",
  "type_expr", "map_type", "set_type", "func_decl", "global_var",
  "global_decl", "map_access", "map_update", "set_expr", "result_expr",
  "precondition_expr", "api_function_call", "api_response",
  "postcondition_expr", "api_spec", "expr", "func_call", "block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    63,    -5,     3,   -35,   -35,   -35,   -35,   -35,    -1,
     228,   211,    73,    73,   -35,   -35,   -35,   -35,   -35,   -35,
      73,   -35,   -35,   -35,   -35,    -2,   -35,   -35,   -35,   -35,
     228,   -11,   -35,   -35,    -4,   -34,   -35,   -35,   106,   -35,
     -35,    77,    73,    24,   -35,    29,   -35,   -35,   -35,   620,
     -35,   219,   542,   228,   -15,   228,   -35,    73,    73,    73,
      73,   -35,    34,    36,    46,   242,   458,    13,    32,    73,
      73,    73,   138,    73,    73,    73,    73,   142,    73,    73,
      73,    55,    73,   -10,   228,   -13,    69,   620,   558,   422,
     574,   -35,    37,    38,   -35,   -35,    73,    70,    75,   634,
     673,   135,    73,   135,    -3,    -3,   673,   673,    73,   620,
     620,   661,   648,    73,   265,   228,    -8,    56,    67,    58,
      73,   -35,    73,    73,    91,    94,   509,    60,    62,   159,
     475,   492,   590,    72,    -9,    98,   228,   103,    96,   288,
     441,   526,    79,    80,   -35,    73,    73,     2,   -35,   -35,
      73,   109,   -35,   -35,   -34,    99,   100,   -35,    74,   -35,
     -35,   -35,    73,    73,   620,   620,   311,   101,   127,    11,
     107,   334,   357,   108,   122,   126,   -35,   185,    73,   -35,
     -35,   123,   -35,   -35,    87,   380,   -35,   620,    73,   -35,
     -35,   606,    73,   403,    97,   119,    73,   620
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    28,     0,     0,     8,    12,    10,    11,     9,     0,
       0,     0,     0,     0,     1,     3,     7,     5,     6,     4,
       0,    19,    20,    13,    14,     0,    16,    17,    18,    15,
       0,     0,    21,    22,     0,    31,    21,    22,    44,    45,
      46,     0,     0,     0,    47,     0,    49,    50,    51,    27,
      74,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,    52,     0,     0,    73,    57,     0,     0,     0,     0,
      68,    64,     0,    65,    66,    67,    69,    70,     0,    35,
      62,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,    44,    57,    34,
       0,     0,    24,    23,    26,     0,     0,    41,     0,    75,
      33,    60,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,    56,
      55,     0,    76,    40,    44,     0,    43,    42,     0,    37,
      38,     0,     0,     0,     0,     0,     0,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,     1,   144,   146,   150,   166,   167,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   171,   -12,   -35,   174
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    31,    32,    33,     4,     5,     6,    46,    47,
      48,   157,    86,   119,   158,   186,     7,   110,    50,     8
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    51,   -61,    14,   117,   -61,     1,     1,    52,   135,
     152,    84,    35,    55,   115,    20,    53,    56,    58,   -61,
      13,    57,    59,    69,    60,   -61,   -61,    67,   176,    65,
      66,    54,    68,    77,    78,   177,    56,    91,    56,    92,
      56,    56,    56,    56,    61,    87,    88,    89,    90,    93,
      97,   -61,     2,     2,    83,    62,    85,    99,   100,   101,
     103,   104,   105,   106,   107,   109,     9,   111,   112,    98,
     114,   113,   118,   127,   124,   125,    38,    39,   128,    10,
      38,    39,   136,   137,   126,   116,   138,    40,    11,    41,
     130,    40,    12,    41,   142,    42,   131,   143,   151,    42,
     145,   132,   146,    58,   189,   153,   155,    59,   139,    60,
     140,   141,   156,   167,    43,   169,   134,    44,    63,   162,
     163,    44,    58,   168,   170,   174,    59,    45,    60,    61,
     175,    64,   178,   164,   165,   182,   181,   154,   166,   188,
      62,    38,    39,   183,   196,    38,    39,   195,    61,     0,
     171,   172,    40,    15,    41,    36,    40,    37,    41,    62,
     102,    69,   147,    39,   108,   185,   187,    73,    74,    16,
      17,    77,    78,    40,    18,    41,   191,    19,     0,    43,
     193,    42,    44,    43,   197,     0,    44,     0,   184,    39,
       0,     0,    45,     0,     0,     0,    45,     0,     0,    40,
      43,    41,     0,    44,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    45,    21,    22,    23,    24,    25,    26,
      27,    28,    81,    29,     0,     0,    43,    30,     0,    44,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    45,
      29,     0,     0,     0,    30,    69,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    94,
      34,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   133,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   159,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   173,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   179,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   180,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   190,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     194,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   121,     0,     0,     0,     0,   122,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   160,     0,     0,     0,     0,    69,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,   129,    79,
      80,    95,    96,     0,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   148,    96,
       0,    69,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   149,    96,     0,    69,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   144,     0,     0,    69,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   161,
       0,     0,    69,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    82,     0,    69,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   120,     0,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   123,     0,
      69,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   150,     0,    69,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     192,     0,    69,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    69,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      69,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,   129,    79,    80,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    69,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    69,
       0,     0,     0,    71,    72,    73,    74,     0,     0,    77,
      78
};

static const yytype_int16 yycheck[] =
{
      12,    13,     0,     0,    17,     3,     3,     3,    20,    17,
      19,    26,    11,    24,    24,    16,    18,    51,    16,    17,
      25,    25,    20,    26,    22,    23,    24,     3,    17,    41,
      42,    30,     3,    36,    37,    24,    51,     3,    51,     3,
      51,    51,    51,    51,    42,    57,    58,    59,    60,     3,
      37,    49,    49,    49,    53,    53,    55,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     3,    79,    80,    37,
      82,    16,     3,     3,    37,    37,     3,     4,     3,    16,
       3,     4,    26,    16,    96,    84,    28,    14,    25,    16,
     102,    14,    29,    16,     3,    22,   108,     3,    26,    22,
      40,   113,    40,    16,    17,     7,     3,    20,   120,    22,
     122,   123,    16,     4,    41,    15,   115,    44,    41,    40,
      40,    44,    16,    24,    50,    24,    20,    54,    22,    42,
       3,    54,    25,   145,   146,    13,    28,   136,   150,    16,
      53,     3,     4,    17,    25,     3,     4,    50,    42,    -1,
     162,   163,    14,     3,    16,    11,    14,    11,    16,    53,
      22,    26,     3,     4,    22,   177,   178,    32,    33,     3,
       3,    36,    37,    14,     3,    16,   188,     3,    -1,    41,
     192,    22,    44,    41,   196,    -1,    44,    -1,     3,     4,
      -1,    -1,    54,    -1,    -1,    -1,    54,    -1,    -1,    14,
      41,    16,    -1,    44,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    54,     3,     4,     5,     6,     7,     8,
       9,    10,     3,    12,    -1,    -1,    41,    16,    -1,    44,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    54,
      12,    -1,    -1,    -1,    16,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    17,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    21,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    23,    24,    -1,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    23,    24,
      -1,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    23,    24,    -1,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    23,    -1,    -1,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    23,
      -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    24,    -1,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    24,    -1,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    24,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    24,    -1,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      24,    -1,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    -1,    -1,    36,
      37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    61,    65,    66,    67,    76,    79,     3,
      16,    25,    29,    25,     0,    65,    66,    67,    76,    79,
      16,     3,     4,     5,     6,     7,     8,     9,    10,    12,
      16,    62,    63,    64,    49,    62,    63,    64,     3,     4,
      14,    16,    22,    41,    44,    54,    68,    69,    70,    77,
      78,    77,    77,    18,    62,    24,    51,    25,    16,    20,
      22,    42,    53,    41,    54,    77,    77,     3,     3,    26,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     3,    24,    62,    26,    62,    72,    77,    77,    77,
      77,     3,     3,     3,    17,    23,    24,    37,    37,    77,
      77,    77,    22,    77,    77,    77,    77,    77,    22,    77,
      77,    77,    77,    16,    77,    24,    62,    17,     3,    73,
      24,    21,    26,    24,    37,    37,    77,     3,     3,    37,
      77,    77,    77,    17,    62,    17,    26,    16,    28,    77,
      77,    77,     3,     3,    23,    40,    40,     3,    23,    23,
      24,    26,    19,     7,    62,     3,    16,    71,    74,    17,
      21,    23,    40,    40,    77,    77,    77,     4,    24,    15,
      50,    77,    77,    17,    24,     3,    17,    24,    25,    17,
      17,    28,    13,    17,     3,    77,    75,    77,    16,    17,
      17,    77,    24,    77,    17,    50,    25,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    65,    66,    66,    67,
      67,    67,    68,    69,    70,    70,    71,    71,    71,    72,
      73,    74,    75,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     6,     2,     8,     3,     1,     3,
       3,     3,     4,     6,     5,     3,     3,     5,     5,     1,
       6,     1,     1,    11,     1,     1,     1,     1,     2,     1,
       1,     1,     3,     6,     6,     8,     8,     3,     5,     5,
       6,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     6,    11,    18
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: %empty  */
#line 92 "parser.yy"
                {
        // Initialize with empty vectors
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
#line 1392 "parser.tab.cc"
    break;

  case 3: /* start: start func_decl  */
#line 102 "parser.yy"
                      {
        // Add function declaration to the root
        root->functions.push_back(unique_ptr<FuncDeclNode>((yyvsp[0].funcDecl)));
    }
#line 1401 "parser.tab.cc"
    break;

  case 4: /* start: start block  */
#line 106 "parser.yy"
                  {
        // Add block to the root
        root->blocks.push_back(unique_ptr<BlockNode>((yyvsp[0].block)));
    }
#line 1410 "parser.tab.cc"
    break;

  case 5: /* start: start global_decl  */
#line 110 "parser.yy"
                        {
        // Handle based on actual type
        if (auto mapDecl = dynamic_cast<MapDeclNode*>((yyvsp[0].node))) {
            root->maps.push_back(unique_ptr<MapDeclNode>(mapDecl));
        } else if (auto varDecl = dynamic_cast<GlobalVarNode*>((yyvsp[0].node))) {
            root->globals.push_back(unique_ptr<GlobalVarNode>(varDecl));
        }
    }
#line 1423 "parser.tab.cc"
    break;

  case 6: /* start: start api_spec  */
#line 118 "parser.yy"
                     {
        // Add API specification to root
        root->apiSpecs.push_back(unique_ptr<ApiSpecNode>((yyvsp[0].apiSpec)));
    }
#line 1432 "parser.tab.cc"
    break;

  case 7: /* start: start global_var  */
#line 122 "parser.yy"
                       {
        // Add global variable to the root
        root->globals.push_back(unique_ptr<GlobalVarNode>((yyvsp[0].globalVar)));
    }
#line 1441 "parser.tab.cc"
    break;

  case 8: /* start: func_decl  */
#line 126 "parser.yy"
                {
        // Start directly with a function declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        functions.push_back(unique_ptr<FuncDeclNode>((yyvsp[0].funcDecl)));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
#line 1457 "parser.tab.cc"
    break;

  case 9: /* start: block  */
#line 137 "parser.yy"
            {
        // Start directly with a block
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        blocks.push_back(unique_ptr<BlockNode>((yyvsp[0].block)));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
#line 1473 "parser.tab.cc"
    break;

  case 10: /* start: global_decl  */
#line 148 "parser.yy"
                  {
        // Start with a global declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        
        if (auto mapDecl = dynamic_cast<MapDeclNode*>((yyvsp[0].node))) {
            maps.push_back(unique_ptr<MapDeclNode>(mapDecl));
        } else if (auto varDecl = dynamic_cast<GlobalVarNode*>((yyvsp[0].node))) {
            globals.push_back(unique_ptr<GlobalVarNode>(varDecl));
        }
        
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
#line 1495 "parser.tab.cc"
    break;

  case 11: /* start: api_spec  */
#line 165 "parser.yy"
               {
        // Start with an API specification
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        specs.push_back(unique_ptr<ApiSpecNode>((yyvsp[0].apiSpec)));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                              std::move(globals), std::move(maps), std::move(specs)));
    }
#line 1511 "parser.tab.cc"
    break;

  case 12: /* start: global_var  */
#line 177 "parser.yy"
                 {
        // Start with a global variable declaration
        vector<unique_ptr<FuncDeclNode>> functions;
        vector<unique_ptr<BlockNode>> blocks;
        vector<unique_ptr<GlobalVarNode>> globals;
        vector<unique_ptr<MapDeclNode>> maps;
        vector<unique_ptr<ApiSpecNode>> specs;
        globals.push_back(unique_ptr<GlobalVarNode>((yyvsp[0].globalVar)));
        root = unique_ptr<SpecNode>(new SpecNode(std::move(functions), std::move(blocks), 
                                      std::move(globals), std::move(maps), std::move(specs)));
    }
#line 1527 "parser.tab.cc"
    break;

  case 13: /* type_expr: STRING  */
#line 192 "parser.yy"
           { (yyval.typeExpr) = new TypeExprNode("string"); }
#line 1533 "parser.tab.cc"
    break;

  case 14: /* type_expr: INT  */
#line 193 "parser.yy"
          { (yyval.typeExpr) = new TypeExprNode("int"); }
#line 1539 "parser.tab.cc"
    break;

  case 15: /* type_expr: HTTP_RESPONSE_CODE  */
#line 194 "parser.yy"
                         { (yyval.typeExpr) = new TypeExprNode("HTTPResponseCode"); }
#line 1545 "parser.tab.cc"
    break;

  case 16: /* type_expr: TOKEN  */
#line 195 "parser.yy"
            { (yyval.typeExpr) = new TypeExprNode("token"); }
#line 1551 "parser.tab.cc"
    break;

  case 17: /* type_expr: ROLE  */
#line 196 "parser.yy"
           { (yyval.typeExpr) = new TypeExprNode("Role"); }
#line 1557 "parser.tab.cc"
    break;

  case 18: /* type_expr: PROGRAM  */
#line 197 "parser.yy"
              { (yyval.typeExpr) = new TypeExprNode("Program"); }
#line 1563 "parser.tab.cc"
    break;

  case 19: /* type_expr: IDENTIFIER  */
#line 198 "parser.yy"
                 { (yyval.typeExpr) = new TypeExprNode(*(yyvsp[0].sval)); delete (yyvsp[0].sval); }
#line 1569 "parser.tab.cc"
    break;

  case 20: /* type_expr: NUMBER  */
#line 199 "parser.yy"
             { (yyval.typeExpr) = new TypeExprNode(std::to_string((yyvsp[0].ival))); }
#line 1575 "parser.tab.cc"
    break;

  case 21: /* type_expr: map_type  */
#line 200 "parser.yy"
               { (yyval.typeExpr) = (yyvsp[0].mapType); }
#line 1581 "parser.tab.cc"
    break;

  case 22: /* type_expr: set_type  */
#line 201 "parser.yy"
               { (yyval.typeExpr) = (yyvsp[0].setType); }
#line 1587 "parser.tab.cc"
    break;

  case 23: /* map_type: LPAREN type_expr ARROW type_expr RPAREN MAP  */
#line 206 "parser.yy"
                                                {
        // Map type: (keyType -> valueType) map
        TypeExprNode* keyType = (yyvsp[-4].typeExpr);
        TypeExprNode* valueType = (yyvsp[-2].typeExpr);
        (yyval.mapType) = new MapTypeNode(keyType->type, valueType->type);
        delete keyType;
        delete valueType;
    }
#line 1600 "parser.tab.cc"
    break;

  case 24: /* map_type: MAP LANGLE type_expr COMMA type_expr RANGLE  */
#line 214 "parser.yy"
                                                  {
        // Map type: map<keyType, valueType>
        TypeExprNode* keyType = (yyvsp[-3].typeExpr);
        TypeExprNode* valueType = (yyvsp[-1].typeExpr);
        (yyval.mapType) = new MapTypeNode(keyType->type, valueType->type);
        delete keyType;
        delete valueType;
    }
#line 1613 "parser.tab.cc"
    break;

  case 25: /* set_type: type_expr SET  */
#line 226 "parser.yy"
                  {
        // Set type: elementType set
        TypeExprNode* elemType = (yyvsp[-1].typeExpr);
        (yyval.setType) = new SetTypeNode(elemType->type);
        delete elemType;
    }
#line 1624 "parser.tab.cc"
    break;

  case 26: /* func_decl: IDENTIFIER LPAREN type_expr COMMA type_expr RPAREN ARROW type_expr  */
#line 236 "parser.yy"
                                                                       {
        // Get type names from type expressions
        TypeExprNode* type1 = (yyvsp[-5].typeExpr);
        TypeExprNode* type2 = (yyvsp[-3].typeExpr);
        TypeExprNode* returnType = (yyvsp[0].typeExpr);
        
        (yyval.funcDecl) = new FuncDeclNode(*(yyvsp[-7].sval), type1->type + ", " + type2->type, returnType->type);
        delete (yyvsp[-7].sval);
        
        // TypeExprNode objects are owned by unique_ptr after this point
        delete type1;
        delete type2;
        delete returnType;
    }
#line 1643 "parser.tab.cc"
    break;

  case 27: /* global_var: IDENTIFIER EQUALS expr  */
#line 254 "parser.yy"
                           {
        (yyval.globalVar) = new GlobalVarNode(*(yyvsp[-2].sval), nullptr, unique_ptr<ExprNode>((yyvsp[0].expr)));
        delete (yyvsp[-2].sval);
    }
#line 1652 "parser.tab.cc"
    break;

  case 28: /* global_var: IDENTIFIER  */
#line 258 "parser.yy"
                 {
        (yyval.globalVar) = new GlobalVarNode(*(yyvsp[0].sval));
        delete (yyvsp[0].sval);
    }
#line 1661 "parser.tab.cc"
    break;

  case 29: /* global_decl: IDENTIFIER COLON map_type  */
#line 266 "parser.yy"
                              {
        // For declarations like: U : (string -> string) map
        std::string name = *(yyvsp[-2].sval);
        knownGlobals.insert(name); // Add to known globals
        (yyval.node) = new MapDeclNode(*(yyvsp[-2].sval), unique_ptr<MapTypeNode>((yyvsp[0].mapType)));
        delete (yyvsp[-2].sval);
    }
#line 1673 "parser.tab.cc"
    break;

  case 30: /* global_decl: IDENTIFIER COLON set_type  */
#line 273 "parser.yy"
                                {
        // For declarations like: L : string set
        std::string name = *(yyvsp[-2].sval);
        knownGlobals.insert(name); // Add to known globals
        (yyval.node) = new GlobalVarNode(*(yyvsp[-2].sval), unique_ptr<TypeExprNode>((yyvsp[0].setType)));
        delete (yyvsp[-2].sval);
    }
#line 1685 "parser.tab.cc"
    break;

  case 31: /* global_decl: IDENTIFIER COLON type_expr  */
#line 280 "parser.yy"
                                 {
        // For declarations like: P : Program
        std::string name = *(yyvsp[-2].sval);
        knownGlobals.insert(name); // Add to known globals
        (yyval.node) = new GlobalVarNode(*(yyvsp[-2].sval), unique_ptr<TypeExprNode>((yyvsp[0].typeExpr)));
        delete (yyvsp[-2].sval);
    }
#line 1697 "parser.tab.cc"
    break;

  case 32: /* map_access: IDENTIFIER LBRACKET expr RBRACKET  */
#line 332 "parser.yy"
                                      {
        (yyval.expr) = new MapAccessNode(*(yyvsp[-3].sval), unique_ptr<ExprNode>((yyvsp[-1].expr)));
        delete (yyvsp[-3].sval);
    }
#line 1706 "parser.tab.cc"
    break;

  case 33: /* map_update: IDENTIFIER LBRACKET expr ARROW expr RBRACKET  */
#line 340 "parser.yy"
                                                 {
        (yyval.expr) = new MapUpdateNode(*(yyvsp[-5].sval), unique_ptr<ExprNode>((yyvsp[-3].expr)), unique_ptr<ExprNode>((yyvsp[-1].expr)));
        delete (yyvsp[-5].sval);
    }
#line 1715 "parser.tab.cc"
    break;

  case 34: /* set_expr: expr UNION LBRACE expr RBRACE  */
#line 348 "parser.yy"
                                  {
        (yyval.expr) = new SetOpNode(SetOpNode::UNION, unique_ptr<ExprNode>((yyvsp[-4].expr)), unique_ptr<ExprNode>((yyvsp[-1].expr)));
    }
#line 1723 "parser.tab.cc"
    break;

  case 35: /* set_expr: expr UNION expr  */
#line 351 "parser.yy"
                      {
        (yyval.expr) = new SetOpNode(SetOpNode::UNION, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr)));
    }
#line 1731 "parser.tab.cc"
    break;

  case 36: /* result_expr: LPAREN OK RPAREN  */
#line 358 "parser.yy"
                     {
        // Handle (OK) response format
        (yyval.response) = new ResponseNode(unique_ptr<ExprNode>(new VarNode("OK")), "OK");
    }
#line 1740 "parser.tab.cc"
    break;

  case 37: /* result_expr: LPAREN OK COMMA IDENTIFIER RPAREN  */
#line 362 "parser.yy"
                                        {
        // Handle (OK, t) response format
        (yyval.response) = new ResponseNode(unique_ptr<ExprNode>(new VarNode("OK")), *(yyvsp[-1].sval));
        delete (yyvsp[-1].sval);
    }
#line 1750 "parser.tab.cc"
    break;

  case 38: /* result_expr: LPAREN OK COMMA expr RPAREN  */
#line 367 "parser.yy"
                                  {
        // Handle (OK, id) response format with expressions
        (yyval.response) = new ResponseNode(unique_ptr<ExprNode>(new VarNode("OK")), "TUPLE");
    }
#line 1759 "parser.tab.cc"
    break;

  case 39: /* precondition_expr: expr  */
#line 375 "parser.yy"
         { (yyval.expr) = (yyvsp[0].expr); }
#line 1765 "parser.tab.cc"
    break;

  case 40: /* api_function_call: IDENTIFIER LPAREN IDENTIFIER COMMA IDENTIFIER RPAREN  */
#line 380 "parser.yy"
                                                         {
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>(new VarNode(*(yyvsp[-3].sval))));
        args.push_back(unique_ptr<ExprNode>(new VarNode(*(yyvsp[-1].sval))));
        (yyval.funcCall) = new FuncCallNode(*(yyvsp[-5].sval), std::move(args));
        delete (yyvsp[-5].sval); delete (yyvsp[-3].sval); delete (yyvsp[-1].sval);
    }
#line 1777 "parser.tab.cc"
    break;

  case 41: /* api_response: result_expr  */
#line 391 "parser.yy"
                { (yyval.response) = (yyvsp[0].response); }
#line 1783 "parser.tab.cc"
    break;

  case 42: /* postcondition_expr: expr  */
#line 396 "parser.yy"
         { (yyval.expr) = (yyvsp[0].expr); }
#line 1789 "parser.tab.cc"
    break;

  case 43: /* api_spec: IDENTIFIER COLON PRECONDITION COLON precondition_expr api_function_call IMPL_ARROW api_response POSTCONDITION COLON postcondition_expr  */
#line 405 "parser.yy"
    {
        // Build the API specification
        (yyval.apiSpec) = new ApiSpecNode(
            *(yyvsp[-10].sval),                         // API name
            unique_ptr<ExprNode>((yyvsp[-6].expr)),    // Precondition
            unique_ptr<FuncCallNode>((yyvsp[-5].funcCall)), // API function call
            unique_ptr<ExprNode>((yyvsp[-3].response)),    // API response
            unique_ptr<ExprNode>((yyvsp[0].expr))    // Postcondition
        );
        
        delete (yyvsp[-10].sval);
    }
#line 1806 "parser.tab.cc"
    break;

  case 44: /* expr: IDENTIFIER  */
#line 421 "parser.yy"
               { 
        std::string name = *(yyvsp[0].sval);
        if (knownGlobals.count(name) > 0) {
            // This is a known global variable
            (yyval.expr) = new GlobalVarRefNode(name);
        } else {
            // This is a regular variable
            (yyval.expr) = new VarNode(name);
        }
        delete (yyvsp[0].sval);
    }
#line 1822 "parser.tab.cc"
    break;

  case 45: /* expr: NUMBER  */
#line 432 "parser.yy"
             { (yyval.expr) = new NumNode((yyvsp[0].ival)); }
#line 1828 "parser.tab.cc"
    break;

  case 46: /* expr: NIL  */
#line 433 "parser.yy"
          { (yyval.expr) = new VarNode("NIL"); }
#line 1834 "parser.tab.cc"
    break;

  case 47: /* expr: UNKNOWN  */
#line 434 "parser.yy"
              { (yyval.expr) = new VarNode("NIL"); }
#line 1840 "parser.tab.cc"
    break;

  case 48: /* expr: IDENTIFIER PRIME  */
#line 435 "parser.yy"
                       {
        // For variables with prime, like U'
        (yyval.expr) = new VarNode(*(yyvsp[-1].sval) + "'");
        delete (yyvsp[-1].sval);
    }
#line 1850 "parser.tab.cc"
    break;

  case 49: /* expr: map_access  */
#line 440 "parser.yy"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 1856 "parser.tab.cc"
    break;

  case 50: /* expr: map_update  */
#line 441 "parser.yy"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 1862 "parser.tab.cc"
    break;

  case 51: /* expr: set_expr  */
#line 442 "parser.yy"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 1868 "parser.tab.cc"
    break;

  case 52: /* expr: IDENTIFIER DOT IDENTIFIER  */
#line 443 "parser.yy"
                                {
        // Property access like program.id
        (yyval.expr) = new PropertyAccessNode(*(yyvsp[-2].sval), *(yyvsp[0].sval));
        delete (yyvsp[-2].sval); delete (yyvsp[0].sval);
    }
#line 1878 "parser.tab.cc"
    break;

  case 53: /* expr: NOT_EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr  */
#line 448 "parser.yy"
                                                         {
        // Not exists quantifier
        (yyval.expr) = new ExistsNode(*(yyvsp[-4].sval), *(yyvsp[-2].sval), unique_ptr<ExprNode>((yyvsp[0].expr)));
        // Note: We're using ExistsNode for simplicity
        // In a more comprehensive implementation, this would have a dedicated NotExistsNode
        delete (yyvsp[-4].sval); delete (yyvsp[-2].sval);
    }
#line 1890 "parser.tab.cc"
    break;

  case 54: /* expr: EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr  */
#line 455 "parser.yy"
                                                     {
        // Existential quantifier: exists x in S s.t. <condition>
        (yyval.expr) = new ExistsNode(*(yyvsp[-4].sval), *(yyvsp[-2].sval), unique_ptr<ExprNode>((yyvsp[0].expr)));
        delete (yyvsp[-4].sval); delete (yyvsp[-2].sval);
    }
#line 1900 "parser.tab.cc"
    break;

  case 55: /* expr: LPAREN EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr RPAREN  */
#line 460 "parser.yy"
                                                                   {
        // Parenthesized existential
        (yyval.expr) = new ExistsNode(*(yyvsp[-5].sval), *(yyvsp[-3].sval), unique_ptr<ExprNode>((yyvsp[-1].expr)));
        delete (yyvsp[-5].sval); delete (yyvsp[-3].sval);
    }
#line 1910 "parser.tab.cc"
    break;

  case 56: /* expr: LPAREN NOT_EXISTS IDENTIFIER IN IDENTIFIER SUCH_THAT expr RPAREN  */
#line 465 "parser.yy"
                                                                       {
        // Parenthesized not exists
        (yyval.expr) = new ExistsNode(*(yyvsp[-5].sval), *(yyvsp[-3].sval), unique_ptr<ExprNode>((yyvsp[-1].expr)));
        // Note: We're using ExistsNode for simplicity
        delete (yyvsp[-5].sval); delete (yyvsp[-3].sval);
    }
#line 1921 "parser.tab.cc"
    break;

  case 57: /* expr: LBRACE expr RBRACE  */
#line 472 "parser.yy"
                         {
        // Create a set literal node with single element
        vector<unique_ptr<ExprNode>> elements;
        elements.push_back(unique_ptr<ExprNode>((yyvsp[-1].expr)));
        (yyval.expr) = new SetLiteralNode(std::move(elements));
    }
#line 1932 "parser.tab.cc"
    break;

  case 58: /* expr: LBRACE expr COMMA expr RBRACE  */
#line 478 "parser.yy"
                                    {
        // Create a set literal node with multiple elements
        vector<unique_ptr<ExprNode>> elements;
        elements.push_back(unique_ptr<ExprNode>((yyvsp[-3].expr)));
        elements.push_back(unique_ptr<ExprNode>((yyvsp[-1].expr)));
        (yyval.expr) = new SetLiteralNode(std::move(elements));
    }
#line 1944 "parser.tab.cc"
    break;

  case 59: /* expr: expr MINUS LBRACE expr RBRACE  */
#line 485 "parser.yy"
                                    {
        // For set difference: P - {programId}
        vector<unique_ptr<ExprNode>> elements;
        elements.push_back(unique_ptr<ExprNode>((yyvsp[-1].expr)));
        (yyval.expr) = new SetOpNode(SetOpNode::DIFFERENCE, 
                           unique_ptr<ExprNode>((yyvsp[-4].expr)), 
                           unique_ptr<ExprNode>(new SetLiteralNode(std::move(elements))));
    }
#line 1957 "parser.tab.cc"
    break;

  case 60: /* expr: IDENTIFIER LBRACE expr COMMA expr RBRACE  */
#line 493 "parser.yy"
                                               {
        // For constructions like Program{id, programName}
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>((yyvsp[-3].expr)));
        args.push_back(unique_ptr<ExprNode>((yyvsp[-1].expr)));
        (yyval.expr) = new ConstructorNode(*(yyvsp[-5].sval), std::move(args));
        delete (yyvsp[-5].sval);
    }
#line 1970 "parser.tab.cc"
    break;

  case 61: /* expr: expr ARROW expr IN IDENTIFIER  */
#line 501 "parser.yy"
                                    {
        // For expressions like "t -> u in T"
        // This can be interpreted as "T[t] = u"
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::EQ, 
                           unique_ptr<ExprNode>(new MapAccessNode(*(yyvsp[0].sval), unique_ptr<ExprNode>((yyvsp[-4].expr)))), 
                           unique_ptr<ExprNode>((yyvsp[-2].expr)));
        delete (yyvsp[0].sval);
    }
#line 1983 "parser.tab.cc"
    break;

  case 62: /* expr: expr IN expr  */
#line 510 "parser.yy"
                   {
        (yyval.expr) = new SetOpNode(SetOpNode::IN, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr)));
    }
#line 1991 "parser.tab.cc"
    break;

  case 63: /* expr: expr UNION expr  */
#line 513 "parser.yy"
                      { 
        (yyval.expr) = new SetOpNode(SetOpNode::UNION, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 1999 "parser.tab.cc"
    break;

  case 64: /* expr: expr PLUS expr  */
#line 516 "parser.yy"
                     { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::ADD, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2007 "parser.tab.cc"
    break;

  case 65: /* expr: expr MINUS expr  */
#line 519 "parser.yy"
                      { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::SUBTRACT, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2015 "parser.tab.cc"
    break;

  case 66: /* expr: expr MULTIPLY expr  */
#line 522 "parser.yy"
                         { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::MULTIPLY, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2023 "parser.tab.cc"
    break;

  case 67: /* expr: expr DIVIDE expr  */
#line 525 "parser.yy"
                       { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::DIVIDE, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2031 "parser.tab.cc"
    break;

  case 68: /* expr: expr EQUALS expr  */
#line 528 "parser.yy"
                       { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::EQ, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2039 "parser.tab.cc"
    break;

  case 69: /* expr: expr EQ expr  */
#line 531 "parser.yy"
                   { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::EQ, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2047 "parser.tab.cc"
    break;

  case 70: /* expr: expr NEQ expr  */
#line 534 "parser.yy"
                    { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::NEQ, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2055 "parser.tab.cc"
    break;

  case 71: /* expr: expr AND expr  */
#line 537 "parser.yy"
                    { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::AND_OP, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2063 "parser.tab.cc"
    break;

  case 72: /* expr: expr OR expr  */
#line 540 "parser.yy"
                   { 
        (yyval.expr) = new BinaryOpNode(BinaryOpNode::OR_OP, unique_ptr<ExprNode>((yyvsp[-2].expr)), unique_ptr<ExprNode>((yyvsp[0].expr))); 
    }
#line 2071 "parser.tab.cc"
    break;

  case 73: /* expr: LPAREN expr RPAREN  */
#line 543 "parser.yy"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 2077 "parser.tab.cc"
    break;

  case 74: /* expr: func_call  */
#line 544 "parser.yy"
                { (yyval.expr) = (yyvsp[0].funcCall); }
#line 2083 "parser.tab.cc"
    break;

  case 75: /* func_call: IDENTIFIER LPAREN expr COMMA expr RPAREN  */
#line 556 "parser.yy"
                                             {
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>((yyvsp[-3].expr)));
        args.push_back(unique_ptr<ExprNode>((yyvsp[-1].expr)));
        (yyval.funcCall) = new FuncCallNode(*(yyvsp[-5].sval), std::move(args));
        delete (yyvsp[-5].sval);
    }
#line 2095 "parser.tab.cc"
    break;

  case 76: /* block: IDENTIFIER IDENTIFIER LPAREN expr COMMA expr RPAREN ARROW NUMBER COMMA HTTP_OK  */
#line 582 "parser.yy"
                                                                                   {
        // Directly match the exact pattern for the API call
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>((yyvsp[-7].expr)));
        args.push_back(unique_ptr<ExprNode>((yyvsp[-5].expr)));
        
        FuncCallNode* funcCall = new FuncCallNode(*(yyvsp[-9].sval), std::move(args));
        ResponseNode* response = new ResponseNode(unique_ptr<ExprNode>(new NumNode((yyvsp[-2].ival))), "HTTP_OK");
        
        (yyval.block) = new BlockNode(
            unique_ptr<ExprNode>(new VarNode(*(yyvsp[-10].sval))),
            unique_ptr<APICallNode>(new APICallNode(
                unique_ptr<FuncCallNode>(funcCall)
            )),
            unique_ptr<ResponseNode>(response)
        );
        
        delete (yyvsp[-10].sval); delete (yyvsp[-9].sval);
    }
#line 2119 "parser.tab.cc"
    break;

  case 77: /* block: PRECONDITION COLON expr IDENTIFIER LPAREN expr COMMA expr RPAREN IMPL_ARROW LPAREN expr COMMA expr RPAREN POSTCONDITION COLON expr  */
#line 604 "parser.yy"
                               {
        // For blocks with explicit PRECONDITION/POSTCONDITION
        vector<unique_ptr<ExprNode>> args;
        args.push_back(unique_ptr<ExprNode>((yyvsp[-12].expr)));
        args.push_back(unique_ptr<ExprNode>((yyvsp[-10].expr)));
        
        FuncCallNode* funcCall = new FuncCallNode(*(yyvsp[-14].sval), std::move(args));
        ResponseNode* response = new ResponseNode(unique_ptr<ExprNode>((yyvsp[-6].expr)), "TUPLE");
        
        (yyval.block) = new BlockNode(
            unique_ptr<ExprNode>((yyvsp[-15].expr)),
            unique_ptr<APICallNode>(new APICallNode(
                unique_ptr<FuncCallNode>(funcCall)
            )),
            unique_ptr<ResponseNode>(response)
        );
        
        delete (yyvsp[-14].sval);
    }
#line 2143 "parser.tab.cc"
    break;


#line 2147 "parser.tab.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 625 "parser.yy"


// Error handling
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at or near token '%s' (line %d)\n", s, yytext, yylineno);
}
