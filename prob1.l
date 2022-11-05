%{
  #ifdef BISON
  #include "prob.tab.h"
  #else
  #include "y.tab.h"
  #endif
%}

alpha [a-zA-Z]
digit [0-9]
num [-]?[0-9]+
id {alpha}|({alpha}|{digit})+

%%

"while" {strcpy(yylval.string,yytext);return WHILE;}
"if" {strcpy(yylval.string,yytext);return IF;}
"else" {strcpy(yylval.string,yytext);return ELSE;}
"true" {strcpy(yylval.string,yytext);return TRUE;}
"false" {strcpy(yylval.string,yytext);return FALSE;}
"struct" {strcpy(yylval.string,yytext);return STRUCT;}
"int" {strcpy(yylval.string,yytext);return INT;}
"float" {strcpy(yylval.string,yytext);return FLOAT;}
"char" {strcpy(yylval.string,yytext);return CHAR;}
"==" {strcpy(yylval.string,yytext);return EQ;}
"!=" {strcpy(yylval.string,yytext);return NEQ;}
"||" {strcpy(yylval.string,yytext);return LOR;}
"&&" {strcpy(yylval.string,yytext);return LAND;}
"<=" {strcpy(yylval.string,yytext);return LTEQ;}
">=" {strcpy(yylval.string,yytext);return GTEQ;}
"<" {strcpy(yylval.string,yytext);return LT;}
">" {strcpy(yylval.string,yytext);return GT;}
"[" {strcpy(yylval.string,yytext);return ARROP;}
"]" {strcpy(yylval.string,yytext);return ARRCL;}
"{" {strcpy(yylval.string,yytext);return CRLOP;}
"}" {strcpy(yylval.string,yytext);return CRLCL;}
"^" {strcpy(yylval.string,yytext);return XOR;}
"|" {strcpy(yylval.string,yytext);return BOR;}
"&" {strcpy(yylval.string,yytext);return BAND;}
"*" {strcpy(yylval.string,yytext);return POINTER;}

"=" {strcpy(yylval.string,yytext);return AEQ;}

"++" {strcpy(yylval.string,yytext);return INC;}
"--" {strcpy(yylval.string,yytext);return DEC;}

{num} {strcpy(yylval.string,yytext);return NUM;}

{id} {strcpy(yylval.string,yytext);return ID;}

[ \t] {}

. {return yytext[0];}

%%
