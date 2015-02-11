#include <stdio.h>
#include <stdlib.h>

int Comp(const void *a,const void *b);

void Display(char *str);

int main(void)
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int 	i = 0, a, b, len;
	char	all[10000][81];
	//scanf("%s%s%s", all[0], all[0], all[0]);
	//system("pause");
	for(i = 0; scanf("%d%s%d", &a, all[i], &b); i++)
	{
		if(feof(stdin) != 0)
		{
			break;
		}
		//printf("%d %s %d\n", a, all[i], b);
	}
	
	//system("pause");
	strcmp(all[i], "000000");
	len = i;
	//printf("%d", len);
	qsort(all, i, 81, Comp);
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(all[i], all[i+1]) != 0)
		{
			Display(all[i]);
			printf("%s\n", all[i]);
			//system("pause");
		}
	}
	
	return EXIT_SUCCESS;
}

int Comp(const void *a,const void *b)
{
	char *aStr = (char* )a;
	char *bStr = (char* )b;
	
	return (strcmp(aStr, bStr));
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

