#include "Syntax.h"


// 初始化当前语法队列
SyntaxQueue* CreateSyntaxQueue( )
{
    SyntaxQueue *queue = NULL;

    if((queue = malloc(sizeof(SyntaxQueue))) == NULL)
    {
        fprintf(stderr, "malloc ERROR\n");
    }

    queue->m_front = NULL;
    queue->m_rear = NULL;
    queue->m_count = 0;

    return queue;
}


// 判断当前语法队列是否为空
bool EmptySyntaxQueue(SyntaxQueue *queue)
{
    return (queue->m_count == 0);
}
//#define EmptySyntaxQueue(queue)     ((queue)->m_count == 0)

// 将语法数据压入语法队列
void InSyntaxQueue(SyntaxQueue *queue, SyntaxTreeNode *node)
{
    if(EmptySyntaxQueue(queue) == true)
    {
        queue->m_front = node;
        queue->m_rear = node;
        node->m_next = NULL;
    }
    else
    {
        queue->m_rear->m_next = node;
        queue->m_rear = node;
        node->m_next = NULL;
    }
    queue->m_count++;
}


// 将语法数据弹出语法队列
SyntaxTreeNode* OutSyntaxQueue(SyntaxQueue *queue)
{
    SyntaxTreeNode *node = NULL;

    if(EmptySyntaxQueue(queue) == true)
    {
        fprintf(stderr, "当前语法队列为空, 无法将队头数据弹出\n");
    }
    else
    {
        node = queue->m_front;
        queue->m_front = node->m_next;
        queue->m_count--;
    }
    return node;
}
