%{
#include <stdio.h>
int yylex();
void yyerror(const char* message);
%}

%union { int num; }

%token <num> NUMBER
%type <num> E

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
Result: E { printf("\nResult: %d\n\n", $1); }
E   : E'+'E     { $$ = $1 + $3; }
    | E'-'E     { $$ = $1 - $3; }
    | E'*'E     { $$ = $1 * $3; }
    | E'/'E     { if ($3 == 0) yyerror("Divide by Zero Error!"); else $$ = $1 / $3; }
    | '('E')'   { $$ = $2; }
    | NUMBER    { $$ = $1; }
    ;
%%

void yyerror(const char* s) { printf("\n%s\n\n", s); }

void main()
{
    printf("\nEnter an expression: ");
    yyparse();
}