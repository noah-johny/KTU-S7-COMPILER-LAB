#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, size = 0;
char input[30], stack[30], action[30];

void reduce()
{
    strcpy(action, "REDUCE");

    for (z = 0; z < size; z++)
    {
        if (stack[z] == 'i' && stack[z + 1] == 'd')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            j++;
        }
    }

    for (z = 0; z < size; z++)
    {
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i = i - 2;
        }
    }

    for (z = 0; z < size; z++)
    {
        if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i = i - 2;
        }
    }

    for (z = 0; z < size; z++)
    {
        if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i = i - 2;
        }
    }
}

void shift()
{
    for (k = 0, i = 0; j < size; k++, i++, j++)
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
