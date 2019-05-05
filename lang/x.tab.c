
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "x.y"

#include "header.h"
#include "structures\struct_defs.h"
#include "structures\SymTable.h"
#include "structures\SymTable.c"
#include "structures\SymTree.h"
#include "structures\SymTree.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

int yyerror(char*);
extern int yylex(); 
//prototypes
nodeType *con(conTypeEnum type,union Value);
nodeType *id(char*  label, char* type, conTypeEnum dataType);
nodeType *getid(char* value);
nodeType *opr(int oper, int nops, ...);
void oprSemanticChecks( nodeType* p);


struct SymTable* currentSymTable;
struct Tree* tree;


/* Line 189 of yacc.c  */
#line 101 "x.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     FLOAT_VAL = 259,
     STRING_VAL = 260,
     IDENTIFIER = 261,
     BOOL_VAL = 262,
     CONST = 263,
     COND_EQ = 264,
     COND_GREQ = 265,
     COND_LSEQ = 266,
     COND_NEQ = 267,
     WHILE = 268,
     IF = 269,
     ELSE = 270,
     DO = 271,
     FOR = 272,
     SWITCH = 273,
     CASE = 274,
     DEFAULT = 275,
     VOID = 276,
     RETURN = 277,
     FUNCTION = 278,
     MAIN = 279,
     INT = 280,
     FLOAT = 281,
     STRING = 282,
     BOOL = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 "x.y"

    char* strVal;
    int intVal;
    bool boolVal;
    float floatVal;
    nodeType* nPtr;
	conTypeEnum conType;         



/* Line 214 of yacc.c  */
#line 176 "x.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "x.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   700

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,     2,
      43,    44,    29,    25,    42,    26,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    38,
      31,    41,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    28,    47,    33,     2,     2,     2,
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
      34,    35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    17,    19,    21,    23,    26,
      28,    30,    32,    34,    36,    38,    40,    43,    46,    53,
      55,    61,    63,    67,    74,    78,    80,    84,    88,    93,
     100,   104,   111,   117,   120,   126,   133,   142,   150,   155,
     159,   166,   169,   171,   175,   179,   181,   188,   194,   196,
     198,   200,   202,   205,   207,   212,   216,   220,   224,   228,
     232,   236,   240,   244,   248,   252,   256,   260,   264,   266,
     270,   274,   278,   282,   286,   290,   294,   298,   302,   304,
     309,   311,   313,   315,   318,   320,   323,   325,   327,   329,
     331,   333,   336,   338,   348,   358,   367,   376,   381,   384,
     386,   391,   395,   397,   402,   406,   410,   413,   415
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    75,    24,    82,    50,    83,    -1,    24,
      82,    50,    83,    -1,    50,    51,    -1,    51,    -1,    55,
      -1,    56,    -1,    59,    38,    -1,    62,    -1,    63,    -1,
      64,    -1,    66,    -1,    60,    -1,    52,    -1,    81,    -1,
      80,    38,    -1,    82,    72,    -1,    74,    39,    70,    40,
       6,    53,    -1,    38,    -1,    41,    82,    54,    83,    38,
      -1,    70,    -1,    54,    42,    70,    -1,     8,    74,     6,
      41,    70,    38,    -1,    74,     6,    57,    -1,    38,    -1,
      41,    70,    38,    -1,     6,    41,    70,    -1,    74,     6,
      41,    70,    -1,     6,    39,    70,    40,    41,    70,    -1,
       6,    41,    70,    -1,     6,    39,    70,    40,    41,    70,
      -1,    14,    43,    71,    44,    61,    -1,    82,    72,    -1,
      82,    72,    15,    82,    72,    -1,    13,    43,    71,    44,
      82,    72,    -1,    16,    82,    72,    13,    43,    71,    44,
      38,    -1,    17,    43,    58,    38,    71,    38,    65,    -1,
      59,    44,    82,    72,    -1,    44,    82,    72,    -1,    18,
      43,    70,    44,    82,    67,    -1,    69,    68,    -1,    83,
      -1,    20,    45,    72,    -1,    20,    45,    72,    -1,    83,
      -1,    69,    19,    43,    70,    44,    73,    -1,    19,    43,
      70,    44,    73,    -1,     3,    -1,     4,    -1,     7,    -1,
       5,    -1,    33,    70,    -1,     6,    -1,     6,    39,    70,
      40,    -1,    70,    25,    70,    -1,    70,    26,    70,    -1,
      70,    29,    70,    -1,    70,    30,    70,    -1,    70,    27,
      70,    -1,    70,    28,    70,    -1,    70,    31,    70,    -1,
      70,    10,    70,    -1,    70,    32,    70,    -1,    70,    11,
      70,    -1,    70,     9,    70,    -1,    70,    12,    70,    -1,
      43,    70,    44,    -1,    80,    -1,    71,    27,    71,    -1,
      71,    28,    71,    -1,    71,    31,    71,    -1,    71,    10,
      71,    -1,    71,    32,    71,    -1,    71,    11,    71,    -1,
      71,     9,    71,    -1,    71,    12,    71,    -1,    43,    71,
      44,    -1,     6,    -1,     6,    39,    70,    40,    -1,     7,
      -1,     3,    -1,     4,    -1,    50,    83,    -1,    83,    -1,
      45,    50,    -1,    45,    -1,    34,    -1,    35,    -1,    37,
      -1,    36,    -1,    75,    76,    -1,    76,    -1,    74,    23,
       6,    43,    77,    44,    82,    50,    83,    -1,    21,    23,
       6,    43,    77,    44,    82,    50,    83,    -1,    74,    23,
       6,    43,    44,    82,    50,    83,    -1,    21,    23,     6,
      43,    44,    82,    50,    83,    -1,    77,    42,    74,    78,
      -1,    74,    78,    -1,     6,    -1,     6,    39,    70,    40,
      -1,    79,    42,    70,    -1,    70,    -1,     6,    43,    79,
      44,    -1,     6,    43,    44,    -1,    22,    70,    38,    -1,
      22,    38,    -1,    46,    -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    67,    70,    71,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    91,    94,
      95,    98,    99,   102,   105,   114,   115,   119,   120,   121,
     127,   128,   134,   137,   138,   144,   147,   150,   153,   154,
     160,   163,   163,   163,   166,   167,   170,   171,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   217,   218,   221,   222,   227,   228,   229,
     230,   236,   237,   240,   241,   242,   243,   246,   247,   250,
     251,   254,   255,   258,   259,   262,   263,   272,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "FLOAT_VAL", "STRING_VAL",
  "IDENTIFIER", "BOOL_VAL", "CONST", "COND_EQ", "COND_GREQ", "COND_LSEQ",
  "COND_NEQ", "WHILE", "IF", "ELSE", "DO", "FOR", "SWITCH", "CASE",
  "DEFAULT", "VOID", "RETURN", "FUNCTION", "MAIN", "'+'", "'-'", "'&'",
  "'|'", "'*'", "'/'", "'<'", "'>'", "'~'", "INT", "FLOAT", "STRING",
  "BOOL", "';'", "'['", "']'", "'='", "','", "'('", "')'", "':'", "'{'",
  "'}'", "$accept", "program", "stmts", "stmt", "decArr", "withArr",
  "multipleExpr", "decConstant", "decVar", "withVal", "assigndec",
  "assign", "matched", "ifcont", "whilestmt", "dowhilestmt", "forloopstmt",
  "forloopcont", "switchcase", "cases", "nodef", "switching", "expr",
  "cond", "stmtornull", "stmtornull2", "type", "functions", "func", "args",
  "argName", "params", "funccall", "return", "openbraces", "closebraces", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    43,    45,    38,   124,    42,
      47,    60,    62,   126,   280,   281,   282,   283,    59,    91,
      93,    61,    44,    40,    41,    58,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    54,    55,    56,    57,    57,    58,    58,    58,
      59,    59,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     6,     1,
       5,     1,     3,     6,     3,     1,     3,     3,     4,     6,
       3,     6,     5,     2,     5,     6,     8,     7,     4,     3,
       6,     2,     1,     3,     3,     1,     6,     5,     1,     1,
       1,     1,     2,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     4,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     9,     9,     8,     8,     4,     2,     1,
       4,     3,     1,     4,     3,     3,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    87,    88,    90,    89,     0,     0,     0,
      92,     0,   107,     0,     1,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,    14,
       6,     7,     0,    13,     9,    10,    11,    12,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    51,    53,    50,     0,
     106,     0,     0,    68,   108,     4,     3,     8,     0,     0,
      16,     0,    17,    84,     0,     0,     0,     0,     0,     0,
      30,   104,   102,     0,     0,    81,    82,    78,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,    25,     0,    24,     0,    83,     0,     0,
       2,     0,    99,    98,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      65,    62,    64,    66,    55,    56,    59,    60,    57,    58,
      61,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,    77,    75,    72,    74,    76,    69,
      70,    71,    73,     0,    32,     0,     0,     0,    27,     0,
       0,     0,    54,    26,     0,     0,     0,    96,     0,    97,
       0,    31,    23,    79,    35,    33,     0,     0,     0,    28,
       0,     0,    40,     0,    42,    19,     0,    18,    95,     0,
     100,    94,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,    41,    45,     0,    93,     0,    36,    29,
       0,     0,     0,    43,     0,     0,     0,    21,    34,    39,
       0,     0,     0,    44,     0,     0,    38,    86,    47,     0,
      22,    20,    85,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    71,    28,    29,   217,   246,    30,    31,   115,
      94,    32,    33,   184,    34,    35,    36,   228,    37,   212,
     233,   213,    62,    90,    72,   258,    38,     9,    10,    78,
     123,    83,    63,    40,    41,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
     277,   -11,   -27,   -74,   -74,   -74,   -74,    27,     9,   663,
     -74,    33,   -74,   269,   -74,    46,   -27,   -74,    16,   -21,
     156,    17,    28,   -27,    29,    45,    37,    98,   -74,   -74,
     -74,   -74,    43,   -74,   -74,   -74,   -74,   -74,    11,    67,
     -74,    98,    74,   269,    63,    80,    80,    30,   104,     2,
       2,    98,   132,    80,   -74,   -74,   -74,    18,   -74,    80,
     -74,    80,   592,   -74,   -74,   -74,   -74,   -74,    26,    80,
     -74,    98,   -74,   -74,   199,    98,   -27,   115,    24,   446,
     664,   -74,   664,    59,    89,   -74,   -74,    92,   -74,     2,
     398,   408,   123,    38,    99,   133,   298,    80,   -74,   322,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,   -74,   -74,    80,   -74,   472,   -74,   -27,    82,
     -74,   269,   107,   -74,   156,   -27,   108,    80,   -74,    80,
      80,   422,     2,     2,     2,     2,     2,     2,     2,     2,
     -27,   -27,   105,    80,    80,     2,   109,   -27,   496,   -74,
     -74,   -74,   -74,   -74,   326,   326,   326,   326,   -74,   -74,
     -74,   -74,   616,   148,   269,   -27,    98,    80,   115,   269,
      80,   664,   640,   520,   -74,   -74,   -74,   -74,   -74,   168,
     168,   -74,   -74,    98,   -74,    98,     2,   544,   664,   261,
      80,     6,   -74,   -74,    81,    98,   269,   -74,   568,   -74,
      98,   664,   -74,   -74,   -74,   140,   436,   117,     5,   664,
     116,   119,   -74,    35,   -74,   -74,   -27,   -74,   -74,    98,
     -74,   -74,   -27,   124,    80,    88,   -27,   129,   -74,    80,
      98,   131,   130,   -74,   -74,    80,   -74,    98,   -74,   664,
      98,   -27,   362,   -74,    80,    98,   -32,   664,   -74,   -74,
      98,   136,   372,   -74,    80,   150,   -74,   269,   -74,   136,
     664,   -74,   269,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -12,   -24,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,    -7,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   151,   -43,   -22,   -73,     4,   -74,   193,   135,
      51,   -74,   -13,   -74,     0,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      39,    27,    13,    65,     8,    85,    86,    91,    87,    88,
     254,   225,    11,     8,    39,    64,    43,    68,    45,    12,
      46,    66,    47,    51,    48,   210,   211,    14,    39,    92,
      39,    75,    15,    54,    55,    56,    57,    58,    39,    18,
      54,    55,    56,    57,    58,    89,   131,    65,    77,   226,
      69,    65,    42,    64,   231,   232,    95,    97,    39,    44,
      49,    47,    39,    59,   113,   117,   124,   114,   125,   120,
      59,    50,    52,    61,    81,    60,   121,   143,    77,   144,
      61,    67,    64,    54,    55,    56,    57,    58,    53,   175,
     176,   177,   178,   179,   180,   181,   182,     3,     4,     5,
       6,   127,   189,   128,    19,    70,    20,    76,    39,   166,
      84,    21,    22,    59,    23,    24,    25,    74,   164,   215,
      26,   122,   216,    61,   124,   169,   165,    45,   168,    46,
     129,   130,     3,     4,     5,     6,   142,   145,    93,   146,
     183,   185,    65,   206,    12,    64,   167,   191,   186,   170,
     190,    39,   195,    39,   194,   222,    39,   200,   224,   229,
     197,   204,   238,   205,   230,   196,     3,     4,     5,     6,
      39,    65,    39,   241,   244,   245,    65,   132,   133,   134,
     135,   257,    39,    39,   219,   214,   263,    39,   261,   218,
       3,     4,     5,     6,   221,    65,    79,    80,    82,   138,
     139,   227,    17,     0,    96,     0,    39,   234,   243,   119,
      98,     0,    99,   236,     0,   248,   235,    39,   249,   199,
     116,     0,   237,   253,    39,     0,   240,    39,   256,     0,
       0,     0,    39,     3,     4,     5,     6,    39,    65,     0,
     255,   250,     0,   118,    39,   262,     0,     0,   148,    39,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,   162,     0,     0,     0,     0,
     132,   133,   134,   135,     0,    19,     0,    20,   171,     0,
     172,   173,    21,    22,     0,    23,    24,    25,   136,   137,
       0,    26,   138,   139,   187,   188,     0,     0,     1,   208,
       0,     2,     0,     3,     4,     5,     6,   100,   101,   102,
     103,     3,     4,     5,     6,    12,     0,     0,   198,     0,
       0,   201,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   100,   101,   102,   103,   100,   101,   102,   103,     0,
       0,   209,   147,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,   100,   101,   102,   103,   239,     0,     0,     0,     0,
     242,   100,   101,   102,   103,     0,   247,   104,   105,   106,
     107,   108,   109,   110,   111,   252,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   260,   251,   132,   133,   134,
     135,     0,     0,     0,     0,     0,   259,   132,   133,   134,
     135,     0,     0,     0,     0,   136,   137,     0,     0,   138,
     139,   132,   133,   134,   135,   136,   137,     0,     0,   138,
     139,     0,   140,     0,     0,   132,   133,   134,   135,   136,
     137,     0,   141,   138,   139,   100,   101,   102,   103,     0,
       0,     0,     0,   136,   137,     0,   174,   138,   139,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     223,   100,   101,   102,   103,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   100,   101,   102,   103,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,     0,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   100,   101,   102,   103,     0,     0,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   100,   101,   102,
     103,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   100,   101,   102,   103,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   100,   101,   102,   103,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   100,   101,   102,   103,     0,   202,     0,
       0,     0,     0,     0,     1,     0,     0,    16,     0,   104,
     105,   106,   107,   108,   109,   110,   111,     3,     4,     5,
       6
};

static const yytype_int16 yycheck[] =
{
      13,    13,     2,    27,     0,     3,     4,    50,     6,     7,
      42,     6,    23,     9,    27,    47,    16,     6,    39,    46,
      41,    27,    43,    23,    20,    19,    20,     0,    41,    51,
      43,    43,    23,     3,     4,     5,     6,     7,    51,     6,
       3,     4,     5,     6,     7,    43,    89,    71,    44,    44,
      39,    75,     6,    47,    19,    20,    52,    39,    71,    43,
      43,    43,    75,    33,    38,    71,    42,    41,    44,    75,
      33,    43,    43,    43,    44,    38,    76,    39,    74,    41,
      43,    38,    47,     3,     4,     5,     6,     7,    43,   132,
     133,   134,   135,   136,   137,   138,   139,    34,    35,    36,
      37,    42,   145,    44,     6,    38,     8,    44,   121,   121,
       6,    13,    14,    33,    16,    17,    18,    43,   118,    38,
      22,     6,    41,    43,    42,   125,    44,    39,   124,    41,
      41,    39,    34,    35,    36,    37,    13,    38,     6,     6,
     140,   141,   166,   186,    46,    47,    39,   147,    43,    41,
      41,   164,   164,   166,     6,    15,   169,   169,    41,    43,
     166,   183,    38,   185,    45,   165,    34,    35,    36,    37,
     183,   195,   185,    44,    43,    45,   200,     9,    10,    11,
      12,    45,   195,   196,   196,   191,   259,   200,    38,   195,
      34,    35,    36,    37,   200,   219,    45,    46,    47,    31,
      32,   208,     9,    -1,    53,    -1,   219,   213,   230,    74,
      59,    -1,    61,   219,    -1,   237,   216,   230,   240,   168,
      69,    -1,   222,   245,   237,    -1,   226,   240,   250,    -1,
      -1,    -1,   245,    34,    35,    36,    37,   250,   262,    -1,
     246,   241,    -1,    44,   257,   257,    -1,    -1,    97,   262,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    -1,     6,    -1,     8,   127,    -1,
     129,   130,    13,    14,    -1,    16,    17,    18,    27,    28,
      -1,    22,    31,    32,   143,   144,    -1,    -1,    21,    38,
      -1,    24,    -1,    34,    35,    36,    37,     9,    10,    11,
      12,    34,    35,    36,    37,    46,    -1,    -1,   167,    -1,
      -1,   170,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,     9,    10,    11,    12,     9,    10,    11,    12,    -1,
      -1,   190,    44,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,   224,    -1,    -1,    -1,    -1,
     229,     9,    10,    11,    12,    -1,   235,    25,    26,    27,
      28,    29,    30,    31,    32,   244,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,   254,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,     9,    10,    11,    12,    27,    28,    -1,    -1,    31,
      32,    -1,    44,    -1,    -1,     9,    10,    11,    12,    27,
      28,    -1,    44,    31,    32,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    27,    28,    -1,    44,    31,    32,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      44,     9,    10,    11,    12,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,     9,    10,    11,    12,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,     9,
      10,    11,    12,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,     9,    10,    11,    12,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,     9,    10,    11,
      12,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,     9,    10,    11,    12,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,     9,    10,    11,    12,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,     9,
      10,    11,    12,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,     9,    10,    11,    12,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    34,    35,    36,
      37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    24,    34,    35,    36,    37,    49,    74,    75,
      76,    23,    46,    82,     0,    23,    24,    76,     6,     6,
       8,    13,    14,    16,    17,    18,    22,    50,    51,    52,
      55,    56,    59,    60,    62,    63,    64,    66,    74,    80,
      81,    82,     6,    82,    43,    39,    41,    43,    74,    43,
      43,    82,    43,    43,     3,     4,     5,     6,     7,    33,
      38,    43,    70,    80,    47,    51,    83,    38,     6,    39,
      38,    50,    72,    83,    43,    50,    44,    74,    77,    70,
      70,    44,    70,    79,     6,     3,     4,     6,     7,    43,
      71,    71,    72,     6,    58,    74,    70,    39,    70,    70,
       9,    10,    11,    12,    25,    26,    27,    28,    29,    30,
      31,    32,    38,    38,    41,    57,    70,    83,    44,    77,
      83,    82,     6,    78,    42,    44,    40,    42,    44,    41,
      39,    71,     9,    10,    11,    12,    27,    28,    31,    32,
      44,    44,    13,    39,    41,    38,     6,    44,    70,    44,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    40,    82,    44,    50,    39,    74,    82,
      41,    70,    70,    70,    44,    71,    71,    71,    71,    71,
      71,    71,    71,    82,    61,    82,    43,    70,    70,    71,
      41,    82,    40,    38,     6,    50,    82,    83,    70,    78,
      50,    70,    38,    40,    72,    72,    71,    40,    38,    70,
      19,    20,    67,    69,    83,    38,    41,    53,    83,    50,
      40,    83,    15,    44,    41,     6,    44,    59,    65,    43,
      45,    19,    20,    68,    83,    82,    83,    82,    38,    70,
      82,    44,    70,    72,    43,    45,    54,    70,    72,    72,
      82,    44,    70,    72,    42,    83,    72,    45,    73,    44,
      70,    38,    50,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 66 "x.y"
    { printf("valid with functions\n");  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 67 "x.y"
    { printf("valid\n"); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 70 "x.y"
    {(yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 71 "x.y"
    {(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 74 "x.y"
    { printf("decConst\n"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 75 "x.y"
    { printf("decVar\n"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 76 "x.y"
    { printf("assignment\n"); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 77 "x.y"
    { printf("while\n"); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 78 "x.y"
    { printf("do\n"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 79 "x.y"
    { printf("for\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 80 "x.y"
    { printf("switch\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 81 "x.y"
    { printf("if\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 82 "x.y"
    { printf("dec array\n"); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 83 "x.y"
    { printf("return\n"); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 84 "x.y"
    { printf("func call\n"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 102 "x.y"
    { (yyval.nPtr) = opr(CONST, 2, id((yyvsp[(3) - (6)].strVal), "const_var", (yyvsp[(2) - (6)].conType)), (yyvsp[(5) - (6)].nPtr)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 105 "x.y"
    { if((yyvsp[(3) - (3)].nPtr)==NULL){
																 id((yyvsp[(2) - (3)].strVal), "var", (yyvsp[(1) - (3)].conType));
																}
															else{
																 (yyval.nPtr) = opr('=', 2, id((yyvsp[(2) - (3)].strVal), "var", (yyvsp[(1) - (3)].conType)), (yyvsp[(3) - (3)].nPtr)); 
															}
														;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 114 "x.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 115 "x.y"
    {(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 119 "x.y"
    { (yyval.nPtr) = opr('=',2,getid((yyvsp[(1) - (3)].strVal)),(yyvsp[(3) - (3)].nPtr));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 120 "x.y"
    { (yyval.nPtr) = opr('=', 2, id((yyvsp[(2) - (4)].strVal), "var", (yyvsp[(1) - (4)].conType)), (yyvsp[(4) - (4)].nPtr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 127 "x.y"
    { (yyval.nPtr) = opr('=',2,getid((yyvsp[(1) - (3)].strVal)),(yyvsp[(3) - (3)].nPtr));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 134 "x.y"
    { (yyval.nPtr) = opr(IF, 2,  (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 137 "x.y"
    { (yyval.nPtr) = (yyvsp[(2) - (2)].nPtr);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 138 "x.y"
    { (yyval.nPtr) = opr(ELSE, 2, (yyvsp[(2) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 144 "x.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (6)].nPtr), (yyvsp[(6) - (6)].nPtr));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 147 "x.y"
    { (yyval.nPtr) = opr(DO, 2, (yyvsp[(3) - (8)].nPtr), (yyvsp[(6) - (8)].nPtr));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 150 "x.y"
    { (yyval.nPtr) = opr(FOR, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 153 "x.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(4) - (4)].nPtr), (yyvsp[(1) - (4)].nPtr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 154 "x.y"
    { (yyval.nPtr) = (yyvsp[(3) - (3)].nPtr);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 177 "x.y"
    {union Value x; x.intVal=(yyvsp[(1) - (1)].intVal); (yyval.nPtr)=con(typeint,x);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 178 "x.y"
    {union Value x; x.floatVal=(yyvsp[(1) - (1)].floatVal); (yyval.nPtr)=con(typefloat,x);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 179 "x.y"
    {union Value x; x.boolVal=(yyvsp[(1) - (1)].boolVal); (yyval.nPtr)=con(typebool,x);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 180 "x.y"
    {union Value x; x.strVal=(yyvsp[(1) - (1)].strVal); (yyval.nPtr)=con(typestring,x);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 181 "x.y"
    {(yyval.nPtr) = opr('~', 1, (yyvsp[(2) - (2)].nPtr));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 182 "x.y"
    {(yyval.nPtr) = getid((yyvsp[(1) - (1)].strVal));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 183 "x.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 184 "x.y"
    {(yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 185 "x.y"
    {(yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 186 "x.y"
    {(yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 187 "x.y"
    {(yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 188 "x.y"
    {(yyval.nPtr) = opr('&', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 189 "x.y"
    {(yyval.nPtr) = opr('|', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 190 "x.y"
    {(yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 191 "x.y"
    {(yyval.nPtr) = opr(COND_GREQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 192 "x.y"
    {(yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 193 "x.y"
    {(yyval.nPtr) = opr(COND_LSEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 194 "x.y"
    {(yyval.nPtr) = opr(COND_EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 195 "x.y"
    {(yyval.nPtr) = opr(COND_NEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 196 "x.y"
    {(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 200 "x.y"
    {(yyval.nPtr) = opr('&', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 201 "x.y"
    {(yyval.nPtr) = opr('|', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 202 "x.y"
    {(yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 203 "x.y"
    {(yyval.nPtr) = opr(COND_GREQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 204 "x.y"
    {(yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 205 "x.y"
    {(yyval.nPtr) = opr(COND_LSEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 206 "x.y"
    {(yyval.nPtr) = opr(COND_EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 207 "x.y"
    {(yyval.nPtr) = opr(COND_NEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 208 "x.y"
    {(yyval.nPtr)=(yyvsp[(2) - (3)].nPtr);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 209 "x.y"
    {(yyval.nPtr) = getid((yyvsp[(1) - (1)].strVal));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 211 "x.y"
    {union Value x; x.boolVal=(yyvsp[(1) - (1)].boolVal); (yyval.nPtr)=con(typebool,x);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 212 "x.y"
    {union Value x; x.intVal=(yyvsp[(1) - (1)].intVal); (yyval.nPtr)=con(typeint,x);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 213 "x.y"
    {union Value x; x.floatVal=(yyvsp[(1) - (1)].floatVal); (yyval.nPtr)=con(typefloat,x);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 217 "x.y"
    {(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 218 "x.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 227 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 228 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 229 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 230 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 236 "x.y"
    {printf("func");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 237 "x.y"
    {printf("func");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 272 "x.y"
    { printf("openbraces\n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 274 "x.y"
    { printf("closebraces\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2204 "x.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 277 "x.y"


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p) 

nodeType *con(conTypeEnum type, union Value value) {
     
	nodeType *p;     /* allocate node */

    if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");     

	/* copy information */
    p->type = typeCon;

	if(type==typeint){
		p->con.intVal = value.intVal;
	}else if( type == typefloat){
		p->con.floatVal = value.floatVal;
	}else if( type == typebool){
		p->con.boolVal = value.boolVal;
	}else{
		p->con.strVal = value.strVal;
	}
    
    p->con.type = type;
	p->retType = type;
	
    return p; 
}

nodeType *id(char*  label, char* type, conTypeEnum dataType) {
    nodeType *p;     /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL){
         yyerror("out of memory");
	}
	 
	union Value  x;
	x.intVal = 1;

	int flag = symInsert(currentSymTable, label, type, x);
	
	if(flag == -1){
		printf("Redeclaration");
	}

	p->type = typeId;
	p->id.label = label;
    p->id.symTablePtr = currentSymTable;
	
	p->retType = dataType;
	
	 return p;
 } 

nodeType *getid(char* value) {
	
    nodeType *p;     /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
         yyerror("out of memory");
	//look up the symbol table to get values
	struct Symbol* sym= symLookup(currentSymTable, value);

	if(sym == NULL){
		printf("var not found");
	}else{
     /* copy information */
		p->type = typeId;
		p->id.label = value;
		p->id.symTablePtr = sym->myTable;
	}
	 
    return p;
 } 

nodeType *opr(int oper, int nops, ...) {    
 	va_list ap;    
 	nodeType *p;   
  	int i;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL)
        yyerror("out of memory");
	
    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
	
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
	
	if(oper==WHILE){
		//printf("\nWHILEEEEEEEEE\n %c \n %d\n", p->opr.op[0]->opr.oper, p->opr.op[1]->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal);//p->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal );
	}
	if(oper==DO){
		printf("\nDOOOOOO\n %d \n %d\n",  p->opr.op[0]->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal, p->opr.op[1]->opr.op[1]->con.intVal);//p->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal );
	}

	/*if(oper==FOR){
		printf("\nfor\n %c \n\n", p->opr.op[2]->opr.op[1]->opr.op[1]->opr.oper ); 
	}*/

	if(oper==IF){
		printf("\nIFFFFFFFFF\n %d\n\n" , p->opr.op[1]->opr.op[0]->opr.op[1]->con.intVal );
	}
	
	
	//TODO: Semantic checks
	oprSemanticChecks(p);
    return p;
 } 

void oprSemanticChecks( nodeType* p){
	
	// Arithmetic check : types are same and are numbers //
	if(p->opr.oper == '+' || p->opr.oper == '-' || p->opr.oper == '*' || p->opr.oper == '/' ){
		if((p->opr.op[0]->retType == p->opr.op[1]->retType) && (p->opr.op[1]->retType == typeint || p->opr.op[1]->retType == typefloat)){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\nshit\n");
		}
		
	}

	// Logical expressions //
	// Check for == or != 
	else if( p->opr.oper == COND_EQ || p->opr.oper == COND_NEQ){
		// Check types equal and are numbers or booleans
		if((p->opr.op[0]->retType == p->opr.op[1]->retType) && (p->opr.op[1]->retType == typeint 
		|| p->opr.op[1]->retType == typefloat || p->opr.op[1]->retType == typebool)){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\nshit\n");
		}
	}
	// Check for < <= > >=
	else if( p->opr.oper == '<' || p->opr.oper == '>' || p->opr.oper == COND_GREQ 
	|| p->opr.oper == COND_LSEQ ){
		// Check types equal and are numbers
		if((p->opr.op[0]->retType == p->opr.op[1]->retType) && (p->opr.op[1]->retType == typeint || p->opr.op[1]->retType == typefloat)){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\nshit\n");
		}
	}
	// Check for & |
	else if( p->opr.oper == '|' || p->opr.oper == '&'){
		// Check types are equal and booleans
		if((p->opr.op[0]->retType == p->opr.op[1]->retType) && (p->opr.op[1]->retType == typebool)){
			p->retType = typebool;
		}else{
			printf("\nshit\n");
		}
	}
	// CHeck for ~
	else if (p->opr.oper == '~'){
		if(p->opr.op[0]-> retType == typeint || p->opr.op[0]-> retType == typefloat){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\nshit\n");
		}
	}
	//Check for = (Assignment)
	// else if (p->opr.oper == '='){	
	// 	// Check types are equal in the left hand side is not a const
	// 	if( (p->opr.op[0]->retType == p->opr.op[1]->retType) && 
	// 	(p->opr.op[0]->type !=typeId ||(p->opr.op[0]->type == typeId && strcmp( symLookup(currentSymTable,p->opr.op[0]->id.label)->type,"const_var")!=0 && strcmp( symLookup(currentSymTable,p->opr.op[0]->id.label)->type,"const_array")!=0  ))){
	// 		p->retType = p->opr.op[0]->retType;
	// 	}else{
	// 		printf("\nshit\n");
	// 	}
	// }

}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
extern FILE *yyin;

int yyerror(char *msg) {
  fprintf(stderr,"%s\n",msg);
  exit(1);
}

int main(int argc, char * argv[]){
  tree = allocateSymTree();
  currentSymTable = startScope(tree);
  yyin=fopen(argv[1],"r");
  yyparse();

  symTablePrint( currentSymTable);
  return 0;
}

