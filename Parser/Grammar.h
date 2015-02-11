#ifndef GRAMMAR_H_INCLUDED
#define GRAMMAR_H_INCLUDED

#include "..\Config\Config.h"

#include "..\Lexical\TokenKind.h"
#include "..\Parser\SyntaxKind.h"




/// 产生式左部
typedef SyntaxKind  LeftGrammar;
///产生式右部
typedef struct  RightGrammar        // 产生式的右部
{
    union RightGrammarData                   // 产生式的右部，可能是终结符或者文法符号
    {
        SyntaxKind  m_Syntax;           // 文法符号的信息
        TokenKind   m_token;            // 终结符号的信息
    }m_data;

    enum  RightGrammarFlag                  // 用于标识产生式右部当前位置是文法符号还是终结符号
    {
        IS_SYNTAX_DATA,                   // 表明当前位置是文法符号
        IS_TOKENS_DATA,                   // 表明当前位置是终结符号
        IS_NULL_DATA,
    }m_flag;

}RightGrammar;




///  文法结构体
typedef struct Grammar
{
	int				m_grammarId;		// 该文法产生式的编号
    int             m_rightLength;      //  产生式右部的长度
    LeftGrammar     m_left;             //  文法左部的符号信息
    RightGrammar    m_right[9];            // 产生式右部的信息
}Grammar;



/// Literal的函数声明部分
#ifdef PUBLIC_and_PUBLIC
#
#
PUBLIC int                  // 返回当前编号产生式右部的长度
RightGrammarLength(
                   int id);         // 文法产生式的编号
#
#
PUBLIC SyntaxKind           // 返回当前id编号产生式的左部信息
LeftGrammarData(
            int id);                //  文法产生式的编号
#
#
#endif





//

#endif // GRAMMAR_H_INCLUDED
