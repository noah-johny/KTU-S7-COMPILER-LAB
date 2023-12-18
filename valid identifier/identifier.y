%{
#include <stdio.h>
void yyerror();
int yylex();
int check = 0;
%}

%token IDENTIFIER

%%
E : IDENTIFIER;
%%

void yyerror()
{
    printf("\nInvalid Identifier!\n\n");
    check = 1;
}

void main()
{
    printf("\nEnter a valid identifier: ");
    yyparse();
    if (check == 0)
        printf("\nValid Identifier!\n\n");
}