
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
nodeType *id(char*  label, Type type, conTypeEnum dataType);
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
     CASE_JOIN = 280,
     INT = 281,
     FLOAT = 282,
     STRING = 283,
     BOOL = 284
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
#line 177 "x.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "x.tab.c"

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
#define YYLAST   733

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,     2,
      44,    45,    30,    26,    43,    27,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    39,
      32,    42,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    29,    48,    34,     2,     2,     2,
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
      25,    35,    36,    37,    38
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
     159,   166,   169,   176,   182,   184,   186,   188,   190,   193,
     195,   200,   204,   208,   212,   216,   220,   224,   228,   232,
     236,   240,   244,   248,   252,   254,   258,   262,   266,   270,
     274,   278,   282,   286,   290,   292,   297,   299,   301,   303,
     306,   308,   311,   313,   315,   317,   319,   321,   324,   326,
     336,   346,   355,   364,   369,   372,   374,   379,   383,   385,
     390,   394,   398,   401,   403
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    75,    24,    82,    51,    83,    -1,    24,
      82,    51,    83,    -1,    51,    52,    -1,    52,    -1,    56,
      -1,    57,    -1,    60,    39,    -1,    63,    -1,    64,    -1,
      65,    -1,    67,    -1,    61,    -1,    53,    -1,    81,    -1,
      80,    39,    -1,    82,    72,    -1,    74,    40,    70,    41,
       6,    54,    -1,    39,    -1,    42,    82,    55,    83,    39,
      -1,    70,    -1,    55,    43,    70,    -1,     8,    74,     6,
      42,    70,    39,    -1,    74,     6,    58,    -1,    39,    -1,
      42,    70,    39,    -1,     6,    42,    70,    -1,    74,     6,
      42,    70,    -1,     6,    40,    70,    41,    42,    70,    -1,
       6,    42,    70,    -1,     6,    40,    70,    41,    42,    70,
      -1,    14,    44,    71,    45,    62,    -1,    82,    72,    -1,
      82,    72,    15,    82,    72,    -1,    13,    44,    71,    45,
      82,    72,    -1,    16,    82,    72,    13,    44,    71,    45,
      39,    -1,    17,    44,    59,    39,    71,    39,    66,    -1,
      60,    45,    82,    72,    -1,    45,    82,    72,    -1,    18,
      44,    70,    45,    82,    68,    -1,    69,    83,    -1,    69,
      19,    44,    70,    45,    73,    -1,    19,    44,    70,    45,
      73,    -1,     3,    -1,     4,    -1,     7,    -1,     5,    -1,
      34,    70,    -1,     6,    -1,     6,    40,    70,    41,    -1,
      70,    26,    70,    -1,    70,    27,    70,    -1,    70,    30,
      70,    -1,    70,    31,    70,    -1,    70,    28,    70,    -1,
      70,    29,    70,    -1,    70,    32,    70,    -1,    70,    10,
      70,    -1,    70,    33,    70,    -1,    70,    11,    70,    -1,
      70,     9,    70,    -1,    70,    12,    70,    -1,    44,    70,
      45,    -1,    80,    -1,    71,    28,    71,    -1,    71,    29,
      71,    -1,    71,    32,    71,    -1,    71,    10,    71,    -1,
      71,    33,    71,    -1,    71,    11,    71,    -1,    71,     9,
      71,    -1,    71,    12,    71,    -1,    44,    71,    45,    -1,
       6,    -1,     6,    40,    70,    41,    -1,     7,    -1,     3,
      -1,     4,    -1,    51,    83,    -1,    83,    -1,    46,    51,
      -1,    46,    -1,    35,    -1,    36,    -1,    38,    -1,    37,
      -1,    75,    76,    -1,    76,    -1,    74,    23,     6,    44,
      77,    45,    82,    51,    83,    -1,    21,    23,     6,    44,
      77,    45,    82,    51,    83,    -1,    74,    23,     6,    44,
      45,    82,    51,    83,    -1,    21,    23,     6,    44,    45,
      82,    51,    83,    -1,    77,    43,    74,    78,    -1,    74,
      78,    -1,     6,    -1,     6,    40,    70,    41,    -1,    79,
      43,    70,    -1,    70,    -1,     6,    44,    79,    45,    -1,
       6,    44,    45,    -1,    22,    70,    39,    -1,    22,    39,
      -1,    47,    -1,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    71,    72,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    92,    95,
      96,    99,   100,   103,   106,   115,   116,   120,   121,   122,
     128,   129,   135,   138,   139,   145,   148,   151,   154,   155,
     161,   164,   174,   175,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     222,   225,   226,   231,   232,   233,   234,   240,   241,   244,
     245,   246,   247,   250,   251,   254,   255,   258,   259,   262,
     263,   266,   267,   276,   278
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
  "DEFAULT", "VOID", "RETURN", "FUNCTION", "MAIN", "CASE_JOIN", "'+'",
  "'-'", "'&'", "'|'", "'*'", "'/'", "'<'", "'>'", "'~'", "INT", "FLOAT",
  "STRING", "BOOL", "';'", "'['", "']'", "'='", "','", "'('", "')'", "':'",
  "'{'", "'}'", "$accept", "program", "stmts", "stmt", "decArr", "withArr",
  "multipleExpr", "decConstant", "decVar", "withVal", "assigndec",
  "assign", "matched", "ifcont", "whilestmt", "dowhilestmt", "forloopstmt",
  "forloopcont", "switchcase", "cases", "switching", "expr", "cond",
  "stmtornull", "stmtornull2", "type", "functions", "func", "args",
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
     275,   276,   277,   278,   279,   280,    43,    45,    38,   124,
      42,    47,    60,    62,   126,   281,   282,   283,   284,    59,
      91,    93,    61,    44,    40,    41,    58,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    55,    55,    56,    57,    58,    58,    59,    59,    59,
      60,    60,    61,    62,    62,    63,    64,    65,    66,    66,
      67,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     6,     1,
       5,     1,     3,     6,     3,     1,     3,     3,     4,     6,
       3,     6,     5,     2,     5,     6,     8,     7,     4,     3,
       6,     2,     6,     5,     1,     1,     1,     1,     2,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     2,     1,     9,
       9,     8,     8,     4,     2,     1,     4,     3,     1,     4,
       3,     3,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    83,    84,    86,    85,     0,     0,     0,
      88,     0,   103,     0,     1,     0,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,    14,
       6,     7,     0,    13,     9,    10,    11,    12,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    47,    49,    46,     0,
     102,     0,     0,    64,   104,     4,     3,     8,     0,     0,
      16,     0,    17,    80,     0,     0,     0,     0,     0,     0,
      30,   100,    98,     0,     0,    77,    78,    74,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,    25,     0,    24,     0,    79,     0,     0,
       2,     0,    95,    94,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      61,    58,    60,    62,    51,    52,    55,    56,    53,    54,
      57,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,    73,    71,    68,    70,    72,    65,
      66,    67,    69,     0,    32,     0,     0,     0,    27,     0,
       0,     0,    50,    26,     0,     0,     0,    92,     0,    93,
       0,    31,    23,    75,    35,    33,     0,     0,     0,    28,
       0,    40,     0,    19,     0,    18,    91,     0,    96,    90,
       0,     0,     0,     0,     0,     0,    37,     0,     0,    41,
       0,    89,     0,    36,    29,     0,     0,     0,     0,     0,
      21,    34,    39,     0,     0,     0,     0,     0,    38,    82,
      43,     0,    22,    20,    81,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    71,    28,    29,   215,   239,    30,    31,   115,
      94,    32,    33,   184,    34,    35,    36,   226,    37,   211,
     212,    62,    90,    72,   250,    38,     9,    10,    78,   123,
      83,    63,    40,    41,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -47
static const yytype_int16 yypact[] =
{
     111,    -7,   -30,   -47,   -47,   -47,   -47,    32,    17,   154,
     -47,    65,   -47,   291,   -47,    79,   -30,   -47,    -5,    15,
     171,    54,    61,   -30,    66,    75,    30,    59,   -47,   -47,
     -47,   -47,    90,   -47,   -47,   -47,   -47,   -47,     6,    91,
     -47,    59,   114,   291,   124,    97,    97,   120,   128,     4,
       4,    59,    76,    97,   -47,   -47,   -47,    16,   -47,    97,
     -47,    97,   625,   -47,   -47,   -47,   -47,   -47,    10,    97,
     -47,    59,   -47,   -47,   165,    59,   -30,   149,   -18,   475,
     700,   -47,   700,    25,   121,   -47,   -47,   126,   -47,     4,
     411,   419,   160,    38,   138,   161,   261,    97,   -47,   321,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,   -47,   -47,    97,   -47,   500,   -47,   -30,    77,
     -47,   291,   140,   -47,   171,   -30,   139,    97,   -47,    97,
      97,   425,     4,     4,     4,     4,     4,     4,     4,     4,
     -30,   -30,   141,    97,    97,     4,   144,   -30,   525,   -47,
     -47,   -47,   -47,   -47,   106,   106,   106,   106,   -47,   -47,
     -47,   -47,   650,   188,   291,   -30,    59,    97,   149,   291,
      97,   700,   675,   550,   -47,   -47,   -47,   -47,   -47,    12,
      12,   -47,   -47,    59,   -47,    59,     4,   575,   700,   348,
      97,   176,   -47,   -47,    24,    59,   291,   -47,   600,   -47,
      59,   700,   -47,   -47,   -47,   205,   450,   182,    -4,   700,
     181,   -47,    -6,   -47,   -30,   -47,   -47,    59,   -47,   -47,
     -30,   187,    97,   172,   -30,   183,   -47,    97,   185,   -47,
      97,   -47,    59,   -47,   700,    59,   -30,   374,    97,   -28,
     700,   -47,   -47,    59,   186,   382,    97,   192,   -47,   291,
     -47,   186,   700,   -47,   291,   -47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -12,   -21,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,    26,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   152,   -46,    33,   -16,     9,   -47,   229,   166,    74,
     -47,   -13,   -47,     3,   -24
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    27,   223,    66,    91,    13,    65,    85,    86,     8,
      87,    88,    68,   228,    39,   246,    11,    12,     8,    43,
      64,   132,   133,   134,   135,   124,    51,   125,    39,    48,
      39,    75,    14,    54,    55,    56,    57,    58,    39,    44,
      15,   224,    64,   131,   138,   139,    69,   117,    89,   113,
      65,   120,   114,    77,    65,    45,    97,    46,    39,    47,
      47,    95,    39,   213,    59,    19,   214,    20,   127,    60,
     128,    18,    21,    22,    61,    23,    24,    25,   143,   121,
     144,    26,    93,    77,    92,    42,   175,   176,   177,   178,
     179,   180,   181,   182,     3,     4,     5,     6,    49,   189,
      54,    55,    56,    57,    58,    50,    12,    64,    39,   166,
      52,     3,     4,     5,     6,   100,   101,   102,   103,    53,
     124,   164,   165,    54,    55,    56,    57,    58,   169,    67,
      70,    59,     1,   168,    84,     2,   108,   109,   110,   111,
     206,    61,   197,   183,   185,    65,     3,     4,     5,     6,
     191,    39,   195,    39,    59,   122,    39,   200,    74,     3,
       4,     5,     6,   129,    61,    81,   130,   146,   196,    76,
      39,   216,    39,   142,    65,     1,   219,   145,    16,    65,
     167,   170,    39,    39,   217,   186,   190,    39,   229,     3,
       4,     5,     6,   231,   194,   210,    65,    79,    80,    82,
       3,     4,     5,     6,    39,    96,     3,     4,     5,     6,
     118,    98,    45,    99,    46,   247,   204,   230,   205,    39,
     220,   116,    39,   232,   222,   227,   233,   235,   236,   238,
      39,   253,   249,    65,   225,   255,    39,   254,    17,   243,
     119,    39,   199,     0,     0,     0,     0,     0,     0,   148,
       0,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   241,   162,     0,   242,     0,
     100,   101,   102,   103,     0,     0,   248,     0,     0,   171,
       0,   172,   173,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   187,   188,    19,     0,    20,
       0,     0,     0,     0,    21,    22,   147,    23,    24,    25,
       0,     0,     0,    26,     0,     0,     0,     0,     0,   198,
       0,     0,   201,     0,     0,     0,     3,     4,     5,     6,
     100,   101,   102,   103,     0,     0,     0,     0,    12,     0,
       0,     0,   209,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,   132,   133,   134,
     135,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,     0,   234,     0,   136,   137,     0,   237,
     138,   139,   240,   100,   101,   102,   103,   208,     0,     0,
     245,   100,   101,   102,   103,     0,     0,     0,   252,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,   244,
     132,   133,   134,   135,     0,     0,     0,   251,   132,   133,
     134,   135,     0,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,   138,   139,     0,     0,   136,   137,     0,
       0,   138,   139,   136,   137,     0,   140,   138,   139,   132,
     133,   134,   135,     0,   141,     0,     0,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,   136,   137,
       0,     0,   138,   139,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   100,   101,   102,   103,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,     0,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   100,   101,   102,   103,     0,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   100,   101,   102,   103,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   100,   101,   102,   103,     0,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   100,
     101,   102,   103,     0,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
      13,    13,     6,    27,    50,     2,    27,     3,     4,     0,
       6,     7,     6,    19,    27,    43,    23,    47,     9,    16,
      48,     9,    10,    11,    12,    43,    23,    45,    41,    20,
      43,    43,     0,     3,     4,     5,     6,     7,    51,    44,
      23,    45,    48,    89,    32,    33,    40,    71,    44,    39,
      71,    75,    42,    44,    75,    40,    40,    42,    71,    44,
      44,    52,    75,    39,    34,     6,    42,     8,    43,    39,
      45,     6,    13,    14,    44,    16,    17,    18,    40,    76,
      42,    22,     6,    74,    51,     6,   132,   133,   134,   135,
     136,   137,   138,   139,    35,    36,    37,    38,    44,   145,
       3,     4,     5,     6,     7,    44,    47,    48,   121,   121,
      44,    35,    36,    37,    38,     9,    10,    11,    12,    44,
      43,   118,    45,     3,     4,     5,     6,     7,   125,    39,
      39,    34,    21,   124,     6,    24,    30,    31,    32,    33,
     186,    44,   166,   140,   141,   166,    35,    36,    37,    38,
     147,   164,   164,   166,    34,     6,   169,   169,    44,    35,
      36,    37,    38,    42,    44,    45,    40,     6,   165,    45,
     183,   195,   185,    13,   195,    21,   200,    39,    24,   200,
      40,    42,   195,   196,   196,    44,    42,   200,   212,    35,
      36,    37,    38,   217,     6,    19,   217,    45,    46,    47,
      35,    36,    37,    38,   217,    53,    35,    36,    37,    38,
      45,    59,    40,    61,    42,   239,   183,   214,   185,   232,
      15,    69,   235,   220,    42,    44,    39,   224,    45,    44,
     243,    39,    46,   254,   208,   251,   249,   249,     9,   236,
      74,   254,   168,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   232,   114,    -1,   235,    -1,
       9,    10,    11,    12,    -1,    -1,   243,    -1,    -1,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,   143,   144,     6,    -1,     8,
      -1,    -1,    -1,    -1,    13,    14,    45,    16,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,   170,    -1,    -1,    -1,    35,    36,    37,    38,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   222,    -1,    28,    29,    -1,   227,
      32,    33,   230,     9,    10,    11,    12,    39,    -1,    -1,
     238,     9,    10,    11,    12,    -1,    -1,    -1,   246,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    45,
       9,    10,    11,    12,    -1,    -1,    -1,    45,     9,    10,
      11,    12,    -1,    -1,     9,    10,    11,    12,    -1,    28,
      29,    -1,    -1,    32,    33,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    28,    29,    -1,    45,    32,    33,     9,
      10,    11,    12,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     9,
      10,    11,    12,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,     9,    10,    11,    12,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     9,
      10,    11,    12,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,     9,    10,    11,    12,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     9,
      10,    11,    12,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,     9,    10,    11,    12,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     9,
      10,    11,    12,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,     9,    10,    11,    12,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     9,
      10,    11,    12,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    24,    35,    36,    37,    38,    50,    74,    75,
      76,    23,    47,    82,     0,    23,    24,    76,     6,     6,
       8,    13,    14,    16,    17,    18,    22,    51,    52,    53,
      56,    57,    60,    61,    63,    64,    65,    67,    74,    80,
      81,    82,     6,    82,    44,    40,    42,    44,    74,    44,
      44,    82,    44,    44,     3,     4,     5,     6,     7,    34,
      39,    44,    70,    80,    48,    52,    83,    39,     6,    40,
      39,    51,    72,    83,    44,    51,    45,    74,    77,    70,
      70,    45,    70,    79,     6,     3,     4,     6,     7,    44,
      71,    71,    72,     6,    59,    74,    70,    40,    70,    70,
       9,    10,    11,    12,    26,    27,    28,    29,    30,    31,
      32,    33,    39,    39,    42,    58,    70,    83,    45,    77,
      83,    82,     6,    78,    43,    45,    41,    43,    45,    42,
      40,    71,     9,    10,    11,    12,    28,    29,    32,    33,
      45,    45,    13,    40,    42,    39,     6,    45,    70,    45,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    41,    82,    45,    51,    40,    74,    82,
      42,    70,    70,    70,    45,    71,    71,    71,    71,    71,
      71,    71,    71,    82,    62,    82,    44,    70,    70,    71,
      42,    82,    41,    39,     6,    51,    82,    83,    70,    78,
      51,    70,    39,    41,    72,    72,    71,    41,    39,    70,
      19,    68,    69,    39,    42,    54,    83,    51,    41,    83,
      15,    45,    42,     6,    45,    60,    66,    44,    19,    83,
      82,    83,    82,    39,    70,    82,    45,    70,    44,    55,
      70,    72,    72,    82,    45,    70,    43,    83,    72,    46,
      73,    45,    70,    39,    51,    73
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
#line 67 "x.y"
    { printf("valid with functions\n");  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 68 "x.y"
    { printf("valid\n"); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 71 "x.y"
    {(yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 72 "x.y"
    {(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 75 "x.y"
    { printf("decConst\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 76 "x.y"
    { printf("decVar\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 77 "x.y"
    { printf("assignment\n"); (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 78 "x.y"
    { printf("while\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 79 "x.y"
    { printf("do\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 80 "x.y"
    { printf("for\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 81 "x.y"
    { printf("switch\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 82 "x.y"
    { printf("if\n"); (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 83 "x.y"
    { printf("dec array\n"); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 84 "x.y"
    { printf("return\n"); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 85 "x.y"
    { printf("func call\n"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 86 "x.y"
    {(yyval.nPtr) = (yyvsp[(2) - (2)].nPtr);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 103 "x.y"
    { (yyval.nPtr) = opr(CONST, 2, id((yyvsp[(3) - (6)].strVal), constVariable, (yyvsp[(2) - (6)].conType)), (yyvsp[(5) - (6)].nPtr)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 106 "x.y"
    { if((yyvsp[(3) - (3)].nPtr)==NULL){
																 id((yyvsp[(2) - (3)].strVal), variable, (yyvsp[(1) - (3)].conType));
																}
															else{
																 (yyval.nPtr) = opr('=', 2, id((yyvsp[(2) - (3)].strVal), variable, (yyvsp[(1) - (3)].conType)), (yyvsp[(3) - (3)].nPtr)); 
															}
														;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 115 "x.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 116 "x.y"
    {(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 120 "x.y"
    { (yyval.nPtr) = opr('=',2,getid((yyvsp[(1) - (3)].strVal)),(yyvsp[(3) - (3)].nPtr));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 121 "x.y"
    { (yyval.nPtr) = opr('=', 2, id((yyvsp[(2) - (4)].strVal), variable, (yyvsp[(1) - (4)].conType)), (yyvsp[(4) - (4)].nPtr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 128 "x.y"
    { (yyval.nPtr) = opr('=',2,getid((yyvsp[(1) - (3)].strVal)),(yyvsp[(3) - (3)].nPtr));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 135 "x.y"
    { (yyval.nPtr) = opr(IF, 2,  (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 138 "x.y"
    { (yyval.nPtr) = (yyvsp[(2) - (2)].nPtr);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 139 "x.y"
    { (yyval.nPtr) = opr(ELSE, 2, (yyvsp[(2) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 145 "x.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (6)].nPtr), (yyvsp[(6) - (6)].nPtr));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 148 "x.y"
    { (yyval.nPtr) = opr(DO, 2, (yyvsp[(3) - (8)].nPtr), (yyvsp[(6) - (8)].nPtr));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 151 "x.y"
    { (yyval.nPtr) = opr(FOR, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 154 "x.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(4) - (4)].nPtr), (yyvsp[(1) - (4)].nPtr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 155 "x.y"
    { (yyval.nPtr) = (yyvsp[(3) - (3)].nPtr);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 161 "x.y"
    { (yyval.nPtr) = opr(SWITCH, 2, (yyvsp[(3) - (6)].nPtr), (yyvsp[(6) - (6)].nPtr));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 164 "x.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 174 "x.y"
    { (yyval.nPtr) = opr(CASE_JOIN,2, (yyvsp[(1) - (6)].nPtr), opr(CASE, 2, (yyvsp[(4) - (6)].nPtr), (yyvsp[(6) - (6)].nPtr)));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 175 "x.y"
    { (yyval.nPtr) = opr(CASE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 181 "x.y"
    {union Value x; x.intVal=(yyvsp[(1) - (1)].intVal); (yyval.nPtr)=con(typeint,x);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 182 "x.y"
    {union Value x; x.floatVal=(yyvsp[(1) - (1)].floatVal); (yyval.nPtr)=con(typefloat,x);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 183 "x.y"
    {union Value x; x.boolVal=(yyvsp[(1) - (1)].boolVal); (yyval.nPtr)=con(typebool,x);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 184 "x.y"
    {union Value x; x.strVal=(yyvsp[(1) - (1)].strVal); (yyval.nPtr)=con(typestring,x);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 185 "x.y"
    {(yyval.nPtr) = opr('~', 1, (yyvsp[(2) - (2)].nPtr));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 186 "x.y"
    {(yyval.nPtr) = getid((yyvsp[(1) - (1)].strVal));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 187 "x.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 188 "x.y"
    {(yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 189 "x.y"
    {(yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 190 "x.y"
    {(yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 191 "x.y"
    {(yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 192 "x.y"
    {(yyval.nPtr) = opr('&', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 193 "x.y"
    {(yyval.nPtr) = opr('|', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 194 "x.y"
    {(yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 195 "x.y"
    {(yyval.nPtr) = opr(COND_GREQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 196 "x.y"
    {(yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 197 "x.y"
    {(yyval.nPtr) = opr(COND_LSEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 198 "x.y"
    {(yyval.nPtr) = opr(COND_EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 199 "x.y"
    {(yyval.nPtr) = opr(COND_NEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 200 "x.y"
    {(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 204 "x.y"
    {(yyval.nPtr) = opr('&', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 205 "x.y"
    {(yyval.nPtr) = opr('|', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 206 "x.y"
    {(yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 207 "x.y"
    {(yyval.nPtr) = opr(COND_GREQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 208 "x.y"
    {(yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 209 "x.y"
    {(yyval.nPtr) = opr(COND_LSEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 210 "x.y"
    {(yyval.nPtr) = opr(COND_EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 211 "x.y"
    {(yyval.nPtr) = opr(COND_NEQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 212 "x.y"
    {(yyval.nPtr)=(yyvsp[(2) - (3)].nPtr);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 213 "x.y"
    {(yyval.nPtr) = getid((yyvsp[(1) - (1)].strVal));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 215 "x.y"
    {union Value x; x.boolVal=(yyvsp[(1) - (1)].boolVal); (yyval.nPtr)=con(typebool,x);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 216 "x.y"
    {union Value x; x.intVal=(yyvsp[(1) - (1)].intVal); (yyval.nPtr)=con(typeint,x);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 217 "x.y"
    {union Value x; x.floatVal=(yyvsp[(1) - (1)].floatVal); (yyval.nPtr)=con(typefloat,x);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 221 "x.y"
    {(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 222 "x.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 225 "x.y"
    {(yyval.nPtr) = (yyvsp[(2) - (2)].nPtr);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 226 "x.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 231 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 232 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 233 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 234 "x.y"
    { (yyval.conType)=(yyvsp[(1) - (1)].conType);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 240 "x.y"
    {printf("func");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 241 "x.y"
    {printf("func");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 276 "x.y"
    { printf("openbraces\n"); currentSymTable = startScope(tree);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 278 "x.y"
    { printf("closebraces\n"); symTablePrint(currentSymTable); currentSymTable = endScope(tree);;}
    break;



/* Line 1455 of yacc.c  */
#line 2256 "x.tab.c"
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
#line 281 "x.y"


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

nodeType *id(char*  label, Type type, conTypeEnum dataType) {
    nodeType *p;     /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL){
         yyerror("out of memory");
	}
	 
	int flag = symInsert(currentSymTable, label, type, dataType);
	
	if(flag == -1){
		printf("\nRedeclaration\n");
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
		printf("var not found\n");
	}else{
     /* copy information */
		p->type = typeId;
		p->id.label = value;
		p->id.symTablePtr = sym->myTable;
		p->retType = sym->datatype;
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
	
	// if(oper==WHILE){
	// 	//printf("\nWHILEEEEEEEEE\n %c \n %d\n", p->opr.op[0]->opr.oper, p->opr.op[1]->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal);//p->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal );
	// }
	// if(oper==DO){
	// 	printf("\nDOOOOOO\n %d \n %d\n",  p->opr.op[0]->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal, p->opr.op[1]->opr.op[1]->con.intVal);//p->opr.op[1]->opr.op[1]->opr.op[1]->con.intVal );
	// }

	// /*if(oper==FOR){
	// 	printf("\nfor\n %c \n\n", p->opr.op[2]->opr.op[1]->opr.op[1]->opr.oper ); 
	// }*/

	// if(oper==IF){
	// 	printf("\nIFFFFFFFFF\n %d\n\n" , p->opr.op[1]->opr.op[0]->opr.op[1]->con.intVal );
	// }
	
	
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
			printf("\n+ - * / error\n");
			yyerror("wrong");
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
			printf("\n== != error\n");
		}
	}
	// Check for < <= > >=
	else if( p->opr.oper == '<' || p->opr.oper == '>' || p->opr.oper == COND_GREQ 
	|| p->opr.oper == COND_LSEQ ){
		// Check types equal and are numbers
		if((p->opr.op[0]->retType == p->opr.op[1]->retType) && (p->opr.op[1]->retType == typeint || p->opr.op[1]->retType == typefloat)){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\n< > <= >= error\n");
		}
	}
	// Check for & |
	else if( p->opr.oper == '|' || p->opr.oper == '&'){
		// Check types are equal and booleans
		if((p->opr.op[0]->retType == p->opr.op[1]->retType) && (p->opr.op[1]->retType == typebool)){
			p->retType = typebool;
		}else{
			printf("\n| & error\n");
		}
	}
	// CHeck for ~
	else if (p->opr.oper == '~'){
		if(p->opr.op[0]-> retType == typeint || p->opr.op[0]-> retType == typefloat){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\n~ error\n");
		}
	}
	//Check for = (Assignment)
	else if (p->opr.oper == '='){	
		struct Symbol* symbol = symLookup(p->opr.op[0]->id.symTablePtr, p->opr.op[0]->id.label );
		// Check types are equal and LHS is variable
		if( (p->opr.op[0]->retType == p->opr.op[1]->retType) &&
		symbol->type == variable){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\nassignment error\n");

		}
	}
	// Check for constnt initialization
	else if( p->opr.oper == CONST){
		// Check types are equal
		if( (p->opr.op[0]->retType == p->opr.op[1]->retType)){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\nconstant init error\n");

		}
	}
	// Check CASE ==> return the type of the expr
	else if (p->opr.oper == CASE){
		p->retType = p->opr.op[0]->retType;
	}
	// Check for CASE_JOIN that expr types are the same
	else if(p->opr.oper == CASE_JOIN){
		// Check types are equal
		if( (p->opr.op[0]->retType == p->opr.op[1]->retType)){
			p->retType = p->opr.op[0]->retType;
		}else{
			printf("\ncases types not equal\n");
		}
	}
	// Check for SWITCH : expr type is same as inner expressions
	else if(p->opr.oper == SWITCH){
		if(p->opr.op[0]->retType == p->opr.op[1]->retType){
			p->retType = typevoid;
		}else{
			printf("\nswitch and cases types not equal\n");
		}
	}	
	else{
		p->retType = typevoid;
	}

}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
extern FILE *yyin;



int main(int argc, char * argv[]){
  tree = allocateSymTree();
  currentSymTable = startScope(tree);
  
  yyin=fopen(argv[1],"r");
  yyparse();

  symTablePrint( currentSymTable);
  return 0;
}

