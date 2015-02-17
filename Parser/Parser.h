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

/*
描述
    Parser为CTools编译器提供词法处理的处理接口
*/


#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#include "Syntax.h"


//#ifdef PROP_REDUCTION_DEFINE
#include "Prop.h"
#include "PropRed.h"
#include "PropTable.h"
//#endif // PROP_REDUCTION_DEFINE


/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif



#ifdef PUBLIC
#
#
PUBLIC SyntaxTree                                  // 语法分析是否通过
ParseTuple(
           BinaryTuple douTuple);       // 词法二元组信息
#
#
PUBLIC SyntaxTree                                // 语法分析是否通过
ParseFile(
          const char *sourFile);          // 源文件名称
#
#
/// 对douTuple进行语法分析, 同时进行插桩，将插桩结果写入destFname
PUBLIC SyntaxTree
ParseTuplePropRed(
                  BinaryTuple douTuple,
                  const char *destFname);       // 词法二元组信息
#
#
/// 对文件fileName进行语法分析, 同时进行插桩分析
PUBLIC SyntaxTree
ParseFilePropRed(const char *destFileName,
                 const char *srcFileName);          // 源文件名称
#
#
/// 0.6.0更新
/// 语法析的时候需要将预编译指令跳过
/// 跳过所有预编译命令的行
PUBLIC TupleNode*
SkipProComTupleNode(
                    TupleNode *tupleNode);
#endif  // PUBLIC



#endif // PARSER_H_INCLUDED





