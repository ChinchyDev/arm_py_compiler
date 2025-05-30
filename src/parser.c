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
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Use get_token instead of yylex
extern int get_token();
#define yylex get_token

extern int line_num;
void yyerror(const char *s);

ASTNode *ast_root = NULL;

#line 87 "src/parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_NUM = 3,                    /* INT_NUM  */
  YYSYMBOL_FLOAT_NUM = 4,                  /* FLOAT_NUM  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_NEWLINE = 8,                    /* NEWLINE  */
  YYSYMBOL_INDENT = 9,                     /* INDENT  */
  YYSYMBOL_DEDENT = 10,                    /* DEDENT  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_ELIF = 13,                      /* ELIF  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_IN = 16,                        /* IN  */
  YYSYMBOL_DEF = 17,                       /* DEF  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_IMPORT = 19,                    /* IMPORT  */
  YYSYMBOL_NONE = 20,                      /* NONE  */
  YYSYMBOL_RANGE = 21,                     /* RANGE  */
  YYSYMBOL_PRINT = 22,                     /* PRINT  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_TIMES = 28,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 32,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 33,              /* MINUS_ASSIGN  */
  YYSYMBOL_TIMES_ASSIGN = 34,              /* TIMES_ASSIGN  */
  YYSYMBOL_DIVIDE_ASSIGN = 35,             /* DIVIDE_ASSIGN  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_LT = 38,                        /* LT  */
  YYSYMBOL_GT = 39,                        /* GT  */
  YYSYMBOL_LE = 40,                        /* LE  */
  YYSYMBOL_GE = 41,                        /* GE  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 43,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 44,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 45,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 46,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 47,                    /* RBRACE  */
  YYSYMBOL_COLON = 48,                     /* COLON  */
  YYSYMBOL_COMMA = 49,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_statement_list = 52,            /* statement_list  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expression_stmt = 54,           /* expression_stmt  */
  YYSYMBOL_assignment_stmt = 55,           /* assignment_stmt  */
  YYSYMBOL_print_stmt = 56,                /* print_stmt  */
  YYSYMBOL_suite = 57,                     /* suite  */
  YYSYMBOL_if_stmt = 58,                   /* if_stmt  */
  YYSYMBOL_elif_clauses = 59,              /* elif_clauses  */
  YYSYMBOL_else_clause = 60,               /* else_clause  */
  YYSYMBOL_while_stmt = 61,                /* while_stmt  */
  YYSYMBOL_for_stmt = 62,                  /* for_stmt  */
  YYSYMBOL_function_def = 63,              /* function_def  */
  YYSYMBOL_return_stmt = 64,               /* return_stmt  */
  YYSYMBOL_import_stmt = 65,               /* import_stmt  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_logical_or = 68,                /* logical_or  */
  YYSYMBOL_logical_and = 69,               /* logical_and  */
  YYSYMBOL_equality = 70,                  /* equality  */
  YYSYMBOL_comparison = 71,                /* comparison  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_unary = 74,                     /* unary  */
  YYSYMBOL_call = 75,                      /* call  */
  YYSYMBOL_arguments = 76,                 /* arguments  */
  YYSYMBOL_primary = 77,                   /* primary  */
  YYSYMBOL_list_expr = 78,                 /* list_expr  */
  YYSYMBOL_dict_expr = 79                  /* dict_expr  */
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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    48,    51,    55,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    73,    76,    80,    84,
      88,    92,    98,   102,   109,   113,   118,   124,   130,   139,
     144,   153,   158,   165,   170,   175,   183,   188,   195,   199,
     204,   209,   213,   220,   223,   224,   231,   232,   239,   240,
     245,   252,   253,   258,   263,   268,   275,   276,   281,   288,
     289,   294,   299,   306,   307,   311,   317,   318,   322,   328,
     332,   338,   343,   348,   351,   354,   357,   360,   363,   366,
     371,   375,   380
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
  "\"end of file\"", "error", "\"invalid token\"", "INT_NUM", "FLOAT_NUM",
  "BOOL", "IDENTIFIER", "STRING", "NEWLINE", "INDENT", "DEDENT", "IF",
  "ELSE", "ELIF", "WHILE", "FOR", "IN", "DEF", "RETURN", "IMPORT", "NONE",
  "RANGE", "PRINT", "AND", "OR", "NOT", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "MODULO", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "TIMES_ASSIGN",
  "DIVIDE_ASSIGN", "EQ", "NEQ", "LT", "GT", "LE", "GE", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COLON", "COMMA", "$accept",
  "program", "statement_list", "statement", "expression_stmt",
  "assignment_stmt", "print_stmt", "suite", "if_stmt", "elif_clauses",
  "else_clause", "while_stmt", "for_stmt", "function_def", "return_stmt",
  "import_stmt", "parameters", "expression", "logical_or", "logical_and",
  "equality", "comparison", "term", "factor", "unary", "call", "arguments",
  "primary", "list_expr", "dict_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     134,   -89,   -89,   -89,   -15,   -89,   -89,   225,   225,    15,
      30,   159,    40,   -89,   250,   225,   225,   225,   165,    10,
      58,   134,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,    54,    44,    48,    -2,    -8,    18,    -4,   -89,
     -89,   -89,   -89,   -89,   225,   225,   225,   225,   225,   192,
      31,    24,    26,    60,    39,   -89,    72,    74,     7,    75,
     -89,   -89,    43,   -89,   -89,   -40,   -89,   -89,   -89,   -89,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,    76,    88,    89,    92,    97,   -89,   -35,
      99,    99,   219,     0,   -89,   -89,   -89,   -89,   -89,   -89,
     225,    48,    -2,    -8,    -8,    18,    18,    18,    18,    -4,
      -4,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     101,    38,   -89,    66,    64,   -89,    65,   -21,   -89,   134,
      67,   225,    41,   -89,   225,    99,    99,    68,   108,    84,
      99,    69,   225,   -89,   -20,   -89,   -89,    99,   -89,   -89,
     -89,    99,    70,    71,   225,   -89,   -89,    99,    99,    78,
     -89,   -89,    77,    99,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    71,    72,    74,    76,    73,    15,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     6,     7,    14,     8,     9,    10,    11,
      12,    13,     0,    43,    44,    46,    48,    51,    56,    59,
      63,    66,    78,    79,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    39,     0,     0,    76,     0,
      65,    64,     0,    81,    69,     0,    82,     1,     5,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,    38,    40,    23,    22,    77,    80,
       0,    45,    47,    49,    50,    52,    53,    54,    55,    57,
      58,    60,    61,    62,    17,    18,    19,    20,    21,    67,
       0,    25,    32,     0,     0,    41,     0,     0,    70,     0,
       0,     0,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    33,    37,     0,    42,    24,
      31,     0,     0,     0,     0,    36,    29,     0,     0,     0,
      30,    34,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,    -6,   -19,   -89,   -89,   -89,   -88,   -89,   -89,
      -1,   -89,   -89,   -89,   -89,   -89,   -89,    -7,   -89,    52,
      61,   -17,   -10,   -18,    -3,   -89,    80,   -89,   -89,   -89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,    23,    24,    25,   121,    26,   132,
     133,    27,    28,    29,    30,    31,   127,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    65,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    52,    68,   122,    56,    99,   125,    59,   119,   100,
      62,    64,    60,    61,   100,    96,    44,    45,    46,    47,
      48,    53,   137,   153,    80,    81,    82,    49,   138,   154,
      74,    75,    76,    77,    72,    73,    54,    83,    84,    85,
      86,    87,    64,   126,    78,    79,    57,   145,   146,    49,
     130,   131,   150,   130,   142,   103,   104,    66,    67,   155,
     109,   110,    69,   156,   105,   106,   107,   108,    70,   160,
     161,    71,    90,    49,    91,   164,    92,   111,   112,   113,
      94,    93,    95,    97,   114,   124,    98,     1,     2,     3,
       4,     5,     6,   128,   149,     7,   115,   116,     8,     9,
     117,    10,    11,    12,    13,   118,    14,   120,   134,    15,
     129,    16,   135,   136,   148,   140,   147,   151,   157,   158,
      68,   162,   101,   139,   141,   163,    17,   144,    18,    89,
      19,   143,   102,     0,     0,   152,     0,     1,     2,     3,
       4,     5,     6,     0,     0,     7,     0,   159,     8,     9,
       0,    10,    11,    12,    13,     0,    14,     0,     0,    15,
       0,    16,     1,     2,     3,    50,     5,    55,     1,     2,
       3,    50,     5,     0,     0,     0,    17,     0,    18,    13,
      19,     0,     0,     0,    15,    13,    16,     0,     0,     0,
      15,     0,    16,     0,     0,     1,     2,     3,    50,     5,
       0,    17,     0,    18,     0,    19,     0,    17,     0,    18,
      63,    19,    13,     0,     0,     0,     0,    15,     0,    16,
       0,     0,     1,     2,     3,    50,     5,     0,     1,     2,
       3,    50,     5,     0,    17,    88,    18,     0,    19,    13,
     123,     0,     0,     0,    15,    13,    16,     0,     0,     0,
      15,     0,    16,     1,     2,     3,    58,     5,     0,     0,
       0,    17,     0,    18,     0,    19,     0,    17,     0,    18,
      13,    19,     0,     0,     0,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,    18,     0,    19
};

static const yytype_int16 yycheck[] =
{
       7,     8,    21,    91,    11,    45,     6,    14,    43,    49,
      17,    18,    15,    16,    49,     8,    31,    32,    33,    34,
      35,     6,    43,    43,    28,    29,    30,    42,    49,    49,
      38,    39,    40,    41,    36,    37,     6,    44,    45,    46,
      47,    48,    49,    43,    26,    27,     6,   135,   136,    42,
      12,    13,   140,    12,    13,    72,    73,    47,     0,   147,
      78,    79,     8,   151,    74,    75,    76,    77,    24,   157,
     158,    23,    48,    42,    48,   163,    16,    80,    81,    82,
       8,    42,     8,     8,     8,    92,    43,     3,     4,     5,
       6,     7,     8,   100,    10,    11,     8,     8,    14,    15,
       8,    17,    18,    19,    20,     8,    22,     8,    42,    25,
       9,    27,    48,    48,     6,    48,    48,    48,    48,    48,
     139,    43,    70,   129,   131,    48,    42,   134,    44,    49,
      46,   132,    71,    -1,    -1,   142,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    -1,   154,    14,    15,
      -1,    17,    18,    19,    20,    -1,    22,    -1,    -1,    25,
      -1,    27,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    42,    -1,    44,    20,
      46,    -1,    -1,    -1,    25,    20,    27,    -1,    -1,    -1,
      25,    -1,    27,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    42,    -1,    44,    -1,    46,    -1,    42,    -1,    44,
      45,    46,    20,    -1,    -1,    -1,    -1,    25,    -1,    27,
      -1,    -1,     3,     4,     5,     6,     7,    -1,     3,     4,
       5,     6,     7,    -1,    42,    43,    44,    -1,    46,    20,
      21,    -1,    -1,    -1,    25,    20,    27,    -1,    -1,    -1,
      25,    -1,    27,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    42,    -1,    44,    -1,    46,    -1,    42,    -1,    44,
      20,    46,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    11,    14,    15,
      17,    18,    19,    20,    22,    25,    27,    42,    44,    46,
      51,    52,    53,    54,    55,    56,    58,    61,    62,    63,
      64,    65,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    77,    78,    79,    31,    32,    33,    34,    35,    42,
       6,    67,    67,     6,     6,     8,    67,     6,     6,    67,
      74,    74,    67,    45,    67,    76,    47,     0,    53,     8,
      24,    23,    36,    37,    38,    39,    40,    41,    26,    27,
      28,    29,    30,    67,    67,    67,    67,    67,    43,    76,
      48,    48,    16,    42,     8,     8,     8,     8,    43,    45,
      49,    69,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    74,    74,    74,     8,     8,     8,     8,     8,    43,
       8,    57,    57,    21,    67,     6,    43,    66,    67,     9,
      12,    13,    59,    60,    42,    48,    48,    43,    49,    52,
      48,    67,    13,    60,    67,    57,    57,    48,     6,    10,
      57,    48,    67,    43,    49,    57,    57,    48,    48,    67,
      57,    57,    43,    48,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    55,    55,    55,
      55,    55,    56,    56,    57,    58,    58,    58,    58,    59,
      59,    60,    61,    62,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     3,     3,     4,     4,     5,     5,     6,     4,
       5,     3,     4,     6,     9,    11,     7,     6,     3,     2,
       3,     1,     3,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     4,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     2,     2
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
  case 2: /* program: statement_list  */
#line 47 "src/parser.y"
                                 { ast_root = (yyvsp[0].node); }
#line 1289 "src/parser.c"
    break;

  case 3: /* program: %empty  */
#line 48 "src/parser.y"
                                 { ast_root = create_node(AST_STATEMENT_LIST, NULL); }
#line 1295 "src/parser.c"
    break;

  case 4: /* statement_list: statement  */
#line 51 "src/parser.y"
                                 { 
                                   (yyval.node) = create_node(AST_STATEMENT_LIST, NULL); 
                                   if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node)); 
                                 }
#line 1304 "src/parser.c"
    break;

  case 5: /* statement_list: statement_list statement  */
#line 55 "src/parser.y"
                                         { 
                                   (yyval.node) = (yyvsp[-1].node); 
                                   if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node)); 
                                 }
#line 1313 "src/parser.c"
    break;

  case 6: /* statement: expression_stmt  */
#line 61 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1319 "src/parser.c"
    break;

  case 7: /* statement: assignment_stmt  */
#line 62 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1325 "src/parser.c"
    break;

  case 8: /* statement: if_stmt  */
#line 63 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1331 "src/parser.c"
    break;

  case 9: /* statement: while_stmt  */
#line 64 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1337 "src/parser.c"
    break;

  case 10: /* statement: for_stmt  */
#line 65 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1343 "src/parser.c"
    break;

  case 11: /* statement: function_def  */
#line 66 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1349 "src/parser.c"
    break;

  case 12: /* statement: return_stmt  */
#line 67 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1355 "src/parser.c"
    break;

  case 13: /* statement: import_stmt  */
#line 68 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1361 "src/parser.c"
    break;

  case 14: /* statement: print_stmt  */
#line 69 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1367 "src/parser.c"
    break;

  case 15: /* statement: NEWLINE  */
#line 70 "src/parser.y"
                                 { (yyval.node) = NULL; }
#line 1373 "src/parser.c"
    break;

  case 16: /* expression_stmt: expression NEWLINE  */
#line 73 "src/parser.y"
                                    { (yyval.node) = create_node(AST_EXPR_STMT, NULL); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1379 "src/parser.c"
    break;

  case 17: /* assignment_stmt: IDENTIFIER ASSIGN expression NEWLINE  */
#line 76 "src/parser.y"
                                                      { 
                    (yyval.node) = create_node(AST_ASSIGNMENT, (yyvsp[-3].sval)); 
                    add_child((yyval.node), (yyvsp[-1].node)); 
                }
#line 1388 "src/parser.c"
    break;

  case 18: /* assignment_stmt: IDENTIFIER PLUS_ASSIGN expression NEWLINE  */
#line 80 "src/parser.y"
                                                           {
                    (yyval.node) = create_node(AST_PLUS_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1397 "src/parser.c"
    break;

  case 19: /* assignment_stmt: IDENTIFIER MINUS_ASSIGN expression NEWLINE  */
#line 84 "src/parser.y"
                                                            {
                    (yyval.node) = create_node(AST_MINUS_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1406 "src/parser.c"
    break;

  case 20: /* assignment_stmt: IDENTIFIER TIMES_ASSIGN expression NEWLINE  */
#line 88 "src/parser.y"
                                                            {
                    (yyval.node) = create_node(AST_TIMES_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1415 "src/parser.c"
    break;

  case 21: /* assignment_stmt: IDENTIFIER DIVIDE_ASSIGN expression NEWLINE  */
#line 92 "src/parser.y"
                                                             {
                    (yyval.node) = create_node(AST_DIVIDE_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1424 "src/parser.c"
    break;

  case 22: /* print_stmt: PRINT expression NEWLINE  */
#line 98 "src/parser.y"
                                     {
             (yyval.node) = create_node(AST_PRINT, NULL);
             add_child((yyval.node), (yyvsp[-1].node));
           }
#line 1433 "src/parser.c"
    break;

  case 23: /* print_stmt: PRINT IDENTIFIER NEWLINE  */
#line 102 "src/parser.y"
                                     {
             (yyval.node) = create_node(AST_PRINT, NULL);
             add_child((yyval.node), create_node(AST_IDENTIFIER, (yyvsp[-1].sval)));
           }
#line 1442 "src/parser.c"
    break;

  case 24: /* suite: NEWLINE INDENT statement_list DEDENT  */
#line 109 "src/parser.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1448 "src/parser.c"
    break;

  case 25: /* if_stmt: IF expression COLON suite  */
#line 113 "src/parser.y"
                                   { 
           (yyval.node) = create_node(AST_IF, NULL);
           add_child((yyval.node), (yyvsp[-2].node)); // condition
           add_child((yyval.node), (yyvsp[0].node)); // body
         }
#line 1458 "src/parser.c"
    break;

  case 26: /* if_stmt: IF expression COLON suite elif_clauses  */
#line 118 "src/parser.y"
                                                {
           (yyval.node) = create_node(AST_IF_ELIF, NULL);
           add_child((yyval.node), (yyvsp[-3].node)); // if condition
           add_child((yyval.node), (yyvsp[-1].node)); // if body
           add_child((yyval.node), (yyvsp[0].node)); // elif chain
         }
#line 1469 "src/parser.c"
    break;

  case 27: /* if_stmt: IF expression COLON suite else_clause  */
#line 124 "src/parser.y"
                                               {
           (yyval.node) = create_node(AST_IF_ELSE, NULL);
           add_child((yyval.node), (yyvsp[-3].node)); // condition
           add_child((yyval.node), (yyvsp[-1].node)); // if body
           add_child((yyval.node), (yyvsp[0].node)); // else body
         }
#line 1480 "src/parser.c"
    break;

  case 28: /* if_stmt: IF expression COLON suite elif_clauses else_clause  */
#line 130 "src/parser.y"
                                                            {
           (yyval.node) = create_node(AST_IF_ELIF_ELSE, NULL);
           add_child((yyval.node), (yyvsp[-4].node)); // if condition
           add_child((yyval.node), (yyvsp[-2].node)); // if body
           add_child((yyval.node), (yyvsp[-1].node)); // elif chain
           add_child((yyval.node), (yyvsp[0].node)); // else body
         }
#line 1492 "src/parser.c"
    break;

  case 29: /* elif_clauses: ELIF expression COLON suite  */
#line 139 "src/parser.y"
                                          {
               (yyval.node) = create_node(AST_ELIF, NULL);
               add_child((yyval.node), (yyvsp[-2].node)); // condition
               add_child((yyval.node), (yyvsp[0].node)); // body
             }
#line 1502 "src/parser.c"
    break;

  case 30: /* elif_clauses: elif_clauses ELIF expression COLON suite  */
#line 144 "src/parser.y"
                                                      {
               (yyval.node) = (yyvsp[-4].node);
               ASTNode *elif_node = create_node(AST_ELIF, NULL);
               add_child(elif_node, (yyvsp[-2].node)); // condition
               add_child(elif_node, (yyvsp[0].node)); // body
               add_child((yyval.node), elif_node);
             }
#line 1514 "src/parser.c"
    break;

  case 31: /* else_clause: ELSE COLON suite  */
#line 153 "src/parser.y"
                              {
              (yyval.node) = (yyvsp[0].node); // Just return the statements in the else block
            }
#line 1522 "src/parser.c"
    break;

  case 32: /* while_stmt: WHILE expression COLON suite  */
#line 158 "src/parser.y"
                                         {
             (yyval.node) = create_node(AST_WHILE, NULL);
             add_child((yyval.node), (yyvsp[-2].node)); // condition
             add_child((yyval.node), (yyvsp[0].node)); // body
           }
#line 1532 "src/parser.c"
    break;

  case 33: /* for_stmt: FOR IDENTIFIER IN expression COLON suite  */
#line 165 "src/parser.y"
                                                   {
            (yyval.node) = create_node(AST_FOR, (yyvsp[-4].sval));
            add_child((yyval.node), (yyvsp[-2].node)); // iterable
            add_child((yyval.node), (yyvsp[0].node)); // body
          }
#line 1542 "src/parser.c"
    break;

  case 34: /* for_stmt: FOR IDENTIFIER IN RANGE LPAREN expression RPAREN COLON suite  */
#line 170 "src/parser.y"
                                                                       {
            (yyval.node) = create_node(AST_FOR_RANGE, (yyvsp[-7].sval));
            add_child((yyval.node), (yyvsp[-3].node)); // range expression
            add_child((yyval.node), (yyvsp[0].node)); // body
          }
#line 1552 "src/parser.c"
    break;

  case 35: /* for_stmt: FOR IDENTIFIER IN RANGE LPAREN expression COMMA expression RPAREN COLON suite  */
#line 175 "src/parser.y"
                                                                                        {
            (yyval.node) = create_node(AST_FOR_RANGE, (yyvsp[-9].sval));
            add_child((yyval.node), (yyvsp[-5].node)); // start
            add_child((yyval.node), (yyvsp[-3].node)); // end
            add_child((yyval.node), (yyvsp[0].node)); // body
          }
#line 1563 "src/parser.c"
    break;

  case 36: /* function_def: DEF IDENTIFIER LPAREN parameters RPAREN COLON suite  */
#line 183 "src/parser.y"
                                                                  {
               (yyval.node) = create_node(AST_FUNCTION_DEF, (yyvsp[-5].sval));
               add_child((yyval.node), (yyvsp[-3].node)); // parameters
               add_child((yyval.node), (yyvsp[0].node)); // body
             }
#line 1573 "src/parser.c"
    break;

  case 37: /* function_def: DEF IDENTIFIER LPAREN RPAREN COLON suite  */
#line 188 "src/parser.y"
                                                      {
               (yyval.node) = create_node(AST_FUNCTION_DEF, (yyvsp[-4].sval));
               add_child((yyval.node), create_node(AST_PARAMETERS, NULL)); // empty parameters
               add_child((yyval.node), (yyvsp[0].node)); // body
             }
#line 1583 "src/parser.c"
    break;

  case 38: /* return_stmt: RETURN expression NEWLINE  */
#line 195 "src/parser.y"
                                       {
              (yyval.node) = create_node(AST_RETURN, NULL);
              add_child((yyval.node), (yyvsp[-1].node));
            }
#line 1592 "src/parser.c"
    break;

  case 39: /* return_stmt: RETURN NEWLINE  */
#line 199 "src/parser.y"
                           {
              (yyval.node) = create_node(AST_RETURN, NULL);
            }
#line 1600 "src/parser.c"
    break;

  case 40: /* import_stmt: IMPORT IDENTIFIER NEWLINE  */
#line 204 "src/parser.y"
                                       {
              (yyval.node) = create_node(AST_IMPORT, (yyvsp[-1].sval));
            }
#line 1608 "src/parser.c"
    break;

  case 41: /* parameters: IDENTIFIER  */
#line 209 "src/parser.y"
                       {
              (yyval.node) = create_node(AST_PARAMETERS, NULL);
              add_child((yyval.node), create_node(AST_IDENTIFIER, (yyvsp[0].sval)));
            }
#line 1617 "src/parser.c"
    break;

  case 42: /* parameters: parameters COMMA IDENTIFIER  */
#line 213 "src/parser.y"
                                        {
              (yyval.node) = (yyvsp[-2].node);
              add_child((yyval.node), create_node(AST_IDENTIFIER, (yyvsp[0].sval)));
            }
#line 1626 "src/parser.c"
    break;

  case 43: /* expression: logical_or  */
#line 220 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1632 "src/parser.c"
    break;

  case 44: /* logical_or: logical_and  */
#line 223 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1638 "src/parser.c"
    break;

  case 45: /* logical_or: logical_or OR logical_and  */
#line 224 "src/parser.y"
                                      {
              (yyval.node) = create_node(AST_OR, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1648 "src/parser.c"
    break;

  case 46: /* logical_and: equality  */
#line 231 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1654 "src/parser.c"
    break;

  case 47: /* logical_and: logical_and AND equality  */
#line 232 "src/parser.y"
                                      {
              (yyval.node) = create_node(AST_AND, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1664 "src/parser.c"
    break;

  case 48: /* equality: comparison  */
#line 239 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1670 "src/parser.c"
    break;

  case 49: /* equality: equality EQ comparison  */
#line 240 "src/parser.y"
                                 {
            (yyval.node) = create_node(AST_EQ, NULL);
            add_child((yyval.node), (yyvsp[-2].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1680 "src/parser.c"
    break;

  case 50: /* equality: equality NEQ comparison  */
#line 245 "src/parser.y"
                                  {
            (yyval.node) = create_node(AST_NEQ, NULL);
            add_child((yyval.node), (yyvsp[-2].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1690 "src/parser.c"
    break;

  case 51: /* comparison: term  */
#line 252 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1696 "src/parser.c"
    break;

  case 52: /* comparison: comparison LT term  */
#line 253 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_LT, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1706 "src/parser.c"
    break;

  case 53: /* comparison: comparison GT term  */
#line 258 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_GT, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1716 "src/parser.c"
    break;

  case 54: /* comparison: comparison LE term  */
#line 263 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_LE, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1726 "src/parser.c"
    break;

  case 55: /* comparison: comparison GE term  */
#line 268 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_GE, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1736 "src/parser.c"
    break;

  case 56: /* term: factor  */
#line 275 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1742 "src/parser.c"
    break;

  case 57: /* term: term PLUS factor  */
#line 276 "src/parser.y"
                       {
        (yyval.node) = create_node(AST_ADD, NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
      }
#line 1752 "src/parser.c"
    break;

  case 58: /* term: term MINUS factor  */
#line 281 "src/parser.y"
                        {
        (yyval.node) = create_node(AST_SUB, NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
      }
#line 1762 "src/parser.c"
    break;

  case 59: /* factor: unary  */
#line 288 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1768 "src/parser.c"
    break;

  case 60: /* factor: factor TIMES unary  */
#line 289 "src/parser.y"
                           {
          (yyval.node) = create_node(AST_MUL, NULL);
          add_child((yyval.node), (yyvsp[-2].node));
          add_child((yyval.node), (yyvsp[0].node));
        }
#line 1778 "src/parser.c"
    break;

  case 61: /* factor: factor DIVIDE unary  */
#line 294 "src/parser.y"
                            {
          (yyval.node) = create_node(AST_DIV, NULL);
          add_child((yyval.node), (yyvsp[-2].node));
          add_child((yyval.node), (yyvsp[0].node));
        }
#line 1788 "src/parser.c"
    break;

  case 62: /* factor: factor MODULO unary  */
#line 299 "src/parser.y"
                            {
          (yyval.node) = create_node(AST_MOD, NULL);
          add_child((yyval.node), (yyvsp[-2].node));
          add_child((yyval.node), (yyvsp[0].node));
        }
#line 1798 "src/parser.c"
    break;

  case 63: /* unary: call  */
#line 306 "src/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1804 "src/parser.c"
    break;

  case 64: /* unary: MINUS unary  */
#line 307 "src/parser.y"
                   {
         (yyval.node) = create_node(AST_NEG, NULL);
         add_child((yyval.node), (yyvsp[0].node));
       }
#line 1813 "src/parser.c"
    break;

  case 65: /* unary: NOT unary  */
#line 311 "src/parser.y"
                 {
         (yyval.node) = create_node(AST_NOT, NULL);
         add_child((yyval.node), (yyvsp[0].node));
       }
#line 1822 "src/parser.c"
    break;

  case 66: /* call: primary  */
#line 317 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1828 "src/parser.c"
    break;

  case 67: /* call: IDENTIFIER LPAREN arguments RPAREN  */
#line 318 "src/parser.y"
                                         {
        (yyval.node) = create_node(AST_CALL, (yyvsp[-3].sval));
        add_child((yyval.node), (yyvsp[-1].node));
      }
#line 1837 "src/parser.c"
    break;

  case 68: /* call: IDENTIFIER LPAREN RPAREN  */
#line 322 "src/parser.y"
                               {
        (yyval.node) = create_node(AST_CALL, (yyvsp[-2].sval));
        add_child((yyval.node), create_node(AST_ARGUMENTS, NULL)); // empty args
      }
#line 1846 "src/parser.c"
    break;

  case 69: /* arguments: expression  */
#line 328 "src/parser.y"
                      {
            (yyval.node) = create_node(AST_ARGUMENTS, NULL);
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1855 "src/parser.c"
    break;

  case 70: /* arguments: arguments COMMA expression  */
#line 332 "src/parser.y"
                                      {
            (yyval.node) = (yyvsp[-2].node);
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1864 "src/parser.c"
    break;

  case 71: /* primary: INT_NUM  */
#line 338 "src/parser.y"
                 {
          char str[32];
          sprintf(str, "%d", (yyvsp[0].ival));
          (yyval.node) = create_node(AST_INT, strdup(str));
        }
#line 1874 "src/parser.c"
    break;

  case 72: /* primary: FLOAT_NUM  */
#line 343 "src/parser.y"
                   {
          char str[32];
          sprintf(str, "%f", (yyvsp[0].fval));
          (yyval.node) = create_node(AST_FLOAT, strdup(str));
        }
#line 1884 "src/parser.c"
    break;

  case 73: /* primary: STRING  */
#line 348 "src/parser.y"
                {
          (yyval.node) = create_node(AST_STRING, (yyvsp[0].sval));
        }
#line 1892 "src/parser.c"
    break;

  case 74: /* primary: BOOL  */
#line 351 "src/parser.y"
              {
          (yyval.node) = create_node(AST_BOOL, (yyvsp[0].bval) ? "True" : "False");
        }
#line 1900 "src/parser.c"
    break;

  case 75: /* primary: NONE  */
#line 354 "src/parser.y"
              {
          (yyval.node) = create_node(AST_NONE, "None");
        }
#line 1908 "src/parser.c"
    break;

  case 76: /* primary: IDENTIFIER  */
#line 357 "src/parser.y"
                    {
          (yyval.node) = create_node(AST_IDENTIFIER, (yyvsp[0].sval));
        }
#line 1916 "src/parser.c"
    break;

  case 77: /* primary: LPAREN expression RPAREN  */
#line 360 "src/parser.y"
                                  {
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1924 "src/parser.c"
    break;

  case 78: /* primary: list_expr  */
#line 363 "src/parser.y"
                   {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1932 "src/parser.c"
    break;

  case 79: /* primary: dict_expr  */
#line 366 "src/parser.y"
                   {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1940 "src/parser.c"
    break;

  case 80: /* list_expr: LBRACKET arguments RBRACKET  */
#line 371 "src/parser.y"
                                       {
            (yyval.node) = create_node(AST_LIST, NULL);
            add_child((yyval.node), (yyvsp[-1].node));
          }
#line 1949 "src/parser.c"
    break;

  case 81: /* list_expr: LBRACKET RBRACKET  */
#line 375 "src/parser.y"
                             {
            (yyval.node) = create_node(AST_LIST, NULL);
          }
#line 1957 "src/parser.c"
    break;

  case 82: /* dict_expr: LBRACE RBRACE  */
#line 380 "src/parser.y"
                         {
            (yyval.node) = create_node(AST_DICT, NULL);
          }
#line 1965 "src/parser.c"
    break;


#line 1969 "src/parser.c"

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

#line 385 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}
