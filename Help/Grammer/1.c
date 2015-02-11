#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	freopen("Grammar_EN--TARGET.c", "r", stdin);
	freopen("Grammar.c", "w", stdout);	
	int i = 0;
	char res[81], str[81];
	
	
	for(i = 0; gets(res); )
	{
		if(strcmp(res, "") == 0)
		{
			continue;
		}
		//printf("%s\n", res);

		//sscanf(res, "%s", str);
		if(res[strlen(res) - 1] == ':')
		{
			printf("\n    %s\n", res);
		}
		else
		{
			i++;
			printf("%03d    %s\n", i, res);
		}
	} 
	
	
	return EXIT_SUCCESS;
}
