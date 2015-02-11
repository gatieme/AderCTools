



#include "PropTable.h"





//////////////////////////////////////
// 记录插桩信息数目的全局变量
//int g_propNodeCount = 0;
/////////////////////////////////////

// 建立插桩信息表, 并且初始化
PropTable CreatePropTable(void)
{
    PropTable  propTable = NULL;

    if((propTable = (PropTableNode *)malloc(sizeof(PropTableNode))) != NULL)
    {
        propTable->m_prop.m_offset = 0;
        propTable->m_prop.m_kind = -1;
        propTable->m_next = NULL;
    }
    ////////////////////////////////////////////////////////////
    // g_propNodeCount = 0;            // 当前插桩信息表结点数目为空
    ////////////////////////////////////////////////////////////
    // InsertPropData(propTable, )
    return propTable;
}

// 依据偏移offset在函数中找到适当的位置
PropTableNode *FindPropInsertPos(PropTable propTable, int offset)
{
    PropTableNode   *headPropNode = propTable;
    PropTableNode   *lastPropNode = headPropNode;           // 上一个结点
    PropTableNode   *currPropNode = headPropNode->m_next;   // 当前结点

    while(currPropNode != NULL)
    {
        // 按照偏移从小到大的顺序将插桩信息结点插入插桩信息表中
        // 因此找到当前插桩信息链表中偏移大于当前要插入偏移的那个结点currPropNode
        // 该结点的前一个位置currPropNode即是要插入的位置
        // 使用 ">" 可以保证偏移相同时， 先插入的结点在前， 后插入的结点在后...
        if(currPropNode->m_prop.m_offset > offset)
        {
            break;
        }

        lastPropNode = currPropNode;
        currPropNode = currPropNode->m_next;
    }


    return lastPropNode;
}

// 将插桩数据以及重定向行号信息插入插桩信息表
void InsertPropDataWithLine(PropTable propTable, long offset, PropStrKind kind, int line)
{
#ifdef PROP_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // PROP_DEBUG_DEFINE
    PropTableNode   *headPropNode = (PropTableNode *)propTable;             // 头指针串
    PropTableNode   *posPropNode = FindPropInsertPos(propTable, offset);    // 待插入位置串，
    PropTableNode   *newPropNode = NULL;                                    // 待插入串

    if((newPropNode = (PropTableNode *)malloc(sizeof(PropTableNode))) != NULL)
    {
//        printf("开辟的地址%p\n", newPropNode);
//        printf("%p    ******** %p\n", propNode, newPropNode);

        #ifdef PROP_SHOWS_DEFINE
        printf("将[%d, %d]插入插桩信息链表\n", offset, kind);
        #endif // PROP_SHOWS_DEFINE

        newPropNode->m_prop.m_offset = offset;
        newPropNode->m_prop.m_kind = kind;
        newPropNode->m_prop.m_line = line;

        newPropNode->m_next = posPropNode->m_next;
        posPropNode->m_next = newPropNode;

        //////////////////////////////////////////////
        // 记录当前插桩信息表的数据结点数目
        // g_propNodeCount++;
        headPropNode->m_prop.m_offset++;
        //////////////////////////////////////////////
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "NO MEMORY\n");
    }
}

// 将"需要在offset偏移， 插入kind形式的插桩串"的插桩数据信息添加入字符串
void InsertPropData(PropTable propTable, long offset, PropStrKind kind)
{
#ifdef PROP_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // PROP_DEBUG_DEFINE
    PropTableNode   *headPropNode = (PropTableNode *)propTable;             // 头指针串
    PropTableNode   *posPropNode = FindPropInsertPos(propTable, offset);    // 待插入位置串，
    PropTableNode   *newPropNode = NULL;                                    // 待插入串

    if((newPropNode = (PropTableNode *)malloc(sizeof(PropTableNode))) != NULL)
    {
//        printf("开辟的地址%p\n", newPropNode);
//        printf("%p    ******** %p\n", propNode, newPropNode);

        #ifdef PROP_SHOWS_DEFINE
        printf("将[%d, %d]插入插桩信息链表\n", offset, kind);
        #endif // PROP_SHOWS_DEFINE

        newPropNode->m_prop.m_offset = offset;
        newPropNode->m_prop.m_kind = kind;

        newPropNode->m_next = posPropNode->m_next;
        posPropNode->m_next = newPropNode;

        //////////////////////////////////////////////
        // 记录当前插桩信息表的数据结点数目
        // g_propNodeCount++;
        headPropNode->m_prop.m_offset++;
        //////////////////////////////////////////////
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "NO MEMORY\n");
    }
}


// 删除插桩信息表的第一个数据结点
void DeleteFirstPropData(PropTable propTable)
{
    PropTableNode *headPropNode = propTable;

    if(EmptyPropTable(propTable) != true)           // 只要当前插桩信息表不是空表
    // if(headPropNode->m_next != NULL)
    // if(headPropNode->m_prop.m_offset != 0)
    {
        PropTableNode *firstPropNode = headPropNode->m_next;
        headPropNode->m_next = firstPropNode->m_next;
        free(firstPropNode);

        /////////////////////////////////////////
        headPropNode->m_prop.m_offset--;/////////
        /////////////////////////////////////////
    }
    else            // 空插桩信息表无法删除第一个数据结点
    {
        fprintf(stderr, "当前插桩信息表为空");
    }
}

// 显示当前插桩数据域结点
void ShowPropTableNode(PropTableNode *propNode)
{
    printf("[%d, %d]\n", propNode->m_prop.m_offset, propNode->m_prop.m_kind);
}


// 显示当前插桩信息表
void ShowPropTable(PropTable propTable)
{
    #ifdef PROP_HELPS_DEFINE
    printf("*************************************************\n");
    printf("**               显示插桩信息表                **\n");
    printf("*************************************************\n");
    PAUSE( );
    #endif
    PropTableNode *pNode = (PropTableNode *)propTable;

    while(pNode != NULL)
    {
        ShowPropTableNode(pNode);
        pNode = pNode->m_next;
    }
    PAUSE( );
}




// 销毁当前插桩信息表
void DestroyPropTable(PropTable propTable)
{
    PropTableNode *headPropNode = (PropTableNode *)propTable;

    while(EmptyPropTable(propTable) != true)           // 只要当前插桩信息表不是空表
    {
        DeleteFirstPropData(propTable);
    }

    free(headPropNode);
}


void WritePropDefStr(PropTableNode *propNode, CToolsFILE destFp, const char *srcFname)
{

    // 这样的数据每修改一项，都需要去文件PropTable.h中修改PropStrKind数据域
    const char *propDefStrArray[] =
    {
        START_DEFINE_PROP_STR,            // 开始信息宏串
        INCLUDE_DEFINE_PROP_STR,          // 基本的文件包含宏，添加在文件开头
        LINE_DEFINE_PROP_STR,             // 基本的插桩语句支持宏，添加在文件开头
        FILE_OPEN_DEFINE_PROP_STR,        // 打开文件宏插桩串，添加在main函数起始的位置
        PROP_CLOSE_DEFINE_PROP_STR,       // 关闭文件宏插桩串, 添加在主函数返回之前
        PROP_BASE_PROP_STR,               // 最基础的插桩信息流" LINE(stream) "
        PROP_COMMA_PROP_STR,              // 带","的插桩信息流" LINE(stream), "
        PROP_SEMICOLON_PROP_STR,          // 带"；"的插桩信息流" LINE(stream); "
        PROP_LBRACE_SEPARATOR_STR,        // " { "
        PROP_RBRACE_SEPARATOR_STR,        // " } "
    };

    // 将数据写入文件中
    #ifdef CTOOLS_FILE_OPEN_BINARY
    fwrite(propDefStrArray[propNode->m_prop.m_kind], sizeof(propDefStrArray[propNode->m_prop.m_kind]), 1, destFp);
    #endif // CTOOLS_FILE_OPEN_BINARY
    #ifdef CTOOLS_FILE_OPEN_TEXT
    fprintf(destFp, "%s", propDefStrArray[propNode->m_prop.m_kind]);
    #endif // CTOOLS_FILE_OPEN_TEXT
/*
    if(propNode->m_prop.m_kind == FILE_OPEN_DEFINE_PROP_KIND)
   //|| propNode->m_prop.m_kind == FILE_CLOSE_DEFINE_PROP_KIND)
    {
        WritePropLineStr(destFp, srcFname, propNode->m_prop.m_line);              // 插入行号初始化数据
    }
    */
}

// 按照PropTable的信息将源文件srcFname的数据写入destFname文件
void WriteProp(PropTable propTable, const char *destFname, const char *srcFname)
{


    // 插桩信息表数据
    PropTableNode *headPropNode = (PropTableNode *)propTable;
    PropTableNode *currPropNode = headPropNode->m_next;

    // 输入输出准备
    #ifdef CTOOLS_FILE_OPEN_TEXT
    // 以文本方式打开文件
    CToolsFILE     destFp = CToolsOpen(destFname, WRITE_ONLY_TEXT);
    CToolsFILE     srcFp = CToolsOpen(srcFname,  READ_ONLY_TEXT);
    #endif // CTOOLS_FILE_OPEN_TEXT

    #ifdef CTOOLS_FILE_OPEN_BINARY
    // 以二进制方式打开文件
    CToolsFILE     destFp = CToolsOpen(destFname, WRITE_ONLY_BINARY);
    CToolsFILE     srcFp = CToolsOpen(srcFname,  READ_ONLY_BINARY);
    #endif // CTOOLS_FILE_OPEN_BINARY


    long           startOffset = -1;
    long           endOffset = -1;
    int             count = 0;

    // 开始想目标文件中写入插桩信息
    InitProp(destFp, srcFname);
    startOffset = 0;                // 打待插桩文件的起始位置开始写入
    while(currPropNode != NULL)
    {
        #ifdef PROP_SHOWS_DEFINE
        printf("当前处理插桩信息表数据单元:");
        ShowPropTableNode(currPropNode);
        PAUSE( );
        #endif // PROP_SHOWS_DEFINE

        endOffset = currPropNode->m_prop.m_offset;

        count = endOffset - startOffset;
        // 将srcFp指向源文件中当前位置开始的count个字符写入destFp指向的目标文件
        PropWriteCountSrcToDest(destFp, srcFp, count);

//        #ifdef PROP_DEBUG_DEFINE
//        printf("%s\n", propDefStrArray[currPropNode->m_prop.m_kind]);
//        #endif // PROP_DEBUG_DEFINE

        //fprintf(destFp, "%s", propDefStrArray[currPropNode->m_prop.m_kind]);
        WritePropDefStr(currPropNode, destFp, srcFname);
        currPropNode = currPropNode->m_next;
        startOffset = endOffset;
    }
    PropWriteAllSrcToDest(destFp, srcFp);       // 将源文件最后的数据写入目标文件

    CToolsCloseAll(destFp, srcFp, NULL);            // 关闭所有文件信息
}

