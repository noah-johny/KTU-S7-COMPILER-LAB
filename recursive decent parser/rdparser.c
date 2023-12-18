#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char s[20];
int p = 0;

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
    if (s[p] == '+')
    {
        printf("Applying rule: E' -> +TE'\n");
        p++;
        T();
        EDash();
    }
    else
    {
        printf("Applying rule: E' -> e\n");
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
    if (s[p] == '*')
    {
        printf("Applying rule: T' -> *FT'\n");
        p++;
        F();
        TDash();
    }
    else
    {
        printf("Applying rule: T' -> e\n");
        return;
    }
}

void F()
{
    if (s[p] == '(')
    {
        printf("Applying rule: F -> (E)\n");
        p++;
        E();
        if (s[p] == ')')
            p++;
        else
        {
            printf("\nParsing error: Missing closing parenthesis.\n\n");
            exit(0);
        }
    }
    else if (isalpha(s[p]))
    {
        printf("Applying rule: F -> id\n");
        p++;
        while (isalnum(s[p]) || s[p] == '_')
            p++;
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
    printf("\n");

    E();

    if (s[p] == '\0')
        printf("\nSuccessfully parsed.\n\n");
    else
        printf("\nParsing error: Unparsed characters remaining!\n\n");
}
