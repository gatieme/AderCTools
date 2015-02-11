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


/*
描述：
    Preprocessor为CTools提供了预处理器的接口信息
*/


#ifndef PREPROCESSOR_H_INCLUDED
#define PREPROCESSOR_H_INCLUDED

#include "..\Tools\Buffer.h"



// 系统头文件路径的宏定义信息
#define SYS_INCLUDE_PATH_DIR "D:/SoftwareEngineer/MinGW32/include"


/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif



/// Preprocessor函数声明
#ifdef PUBLIC_and_PRIVATE
#
#
/// 预处理函数
PUBLIC bool                            // 返回预处理是否成功
Processor(
          char *destFile,           // 待处理的目标文件-=>预处理源文件
          char *sourFile);          // 待处理源文件名称或者路径
#
#
#endif          // PUBLIC_and_PRIVATE











#endif // PREPROCESSOR_H_INCLUDED
