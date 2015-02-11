#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	
	char str[81], result[81], other[81];
	int i, num;
	
	while(gets(str) != NULL)
	{
		//printf("%s\n", str);
		for(i = 0; !(str[i] >= 'A' && str[i] <= 'Z') && str[i] != '\0'; i++);
		if(str[i] != '\0')
		{
			sscanf(str, "	%s", result);
			printf("\t\tcase %-24s:\n", result);
			printf("\t\t{\n");
			printf("\t\t\tbreak;\n");
			printf("\t\t}\n");
			
		}
	}
	
	return EXIT_SUCCESS;
}
