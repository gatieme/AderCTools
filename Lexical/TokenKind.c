#include "Lexical.h"





/// 数据定义部分
/**	定义了所有C语言的关键字***********************************************************************
*** 描述信息:
***		关键字按照字典顺序排序, 共26个, 兼容C99
*** 更新信息:
***		2013/8/17-11:57	-=>	更新注释格式,
***		2013/8/17-12:05	-=>	sizeof运算符号作为关键字存储
*************************************************************************************************/
const char keyword[MAX_KEYWORD_COUNT][20] =
{
    "keyword",                  // 0位作占位用

	/// C所有的关键字[保留字]信息
    "auto",
    "bool", "break",
    "case", "char", "const", "continue",
    "default", "do", "double",
    "else", "enum", "extern",
    "float", "for",
    "goto",
	/*h*/
    "if", "inline", "int",
    /*j-k*/
    "long",
    /*m-n-o-p-q*/
    "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef",
	"union", "unsigned",
	"void", "volatile",
    "while",
    "_Bool", "_Complex", "_Imaginary",
    /*x-y-z*/
};


/**	定义了所有C语言的关键字***********************************************************************
*** 描述信息:																					*
***		预编译指令的信息, 共13个													*
*** 更新信息:																					*
***		2013/8/21-10:26	-=>	更新注释格式,														*
***		版本0.4.0											*
*************************************************************************************************/
const char procom[MAX_PROCOM_COUNT][10] =
{
    "procom",           // 0位作为站位子用
    "",                 // 空的预编译行信息
    "include", "line",
    "define", "undef",
    "if", "elif", "else",
    "ifdef", "ifndef", "endif",
    "error", "pragma", "import",
};


///	单运算符
/**	定义了所有C语言的简单运算符号******************************************************************
***	描述信息:																					*
***		简单运算符, 为全部运算符提供辅助,															*
***		词法分析器按照单个字符读入数据，															*
***		判断器是否属于简单运算符，然后再从当前字符开始检索一个串，判断是否属于全部运算符			*
***	更新信息:																					*
***		2013/8/17-11:48	-=>	添加了注视信息，更改了部分运算符号的顺序以保证与TokenKind定义符合		*
***    2013/8/21-12:13   -=> 修改了(), []作为运算符号, 但为了方式BUG, 定义在分界符中， 作为分界符处理、
*************************************************************************************************/
const char operate[MAX_OPERATE_COUNT] =
{
'$',                                // o位作占位用
'.', ',',
'+', '-', '*', '/', '%', '=',
'<', '>',
'|', '&', '!', '^',
'?', ':', //'(', ')', '[', ']',
};


/// 全部运算符
/**	定义了所有C语言的全部运算符号******************************************************************
***	描述信息：																					*
***		这个是C标准可能出现的全部																	*
***	更新信息：																					*
***    2013/8/21-12:13   -=> 修改了(), []作为运算符号, 但为了方式BUG, 定义在分界符中， 作为分界符处理、
*************************************************************************************************/
const char allOperator[MAX_OPERATE_COUNT][4] =
{
"$",                                    // o位作占位用
",",                                                                    // 15-level
"=", "+=", "-=", "*=", "/=", "%=", "|=", "^=", "&=", ">>=", "<<=",      // 14-level
"?", ":",                                                               // 13-level
"||",                                                                   // 12-level
"&&",                                                                   // 11-level
"|",                                                                    // 10-level
"^",                                                                    // 09-level
"&",                                                                    // 08-level
"==", "!=",                                                             // 07-level
">", ">=", "<", "<=",                                                   // 06-level
">>", "<<",                                                             // 05-level
"+", "-",                                                               // 04-level
"*", /*"**", "***", "****"*/"/", "%",                                     // 03-level
"!", "~", /*"-", -12*/ "++", "--", /** &,*,（type）, "sizeof",*/     // 02-level
/*"(", ")", "[", "]",*/ ".", "->",                                          // 01-level
"...",                                                                  // 000000000
};

/// 界符
/**	定义了所有C语言的分界符号的信息****************************************************************
***	描述信息：																					*
***		定了一个C标准中虽有的分界符																*
***	更新信息：																					*
****	2013/8/17-12:03	-=>	更新了注释的格式														*
***		2013/8/17-12:06	-=>	添加了' '空格字符作为分界符号存储										*
***    2013/8/21-12:13   -=> 修改了(), []作为运算符号, 但为了方式BUG, 定义在分界符中， 作为分界符处理、
***********************************************************************************************/
const char separator[MAX_SEPARAROR_COUNT] =
{
	'$',                            // o位作占位用
	' ',
	'(', ')', '[', ']',             //
	'{', '}',
	';',
	'#',
	'\'', '\"', '\\',
	'\n', '\t', '\r',
};

///**	判断当前输入串是不是一个指针类型符号***********************************************************
//***	Function	:	IsPoint
//***	Param		:	token[CHAR*]	待处理的输入串
//***	Return		:	[BOOL]			待输入串如果形如'**'则返回true, 否则返回false
//***	Description	:	判断当前输入串token是否是***, 用来标识后面的串信息是一个指针
//***	Calls		:   NULL
//***	Called By	:	IsAllOperate	由于判断串是不是运算符号时，判断步骤为
//***									先看当前输入字符是不是简单运算符，然后再提取一个长串，
//***									看是不是一个运算符，这是可能出现问题
//***									提取出来的串如果是指针类型串需要特殊判断，
//***									然后才能看是不是一个运算符号。
//***									例如：char **ptr, ptr被定义为一个指针, 但是需要存储，
//***									但是**不是运算符，直接交给运算符号处理函数会造成**符号丢失
//***	Version		:	0.3.8
//***	Warning		:	能够处理的指针类型声明符号有限。
//*************************************************************************************************/
//int IsPoint(char *token)           // 提取出来的运算符号
//{
//    int i = 0;
//    while(token[i] != '\0' && token[i] == '*')  // the point is define as anyone "*"
//    {
//        i++;
//    }
//
//    if(token[i] == '\0')
//    {
//        return i;           // return the count of the '*' in the token
//    }
//    else
//    {
//        return NOT_FIND;    // the token is not a pointer...
//    }
//}



/**	判断当前输入符号是不是分界符号*****************************************************************
***	Function	:	IsSeparator																	*
***	Param		:	now[CHAR]	待处理的输入串													*
***	Return		:	[INT]		待处理符号如果是分界面符则返回其位置,	否则返回NOT_FIND(-1)			*
***	Description	:	判断当前字符是不是分界符号，即是不是separator[MAX_SEPARAROR]的数据域			*
***	Calls		:   NULL																		*
***	Called By	:																				*
***	Version		:	0.3.8																		*
***	Warning		:	把空格当作分界符号处理														*
***					必须保证分界符定义的顺序与ToekKind.h中的定义顺序相同那个						*
*************************************************************************************************/
int IsSeparator(const char now)
{
    //int i;
    for(int i = 1; i < MAX_SEPARAROR_COUNT; i++)  //遍历所有的分隔符
    {
        if(now == separator[i])    //分隔符数组-separator[i]
        {
            return i;
        }
    }
    return NOT_FIND;
}


/**	判断当前输入符号是不是简单运算符号*************************************************************
***	Function	:	IsOperate																	*
***	Param		:	now[CHAR]	待处理的输入串													*
***	Return		:	[INT]		待处理符号如果是简单运算符号符则返回其位置,否则返回NOT_FIND(-1)	*
***	Description	:	判断当前字符是不是简单运算符，即是不是operate[MAX_OPERATE]的数据域				*
***	Calls		:   NULL																		*
***	Called By	:																				*
***	Version		:	0.3.8																		*
***	Warning		:																				*
*************************************************************************************************/
int IsOperate(const char now)
{
    for(int i = 1; i < MAX_OPERATE_COUNT; i++)
    {
      if(now == operate[i])
      {
            return i;
      }
    }
    return NOT_FIND;
}

/**	判断当前输入串是不是符合C标准的运算符号********************************************************
*	Function	:	IsAllOperate
*	Param		:	token[CHAR*]待处理的输入串
*	Return		:	[INT]		待处理符号如果是简单运算符号符则返回其位置,否则返回NOT_FIND(-1)
*	Description	:	判断当前字符是不是简单运算符，即是不是allOperate[MAX_OPERATE]的数据域
*	Calls		:   NULL
*	Called By	:
*	Version	:	0.3.8
*				    必须保证运算符号的顺序与TokenKind.h中的定义顺序相同
*                 将多重指针进行了重新定义
*                 char **str   -=> ** 对应 DMUL_OPERATE
*                 char ***str   -=> *** 对应 TMUL_OPERATE
*                 char ****str -=>  **** 对应 fMUL_OPERATE
*                 暂时只支持三重指针，但是为其他指针提供了预留位置
*************************************************************************************************/
int IsAllOperate(const char *token)
{
    int keyCode = NOT_FIND;
    for(int pos = 1; pos < MAX_OPERATE_COUNT; pos++)
    {
        if(strcmp(token, allOperator[pos]) == 0)
        {
            //printf("%s == %s %d\n", token, allOperator[pos], pos);
            keyCode = pos;
            break;
        }
    }

    return keyCode;
}



/** IsKeyword*****************************************************************
*   \brief  :判断当前字符是不是C关键字，即是不是keyWord[MAX_KEYWORD]的数据域
*   \param  :	token[CHAR*]待处理的输入串
*   \return :	待处理符号如果是关键字则返回其位置,否则返回NOT_FIND(-1)
*	\bug    :	必须保证关键字的顺序与TokenKind.h中的定义顺序相同
******************************************************************************/
int IsKeyword(const char *token)
{
    for(int pos = 1; pos < MAX_KEYWORD_COUNT; pos++)
    {
        if (strcmp(token, keyword[pos]) == 0)
        {
            #ifdef  LEXICAL_DEBUG_DEFINE
            printf("%s == %s, %d\n", token, keyword[pos], pos);
            #endif // LEXICAL_DEBUG_DEFINE


            return pos;
        }
    }

    return NOT_FIND;
}



/**	IsProCom*********************************************************************************
*	\brief	:	判断当前字符是不是预编译指令符，即是不是procom[MAX_OPERATE]的数据域
*	\param		:	token[CHAR*]	待处理的输入串
*	\return		:	[INT]		待处理符号如果是预编译指令符则返回其位置,否则返回NOT_FIND(-1)
********************************************************************************************/
int IsProCom(const char *token)
{
    for(int i = 1; i < MAX_PROCOM_COUNT; i++)
    {
        if(strcmp(token, procom[i]) == 0)
        {
            return i;
        }
    }

    return NOT_FIND;
}






/**	判断当前输入串是不是常量信息*******************************************************************
***	Function	:	IsConstant
***	Param		:	str[CHAR*]待处理的输入串
***	Return		:	[INT]		待处理符号如果是常量串则返回其位置,否则返回NOT_FIND(-1)
***	Description	:	判断当前输入串是不是常量信息
***	Calls		:   NULL
***	Called By	:
***	Version		:	0.3.8
***	Warning		:	必须保证关键字的顺序与TokenKind.h中的定义顺序相同
*************************************************************************************************/
TokenKind IsConstant(const char *str)
{
    int     i;              // 循环字符串的每一位
    int     count = 0;         // 用于标识浮点数的小数点数目
    //int     flag = -1;           // 用于标识是整数[0]还是浮点数[1]

    #ifdef LEXICAL_DEBUG_DEFINE
    printf("待判断的常量串%s\n", str);
    PAUSE( );
    #endif // LEXICAL_DEBUG_DEFINE

    if(str[0] == '0' && (str[1]  == 'x' || str[1] == 'X'))          // 如果当前数据可能是16进制数
    {
        i = 2;
        //flag = 0;           // 此数据是一个整型常量
        while(IsHexDigit(str[i]) == true)          // 检索当前字符串每一位是否是符合要求的16进制数据位
        {
            i++;
        }
        if(str[i] == '\0')          // 检索成功就是一个整形常量
        {
            return INT_CONST;
        }
    }
    else if(str[0] == '0')
    {
        i = 1;
        //flag = 0;            // 此数据是一个整型常量
        while(IsOctDigit(str[i]) == true)           // 检索当前字符串的每一位是否是符合要求的8进制数据位
        {
            i++;
        }
        if(str[i] == '\0')          // 检索成功就是一个八进制常量
        {
            return INT_CONST;
        }
    }

    i = 0;
    while(IsDigit(str[i]) == true || str[i] == '.')
    {
        if(str[i] == '.')           // 计算浮点数的小数点数目
        {
            count++;
        }
        i++;
    }

    if(count == 0 && str[i] == '\0')          // 整形常量没有一位小数点
    {
        return INT_CONST;
    }
    else if(count == 1 && str[i] == '\0')     // 浮点数只有一位小数点
    {
        return FLOAT_CONST;
    }
    else
                            // 小数点数目错误，定义有误
    {
        return TOKEN_NULL;
    }
}

