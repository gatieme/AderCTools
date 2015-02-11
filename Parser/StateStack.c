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



#include "..\Parser\StateStack.h"



/// 构建初始的栈信息
StateStack* CreateStateStack( )
{
    StateStack *stack = malloc(sizeof(StateStack));           // 开辟栈地址空间

    stack->m_top = NULL;            // 构造栈顶指针
    stack->m_count = 0;

    return stack;
}


/// 销毁Stack栈信息
void DestroyStateStack(StateStack *stack) // 待销毁的栈信息
{
    #ifdef PARSER_SHOWS_DEFINE
    printf("当前栈中元素数目%d\n", stack->m_count);
    #endif

    while(stack->m_count > 0)
    {
        PopState(stack);     // 弹出
    }

    free(stack);        // 清空地址信息
}

/// pandaun当前栈是不是空栈
bool EmptyStateSatck(StateStack *stack)   // 栈信息
{
    return (stack->m_count == 0 && stack->m_top == NULL);
}


/// 将元素elem压入栈中
bool PushState(StateStack *stack, State state)
{

    if(EmptyStateSatck(stack) == true)
    {
        CreateStateStack(stack);
    }

    StateNode *newNode = NULL;
    if((newNode = (StateNode *)malloc(sizeof(StateNode))) != NULL)     // 开辟新空间
    {//□□→→■■→→□□
        // 建立栈的结点联系
        newNode->m_state = state;     // 新结点的数据域
        newNode->m_next = stack->m_top;     // 将栈顶元素作为新建立结点的后继
        stack->m_top = newNode;             // 新建立的结点作为新栈顶
        // 增加栈的元素个数
        stack->m_count++;                   // 栈元素个数进1

        #ifdef PARSER_SHOWS_DEFINE
        printf("将状态%d压入栈中, 地址%p\n", state, newNode);
        printf("当前状态栈中元素数目%d\n", stack->m_count);
        #endif      // PARSER_SHOWS_DEFINE

        return true;
    }
    else      // 开辟空间失败
    {
        fprintf(stderr, "内存不足, 开辟栈空间失败\n");
        return false;
    }

    return false;
}


/// 将栈顶数据弹出
State PopState(StateStack *stack)
{
    StateNode *oldTop;
    State elem;      //

    if(EmptyStateSatck(stack) != true)        // 不能对空栈进行弹出操作
    {
        oldTop = stack->m_top;       // 保存原来栈顶
        elem = oldTop->m_state;       // 保存将要弹出的数据
        stack->m_top = oldTop->m_next;   // 将结点弹出
        free(oldTop);                // 删除就栈顶的空间
        stack->m_count--;           // 栈中元素个数减少1

        #ifdef PARSER_SHOWS_DEFINE
        printf("将%d弹出栈中, 地址%p\n", elem, oldTop);
        printf("当前状态栈中元素数目%d\n", stack->m_count);
        #endif  // PARSER_SHOWS_DEFINE
    }
    else
    {
        fprintf(stderr,"%d, 当前状态栈为空, 不能执行弹出操作\n", __LINE__);
        elem = (State)EOF;
    }
    return elem;
}

/// 将栈顶数据弹出
void PopedState(StateStack *stack, int count)
{
    #ifdef PARSER_SHOWS_DEFINE
    printf("将从状态栈中弹出%d个数据\n", count);
    #endif  // PARSER_SHOWS_DEFINE
    while(count--)          // 循环弹出count个数据
    {
        PopState(stack);         // 弹出栈顶数据
    }
}


/// 返回栈顶元素的下一个元素的信息
State NextState(StateStack *stack)
{
    if(stack->m_count <= 1)
    {
        return (State)EOF;
    }
    else
    {
        return (State)stack->m_top->m_next->m_state;           // 返回栈顶下一个位置的数据信息
    }

    return (State)EOF;               //
}



/// 返回栈顶的数据信息
State TopState(StateStack *stack)  // 返回栈的栈顶数据
{
    return (State)(stack->m_top->m_state);      // 返回栈顶的数据
}



/// 显示当前状态栈中的数据信息
void ShowStateStack(StateStack *stack)
{
    printf("******************************\n");
    printf("**\tStateStack  %02d\t**\n", stack->m_count);
    StateNode *pNode = stack->m_top;
    for(int i = 0; pNode != NULL; i++)
    {
        printf("**%02d -=> (%03d, %p)**\n", i, pNode->m_state, pNode);
        pNode = pNode->m_next;
    }
    printf("******************************\n\n");
}

