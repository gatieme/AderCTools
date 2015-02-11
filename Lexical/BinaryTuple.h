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
/*
描述：
    BinaryTuple采用链表的方式存储当前文件的词法信息
*/




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


#ifndef BINARYTUPLE_H_INCLUDED
#define BINARYTUPLE_H_INCLUDED


#include "..\Config\Config.h"


#include "..\Lexical\TokenKind.h"           // 种别信息
#include "..\Tools\Files.h"          // 文件处理接口
#include "..\Tools\Errors.h"


/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif

/// 0.1.6之前原来的结构体定义
///// 存放C语言词法信息的二元组结点
//typedef struct TupleNode
//{
//    Kind  m_kind;       /*种别码*/
//    union Data
//    {
//        char *m_identifier;        // [标识符]指向符号表中标识符地址的指针
//        char *m_constNum;               // 常量数据
//        char *m_fileName;           // 文件名
//        int m_keyCode;              // [关键字]关键字的编码
//    }m_data;
//    struct TupleNode *m_next;      /*指向下一个结点的指针域*/
//}TupleNode;

/// 0.5.2之前原来的结构体的定义
/// 词法结点的数据域信息
typedef union TupleInfo
{
    char*               m_identifier;        // [标识符]指向符号表中标识符地址的指针
    char*               m_constNum;               // 常量数据
    char*               m_fileName;           // 文件名
    int                 m_keyCode;              // [关键字]关键字的编码
}TupleInfo;                          // size -=> 4B

/// 存放C语言词法信息的二元组结点
typedef struct TupleData
{
    TokenKind           m_kind;        // 词法信息的种别码
    TupleInfo           m_data;        // 词法信息的数据域
    Coord               m_coord;       // 词法二元组的行标识
}TupleData;

/// 存放C语言词法信息的二元组结点
typedef struct TupleNode
{
    TupleData           m_tuple;              // 词法二元组信息

    struct TupleNode    *m_next;      // 词法信息中指向下一个结点的指针域
    struct TupleNode    *m_last;       // 词法=信息中指向上一个结点的指针域
}TupleNode;

///0.5.4之后的定义词法结点
//typedef struct TupleNode
//{
//    TupleInfo          m_data;        // 词法信息的数据域
//    TokenKind          m_kind;        // 词法信息的种别码
//    Coord              m_coord;       // 词法二元组的行标识
//
//    char*               m_identifier;        // [标识符]指向符号表中标识符地址的指针
//    char*               m_constNum;               // 常量数据
//    char*               m_fileName;           // 文件名
//    int                 m_keyCode;              // [关键字]关键字的编码
//
//    struct TupleNode*   m_next;        // 词法信息中指向下一个结点的指针域
//}TupleNode;
////typedef struct TupleData
////{
////    TokenKind           m_kind;        // 词法信息的种别码
////    Coord               m_coord;       // 词法二元组的行标识
////
////    char*               m_identifier;        // [标识符]指向符号表中标识符地址的指针
////    char*               m_constNum;               // 常量数据
////    char*               m_fileName;           // 文件名
////    int                 m_keyCode;              // [关键字]关键字的编码
////}TupleData;
////
////typedef struct TupleNode
////{
//////    //TupleInfo          m_data;        // 词法信息的数据域
//////    TokenKind          m_kind;        // 词法信息的种别码
//////    Coord              m_coord;       // 词法二元组的行标识
//////
//////    char*               m_identifier;        // [标识符]指向符号表中标识符地址的指针
//////    char*               m_constNum;               // 常量数据
//////    char*               m_fileName;           // 文件名
//////    int                 m_keyCode;              // [关键字]关键字的编码
////    struct TupleData    m_data;
////    struct TupleNode    *m_next;        // 词法信息中指向下一个结点的指针域
////}TupleNode;

/// 存放C语言词法信息的二元组
typedef TupleNode* BinaryTuple;


#define TUPLE_MAGIC_NUM "ctools.tup"    // 存储词法信息的*.tup的文件魔数信息
#
#
#ifdef PUBLIC_and_PRIVATE
#
#
/// 初始化二元组信息
PUBLIC BinaryTuple
InitTuple(
          const char* sourFile);
#define init_tuple  InitTuple
#
#
/// 将一个关键字信息插入到二元组中
PUBLIC TupleNode*
InsertTupleKey(
               TupleNode *pNode,                   // 当前处理文件的二元组信息结点
               TokenKind kind,                     // 待处理关键字的种类[关键字，运算符]
               int keyCode,                       // 待处理关键字的编码信息
               Coord *coord);                     // 词法信息在源文件中的位置标识
#define insert_tuple_key  InsertTupleKey
#
#
/// 将一个常量信息插入到二元组中
PUBLIC TupleNode*
InsertTupleLiteral(
                   TupleNode    *pNode,                // 当前处理文件的二元组信息结点
                   char         *token,                    // 待处理的常量字符串
                   Coord        *coord,                 // 词法信息在源文件中的位置标识
                   TokenKind     kind);                // 用于标识当前常量信息的种类是

#define insert_tuple_literal  InsertTupleLiteral
#
#
/// 将一个标识符插入到二元组中
PUBLIC TupleNode*
InsertTupleId(TupleNode     *pNode,                     // 当前处理文件的二元组信息结点
                char          *token,                          // 待处理的标识符字符串信息
                Coord         *coord);                       // 词法信息在源文件中的位置标识
#define insert_tuple_id   InsertTupleId
#
#
PUBLIC TupleNode*
InsertEndToken(TupleNode *pNode);                       // 在词法二元组链表的最后添加上终结标识
#
#
/// 遍历词法二元数组
PUBLIC void
VisitTuple(
           BinaryTuple douTuple);                   // 二元组信息[二元组结点的指针头]
#define visit_tuple VisitTuple                 // 提供C命名方式的函数调用接口
#
#
/// 清除词法二元组信息
PUBLIC bool
DestroyTuple(
             BinaryTuple douTuple);
#define  destroy_tuple DestroyTuple                 // 提供C命名方式的函数调用接口
#
#
/// 将词法二元组信息填进去制定的文件中
PUBLIC void
WriteTupleFile(
               BinaryTuple douTuple,
               char *fname);           // 待处理的词法文件
#define wrire_tuple_file    WriteTupleFile       // 提供C命名方式的函数调用接口
#
#
/// 从指定文件中读取词法二元组信息
PUBLIC BinaryTuple
ReadTupleFile(char *fname);           // 待处理的词法文件
#define read_tuple_file    WriteTupleFile       // 提供C命名方式的函数调用接口
#
#
#
#
/// 输出每个二元组Node结点的信息
PUBLIC void
ShowNode(
         TupleNode *pNode);                         // 二元组信息[二元组结点指针]
#define  show_node   ShowNode                   // 提供C命名方式的函数调用接口
#
#
// 输出每个二元组Node结点的数据域信息
PUBLIC void
ShowTupleData(
                   TupleNode *pNode);
#
#
// 在以pNode为起始的词法二元组链表中，正向找到数据为终结符treinal的结点
PUBLIC TupleNode*
FindFirstTupleTreinal(
                 TupleNode *headTupleNode,          // 起始的词法链表指针
                 TokenKind treinal);        // 终结符信息
#
#
// 在以pNode为起始的词法二元组链表中， 正向查找到找到第count个数据为终结符terinal的结点
PUBLIC TupleNode*
FindTupleTreinal(
                 TupleNode *headTupleNode,          // 起始的词法链表结点指针
                 TokenKind terinal,         // 待查找的终结符信息
                 int count);                 // 待查找的终结符是链表中第count个终结符
#
#
// 在pNode结尾的词法二元组串中，反向查找到第一个符号是terinal的词法二元组结点
PUBLIC TupleNode*
ReFindFirstTupleTreinal(TupleNode *finalTupleNode,           // 收尾的词法结点指针
                        TokenKind terinal);         // 待查找的终结符信息
#
#
// 在以pNode结尾的词法二元组链表串中, 找到第count个符号是terinal的词法二元组
PUBLIC TupleNode*
ReFindTupleTreinal(TupleNode *finalTupleNode,       // 收尾的词法结点指针
                   TokenKind terinal,      // 待查找的终结符信息
                   int count);              // 待查找的终结符是链表中第count个终结符
#
#
// 判断当前结点是不是预编译指令
PUBLIC bool
IsProComTupleNode(
                        TupleNode *tupleNode);
#endif


#endif // TUPLE_H_INCLUDED




