void Cycle(int *array, int b); 

// 主函数 
int main( )
{




	
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

