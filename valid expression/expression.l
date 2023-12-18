%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}

NUMBER      [0-9]+
OPERATOR    [-+*/%]

%% 
{NUMBER}    { yylval = atoi(yytext); return NUMBER; }
{OPERATOR}  return yytext[0];
[\n]        return 0;
[\t ]       ; 
.           return yytext[0]; 
%% 

int yywrap() { return 1; }