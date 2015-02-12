// bug8
// scanf() 和 printf 函数位于int a;定义后会出现崩溃
//  
int main()
{
	int a;
	scanf("%d", &a);
}