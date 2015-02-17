


#include "Config.h"     //  #include "..\Config\Config.h"

int CToolsPrintf(const char* format, ...)
{
	va_list	argPtr;
	int		count;

	va_start(argPtr, format);				// 获取可变参数列表的地址
	count = vprintf(format, argPtr);		// 将信息输出到输出设备
	va_end(argPtr);							// 可变参数的结束

	return count;
}




///CTOOLS全局调试宏定义////////////////////////////////////////////
// CTools调试宏信息////////////////////////////////
#ifdef CTOOLS_DEBUG_DEFINE
    #define CToolsDebugPrintf(arg)  CToolsPrintf arg
    #define ShowFileFunctionLine( )    FILE_FUNC_LINE( )
#else
    #define CToolsDebugPrintf
    #define ShowFileFunctionLine( )
#endif
//////////////////////////////////////////////////
#
#
// CTools信息输出宏////////////////////////////////
#ifdef CTOOLS_SHOWS_DEFINE
    #define CToolsShowsPintf(arg)    CToolsPrintf arg
#else
    #define CToolsShowsPintf(arg)
#endif
//////////////////////////////////////////////////
#
#
//////////////////////////////////////////////////
#ifdef CTOOLS_HELPS_DEFINE
    #define CToolsHelpsPrintf(arg)  CToolsPrintf arg
#else
    #define CToolsHelpsPrintf(arg)
#endif
//////////////////////////////////////////////////
///-/////////////////////////////////////////////////////////////
#
#
///-词法LEX全局调试信息定义////////////////////////////////////////
// LEXICAL调试宏信息////////////////////////////////
#ifdef LEXICAL_DEBUG_DEFINE
    #define LexicalDebugPrintf(arg)  CToolsPrintf arg
#else
    #define LexicalDebugPrintf
#endif
//////////////////////////////////////////////////
#
#
// LEXICAL信息输出宏////////////////////////////////
#ifdef LEXICAL_SHOWS_DEFINE
    #define LexicalShowsPintf(arg)    CToolsPrintf arg
#else
    #define LexicalShowsPintf(arg)
#endif
//////////////////////////////////////////////////
#
#
// LEXICAL帮助输出宏////////////////////////////////
#ifdef LEXICAL_HELPS_DEFINE
    #define LexicalHelpsPrintf(arg)  CToolsPrintf arg
#else
    #define LexicalHelpsPrintf(arg)
#endif
//////////////////////////////////////////////////
///-/////////////////////////////////////////////////////////////
#
#
///-语法PARSER全局调试信息定义////////////////////////////////////////
// PARSER调试宏信息////////////////////////////////
#ifdef PARSER_DEBUG_DEFINE
    #define ParserDebugPrintf(arg)  CToolsPrintf arg
#else
    #define ParserDebugPrintf
#endif
//////////////////////////////////////////////////
#
#
// PARSER信息输出宏////////////////////////////////
#ifdef PARSER_SHOWS_DEFINE
    #define ParserShowsPintf(arg)    CToolsPrintf arg
#else
    #define ParserShowsPintf(arg)
#endif
//////////////////////////////////////////////////
#
#
// PARSER帮助输出宏////////////////////////////////
#ifdef PARSER_HELPS_DEFINE
    #define ParserHelpsPrintf(arg)  CToolsPrintf arg
#else
    #define ParserHelpsPrintf(arg)
#endif
//////////////////////////////////////////////////
///-////////////////////////////////////////////////////////////
