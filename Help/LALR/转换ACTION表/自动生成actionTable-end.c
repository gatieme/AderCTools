#include <stdio.h>
#include <stdlib.h>


#define SIZE 395

int main(void)
{
	int i;
	//printf("%d", 376%12);
	
	freopen("3.txt", "w", stdout);
	//printf("    NULL,\n  ");
	for(i = 0; i <= SIZE; i++)
	{
		if(i % 10 == 0)
		{
			printf("\n   ");
		}
		if(i / 10 == 0)
		{
			printf("   ");
		}
		else if(i / 100 == 0)
		{
			printf("  ");
		}
		else
		{
			printf(" ");
		}
		printf("action%d,", i);
	}
	
	return EXIT_SUCCESS;
}
