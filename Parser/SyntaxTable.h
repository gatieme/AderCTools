/***********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe
*   File Name  : Buffer.h
*   Description: CTools-SyntacicParser
*   Author     : Gatie_Me
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-3-10 21:29:24
*   Content    : CTools-Lexical
***********************************************************************************/


/*
描述：
    SyntaxTable用于在语法分析阶段存储LR(1)语法分析表
*/


#ifndef SYNTAXTABLE_H_INCLUDED
#define SYNTAXTABLE_H_INCLUDED


#include "Config.h"     //  #include "..\Config\Config.h"

#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"
#include "SyntaxKind.h"    //  #include "..\Parser\SyntaxKind.h"
#include "BinaryTuple.h"   //  #include "..\Lexical\BinaryTuple.h"
/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif



#define RECEIVE_SIZE





/// 动作指示标识
typedef enum ActionFlag
{
    ACTION_NULL =   -2,
    ERRORS      =   -1,         // 出错信息
    ACCEPT      =    0,          // 移进
    MOVING      =    1,         // 移进
    REDUCTION   =    2,      // 归约
}ActionFlag;




typedef struct ActionNode
{
    //int     state;                    // 当前状态
    TokenKind       m_received;             // 当前读取词法信息
    ActionFlag      m_action;               // 转移MOVE状态
    SyntaxKind      m_nonter;               // 读取移近的终结信息
    State           m_actState;             //  移近后转移到新状态
}ActionNode;



typedef struct GoToNode
{
    //int             m_state;            // 当前状态
    SyntaxKind 	    m_receive;          // 当前读取
    State 	        m_gotoState;             // 跳转到的新状态
}GoToNode;

/// Literal的函数声明部分
#ifdef PUBLIC_and_PUBLIC
#
#
// ACTION函数检索语法分析表的信息
PUBLIC ActionNode*                  // 返回指向动作信息的指针
ACTION(
       State state,                 // 当前状态
       TupleNode *tupleNode);       // 读取到的词法信息
// ACTION函数检索语法分析表的信息
PUBLIC GoToNode*                    // 返回指向gotoTable的指针
GOTO(
     int state,                     // 当前状态
     SyntaxKind  receive);          // 当前遇见的文法符号
#
#

#endif


#endif // SYNTAXTABLE_H_INCLUDED
