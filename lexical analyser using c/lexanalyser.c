#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main()
{
	FILE *fp;
	int lines = 1, tokens = 0, i, j, flag;
	char ch, word[20];

	fp = fopen("input.c", "r");

	char keyword[30][30] = {"int", "main", "if", "else", "do", "while", "include", "stdio", "void", "printf", "scanf"};

	while (!feof(fp))
	{
		i = 0;
		flag = 0;
		ch = fgetc(fp);

		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		{
			printf("%c\t\tOperator\n", ch);
			tokens++;
		}
		else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '?' || ch == '@' || ch == '!')
		{
			printf("%c\t\tSpecial symbol\n", ch);
			tokens++;
		}
		else if (isdigit(ch))
		{
			printf("%c\t\tDigit\n", ch);
			tokens++;
		}
		else if (isalpha(ch))
		{
			word[i] = ch;
			i++;
			ch = fgetc(fp);

			while (isalnum(ch) && ch != ' ')
			{
				word[i] = ch;
				i++;
				ch = fgetc(fp);
			}

			word[i] = '\0';
			for (j = 0; j <= 30; j++)
			{
				if (strcmp(word, keyword[j]) == 0)
				{
					flag = 1;
					break;
				}
			}

			if (flag == 1)
			{
				printf("%s\t\tKeyword\n", word);
				tokens++;
			}
			else
			{
				printf("%s\t\tIdentifier\n", word);
				tokens++;
			}
		}
		else if (ch == '\n')
			lines++;
	}

	fclose(fp);
}
