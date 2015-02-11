/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Lexical.h                                                      *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/



/**[代码修改信息]0.6
@@   修复了douTuple头结点未分配空间就使用所造成的BUG[2013/3/21-15:39]
@@   修复了判断为分界符[5]不可打印字符的输出造成的程序错误isprint()
##   采用较低级的办法处理了二元组结点域中char *m_value指针的赋值问题, 暂时修改为char m_value[20];
**/

/**[代码修改信息]0.7
@@   添加主函数传参的处理信息
@@   增加了TupleNode结点的属性m_fileInfo, 替换了原来的[int]m_keycode, 作为HEAD结点的数据域
     [int] m_keycount用来存储当前文件的词法信息数目
     [char*] m_file用来存储当前编译的文件的文件名
**/



/**[代码修改信息]0.8
@@  添加双缓冲区的设置, 将文件中的信息读取到缓冲区以提高效率[未完成]
**/


/**[代码修改信息]0.9
@@  修改双缓冲区的设置, 将文件中的信息读取到缓冲区以提高效率[未完成]
@@  添加符号表SymbolTable的信息, 将标识符插入到符号表中的哈希表中
**/

/**[代码修改信息]0.95
@@  修改双缓冲区的设置, 将文件中的信息读取到缓冲区以提高效率[未完成]
@@  修改符号表SymbolTable的信息, 将标识符插入到符号表中的哈希表中
@@  更改函数BufferLexical将大于100行的函数全部分成几个分别处理的函数
    分别处理串[关键字或者标识符], 以及处理运算符, 分界面符号
**/


/**[代码修改信息]0.96
@@  修改符号表SymbolTable的信息, 将标识符插入到符号表中的哈希表中
@@  更改函数BufferLexical将大于100行的函数全部分成几个分别处理的函数
    分别处理串[关键字或者标识符], 以及处理运算符, 分界面符号
@@  将所有的参数更改为指针类型, 更改缓冲区的设置, 缓冲区改为堆空间申请开辟
**/

/**[代码修改信息]0.97
@@  更新所有的程序结构，消除所有的警告信息
    将PUBLIC函数声明移动到.h文件, 将PRIVATE函数声明移动到.c文件中
    结构体命名的更新， 消除指针转型的警告信息

**/



#ifndef LEXICAL_H_INCLUDED
#define LEXICAL_H_INCLUDED


#include "..\Config\Config.h"

#include "..\Tools\Files.h"             // 文件处理接口
#include "..\Tools\Buffer.h"            // 双缓冲区接口
#include "..\Lexical\TokenKind.h"       // 关键字种类标识
#include "..\Lexical\BinaryTuple.h"     // 词法二元组信息


/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#
    #define PUBLIC  extern          // 函数可以被外界访问
    #define PRIVATE static      // 函数只能被本文件的函数调用
#
#
#endif








#ifdef PUBLIC_and_PRIVATE
#
#
/// 基本操作函数
/// 对源文件进行词法分析
PUBLIC BinaryTuple                          // 返回分析出来的词法二元组
BufferLexical(
              const char *sourFile);               // 待处理源文件
#define  buffer_lexical   BufferLexical
#
#
// 对源文件进行词法分析
PUBLIC void     // 词法分析的测试主程序
MainOfLexical(void);    // 待处理源文件
#define main_of_lexical MainOfLexical
#
#
// 对源文件进行词法分析
PUBLIC void     // 词法分析的测试主程序
TestOfLexical(void);    // 待处理源文件
#
#
/// 对源文件进行词法分析
PUBLIC BinaryTuple                          // 返回分析出来的词法二元组
BufLexSourFile(
              const char *sourFile);               // 待处理源文件
#define  buffer_lexical   BufferLexical
#
#
/// 对预处理文件进行词法分析
PUBLIC BinaryTuple                          // 返回分析出来的词法二元组
BufLexProFile(
              const char *proFile);               // 待处理源文件
#endif



#endif // LEXICAL_H_INCLUDED
