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



#include "Syntax.h"




/// 构建初始的栈信息
SyntaxStack* CreateSyntaxStack( )
{
    SyntaxStack *stack = malloc(sizeof(SyntaxStack));           // 开辟栈地址空间

    stack->m_top = NULL;            // 构造栈顶指针
    stack->m_count = 0;

    return stack;
}


/// 销毁Stack栈信息
void DestroySyntaxStack(SyntaxStack *stack) // 待销毁的栈信息
{
    #ifdef PARSER_SHOWS_DEFINE
    printf("当前栈中元素数目%d\n", stack->m_count);
    #endif

    while(stack->m_count > 0)
    {
        PopSyntax(stack);     // 弹出
    }

    free(stack);        // 清空地址信息
}

/// 将pNode所指向的词法信息结点压入分析栈中
bool PushTupleInSyntaxStack(SyntaxStack *stack, TupleNode *tupleNode)
{
    if(EmptySyntaxStack(stack) == true)
    {
        CreateSyntaxStack(stack);
    }
    SyntaxStackNode *newNode = NULL;

    if((newNode = (SyntaxStackNode *)malloc(sizeof(SyntaxStackNode))) != NULL)
    {//□□→→■■→→□□
        // 结点数据域赋值
        newNode->m_syntax.m_kind = SYNTAX_TERR_TERINAL;     // 指向词法信息的结点都是终结符号
        newNode->m_syntax.m_data.m_tupleNode = tupleNode;        // 新结点的数据域
        newNode->m_syntax.m_startCoord = tupleNode->m_tuple.m_coord;
        newNode->m_syntax.m_endCoord = tupleNode->m_tuple.m_coord;

        // 语法树结点指针域初始化
        newNode->m_parent = NULL;
        newNode->m_finalChild = NULL;
        newNode->m_leftBrother = NULL;
        newNode->m_firstChild = NULL;
        newNode->m_rightBrother = NULL;

        // 建立栈的结点联系
        newNode->m_next = stack->m_top;     // 将栈顶元素作为新建立结点的后继
        stack->m_top = newNode;             // 新建立的结点作为新栈顶
        // 增加栈的元素个数
        stack->m_count++;                   // 栈元素个数进1

        //ShowSyntaxTreeNode(newNode->m_syntax);

        #ifdef PARSER_SHOWS_DEFINE
        printf("将终结符%d压入分析栈中, 地址%p  %p\n", newNode->m_syntax.m_data.m_tupleNode->m_tuple.m_kind, newNode, stack->m_top);
        printf("当前分析栈中元素数目%d\n", stack->m_count);
        #endif
        return true;
    }
    else      // 开辟空间失败
    {
        fprintf(stderr, "内存不足, 开辟栈空间失败\n");
        return false;
    }

    return false;
}
/// 将kind 所描述的文法变量数据压入分析栈中
bool PushGrammarInSyntaxStack(SyntaxStack *stack, SyntaxKind syntax)    // 语法变量信息
{
    if(EmptySyntaxStack(stack) == true)
    {
        CreateSyntaxStack(stack);
    }

    SyntaxStackNode *newNode = NULL;
    if((newNode = (SyntaxStackNode *)malloc(sizeof(SyntaxStackNode))) != NULL)
    {//□□→→■■→→□□
        // 栈的结点数据域赋值
        newNode->m_syntax.m_kind = SYNTAX_TERR_VARIBALE;     // 指向词法信息的结点都是语法变量
        newNode->m_syntax.m_data.m_syntaxKind = syntax;        // 新结点的数据域
        // 语法树结点指针域初始化
        newNode->m_parent = NULL;
        newNode->m_finalChild = NULL;
        newNode->m_leftBrother = NULL;
        newNode->m_firstChild = NULL;
        newNode->m_rightBrother = NULL;

        // 建立栈的结点联系
        newNode->m_next = stack->m_top;     // 将栈顶元素作为新建立结点的后继
        stack->m_top = newNode;             // 新建立的结点作为新栈顶

        // 增加栈的元素个数
        stack->m_count++;                   // 栈元素个数进1

        //ShowSyntaxTreeNode(newNode->m_syntax);

        #ifdef PARSER_SHOWS_DEFINE
        printf("将文法符%d压入分析栈中, 地址%p\n", (int)syntax, newNode);
        printf("当前分析栈中元素数目%d\n", stack->m_count);
        #endif
        return true;
    }
    else      // 开辟空间失败
    {
        fprintf(stderr, "内存不足, 开辟栈空间失败\n");
        return false;
    }

    return false;
}





bool PushSynTreeNodeInSynStack(SyntaxStack *stack, SyntaxTreeNode *syntaxNode)
{
    if(EmptySyntaxStack(stack) == true)
    {
        CreateSyntaxStack(stack);
    }

    SyntaxStackNode *newNode = NULL;
    if(syntaxNode != NULL)
    {//□□→→■■→→□□
        // 栈的结点数据域赋值
        newNode = syntaxNode;

        // 建立栈的结点联系
        newNode->m_next = stack->m_top;     // 将栈顶元素作为新建立结点的后继
        stack->m_top = newNode;             // 新建立的结点作为新栈顶

        // 增加栈的元素个数
        stack->m_count++;                   // 栈元素个数进1
        //ShowSyntaxTreeNode(newNode->m_syntax);
        #ifdef PARSER_SHOWS_DEFINE
        if(syntaxNode->m_syntax.m_kind == SYNTAX_TERR_VARIBALE)
        {
        printf("将文法符%d压入分析栈中, 地址%p\n", newNode->m_syntax.m_data.m_syntaxKind, newNode);
        }
        else
        {
            printf("将终结符%d压入分析栈中, 地址%p  %p\n", newNode->m_syntax.m_data.m_tupleNode->m_tuple.m_kind, newNode, stack->m_top);
        }
        printf("当前分析栈中元素数目%d\n", stack->m_count);
        #endif
        return true;
    }
    else      // 开辟空间失败
    {
        fprintf(stderr, "内存不足, 开辟栈空间失败\n");
        return false;
    }

    return false;
}

/// 将元素Syntax压入栈中
bool PushSyntax(SyntaxStack *stack, Syntax syntax)
{

    return PushSynTreeNodeInSynStack(stack, syntax);
}



/// 将栈顶数据弹出
bool PopSyntax(SyntaxStack *stack)
{

    //Syntax Syntax = (Syntax)NULL;      //
    if(EmptySyntaxStack(stack) != true)        // 不能对空栈进行弹出操作
    {
        #ifdef PARSER_SHOWS_DEFINE
        if(stack->m_top->m_syntax.m_kind == SYNTAX_TERR_TERINAL)
        {
            printf("将终结符%d弹出分析栈中, 地址%p\n", stack->m_top->m_syntax.m_data.m_tupleNode->m_tuple.m_kind, stack->m_top);
        }
        else
        {
            printf("将文法符%d弹出分析栈中, 地址%p\n", stack->m_top->m_syntax.m_data.m_syntaxKind, stack->m_top);
        }
        printf("当前分析栈中元素数目%d\n", stack->m_count - 1);
        #endif

        SyntaxStackNode *oldTop;
        oldTop = stack->m_top;       // 保存原来栈顶
        //Syntax = oldTop->m_syntax;       // 保存将要弹出的数据
        stack->m_top = oldTop->m_next;   // 将结点弹出
        //free(oldTop);                // 删除就栈顶的空间
        stack->m_count--;           // 栈中元素个数减少1
    }
    else
    {
        fprintf(stderr,"%d, 当前分析栈为空, 不能执行弹出操作\n", __LINE__);
        ///////////////////////////////////////////////////////////////////////////////
        //Syntax = (Syntax)EOF;/////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        return false;
    }
    return true;
}

/// 将栈顶数据弹出
void PopedSyntax(SyntaxStack *stack, int count)
{
    #ifdef PARSER_SHOWS_DEFINE
    printf("将从分析栈中弹出%d个数据\n", count);
    #endif

    while(count--)          // 循环弹出count个数据
    {
        PopSyntax(stack);         // 弹出栈顶数据
    }
}


/// 返回栈顶元素的下一个元素的信息
Syntax NextSyntax(SyntaxStack *stack)
{
    return stack->m_top->m_next;
}


/// 获取栈离栈顶step个元素的数据信息
Syntax GetSyntax(SyntaxStack *stack, int step)           // 返回栈顶元素的下一个元素的信息
{
    if(step < 0 || step >= stack->m_count)
    {
        return (Syntax)NULL;
    }
    // 找到离栈顶距离为step的语法节点信息
    int i = 0;
    SyntaxStackNode* syntaxStackNode = stack->m_top;

    while(i < step)
    {
        syntaxStackNode = syntaxStackNode->m_next;
        i++;
    }

    return (Syntax)syntaxStackNode;           // 返回当前占栈中的数据域
}

/// pandaun当前栈是不是空栈
bool EmptySyntaxStack(SyntaxStack *stack)   // 栈信息
{
    return (stack->m_count == 0 && stack->m_top == NULL);
}

/// 返回栈顶的数据信息
Syntax TopSyntax(SyntaxStack *stack)  // 返回栈的栈顶数据
{
    return (Syntax)(stack->m_top);      // 返回栈顶的数据
}


void ShowSyntaxStack(SyntaxStack *stack)
{
    printf("**********************************\n");
    printf("**\tSyntaxStack  %04d\t**\n", stack->m_count);

    SyntaxStackNode *pNode = stack->m_top;

    for(int i = 0; pNode != NULL; i++)
    {
        printf("**\t");
        ShowSyntaxTreeNode(pNode);
        pNode = pNode->m_next;
        printf("\t**\n");
    }

    printf("**********************************\n\n");
}
