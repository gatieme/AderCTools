/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : SymbolTable.h                                                  *
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


#ifndef SYMBOLTABLE_H_INCLUDED
#define SYMBOLTABLE_H_INCLUDED


#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"



#define UNKNOWVALUE -1

/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif


///  变量数据结构
typedef struct Identifier
{
    char                *m_name;               // 指向NameTable的指针[存放当前变量的名称]//1
    TokenKind            m_kind;                // 符号的种类[变量、函数、形参]//
    int                  m_offset;               // 相对地址
    void                *m_expand;             // 扩展指针[]
    struct Identifier   *m_next;   // 指向下一个信息的地址的指针
}Identifier;                    // 变量-识别码


// 宏定义符号表的宽度
#define BUCKETS 27      // 27个宽度对应26个英文字母 + '_'
// 也就是说此哈希表是按照英文字母开始索引的部分大小写


/// 符号表数据结构[HashTable]
//typedef struct SymbolTable
//{
//    Identifier **m_hashTable;        // 符号哈希表
//}SymbolTable;       // 符号表
typedef Identifier**    SymbolTable;       // 符号表信息



#ifdef PUBLIC_and_PRIVATE
#
#
// 初始化哈希表信息
PUBLIC SymbolTable
InitSymbolTalbe(
                SymbolTable /*__attribute__((unused))*/ symbolTable);
#
/// 将表示token添加进入符号表
PUBLIC Identifier*                      // 返回插入的标识符信息在符号表中的指针
InsertSymbolToken(char *token,                // 检索出来需要处理的字符串信息
            SymbolTable symbolTable);   //  符号表信息
#
/// 查询token是否在符号表中
PUBLIC Identifier*                      // 如果token在符号表中, 返回指向标识符信息的指针，否则返回NULL
FindSymbolToken(char *token,                  // 检索出来需要处理的字符串信息
          SymbolTable symbolTable);     //  符号表信息
#
PUBLIC void
ShowSymbolList(Identifier *idenList);   // 输出每个哈希数据项的信息
#
PUBLIC void
VisitSymbolTable(SymbolTable symbolTable);  // 输出符号表的信息
#
#endif



#endif // SYMBOLTABLE_H_INCLUDED
