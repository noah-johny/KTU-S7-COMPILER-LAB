#include <stdio.h>
#include <string.h>

char states[30][5], result[30][5];
int count = 0;

void displayClosure(char state[5])
{
    printf("Epsilon closure of %s = {", state);
    for (int i = 0; i < count; i++)
        printf(" %s", result[i]);
    printf(" }\n");

    memset(result, 0, sizeof(result));
    count = 0;
}

void main()
{
    FILE *fp;
    fp = fopen("input.dat", "r");

    int n;
    char state[5], state1[5], state2[5], transition[5];

    printf("\nEnter the number of states: ");
    scanf("%d", &n);

    printf("\nEnter the states: ");
    for (int i = 0; i < n; i++)
        scanf("%s", states[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        strcpy(state, states[i]);
        strcpy(result[count++], state);

        while (!feof(fp))
        {
            fscanf(fp, "%s%s%s", state1, transition, state2);

            if (strcmp(state, state1) == 0 && strcmp(transition, "e") == 0)
            {
                strcpy(result[count++], state2);
                strcpy(state, state2);
            }
        }
        displayClosure(states[i]);
        rewind(fp);
    }

    printf("\n");
    fclose(fp);
}
