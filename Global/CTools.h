

#ifndef CTOOLS_H_INCLUDED
#define CTOOLS_H_INCLUDED




/// 配置文件信息
#include "Config.h"     //  #include "..\Config\Config.h"                // 配置工具


/// 全局接口
#include "Errors.h"               // 错误处理接口
#include "Files.h"                 // 文件处理接口

/// 工具信息
#include "Buffer.h"               // 双缓冲区

/// 词法分析端
//#include "BinaryTuple.h"   //  #include "..\Lexical\BinaryTuple.h"         // 词法二元组接口
#include "Lexical.h"    //  #include "..\Lexical\Lexical.h"             // 词法分析器主控程序

/// 语法分析器
#include "Parser.h"    //  #include "..\Parser\Parser.h"               // 语法分析主控程序

/// 符号表信息
#include "SymbolTable.h"

/// 插桩器信息
#include "Prop.h"

/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif





#endif // CTOOLS_H_INCLUDED
