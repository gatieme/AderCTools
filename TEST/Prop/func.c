typedef struct tagAB
{
	int a;
	int b;
}AB;

// 顺序结构 
void Sequence(int a, int b); 
// 选择结构 
void Choice(int a, int b);
// 循环结构 
void Cycle(itn *array, int b); 

// 主函数 
int main( )
{
	// 变量声明语句 
	int	a	=	10;
	int b = 056;
	int c = 0xffff;
	
	int array[] = {1, 2, 3, 4, 5,};
	char	d =	'a';
	char	*e = "affsfsdfsd";
	char	f[] = "asdfdsfsd";
	char	g[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0',};
	char	h[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0'};



	
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


// 选择结构 
void Choice(int a, int b)
{
	// 单IF结构 
	if(a == b)
	{
		printf("1\n");
	}
	
	// IF-ELSE结构 
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
		case 	b:	
			printf("1\n");
			break;
		default	 :  
			printf("0");
			break;
	}
}


// 循环结构 
void Cycle(int *array, int len)
{
	int i = 0;
	
	do
	{
		i++; 
	}while(i < len);
	
	for(;;)
	{
		break
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
