%{
#include <stdio.h>
void yyerror();
int yylex();
int check = 0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
E : E'+'E | E'-'E | E'*'E | E'/'E | E'%'E | '('E')' | NUMBER;
%%

void yyerror()
{
    printf("\nInvalid Expression!\n\n");
    check = 1;
}

void main()
{
    printf("\nEnter Expression: ");
    yyparse();
    if(check == 0)
        printf("\nValid Expression!\n\n");
}
