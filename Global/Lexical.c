/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : main.c                                                         *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/





#include "CTools.h"    //  #include "..\Global\CTools.h"



/*
*
*   BUG:    归约之后，应该将产生式的左部信息入栈, 但是再次归约时出现问题
*   BUG:    常量信息插入的数据有误, 需要对数据进行判断将不同类型的常量进行分别处理
*   D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.3]\Prop\Prop.c
*
*/



int main(int argc, char **argv/*char *argv[]*/)
{
    //MainOfLexical( );
    char sourceFile[FILE_NAME_SIZE];        // 源文件名
    BinaryTuple douTuple = NULL;               // 二元组信息

    if(argc > 2)
    {
        printf("usage : %s [ source.c] \n", argv[1]);
    }
    else if(argc == 2)
    {
        strcpy(sourceFile, argv[1]);
    }
    else/* if(argc == 1)*/
    {
        printf("please input the fiel you want to lexical : ");
        scanf("%s", sourceFile);
    }

    #ifdef SYS_WINDOWS_DEF
    system("title 词法分析器");
    system("color 00");
    #endif      // SYS_WINDOWS_DEF



    douTuple = BufferLexical(sourceFile);      // 直接处理源文件
    VisitTuple(douTuple);                    // 遍历二元组信息, 查找二元组正确性


    return EXIT_SUCCESS;
}

