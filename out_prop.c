#include <stdio.h>
#include <stdlib.h>

#define LINE()        fprintf(__propFP__, "%d\n", __LINE__)
FILE *__propFP__;

#line 1 "Test\Source\bug11.c"
int main()
{if((__propFP__ = fopen("prop.txt", "w")) == NULL){fprintf(stderr, "can't open the file prop.txt\n");}
	for( LINE( ), i = 0; i < 10; LINE( ),  i++)
		 {  LINE( ); break; } 
 fclose(__propFP__); }