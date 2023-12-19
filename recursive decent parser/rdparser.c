#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char s[20];
int cursor = 0;

void E();
void EDash();
void T();
void TDash();
void F();

void E()
{
    printf("Applying rule: E -> TE'\n");
    T();
    EDash();
}

void EDash()
{
    if (s[cursor] == '+')
    {
        printf("Applying rule: E' -> +TE'\n");
        cursor++;
        T();
        EDash();
    }
    else
    {
        printf("Applying rule: E' -> #\n");
        return;
    }
}

void T()
{
    printf("Applying rule: T -> FT'\n");
    F();
    TDash();
}

void TDash()
{
    if (s[cursor] == '*')
    {
        printf("Applying rule: T' -> *FT'\n");
        cursor++;
        F();
        TDash();
    }
    else
    {
        printf("Applying rule: T' -> #\n");
        return;
    }
}

void F()
{
    if (s[cursor] == '(')
    {
        printf("Applying rule: F -> (E)\n");
        cursor++;
        E();
        if (s[cursor] == ')')
            cursor++;
        else
        {
            printf("\nParsing error: Missing closing parenthesis.\n\n");
            exit(0);
        }
    }
    else if (isalpha(s[cursor]))
    {
        printf("Applying rule: F -> id\n");
        cursor++;
        while (isalnum(s[cursor]))
            cursor++;
    }
    else
    {
        printf("\nParsing error: Unexpected character encountered!\n\n");
        exit(0);
    }
}

void main()
{
    printf("\nEnter the string to be parsed: ");
    scanf("%s", s);
    printf("\n['#' denotes Epsilon]\n\n");

    E();

    if (s[cursor] == '\0')
        printf("\nSuccessfully parsed.\n\n");
    else
        printf("\nParsing error: Unparsed characters remaining!\n\n");
}
