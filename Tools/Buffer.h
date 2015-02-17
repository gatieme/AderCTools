/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Buffer.h                                                       *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/




#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED


#include "Files.h"          // 文件信息函数
#include "Errors.h"


/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif

// 宏定义每个缓冲区大小4096B
#define BUFFER_SIZE  (sizeof(char)*4096)
#define BUFFER_COUNT 2


#define LINE_SIZE 1024
#
#
/// 缓冲区的使用信息
#define     NOT_USE   -1   // 当前缓冲区仅初始化完毕, 未使用
#define     LEFT       0     // 当前使用左缓冲区
#define     RIGHT      1     // 当前使用右缓冲区
#
#
/// 状态参数的宏定义信息
// 为特殊的函数提供-=>参数名为int choice
#define     THIS       0       // 表示参数处理为当前使用缓冲区
#define     OTHER      1       // 表示参数处理为另外一个未使用的缓冲区
#define     ALL       -1








//enum BufUsing
//{
//    LEFT = -1,          // 表示处理或者使用左部缓冲区
//    ALL = 0,            // 表示处理整个缓冲区
//    RIGHT = 1,          // 表示处理或者使用右边缓冲区
//}BufUsing;


// 双缓冲区结构体
typedef struct DouBuffer
{
    // 缓冲区信息
    char       *m_leftBuffer;       // 左半部分缓冲区    // 4097
    char       *m_rightBuffer;      // 右半部分缓冲区    // 4097
    int         m_using;            // 表示当前的使用信息使用   // 1
    // size_t m_bufsize;       // 缓冲区的大小

    // 缓冲区指针信息
    char       *m_forward;          // 向前指针
    char       *m_lexeme;           // 开始指针

    // 文件偏移信息
    CToolsFILE  m_fp;               // 指向当前缓冲区填充的文件的指针
    Coord      *m_coord;            // 当前缓冲区指令的位置偏移
}DouBuffer;                 // 双缓冲信息sizeof(DouBuffer) == 8204



#ifdef PUBLIC_and_PRIVATE
#
#
/// 返回当前字符的
/// 将字符串str填入到缓冲区中
PUBLIC bool                          // 返回值: 如果填入过程中修改了缓冲区的位置, 返回非零值false, 否则返回true
WriteStrInBuffer(                        // 功能:   将字符填入缓冲区
                 DouBuffer *douBuffer,   // 参数：  待处理的缓冲群信息
                 char *str);       // 参数：  将要填入缓冲区的字符串
#define write_str_in_buffer    WriteStrInBuffer  // 提供C命名方式的函数调用接口
#
#
/// 将缓冲区中的信息填入文件中
PUBLIC int
WriteBufferToFile(                          // 功能：  将缓冲区的信息写入文件中
                  DouBuffer *douBuffer,     // 参数：  待处理缓冲区的信息
                  CToolsFILE ofp,           // 参数：  指向待写入文件的指针
                  int choice);               // 参数：  0
#define write_buffer_to_file    WriteBufferToFile
#
#
/// 将缓冲区中的信息填入文件中
PUBLIC int
WriteLeftBufferToFile(                      // 功能：  将缓冲区的信息写入文件中
                     DouBuffer *douBuffer,    // 参数：  待处理缓冲区的信息
                     CToolsFILE ofp);           // 参数：  指向待写入文件的指针
#define write_left_buffer_to_file    WriteLeftBufferToFile
#
#
/// 将缓冲区中的信息填入文件中
PUBLIC int
WriteRightBufferToFile(                      // 功能：  将缓冲区的信息写入文件中
                     DouBuffer *douBuffer,    // 参数：  待处理缓冲区的信息
                     CToolsFILE ofp);           // 参数：  指向待写入文件的指针
#define write_right_buffer_to_file    WriteRightBufferToFile
#
#
/// 初始化缓冲区的信息
PUBLIC DouBuffer*                            // 函数无返回信息
InitBuffer(
           const char *fileName);           // 待处理的文件信息
#define init_buffer InitBuffer          // 提供C命名方式的函数调用接口
#define create_buffer InitBuffer
#define CreateBuffer InitBuffer
#
#
// 缓冲区收尾工作
PUBLIC void
FinitBuffer(
            DouBuffer *douBuffer);
#define finit_buffer FinitBuffer        // 提供C命名方式的函数调用接口
#define DestroyBuffer FinitBuffer
#define destroy_buffer FinitBuffer
#
#
/// 将待处理源文件ifp文件中信息读入缓冲区
PUBLIC int
PutBuffer(
          DouBuffer *douBuffer);         // 缓冲区的信息
#define put_buffer PutBuffer            // 提供C命名方式的函数调用接口
#
#
/// 将开始字符与向前指针之间的字符区出来
PUBLIC char*                            // 返回提取出来的文件的指针
CopyBufToken(
          DouBuffer *douBuffer);               // 缓冲区信息
#define copy_token  CopyToken           // 提供C命名方式的函数调用接口
#
#
// 将开始指针指向下一位置, 同时增加位置便偏移针的开始偏移
PUBLIC void
AddBufLexeme(
             DouBuffer *douBuffer);
#define sub_buf_lexeme AddBufLexeme
#
#
/// 将向前指针指向下一个位置
PUBLIC int
AddBufForward(
           DouBuffer *douBuffer);                // 缓冲区信息
#define add_forward  AddForward           // 提供C命名方式的函数调用接口
#
#
// 将向前指针指向下一个位置, 同时增加位置指针的结束偏移
PUBLIC void
SubBufForward(
              DouBuffer *douBuffer);
#define sub_buf_forward  SubBufForward
#
#
// 将开始指针指向下一位置, 同时增加位置便偏移针的开始偏移
PUBLIC void
SubBufLexeme(DouBuffer *douBuffer);
#define sub_forward  SubForward           // 提供C命名方式的函数调用接口

/// 判断当前访问位置[向前指针]是不是缓冲区的末尾
PUBLIC bool                                // 如果是缓冲区末尾返回TRUE, 否则返回FALSE
IsBufferEnd(
            DouBuffer *douBuffer);              // 缓冲区信息
#define is_buffer_end IsBufferEnd              // 提供C命名方式的函数调用接口
#
#
// 检查开始指针是不是位于缓冲区末尾
PUBLIC bool
IsLexmeAtBufEnd(
                DouBuffer *doubuffer);
#define is_lexeme_ad_buf_end    IsLexmeAtBufEnd
#
#
/// 判断当前两个指针是否在同一个缓冲区内部
PUBLIC bool                                     // 如果向前指针和开始指针在同一个缓冲区返回TRUE, 否则返回FALSE
IsInSameBuffer(
               DouBuffer *douBuffer);           // 缓冲区信息
#define is_in_same_buffer IsInSameBuffer        // 提供C命名方式的函数调用接口
#
#
/// 返回当前左部缓冲区的末尾
PUBLIC char*                                    // 返回指向左部缓冲区末尾的指针信息
LeftBufferEnd(
              DouBuffer *douBuffer);             // 缓冲区信息
#define left_buffer_end  LeftBufferEnd          // 提供C命名方式的函数调用接口
#
#
/// 返回当前右部缓冲区的末尾
PUBLIC char*
RightBufferEnd(
              DouBuffer *douBuffer);           // 缓冲区信息
#define right_buffer_end    RightBufferEnd      // 提供C命名方式的函数调用接口
#
#
/// 返回当前缓冲区末尾
PUBLIC char*                            // 指向当前使用的缓冲区的地址的指针
BufferEnd(
          DouBuffer *douBuffer,         // 缓冲区信息
          int choice);                  // 参数 0, 表示当前使用的缓冲区的末尾参数 1, 表示当前未使用缓冲区的末尾
#define buffer_end    BufferEnd      // 提供C命名方式的函数调用接口
#
#
/// 返回当前缓冲区末尾
PUBLIC char*                        // 指向当前使用的缓冲区起始位置的指针
BufferBegin(DouBuffer *douBuffer,   // 缓冲区信息
                  int choice);       // 参数 0, 表示当前使用的缓冲区的开始参数 1, 表示当前未使用缓冲区开始的末尾
#define buffer_begin    BufferBegin  // 提供C命名方式的函数调用接口
#
#
/// 将开始指针调整至向前指针的位置
PUBLIC void                         // 将缓冲区开始指针和向前指针对齐
CheckLexemeToForward(
                    DouBuffer *douBuffer);        // 缓冲区信息
#define check_lexeme_to_forward          // 提供C命名方式的函数调用接口
#
#
/// 计算缓冲区两个指针之间字符串的长度
PUBLIC int                              // 返回检索出来的字符串的长度
TokenLength(
            DouBuffer *douBuffer);      // 双缓冲区信息
#define token_length TokenLength        // 提供C命名方式的函数调用接口
#
#
/// 进行与预编译处理时,跳过空白字符的信息-=>空格制表符号
PUBLIC void
DisBufSpace(
            DouBuffer *doubuffer);           // 待处理的缓冲区信息
#define dis_space DisSpace              // 提供C命名方式的函数调用接口
#
#
/// 处理控制字符
PUBLIC void
DisBufControl(
           DouBuffer *douBuffer);                // 缓冲区信息
#define dis_buf_control  DisBufControl
#
#
/// 直接处理过滤掉整个文件缓冲区行的信息
PUBLIC void
DisCurrLine(
            DouBuffer *douBuffer);
#
#
/// 处理普通的注释信息
PUBLIC void
DisBufCommentLine(
                  DouBuffer *douBuffer);
#
#
/// 跳过预编译指令信息
PUBLIC void
DisBufProcom(
              DouBuffer *douBuffer);
#
#
#endif                 // #end_of_ifndef PUBLIC_and_PRIVATE






#endif // BUFFER_H_INCLUDED
