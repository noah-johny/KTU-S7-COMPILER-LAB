#include <stdio.h>
#include <stdlib.h>

int countbit1(unsigned int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        n >>= 1;
        i++;
    }
    printf("\nNumber of iterations: %d", i);
    return bits;
}

int countbit2(unsigned int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        if (n & 2)
            bits++;
        if (n & 4)
            bits++;
        if (n & 8)
            bits++;
        n >>= 4;
        i++;
    }
    printf("\nNumber of iterations: %d", i);
    return bits;
}

void main()
{
    unsigned int n;
    int x, ch;

    while (1)
    {
        printf("\n[Enter '0' to exit]\n1. Loop Roll\n2. Loop Unroll\n");
        printf("\nEnter the choice: ");
        scanf(" %d", &ch);

        if (ch != 0)
        {
            printf("\nEnter n: ");
            scanf("%u", &n);
        }

        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            printf("\nLoop Rolling:");
            x = countbit1(n);
            printf("\nCount of 1's: %d\n\n", x);
            break;
        case 2:
            printf("\nLoop Unrolling:");
            x = countbit2(n);
            printf("\nCount of 1's: %d\n\n", x);
            break;
        default:
            printf("\nInvalid Choice!\n\n");
        }
    }
}