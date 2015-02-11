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

	for(j = 0; gets(str);)
	{
		if(strcmp(str, "") != 0)
		{
			printf("\t//%s\n", str);
		}
		if(strcmp(str, "") == 0)
		{
			if(feof(stdin) != 0)
			{
				break;
			}
			continue;
		}
		//printf("%s\n", str);


		if(str[strlen(str)-1] >= '0' && str[strlen(str)-1] <= '9')
		{

			j++;
			count = atoi(&str[strlen(str) - 1]);		// 读取出来产生式的长度

			//	printf("  {\n");
			Display(str, count);
		//	printf("\n  },\n\n");
		}
		else
		{
		    //printf("\"%s\"\n", str);
			//exit(-1);
		}


	}

	//system("PAUSE");
	return EXIT_SUCCESS;
}



void Display(char *str, int count)
{
	char left[81];
	char info[81];
	char name[9][81];
	char flag[9][81];
	int i;
	int cnt/*长度*/, num/*编号*/;
	switch(count)
	{
		case 1:
			//sscanf(str, "%s%s%s%s%d", left, info, name[0], flag[0], num);
			sscanf(str, "%d%s%s%s%s%d", &num, left, info, name[0], flag[0], &cnt);

			for(i = 1; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 2:
			sscanf(str, "%d%s%s%s%s%s%s%d", &num, left, info, name[0], flag[0], name[1], flag[1], &cnt);
			for(i = 2; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 3:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%d", &num, left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], &cnt);
			for(i = 3; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 4:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%s%s%d", &num,  left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], &cnt);
			for(i = 4; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 5:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%s%s%s%s%d", &num,  left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], &cnt);
			for(i = 5; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;

		case 6:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", &num,  left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], &cnt);
			for(i = 6; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 7:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", &num,  left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], name[6], flag[6], &cnt);
			for(i = 7; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 8:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", &num,  left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], name[6], flag[6], name[7], flag[7], &cnt);
			for(i = 8; i < 9; i++)
			{
				strcpy(name[i], "SYN_NULL,");
				strcpy(flag[i], "IS_NULL_DATA,");
			}
			break;
		case 9:
			sscanf(str, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", &num,  left, info, name[0], flag[0], name[1], flag[1], name[2], flag[2], name[3], flag[3], name[4], flag[4], name[5], flag[5], name[6], flag[6], name[7], flag[7], name[8], flag[8], &cnt);
			break;
	}
	//system("pause");
	printf("\t{\n");

	printf("\t\t%4d,%4d,%28s,\n", num, cnt, left);
	printf("\t\t{\n");

	for(i = 0; i < 9; i++)
	{
		/*if(i != 0 && i % 3 == 0)
		{
			printf("\n                                                   ");
		}
		*/
		printf("\t\t\t{%s%s},\n", name[i], flag[i]);
		/*if(strlen(name[i]) + strlen(flag[i]) < 44)
		{
			int j, len = 44 - strlen(name[i]) - strlen(flag[i]);
			for(j = 0; j < len; j++)
			{
				printf(" ");
			}
		}*/
	}
	printf("\t\t},\n");
	printf("\t},\n\n");

}











