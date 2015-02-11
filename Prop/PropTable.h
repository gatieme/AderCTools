/***********************************************************************************
*   CopyRight   : 2013-2014, HerBinUnversity, GatieMe
*   File Name   : Buffer.h
*   Description: CTools-SyntacicParser
*   Author     : Gatie_Me
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-11-18 08:42:24
*   Content    : CTools-Prop
***********************************************************************************/

#ifndef PROPTABLE_H_INCLUDED
#define PROPTABLE_H_INCLUDED

#include "../Config/Config.h"
#include "Prop.h"




/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif


// 插桩宏字符串种类(编号)
// 这样的数据每修改一项，都需要去文件PropTable.c中修改WritePropDefStr函数的propDefStrArray数据域
typedef enum tagPropStrKind
{
    PROP_TABLE_HEAD             =  -1,          // 头结点信息域
    START_DEFINE_PROP_KIND      =   0,          // 开始信息宏串
    INCLUDE_DEFINE_PROP_KIND    =   1,          // 基本的文件包含宏，添加在文件开头
    LINE_DEFINE_PROP_KIND       =   2,          // 基本的插桩语句支持宏，添加在文件开头
    FILE_OPEN_DEFINE_PROP_KIND  =   3,          // 打开文件宏插桩串，添加在main函数起始的位置
    FILE_CLOSE_DEFINE_PROP_KIND =   4,          // 关闭文件宏插桩串, 添加在主函数返回之前
    PROP_BASE_PROP_KIND         =   5,          // 最基础的插桩信息流" LINE(stream) "
    PROP_COMMA_PROP_KIND        =   6,          // 带","的插桩信息流" LINE(stream), "
    PROP_SEMICOLON_PROP_KIND    =   7,          // 带"；"的插桩信息流" LINE(stream); "
    PROP_LBRACE_SEPARATOR_KIND  =   8,
    PROP_RBRACE_SEPARATOR_KIND  =   9,
}PropStrKind;


// 插桩信息数据域
typedef struct tagPropData
{
    long            m_offset;               // 需要添加插桩信息的偏移位置
    PropStrKind     m_kind;                 // 当前位置应该插入的桩信息
    SyntaxKind      m_grammar;              // 当前归约数据的产生式类型 -=> 供后期插桩扩展使用
    int              m_line;                 // 重新定位的行号数据
}PropData;

// 插桩信息表(链表)结点
typedef struct PropTableNode
{
    PropData                m_prop;             // 插桩信息数据域
    struct PropTableNode    *m_next;             // 指向下一个结点的数据域
}PropTableNode;

// 插桩信息表
typedef PropTableNode*  PropTable;              // 插桩信息表
//typedef struct tagPropTable
//{
//    PropTableNode   *m_headNode;
//    int               m_count;
//}PropTable;


#ifdef PUBLIC_and_PRIVATE
#
#
// 建立插桩信息表, 并且初始化
PUBLIC PropTable
CreatePropTable(void);
#
#
// 对语法子树parentRoot依照第id个产生式的形式进行插桩
PUBLIC void
PropRed(
        PropTable propTable,
        SyntaxTree parentRoot,
        int id);
#
#
// 将"需要在offset偏移， 插入kind形式的插桩串"的插桩数据信息添加入字符串
PUBLIC void
InsertPropData(PropTable propTable,    // 当前插桩信息表
               long offset,            // 需要插入为位置的偏移
               PropStrKind kind);      // 需要插入的插桩数据类型
#
#
// 显示当前插桩数据域结点
PUBLIC void
ShowPropTableNode(
                  PropTableNode *propNode);           // 当前插桩信息结点
#
#
// 显示当前插桩信息表
PUBLIC void
ShowPropTable(
              PropTable propTable);                 // 待显示的插桩信息表
#
#
// 销毁当前插桩信息表
PUBLIC void
DestroyPropTable(
                 PropTable propTable);              // 待销毁的插桩信息表
// 删除插桩信息表中的第一个数据
PUBLIC void
DeleteFirstPropData(
                    PropTable propTable);       // 待处理的插桩信息表头指针
#
#
// 依据偏移offset在函数中找到适当的位置
PUBLIC PropTableNode*
FindPropInsertPos(
                  PropTable propTable,          // 带处理的插桩数据表头指针
                  int offset);                   // 将要插入的结点的位置偏移
#
#
#define EmptyPropTable(propTable)               \
        (propTable->m_next == NULL)
        // propTable->m_prop.m_offset == 0
#
#
// 按照PropTable的信息将源文件srcFname的数据写入destFname文件
void WriteProp(PropTable propTable,
               const char *destFname,
               const char *srcFname);
#endif  // PUBLIC_and_PRIVATE





#endif // PROPTABLE_H_INCLUDED
