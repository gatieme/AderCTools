int main(void)
{

    char sourFile[MAX_STR_SIZE];

    while(printf("请输入待处理源文件名:"), scanf("%s", sourFile) != (-1))
    {
        Lexical(sourFile);
    }

    return 0;
}
