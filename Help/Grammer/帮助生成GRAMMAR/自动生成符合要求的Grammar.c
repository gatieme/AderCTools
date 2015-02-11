#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// 将终结符号转换为必要的格式
void Display(char *str, int count);


int main(void)
{
	freopen("result.c", "r", stdin);
	freopen("AllResult.c", "w", stdout);
	char str[1000];
	int count;
	int j;

	for(j = 1; gets(str);)
	{

		if(strcmp(str, "") == 0)
		{
			printf("\n");
			if(feof(stdin) != 0)
			{
				break;
			}
			continue;
		}
		//printf("%s\n", str);


		if(str[strlen(str)-1] >= '0' && str[strlen(str)-1] <= '9')
		{
			printf("  {\n    %3d,", j);
			j++;
			count = atoi(&str[strlen(str) - 1]);
			//system("pause");
			Display(str, count);
			printf("\n  },\n\n");
		}
		else
		{
			exit(-1);
		}


	}

	return EXIT_SUCCESS;
}



void Display(char *str, int count)
{
	char left[81];
	char info[81];
	char name[9][81];
	char flag[9][81];
	int i;
	int num;
	switch(count)
	{
		case 1:
			//sscanf(str, "%s%s%s%s%d", left, info, name[0], flag[0], num);
			sscanf(str, "%s%s%s%s%d", left, info, name[0], flag[0], &num);

			for(i = 1; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 2:
			sscanf(str, "%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], &num);
			for(i = 2; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 3:
			sscanf(str, "%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], &num);
			for(i = 3; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 4:
			sscanf(str, "%s%s%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], &num);
			for(i = 4; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 5:
			sscanf(str, "%s%s%s%s%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], &num);
			for(i = 5; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;

		case 6:
			sscanf(str, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], &num);
			for(i = 6; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 7:
			sscanf(str, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], name[6], flag[6], &num);
			for(i = 7; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 8:
			sscanf(str, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], name[6], flag[6], name[7], flag[7], &num);
			for(i = 8; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 9:
			sscanf(str, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], name[6], flag[6], name[7], flag[7], name[8], flag[8], &num);
			break;
	}
	//system("pause");
	//printf("  {\n");
	printf("%4d,%28s,    ", num, left);
	printf("{    ");
	for(i = 0; i < 9; i++)
	{
		if(i != 0 && i % 3 == 0)
		{
			printf("\n                                                   ");
		}
		printf("{%s%s},", name[i], flag[i]);
		if(strlen(name[i]) + strlen(flag[i]) < 44)
		{
			int j, len = 44 - strlen(name[i]) - strlen(flag[i]);
			for(j = 0; j < len; j++)
			{
				printf(" ");
			}
		}
	}
	printf("    },");

}











