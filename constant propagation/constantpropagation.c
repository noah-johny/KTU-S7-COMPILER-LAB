#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct expression
{
    char op[2], op1[5], op2[5], res[5];
    bool modified;
} exp[10];

int n;

void input()
{
    printf("\nEnter the no. of expressions: ");
    scanf("%d", &n);
    printf("\nEnter the expressions:\n[Format: Operator Operand1 Operand2 Variable]\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", exp[i].op);
        scanf("%s", exp[i].op1);
        scanf("%s", exp[i].op2);
        scanf("%s", exp[i].res);
        exp[i].modified = false;
    }
}

void change(int i, int res)
{
    char res_copy[5];
    sprintf(res_copy, "%d", res);

    for (int j = i + 1; j < n; j++)
    {
        if (strcmp(exp[i].res, exp[j].op1) == 0)
            strcpy(exp[j].op1, res_copy);
        else if (strcmp(exp[i].res, exp[j].op2) == 0)
            strcpy(exp[j].op2, res_copy);
    }
}

void constant()
{
    int op1, op2, res;
    char op;
    for (int i = 0; i < n; i++)
    {
        if ((isdigit(exp[i].op1[0]) && isdigit(exp[i].op2[0])) || strcmp(exp[i].op, "=") == 0)
        {
            op1 = atoi(exp[i].op1);
            op2 = atoi(exp[i].op2);
            op = exp[i].op[0];

            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '=':
                res = op1;
                break;
            }

            exp[i].modified = true;
            change(i, res);
        }
    }
}

void output()
{
    printf("\nOptimized Code:");
    for (int i = 0; i < n; i++)
    {
        if (!exp[i].modified)
            printf("\n%s %s %s %s", exp[i].op, exp[i].op1, exp[i].op2, exp[i].res);
    }
    printf("\n\n");
}

void main()
{
    input();
    constant();
    output();
}