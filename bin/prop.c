void Sequence(int a, int b);

void Choice(int a, int b);

void Cycle(int *array, int b);

int	a	=	10;
int b = 056;
int c = 0xffff;



int main( )
{
	int array[] = {1, 2, 3, 4, 5,};
	{
		char	d =	'a';
		char	*e = "affsfsdfsd";
		char	f[] = "asdfdsfsd";
		char	g[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0',};
		char	h[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	}

		Sequence(a, b);
		Choice(a, b);
		Cycle(array, 5);




	return EXIT_SUCCESS;
}


void Sequence(int a, int b)
{
	a = 10;
	a = b;

	a++;
	b--;

	a += 11;
	a += b;

	a = a + b;
	a = a + 10;

	a = (a + b) * (a - b);
	a = (a + 10) *(b + 10);

}

void Choice(int a, int b)
{

	if(a == b)
	{
		printf("1\n");
	}

	if(a == b)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	switch(a)
	{
		case 	3:
			printf("1\n");
			break;
		default	 :
			printf("0");
			break;
	}
}


void Cycle(int *array, int len)
{
	int i = 0;

	do
	{
		i++;
	}while(i < len);

	for(;;)
	{
		break;
	}

	for(i = 0; ; i++)
	{
		if(i == len)
		{
			break;
		}
	}

	for(i = 0; i < len ; i++)
	{
		continue;
	}

	for(i = 0; i < len; )
	{
		i++;
	}

	for(; i < len; i++)
	{
		i = len;
	}

	while(i < len)
	{
		i++;
	}

}
