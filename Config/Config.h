/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : BinaryTuple.h                                                  *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/



#ifndef _CONFIG_H_INCLUDED
#define _CONFIG_H_INCLUDED







////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>          // 标准输入输出
#include <stdlib.h>         // 标准库函数
#include <stdarg.h>         // 可变参数列表
#include <assert.h>         // 断言函数
#include <limits.h>         // 宏信息库
#include <errno.h>          // 错误信息
#include <string.h>         // 字符串处理
#include <ctype.h>          // 字符处理
#include <stdbool.h>        // BOOL类型
#include <malloc.h>         // 堆空间处理
#include <time.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////
#define SYS_WINDOWS_DEF

#ifdef SYS_WINDOWS_DEF
#
    #define SYS_WIN32_DEF            // 32位Windows操作系统
    //#define SYS_WIN64_DEFINE            // 64位Windows操作系统

    #if define      SYS_WIN32_DEF
    #
    #
/////////////////////////////////////////////////////////////////////////////////////////////
        #define	WCHAR		 USHORT                                            //宽字符类型//
        #define CHAR_SIZE         1                                            // 字符类型 //
        #define SHORT_SIZE        2                                            // 短整型   //
        #define INT_SIZE          4                                            //   整型   //
        #define LONG_SIZE         4                                            //  长整型  //
        #define LONG_LONG_SIZE    4                                            // 长长整型 //
        #define FLOAT_SIZE        4                                            //  浮点数  //
        #define DOUBLE_SIZE       8                                            // 双精度数 //
        #define LONG_DOUBLE_SIZE  8                                            //长双精度数//
/////////////////////////////////////////////////////////////////////////////////////////////
    #
    #
    #
    #
    #elifdef   SYS_WIN64_DEFINE
    #
    #
//////////////////////////////////////////////////////////////////////////////////////////
        #define WCHAR		   ULONG                                            //宽字符类型//
        #define CHAR_SIZE          1                                            // 字符类型 //
        #define SHORT_SIZE         4                                            // 短整型   //
        #define INT_SIZE           8                                            //   整型   //
        #define LONG_SIZE          8                                            //  长整型  //
        #define LONG_LONG_SIZE     8                                            // 长长整型 //
        #define FLOAT_SIZE         8                                            //  浮点数  //
        #define DOUBLE_SIZE       16                                            // 双精度数 //
        #define LONG_DOUBLE_SIZE  16                                            //长双精度数//
//////////////////////////////////////////////////////////////////////////////////////////
    #
    #
    #
    #
    #endif
#
#
#
#
#endif

///CTools宏函数信息
///////////////////////////////////////////////////////////////////////////////////////////
#
#
/// 当前字符是数字
#define IsDigit(c)         (c >= '0' && c <= '9')
/// 当前字符是8进制数据
#define IsOctDigit(c)      (c >= '0' && c <= '7')
/// 当前字符是16进制数据
#define IsHexDigit(c)      (IsDigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
/// 当前字符是字母或者_
#define IsLetter(c)        ((c >= 'a' && c <= 'z') || (c == '_') || (c >= 'A' && c <= 'Z'))
/// 当前自负是否满足C的变量命名规则
#define IsLetterOrDigit(c) (IsLetter(c) || IsDigit(c))
#define IsIdentifier    IsLetterOrDigit
/// 当前字符是空白字符
#define IsSpace(c)  ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
///
#define ToUpper(c)		   (c & ~0x20)
/// 取出当前信息的高4位
#define HIGH_4BIT(v)       ((v) >> (8 * sizeof(int) - 4) & 0x0f)
/// 取出当前信息的高3位
#define HIGH_3BIT(v)       ((v) >> (8 * sizeof(int) - 3) & 0x07)
/// 取出当前信息的高1位
#define HIGH_1BIT(v)       ((v) >> (8 * sizeof(int) - 1) & 0x01)
#define ALIGN(size, align) ((size + align - 1) & (~(align - 1)))
#
#
///////////////////////////////////////////////////////////////////////////////////////////








/// CTools宏函数信息
//////////////////////////////////////////////////////////////////////////////////////////////
#define SHOW_FILE_NAME(fileName)     do                                                     \
                                    {   int i = strlen(fileName) - 1;                       \
                                        for( ; fileName[i] != '\\'                          \
                                        && fileName[i] != '/' && i >= 0; i--);              \
                                        char *fname = malloc(strlen(fileName) - i);         \
                                        strcpy(fname, fileName + i + 1);                    \
                                        printf("File: %s  ", fname);                        \
                                        free(fname);                                        \
                                    }while( 0 );
#
#
#define __file__ __FILE__           ///CTools文件名输出处理
#define FILENAME()                  do                                                      \
                                    {   int i = strlen(__FILE__) - 1;                       \
                                        for( ;                                              \
                                             __FILE__[i] != '\\' && __FILE__[i] != '/';     \
                                            i--);                                           \
                                        char *fname = malloc(strlen(__FILE__) - i);         \
                                        strcpy(fname, __FILE__ + i + 1);                    \
                                        printf("FileName: %s", fname);                      \
                                        free(fname);                                        \
                                    }while( 0 );
#
#
#define __line__ __LINE__           /// CTools行号输出处理
#define LINE( )                     do                                                      \
                                    {                                                       \
                                        printf("Line: %d", __LINE__);                       \
                                    }while( 0 );
#
#
#define __FUNC__ __func__           /// CTools函数名输出处理
#define FUNC( )                     do                                                      \
                                    {                                                       \
                                        printf("Function: %s", __FUNC__);                   \
                                    }while( 0 );
#
#
#define FILE_FUNC_LINE( )           do                                                      \
                                    {                                                       \
                                        FILENAME( );                                        \
                                        putchar(' ');                                       \
                                        FUNC( );                                            \
                                        putchar(' ');                                       \
                                        LINE( );                                            \
                                        putchar('\n');                                      \
                                    }while(0);
#
#
///////////////////////////////////////////////////////////////////////////////////////////////



/// 其他帮助函数信息
///////////////////////////////////////////////////////////////////////////////////////////////
#
#
// 延时函数
#define DELAY( )                    do                                                      \
                                    {                                                       \
                                        int i;                                              \
                                        for(i = 0; i < 1000000; i++);                       \
                                    }while( 0 );
#
#
#define PAUSE( )                    do                                                       \
                                    {                                                        \
                                        printf("Please enter any key to continue...\n");     \
                                        getchar( );                                          \
                                    }while( 0 );
#define STEP( ) PAUSE( )
#
// 版本输出函数
#define  VERSION( ) do                                                                              \
                    {   printf("\t\t**************************************************\n");         \
                        printf("\t\t**  Wacky Window (c) 2012 Wacky SoftWare. Inc.  **\n");         \
                        printf("\t\t**     Complied on %s at %s      **\n", __DATE__, __TIME__);    \
                        printf("\t\t**************************************************\n");         \
                        PAUSE( );                                                                   \
                    }while( 0 );
#
#
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 插桩器肯而难过用到的函数信息
#define Line(stream)        fprintf(stream, "%d\n", __line__);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////




typedef int State;          // 定义语法状态类型




/// 调试信息宏以及宏函数信息定义
///////////////////////////////////////////////////////////////////////////////////////////
// 宏定义函数的定义方式信息///////////////////////////////////////////////
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif
////////////////////////////////////////////////////////////////////////
#
#
// 函数定义信息//////////////////////////////////////////////////////////
PUBLIC int CToolsPrintf(const char *format, ...);                       // 定义CTools自己的输出函数
////////////////////////////////////////////////////////////////////////
#
#
/// DEBUG_DEFINE    用来开启调试信息宏
/// SHOWS_DEFINE    用来开启运行过程中的输出，开启每一步中的输出
/// HELPS_DEFINE    用来移到程序整体逻辑运行
//////////////////////////////////////////////////////////////////////////
// 全局调试信息宏////////////////////////////////////
// 文件打开方式更改
#define CTOOLS_FILE_OPEN_TEXT
#
#
//#define CTOOLS_FILE_OPEN_BINARY
#
#
// 调试信息更改
//#define CTOOLS_DEBUG_DEFINE         ///CTools调试宏信息//
#
//#define CTOOLS_SHOWS_DEFINE         ///CTools信息输出宏//
#
//#define CTOOLS_HELPS_DEFINE         /// CTools帮助输出宏
#
//#define CTOOLS_STEPS_DEFINE           /// CTools单步调试输出
////////////////////////////////////////////////////
#
#
// 词法分析器调试信息宏//////////////////////////////
//#define LEXICAL_DEBUG_DEFINE            /// Lexical调试信息宏
#
//#define LEXICAL_SHOWS_DEFINE            /// Lexical输出信息宏
#
//#define LEXICAL_HELPS_DEFINE            /// Lexical帮助信息宏
///////////////////////////////////////////////////
#
#
// 语法分析器调试信息宏/////////////////////////////
#
#define PARSER_DEBUG_DEFINE            /// Parser调试信息宏
#
#define PARSER_SHOWS_DEFINE            /// Parser输出信息宏
#
//#define PARSER_HELPS_DEFINE            /// Parser帮助信息宏
///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#
#
// 插桩器调试信息宏/////////////////////////////
#
//#define PROP_DEBUG_DEFINE            /// Prop调试信息宏
#
//#define PROP_SHOWS_DEFINE            /// Prop输出信息宏
#
//#define PROP_HELPS_DEFINE            /// Prop帮助信息宏
#
//#define PROP_REDUCTION_DEFINE        /// 在语法分析的同时进行Prop插桩
///////////////////////////////////////////////////
#
#
///////////////////////////////////////////////////////////////////////////









#endif      // ENDIF __CONFIG_H_
