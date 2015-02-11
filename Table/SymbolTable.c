/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : BinaryTuple.c                                                  *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/




#include "SymbolTable.h"

#define ID_ERROR -1


/// SymBolTable的函数声明部分
#ifdef PUBLIC_and_PRIVATE
#
#
// 计算token在Hash表中的插入位置
PRIVATE int SymbolHashCode(char *token);
#
#
#endif




// 计算token在Hash表中的插入位置
int SymbolHashCode(char *token)
{
    //assert(token != NULL && strlen(token) > 0);          // 参数不能为空
    if(token[0] == '_')         // 以_下划线开头的变量标识
    {
        return 0;
    }
    else if(isalpha(token[0]) != 0)     // 以字母开头的
    {
        return tolower(token[0]) - 'a';       // 返回字母的序号
    }
    else
    {
        return ID_ERROR;      // 返回错误不合法的标识变量
    }
}

// 将表示token添加进入符号表
Identifier* InsertSymbolToken(char *token, SymbolTable symbolTable)
{
    /// 定义串的哈希编码信息, 以及符号表指针域
    int code;                                   // 保存当前串的哈希编码
    Identifier *pNode = NULL, *newNode = NULL;  // 两个指针信息
    printf("%s %d %p\n", __func__, __LINE__, symbolTable);
    /// 前期检查的部分
    if(SymbolHashCode(token) == ID_ERROR)     // 只要标识符不合法
    {
        return NULL;                        // 直接返回
    }
    else if((pNode = FindSymbolToken(token, symbolTable)) != NULL)   // 当前标识符号已经在符号表中
    {
        return pNode;                        // 当前串已经在目前链中, 无需再插入, 直接返回指向当前串的地址
    }
    //assert(token != NULL && strlen(token) > 0 && SymbolHashCode(token) == ID_ERROR);          // 参数不能为空

    printf("%d", __LINE__);system("pause");

    /// 将当前标识符插入符号表的哈希串中
    code = SymbolHashCode(token);     // 计算当前变量的哈希码

    // 首先找到当前链表串的末尾
    pNode = symbolTable[code]->m_next;                 // 指向头结点的下一个位置也就是第一个结点

    while(pNode != NULL)        // 循环走到连标的末尾
    {
        pNode = pNode->m_next;          //只要不是链表的末尾就往下一个结点走
    }

    // 开辟空间
    newNode = (Identifier *)malloc(sizeof(Identifier));         // 为新数据开辟空间
    // 数据项初始化
    newNode->m_name = (char *)malloc(sizeof(token));  // 为名称的数据开辟空间
    strcpy(newNode->m_name, token);                              // 为标识符名称赋值

    newNode->m_offset = UNKNOWVALUE;                            // 当前偏移地址为未知项
    newNode->m_kind = UNKNOW;                                   // 当前标识符的属性未知
    newNode->m_expand = NULL;                                   // 当前标识符的扩展是真属性为NULL
    newNode->m_next = NULL;                                     // 下一个指针项为空
    // 构建链表信息
    pNode->m_next = newNode;                                    // 将当前吗末尾指向新的末尾
    // 当前串的数据项数目加1
    symbolTable[code]->m_offset++;   // 头结点的offset标识当前链的数据项数

    return pNode;// return newNode;                 // 返回当前插入结点的地址信息

}


// 查询token是否在符号表中
Identifier* FindSymbolToken(char *token, SymbolTable symbolTable)
{
    int code = code = SymbolHashCode(token);     // 计算当前变量的哈希码
    printf("%s %d %p\n", __func__, __LINE__, symbolTable);
    printf("%s %d %p\n", __func__, __LINE__, *(symbolTable + code));
    printf("%s %d %p\n", __func__, __LINE__, symbolTable[code]);
    Identifier *pNode = symbolTable[code];       // 指向第一个结点信息
    printf("%s %d %p\n", __func__, __LINE__, symbolTable);
    //symbolTable[code]->m_offset;
    printf("1111");
    printf("%s %d %d\n", __func__, __LINE__, symbolTable[code]->m_offset);
    printf("1111");
    if(pNode->m_offset == 0)     // 如果当前哈希串中还没有数据
    {
        printf("%d", __LINE__);system("pause");
        return NULL;
    }
    printf("%d", __LINE__);system("pause");

    for(pNode = pNode->m_next; pNode != NULL; pNode = pNode->m_next)
    {
        if(strcmp(symbolTable[code]->m_name, token) == 0)       // 如果当前串与目前这个
        {
            break;
        }
    }

    return pNode;           // 返回当前串地址
}



// 初始化哈希表信息
SymbolTable InitSymbolTalbe(SymbolTable __attribute__((unused)) symbolTable)
{   /// 这里有一个警告, 原因为参数symbolTable没使用过
    symbolTable = (Identifier **)malloc(sizeof(Identifier *) * BUCKETS);        /*typedef Identifier **SymbolTable;       // 符号表信息*/
    printf("%d %p\n", __LINE__, symbolTable);
    Identifier* pNode = NULL;

    for(int code = 0; code < BUCKETS; code++)          // 初始化每个头结点
    {
        // 指向头结点
        pNode = symbolTable[code];
        pNode = *(symbolTable + code);            // 有问题

        //printf("%d %p", __LINE__, pNode);
        // 初始化头结点信息
        pNode = (Identifier *)malloc(sizeof(Identifier));       // 为头结点开辟空间
        pNode->m_name = NULL;                                      // 头结点的名称串为空串
        pNode->m_offset = 0;                            // 当前偏移地址为未知项
        pNode->m_kind = UNKNOW;                                   // 当前标识符的属性未知
        pNode->m_expand = NULL;                                   // 当前标识符的扩展是真属性为NULL
        pNode->m_next = NULL;                                     // 下一个指针项为空
        printf("%d %p %d\n", __LINE__, pNode, pNode->m_offset);
    }

    return symbolTable;
}

// 显示符号表每个哈希表项的数据信息
void ShowSymbolList(Identifier *idenList)
{
    //getchar( );
    printf("有%d个结点信息\n", idenList->m_offset);

    Identifier *pNode = idenList->m_next;       // 指向第一个结点信息

    while(pNode != NULL)
    {
        printf("{%d, %s}\n", pNode->m_kind, pNode->m_name);
        pNode = pNode->m_next;          // 只想下一个指针位置
    }
}


// 显示符号表的信息
void VisitSymbolTable(SymbolTable symbolTable)
{
    for(int code = 0; code < BUCKETS; code++)       // 输出每个元素的信息
    {
        printf("\n\nHASHCODECODE -=> %d\n", code);
        ShowSymbolList(symbolTable[code]);                // 输出每个哈希项的数据信息
        //printf("%s %d %p %p\n", __func__, __LINE__, symbolTable[code], *(symbolTable + code));
    }
}


void ShowSymbolPoint(SymbolTable __attribute__((unused)) symbolTable)
{
    for(int code = 0; code < BUCKETS; code++)       // 输出每个元素的信息
    {
        printf("%s %d %p %p\n", __func__, __LINE__, symbolTable[code], *(symbolTable + code));
    }
}
// **p = *a[]
// (*p)[4] = a[][4]

/**
185 00662ae8
202 00662b60 0
202 00662b80 0
202 00662ba0 0
202 00662bc0 0
202 00662be0 0
202 00662c00 0
202 00662c20 0
202 00662c40 0
202 00662c60 0
202 00662c80 0
202 00662ca0 0
202 00662cc0 0
202 00662ce0 0
202 00662d00 0
202 00662d20 0
202 00662d40 0
202 00662d60 0
202 00666aa0 0
202 009ad850 0
202 009ad870 0
202 009ad890 0
202 009ad8b0 0
202 009ad8d0 0
202 009ad8f0 0
202 009ad910 0
202 009ad930 0
202 009ad950 0
**/
