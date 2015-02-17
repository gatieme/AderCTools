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





#ifndef LITERALTABLE_H_INCLUDED
#define LITERALTABLE_H_INCLUDED



#include "TokenKind.h"


#define UNKNOWVALUE -1
#define CON_ERROR   -1    // 常量错误

/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif



/*typedef struct Literal
{
    Kind m_kind;          // 标识当前常量文字信息的种别
//    union               // 标识常量数据的联合体
//    {
//        int m_intValue;             // 整数
//        long m_longValue;           // 长整型
//        long long m_llongValue;     // 长长整形
//
//        float m_floatValue;         // 浮点数常量
//        double m_douValue;          // 双精度浮点数常量
//        long double m_ldouValue;    // 长双精度浮点数常量
//        char m_charValue;           // 字符常量
//        //wchar_t m_wcharValue;       // 宽字符常量
//        char *m_strValue;              // 字符串常量
//    }m_data;            // 数据信息
    char *m_data;         // 数据信息
    int m_offset;               // 相对地址
    struct Literal *m_next;   // 指向下一个信息的地址的指针
}Literal;*/


typedef struct Literal
{
    TokenKind       m_kind;          // 标识当前常量文字信息的种别
    char*           m_data;         // 数据信息
    int             m_offset;               // 相对地址
    struct Literal* m_next;   // 指向下一个信息的地址的指针
}Literal;


// 常量表为一个链表信息
/// 符号表数据结构[HashTable]
//typedef struct LiteralTable
//{
//    Literal **m_hashTable;        // 符号哈希表
//}LiteralTable;       // 符号表
typedef Literal** LiteralTable;





#ifdef PUBLIC_and_PRIVATE
#
#
// 将表示token添加进入符号表
PUBLIC Literal*
InsertLiteralToken(char *token,
                   LiteralTable literTable);
#define insert_literal_token  InsertLiteralToken
#
#
// 查询token是否在符号表中
PUBLIC Literal*
FindLiteralToken(char *token,
                 LiteralTable literTable);
#define find_literal_token    FindLiteralToken
#
#
#endif


#endif // LITERALTABLE_H_INCLUDED
