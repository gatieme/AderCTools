/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Preprocessor.c                                                         *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/








#include "Preprocessor.h"               // 预处理函数接口
#include "Errors.h"                     // 错误定位信息
#include "Buffer.h"

/// Preprocessor函数声明
#ifdef PUBLIC_and_PRIVATE
#
#
/// 确定预处理文件的名字
PRIVATE bool                                // 返回预处理是否成功
SetProFileName(
               char *sourFile);             // 待处理源文件名称或者路径
#
#
/// 对#define宏定义指令进行处理
PRIVATE bool                                // 返回对#define预编译是否成功
ProDefine(DouBuffer *douBuffer,             // 双缓冲区信息
          char *str,                        // 从输入文件中读取出来的字符串信息
          CToolsFILE ifp);                  // 待处理文件
#
#
/// 对#line宏定义指令进行处理
PRIVATE bool                                // 返回#line预编译处理是否成功
ProLine(DouBuffer *douBuffer,               // 待处理缓冲区信息
        char *str);                          // 待处理的字符串
#
#
#endif          // PUBLIC_and_PRIVATE

/// 预处理函数
/*
思路：
    首先从原文件中读取一行信息, 判断当前信息
    如果是类型的注释就跳过
    如果是#预编译指令就开始处理
    同时递归添加信息
    添加源文件的行号信息
*/

/// 确定预处理文件的名字
bool SetProFileName(char *sourFile)             // 待处理源文件名称或者路径
{
    return false;
}


bool Processor(char *destFile, char *sourFile)
{
    char        str[BUFFER_SIZE];              // 用于存储从文件中读取到的字符串信息

    // 准备好输入输出文件
    /// 这里存在一个问题：如果打开输出文件失败返回但是ifp却打开并没有关闭
    CToolsFILE  ifp = CToolsFineOpen(sourFile, READ_ONLY_BINARY, NULL/*当前打开文件列表为空*/);        // 打开源文件
    CToolsFILE  ofp = CToolsFineOpen(destFile,WRITE_ONLY_BINARY, ifp, NULL/*当前打开文件列表为ifp, NULL*/);        // 目标文件

    /// 词法行号的记录信息
    ///Coord *coord = InitCoord(sourFile);                 // 文件行号记录信息

    /// 双缓冲区设置信息
    DouBuffer *douBuffer = InitBuffer(sourFile);                   // 双缓冲区信息

    if(CToolsGets(str, BUFFER_SIZE, ifp) != NULL)        // 按行从原文件中读取信息
    {
        if(str[0] == '#')           // 以#开头的为预编译命令
        {
            if(strncmp(str, "include", 7) == 0)             //
            {

            }
            else if(strncmp(str, "define", 6) == 0)         // 宏定义预编译指令
            {

            }
            else if(strncmp(str, "undef", 5) == 0)          // 取消定义宏指令
            {

            }
            else if(strncmp(str, "if", 2) == 0)             // 条件编译指令#if, #ifdef, #ifndef, #if define,
            {

            }
            else if(strncmp(str, "el", 2) == 0)             // 条件编译指令
            {

            }
            else if(strncmp(str, "error", 5) == 0)         // 错误预编译指令
            {

            }
            else if(strncmp(str, "line", 4) == 0)           // 行号编译指令
            {

            }
            else if(strncmp(str, "pragma", 6) == 0)         // 特殊编译指令
            {

            }
            else
            {
                ///*/////////////////////////////////////////////////////////
                ///                 文件中有错误信息
                ///*/////////////////////////////////////////////////////////
            }
        }
        else                // 源文件中不宜#开头的均是源代码信息
        {
            WriteStrInBuffer(douBuffer, str);               // 直接将源代码写入缓冲区中
        }
    }

    if(douBuffer->m_coord != NULL)
    {
        free(douBuffer->m_coord);
    }

    return true;
}



/// 对#define宏定义指令进行处理
// char *str    从文件中读取到的str字符串信息
//
bool ProDefine(DouBuffer *douBuffer, char *str, CToolsFILE ifp)
{
    return true;
}


/// 对#ifdef宏定义指令进行处理
// char *str    从文件中读取到的str字符串信息
//
bool ProIfdef(DouBuffer *douBuffer, char *str, CToolsFILE ifp)
{
    #ifdef CTOOLS_DEBUG_DEFINE
    assert(strncmp(str, "ifdef", 5) == 0);          // 参数必须合法
    #endif     // CTOOLS_DEBUG_DEFINE


    return true;
}


/// 对#line宏定义指令进行处理
bool ProLine(DouBuffer *douBuffer, char *str)                          // 待处理的字符串
{
    return true;
}
