%{
	FILE *fp;
%}

NUMBER				[0-9]+
HEADER				"#include"[ \t]*<[^>]*>
BRACKET				[{}()\[\]]
SPACE               [ \t\n]+
FORMAT_SPECIFIER    [%][a-zA-Z]
COMMA				[,]
QUOTE				[\"\']
TERMINATOR			[;]
KEYWORD				"int"|"float"|"char"|"void"|"if"|"else"|"for"|"while"|"do"|"printf"|"scanf"|"main"
IDENTIFIER			[a-zA-Z]+[0-9a-zA-Z]*
OPERATOR			[-+*/%=]
COMPARATOR			"=="|"!="|"<="|">="|"<"|">"

%%
{NUMBER}            printf("\n%s \t\t\tNumber", yytext);
{HEADER}            printf("\n%s \tHeader", yytext);
{KEYWORD}           printf("\n%s \t\t\tKeyword", yytext);
{IDENTIFIER}        printf("\n%s \t\t\tIdentifier", yytext);
{OPERATOR}          printf("\n%s \t\t\tOperator", yytext);
{COMPARATOR}        printf("\n%s \t\t\tComparator", yytext);
{BRACKET}           printf("\n%s \t\t\tBracket", yytext);
{TERMINATOR}        printf("\n%s \t\t\tTerminator", yytext);
{QUOTE}             printf("\n%s \t\t\tQuote", yytext);
{FORMAT_SPECIFIER}  printf("\n%s \t\t\tFormat Specifier", yytext);
{COMMA}             printf("\n%s \t\t\tComma", yytext);
{SPACE}				;
.					;
%%

int yywrap()
{
    return 1;
}

void main()
{
	fp = fopen("input.c", "r");
	if (fp != NULL)
	{
		yyin = fp;
		yylex();
	}
	else
		printf("File not found!");

    printf("\n\n");
}