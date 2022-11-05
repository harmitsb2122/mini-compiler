/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "prob1.y"

  #include <stdio.h>
  #include<string.h>
  #include <stdbool.h>
  #include <stdlib.h>
  int yylex();
  int yyerror();
  int line_no = 0;
  bool error_status = false;
  int variable_index=0,label_index=0;
  char* generateVariable();
  char* generateLabel();
  int MAXSIZE = 50;       
  char instack[50][50];
  char outstack[50][50];   
  int topin = 0;
  int topout = 0;
  void pushin();
  void pushout();   
  char* popin();
  char* popout();
  struct Node{
    char vname[50];
    char type[50];
    int addr;
    int size;
  };
  
  struct SNode{
    char vname[50];
    char type[50];
    int addr;
    int size;
    int tab_sz;
    struct Node* tables[50];
  };

  struct TNode{
    int size;
    int struct_table_size;
    struct Node* tables[50];
    struct SNode* struct_tables[50];
  };
  struct TNode *Table_Stack[50];
  struct Node variable[1000];
  struct SNode struct_variable[1000];
  int var_idx = 0;
  int struct_var_idx = 0;
  struct TNode stack_node[50];
  int table_idx = 0;
  int base_address = 0;
  int offset = 1;
  int struct_offset = 1;
  char temp_store[50];
  void init();
  void insert();
  bool typecheckStruct(char* type,char* data);
  bool redeclarationStruct(char* type,char* data);
  bool missingdeclarationStruct(char* data);
  bool typecheck(char* type,char* data);
  bool redeclaration(char* type,char* data);
  bool missingdeclaration(char* data);
  void print_table();

#line 135 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    TRUE = 259,
    FALSE = 260,
    EQ = 261,
    NEQ = 262,
    LOR = 263,
    LAND = 264,
    LTEQ = 265,
    GTEQ = 266,
    LT = 267,
    GT = 268,
    XOR = 269,
    BOR = 270,
    BAND = 271,
    AEQ = 272,
    INC = 273,
    DEC = 274,
    NUM = 275,
    ID = 276,
    IF = 277,
    ELSE = 278,
    STRUCT = 279,
    INT = 280,
    FLOAT = 281,
    POINTER = 282,
    CHAR = 283,
    ARROP = 284,
    ARRCL = 285,
    CRLOP = 286,
    CRLCL = 287,
    UMINUS = 288
  };
#endif
/* Tokens.  */
#define WHILE 258
#define TRUE 259
#define FALSE 260
#define EQ 261
#define NEQ 262
#define LOR 263
#define LAND 264
#define LTEQ 265
#define GTEQ 266
#define LT 267
#define GT 268
#define XOR 269
#define BOR 270
#define BAND 271
#define AEQ 272
#define INC 273
#define DEC 274
#define NUM 275
#define ID 276
#define IF 277
#define ELSE 278
#define STRUCT 279
#define INT 280
#define FLOAT 281
#define POINTER 282
#define CHAR 283
#define ARROP 284
#define ARRCL 285
#define CRLOP 286
#define CRLCL 287
#define UMINUS 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "prob1.y"

	char string[100];

#line 257 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,     2,     2,     2,     2,
      38,    39,     2,    33,    41,    34,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
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
      25,    26,    27,    28,    29,    30,    31,    32,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   136,   136,   136,   151,   151,   153,   153,   155,   155,
     157,   159,   159,   162,   161,   189,   189,   195,   200,   213,
     219,   220,   223,   231,   239,   221,   254,   266,   270,   270,
     271,   321,   370,   420,   471,   472,   474,   474,   474,   476,
     479,   481,   481,   492,   492,   494,   494,   538,   540,   542,
     542,   597,   599,   599,   601,   601,   603,   607,   611,   615,
     619,   623,   627,   629,   633,   637,   639,   652,   665,   678,
     692,   696,   707,   711,   716,   717,   718,   719,   720,   721,
     722,   723,   725
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "TRUE", "FALSE", "EQ", "NEQ",
  "LOR", "LAND", "LTEQ", "GTEQ", "LT", "GT", "XOR", "BOR", "BAND", "AEQ",
  "INC", "DEC", "NUM", "ID", "IF", "ELSE", "STRUCT", "INT", "FLOAT",
  "POINTER", "CHAR", "ARROP", "ARRCL", "CRLOP", "CRLCL", "'+'", "'-'",
  "'/'", "UMINUS", "'!'", "'('", "')'", "';'", "','", "$accept", "start",
  "$@1", "slst", "BODY", "E", "DUMMY", "CONTROL", "E1", "$@2", "E2", "$@3",
  "COND", "STMT", "$@4", "$@5", "$@6", "VAR_DEC", "$@7", "REP", "TYPE",
  "B", "NEXT", "ARRM", "$@8", "PTRDEC", "STRUCTDEC", "$@9", "OPTID",
  "INSSTR", "$@10", "C", "$@11", "D", "AFTER", "LATER", "PRE", "ANY",
  "CMP", "ASSIGN", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    43,    45,    47,   288,    33,    40,    41,
      59,    44
};
# endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -93,     6,    75,   -93,   -13,   -11,    97,     4,    17,   -93,
     -93,   -93,   -93,     0,     2,   -93,    15,   -93,    31,    33,
      40,   -93,   -93,   -93,   -93,   -93,    49,    45,   -93,   -93,
      52,   -93,   -93,   -93,   -93,   -93,    62,    31,   -93,   -93,
     -93,   -93,   -93,   -93,    11,     1,     5,   -93,   -93,    81,
     -93,    99,    46,    45,    63,    73,    78,    81,   -93,   -93,
      49,    49,    49,    49,    49,   -93,    58,    58,    49,    53,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    49,    62,
      88,    82,   -93,    90,    94,    62,    58,   -93,   -93,   -93,
      61,    61,   -93,   -93,   -93,    23,    93,    23,   -93,   104,
      96,   -93,   108,   -93,    81,   -93,    63,    89,   -93,   -93,
     -93,   -93,    58,    98,    46,    63,   101,   -93,   -93,   -93,
     100,    94,   -93,   110,   -93,   -93,   103,   -93,    63,   105,
     -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    10,     1,     0,     0,     0,     0,     0,    36,
      37,    38,     3,     5,     0,     8,     0,    28,    34,     0,
       0,    66,    68,    82,    67,    69,     0,     0,    45,     4,
       0,    15,     9,    11,    12,    20,     0,    44,    35,    21,
      27,    72,    73,    70,    71,     0,    62,    61,    65,    71,
      22,    19,    51,     0,    10,    39,    29,    32,    40,    43,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     6,     0,     0,     0,     0,    58,    60,    59,
      56,    57,    71,    63,    64,    18,     0,    17,    49,    48,
       0,    16,     0,    42,    30,    33,    10,     0,    47,    46,
      13,    52,     0,     0,    51,    10,     0,    31,    23,    50,
       0,    54,    53,     0,    14,    55,     0,    24,    10,     0,
      25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,     7,   -92,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,    83,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -50,   -93,   -72,   -93,   -93,   102,   -93,   -93,   -93,    21,
     -93,    19,   -93,   -93,   -17,    51,    -2,   -26,   -93,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    82,    83,    13,    14,    32,    33,   115,
      34,    54,    50,    15,    69,   123,   128,    16,    36,    56,
      17,    18,    57,    58,    84,    38,    19,    52,   109,    80,
     107,   103,   116,   122,    45,    46,    47,    48,    78,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    51,    79,   -10,    68,    30,     3,    98,    21,    12,
      22,    20,    86,   104,   113,    60,    61,    62,     4,     5,
      29,     6,     7,   120,     8,     9,    10,    51,    11,    24,
      25,   -10,    66,    31,    63,    64,   129,    60,    61,    62,
      67,    65,    27,    87,    88,    89,    90,    91,    28,    41,
      42,    95,    20,    41,    42,    35,    63,    64,    37,   112,
     105,    97,    41,    42,    79,    43,    49,     4,     5,    43,
      44,     9,    10,    39,    11,    60,    61,    62,    43,    92,
      40,     4,     5,    55,     6,     7,   117,     8,     9,    10,
      53,    11,    96,     4,     5,    -7,     6,     7,    23,     8,
       9,    10,   -41,    11,    20,    70,    71,    72,    73,    74,
      75,    76,    77,    20,    23,    24,    25,    93,    94,    85,
      99,   100,   101,   102,   106,   108,    20,   110,   111,   114,
     118,   121,   124,   126,   127,   119,    81,   130,     0,    59,
     125
};

static const yytype_int16 yycheck[] =
{
       2,    27,    52,     3,    49,     3,     0,    79,    21,     2,
      21,    13,    57,    85,   106,    14,    15,    16,    18,    19,
      13,    21,    22,   115,    24,    25,    26,    53,    28,    18,
      19,    31,    27,    31,    33,    34,   128,    14,    15,    16,
      35,    40,    38,    60,    61,    62,    63,    64,    31,     4,
       5,    68,    54,     4,     5,    40,    33,    34,    27,   104,
      86,    78,     4,     5,   114,    20,    21,    18,    19,    20,
      21,    25,    26,    40,    28,    14,    15,    16,    20,    21,
      40,    18,    19,    21,    21,    22,   112,    24,    25,    26,
      38,    28,    39,    18,    19,    32,    21,    22,    17,    24,
      25,    26,    29,    28,   106,     6,     7,     8,     9,    10,
      11,    12,    13,   115,    17,    18,    19,    66,    67,    41,
      32,    39,    32,    29,    31,    21,   128,    31,    20,    40,
      32,    30,    32,    23,    31,   114,    53,    32,    -1,    37,
     121
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,    18,    19,    21,    22,    24,    25,
      26,    28,    45,    47,    48,    55,    59,    62,    63,    68,
      78,    21,    21,    17,    18,    19,    81,    38,    31,    45,
       3,    31,    49,    50,    52,    40,    60,    27,    67,    40,
      40,     4,     5,    20,    21,    76,    77,    78,    79,    21,
      54,    79,    69,    38,    53,    21,    61,    64,    65,    67,
      14,    15,    16,    33,    34,    40,    27,    35,    81,    56,
       6,     7,     8,     9,    10,    11,    12,    13,    80,    62,
      71,    54,    45,    46,    66,    41,    81,    76,    76,    76,
      76,    76,    21,    77,    77,    76,    39,    76,    64,    32,
      39,    32,    29,    73,    64,    79,    31,    72,    21,    70,
      31,    20,    81,    46,    40,    51,    74,    79,    32,    71,
      46,    30,    75,    57,    32,    73,    23,    31,    58,    46,
      32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    51,    50,    53,    52,    54,    54,    54,
      55,    55,    56,    57,    58,    55,    55,    55,    60,    59,
      61,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    66,    65,    67,    67,    69,    68,    70,    70,    72,
      71,    71,    74,    73,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     0,     1,     2,
       0,     1,     1,     0,     8,     0,     4,     3,     3,     1,
       2,     2,     0,     0,     0,    14,     4,     2,     0,     3,
       3,     5,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     0,     3,     2,     1,     0,     6,     1,     0,     0,
       5,     0,     0,     4,     1,     2,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 2:
#line 136 "prob1.y"
        {
          init();
        }
#line 1533 "y.tab.c"
    break;

  case 3:
#line 139 "prob1.y"
             { 
              if(error_status)
              {
                printf("\nSnippet no: %d : ERROR\n",++line_no,variable_index=0,label_index=0);
              }
              else 
              { 
                printf("\nSnippet no: %d : ACCEPTED\n",++line_no,variable_index=0,label_index=0);
              }
              }
#line 1548 "y.tab.c"
    break;

  case 7:
#line 153 "prob1.y"
              {}
#line 1554 "y.tab.c"
    break;

  case 10:
#line 157 "prob1.y"
        {char topp[50]; strcpy(topp,generateLabel()); pushout(topp); printf("%s :\n",topp);}
#line 1560 "y.tab.c"
    break;

  case 13:
#line 162 "prob1.y"
            {
              // print_table(Table_Stack[table_idx-1]);
              init();
              // print_table(Table_Stack[table_idx-1]);
              char topp[50];
              strcpy(topp,instack[topin-1]);
              topin=topin-1;
              printf("%s :\n",topp);
          }
#line 1574 "y.tab.c"
    break;

  case 14:
#line 174 "prob1.y"
            {
              char topp[50];
              strcpy(topp,outstack[topout-2]);
              printf("goto %s\n",topp);
              strcpy(topp,outstack[topout-1]);
              topout=topout-2;
              printf("%s :",topp);
              table_idx--;
       }
#line 1588 "y.tab.c"
    break;

  case 15:
#line 189 "prob1.y"
            {
            init();
          }
#line 1596 "y.tab.c"
    break;

  case 16:
#line 193 "prob1.y"
            {table_idx--;}
#line 1602 "y.tab.c"
    break;

  case 17:
#line 195 "prob1.y"
                     {strcpy((yyval.string),generateLabel()); printf("if %s %s %s goto %s\n",(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string),(yyval.string));
                      pushin((yyval.string));
                      strcpy((yyval.string),generateLabel()); printf("goto %s\n",(yyval.string));
                      pushout((yyval.string));
                      }
#line 1612 "y.tab.c"
    break;

  case 18:
#line 200 "prob1.y"
                        {
                        if(missingdeclaration((yyvsp[-2].string)))
                        {
                          printf( "error : var '%s' is not declared in the scope\n",(yyvsp[-2].string));
                        }
                        else
                        {
                          strcpy((yyval.string),generateLabel()); printf("if %s %s %s goto %s\n",(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string),(yyval.string));
                          pushin((yyval.string));
                          strcpy((yyval.string),generateLabel()); printf("goto %s\n",(yyval.string));
                          pushout((yyval.string));
                        }
                      }
#line 1630 "y.tab.c"
    break;

  case 19:
#line 213 "prob1.y"
            {strcpy((yyval.string),generateLabel()); printf("if %s != 0 goto %s\n",(yyvsp[0].string),(yyval.string));
              pushin((yyval.string));
             strcpy((yyval.string),generateLabel()); printf("goto %s\n",(yyval.string));
              pushout((yyval.string));
           }
#line 1640 "y.tab.c"
    break;

  case 22:
#line 223 "prob1.y"
              {
                init();
                char topp[50];
                strcpy(topp,instack[topin-1]);
                topin=topin-1;
                printf("%s :\n",topp);
              }
#line 1652 "y.tab.c"
    break;

  case 23:
#line 231 "prob1.y"
                        {
                      char topp[50];
                      strcpy(topp,generateLabel());
                      pushout(topp);
                      printf("goto %s\n",topp);
                    }
#line 1663 "y.tab.c"
    break;

  case 24:
#line 239 "prob1.y"
                      {
                      char topp[50];
                      strcpy(topp,outstack[topout-2]);
                      strcpy(outstack[topout-2],outstack[topout-1]);
                      topout-=1;
                      printf("%s :\n",topp);
                    }
#line 1675 "y.tab.c"
    break;

  case 25:
#line 247 "prob1.y"
                    {
                      char topp[50];
                      strcpy(topp,outstack[topout-1]);
                      topout=topout-1;
                      printf("%s :\n",topp);
                      table_idx--;
                    }
#line 1687 "y.tab.c"
    break;

  case 26:
#line 254 "prob1.y"
                           {

                              // print_table();                        
                              if(missingdeclaration((yyvsp[-3].string)))
                              {
                                printf( "error : var '%s' is not declared in the scope\n",(yyvsp[-3].string));
                              }
                              else
                              {
                                printf("%s = %s",(yyval.string),(yyvsp[-1].string));
                              }     
                           }
#line 1704 "y.tab.c"
    break;

  case 28:
#line 270 "prob1.y"
               {strcpy(temp_store,(yyvsp[0].string));}
#line 1710 "y.tab.c"
    break;

  case 30:
#line 271 "prob1.y"
                             { 
                                  // printf("%s\n",$2);
                                bool check1 = typecheck(temp_store,(yyvsp[0].string));
                                bool check2 = redeclaration(temp_store,(yyvsp[0].string));
                                if(check1)
                                {
                                  printf("error : conflicting types for '%s'\n",(yyvsp[0].string));
                                }
                                else if(check2)
                                {
                                  printf("error : redeclaration of '%s'\n",(yyvsp[0].string));
                                }
                                else
                                {
                                  strcpy(variable[var_idx].type,temp_store);
                                  strcpy(variable[var_idx].vname,(yyvsp[0].string));
                                  if(!strcmp(temp_store,"int"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"float"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"char"))
                                  {
                                    offset*=1;
                                  }
                                  else if(!strcmp(temp_store,"pointer"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"struct"))
                                  {
                                    offset*=1;
                                  } 
                                  // printf("%d ",base_address);
                                  printf("0x%04x ", base_address);
                                  variable[var_idx].addr = base_address;
                                  int cur_size = offset;
                                  variable[var_idx++].size = offset;
                                  base_address+=offset;
                                  offset = 1;
                                  insert(&variable[var_idx-1]);
                                  printf("%s ",(yyvsp[0].string));
                                  printf("%s ",temp_store);
                                  printf("%d\n",cur_size);
                                }
                                // print_table();
                              }
#line 1765 "y.tab.c"
    break;

  case 31:
#line 321 "prob1.y"
                                   {
                                  bool check1 = typecheck(temp_store,(yyvsp[-2].string));
                                  bool check2 = redeclaration(temp_store,(yyvsp[-2].string));
                                  if(check1)
                                  {
                                    printf("error : conflicting types for '%s'\n",(yyvsp[-2].string));
                                  }
                                  else if(check2)
                                  {
                                    printf("error : redeclaration of '%s'\n",(yyvsp[-2].string));
                                  }
                                  else
                                  {
                                    printf("%s = %s\n",(yyvsp[-2].string),(yyvsp[0].string));
                                    strcpy(variable[var_idx].type,temp_store);
                                    strcpy(variable[var_idx].vname,(yyvsp[-2].string));
                                    if(!strcmp(temp_store,"int"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"float"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"char"))
                                    {
                                      offset*=1;
                                    }
                                    else if(!strcmp(temp_store,"pointer"))
                                    {
                                      offset*=4;
                                    } 
                                    else if(!strcmp(temp_store,"struct"))
                                    {
                                      offset*=1;
                                    } 
                                    // printf("%d ",base_address);
                                    printf("0x%04x ", base_address);
                                    variable[var_idx].addr = base_address;
                                    int cur_size = offset;
                                    variable[var_idx++].size = offset;
                                    base_address+=offset;
                                    offset = 1;
                                    insert(&variable[var_idx-1]);
                                    printf("%s ",(yyvsp[-2].string));
                                    printf("%s ",temp_store);
                                    printf("%d\n",cur_size);
                                  }
                               }
#line 1819 "y.tab.c"
    break;

  case 32:
#line 370 "prob1.y"
                  { 
                                  // printf("%s\n",$2);
                                bool check1 = typecheck(temp_store,(yyvsp[0].string));
                                bool check2 = redeclaration(temp_store,(yyvsp[0].string));
                                if(check1)
                                {
                                  printf("error : conflicting types for '%s'\n",(yyvsp[0].string));
                                }
                                else if(check2)
                                {
                                  printf("error : redeclaration of '%s'\n",(yyvsp[0].string));
                                }
                                else
                                {
                                  strcpy(variable[var_idx].type,temp_store);
                                  strcpy(variable[var_idx].vname,(yyvsp[0].string));
                                  if(!strcmp(temp_store,"int"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"float"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"char"))
                                  {
                                    offset*=1;
                                  }
                                  else if(!strcmp(temp_store,"pointer"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"struct"))
                                  {
                                    offset*=1;
                                  } 
                                  // printf("%d ",base_address);
                                  printf("0x%04x ", base_address);
                                  variable[var_idx].addr = base_address;
                                  int cur_size = offset;
                                  variable[var_idx++].size = offset;
                                  base_address+=offset;
                                  offset = 1;
                                  insert(&variable[var_idx-1]);
                                  printf("%s ",(yyvsp[0].string));
                                  printf("%s ",temp_store);
                                  printf("%d\n",cur_size);
                                }
                                // print_table();
                              }
#line 1874 "y.tab.c"
    break;

  case 33:
#line 420 "prob1.y"
                            {
                                  bool check1 = typecheck(temp_store,(yyvsp[-2].string));
                                  bool check2 = redeclaration(temp_store,(yyvsp[-2].string));
                                  if(check1)
                                  {
                                    printf("error : conflicting types for '%s'\n",(yyvsp[-2].string));
                                  }
                                  else if(check2)
                                  {
                                    printf("error : redeclaration of '%s'\n",(yyvsp[-2].string));
                                  }
                                  else
                                  {
                                    printf("%s = %s\n",(yyvsp[-2].string),(yyvsp[0].string));
                                    strcpy(variable[var_idx].type,temp_store);
                                    strcpy(variable[var_idx].vname,(yyvsp[-2].string));
                                    if(!strcmp(temp_store,"int"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"float"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"char"))
                                    {
                                      offset*=1;
                                    }
                                    else if(!strcmp(temp_store,"pointer"))
                                    {
                                      offset*=4;
                                    } 
                                    else if(!strcmp(temp_store,"struct"))
                                    {
                                      offset*=1;
                                    } 
                                    // printf("%d ",base_address);
                                    printf("0x%04x ", base_address);
                                    variable[var_idx].addr = base_address;
                                    int cur_size = offset;
                                    variable[var_idx++].size = offset;
                                    base_address+=offset;
                                    offset = 1;
                                    insert(&variable[var_idx-1]);
                                    printf("%s ",(yyvsp[-2].string));
                                    printf("%s ",temp_store);
                                    printf("%d\n",cur_size);
                                  }
                               }
#line 1928 "y.tab.c"
    break;

  case 34:
#line 471 "prob1.y"
            {strcpy((yyval.string),(yyvsp[0].string));}
#line 1934 "y.tab.c"
    break;

  case 35:
#line 472 "prob1.y"
                   {strcpy((yyval.string),"pointer");}
#line 1940 "y.tab.c"
    break;

  case 36:
#line 474 "prob1.y"
              {strcpy((yyval.string),"int");}
#line 1946 "y.tab.c"
    break;

  case 37:
#line 474 "prob1.y"
                                         {strcpy((yyval.string),"float");}
#line 1952 "y.tab.c"
    break;

  case 38:
#line 474 "prob1.y"
                                                                     {strcpy((yyval.string),"char");}
#line 1958 "y.tab.c"
    break;

  case 39:
#line 476 "prob1.y"
             {
                strcpy((yyval.string),(yyvsp[0].string));
             }
#line 1966 "y.tab.c"
    break;

  case 41:
#line 481 "prob1.y"
             {offset = 1;}
#line 1972 "y.tab.c"
    break;

  case 42:
#line 481 "prob1.y"
                             {
                                // if(missingdeclaration($1))
                                // {
                                //   printf( "error : var '%s' is not declared in the scope\n",$1);
                                // }
                                // else
                                // {
                                  strcpy((yyval.string),(yyvsp[-2].string));
                                // }
                             }
#line 1987 "y.tab.c"
    break;

  case 45:
#line 494 "prob1.y"
                          {
                          struct_variable[struct_var_idx].tab_sz = 0;
                          struct_offset = base_address;
                          init();
                        }
#line 1997 "y.tab.c"
    break;

  case 46:
#line 503 "prob1.y"
                {
                  // print_table();
                  bool check1 = typecheck((yyvsp[-5].string),(yyvsp[0].string));
                  bool check2 = redeclaration((yyvsp[-5].string),(yyvsp[0].string));
                  
                  if(check1)
                  {
                    printf("error : conflicting types for '%s'\n",(yyvsp[0].string));
                  }
                  else if(check2)
                  {
                    printf("error : redeclaration of '%s'\n",(yyvsp[0].string));
                  }
                  else
                  {
                    // finding the offset
                    int temp = struct_offset;
                    struct_offset = base_address - struct_offset;
                    offset = struct_offset;
                    base_address = temp;
                    printf("0x%04x ", base_address);
                    strcpy(struct_variable[struct_var_idx].vname,(yyvsp[0].string));
                    strcpy(struct_variable[struct_var_idx].type,"struct");
                    printf("%s ",(yyvsp[0].string));
                    printf("%s ",(yyvsp[-5].string));
                    printf("%d\n",offset);
                    struct_variable[struct_var_idx].size = offset;
                    insert_struct(&struct_variable[struct_var_idx]);
                    table_idx--;
                    struct_var_idx++;
                    offset = 1;                
                  }
                }
#line 2035 "y.tab.c"
    break;

  case 47:
#line 538 "prob1.y"
           {
              strcpy((yyval.string),(yyvsp[0].string));
           }
#line 2043 "y.tab.c"
    break;

  case 48:
#line 540 "prob1.y"
              {}
#line 2049 "y.tab.c"
    break;

  case 49:
#line 542 "prob1.y"
                    { 
                                  // printf("%s\n",$2);
                                bool check1 = typecheckStruct((yyvsp[-1].string),(yyvsp[0].string));
                                bool check2 = redeclarationStruct((yyvsp[-1].string),(yyvsp[0].string));
                                if(check1)
                                {
                                  printf("error : conflicting types for '%s'\n",(yyvsp[0].string));
                                }
                                else if(check2)
                                {
                                  printf("error : redeclaration of '%s'\n",(yyvsp[0].string));
                                }
                                else
                                {
                                  strcpy(variable[var_idx].type,(yyvsp[-1].string));
                                  strcpy(variable[var_idx].vname,(yyvsp[0].string));
                                  if(!strcmp((yyvsp[-1].string),"int"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp((yyvsp[-1].string),"float"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp((yyvsp[-1].string),"char"))
                                  {
                                    offset*=1;
                                  }
                                  else if(!strcmp((yyvsp[-1].string),"pointer"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp((yyvsp[-1].string),"struct"))
                                  {
                                    offset*=1;
                                  } 
                                  // printf("%d ",base_address);
                                  // printf("0x%04x ", base_address);
                                  variable[var_idx].addr = base_address;
                                  int cur_size = offset;
                                  variable[var_idx++].size = offset;
                                  base_address+=offset;
                                  offset = 1;
                                  // strcpy(struct_variable[struct_var_idx].vname,variable[var_idx-1].vname);
                                  // strcpy(struct_variable[struct_var_idx].type,variable[var_idx-1].type);
                                  // struct_variable[struct_var_idx].addr = variable[var_idx-1].addr;
                                  int tab_sz = struct_variable[struct_var_idx].tab_sz;
                                  struct_variable[struct_var_idx].tables[tab_sz] = (&variable[var_idx-1]);
                                  struct_variable[struct_var_idx].tab_sz++;
                                  // printf("%s ",$2);
                                  // printf("%s ",$1);
                                  // printf("%d\n",cur_size);
                                }
                                // print_table();
                              }
#line 2109 "y.tab.c"
    break;

  case 51:
#line 597 "prob1.y"
                                 {/*print_table();*/}
#line 2115 "y.tab.c"
    break;

  case 52:
#line 599 "prob1.y"
                    {offset*=atoi((yyvsp[0].string));}
#line 2121 "y.tab.c"
    break;

  case 56:
#line 603 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s + %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2130 "y.tab.c"
    break;

  case 57:
#line 607 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s - %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2139 "y.tab.c"
    break;

  case 58:
#line 611 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s ^ %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2148 "y.tab.c"
    break;

  case 59:
#line 615 "prob1.y"
                         {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s & %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                         }
#line 2157 "y.tab.c"
    break;

  case 60:
#line 619 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s | %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2166 "y.tab.c"
    break;

  case 61:
#line 623 "prob1.y"
            {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
            }
#line 2175 "y.tab.c"
    break;

  case 63:
#line 629 "prob1.y"
                            {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s * %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2184 "y.tab.c"
    break;

  case 64:
#line 633 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s / %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2193 "y.tab.c"
    break;

  case 66:
#line 639 "prob1.y"
               {
                if(missingdeclaration((yyvsp[0].string)))
                {
                   printf( "error : var '%s' is not declared in the scope\n",(yyvsp[0].string));
                }
                else
                {
                  strcpy((yyval.string),generateVariable());
                  printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
                  printf("%s = %s + 1\n",(yyval.string),(yyval.string));
                  printf("%s = %s\n",(yyvsp[0].string),(yyval.string));
                }
               }
#line 2211 "y.tab.c"
    break;

  case 67:
#line 652 "prob1.y"
               {
                if(missingdeclaration((yyvsp[-1].string)))
                {
                   printf( "error : var '%s' is not declared in the scope\n",(yyvsp[-1].string));
                }
                else
                {
                  strcpy((yyval.string),generateVariable());
                  printf("%s = %s\n",(yyval.string),(yyvsp[-1].string));
                  printf("%s = %s + 1\n",(yyval.string),(yyval.string));
                  printf("%s = %s\n",(yyvsp[-1].string),(yyval.string));
                }
               }
#line 2229 "y.tab.c"
    break;

  case 68:
#line 665 "prob1.y"
               {
                if(missingdeclaration((yyvsp[0].string)))
                {
                   printf( "error : var '%s' is not declared in the scope\n",(yyvsp[0].string));
                }
                else
                {
                  strcpy((yyval.string),generateVariable());
                  printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
                  printf("%s = %s - 1\n",(yyval.string),(yyval.string));
                  printf("%s = %s\n",(yyvsp[0].string),(yyval.string));
                }
               }
#line 2247 "y.tab.c"
    break;

  case 69:
#line 678 "prob1.y"
               {
                if(missingdeclaration((yyvsp[-1].string)))
                {
                   printf( "error : var '%s' is not declared in the scope\n",(yyvsp[-1].string));
                }
                else
                {
                  strcpy((yyval.string),generateVariable());
                  printf("%s = %s\n",(yyval.string),(yyvsp[-1].string));
                  printf("%s = %s - 1\n",(yyval.string),(yyval.string));
                  printf("%s = %s\n",(yyvsp[-1].string),(yyval.string));
                }
               }
#line 2265 "y.tab.c"
    break;

  case 70:
#line 692 "prob1.y"
          {
            strcpy((yyval.string),generateVariable());
            printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
          }
#line 2274 "y.tab.c"
    break;

  case 71:
#line 696 "prob1.y"
         {
            if(missingdeclaration((yyvsp[0].string)))
            {
                printf( "error : var '%s' is not declared in the scope\n",(yyvsp[0].string));
            }
            else
            {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
            }
         }
#line 2290 "y.tab.c"
    break;

  case 72:
#line 707 "prob1.y"
           {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
           }
#line 2299 "y.tab.c"
    break;

  case 73:
#line 711 "prob1.y"
            {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
            }
#line 2308 "y.tab.c"
    break;

  case 74:
#line 716 "prob1.y"
         {strcpy((yyval.string),(yyvsp[0].string));}
#line 2314 "y.tab.c"
    break;

  case 75:
#line 717 "prob1.y"
          {strcpy((yyval.string),(yyvsp[0].string));}
#line 2320 "y.tab.c"
    break;

  case 76:
#line 718 "prob1.y"
          {strcpy((yyval.string),(yyvsp[0].string));}
#line 2326 "y.tab.c"
    break;

  case 77:
#line 719 "prob1.y"
           {strcpy((yyval.string),(yyvsp[0].string));}
#line 2332 "y.tab.c"
    break;

  case 78:
#line 720 "prob1.y"
           {strcpy((yyval.string),(yyvsp[0].string));}
#line 2338 "y.tab.c"
    break;

  case 79:
#line 721 "prob1.y"
           {strcpy((yyval.string),(yyvsp[0].string));}
#line 2344 "y.tab.c"
    break;

  case 80:
#line 722 "prob1.y"
         {strcpy((yyval.string),(yyvsp[0].string));}
#line 2350 "y.tab.c"
    break;

  case 81:
#line 723 "prob1.y"
         {strcpy((yyval.string),(yyvsp[0].string));}
#line 2356 "y.tab.c"
    break;

  case 82:
#line 725 "prob1.y"
             {strcpy((yyval.string),(yyvsp[0].string));}
#line 2362 "y.tab.c"
    break;


#line 2366 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 727 "prob1.y"


void insert(struct Node* entry)
{
  int cur_size = Table_Stack[table_idx-1]->size;
  // printf("cur_size : %d\n",cur_size);
  Table_Stack[table_idx-1]->tables[cur_size] = entry;
  Table_Stack[table_idx-1]->size = Table_Stack[table_idx-1]->size + 1;
  // printf("cur_size : %d\n",Table_Stack[table_idx-1]->size);
}

void insert_struct(struct SNode* entry)
{
  int cur_size = Table_Stack[table_idx-1]->struct_table_size;
  // printf("cur_size : %d\n",cur_size);
  Table_Stack[table_idx-1]->struct_tables[cur_size] = entry;
  Table_Stack[table_idx-1]->struct_table_size = Table_Stack[table_idx-1]->struct_table_size + 1;
  printf("cur_size : %d\n",Table_Stack[table_idx-1]->struct_table_size);
}

void print_table()
{
  printf(" ------------------------------------------------ \n");
  printf("|          CURRENT SYMBOL TABLE                  |\n");
  printf("| ---------------------------------------------- |\n");
  printf("| var_name      type            address   size   |\n");
  int sz = Table_Stack[table_idx-1]->size;
  for(int i=0;i<sz;i++)
  { 
    printf("| ");
    printf("%s\t\t",Table_Stack[table_idx-1]->tables[i]->vname);
    printf("%s\t\t",Table_Stack[table_idx-1]->tables[i]->type);
    printf("%d\t  ",Table_Stack[table_idx-1]->tables[i]->addr);
    printf("%d\t |\n",Table_Stack[table_idx-1]->tables[i]->size);
  }
  printf("\n| struct_name   type            address   size   |\n");
  sz = Table_Stack[table_idx-1]->struct_table_size;
  for(int i=0;i<sz;i++)
  { 
    printf("| ");
    printf("%s\t\t",Table_Stack[table_idx-1]->struct_tables[i]->vname);
    printf("%s\t\t",Table_Stack[table_idx-1]->struct_tables[i]->type);
    printf("%d\t  ",Table_Stack[table_idx-1]->struct_tables[i]->addr);
    printf("%d\t |\n",Table_Stack[table_idx-1]->struct_tables[i]->size);
  }
  printf(" ------------------------------------------------ \n");
}

//---------------- STRUCT CHECKING -------------------------
bool typecheckStruct(char* type,char* data)
{
      int i = struct_var_idx;
      int inner_size = struct_variable[i].tab_sz;
      for(int j=0;j<inner_size;j++)
      {
        if(strcmp(struct_variable[i].tables[j]->type,type) && (!strcmp(struct_variable[i].tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
    return false;
}

bool redeclarationStruct(char* type,char* data)
{
      int i = struct_var_idx;
      int inner_size = struct_variable[i].tab_sz;
      for(int j=0;j<inner_size;j++)
      {
        if((!strcmp(struct_variable[i].tables[j]->type,type)) && (!strcmp(struct_variable[i].tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
      return false;
}

bool missingdeclarationStruct(char* data)
{
      int i = struct_var_idx;
      int inner_size = struct_variable[i].tab_sz;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(struct_variable[i].tables[j]->vname,data))
        {
          return false;
        }
      }
    return error_status = true;
}

//----------------------------------------------------------

bool typecheck(char* type,char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if(strcmp(Table_Stack[i]->tables[j]->type,type) && (!strcmp(Table_Stack[i]->tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
      inner_size = Table_Stack[i]->struct_table_size;
      for(int j=0;j<inner_size;j++)
      {
        if(strcmp(Table_Stack[i]->struct_tables[j]->type,type) && (!strcmp(Table_Stack[i]->struct_tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
    }
    return false;
}

bool redeclaration(char* type,char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if((!strcmp(Table_Stack[i]->tables[j]->type,type)) && (!strcmp(Table_Stack[i]->tables[j]->vname,data)))
        {
          // printf("1. %s\n",Table_Stack[i]->tables[j]->type);
          // printf("2. %s\n",type);
          // printf("3. %s\n",Table_Stack[i]->tables[j]->vname);
          // printf("4. %s\n",data);
          return error_status = true;
        }
      }
      inner_size = Table_Stack[i]->struct_table_size;
      for(int j=0;j<inner_size;j++)
      {
        if((!strcmp(Table_Stack[i]->struct_tables[j]->type,type)) && (!strcmp(Table_Stack[i]->struct_tables[j]->vname,data)))
        {
          printf("128938912389123\n");
          return error_status = true;
        }
      }
    }
    return false;
}

bool missingdeclaration(char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(Table_Stack[i]->tables[j]->vname,data))
        {
          return false;
        }
      }
      inner_size = Table_Stack[i]->struct_table_size;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(Table_Stack[i]->struct_tables[j]->vname,data))
        {
          return false;
        }
      }
    }
    return error_status = true;
}

void init()
{
    stack_node[table_idx].size = 0;
    Table_Stack[table_idx] = (&stack_node[table_idx]);
    table_idx++;
}

char* generateVariable()
{
    char *temp=(char *)malloc(sizeof(2*10));
    sprintf(temp,"t%d",variable_index);
    variable_index++;
    return temp;
}

char* generateLabel()
{
    char *temp=(char *)malloc(sizeof(2*10));
    sprintf(temp,"L%d",label_index);
    label_index++;
    return temp;
}

char* popout() {
    
    char data[50];
    strcpy(data,outstack[topout-1]);
    topout = topout - 1;   
    return data;
}

char* popin() {
    
    char data[50];
    strcpy(data,instack[topin-1]);
    topin = topin - 1;   
    return data;
}

void pushin(char* data) {

    strcpy(instack[topin++],data);

}

void pushout(char* data) {

    strcpy(outstack[topout++],data);

}

int yyerror()
{
  printf("\n\nSyntax Error!\n");
  return 0;
}

extern FILE *yyin;

int main(int argc,char* argv[])
{
  if(argc > 1)
  {
    FILE *fp = fopen(argv[1],"r");
    if(fp)
      yyin = fp;
  }
  yyparse();
  return 0;
}
