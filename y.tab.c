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
    char cur_type[50];
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
  int computation_type = -1;
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
  bool update_cur_type(char* type,char* data);
  void print_table();
  void reset_types();
  int max(int a,int b)
  {
    if(a>=b)
    {
      return a;
    }
    else
    {
      return b;
    }
  }

#line 150 "y.tab.c"

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
    LNOT = 265,
    LTEQ = 266,
    GTEQ = 267,
    LT = 268,
    GT = 269,
    XOR = 270,
    BOR = 271,
    BAND = 272,
    AEQ = 273,
    INC = 274,
    DEC = 275,
    NUM = 276,
    ID = 277,
    IF = 278,
    ELSE = 279,
    STRUCT = 280,
    INT = 281,
    FLOAT = 282,
    LONG = 283,
    POINTER = 284,
    CHAR = 285,
    ARROP = 286,
    ARRCL = 287,
    CRLOP = 288,
    CRLCL = 289,
    ROP = 290,
    RCL = 291,
    UMINUS = 292
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
#define LNOT 265
#define LTEQ 266
#define GTEQ 267
#define LT 268
#define GT 269
#define XOR 270
#define BOR 271
#define BAND 272
#define AEQ 273
#define INC 274
#define DEC 275
#define NUM 276
#define ID 277
#define IF 278
#define ELSE 279
#define STRUCT 280
#define INT 281
#define FLOAT 282
#define LONG 283
#define POINTER 284
#define CHAR 285
#define ARROP 286
#define ARRCL 287
#define CRLOP 288
#define CRLCL 289
#define ROP 290
#define RCL 291
#define UMINUS 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "prob1.y"

	char string[100];

#line 280 "y.tab.c"

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
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


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
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    43,    38,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
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
      35,    36,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   159,   174,   174,   176,   176,   178,   178,
     180,   182,   182,   185,   184,   212,   212,   218,   224,   232,
     246,   260,   274,   276,   290,   304,   318,   332,   335,   349,
     368,   369,   372,   380,   388,   370,   403,   426,   430,   430,
     431,   482,   532,   583,   635,   636,   638,   638,   638,   638,
     640,   643,   645,   645,   656,   656,   658,   658,   702,   704,
     706,   706,   761,   763,   763,   765,   765,   768,   805,   809,
     813,   817,   821,   826,   828,   832,   836,   838,   851,   864,
     877,   891,   895,   908,   922,   926,   931,   933,   934,   935,
     936,   937,   938,   939,   940,   942
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "TRUE", "FALSE", "EQ", "NEQ",
  "LOR", "LAND", "LNOT", "LTEQ", "GTEQ", "LT", "GT", "XOR", "BOR", "BAND",
  "AEQ", "INC", "DEC", "NUM", "ID", "IF", "ELSE", "STRUCT", "INT", "FLOAT",
  "LONG", "POINTER", "CHAR", "ARROP", "ARRCL", "CRLOP", "CRLCL", "ROP",
  "RCL", "'+'", "'-'", "'/'", "UMINUS", "'!'", "';'", "','", "$accept",
  "start", "$@1", "slst", "BODY", "E", "DUMMY", "CONTROL", "E1", "$@2",
  "E2", "$@3", "COND", "COND0", "COND1", "COND2", "STMT", "$@4", "$@5",
  "$@6", "VAR_DEC", "$@7", "REP", "TYPE", "B", "NEXT", "ARRM", "$@8",
  "PTRDEC", "STRUCTDEC", "$@9", "OPTID", "INSSTR", "$@10", "C", "$@11",
  "D", "AFTER", "LATER", "PRE", "ANY", "OPTYPE", "CMP", "ASSIGN", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    43,    45,    47,
     292,    33,    59,    44
};
# endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -73,    28,   104,   -73,     8,    13,    80,    16,    33,   -73,
     -73,   -73,   -73,   -73,    22,    21,   -73,    31,   -73,    49,
      44,    52,   -73,   -73,   -73,   -73,   -73,    -1,     1,   -73,
     -73,    56,   -73,   -73,   -73,   -73,   -73,    90,    49,   -73,
     -73,   -73,   -73,   -73,   -73,    37,    62,    59,    14,   -73,
     -73,    98,     1,   115,   -73,    99,   140,   -73,   132,    62,
       1,    91,    78,    79,   115,   -73,   -73,   106,    -1,    -1,
      -1,    -1,    -1,   -73,     5,     5,   -73,   -73,   132,    -1,
     111,     1,     1,    11,    11,    11,    11,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,    -1,    90,   114,   113,   -73,
     125,   129,    90,     5,   -73,   -73,   -73,   -73,    87,    87,
     -73,   -73,   -73,    68,   128,   -73,   -73,   -73,   -73,   -73,
     -73,    68,   -73,   141,   131,   -73,   144,   -73,   115,   -73,
      91,   120,   -73,   -73,   -73,   -73,     5,   133,    62,    91,
     134,   -73,   -73,   -73,   135,   129,   -73,   146,   -73,   -73,
     138,   -73,    91,   139,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    10,     1,     0,     0,     0,     0,     0,    46,
      47,    49,    48,     3,     5,     0,     8,     0,    38,    44,
       0,     0,    77,    79,    95,    78,    80,     0,     0,    56,
       4,     0,    15,     9,    11,    12,    30,     0,    55,    45,
      31,    37,    84,    85,    81,    82,     0,     0,    73,    72,
      76,     0,     0,    82,    32,    17,    22,    27,    18,    62,
       0,    10,    50,    39,    42,    51,    54,     0,     0,     0,
       0,     0,     0,    36,     0,     0,    83,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     6,
       0,     0,     0,     0,    86,    69,    71,    70,    67,    68,
      82,    74,    75,    29,     0,    19,    20,    25,    26,    23,
      24,    28,    60,    59,     0,    16,     0,    53,    40,    43,
      10,     0,    58,    57,    13,    63,     0,     0,    62,    10,
       0,    41,    33,    61,     0,    65,    64,     0,    14,    66,
       0,    34,    10,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,    15,   -72,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   108,   -44,    72,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -45,   -73,   -15,   -73,   -73,   136,   -73,
     -73,   -73,    34,   -73,    30,   -73,   -73,     0,    61,    -2,
     -21,   -73,   -73,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    99,   100,    14,    15,    33,    34,   139,
      35,    61,    54,    55,    56,    57,    16,    80,   147,   152,
      17,    37,    63,    18,    19,    64,    65,   101,    39,    20,
      59,   133,    97,   131,   127,   140,   146,    47,    48,    49,
      50,    51,    95,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    67,    79,    42,    43,    42,    43,    58,    77,    42,
      43,    52,    21,   103,    96,    42,    43,    13,     4,     5,
      44,    45,    44,    53,    31,   -10,    44,   110,     3,    30,
      22,    78,    44,    53,    46,    23,    46,   115,   116,    58,
      46,     4,     5,    74,     6,     7,    46,     8,     9,    10,
      11,    28,    12,    75,    32,   -10,    25,    26,   137,    21,
      78,    78,    78,    78,    78,    78,    29,   144,   105,   106,
     107,   108,   109,    36,    68,    69,    70,   136,    38,   113,
     153,   122,   129,    68,    69,    70,    40,   128,     9,    10,
      11,    60,    12,    96,    41,   121,    71,    72,    24,    25,
      26,    73,    68,    69,    70,    71,    72,    81,    82,   -52,
       4,     5,    62,     6,     7,   141,     8,     9,    10,    11,
      76,    12,   102,     4,     5,    -7,     6,     7,    21,     8,
       9,    10,    11,    24,    12,   111,   112,    21,    87,    88,
      89,    90,   104,    91,    92,    93,    94,   114,   123,   124,
      21,    83,    84,    85,    86,   117,   118,   119,   120,   125,
     126,   130,   138,   132,   134,   135,   145,   142,    98,   148,
     150,   151,   143,   154,    66,   149
};

static const yytype_uint8 yycheck[] =
{
       2,    46,    53,     4,     5,     4,     5,    28,    52,     4,
       5,    10,    14,    64,    59,     4,     5,     2,    19,    20,
      21,    22,    21,    22,     3,     3,    21,    22,     0,    14,
      22,    52,    21,    22,    35,    22,    35,    81,    82,    60,
      35,    19,    20,    29,    22,    23,    35,    25,    26,    27,
      28,    35,    30,    39,    33,    33,    19,    20,   130,    61,
      81,    82,    83,    84,    85,    86,    33,   139,    68,    69,
      70,    71,    72,    42,    15,    16,    17,   128,    29,    79,
     152,    96,   103,    15,    16,    17,    42,   102,    26,    27,
      28,    35,    30,   138,    42,    95,    37,    38,    18,    19,
      20,    42,    15,    16,    17,    37,    38,     8,     9,    31,
      19,    20,    22,    22,    23,   136,    25,    26,    27,    28,
      22,    30,    43,    19,    20,    34,    22,    23,   130,    25,
      26,    27,    28,    18,    30,    74,    75,   139,     6,     7,
       8,     9,    36,    11,    12,    13,    14,    36,    34,    36,
     152,    11,    12,    13,    14,    83,    84,    85,    86,    34,
      31,    33,    42,    22,    33,    21,    32,    34,    60,    34,
      24,    33,   138,    34,    38,   145
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,    19,    20,    22,    23,    25,    26,
      27,    28,    30,    47,    49,    50,    60,    64,    67,    68,
      73,    83,    22,    22,    18,    19,    20,    87,    35,    33,
      47,     3,    33,    51,    52,    54,    42,    65,    29,    72,
      42,    42,     4,     5,    21,    22,    35,    81,    82,    83,
      84,    85,    10,    22,    56,    57,    58,    59,    84,    74,
      35,    55,    22,    66,    69,    70,    72,    67,    15,    16,
      17,    37,    38,    42,    29,    39,    22,    57,    84,    87,
      61,     8,     9,    11,    12,    13,    14,     6,     7,     8,
       9,    11,    12,    13,    14,    86,    67,    76,    56,    47,
      48,    71,    43,    87,    36,    81,    81,    81,    81,    81,
      22,    82,    82,    81,    36,    57,    57,    58,    58,    58,
      58,    81,    69,    34,    36,    34,    31,    78,    69,    84,
      33,    77,    22,    75,    33,    21,    87,    48,    42,    53,
      79,    84,    34,    76,    48,    32,    80,    62,    34,    78,
      24,    33,    63,    48,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    48,    48,    49,    49,
      50,    51,    51,    53,    52,    55,    54,    56,    56,    57,
      57,    57,    57,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    63,    60,    60,    60,    65,    64,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    71,    70,    72,    72,    74,    73,    75,    75,
      77,    76,    76,    79,    78,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     0,     1,     2,
       0,     1,     1,     0,     8,     0,     4,     1,     1,     3,
       3,     2,     1,     3,     3,     3,     3,     1,     3,     3,
       2,     2,     0,     0,     0,    14,     4,     2,     0,     3,
       3,     5,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     3,     2,     1,     0,     6,     1,     0,
       0,     5,     0,     0,     4,     1,     2,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     1,     2,     2,     2,
       2,     1,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 159 "prob1.y"
        {
          init();
        }
#line 1574 "y.tab.c"
    break;

  case 3:
#line 162 "prob1.y"
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
#line 1589 "y.tab.c"
    break;

  case 7:
#line 176 "prob1.y"
              {}
#line 1595 "y.tab.c"
    break;

  case 10:
#line 180 "prob1.y"
        {char topp[50]; strcpy(topp,generateLabel()); pushout(topp); printf("%s :\n",topp);}
#line 1601 "y.tab.c"
    break;

  case 13:
#line 185 "prob1.y"
            {
              // print_table(Table_Stack[table_idx-1]);
              init();
              // print_table(Table_Stack[table_idx-1]);
              char topp[50];
              strcpy(topp,instack[topin-1]);
              topin=topin-1;
              printf("%s :\n",topp);
          }
#line 1615 "y.tab.c"
    break;

  case 14:
#line 197 "prob1.y"
            {
              char topp[50];
              strcpy(topp,outstack[topout-2]);
              printf("goto %s\n",topp);
              strcpy(topp,outstack[topout-1]);
              topout=topout-2;
              printf("%s :",topp);
              table_idx--;
       }
#line 1629 "y.tab.c"
    break;

  case 15:
#line 212 "prob1.y"
            {
            init();
          }
#line 1637 "y.tab.c"
    break;

  case 16:
#line 216 "prob1.y"
            {table_idx--;}
#line 1643 "y.tab.c"
    break;

  case 17:
#line 218 "prob1.y"
             {
                strcpy((yyval.string),generateLabel()); printf("if %s!=0 goto %s\n",(yyvsp[0].string),(yyval.string));
                pushin((yyval.string));
                strcpy((yyval.string),generateLabel()); printf("goto %s\n",(yyval.string));
                pushout((yyval.string));
             }
#line 1654 "y.tab.c"
    break;

  case 18:
#line 224 "prob1.y"
            {
                    strcpy((yyval.string),generateLabel()); printf("if %s != 0 goto %s\n",(yyvsp[0].string),(yyval.string));
                    pushin((yyval.string));
                    strcpy((yyval.string),generateLabel()); printf("goto %s\n",(yyval.string));
                    pushout((yyval.string));
            }
#line 1665 "y.tab.c"
    break;

  case 19:
#line 232 "prob1.y"
                        {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s || %s goto %s\n",(yyvsp[-2].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1684 "y.tab.c"
    break;

  case 20:
#line 246 "prob1.y"
                         {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s && %s goto %s\n",(yyvsp[-2].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1703 "y.tab.c"
    break;

  case 21:
#line 260 "prob1.y"
                   {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if !%s goto %s\n",(yyvsp[-1].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1722 "y.tab.c"
    break;

  case 23:
#line 276 "prob1.y"
                        {    
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s < %s goto %s\n",(yyvsp[-2].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1741 "y.tab.c"
    break;

  case 24:
#line 290 "prob1.y"
                       {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s > %s goto %s\n",(yyvsp[-2].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1760 "y.tab.c"
    break;

  case 25:
#line 304 "prob1.y"
                         {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s <= %s goto %s\n",(yyvsp[-2].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1779 "y.tab.c"
    break;

  case 26:
#line 318 "prob1.y"
                        {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s >= %s goto %s\n",(yyvsp[-2].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                     }
#line 1798 "y.tab.c"
    break;

  case 28:
#line 335 "prob1.y"
                      {
                        strcpy((yyval.string),generateVariable());
                        char temp1[50];
                        char temp2[50];
                        char temp3[50];
                        strcpy(temp1,generateLabel());
                        strcpy(temp2,generateLabel());
                        strcpy(temp3,generateLabel());
                        printf("if %s %s %s goto %s\n",(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string),temp1);
                        printf("goto %s\n",temp2);
                        printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                        printf("%s :\n%s = 0\n",temp2,(yyval.string));
                        printf("%s :\n",temp3);
                      }
#line 1817 "y.tab.c"
    break;

  case 29:
#line 349 "prob1.y"
                        {
                        if(missingdeclaration((yyvsp[-2].string)))
                        {
                          strcpy((yyval.string),generateVariable());
                          char temp1[50];
                          char temp2[50];
                          char temp3[50];
                          strcpy(temp1,generateLabel());
                          strcpy(temp2,generateLabel());
                          strcpy(temp3,generateLabel());
                          printf("if %s %s %s goto %s\n",(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string),temp1);
                          printf("goto %s\n",temp2);
                          printf("%s :\n%s = 1\ngoto %s:\n",temp1,(yyval.string),temp3);
                          printf("%s :\n%s = 0\n",temp2,(yyval.string));
                          printf("%s :\n",temp3);
                        }
                      }
#line 1839 "y.tab.c"
    break;

  case 32:
#line 372 "prob1.y"
              {
                init();
                char topp[50];
                strcpy(topp,instack[topin-1]);
                topin=topin-1;
                printf("%s :\n",topp);
              }
#line 1851 "y.tab.c"
    break;

  case 33:
#line 380 "prob1.y"
                        {
                      char topp[50];
                      strcpy(topp,generateLabel());
                      pushout(topp);
                      printf("goto %s\n",topp);
                    }
#line 1862 "y.tab.c"
    break;

  case 34:
#line 388 "prob1.y"
                      {
                      char topp[50];
                      strcpy(topp,outstack[topout-2]);
                      strcpy(outstack[topout-2],outstack[topout-1]);
                      topout-=1;
                      printf("%s :\n",topp);
                    }
#line 1874 "y.tab.c"
    break;

  case 35:
#line 396 "prob1.y"
                    {
                      char topp[50];
                      strcpy(topp,outstack[topout-1]);
                      topout=topout-1;
                      printf("%s :\n",topp);
                      table_idx--;
                    }
#line 1886 "y.tab.c"
    break;

  case 36:
#line 403 "prob1.y"
                           {

                              // print_table();                        
                              if(missingdeclaration((yyvsp[-3].string)))
                              {
                                printf( "error : var '%s' is not declared in the scope\n",(yyvsp[-3].string));
                              }
                              else
                              {
                                int id_type = get_cur_type((yyvsp[-3].string));
                                if(id_type < computation_type)
                                {
                                  printf( "error : the assignment for '%s' is not vaild\n",(yyvsp[-3].string));
                                }
                                else
                                {
                                  printf("%s = %s",(yyval.string),(yyvsp[-1].string));
                                }
                              }     
                              computation_type = -1;
                              reset_types();
                              // print_table();
                           }
#line 1914 "y.tab.c"
    break;

  case 38:
#line 430 "prob1.y"
               {strcpy(temp_store,(yyvsp[0].string));}
#line 1920 "y.tab.c"
    break;

  case 40:
#line 431 "prob1.y"
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
                                  strcpy(variable[var_idx].cur_type,temp_store);
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
#line 1976 "y.tab.c"
    break;

  case 41:
#line 482 "prob1.y"
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
                                    strcpy(variable[var_idx].cur_type,temp_store);
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
#line 2031 "y.tab.c"
    break;

  case 42:
#line 532 "prob1.y"
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
                                  strcpy(variable[var_idx].cur_type,temp_store);
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
#line 2087 "y.tab.c"
    break;

  case 43:
#line 583 "prob1.y"
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
                                    strcpy(variable[var_idx].cur_type,temp_store);
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
#line 2142 "y.tab.c"
    break;

  case 44:
#line 635 "prob1.y"
            {strcpy((yyval.string),(yyvsp[0].string));}
#line 2148 "y.tab.c"
    break;

  case 45:
#line 636 "prob1.y"
                   {strcpy((yyval.string),"pointer");}
#line 2154 "y.tab.c"
    break;

  case 46:
#line 638 "prob1.y"
              {strcpy((yyval.string),"int");}
#line 2160 "y.tab.c"
    break;

  case 47:
#line 638 "prob1.y"
                                         {strcpy((yyval.string),"float");}
#line 2166 "y.tab.c"
    break;

  case 48:
#line 638 "prob1.y"
                                                                     {strcpy((yyval.string),"char");}
#line 2172 "y.tab.c"
    break;

  case 49:
#line 638 "prob1.y"
                                                                                                 {strcpy((yyval.string),"long");}
#line 2178 "y.tab.c"
    break;

  case 50:
#line 640 "prob1.y"
             {
                strcpy((yyval.string),(yyvsp[0].string));
             }
#line 2186 "y.tab.c"
    break;

  case 52:
#line 645 "prob1.y"
             {offset = 1;}
#line 2192 "y.tab.c"
    break;

  case 53:
#line 645 "prob1.y"
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
#line 2207 "y.tab.c"
    break;

  case 56:
#line 658 "prob1.y"
                          {
                          struct_variable[struct_var_idx].tab_sz = 0;
                          struct_offset = base_address;
                          init();
                        }
#line 2217 "y.tab.c"
    break;

  case 57:
#line 667 "prob1.y"
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
#line 2255 "y.tab.c"
    break;

  case 58:
#line 702 "prob1.y"
           {
              strcpy((yyval.string),(yyvsp[0].string));
           }
#line 2263 "y.tab.c"
    break;

  case 59:
#line 704 "prob1.y"
              {}
#line 2269 "y.tab.c"
    break;

  case 60:
#line 706 "prob1.y"
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
#line 2329 "y.tab.c"
    break;

  case 62:
#line 761 "prob1.y"
                                 {/*print_table();*/}
#line 2335 "y.tab.c"
    break;

  case 63:
#line 763 "prob1.y"
                    {offset*=atoi((yyvsp[0].string));}
#line 2341 "y.tab.c"
    break;

  case 67:
#line 768 "prob1.y"
                        {
                          // int a1 = get_cur_type($1);
                          // int a2 = get_cur_type($3);
                          // if( a1 >= a2)
                          // {
                          //   if(a1 == 1)
                          //   {
                          //     update_cur_type("int",$3);
                          //   }
                          //   if(a1 == 2)
                          //   {
                          //     update_cur_type("float",$3);
                          //   }  
                          //   if(a1 == 3)
                          //   {
                          //     update_cur_type("long",$3);
                          //   }                            
                          // }
                          // else
                          // {
                          //   if(a2 == 1)
                          //   {
                          //     update_cur_type("int",$3);
                          //   }
                          //   if(a2 == 2)
                          //   {
                          //     update_cur_type("float",$3);
                          //   }  
                          //   if(a2 == 3)
                          //   {
                          //     update_cur_type("long",$3);
                          //   }  
                          // }
                          // print_table1();
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s + %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2383 "y.tab.c"
    break;

  case 68:
#line 805 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s - %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2392 "y.tab.c"
    break;

  case 69:
#line 809 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s ^ %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2401 "y.tab.c"
    break;

  case 70:
#line 813 "prob1.y"
                         {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s & %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                         }
#line 2410 "y.tab.c"
    break;

  case 71:
#line 817 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s | %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2419 "y.tab.c"
    break;

  case 72:
#line 821 "prob1.y"
            {

              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
            }
#line 2429 "y.tab.c"
    break;

  case 74:
#line 828 "prob1.y"
                            {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s * %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2438 "y.tab.c"
    break;

  case 75:
#line 832 "prob1.y"
                        {
                          strcpy((yyval.string),generateVariable());
                          printf("%s = %s / %s\n",(yyval.string),(yyvsp[-2].string),(yyvsp[0].string));
                        }
#line 2447 "y.tab.c"
    break;

  case 77:
#line 838 "prob1.y"
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
#line 2465 "y.tab.c"
    break;

  case 78:
#line 851 "prob1.y"
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
#line 2483 "y.tab.c"
    break;

  case 79:
#line 864 "prob1.y"
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
#line 2501 "y.tab.c"
    break;

  case 80:
#line 877 "prob1.y"
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
#line 2519 "y.tab.c"
    break;

  case 81:
#line 891 "prob1.y"
          {
            strcpy((yyval.string),generateVariable());
            printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
          }
#line 2528 "y.tab.c"
    break;

  case 82:
#line 895 "prob1.y"
         {
            if(missingdeclaration((yyvsp[0].string)))
            {
                printf( "error : var '%s' is not declared in the scope\n",(yyvsp[0].string));
            }
            else
            {
              int a1 = get_cur_type((yyvsp[0].string));
              computation_type = max(computation_type,a1);
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
            }
         }
#line 2546 "y.tab.c"
    break;

  case 83:
#line 908 "prob1.y"
                {
            if(missingdeclaration((yyvsp[0].string)))
            {
                printf( "error : var '%s' is not declared in the scope\n",(yyvsp[0].string));
            }
            else
            {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
              update_cur_type((yyvsp[-1].string),(yyvsp[0].string));
              int a1 = get_cur_type((yyvsp[0].string));
              computation_type = max(computation_type,a1);
            }
         }
#line 2565 "y.tab.c"
    break;

  case 84:
#line 922 "prob1.y"
           {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
           }
#line 2574 "y.tab.c"
    break;

  case 85:
#line 926 "prob1.y"
            {
              strcpy((yyval.string),generateVariable());
              printf("%s = %s\n",(yyval.string),(yyvsp[0].string));
            }
#line 2583 "y.tab.c"
    break;

  case 86:
#line 931 "prob1.y"
                      {strcpy((yyval.string),(yyvsp[-1].string));}
#line 2589 "y.tab.c"
    break;

  case 87:
#line 933 "prob1.y"
         {strcpy((yyval.string),(yyvsp[0].string));}
#line 2595 "y.tab.c"
    break;

  case 88:
#line 934 "prob1.y"
          {strcpy((yyval.string),(yyvsp[0].string));}
#line 2601 "y.tab.c"
    break;

  case 89:
#line 935 "prob1.y"
          {strcpy((yyval.string),(yyvsp[0].string));}
#line 2607 "y.tab.c"
    break;

  case 90:
#line 936 "prob1.y"
           {strcpy((yyval.string),(yyvsp[0].string));}
#line 2613 "y.tab.c"
    break;

  case 91:
#line 937 "prob1.y"
           {strcpy((yyval.string),(yyvsp[0].string));}
#line 2619 "y.tab.c"
    break;

  case 92:
#line 938 "prob1.y"
           {strcpy((yyval.string),(yyvsp[0].string));}
#line 2625 "y.tab.c"
    break;

  case 93:
#line 939 "prob1.y"
         {strcpy((yyval.string),(yyvsp[0].string));}
#line 2631 "y.tab.c"
    break;

  case 94:
#line 940 "prob1.y"
         {strcpy((yyval.string),(yyvsp[0].string));}
#line 2637 "y.tab.c"
    break;

  case 95:
#line 942 "prob1.y"
             {strcpy((yyval.string),(yyvsp[0].string));}
#line 2643 "y.tab.c"
    break;


#line 2647 "y.tab.c"

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
#line 944 "prob1.y"


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

void print_table1()
{
  printf(" ----------------------------------------------------- \n");
  printf("|               CURRENT SYMBOL TABLE                  |\n");
  printf("| --------------------------------------------------- |\n");
  printf("| var_name      type    cur type      address   size  |\n");
  int sz = Table_Stack[table_idx-1]->size;
  for(int i=0;i<sz;i++)
  { 
    printf("| ");
    printf("%s\t\t",Table_Stack[table_idx-1]->tables[i]->vname);
    printf("%s\t",Table_Stack[table_idx-1]->tables[i]->type);
    printf("%s\t      ",Table_Stack[table_idx-1]->tables[i]->cur_type);
    printf("%d\t\t",Table_Stack[table_idx-1]->tables[i]->addr);
    printf("%d     |\n",Table_Stack[table_idx-1]->tables[i]->size);
  }
  printf(" ----------------------------------------------------- \n");
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
          // printf("128938912389123\n");
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

bool update_cur_type(char* type,char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(Table_Stack[i]->tables[j]->vname,data))
        {
          strcpy(Table_Stack[i]->tables[j]->cur_type,type);
          return true;
        }
      }
    }
    error_status = true;
    return false;
}

int get_cur_type(char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(Table_Stack[i]->tables[j]->vname,data))
        {
          if(!strcmp(Table_Stack[i]->tables[j]->cur_type,"int"))
          {
            return 1;
          }
          if(!strcmp(Table_Stack[i]->tables[j]->cur_type,"float"))
          {
            return 2;
          }
          if(!strcmp(Table_Stack[i]->tables[j]->cur_type,"long"))
          {
            return 3;
          }
          if(!strcmp(Table_Stack[i]->tables[j]->cur_type,"char"))
          {
            return 0;
          }
        }
      }
    }
    return -1;  
}

void reset_types()
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        strcpy(Table_Stack[i]->tables[j]->cur_type,Table_Stack[i]->tables[j]->type);
      }
    }  
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
