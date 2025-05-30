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

#line 87 "src/parser.tab.c"

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

#include "parser.tab.h"
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
  YYSYMBOL_IFX = 50,                       /* IFX  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_extra_newlines = 53,            /* extra_newlines  */
  YYSYMBOL_statement_list = 54,            /* statement_list  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_expression_stmt = 56,           /* expression_stmt  */
  YYSYMBOL_assignment_stmt = 57,           /* assignment_stmt  */
  YYSYMBOL_print_stmt = 58,                /* print_stmt  */
  YYSYMBOL_suite = 59,                     /* suite  */
  YYSYMBOL_if_stmt = 60,                   /* if_stmt  */
  YYSYMBOL_elif_else_opt = 61,             /* elif_else_opt  */
  YYSYMBOL_while_stmt = 62,                /* while_stmt  */
  YYSYMBOL_for_stmt = 63,                  /* for_stmt  */
  YYSYMBOL_function_def = 64,              /* function_def  */
  YYSYMBOL_return_stmt = 65,               /* return_stmt  */
  YYSYMBOL_import_stmt = 66,               /* import_stmt  */
  YYSYMBOL_parameters = 67,                /* parameters  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_logical_or = 69,                /* logical_or  */
  YYSYMBOL_logical_and = 70,               /* logical_and  */
  YYSYMBOL_equality = 71,                  /* equality  */
  YYSYMBOL_comparison = 72,                /* comparison  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_unary = 75,                     /* unary  */
  YYSYMBOL_call = 76,                      /* call  */
  YYSYMBOL_arguments = 77,                 /* arguments  */
  YYSYMBOL_primary = 78,                   /* primary  */
  YYSYMBOL_list_expr = 79,                 /* list_expr  */
  YYSYMBOL_dict_expr = 80                  /* dict_expr  */
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    52,    58,    59,    60,    65,    69,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    88,
      91,    95,    99,   103,   107,   113,   120,   124,   133,   134,
     140,   146,   153,   158,   163,   171,   176,   183,   187,   192,
     197,   201,   208,   211,   212,   219,   220,   227,   228,   233,
     240,   241,   246,   251,   256,   263,   264,   269,   276,   277,
     282,   287,   294,   295,   299,   305,   306,   310,   316,   320,
     326,   331,   336,   339,   342,   345,   348,   351,   354,   359,
     363,   368
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
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COLON", "COMMA", "IFX",
  "$accept", "program", "extra_newlines", "statement_list", "statement",
  "expression_stmt", "assignment_stmt", "print_stmt", "suite", "if_stmt",
  "elif_else_opt", "while_stmt", "for_stmt", "function_def", "return_stmt",
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
     134,   -89,   -89,   -89,   -17,   -89,   -89,   217,   217,     2,
      13,    26,    49,   -89,   217,   217,   217,   217,   159,    20,
      69,   134,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,    74,    59,    61,   -13,    24,     9,    30,   -89,
     -89,   -89,   -89,   -89,   217,   217,   217,   217,   217,   165,
      44,    39,    40,    73,    48,   -89,    83,    91,    94,   -89,
     -89,    60,   -89,   -89,   -40,   -89,   -89,    46,   -89,   -89,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,    98,   103,   105,   106,   108,   -89,   -23,
     110,   110,   192,     0,   -89,   -89,   -89,   -89,   -89,   217,
     -89,   -89,    61,   -13,    24,    24,     9,     9,     9,     9,
      30,    30,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   112,    32,   -89,    77,    75,   -89,    76,   -22,   -89,
     134,    78,   217,   -89,   217,   110,   110,    80,   116,    90,
     110,    81,   -21,   -89,   -89,   110,   -89,   -89,   -89,   110,
      82,   217,   -89,    32,   110,    88,   -89,   -89,    85,   110,
     -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    70,    71,    73,    75,    72,    18,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     4,     7,     9,    10,    17,    11,    12,    13,    14,
      15,    16,     0,    42,    43,    45,    47,    50,    55,    58,
      62,    65,    77,    78,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,    38,     0,     0,     0,    64,
      63,     0,    80,    68,     0,    81,     1,     2,     8,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,    37,    39,    25,    76,    79,     0,
       5,     6,    44,    46,    48,    49,    51,    52,    53,    54,
      56,    57,    59,    60,    61,    20,    21,    22,    23,    24,
      66,     0,    28,    31,     0,     0,    40,     0,     0,    69,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    36,     0,    41,    26,    30,     0,
       0,     0,    35,    28,     0,     0,    29,    33,     0,     0,
      34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,     5,   -19,   -89,   -89,   -89,   -88,   -89,
     -10,   -89,   -89,   -89,   -89,   -89,   -89,    -7,   -89,    87,
      79,     8,    -1,   -29,    -3,   -89,    97,   -89,   -89,   -89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    67,    21,    22,    23,    24,    25,   122,    26,
     133,    27,    28,    29,    30,    31,   128,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    64,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    52,    68,   123,    56,    98,   126,    58,    53,    99,
      61,    63,    59,    60,    44,    45,    46,    47,    48,    54,
     120,   137,   150,    72,    73,    49,    99,   138,   151,     1,
       2,     3,    50,     5,    55,    78,    79,    83,    84,    85,
      86,    87,    63,   127,   131,   132,    13,   143,   144,   110,
     111,    15,   148,    16,   100,    57,   101,   152,    80,    81,
      82,   153,    74,    75,    76,    77,   157,    65,    17,    66,
      18,   160,    19,   106,   107,   108,   109,   112,   113,   114,
     104,   105,    69,    70,    71,   125,    49,    90,    91,    92,
      93,    94,   129,     1,     2,     3,     4,     5,     6,    95,
     147,     7,    96,    97,     8,     9,   115,    10,    11,    12,
      13,   116,    14,   117,   118,    15,   119,    16,   121,   134,
      68,   130,   146,   135,   136,   141,   140,   142,   145,   149,
     154,   158,    17,   159,    18,   139,    19,     1,     2,     3,
       4,     5,     6,   156,   155,     7,    89,     0,     8,     9,
     103,    10,    11,    12,    13,     0,    14,   102,     0,    15,
       0,    16,     1,     2,     3,    50,     5,     0,     1,     2,
       3,    50,     5,     0,     0,     0,    17,     0,    18,    13,
      19,     0,     0,     0,    15,    13,    16,     0,     0,     0,
      15,     0,    16,     0,     0,     1,     2,     3,    50,     5,
       0,    17,     0,    18,    62,    19,     0,    17,    88,    18,
       0,    19,    13,   124,     0,     0,     0,    15,     0,    16,
       1,     2,     3,    50,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,    18,    13,    19,     0,
       0,     0,    15,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,    18,     0,    19
};

static const yytype_int16 yycheck[] =
{
       7,     8,    21,    91,    11,    45,     6,    14,     6,    49,
      17,    18,    15,    16,    31,    32,    33,    34,    35,     6,
      43,    43,    43,    36,    37,    42,    49,    49,    49,     3,
       4,     5,     6,     7,     8,    26,    27,    44,    45,    46,
      47,    48,    49,    43,    12,    13,    20,   135,   136,    78,
      79,    25,   140,    27,     8,     6,    10,   145,    28,    29,
      30,   149,    38,    39,    40,    41,   154,    47,    42,     0,
      44,   159,    46,    74,    75,    76,    77,    80,    81,    82,
      72,    73,     8,    24,    23,    92,    42,    48,    48,    16,
      42,     8,    99,     3,     4,     5,     6,     7,     8,     8,
      10,    11,     8,    43,    14,    15,     8,    17,    18,    19,
      20,     8,    22,     8,     8,    25,     8,    27,     8,    42,
     139,     9,     6,    48,    48,   132,    48,   134,    48,    48,
      48,    43,    42,    48,    44,   130,    46,     3,     4,     5,
       6,     7,     8,   153,   151,    11,    49,    -1,    14,    15,
      71,    17,    18,    19,    20,    -1,    22,    70,    -1,    25,
      -1,    27,     3,     4,     5,     6,     7,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    42,    -1,    44,    20,
      46,    -1,    -1,    -1,    25,    20,    27,    -1,    -1,    -1,
      25,    -1,    27,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    42,    -1,    44,    45,    46,    -1,    42,    43,    44,
      -1,    46,    20,    21,    -1,    -1,    -1,    25,    -1,    27,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    44,    20,    46,    -1,
      -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    11,    14,    15,
      17,    18,    19,    20,    22,    25,    27,    42,    44,    46,
      52,    54,    55,    56,    57,    58,    60,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    78,    79,    80,    31,    32,    33,    34,    35,    42,
       6,    68,    68,     6,     6,     8,    68,     6,    68,    75,
      75,    68,    45,    68,    77,    47,     0,    53,    55,     8,
      24,    23,    36,    37,    38,    39,    40,    41,    26,    27,
      28,    29,    30,    68,    68,    68,    68,    68,    43,    77,
      48,    48,    16,    42,     8,     8,     8,    43,    45,    49,
       8,    10,    70,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    75,    75,    75,     8,     8,     8,     8,     8,
      43,     8,    59,    59,    21,    68,     6,    43,    67,    68,
       9,    12,    13,    61,    42,    48,    48,    43,    49,    54,
      48,    68,    68,    59,    59,    48,     6,    10,    59,    48,
      43,    49,    59,    59,    48,    68,    61,    59,    43,    48,
      59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    57,    57,    57,    58,    59,    60,    61,    61,
      61,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    76,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     3,     4,     5,     0,     5,
       3,     4,     6,     9,    11,     7,     6,     3,     2,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     1,     4,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       2,     2
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
  case 2: /* program: statement_list extra_newlines  */
#line 49 "src/parser.y"
                                  {
        ast_root = (yyvsp[-1].node);
    }
#line 1286 "src/parser.tab.c"
    break;

  case 3: /* program: %empty  */
#line 52 "src/parser.y"
           {
        ast_root = create_node(AST_STATEMENT_LIST, NULL);
    }
#line 1294 "src/parser.tab.c"
    break;

  case 7: /* statement_list: statement  */
#line 65 "src/parser.y"
              {
        (yyval.node) = create_node(AST_STATEMENT_LIST, NULL);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1303 "src/parser.tab.c"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 69 "src/parser.y"
                             {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1312 "src/parser.tab.c"
    break;

  case 9: /* statement: expression_stmt  */
#line 76 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1318 "src/parser.tab.c"
    break;

  case 10: /* statement: assignment_stmt  */
#line 77 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1324 "src/parser.tab.c"
    break;

  case 11: /* statement: if_stmt  */
#line 78 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1330 "src/parser.tab.c"
    break;

  case 12: /* statement: while_stmt  */
#line 79 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1336 "src/parser.tab.c"
    break;

  case 13: /* statement: for_stmt  */
#line 80 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1342 "src/parser.tab.c"
    break;

  case 14: /* statement: function_def  */
#line 81 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1348 "src/parser.tab.c"
    break;

  case 15: /* statement: return_stmt  */
#line 82 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1354 "src/parser.tab.c"
    break;

  case 16: /* statement: import_stmt  */
#line 83 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1360 "src/parser.tab.c"
    break;

  case 17: /* statement: print_stmt  */
#line 84 "src/parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1366 "src/parser.tab.c"
    break;

  case 18: /* statement: NEWLINE  */
#line 85 "src/parser.y"
                                 { (yyval.node) = NULL; }
#line 1372 "src/parser.tab.c"
    break;

  case 19: /* expression_stmt: expression NEWLINE  */
#line 88 "src/parser.y"
                                    { (yyval.node) = create_node(AST_EXPR_STMT, NULL); add_child((yyval.node), (yyvsp[-1].node)); }
#line 1378 "src/parser.tab.c"
    break;

  case 20: /* assignment_stmt: IDENTIFIER ASSIGN expression NEWLINE  */
#line 91 "src/parser.y"
                                                      { 
                    (yyval.node) = create_node(AST_ASSIGNMENT, (yyvsp[-3].sval)); 
                    add_child((yyval.node), (yyvsp[-1].node)); 
                }
#line 1387 "src/parser.tab.c"
    break;

  case 21: /* assignment_stmt: IDENTIFIER PLUS_ASSIGN expression NEWLINE  */
#line 95 "src/parser.y"
                                                           {
                    (yyval.node) = create_node(AST_PLUS_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1396 "src/parser.tab.c"
    break;

  case 22: /* assignment_stmt: IDENTIFIER MINUS_ASSIGN expression NEWLINE  */
#line 99 "src/parser.y"
                                                            {
                    (yyval.node) = create_node(AST_MINUS_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1405 "src/parser.tab.c"
    break;

  case 23: /* assignment_stmt: IDENTIFIER TIMES_ASSIGN expression NEWLINE  */
#line 103 "src/parser.y"
                                                            {
                    (yyval.node) = create_node(AST_TIMES_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1414 "src/parser.tab.c"
    break;

  case 24: /* assignment_stmt: IDENTIFIER DIVIDE_ASSIGN expression NEWLINE  */
#line 107 "src/parser.y"
                                                             {
                    (yyval.node) = create_node(AST_DIVIDE_ASSIGN, (yyvsp[-3].sval));
                    add_child((yyval.node), (yyvsp[-1].node));
                }
#line 1423 "src/parser.tab.c"
    break;

  case 25: /* print_stmt: PRINT expression NEWLINE  */
#line 113 "src/parser.y"
                                     {
             (yyval.node) = create_node(AST_PRINT, NULL);
             add_child((yyval.node), (yyvsp[-1].node));
           }
#line 1432 "src/parser.tab.c"
    break;

  case 26: /* suite: NEWLINE INDENT statement_list DEDENT  */
#line 120 "src/parser.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1438 "src/parser.tab.c"
    break;

  case 27: /* if_stmt: IF expression COLON suite elif_else_opt  */
#line 124 "src/parser.y"
                                                           {
           (yyval.node) = create_node(AST_IF, NULL);
           add_child((yyval.node), (yyvsp[-3].node));
           add_child((yyval.node), (yyvsp[-1].node));
           if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
         }
#line 1449 "src/parser.tab.c"
    break;

  case 28: /* elif_else_opt: %empty  */
#line 133 "src/parser.y"
                { (yyval.node) = NULL; }
#line 1455 "src/parser.tab.c"
    break;

  case 29: /* elif_else_opt: ELIF expression COLON suite elif_else_opt  */
#line 134 "src/parser.y"
                                                   {
           (yyval.node) = create_node(AST_ELIF, NULL);
           add_child((yyval.node), (yyvsp[-3].node));
           add_child((yyval.node), (yyvsp[-1].node));
           if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
         }
#line 1466 "src/parser.tab.c"
    break;

  case 30: /* elif_else_opt: ELSE COLON suite  */
#line 140 "src/parser.y"
                          {
           (yyval.node) = create_node(AST_ELSE, NULL);
           add_child((yyval.node), (yyvsp[0].node));
         }
#line 1475 "src/parser.tab.c"
    break;

  case 31: /* while_stmt: WHILE expression COLON suite  */
#line 146 "src/parser.y"
                                         {
             (yyval.node) = create_node(AST_WHILE, NULL);
             add_child((yyval.node), (yyvsp[-2].node));
             add_child((yyval.node), (yyvsp[0].node));
           }
#line 1485 "src/parser.tab.c"
    break;

  case 32: /* for_stmt: FOR IDENTIFIER IN expression COLON suite  */
#line 153 "src/parser.y"
                                                   {
            (yyval.node) = create_node(AST_FOR, (yyvsp[-4].sval));
            add_child((yyval.node), (yyvsp[-2].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1495 "src/parser.tab.c"
    break;

  case 33: /* for_stmt: FOR IDENTIFIER IN RANGE LPAREN expression RPAREN COLON suite  */
#line 158 "src/parser.y"
                                                                       {
            (yyval.node) = create_node(AST_FOR_RANGE, (yyvsp[-7].sval));
            add_child((yyval.node), (yyvsp[-3].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1505 "src/parser.tab.c"
    break;

  case 34: /* for_stmt: FOR IDENTIFIER IN RANGE LPAREN expression COMMA expression RPAREN COLON suite  */
#line 163 "src/parser.y"
                                                                                        {
            (yyval.node) = create_node(AST_FOR_RANGE, (yyvsp[-9].sval));
            add_child((yyval.node), (yyvsp[-5].node));
            add_child((yyval.node), (yyvsp[-3].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1516 "src/parser.tab.c"
    break;

  case 35: /* function_def: DEF IDENTIFIER LPAREN parameters RPAREN COLON suite  */
#line 171 "src/parser.y"
                                                                  {
               (yyval.node) = create_node(AST_FUNCTION_DEF, (yyvsp[-5].sval));
               add_child((yyval.node), (yyvsp[-3].node));
               add_child((yyval.node), (yyvsp[0].node));
             }
#line 1526 "src/parser.tab.c"
    break;

  case 36: /* function_def: DEF IDENTIFIER LPAREN RPAREN COLON suite  */
#line 176 "src/parser.y"
                                                      {
               (yyval.node) = create_node(AST_FUNCTION_DEF, (yyvsp[-4].sval));
               add_child((yyval.node), create_node(AST_PARAMETERS, NULL));
               add_child((yyval.node), (yyvsp[0].node));
             }
#line 1536 "src/parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN expression NEWLINE  */
#line 183 "src/parser.y"
                                       {
              (yyval.node) = create_node(AST_RETURN, NULL);
              add_child((yyval.node), (yyvsp[-1].node));
            }
#line 1545 "src/parser.tab.c"
    break;

  case 38: /* return_stmt: RETURN NEWLINE  */
#line 187 "src/parser.y"
                           {
              (yyval.node) = create_node(AST_RETURN, NULL);
            }
#line 1553 "src/parser.tab.c"
    break;

  case 39: /* import_stmt: IMPORT IDENTIFIER NEWLINE  */
#line 192 "src/parser.y"
                                       {
              (yyval.node) = create_node(AST_IMPORT, (yyvsp[-1].sval));
            }
#line 1561 "src/parser.tab.c"
    break;

  case 40: /* parameters: IDENTIFIER  */
#line 197 "src/parser.y"
                       {
              (yyval.node) = create_node(AST_PARAMETERS, NULL);
              add_child((yyval.node), create_node(AST_IDENTIFIER, (yyvsp[0].sval)));
            }
#line 1570 "src/parser.tab.c"
    break;

  case 41: /* parameters: parameters COMMA IDENTIFIER  */
#line 201 "src/parser.y"
                                        {
              (yyval.node) = (yyvsp[-2].node);
              add_child((yyval.node), create_node(AST_IDENTIFIER, (yyvsp[0].sval)));
            }
#line 1579 "src/parser.tab.c"
    break;

  case 42: /* expression: logical_or  */
#line 208 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1585 "src/parser.tab.c"
    break;

  case 43: /* logical_or: logical_and  */
#line 211 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1591 "src/parser.tab.c"
    break;

  case 44: /* logical_or: logical_or OR logical_and  */
#line 212 "src/parser.y"
                                      {
              (yyval.node) = create_node(AST_OR, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1601 "src/parser.tab.c"
    break;

  case 45: /* logical_and: equality  */
#line 219 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1607 "src/parser.tab.c"
    break;

  case 46: /* logical_and: logical_and AND equality  */
#line 220 "src/parser.y"
                                      {
              (yyval.node) = create_node(AST_AND, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1617 "src/parser.tab.c"
    break;

  case 47: /* equality: comparison  */
#line 227 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1623 "src/parser.tab.c"
    break;

  case 48: /* equality: equality EQ comparison  */
#line 228 "src/parser.y"
                                 {
            (yyval.node) = create_node(AST_EQ, NULL);
            add_child((yyval.node), (yyvsp[-2].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1633 "src/parser.tab.c"
    break;

  case 49: /* equality: equality NEQ comparison  */
#line 233 "src/parser.y"
                                  {
            (yyval.node) = create_node(AST_NEQ, NULL);
            add_child((yyval.node), (yyvsp[-2].node));
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1643 "src/parser.tab.c"
    break;

  case 50: /* comparison: term  */
#line 240 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1649 "src/parser.tab.c"
    break;

  case 51: /* comparison: comparison LT term  */
#line 241 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_LT, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1659 "src/parser.tab.c"
    break;

  case 52: /* comparison: comparison GT term  */
#line 246 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_GT, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1669 "src/parser.tab.c"
    break;

  case 53: /* comparison: comparison LE term  */
#line 251 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_LE, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1679 "src/parser.tab.c"
    break;

  case 54: /* comparison: comparison GE term  */
#line 256 "src/parser.y"
                               {
              (yyval.node) = create_node(AST_GE, NULL);
              add_child((yyval.node), (yyvsp[-2].node));
              add_child((yyval.node), (yyvsp[0].node));
            }
#line 1689 "src/parser.tab.c"
    break;

  case 55: /* term: factor  */
#line 263 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1695 "src/parser.tab.c"
    break;

  case 56: /* term: term PLUS factor  */
#line 264 "src/parser.y"
                       {
        (yyval.node) = create_node(AST_ADD, NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
      }
#line 1705 "src/parser.tab.c"
    break;

  case 57: /* term: term MINUS factor  */
#line 269 "src/parser.y"
                        {
        (yyval.node) = create_node(AST_SUB, NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
      }
#line 1715 "src/parser.tab.c"
    break;

  case 58: /* factor: unary  */
#line 276 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1721 "src/parser.tab.c"
    break;

  case 59: /* factor: factor TIMES unary  */
#line 277 "src/parser.y"
                           {
          (yyval.node) = create_node(AST_MUL, NULL);
          add_child((yyval.node), (yyvsp[-2].node));
          add_child((yyval.node), (yyvsp[0].node));
        }
#line 1731 "src/parser.tab.c"
    break;

  case 60: /* factor: factor DIVIDE unary  */
#line 282 "src/parser.y"
                            {
          (yyval.node) = create_node(AST_DIV, NULL);
          add_child((yyval.node), (yyvsp[-2].node));
          add_child((yyval.node), (yyvsp[0].node));
        }
#line 1741 "src/parser.tab.c"
    break;

  case 61: /* factor: factor MODULO unary  */
#line 287 "src/parser.y"
                            {
          (yyval.node) = create_node(AST_MOD, NULL);
          add_child((yyval.node), (yyvsp[-2].node));
          add_child((yyval.node), (yyvsp[0].node));
        }
#line 1751 "src/parser.tab.c"
    break;

  case 62: /* unary: call  */
#line 294 "src/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1757 "src/parser.tab.c"
    break;

  case 63: /* unary: MINUS unary  */
#line 295 "src/parser.y"
                   {
         (yyval.node) = create_node(AST_NEG, NULL);
         add_child((yyval.node), (yyvsp[0].node));
       }
#line 1766 "src/parser.tab.c"
    break;

  case 64: /* unary: NOT unary  */
#line 299 "src/parser.y"
                 {
         (yyval.node) = create_node(AST_NOT, NULL);
         add_child((yyval.node), (yyvsp[0].node));
       }
#line 1775 "src/parser.tab.c"
    break;

  case 65: /* call: primary  */
#line 305 "src/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1781 "src/parser.tab.c"
    break;

  case 66: /* call: IDENTIFIER LPAREN arguments RPAREN  */
#line 306 "src/parser.y"
                                         {
        (yyval.node) = create_node(AST_CALL, (yyvsp[-3].sval));
        add_child((yyval.node), (yyvsp[-1].node));
      }
#line 1790 "src/parser.tab.c"
    break;

  case 67: /* call: IDENTIFIER LPAREN RPAREN  */
#line 310 "src/parser.y"
                               {
        (yyval.node) = create_node(AST_CALL, (yyvsp[-2].sval));
        add_child((yyval.node), create_node(AST_ARGUMENTS, NULL));
      }
#line 1799 "src/parser.tab.c"
    break;

  case 68: /* arguments: expression  */
#line 316 "src/parser.y"
                      {
            (yyval.node) = create_node(AST_ARGUMENTS, NULL);
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1808 "src/parser.tab.c"
    break;

  case 69: /* arguments: arguments COMMA expression  */
#line 320 "src/parser.y"
                                      {
            (yyval.node) = (yyvsp[-2].node);
            add_child((yyval.node), (yyvsp[0].node));
          }
#line 1817 "src/parser.tab.c"
    break;

  case 70: /* primary: INT_NUM  */
#line 326 "src/parser.y"
                 {
          char str[32];
          sprintf(str, "%d", (yyvsp[0].ival));
          (yyval.node) = create_node(AST_INT, strdup(str));
        }
#line 1827 "src/parser.tab.c"
    break;

  case 71: /* primary: FLOAT_NUM  */
#line 331 "src/parser.y"
                   {
          char str[32];
          sprintf(str, "%f", (yyvsp[0].fval));
          (yyval.node) = create_node(AST_FLOAT, strdup(str));
        }
#line 1837 "src/parser.tab.c"
    break;

  case 72: /* primary: STRING  */
#line 336 "src/parser.y"
                {
          (yyval.node) = create_node(AST_STRING, (yyvsp[0].sval));
        }
#line 1845 "src/parser.tab.c"
    break;

  case 73: /* primary: BOOL  */
#line 339 "src/parser.y"
              {
          (yyval.node) = create_node(AST_BOOL, (yyvsp[0].bval) ? "True" : "False");
        }
#line 1853 "src/parser.tab.c"
    break;

  case 74: /* primary: NONE  */
#line 342 "src/parser.y"
              {
          (yyval.node) = create_node(AST_NONE, "None");
        }
#line 1861 "src/parser.tab.c"
    break;

  case 75: /* primary: IDENTIFIER  */
#line 345 "src/parser.y"
                    {
          (yyval.node) = create_node(AST_IDENTIFIER, (yyvsp[0].sval));
        }
#line 1869 "src/parser.tab.c"
    break;

  case 76: /* primary: LPAREN expression RPAREN  */
#line 348 "src/parser.y"
                                  {
          (yyval.node) = (yyvsp[-1].node);
        }
#line 1877 "src/parser.tab.c"
    break;

  case 77: /* primary: list_expr  */
#line 351 "src/parser.y"
                   {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1885 "src/parser.tab.c"
    break;

  case 78: /* primary: dict_expr  */
#line 354 "src/parser.y"
                   {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1893 "src/parser.tab.c"
    break;

  case 79: /* list_expr: LBRACKET arguments RBRACKET  */
#line 359 "src/parser.y"
                                       {
            (yyval.node) = create_node(AST_LIST, NULL);
            add_child((yyval.node), (yyvsp[-1].node));
          }
#line 1902 "src/parser.tab.c"
    break;

  case 80: /* list_expr: LBRACKET RBRACKET  */
#line 363 "src/parser.y"
                             {
            (yyval.node) = create_node(AST_LIST, NULL);
          }
#line 1910 "src/parser.tab.c"
    break;

  case 81: /* dict_expr: LBRACE RBRACE  */
#line 368 "src/parser.y"
                         {
            (yyval.node) = create_node(AST_DICT, NULL);
          }
#line 1918 "src/parser.tab.c"
    break;


#line 1922 "src/parser.tab.c"

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

#line 373 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}
