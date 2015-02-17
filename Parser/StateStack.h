/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Buffer.h                                                       *
*   Description: CTools-SyntacicParser                                          *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/


/*
描述：
    SatetSatck分析栈用于在LR语法分析阶段存储语法状态的词法信息
*/


#ifndef STATESTACK_H_INCLUDED
#define STATESTACK_H_INCLUDED





#include "Config.h"     //  #include "..\Config\Config.h"


/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif



typedef struct StateNode
{
    State               m_state;            // 栈中的数据
    struct StateNode*    m_next;   // 下一个结点的指针
}StateNode;



typedef struct StateStack
{
    StateNode*          m_top; // 栈顶信息
    int                 m_count;        // 元素个数信息标识
}StateStack;



#ifdef PUBLIC_and_PRIVATE
#
#
/// 初始化stack栈信息
PUBLIC StateStack*           // 返回建立的占空间的地址
CreateStateStack( );
#
/// Stack的收尾工作
PUBLIC void
FinitStateStack(StateStack *stack);   // 清除头指针信息
#
/// 销毁Stack栈信息
PUBLIC void
DestroyStateStack(StateStack *stack); // 待销毁的栈信息
#
/// 将元素elem压入栈中
PUBLIC bool             // 压入成功或者失败
PushState(StateStack *stack,  // 栈信息
     State elem);    // 要压入的数据信息
#
/// 将栈顶数据弹出
PUBLIC State           // 弹出成功或者失败
PopState(
         StateStack *stack);   // 栈信息
#
/// 将栈顶数据弹出
PUBLIC void             // 弹出成功或者失败
PopedState(
           StateStack *stack,   // 栈信息
           int count);     // 要弹出的数据的个数
#
/// pandaun当前栈是不是空栈
PUBLIC bool           // 弹出成功或者失败
EmptyStateStack(
                StateStack *stack);   // 栈信息
#
/// 返回栈顶的数据信息
PUBLIC State
TopState(
         StateStack *stack);  // 返回栈的栈顶数据
#
PUBLIC State
NextState(
          StateStack *stack); // 返回栈顶元素的下一个元素的信息
#
#
/// 显示当前状态栈中的数据信息
PUBLIC void
ShowStateStack(
               StateStack *stack);      // 待显示的状态栈的数据
#
#
#endif



#endif // STATESTACK_H_INCLUDED
