#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int n;
char p[20][20], f[20];
int k = 0;

void first(char item);
void follow(char item);

void first(char item)
{
    if (islower(item))
        f[k++] = item;

    for (int i = 0; i < n; i++)
    {
        if (p[i][0] == item)
        {
            if (p[i][2] == '$')
                follow(p[i][0]);
            else if (islower(p[i][2]))
                f[k++] = p[i][2];
            else
                first(p[i][2]);
        }
    }
}

void follow(char item)
{
    if (p[0][0] == item)
        f[k++] = '$';

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(p[i]); j++)
        {
            if (p[i][j] == item)
            {
                if (p[i][j + 1] != '\0')
                    first(p[i][j + 1]);
                else if (p[i][j + 1] == '\0' && item != p[i][0])
                    follow(p[i][0]);
            }
        }
    }
}

void display()
{
    for (int i = 0; i < k; i++)
    {
        if (i == k - 1)
            printf("%c}\n", f[i]);
        else
            printf("%c,", f[i]);
    }
    k = 0;
    strcpy(f, "");
}

void main()
{
    int ch = 1;
    char item;

    printf("\nEnter the number of productions: ");
    scanf("%d", &n);
    printf("\nEnter the productions:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", p[i]);

    do
    {
        printf("\nEnter the item whose FIRST and FOLLOW is to be found: ");
        scanf(" %c", &item);

        first(item);
        printf("FIRST(%c) = {", item);
        display();

        follow(item);
        printf("FOLLOW(%c) = {", item);
        display();

        printf("\nDo you want to continue? [0/1]: ");
        scanf("%d", &ch);
    } while (ch == 1);
}