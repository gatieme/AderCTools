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



int main(int argc, char **argv)
{
    // printf("%s\n", LineDefineStr);
    // printf("%s\n", FileOpenDefineStr);
    // printf("%s\n", StartDefineStr);
    // freopen("out-bug.txt", "w", stdout);

    MainOfLexical( );
//
//    #ifndef PROP_REDUCTION_DEFINE
//    ParseFilePropRed("out_prop.c", ".\\TEST\\Bug\\bug8-1.c");
//    #endif  // PROP_REDUCTION_DEFINE

    PAUSE( );
    return EXIT_SUCCESS;
}

