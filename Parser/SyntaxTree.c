/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : SyntaxTree.c                                                   *
*   Description: CTools-SyntacicParser                                          *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/


///-//////////////////////////////////////////////////////////////////////////////////////-///
/// 本文件系AderCTools编译器语法分析树函数接口实现文件                                          ///
/// 添加时间2013-7-21   15:16                                                               ///
/// 编码：GatieMe                                                                           ///
/// 版本0.3.3添加                                                                           ///
///-//////////////////////////////////////////////////////////////////////////////////////-///



#include "Syntax.h"               // 语法树结点信息


/*
*   本程序在归约过程中建立语法树的思路是， 在树的最高层建立一个总根
*   在归约的过程中，
*
*
*
*/


/** 初始化新的语法树信息*************************************************************************
*   Function	 :  CreateSyntaxTree
*   Param		 :
*   Return		 :  返回新建立的语法树根节点信息,想根结点的指针
*   Description:  该函数在语法分析的初始化阶段，进行语法分析树的初始化工作
*   Calls		 :  NULL
*   CalledBy   :
*   Version    :	0.4.0
*   Warning    :
**********************************************************************************************/
SyntaxTree CreateSyntaxTree( )
{
    SyntaxTreeNode* root;               // 当前语法树的结点信息

    if((root = (SyntaxTreeNode *)malloc(sizeof(SyntaxTreeNode))) != NULL)            // 为根节点开辟空间
    {
        printf("语法树头结点%p\n", root);
        PAUSE( );
        root->m_syntax.m_kind = SYNTAX_TERR_STARTER;                              // 语法树的根为开始文法符号
        root->m_syntax.m_data.m_syntaxKind = SYN_STARTER;                              // 文法开始符号表示为SYN_START

        /// 树结点的指针域赋值
        // 双亲的赋值
        root->m_parent = NULL;                  // 根没有双亲结点
        // 最右孩子策略的赋值
        root->m_finalChild = NULL;
        root->m_leftBrother = NULL;
        // 最左孩子策略的赋值
        root->m_firstChild = NULL;
        root->m_rightBrother = NULL;

        root->m_next = NULL;
    }
    else
    {
        fprintf(stderr, "初始化语法树时，  开辟根节点失败\n");
    }

    return root;
}

/** 销毁语法分析树信息***************************************************************************
*   Function	 :  DeleteSyntaxTreeNode
*   Param		 :  root[SYNTAXTREE]待销毁的语法分析树结点的信息.
*   Return		 :  销毁成功返回TRUE,销毁失败返回FALSE
*   Description:  该函数在语法分析的初始化阶段，进行语法分析树的初始化工作
*   Calls		 :  NULL
*   CalledBy   :
*   Version    :	0.4.2
*   Warning    :
**********************************************************************************************/
void DeleteSyntaxTreeNode(SyntaxTreeNode *node)
{
    if(node == (SyntaxTreeNode *)node->m_parent->m_firstChild)        // (node->m_leftBrother == NULL)当前结点是父节点的第一个孩子-=>
    {
        node->m_parent->m_firstChild = node->m_rightBrother;

        node->m_rightBrother->m_leftBrother = NULL/*node->leftBrother = NULL*/;
        //node->m_leftBrother->m_leftBrother = node->m_rightBrother;
    }
    else if(node == node->m_parent->m_finalChild)        // (node->m_rightBrother == NULL)当前结点是父节点的最后一个孩子-=>
    {
        node->m_parent->m_finalChild = node->m_leftBrother;

        node->m_leftBrother->m_leftBrother = NULL/*node->m_rightBrother = NULL*/;
        //node->m_rightBrother->leftBrother = node->m_leftBrother;
    }
    else //if(node->m_rightBrother != NULL)
    {
        node->m_rightBrother->m_leftBrother = node->m_leftBrother;
        node->m_leftBrother->m_leftBrother = node->m_rightBrother;
    }

    free(node);             // 删除结点的空间
}


/** 销毁语法分析树信息***************************************************************************
*   Function	 :  DestroySyntaxTree
*   Param		 :  root[SYNTAXTREE]待销毁的语法分析树结点的信息.
*   Return		 :  销毁成功返回TRUE,销毁失败返回FALSE
*   Description:  该函数在语法分析的初始化阶段，进行语法分析树的初始化工作
*   Calls		 :  NULL
*   CalledBy   :
*   Version    :	0.4.2
*   Warning    :
**********************************************************************************************/
void DestroySyntaxTree(SyntaxTree root)
{
    /// 类似于后序遍历
    if(root != NULL)
    {
        /// 后序遍历语法树
        if(root->m_firstChild != NULL)          // 递归访问其第一个孩子
        {
            DestroySyntaxTree(root->m_firstChild);
        }
        else if(root->m_rightBrother != NULL)
        {
            DestroySyntaxTree(root->m_rightBrother);        // 删除第一个孩子以后递归访问其右边的兄弟
        }

        DeleteSyntaxTreeNode(root);                                     // 删除当前位置，也就是第一个孩子的信息
    }
}






/** 添加第id个产生式的信到语法树*****************************************************************
*   Function	 :  InsertTree
*   Param		 :  root[SyntaxTREE*] 当前待处理的语法树根节点
*                 stack[SyntaxSTACK*]当前语法栈信息，存储了当前处理的词法和文法结点的信息
*                 id[INT]           当前归约的产生式的编号, 可以查找到文法的产生式左右部的信息
*   Return		 :  返回语法子树的根节点信息, 指向子树根结点的指针
*   Description:  该函数在语法分析进行归月的时候调用, 在原语法树中插入一颗语法子树
*              :  将语法分析扎中的信息按照Grammar.c中第id个文法产生式的存储结构,
*                 插入一颗符合当前归约要求的语法子树
*   Calls		 :  NULL
*   CalledBy   :
*   Version    :	0.3.8
*   Warning    :
**********************************************************************************************/
SyntaxTree InsertSyntaxTree(SyntaxStack *stack, int id)
{
#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
assert(stack != NULL                            // 语法分析栈栈顶结点不为空
    && EmptySyntaxStack(stack) != true);         // 语法分析栈不为空
#endif // PARSER_DEBUG_DEFINE

#ifdef PARSER_SHOWS_DEFINE
if( stack == NULL)
{
    fprintf(stderr, "当前语法分析树或者分析栈未初始化, 结点为NULL\n");
    PAUSE( );
    exit(-1);
}

if(EmptySyntaxStack(stack) == true)
{
    fprintf(stderr, "当前分析栈为空, 无法建立语法子树操作");
    PAUSE( );
    exit(-1);
}
#endif // PARSER_SHOWS_DEFINE

/*
*   当你建立需要归约的时候，产生式的右部均位于分析栈的顶部
*   我们只需要在分析栈中建立语法子树之间的父子兄弟结点的练习（由于）
*
*/
    // 提取产生式的信息
    int                      length = RightGrammarLength(id);               // 查询出来当前文法产生式的长度

    //printf("%d头指针地址%p\n", __LINE__, root);

    #ifdef PARSER_SHOWS_DEFINE
    printf("当前归约信息:\n");
    printf("产生式编号:%d", id);
    printf("产生式右部长度:%d\n", length);
    #endif // PARSER_SHOWS_DEFINE

    // 提取和建立语法树结点的信息
    // SyntaxStackNode*         syntaxStackNode = NULL;
    SyntaxTreeNode*/* Syntax */ parentSyntaxNode = NULL;
    SyntaxTreeNode*/* Syntax */ currSyntaxNode = NULL;    // = TopSyntax(stack);             // 取出栈顶的语法信息
    SyntaxTreeNode*/* Syntax */ lastSyntaxNode = NULL;    // = NULL;
    SyntaxTreeNode*/* Syntax */ nextSyntaxNode = NULL;


    // 首先归约时, 建立的语法子树是以文法产生式的左部的文法信息为子树根节点的
    if((parentSyntaxNode = (SyntaxTreeNode *)malloc(sizeof(SyntaxTreeNode))) == NULL)                // 开辟子树根节点的信息
    {
        fprintf(stderr, "malloc ERROR\n");
        exit(-1);
    }
    //printf("******************parentSyntaxNode = %p******************\n", parentSyntaxNode);
    parentSyntaxNode->m_syntax.m_kind = SYNTAX_TERR_VARIBALE;                                    // 产生式左部是文法变量
    parentSyntaxNode->m_syntax.m_data.m_syntaxKind = LeftGrammarData(id);                                 // 产生式左部的文法值

    // 暂时无法获取当前语法树艮结点的兄弟信息，
    parentSyntaxNode->m_rightBrother = NULL;
    parentSyntaxNode->m_leftBrother = NULL;


    // 子树根节点与孩子的联系
    parentSyntaxNode->m_finalChild = GetSyntax(stack, 0);//TopSyntax(stack);            // 子树根结点的最右孩子在栈顶
    parentSyntaxNode->m_firstChild = GetSyntax(stack, length - 1);                       //
    parentSyntaxNode->m_syntax.m_startCoord = parentSyntaxNode->m_firstChild->m_syntax.m_startCoord;
    parentSyntaxNode->m_syntax.m_endCoord = parentSyntaxNode->m_finalChild->m_syntax .m_endCoord;

    //parentSyntaxNode->m_syntax.m_coord =
    // 当前结点在栈中的练习暂时无法确定
    parentSyntaxNode->m_next = NULL;

    /// 进行语法子树叶子结点的赋值
    for(int step = 0; step < length; step++)
    {
        currSyntaxNode = GetSyntax(stack, step);                    // 取出当前语法节点

        if(step == 0)                                               // 第一个语法节点作为子树根的最右孩子节点，其上一个结点为空
        {
            lastSyntaxNode = NULL;
        }
        else                                                        // 否则取出其上一语法节点的信息
        {
            lastSyntaxNode = GetSyntax(stack, step - 1);
        }

        if(step == length - 1)                                      // 最后一个语法节点作为子树的最左孩子，其下一个结点为空
        {
            nextSyntaxNode = NULL;
        }
        else                                                        // 否则取出其下一个语法节点
        {
            nextSyntaxNode = GetSyntax(stack, step + 1);
        }

        currSyntaxNode->m_parent = parentSyntaxNode;                    // 当前结点的双亲结点为新建的双亲结点
        currSyntaxNode->m_leftBrother = nextSyntaxNode;                 // 当前结点的左孩子为其下一个结点
        currSyntaxNode->m_rightBrother = lastSyntaxNode;                // 当前结点的右孩子为其上一个结点

        if(currSyntaxNode->m_syntax.m_kind == SYNTAX_TERR_TERINAL)             // 如果当前结点为终结符号, 其孩子结点为NULL
        {
            currSyntaxNode->m_firstChild = NULL;
            currSyntaxNode->m_finalChild = NULL;
        }

        #ifdef PARSER_DEBUG_DEFINE
        printf("curr = %p, left = %p, right = %p\n", currSyntaxNode, nextSyntaxNode, lastSyntaxNode);
        ShowSyntaxTreeNode(currSyntaxNode);
        printf("\n");
        ShowSyntaxTreeNode(nextSyntaxNode);
        printf("\n");
        ShowSyntaxTreeNode(lastSyntaxNode);
        printf("\n");
        #endif // PARSER_DEBUG_DEFINE

    }
    //printf("******************parentSyntaxNode = %p******************\n", parentSyntaxNode);
    return parentSyntaxNode;                // 返回插入语法子树的父亲结点
}




// 获取以root为根的语法树的高度
int GetSyntaxTreeHeight(SyntaxTree root)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight, rightHeight;
        leftHeight = GetSyntaxTreeHeight(root->m_firstChild);
        rightHeight = GetSyntaxTreeHeight(root->m_rightBrother);

        return 1 + (leftHeight > rightHeight) ? leftHeight : rightHeight;
    }
}


// 获取以root为根的语法树的结点个数
int GetSyntaxTreeNodeCount(SyntaxTree root)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + GetSyntaxTreeNodeCount(root->m_firstChild) + GetSyntaxTreeNodeCount(root->m_rightBrother);
    }
}


// 显示当前语法信息的值
void ShowSyntaxTreeNode(SyntaxTreeNode  *pNode)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    if(pNode != NULL)
    {
        printf("{%03d : ", pNode->m_syntax.m_kind);

        if(pNode->m_syntax.m_kind == SYNTAX_TERR_VARIBALE
           || pNode->m_syntax.m_kind == SYNTAX_TERR_STARTER)           // 当前结点是语法变量，也就是非终结符号
        {
            printf("[%03d, %03d]", pNode->m_syntax.m_kind, pNode->m_syntax.m_data.m_syntaxKind);      // 输出语法变量的编号
        }
        else if(pNode->m_syntax.m_kind == SYNTAX_TERR_TERINAL)       // 当前结点是终结符号
        {
            ShowTupleData(pNode->m_syntax.m_data.m_tupleNode);
        }
        printf("}");
    }
    #ifdef PARSER_DEBUG_DEFINE
    else
    {
        printf("当前语法树结点为空\n");
    }
    #endif // PARSER_DEBUG_DEFINE

}


// 先序遍历以root为根的语法树
void PreOrderSytaxTree(SyntaxTree root)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    SyntaxTreeNode *pNode = root;
    if(pNode != NULL)
    {
        ShowSyntaxTreeNode(pNode);                      // 显示当前根结点信息
        printf("\n");
        PreOrderSytaxTree((SyntaxTree)pNode->m_firstChild);       // 递归当前根结点的
        //printf("孩子完毕\n");
        PreOrderSytaxTree((SyntaxTree)pNode->m_rightBrother);    // 递归当前根的右兄弟
        //printf("兄弟完毕\n");
    }
}

// 中序遍历以root为根的语法树
void InOrderSyntaxTree(SyntaxTree root)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    SyntaxTreeNode *pNode = root;
    //printf("root = %p\n", root);
    //PAUSE( );
    if(pNode != NULL)
    {
        InOrderSyntaxTree((SyntaxTree)pNode->m_firstChild);       // 递归当前根结点的

        ShowSyntaxTreeNode(pNode);                      // 显示当前根结点信息
        printf("\n");
        InOrderSyntaxTree((SyntaxTree)pNode->m_rightBrother);    // 递归当前根的右兄弟
    }
}



// 后序遍历以root为根的语法树
void PostOrderSyntaxTree(SyntaxTree root)
{
#ifdef PARSER_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // PARSER_DEBUG_DEFINE
    SyntaxTreeNode *pNode = root;

    if(pNode != NULL)
    {
        PostOrderSyntaxTree((SyntaxTree)pNode->m_firstChild);       // 递归当前根结点的
        PostOrderSyntaxTree((SyntaxTree)pNode->m_rightBrother);    // 递归当前根的右兄弟
        ShowSyntaxTreeNode(pNode);                      // 显示当前根结点信息
        printf("\n");
    }
}
/// 采用中序对语法树做done操作
void InOrderDoneSyntaxTree(SyntaxTree root, void (*Done)(void *))                  // 希望采取的操作
{
    SyntaxTreeNode *pNode = root;

    if(pNode != NULL)
    {
        PostOrderSyntaxTree((SyntaxTree)pNode->m_firstChild);       // 递归当前根结点的
        (*Done)((void *)pNode);                      // 显示当前根结点信息
        printf("\n");
        PostOrderSyntaxTree((SyntaxTree)pNode->m_rightBrother);    // 递归当前根的右兄弟
    }
}


// 以树状显示语法树-=> 层次遍历语法树
void ShowSyntaxTree(Syntax root)
{
    SyntaxTreeNode *node = NULL;
    SyntaxQueue    *queue = CreateSyntaxQueue( );

    if(root != NULL)            // 如果根为非空, 则将根入队
    {
        InSyntaxQueue(queue, root);
    }

    while(EmptySyntaxQueue(queue) != true)
    {
        node = OutSyntaxQueue(queue);
        /*if(SYN_ENDL)
        {
            printf("\n");
        }*/
        ShowSyntaxTreeNode(node);                   // 显示当前语法树结点的信息

        // 依次将其所有孩子入队
        if(node->m_firstChild != NULL)
        {
            node = node->m_firstChild;
            InSyntaxQueue(queue, node);             // 先将第一个孩子入队

            while(node->m_rightBrother != NULL)     // 依次将第一个孩子的右兄弟即其他孩子入队
            {
                node = node->m_rightBrother;
                InSyntaxQueue(queue, node);
            }
            //InSyntaxQueue(queue, SYN_ENDL);
        }

    }
}





// 在以parentRoot为根的语法子树中找到第一个是终结符的叶子节点
SyntaxTreeNode* FindFirstChildTreeNode(SyntaxTree parentRoot)
{
    SyntaxTreeNode *treeNode = NULL;

    /// 首先先找到语法子树中第一个叶子结点
    treeNode = parentRoot;
    while(treeNode->m_firstChild != NULL)          // 找到第一个终结符编号
    {
        treeNode = treeNode->m_firstChild;
    }

    // 然后找到函数名称的词法结点
    if(treeNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在语法子树中第一个叶子节点不是终结符号\n");
        return NULL;
    }
    else if(treeNode->m_syntax.m_kind == SYNTAX_TERR_TERINAL)        // 语法子树的第一个叶子结点必须但是终结符号
    {
        return treeNode;
    }

    return treeNode;
}


// 在以parentRoot为根的语法子树中找到第一个是终结符的叶子节点
TupleNode* FindFirstChildTupleNode(SyntaxTree parentRoot)
{
    SyntaxTreeNode *treeNode = NULL;
    if((treeNode = FindFirstChildTreeNode(parentRoot)) != NULL)
    {
        return treeNode->m_syntax.m_data.m_tupleNode;
    }
    else
    {
        return NULL;
    }
//
//    SyntaxTreeNode *treeNode = NULL;
//
//    /// 首先先找到语法子树中第一个叶子结点
//    treeNode = parentRoot;
//    while(treeNode->m_firstChild != NULL)          // 找到第一个终结符编号
//    {
//        treeNode = treeNode->m_firstChild;
//    }
//
//    // 然后找到函数名称的词法结点
//    if(treeNode == NULL)
//    {
//        #ifdef PROP_DEBUG_DEFINE
//        FILE_FUNC_LINE( );
//        #endif // PROP_DEBUG_DEFINE
//        fprintf(stderr, "在语法子树中第一个叶子节点不是终结符号\n");
//        return NULL;
//    }
//    if(treeNode->m_syntax.m_kind == SYNTAX_TERR_TERINAL)        // 语法子树的第一个叶子结点必须但是终结符号
//    {
//        return treeNode->m_syntax.m_data.m_tupleNode;
//    }

}

// 在以parentRoot为根的语法子树中找到终结符treinal的位置
TupleNode* FindFirstSyntaxTreeTreinal(SyntaxTree parentRoot, TokenKind treinal)
{
    TupleNode      *headTupleNode = NULL;
    TupleNode      *tupleNode = NULL;

    /// 首先先找到语法子树中第一个叶子结点d的词法指针域
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // FILE_FUNC_LINE( );
    // 然后找到函数名称的词法结点
    if(headTupleNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在语法子树中第一个叶子节点不是终结符号\n");
        return NULL;
    }
    else        // 语法子树的第一个叶子结点必须但是终结符号
    {
        tupleNode = FindFirstTupleTreinal(headTupleNode, treinal);
        return tupleNode;
    }
}


// 在以parentRoot为根的语法子树中找到最后一个是终结符的叶子节点
SyntaxTreeNode* FindFinalChildTreeNode(SyntaxTree parentRoot)
{
    SyntaxTreeNode *treeNode = NULL;

    /// 首先先找到语法子树中最后一个叶子结点
    treeNode = (SyntaxTreeNode *)parentRoot;
    while(treeNode->m_finalChild != NULL)          // 找到第一个终结符编号
    {
        treeNode = treeNode->m_finalChild;
    }

    // 然后找到函数名称的词法结点
    if(treeNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在语法子树中最后一个叶子节点不是终结符号\n");
        return NULL;
    }
    else if(treeNode->m_syntax.m_kind == SYNTAX_TERR_TERINAL)        // 语法子树的第一个叶子结点必须但是终结符号
    {
        return treeNode;
    }

    return treeNode;
}

// 在以parentRoot为根的语法子树中找到第一个是终结符的叶子节点
TupleNode* FindFinalChildTupleNode(SyntaxTree parentRoot)
{
    SyntaxTreeNode *treeNode = NULL;
    if((treeNode = FindFinalChildTreeNode(parentRoot)) != NULL)
    {
        return treeNode->m_syntax.m_data.m_tupleNode;
    }
    else
    {
        return NULL;
    }
}
