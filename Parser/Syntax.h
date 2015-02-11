#ifndef SYNTAX_H_INCLUDED
#define SYNTAX_H_INCLUDED


#include "..\Config\Config.h"

#include "..\Lexical\Lexical.h"

#include "..\Lexical\BinaryTuple.h"            // 词法二元组

#include "..\Parser\StateStack.h"

#include "..\Parser\SyntaxTable.h"
#include "..\Parser\Grammar.h"





/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif





/// 用于标识当前节点信息类型的数据域
typedef enum SyntaxTreeKind
{
    SYNTAX_TREE_NULL                    =   00,
    SYNTAX_TERR_STARTER                 =   01,               // 文法开始符号 [开始符号]
    SYNTAX_TERR_VARIBALE                =   02,               // 语法变量     [非终结符号]
    SYNTAX_TERR_TERINAL                 =   03,                // 语法终结符号 [终结符号]
}SyntaxTreeKind;


typedef union SyntaxTreeInfo
{
    TupleNode*              m_tupleNode;        // 终结符结点指向的
    SyntaxKind              m_syntaxKind;          // 当前结点信息是语法变量
}SyntaxTreeInfo;


typedef struct SyntaxData
{
    SyntaxTreeKind          m_kind;                 // 标识当前树结点的种类
    // 如果kind == SYN_ANA_TERR_VARIBALE, 则m_data == m_synaAna
    // 如果kind == SYN_ANA_TERR_TERINAL,  则m_data == m_tupleNode
    SyntaxTreeInfo          m_data;                 // 语法树结点的数据域信息
    Coord                   m_startCoord;                // 当前语法信息的开始位置
    Coord                   m_endCoord;                  // 当前语法信息的结束位置
    //Coord                   m_coord;                // 语法树结点的位置信息
}SyntaxData;




/// 语法结点
typedef struct SyntaxTreeNode
{
    // 语法结点数据域
    SyntaxData           m_syntax;           // 语法分析树结点数据域信息

    // 语法树指针数据源
    struct SyntaxTreeNode*  m_parent;           // 指向父亲结点的指针域
    struct SyntaxTreeNode*  m_firstChild;       // 指向孩子结点的指针域
    struct SyntaxTreeNode*  m_rightBrother;     // 指向右边第一个兄弟
    struct SyntaxTreeNode*  m_finalChild;       // 指向最后一个孩子结点的指针域
    struct SyntaxTreeNode*  m_leftBrother;      // 指向左边第一个兄弟结点

    // 语法栈或者语法队列数据域
    struct SyntaxTreeNode*  m_next;             // 指向下一个结点的数据域
}SyntaxTreeNode, SyntaxStackNode, SyntaxQueueNode;


typedef SyntaxTreeNode*           Syntax;                   // 语法信息
typedef SyntaxTreeNode*           SyntaxTree;             // 语法分析树

/// 语法分析栈
typedef struct SyntaxStack
{
    SyntaxStackNode*     m_top; // 栈顶信息
    int                  m_count;        // 元素个数信息标识
}SyntaxStack;

/// 语法树分析队列
typedef struct SyntaxQueue
{
    SyntaxQueueNode     *m_front;           // 语法队列头
    SyntaxQueueNode     *m_rear;            // 语法对列尾
    int                  m_count;          // 语法队列
}SyntaxQueue;

#ifdef PUBLIC_and_PRIVATE
#
#
/// 语法分析栈函数信息-BEGIN/////////////////////////////////////////////////////////////////////////////////////////////////////
/// 初始化stack栈信息
PUBLIC SyntaxStack*           // 返回建立的占空间的地址
CreateSyntaxStack( );
#
#
/// Stack的收尾工作
PUBLIC void
FinitSyntaxStack(SyntaxStack *stack);   // 清除头指针信息
#
#
/// 销毁Stack栈信息
PUBLIC void
DestroySyntaxStack(SyntaxStack *stack); // 待销毁的栈信息
#
#
/// 将词法信息结点压入栈中
PUBLIC bool
PushTupleInSyntaxStack(                      // 将词法信息结点压入栈中
                      SyntaxStack *stack,   // 语法分析栈
                      TupleNode *pNode);    // 词法信息的结点
#
#
/// 将语法变量压入分析栈中
PUBLIC bool
PushGrammarInSyntaxStack(                     // 将语法变量压入分析栈中
                        SyntaxStack *stack,  // 语分析栈的信息
                        SyntaxKind kind);    // 语法变量信息
#
#
/// 将元素elem压入栈中
PUBLIC bool             // 压入成功或者失败
PushSyntax(SyntaxStack *stack,  // 栈信息
     Syntax syntax);    // 要压入的数据信息
#
#
/// 将栈顶数据弹出
PUBLIC bool           // 弹出成功或者失败
PopSyntax(SyntaxStack *stack);   // 栈信息
#
#
/// 将栈顶数据弹出
PUBLIC void             // 弹出成功或者失败
PopedSyntax(SyntaxStack *stack,   // 栈信息
    int count);     // 要弹出的数据的个数
#
#
/// pandaun当前栈是不是空栈
PUBLIC bool           // 弹出成功或者失败
EmptySyntaxStack(SyntaxStack *stack);   // 栈信息
#
#
/// 返回栈顶的数据信息
PUBLIC Syntax
TopSyntax(SyntaxStack *stack);  // 返回栈的栈顶数据
#
#
/// 返回栈顶的下一个数据信息
PUBLIC Syntax
NextSyntax(SyntaxStack *stack);
#
#
/// 获取栈离栈顶step个元素的数据信息
PUBLIC Syntax
GetSyntax(SyntaxStack *stack,
           int step);           // 返回栈顶元素的下一个元素的信息
#
#
/// 语法分析栈函数信息-ENDLS/////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
///
///
/// 语法分析树函数信息-NEGIN/////////////////////////////////////////////////////////////////////////////////////////////////////
/// 依据第id个文法信息建立语法子树
/// 初始化语法结点
PUBLIC SyntaxTree
CreateSyntaxTree( );
#
#
/// 销毁语法分析树
PUBLIC void
DestroySyntaxTree(
                  SyntaxTree root);
#
#
PUBLIC void
DeleteSyntaxTreeNode(
                     SyntaxTreeNode *node);
#
#
PUBLIC SyntaxTree
InsertSyntaxTree(
           SyntaxStack *stack,           // 语法分析栈
           int id);                     // 归约的文法产生式编号
#
#
// 获取以root为根的语法树的高度
PUBLIC int
GetSyntaxTreeHeight(
                    SyntaxTree root);       // 语法树的根
#
#
// 获取以root为根的语法树的结点个数
PUBLIC  int
GetSyntaxTreeNodeCount(
                       SyntaxTree root);      // 语法树的根
#
#
// 先序遍历以root为根的语法树
PUBLIC void
PreOrderSytaxTree(
                  SyntaxTree root);                 // 语法树的根

#
#
// 中序遍历以root为根的语法树
PUBLIC void
InOrderSyntaxTree(
                  SyntaxTree root);                 // 语法树的根
#
#
// 后序遍历以root为根的语法树
PUBLIC void
PostOrderSyntaxTree(SyntaxTree root);                   //  语法树的根
#
#
// 显示当前语法信息的值
PUBLIC void
ShowSyntaxTreeNode(
                   SyntaxTreeNode *pNode);                        // 显示当前语法树结点的值
#
#
// 采用中序对语法树做done操作
PUBLIC void
InOrderDoneSyntaxTree(
                        SyntaxTree root,                        // 语法树的根
                        void (*Done)(void *));                  // 希望采取的操作
#
#
// 在以parentRoot为根的语法子树中找到终结符treinal的位置
PUBLIC TupleNode*
FindFirstSyntaxTreeTreinal(
                           SyntaxTree parentRoot,
                           TokenKind treinal);
#
#
// 在以parentRoot为根的语法子树中找到第一个叶子节点的词法结点指针域
PUBLIC TupleNode*
FindFirstChildTuple(
                    SyntaxTree parentRoot);
#
#
// 在以parentRoot为根的语法子树中找到第一个是终结符的叶子节点
PUBLIC SyntaxTreeNode*
FindFirstChildTreeNode(
                       SyntaxTree parentRoot);
#
#
// 在以parentRoot为根的语法子树中找到最后一个是终结符的叶子节点
PUBLIC SyntaxTreeNode*
FindFinalChildTreeNode(
                        SyntaxTree parentRoot);
#
#
// 在以parentRoot为根的语法子树中找到第一个是终结符的叶子节点
PUBLIC TupleNode*
FindFinalChildTupleNode(
                        SyntaxTree parentRoot);
/// 语法分析树函数信息-ENDLS/////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
///
///
/// 语法分析栈函数信息-BEGIN/////////////////////////////////////////////////////////////////////////////////////////////////////
#
#
// 初始化当前语法队列
PUBLIC SyntaxQueue*
CreateSyntaxQueue( );
#
#
// 判断当前语法队列是否为空
PUBLIC bool
EmptySyntaxQueue(SyntaxQueue *queue);
#
#
// 将语法数据压入语法队列
PUBLIC void
InSyntaxQueue(SyntaxQueue *queue,
              SyntaxTreeNode *node);
#
#
// 将语法数据弹出语法队列
PUBLIC SyntaxTreeNode*
OutSyntaxQueue(
               SyntaxQueue *queue);                 // 语法队列
#
#
#endif      // PUBLIC_and_PRIVATE





#endif // SYNTAX_H_INCLUDED
