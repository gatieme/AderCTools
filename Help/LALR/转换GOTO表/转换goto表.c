#include <stdio.h>
#include <stdlib.h>



void Display(char *reveived);

int main(void)
{
	freopen("GOTO.lalr", "r", stdin);
	freopen("GOTO.c", "w", stdout);
	
	int i = 0;
	char str[81], received[81];
	int state, goTo, last = -1;

	gets(str);
	for(i = 0; gets(str); i++)
	{
		if(strcmp(str, "") == 0)
		{
			continue;
		}
		//printf("%s\n", str);
		sscanf(str, "%d%s%d", &state, received, &goTo);
		

		Display(received);

		if(last != state)
		{
			if(last != -1)
			{
				printf("\n    {                        SYN_NULL,      -1,    },    // the %d's goto end\n", state);
				printf("};\n\n");
			}
			printf("GoToNode goto%d[] = \n", state);
			printf("{\n");
			printf("/**			receive				goto**/\n");
			//printf("    %-28s,%3d,		//%s\n", received, goTo, str);
			
			last = state;
		}
		else
		{
			//printf("    %-28s,%3d,		//%s\n", received, goTo, str);
		}
		printf("    {    %28s,%8d,    },    // %s\n", received, goTo, str);
	}
	printf("\n    {                        SYN_NULL,      -1,    },    // the %d's goto end\n", state);
	printf("};\n\n");
	return EXIT_SUCCESS;
}


void Display(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if(str[i] == '-')
		{
			str[i] = '_';
		}
		i++;
	}
}
