%{
#include <stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
%}

NUMBER      [0-9]+
OPERATOR    [-+*/]

%% 
{NUMBER}    { yylval.num = atoi(yytext); return NUMBER; }
{OPERATOR}  return yytext[0];
[\n]        return 0;
[\t ]       ; 
.           return yytext[0]; 
%% 

int yywrap() { return 1; }