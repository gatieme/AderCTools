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




#include "LiteralTable.h"


/// Literal的函数声明部分
#ifdef PUBLIC_and_PRIVATE
#
#
// 计算token在Hash表中的插入位置
PRIVATE int LiteralHashCode(char *token);
#
#
#endif




// 计算token在Hash表中的插入位置
int LiteralHashCode(char *token)
{
   for(int i = 0; token[i] != '\0'; i++)
   {

   }
   return 0;
}

// 将表示token添加进入符号表
Literal* InsertLiteralToken(char *token, LiteralTable literalTable)
{
    /// 定义串的哈希编码信息, 以及符号表指针域
    int code;                                   // 保存当前串的哈希编码
    Literal *pNode = NULL, *newNode = NULL;  // 两个指针信息

    /// 前期检查的部分
    if(LiteralHashCode(token) == CON_ERROR)     // 只要标识符不合法
    {
        return NULL;                        // 直接返回
    }
    else if((pNode = FindLiteralToken(token, literalTable)) != NULL)   // 当前标识符号已经在符号表中
    {
        return pNode;                        // 当前串已经在目前链中, 无需再插入, 直接返回指向当前串的地址
    }
    //assert(token != NULL && strlen(token) > 0 && SymbolHashCode(token) == ID_ERROR);          // 参数不能为空

    /// 将标识符插入到符号表
    code = LiteralHashCode(token);     // 计算当前变量的哈希码

    /// 将当前标识符插入哈希表串中
    if(literalTable[code]->m_offset/*头结点的offset标识当前链的数据项数*/ == 0)        // 如果当前哈希表串没有数据
    {   // 先初始化头结点域, 在将数据插入
        // pNode指向头指针
        /*Identifier* */pNode = literalTable[code];
        /*Identifier* */newNode = NULL;

        // 初始化头结点信息
        pNode = (Literal *)malloc(sizeof(Literal));       // 为头结点开辟空间
        pNode->m_data = NULL;                                      // 头结点的名称串为空串
        pNode->m_offset = 0;                            // 当前偏移地址为未知项
        pNode->m_kind = CONST;                                   // 当前标识符的属性未知
        //pNode->m_expand = NULL;                                   // 当前标识符的扩展是真属性为NULL
        pNode->m_next = NULL;                                     // 下一个指针项为空

        // 建立要插入信息的新结点
        newNode = (Literal*)malloc(sizeof(Literal));         // 为新数据开辟空间
        // 新结点数据项初始化
        newNode->m_data = (char *)malloc(strlen(token) + sizeof(char));  // 为名称的数据开辟空间
        strcpy(newNode->m_data, token);                              // 为标识符名称赋值
        newNode->m_offset = UNKNOWVALUE;                            // 当前偏移地址为未知项
        newNode->m_kind = UNKNOW;                                   // 当前标识符的属性未知
        //newNode->m_expand = NULL;                                   // 当前标识符的扩展是真属性为NULL
        newNode->m_next = NULL;                                     // 下一个指针项为空
        // 构建链表信息
        pNode->m_next = newNode;                                    // 将当前吗末尾指向新的末尾

        // 当前串的数据项数目加1
        literalTable[code]->m_offset++;   // 头结点的offset标识当前链的数据项数

        return pNode;// return newNode;                 // 返回当前插入结点的地址信息
    }
    else      // 如果当前哈希表已经有数据项
    {   // 直接将符号插入
        //Literal[code].m_name = malloc(strlen(token) + 1);       // 为变量的名称开辟必要的空间
        /*Identifier* */pNode = literalTable[code]->m_next;                 // 指向头结点的下一个位置也就是第一个结点
        /*Identifier* */newNode = NULL;

        // 首先找到当前链表串的末尾
        while(pNode != NULL)        // 循环走到连标的末尾
        {
            pNode = pNode->m_next;          //只要不是链表的末尾就往下一个结点走
        }

        // 开辟空间
        newNode = (Literal*)malloc(sizeof(Literal));         // 为新数据开辟空间
        // 数据项初始化
        newNode->m_data = (char *)malloc(strlen(token) + sizeof(char));  // 为名称的数据开辟空间
        strcpy(newNode->m_data, token);                              // 为标识符名称赋值
        newNode->m_offset = UNKNOWVALUE;                            // 当前偏移地址为未知项
        newNode->m_kind = UNKNOW;                                   // 当前标识符的属性未知
        //newNode->m_expand = NULL;                                   // 当前标识符的扩展是真属性为NULL
        newNode->m_next = NULL;                                     // 下一个指针项为空
        // 构建链表信息
        pNode->m_next = newNode;                                    // 将当前吗末尾指向新的末尾

        // 当前串的数据项数目加1
        literalTable[code]->m_offset++;   // 头结点的offset标识当前链的数据项数

        return pNode;// return newNode;                 // 返回当前插入结点的地址信息
    }

    return pNode;
}


// 查询token是否在符号表中
Literal* FindLiteralToken(char *token, LiteralTable literalTable)
{
    int code = code = LiteralHashCode(token);     // 计算当前变量的哈希码

    Literal *pNode = literalTable[code]->m_next;       // 指向第一个结点信息

    while(pNode != NULL)
    {
        if(strcmp(literalTable[code]->m_data, token) == 0)       // 如果当前串与目前这个
        {
            break;
        }
        pNode = pNode->m_next;          // 只想下一个指针位置
    }

    return pNode;           // 返回当前串地址
}









