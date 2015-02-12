#include <stdio.h>
#include <stdlib.h>

#define LINE()        fprintf(__propFP__, "%d\n", __LINE__)
FILE *__propFP__;

#line 1 "prop.c"
void Sequence(int a, int b);

void Choice(int a, int b);

void Cycle(int *array, int b);

int	a	=	10;
int b = 056;
int c = 0xffff;



int main( )
{if((__propFP__ = fopen("prop.txt", "w")) == NULL){fprintf(stderr, "can't open the file prop.txt\n");}
	int array[] = {1, 2, 3, 4, 5,};
	{
		char	d =	'a';
		char	*e = "affsfsdfsd";
		char	f[] = "asdfdsfsd";
		char	g[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0',};
		char	h[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	}

		 LINE( ), Sequence(a, b);
		 LINE( ), Choice(a, b);
		 LINE( ), Cycle(array, 5);
	



	 {  LINE( );  fclose(__propFP__); return EXIT_SUCCESS; } 
}


void Sequence(int a, int b)
{
	 LINE( ), a = 10;
	 LINE( ), a = b;
	
	 LINE( ), a++;
	 LINE( ), b--;
	
	 LINE( ), a += 11;
	 LINE( ), a += b;
	
	 LINE( ), a = a + b;
	 LINE( ), a = a + 10;
	
	 LINE( ), a = (a + b) * (a - b);
	 LINE( ), a = (a + 10) *(b + 10);
	
} 

void Choice(int a, int b)
{

	if( LINE( ), a == b)
	{
		 LINE( ), printf("1\n");
	}
	
	if( LINE( ), a == b)
	{
		 LINE( ), printf("1\n");
	} 
	else
	{
		 LINE( ), printf("0\n");
	}
		
	switch( LINE( ), a)
	{
		case 	3:	
			 LINE( ), printf("1\n");
			 {  LINE( ); break; } 
		default	 :  
			 LINE( ), printf("0");
			 {  LINE( ); break; } 
	}
}


void Cycle(int *array, int len)
{
	int i = 0;
	
	do
	{
		 LINE( ), i++; 
	}while( LINE( ), i < len);
	
	for( LINE( ) ;; LINE( ) )
	{
		 {  LINE( ); break; } 
	}
	
	for( LINE( ), i = 0; ; LINE( ),  i++)
	{
		if( LINE( ), i == len)
		{
			 {  LINE( ); break; } 
		}
	}
	
	for( LINE( ), i = 0; i < len ; LINE( ),  i++)
	{
		 {  LINE( ); continue; } 
	}
	
	for( LINE( ), i = 0; i < len; LINE( )  )
	{
		 LINE( ), i++;
	}
	
	for( LINE( ) ; i < len; LINE( ),  i++)
	{
		 LINE( ), i = len;
	}

	while( LINE( ), i < len)
	{
		 LINE( ), i++;
	}
	
} 
