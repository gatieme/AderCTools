/***********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe
*   File Name  : Parser.h
*   Description: CTools-SyntacicParser
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-3-10 21:29:24
*   Content    : CTools-Lexical
*
*   This file is the CodeProp...
***********************************************************************************/


#ifndef PROP_H_INCLUDED
#define PROP_H_INCLUDED


#include "../Parser/Syntax.h"
#include "../Tools/Files.h"
#include "../Config/Config.h"
#include "../Lexical/BinaryTuple.h"
#include "../Lexical/Lexical.h"



/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif



//////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/// 全局头文件包含插桩宏串 -=> 在位置开始位置插入
#define PROP_FILE_NAME  ".\\OutPut\\out_prop.c"
#
#
#define INCLUDE_DEFINE_PROP_STR                                             \
        "#include <stdio.h>\n#include <stdlib.h>\n\n"
#
#
/// 此宏定义用于插入插桩字符串 -=> 在文件在文件开始位置插入
#define LINE_DEFINE_PROP_STR                                                \
        "#define LINE()        fprintf(__propFP__, \"%d\\n\", __LINE__)\n"
#
#
/// 全局插桩文件指针变量宏串    -=> 在文件开始位置插入
#define GLOBAL_FILE_POINT_PROP_STR                                          \
        "FILE *__propFP__;\n"
#
#
/// 所以在文件开始位置插入的宏的集合
#define START_DEFINE_PROP_STR                                                 \
        INCLUDE_DEFINE_PROP_STR LINE_DEFINE_PROP_STR GLOBAL_FILE_POINT_PROP_STR
#
#
/// 此宏定义了文件打开信息 -=> 插入在main主入口函数起始位置
/*#define FILE_OPEN_DEFINE_PROP_STR                                                 \
        "//\tFILE *__propFP__ = NULL;\n"                                          \
        "\tif((__propFP__ = fopen(\"prop.txt\", \"w\")) == NULL)\n"               \
        "\t{\n"                                                                   \
        "\t\tfprintf(stderr, \"can\'t open the file prop.txt\\n\");\n"            \
        "\t}\n"*/
#define FILE_OPEN_DEFINE_PROP_STR                                             \
        "if((__propFP__ = fopen(\"prop.txt\", \"w\")) == NULL)"               \
        "{"                                                                   \
        "fprintf(stderr, \"can\'t open the file prop.txt\\n\");"              \
        "}"
#
#
/// 此宏定义了文件结束描述符 -=>  插入在主函数返回之前
#define PROP_CLOSE_DEFINE_PROP_STR             \
        " fclose(__propFP__); "
#
#
/// 此宏定义了插桩器的信息
#define PROP_STREAM_BASE_PROP_STR(stream)  \
        " LINE(stream) "
#
#
#define PROP_STREAM_SEMICOLON_PROP_STR(stream) \
        " LINE(stream); "
#
#
#define PROP_STREAM_COMMA_PROP_STR(stream)  \
        " LINE(stream), "
#
#
#define PROP_BASE_PROP_STR  \
        " LINE( ) "
#
#
#define PROP_SEMICOLON_PROP_STR \
        " LINE( ); "
#
#
#define PROP_COMMA_PROP_STR  \
        " LINE( ), "
#
#
#define PROP_LBRACE_SEPARATOR_STR   \
        " { "
#
#
#define PROP_RBRACE_SEPARATOR_STR   \
        " } "
#
#
/// 此函数用于插入重定向
#define ReopenDSefineStr    "freopen("prop.txt", "w", stdout);"
#
#
// 在文件中添加重定义文件行的信息
#define WritePropLineStr(fp, fileName, fileLine)                                        \
    do                                                                                  \
    {                                                                                   \
        fprintf(fp, "#line %d \"%s\"\n", fileLine, fileName);                           \
    }while(0);


// 在文件中添加文件插桩信息
#define WritePropStr(fp, streamName)                 \
        do                                           \
        {                                            \
            fprintf(fp, "Line(%s);", streamName);    \
        }while(0);

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////////////////



/// Literal的函数声明部分
#ifdef PUBLIC_and_PUBLIC
#
#
// 在文件中添加起始信息[包括：FileOpenDefineStr，FileOpenDefineStr]
PUBLIC void
WritePropStartStr(
              const char *dest,             // 插桩目标文件
              const char *src);             // 待插桩源文件
#
#
// 对文件fileName进行插桩处理
PUBLIC void
PropFile(const char *dest,          // 插桩后的输出目的文件
          const char *src);          // 待插桩的源文件
#
#
// 将源文件src中偏移start到end的数据写入dest文件中
PUBLIC void
PropWriteSrcToDest(
                    CToolsFILE destfp,         // 指向插桩后目的文件描述符的指针
                    CToolsFILE srcfp,          // 指向待插桩文件描述符的指针
                    int start,                  // 需要写入位置的起始位置
                    int end);                   // 需要写入位置的结束位置
#
#
// 将词法二元组符号添加到目的文件中
PUBLIC void
PropWriteTupleNode(
                    CToolsFILE destfp,         // 指向插桩后目的文件描述符的指针
                    TupleNode* pNode);         // 指向词法二元组的指针
#
#
// 判断当前语法子树所表示的函数定义信息是不是主main函数入口
PUBLIC bool
IsMainFunc(
           SyntaxTree parentRoot);
#
#
// 将srcFp文件指针中的count个字符写入destFp指向的文件中
PUBLIC void
PropWriteCountSrcToDest(
                        CToolsFILE destFp,          // 目标文件指针
                        CToolsFILE srcFp,           // 目标文件指针
                        int count);
#
#
// 将源文件中从当前位置开始到末尾的所有字符写入目标文件中
PUBLIC void
PropWriteAllSrcToDest(
                      CToolsFILE destFp,            // 指向目标文件的指针
                      CToolsFILE srcFp);            // 指向源文件的指针
#
#
#endif




#endif // PROP_H_INCLUDED
