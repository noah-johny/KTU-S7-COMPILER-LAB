#include <stdio.h>
#include <string.h>

int i = 0, j = 0, k = 0, size = 0;
char input[30], stack[30], action[30];

void reduce()
{
    strcpy(action, "REDUCE");

    for (k = 0; k < size; k++)
    {
        if (stack[k] == 'i' && stack[k + 1] == 'd')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            j++;
        }
    }

    for (k = 0; k < size; k++)
    {
        if (stack[k] == 'E' && stack[k + 1] == '+' && stack[k + 2] == 'E')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i -= 2;
        }
    }

    for (k = 0; k < size; k++)
    {
        if (stack[k] == 'E' && stack[k + 1] == '*' && stack[k + 2] == 'E')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i -= 2;
        }
    }

    for (k = 0; k < size; k++)
    {
        if (stack[k] == '(' && stack[k + 1] == 'E' && stack[k + 2] == ')')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i -= 2;
        }
    }
}

void shift()
{
    for (i = 0, j = 0; j < size; i++, j++)
    {
        strcpy(action, "SHIFT");

        if (input[j] == 'i' && input[j + 1] == 'd')
        {
            stack[i] = 'i';
            stack[i + 1] = 'd';
            stack[i + 2] = '\0';
            input[j] = ' ';
            input[j + 1] = ' ';
        }
        else
        {
            stack[i] = input[j];
            stack[i + 1] = '\0';
            input[j] = ' ';
        }
        printf("\n$%s\t%s$\t%s", stack, input, action);
        reduce();
    }
}

void display()
{
    printf("\nSTACK \t INPUT\t\tACTION");
    shift();
    reduce();
}

void main()
{
    printf("\nGrammar:\nE->E+E \nE->E*E \nE->(E) \nE->id\n");
    printf("\nEnter the input string: ");
    scanf("%s", input);

    size = strlen(input);

    display();
    printf("\n\n");
}
