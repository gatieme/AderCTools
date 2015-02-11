/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Files.c                                                        *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/



#include "Files.h"


/// files函数实现部分
CToolsFILE CToolsOpen(const char* fileName, const char *openWay)     // 打开文件
{
    assert(fileName != NULL);       // 文件名不能为空

    CToolsFILE CToolsFILE_point;      // 源代码文件

    if((CToolsFILE_point = fopen(fileName, openWay)) == NULL)      // 打开文件
    {
        printf("can't open the source file...[%s]\n", fileName);
        exit(EXIT_FAILURE);
    }

    return CToolsFILE_point;
}


CToolsFILE CToolsFineOpen(const char* fileName, const char *openWay, CToolsFILE fp, ...)     // 打开文件
{
    #ifdef CTOOLS_DEBUG_DEFINE
    assert(fileName != NULL);       // 文件名不能为空
    #endif // CTOOLS_DEBUG_DEFINE

    CToolsFILE CToolsFILE_point;      // 源代码文件

    if((CToolsFILE_point = fopen(fileName, openWay)) == NULL)      // 打开文件
    {
        printf("can't open the source file...[%s]\n", fileName);

        /// 关闭已经打开的文件
        if(fp != NULL)              // 只要关联文件不是空的
        {
            va_list argPtr;

            int argCount = 0; // 可变参数数目
            CToolsFILE argValue = fp;
            va_start(argPtr, fp);    // 以固定参数的地址为起点确定变参的内存起始地址

            while(argValue != NULL)
            {
                fclose(argValue);       // 关闭文件

                printf("%p\n", argValue);
                argValue = va_arg(argPtr, CToolsFILE);  // 取出下一个地址变量的信息
                printf("%p\n", argValue);
                ++argCount;     // 参数数目增加1
            }
            #ifdef CTOOLS_DEBUG_DEFINE
            printf("正常关闭了已经打开的%d文件\n", argCount);
            #endif // CTOOLS_DEBUG_DEFINE

            exit(EXIT_FAILURE);
        }
    }

    return CToolsFILE_point;
}

int	CToolsCloseAll(CToolsFILE fpi,...)          // 关闭文件
{

    va_list argPtr;

    int argCount = 0; // 可变参数数目
    CToolsFILE argValue = fpi;


    va_start(argPtr, fpi);    // 以固定参数的地址为起点确定变参的内存起始地址
    //va_start(argPtr, argValue);

    while(argValue != NULL)
    {
        fclose(argValue);       // 关闭文件

        //printf("%p\n", argValue);
        argValue = va_arg(argPtr, CToolsFILE);  // 取出下一个地址变量的信息
        ++argCount;     // 参数数目增加1
    }

    // 上面的代码等价于下面的代码
    /*do
    {
    //    printf("%p\n", argValue);
        fclose(argValue);       // 关闭文件
        argValue = va_arg(argPtr, CToolsFILE);  // 取出下一个地址变量的信息
        ++argCount;        // 参数增加1
    }while(argValue != NULL);*/
    return argCount;
}


void CToolsFree(void *point)
{
    if(point != NULL)
    {
        free(point);
    }
}




