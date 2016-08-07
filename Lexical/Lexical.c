/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Lexical.c                                                      *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3NOT_FIND0 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/


#include "Lexical.h"    //  #include "..\Lexical\Lexical.h"



// 来自与TokenKind中的外部变量
extern const char keyword[MAX_KEYWORD_COUNT][MAX_KEYWORD_SIZE];         // 所有的关键字变量
extern const char procom[MAX_PROCOM_COUNT][MAX_PROCOM_SIZE];           // 预编译指令定义
extern const char operate[MAX_OPERATE_COUNT];             // 简单运算符定义
extern const char allOperator[MAX_OPERATE_COUNT][MAX_OPERATE_SIZE];      // 运算符定义
extern const char separator[MAX_SEPARAROR_COUNT];         // 分界符定义



#ifdef PUBLIC_and_PRIVATE
#
#
/// 基本操作函数
//// 返回当前关键字信息的种别码
//PRIVATE int KeyCode(char *token);
#
#
/// 对token记录进行词法分析, 将信息填入douTuple元组, 缓冲区为douBuffer, 符号表是symbolTable
PRIVATE TupleNode*              // 返回指向插入的词法信息的指针
Scanner(
        TupleNode *oldNode,             // 原来词法信息表的末尾
        DouBuffer *douBuffer);           // 缓冲区信息
#define scanner Scanner
#
#
/// 对待编译文件中的分界符信息进行处理
PRIVATE TupleNode*
LexSeparator(
             TupleNode *pNode,
             DouBuffer *douBuffer);
#
#
/// 对待编译文件中的运算符信息进行处理
PRIVATE TupleNode*
LexOperator(
            TupleNode *pNode,
            DouBuffer *douBuffer);
#define dis_pro_operator DisProOperator
#
#
PRIVATE TupleNode*
LexCharacter(
             TupleNode *pNode,         // 词法信息的尾结点
             DouBuffer *douBuffer);     // 双缓冲区信息
#
#
/// 处理运算符的函数段
PRIVATE TupleNode *
LexString(
          TupleNode *pNode,         // 词法信息的尾结点
          DouBuffer *douBuffer);     // 双缓冲区信息
#
#
PRIVATE TupleNode*
LexIncludeFile(TupleNode *pNode,
               DouBuffer *douBuffer);
#
#
/// 处理常量信息
PRIVATE TupleNode*
LexConstant(TupleNode *pNode,                   // 指向词法二元组链表最后一个词法结点的指针
            DouBuffer *douBuffer);               // 双缓冲区信息
#
#
/// 处理待编译文件中的预编译信息
PRIVATE Coord*                        // 返回修改后的语法信息
LexLinePro(
          DouBuffer *douBuffer);    // 双缓冲区信息
#
#
/// 处理待编译文件中的预编译信息
PRIVATE TupleNode*                        // 返回插入的词法结点
LexProCom(
          TupleNode *pNode,         // 词法二元组信息
          DouBuffer *douBuffer);    // 双缓冲区信息
#
#
/// 处理控制字符
PRIVATE bool        // 如果文件结束返回TRUE， 否则返回FALSE
LexCntrl(
        DouBuffer *douBuffer);
#
#
// 跳过预编译指令信息
PRIVATE void
SkipProcom(
           DouBuffer *douBuffer);
#endif          // PUBLIC_and_PRIVATE



/// 处理存在的预编译指令信息[#line  #program]
/**	处理存在的预编译指令信息[#line]***********************************************************
***	Function	:	IsPoint
***	Param		:	douBuffer[DOUBUFFER*] 待处理的文件缓冲区信息
***               ifp      [CTOOLSFILE] 指向待处理文件的文件指针
                  coord    [COORD*]     表示文件信息的标识
***	Return		:	Coord*  对#line需要重新定位Coord的信息，返回修改后的coord标识
***	Description:	处理存在的预编译指令信息[#line]
***	Calls		:   NULL
***	Called By	:	文件中如果存在#开头的预编译指令, 则首先交给LexProCom函数进行处理, 将信息标识下来
                  如果提取出来的预编译指令是#line, 则调用此函数对源文件行号标识进行重新定位
***	Version		:	0.4.2后进行了重新定义
***	Warning		:	对pragma指令的处理还未进行定义
********************************************************************************************/
Coord* LexLinePro(DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(*(douBuffer->m_forward) == '#');     // 预编译指令以#开始
#endif // LEICAL_DEBUG_DEFINR

    char *token = NULL;

    //DisBufSpace(douBuffer);     // 由于预编译命令后面可以跟上数个空白字符
    /// 首先读取到必要的行号信息
    do
    {
        AddBufForward(douBuffer);             // 找到行号的信息
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }while(IsDigit(*(douBuffer->m_forward)) == true);       // 找到最后一个不是数字的字符
    token = CopyBufToken(douBuffer);           // 将行号以数字的方式取出来

    // 将检索出来的行号标识日安如行信息标识中
    douBuffer->m_coord->m_fileLine = atoi(token) - 1;
    free(token);

    #ifdef  LEXICAL_DEBUG_DEFINE
    printf("提取出来的行号信息LINE = %d\n", douBuffer->m_coord->m_fileLine);
    #endif  // LEXICAL_DEBUG_DEFINE

    /// 下面读取到指令指示到的文件
    do      // 指令这个字符串以"开始
    {
        AddBufForward(douBuffer);      // 持续让向前指针增加
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }while(*(douBuffer->m_forward-1) != '\"');
    CheckLexemeToForward(douBuffer);        // 定位开始指针到当前循环找的位置
    ////CheckBegOffsetToEndOffset(coord);

    do          // 定位到文件名字的结束位置也就是“的位置
    {
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }while(*(douBuffer->m_forward) != '\"');

    if((token = CopyBufToken(douBuffer)) != NULL)  // 取出指示到的文件名
    {
        douBuffer->m_coord->m_fileName = token;          // 将文件行表示的文件名指针域指向提取出来的文件名字符串

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("更改词法信息的文件名为：%s\n", douBuffer->m_coord->m_fileName);
        printf("更改词法信息的文件行为：%d\n", douBuffer->m_coord->m_fileLine);
        #endif      // LEXICAL_DEBUG_DEFINE
    }

    /// 跳过该预编译命令的后面其他信息
    do
    {
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }while(*(douBuffer->m_forward) != '\r' && *(douBuffer->m_forward) != '\n');

    CheckLexemeToForward(douBuffer);
    //CheckBegOffsetToEndOffset(coord);

    return douBuffer->m_coord;           // 返回当前的文件行标识
}





TupleNode* LexProCom(TupleNode *pNode, DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(*(douBuffer->m_forward) == '#');     // 预编译指令以#开始
#endif // LEICAL_DEBUG_DEFINR

    char *token = NULL;
    int  keyCode = NOT_FIND;
    // 首先找到#编译指令符号后面第一个非空白符号
    //DisBufSpace(douBuffer);           // 由于预编译指令后面可以跟上任意的空白字符
    #ifdef LEXICAL_DEBUG_DEFINE
    printf("当前字符%c, 偏移%d %d\n", *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
    #endif  // LEXICAL_DEBUG_DEFINE
    do
    {
        AddBufForward(douBuffer);      // 找到当前这个串信息的末尾
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("当前字符%c, 偏移%d %d\n", *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
        #endif  // LEXICAL_DEBUG_DEFINE
    }while(IsLetterOrDigit(*(douBuffer->m_forward)) == true);

    if((token = CopyBufToken(douBuffer)) != NULL)     // 取出中间的字符串
    {
        if((keyCode = IsProCom(token)) != NOT_FIND)
        {
            if(strcmp(token, "line") == 0)
            {
                free(token);
                douBuffer->m_coord = LexLinePro(douBuffer);
            }
            else if (strcmp(token, "include") == 0)
            {
                free(token);
                //DisBufSpace(douBuffer);
                //LexIncludeFile(pNode, douBuffer, ifp, coord);
            }
            else
            {
            //    pNode = newNode;
                CheckLexemeToForward(douBuffer);
                //CheckBegOffsetToEndOffset(coord);
                free(token);
            }
        }
        else
        {
        #ifdef    CTOOLS_LEX_ERRO_DEFINE
        ///////////////////////////////////////////////////////////////////////////////////////////////
        /**/Error(coord, "the %s can't distinguish as Operator", token);// 无法被识别的运算符号////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        #endif // CTOOLS_LEX_ERRO_DEFINE
        }
    }


    DisBufProcom(douBuffer);
    CheckLexemeToForward(douBuffer);
    //CheckBegOffsetToEndOffset(coord);
    //DisBufSpace(douBuffer);

    #ifdef LEXICAL_DEBUG_DEFINE
    printf("预处理后当前字符%c\n", *(douBuffer->m_forward));
    printf("预处理后当前字符%c\n", *(douBuffer->m_forward));
    #endif // LEXICAL_DEBUG_DEFINE

    return pNode;
}





/// 处理控制字符
bool LexCntrl(DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE

    // 输出分隔符，空格、换行符、制表符除外
    if(iscntrl(*(douBuffer->m_forward)) != 0
    && *(douBuffer->m_forward) != '\t'
    && *(douBuffer->m_forward) != '\n')
    {
        //printf("当前为空格-换行-或者制表符, 或者不可打印\n");
        #ifdef LEXICAL_DEBUG_DEFINE
        printf("偏移%d\n", douBuffer->m_coord->m_fileBegOffset);
        #endif // LEXICAL_DEBUG_DEFINE

        DisBufControl(douBuffer);
        //while(iscntrl(*(douBuffer->m_forward)) != 0); // 跳过分隔符，空格、换行符、制表符除外

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("当前的字符是%c = %d", *(douBuffer->m_forward), *(douBuffer->m_forward));
        #endif

        CheckLexemeToForward(douBuffer);
        //CheckBegOffsetToEndOffset(coord);
        ///-////////////////////////////////////////////////////////////////////////////
        ///-AddBufForward(douBuffer->m_forward, ifp);  将这行加入编译会产生非常奇怪的问题
        ///-////////////////////////////////////////////////////////////////////////////
    }

    if(*(douBuffer->m_forward) == (char)CToolsIsEOF)
    {
        if(feof(douBuffer->m_fp) == 0)         // 如果不是文件结束
        {
            PutBuffer(douBuffer);       // 向另外一个缓冲区写入信息
            return false;
        }
        else        // 否则说明是文件结束, 终止词法分析
        {
            #ifdef LEXICAL_HELPS_DEFINE         // 利用帮助宏 -=> 提示文件已经结束
            FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
            printf("\t\t**********************************************\n");
            printf("\t\t******The File is End...................******\n");
            printf("\t\t**********************************************\n");
            PAUSE( );
            #endif      // LEXICAL_HELPS_DEFINE

            return true;
        }
    }

    return false;
}

/*
在C中，字符和整数并没有什么本质的区别。
char可以看成是1个字节的整数，
short可以看成2个字节的宽字符，
int可以看成4个字节的宽字符。
所以，'a'表示一个字符'a'，'ab'则表示一个2个字节的整数或者宽字符，
'abcd'则表示一个4个字节的整数或宽字符。但是只支持1字节、2字节、4字节。
char c='a'; //当然没错了
char c='ab'; //相当于整数 char c=0x6162。因为'a'字符表示0x61，'b'字符表示0x62。但因为'ab'是2个字节，所以赋给char时会出整数截断的警告。
char c='abc'; //相当于整数char c=0x00616263，也会出警告。
char c='abcd'; //相当于整数char c=0x61626364，也会出警告。
char c='abcde'; //超出最大整数字节长度4。当错误处理
*/
TupleNode* LexCharacter(TupleNode *pNode, DouBuffer *douBuffer)              // 词法数目
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(*(douBuffer->m_forward) == '\'');         // 当前字符串必须是单引号
#endif  // LEXICAL_DEBUG_DEFINE

    char *token = NULL;                     // 用于存储串信息
    TupleNode *newNode = NULL;              // 用于存储字符串信息

    /// 将向前指针指向'的末尾
    do          /// 循环跳过所有的字符串信息
    {
        if(*(douBuffer->m_forward) == '\n' || *(douBuffer->m_forward) == '\r' || *(douBuffer->m_forward) == EOF)       // 遇见了换行却仍然没有找到"
        {   // 说明源文件有错误
            /// stdERR这里会出现一个错误, 如果源代码只有一个单引号可能会出现错误
            ///Error(crood, "");
            break;
        }

        AddBufForward(douBuffer);             // 循环跳过所有与的""之间字符信息
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1

    }while(*(douBuffer->m_forward) != '\'');    // 现在字符停留在后面的"位置

    if(*(douBuffer->m_forward) == '\'')
    {
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1

        /// 将字符串面变量添加进入词法二元组
        if((token = CopyBufToken(douBuffer)) != NULL)      // 读取‘’之间的字符面变量
        {
            #ifdef CTOOLS_LEX_WARN_DEFINE
            if(strlen(token) > INT_SIZE)           // 长度大于正常的整形长度将提示溢出截断警告
            {
                Warning(coord, "overflow in implicit constant conversion\n");
            }
            if(strlen(token) > 1)           // 字符的长度大于1给出字符常量长度过长的警告
            {
                Warning(coord, "character constant too long for its type\n");
            }
            #endif

            // 需要将信息插入二元组中[项为:字符串面变量]
            if((newNode = InsertTupleLiteral(pNode, token, douBuffer->m_coord, CHAR_CONST)) != NULL)
            {
                pNode = newNode;

                #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
                printf("\n字符\n");

                SHOW_FILE_NAME(pNode->m_tuple.m_coord.m_fileName);
                printf("Line = %d  ", pNode->m_tuple.m_coord.m_fileLine);
                printf("Begi = %d ", pNode->m_tuple.m_coord.m_fileBegOffset);
                printf("Endl = %d ", pNode->m_tuple.m_coord.m_fileEndOffset);
                printf("[%d, %s]\n", CONST, token);
                #endif      // LEXICAL_SHOWS_DEFINE
            }
            else
            {   /// 程序如果走到这里，说明程序出错了
                printf("将字符串面变量%s插入词法二元组的时候出错\n", token);
            }
        }
        else
        {
            /// 程序如果走到这里，说明程序出错了
            printf("将分界符%c插入词法二元组的时候出错\n", *(douBuffer->m_forward));
        }
    }
    else                    // 未找到字符'‘的结尾
    {
    #ifdef CTOOLS_LEX_ERRO_DEFINE
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /**/Error(coord, "missing terminating \' Character...");//字符面变量‘’未匹配////////////////////////
    /**/douBuffer->m_forward = douBuffer->m_lexeme;///////////回退到开始字符面变量开始的位置////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    #endif // CTOOLS_LEX_DRR_DEFINE
    }

    //CheckLexemeToForward(douBuffer);
    ////CheckBegOffsetToEndOffset(coord);
    douBuffer->m_forward--;
    douBuffer->m_coord->m_fileEndOffset--;
    //SubBufForward(douBuffer);
    return pNode;               // 返回词法二元组的地址
}


/// 处理运算符的函数段
TupleNode * LexString(TupleNode *pNode, DouBuffer *douBuffer)          // 文件指针信息
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(*(douBuffer->m_forward) == '\"');
#endif // DEBUG_DEFINE

    char *token = NULL;                   // 用于存储串信息
    TupleNode *newNode = NULL;              // 用于存储字符串信息

    do          /// 循环跳过所有的字符串信息
    {
        if(*(douBuffer->m_forward) == '\n' || *(douBuffer->m_forward) == '\r' || *(douBuffer->m_forward) == (char)EOF)     // 遇见了换行却仍然没有找到"
        {   // 说明源文件有错误
            /// stdERR这里会出现一个错误, 如果源代码只有一个单引号可能会出现错误
            ///Error(crood, "");
            break;
        }

        AddBufForward(douBuffer);             // 循环跳过所有与的""之间字符信息
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1

    }while(*(douBuffer->m_forward) != '\"' || *(douBuffer->m_forward - 1) == '\\');    // 现在字符停留在后面的"位置


    if(*(douBuffer->m_forward) == '\"')      // 只有当前字符是", 取出来的字符串才是字符串面变量
    {
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
        /// 将字符串面变量添加进入词法二元组
        if((token = CopyBufToken(douBuffer)) != NULL)      // 读取""之间的字符串面变量
        {   // 需要将信息插入二元组中[项为:字符串面变量]
            if((newNode = InsertTupleLiteral(pNode, token, douBuffer->m_coord, STRING_CONST)) != NULL)
            {
                pNode = newNode;

                #ifdef LEXICAL_SHOWS_DEFINE      // 利用帮助宏 -=> 显示发现词法信息的类型
                printf("\n字符串\n");

                SHOW_FILE_NAME(pNode->m_tuple.m_coord.m_fileName);
                printf("Line = %d  ", pNode->m_tuple.m_coord.m_fileLine);
                printf("Begi = %d ", pNode->m_tuple.m_coord.m_fileBegOffset);
                printf("Endl = %d ", pNode->m_tuple.m_coord.m_fileEndOffset);
                printf("[%d, %s]\n", CONST, token);
                #endif      // LEXICAL_SHOWS_DEFINE
            }
            else
            {   /// 程序如果走到这里，说明程序出错了
                printf("将字符串面变量%s插入词法二元组的时候出错\n", token);
            }
        }
        else
        {
            /// 程序如果走到这里，说明程序出错了
            printf("将分界符%c插入词法二元组的时候出错\n", *(douBuffer->m_forward));
        }
    }
    else                    // 未找到字符'‘的结尾
    {
    #ifdef CTOOLS_LEX_ERRO_DEFINE
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /**/Error(douBuffer->m_coord, "missing terminating \" String...");//字符串面变量""未配对/////////////////////////
    /**/douBuffer->m_forward = douBuffer->m_lexeme;////////回退到开始字符面变量开始的位置///////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    #endif //CTOOLS_LEX_DRR_DEFINE
    }

    //CheckLexemeToForward(douBuffer);
    ////CheckBegOffsetToEndOffset(coord);

    douBuffer->m_forward--;
    douBuffer->m_coord->m_fileEndOffset--;

    return pNode;               // 返回词法二元组的地址
}



/**	LexIncludeFile***************************************************************************
*   \brief  the function can display the file name in "include<filename>"
*   \param  pNode       the node point to the tuple of the lexical
*   \param  doubuffer   the buffer which you read file in
*   \param  ifp         the file pointer point to the file you want to compiler
*   \param  coord       the global coord of the current char you display
*   \return return the node which point to the tuple if you find
********************************************************************************************/
TupleNode* LexIncludeFile(TupleNode *pNode, DouBuffer *douBuffer)              // 词法数目
{
    #ifdef LEXICAL_DEBUG_DEFINE
    assert(*(douBuffer->m_forward) == '<');         // 当前字符串必须是单引号
    #endif  // LEXICAL_DEBUG_DEFINE

    int keyCode = IsAllOperate("<");        // 计算'的编码信息
    char *token = NULL;                     // 用于存储串信息
    TupleNode *newNode = NULL;              // 用于存储字符串信息

    /// 需要将信息插入二元组中[项为:分界符], 符号特定为'
    if((newNode = InsertTupleKey(pNode, OPERATE, keyCode, douBuffer->m_coord)) != NULL)
    {
        pNode = newNode;

        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1

        CheckLexemeToForward(douBuffer);
        //CheckBegOffsetToEndOffset(coord);
        ///*count += 1;

        #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
        printf("\n运算符\n");

        SHOW_FILE_NAME(pNode->m_tuple.m_coord.m_fileName);
        printf("Line = %d  ", pNode->m_tuple.m_coord.m_fileLine);
        printf("Begi = %d ", pNode->m_tuple.m_coord.m_fileBegOffset);
        printf("Endl = %d ", pNode->m_tuple.m_coord.m_fileEndOffset);
        printf("[%d, %s]\n", OPERATE, allOperator[keyCode]);        // 将"保存输出
        #endif         // LEXICAL_SHOWS_DEFINE
    }
    else
    {
        /// 程序如果走到这里，说明程序出错了
        printf("将分界符%c插入词法二元组的时候出错\n", *(douBuffer->m_forward));
    }

    /// 将向前指针指向'的末尾
    do          /// 循环跳过所有的字符串信息
    {
        if(*(douBuffer->m_forward) == '\n' || *(douBuffer->m_forward) == '\r' || *(douBuffer->m_forward) == EOF)       // 遇见了换行却仍然没有找到"
        {   // 说明源文件有错误
            /// stdERR这里会出现一个错误, 如果源代码只有一个单引号可能会出现错误
            ///Error(crood, "");
            break;
        }
        AddBufForward(douBuffer);             // 循环跳过所有与的""之间字符信息
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1

    }while(*(douBuffer->m_forward) != '>');    // 现在字符停留在后面的"位置

    if(*(douBuffer->m_forward) == '>')      // 只有当前字符是‘, 取出来的字符串才是字符面变量
    {
        /// 将字符串面变量添加进入词法二元组
        if((token = CopyBufToken(douBuffer)) != NULL)      // 读取‘’之间的字符面变量
        {
            #ifdef CTOOLS_LEX_WARN_DEFINE
            if(strlen(token) > INT_SIZE)           // 长度大于正常的整形长度将提示溢出截断警告
            {
                Warning(coord, "overflow in implicit constant conversion\n");
            }
            if(strlen(token) > 1)           // 字符的长度大于1给出字符常量长度过长的警告
            {
                Warning(coord, "character constant too long for its type\n");
            }
            #endif

            // 需要将信息插入二元组中[项为:字符串面变量]
            if((newNode = InsertTupleLiteral(pNode, token, douBuffer->m_coord, STRING_CONST)) != NULL)
            {
                pNode = newNode;
                ///*count += 1;

                #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
                printf("\n字符串\n");


                SHOW_FILE_NAME(pNode->m_tuple.m_coord.m_fileName);
                printf("Line = %d  ", pNode->m_tuple.m_coord.m_fileLine);
                printf("Begi = %d ", pNode->m_tuple.m_coord.m_fileBegOffset);
                printf("Endl = %d ", pNode->m_tuple.m_coord.m_fileEndOffset);
                printf("[%d, %s]\n", CONST, token);
                #endif      // LEXICAL_SHOWS_DEFINE
            }
            else
            {   /// 程序如果走到这里，说明程序出错了
                printf("将字符串面变量%s插入词法二元组的时候出错\n", token);
            }
        }

        // 需要将信息插入二元组中[项为:分界符], 符号特定为"
        keyCode = IsAllOperate(">");        // 计算'的编码信息
        if((newNode = InsertTupleKey(pNode, OPERATE, keyCode, douBuffer->m_coord)) != NULL)
        {
            pNode = newNode;
            CheckLexemeToForward(douBuffer);

            AddBufLexeme(douBuffer);
            ///*count += 1;

            #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
            printf("\n分界符\n");
            ShowTupleNode(pNode);
            #endif      // LEXICAL_SHOWS_DEFINE
        }
        else
        {
            /// 程序如果走到这里，说明程序出错了
            printf("将分界符%c插入词法二元组的时候出错\n", *(douBuffer->m_forward));
        }
    }
    else                    // 未找到字符'‘的结尾
    {
    #ifdef CTOOLS_LEX_ERRO_DEFINE
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /**/Error(coord, "missing terminating \' Character...");//字符面变量‘’未匹配////////////////////////
    /**/douBuffer->m_forward = douBuffer->m_lexeme;///////////回退到开始字符面变量开始的位置////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    #endif // CTOOLS_LEX_DRR_DEFINE
    }


    return pNode;               // 返回词法二元组的地址
}


/// 对token记录进行词法分析, 将信息填入douTuple元组尾部pNode, 缓冲区为douBuffer, 符号表是symbolTable
TupleNode* Scanner(TupleNode *pNode, DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE
    char *token = NULL;
    int keyCode = NOT_FIND;

    // 如果当前位置的信息满足合法的变量名称要求, 说明当前标识符或者关键字还没有结束
    if(IsLetterOrDigit(*(douBuffer->m_forward)) == true)
    {
        #ifdef LEXICAL_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // LEXICAL_DEBUG_DEFINE

        printf("当前字符仍然可以作为一个符合要求的标识符, 继续进行超前搜索\n");
        return NULL;            // 当前标识符仍然没有结束, 应该提前返回
    }

    if((token = CopyBufToken(douBuffer)) == NULL)      // 首先将缓冲区中的串取出来
    {
        #ifdef LEXICAL_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // LEXICAL_DEBUG_DEFINE

        return NULL;
    }

    #ifdef LEXICAL_DEBUG_DEFINE
    FILE_FUNC_LINE( );
    printf("当前取出来的串信息：%s\n", token);
    ShowCoord(douBuffer->m_coord);
    printf("\n");
    #ifdef CTOOLS_STEPS_DEFINE
    PAUSE( );
    #endif      //  CTOOLS_STEPS_DEFINE
    #endif // LEXICAL_DEBUG_DEFINE
    TupleNode *newNode = NULL;     // 新建二元组结点

    if((keyCode = IsKeyword(token)) != NOT_FIND)   /// 是关键字
    {
        // 构建二元组的信息
        if((newNode = InsertTupleKey(pNode, KEYWORD, keyCode, douBuffer->m_coord)) != NULL) // 将token串当作关键字插入Tuple
        {
            pNode = newNode;

            // 输出当前的信息
            #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
            printf("\n关键字\n");
            ShowTupleNode(pNode);
            #endif      // LEXICAL_SHOWS_DEFINE
        }
        else        /// 程序如果走到这列说明程序出错了
        {
            printf("ERROR:程序将关键字%s插入到词法表的时候出错\n", token);
            PAUSE( );
        }
    }
//    else if((keyCode = IsProCom(token)) != NOT_FIND)   /// 是关键字
//    {
//        // 构建二元组的信息
//        if((newNode = InsertTupleKey(pNode, PROCOM, keyCode, douBuffer->m_coord)) != NULL) // 将token串当作关键字插入Tuple
//        {
//            pNode = newNode;
//
//            // 输出当前的信息
//            #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
//            printf("\n预编译\n");
//            ShowTupleNode(pNode);
//            #endif      // LEXICAL_SHOWS_DEFINE
//        }
//        else        /// 程序如果走到这列说明程序出错了
//        {
//            printf("ERROR:程序将关键字%s插入到词法表的时候出错\n", token);
//            PAUSE( );
//        }
//    }
    else            /// token既非关键字，又非常量，则判断为标识符，输出token并置空
    {
        // 构建二元组的信息
        if((newNode = InsertTupleId(pNode, token, douBuffer->m_coord)) != NULL) // 将token串当作标识符插入Tuple和sysmbolTable
        {
            pNode = newNode;

            #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
            printf("\n标识符\n");
            ShowTupleNode(pNode);
            #endif      // LEXICAL_SHOWS_DEFINE
        }
        else
        {
            printf("ERROR:程序将标识符%s插入到符号表的时候出错\n", token);
            PAUSE( );
            /// 程序如果走到这列说明程序出错了
        }
    }

    CheckLexemeToForward(douBuffer);

    return pNode;           // 返回当前二元组的的末尾结点
}



/// 处理分界符的函数段
/**	处理待编译文件中的分界面符号的信息*****************************************************
***	Function	:	IsPoint
***	Param		:	pNode    [TUPLENODE*] 词法二元组链表尾指针
***               douBuffer[DOUBUFFER*] 待处理的文件缓冲区信息
***               ifp      [CTOOLSFILE] 指向待处理文件的文件指针
***               coord    [COORD*]     表示文件信息的标识
***	Return		:	Coord*  对#line需要重新定位Coord的信息，返回修改后的coord标识
***	Description:	预处理文件中不会再有注视信息, 因此注释信息将不在判断
***	Calls		:   NULL
***	Called By	:	处理原文件时， 如果遇见分界符, 先将分界符添加在词法二元组链表中
                  在调用此函数进行后面信息标识符的处理， 因为源文件中分界符后面可能出现标识符等信息
***	Version	:	0.4.2
***	Warning	:	源文件中存在#预编译指令, 而预编译文件中不存在
***************************************************************************************/
TupleNode* LexSeparator(TupleNode *pNode, DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE
    int         keyCode = NOT_FIND;
    TupleNode   *newNode = NULL;

    //if(*(douBuffer->m_forward) == ' ' || *(douBuffer->m_forward) == '\t')          // 如果当前字符是空格
    if(IsSpace(*douBuffer->m_forward) == true)
    {
        #ifdef LEXICAL_DEBUG_DEFINE
        printf("当前为SPACE字符\n");
        #endif      // LEXICAL_DEBUG_DEFINE
        //printf("=======%d", *(douBuffer->m_forward));
        /// 如果下一个字符还是空格、换行、制表符、或者不可打印字符
        DisBufSpace(douBuffer);

        CheckLexemeToForward(douBuffer);

        douBuffer->m_forward--;
        douBuffer->m_coord->m_fileEndOffset--;
    }
    else if(*(douBuffer->m_forward) == '\"')                   // 当前字符是双引号, 则可能遇见了一个字符串常量
    {
        if((newNode = LexString(pNode, douBuffer)) != NULL)       // 处理中间字符串
        {
            pNode = newNode;
            CheckLexemeToForward(douBuffer);

            AddBufLexeme(douBuffer);           // 在插入了符号之后, 将开始指针移动到下一位
        }
    }
    else if(*(douBuffer->m_forward) == '\'')         // 当前字符是单引号', 可能出现了一个字符常量
    {
        if((newNode = LexCharacter(pNode, douBuffer)) != NULL);
        {
            pNode = newNode;
            CheckLexemeToForward(douBuffer);
            //CheckBegOffsetToEndOffset(coord);
//            douBuffer->m_lexeme++;          // 在插入了符号之后, 将开始指针移动到下一位
//            coord->m_fileBegOffset++;
            AddBufLexeme(douBuffer);                // 在插入了符号之后, 将开始指针移动到下一位
        }
    }
    else if(*(douBuffer->m_forward) == '#')
    {
        LexProCom(pNode, douBuffer);
        CheckLexemeToForward(douBuffer);

        AddBufLexeme(douBuffer);                // 在插入了符号之后, 将开始指针移动到下一位

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("当前字符%c, 偏移%d %d\n", *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
        #endif  // LEXICAL_DEBUG_DEFINE
    }
    else if((keyCode = IsSeparator(*(douBuffer->m_forward))) != NOT_FIND)  // 当前字符是分界符
    {
        // 需要将信息插入二元组中[项为:分界符]
        if((newNode = InsertTupleKey(pNode, SEPARATOR, keyCode, douBuffer->m_coord)) != NULL)
        {
            pNode = newNode;
            CheckLexemeToForward(douBuffer);

            AddBufLexeme(douBuffer);                // 在插入了符号之后, 将开始指针移动到下一位

            #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
            printf("\n分界符\n");
            ShowTupleNode(pNode);
            #endif      // LEXICAL_SHOWS_DEFINE


        }
        else
        {
            /// 程序如果走到这里，说明程序出错了
            printf("将分界符%c插入词法二元组的时候出错\n", *(douBuffer->m_forward));
        }
    }

    return pNode;
}




/// 处理运算符号的函数段
/**	处理预编译文件中的运算符号***********************************************************
***	Function	:	IsPoint
***	Param		:	pNode    [TUPLENODE*] 词法二元组链表尾指针
***               douBuffer[DOUBUFFER*] 待处理的文件缓冲区信息
***               ifp      [CTOOLSFILE] 指向待处理文件的文件指针
***               coord    [COORD*]     表示文件信息的标识
***	Return		:	Coord*  对#line需要重新定位Coord的信息，返回修改后的coord标识
***	Description:	预处理文件中不会再有注视信息, 因此注释信息将不在判断
***	Calls		:   NULL
***	Called By	:	处理原文件时， 如果遇见运算符号, 先将运算符添加在词法二元组链表中
                  在调用此函数进行后面信息标识符的处理， 因为源文件中运算符后面可能出现标识符等信息
***	Version		:	0.4.2此函数段废弃, 源文件和预编译文件进行同样的处理方式
***	Warning		:	源文件中存在注释信息, 而预编译文件中已经在预处理阶段将注释信息剔除
***************************************************************************************/
TupleNode* LexOperator(TupleNode *pNode, DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE
    char        *token = NULL;
    int         keyCode = NOT_FIND;
    TupleNode   *newNode = NULL;


    // 对注释信息进行排除
    if(*(douBuffer->m_forward) == '/' && *(douBuffer->m_forward + 1) == '/') // 判断是否为单行注释//
    {   // 排除//行注释

        DisBufCurrLine(douBuffer);
        CheckLexemeToForward(douBuffer);

        AddBufLexeme(douBuffer);                // 在插入了符号之后, 将开始指针移动到下一位

    }
    else if(*(douBuffer->m_forward) == '/' && *(douBuffer->m_forward + sizeof(char)) == '*')  // 判断是否为单行注释//
    {   // 排除/**/型注释
        DisBufCommentLine(douBuffer);
        CheckLexemeToForward(douBuffer);

        AddBufLexeme(douBuffer);
    }
    else if(IsOperate(*(douBuffer->m_forward) != NOT_FIND))            // 否则是运算符
    {
        char *oldLexeme = douBuffer->m_lexeme;
        char *oldForward = douBuffer->m_forward;

        // 由于运算符里面可能出现单运算符+，双运算符++， 三运算符>>=
        do
        {
            AddBufForward(douBuffer);
            //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
        }while(IsOperate(*(douBuffer->m_forward)) != NOT_FIND);     // 只要后面仍然是运算符就++

        if((token = CopyBufToken(douBuffer)) != NULL)            // 找出字符串
        {
            if((keyCode = IsAllOperate(token)) != NOT_FIND)
            {
                /// 将检索出来的运算符填入二元组中
                if((newNode = InsertTupleKey(pNode, OPERATE, keyCode, douBuffer->m_coord)) != NULL)
                {
                    pNode = newNode;

                    #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
                    printf("\n运算符\n");
                    ShowTupleNode(pNode);
                    #endif      // LEXICAL_SHOWS_DEFINE
                }
            }
            else
            {
                printf("无法被识别的运算符号\n", token);
                free(token);
                #ifdef    CTOOLS_LEX_ERRO_DEFINE
                ///////////////////////////////////////////////////////////////////////////////////////////////
                /**/Error(coord, "the %s can't distinguish as Operator", token);// 无法被识别的运算符号////////
                ///////////////////////////////////////////////////////////////////////////////////////////////
                #endif // CTOOLS_LEX_ERRO_DEFINE
            }
        }

        CheckLexemeToForward(douBuffer);

        douBuffer->m_forward--;      // 运算符向前返回一位
        douBuffer->m_coord->m_fileEndOffset--;
    }
    return pNode;
}





/// 对常量信息进行处理
TupleNode* LexConstant(TupleNode *pNode, DouBuffer *douBuffer)
{
    #ifdef LEXICAL_DEBUG_DEFINE
    assert(IsDigit(*douBuffer->m_forward) == true);
    #endif // LEICAL_DEBUG

    char        *token = NULL;
    TokenKind    kind = TOKEN_NULL;
    TupleNode   *newNode = NULL;

    CheckLexemeToForward(douBuffer);            // 首先移动到字符串开头
    //CheckBegOffsetToEndOffset(coord);

    do              // 寻找到不是
    {
        #ifdef LEXICAL_DEBUG_DEFINE
        printf("%c", *(douBuffer->m_forward));
        #endif // LEXICAL_DEBUG_DEFINE

        AddBufForward(douBuffer);             // 移动字符串
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }while(IsHexDigit(*(douBuffer->m_forward)) == true
        || *(douBuffer->m_forward) == '.'
        || *(douBuffer->m_forward) == 'x' || *(douBuffer->m_forward) == 'X');

    #ifdef LEXICAL_DEBUG_DEFINE
    printf("移动到常数的末尾%c", *(douBuffer->m_forward));
    #endif // LEICAL_DEBUG

    if((token = CopyBufToken(douBuffer)) != NULL)          // 取出常数信息
    {   //FILE_FUNC_LINE( );
        if((kind = IsConstant(token)) != TOKEN_NULL)                   // 如果取出来的常数信息是一个合法的常数信息
        {//FILE_FUNC_LINE( );
            if((newNode = InsertTupleLiteral(pNode, token, douBuffer->m_coord, kind)) != NULL)        // 将常量的信息添加进去
            {//FILE_FUNC_LINE( );
                pNode = newNode;


                #ifdef LEXICAL_SHOWS_DEFINE               //  利用显示宏 -=> 输出发现的词法信息
                printf("\n常量数\n");
                ShowTupleNode(pNode);
                #endif      // LEXICAL_SHOWS_DEFINE
            }
        }
        else
        {
            free(token);           // 如果不是常量数字, 就将指针销毁
        }
        // 将指针设置好,以供下次开始分析新的词法信息
        CheckLexemeToForward(douBuffer);

        douBuffer->m_forward--;
        douBuffer->m_coord->m_fileEndOffset--;
    }

    return pNode;               // 返回词法二元组链表的尾链表
}


BinaryTuple BufferLexical(const char *sourFile)
{
    int         count = 0;              // 此法结点计数器

    /// 双缓冲区信息
    DouBuffer   *douBuffer = InitBuffer(sourFile);


    /// 编译信息的处理结果
    CompResult  *compResult = InitCompResult( );     // 编译结果-=> 包括错误数目, 警告数目, 终止位置

    /// 词法二元组的信息
    BinaryTuple douTuple = InitTuple(sourFile);            // 初始化二元组信
    TupleNode   *pNode = (TupleNode *)douTuple, *newNode = NULL; // 结点指针




    /// 整个词法分析过程
    for(PutBuffer(douBuffer); /*feof(ifp) == 0*/; AddBufForward(douBuffer))     // 循环缓冲区的所有字符, 只要没有到达缓冲区末尾
    {
        if(LexCntrl(douBuffer) == true)       // 处理控制字符信息
        {
            break;
        }
        #ifdef LEXICAL_DEBUG_DEFINE
        printf("当前处理字符%c=%d, 偏移%d %d\n", *(douBuffer->m_forward), *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
        #ifdef CTOOLS_STEPS_DEFINE
        PAUSE( );
        #endif      // CTOOLS_STEPS_DEFINE
        #endif

        if(IsSeparator(*(douBuffer->m_forward)) != NOT_FIND)	/// ==========分界符号的处理过程==========
        {
            if((newNode = Scanner(pNode, douBuffer)) != NULL)       /// 先对对读取的信息进行次词法扫描
            {
                pNode = newNode;        // 将pNode指向新的链表尾部
                count++;
            }

            if((newNode = LexSeparator(pNode, douBuffer)) != NULL)    /// 再对发现的当前分界符号进行词法分析
            {
                pNode = newNode;
                count++;
            }
        }
        else if(IsOperate(*(douBuffer->m_forward)) != NOT_FIND)  /// ==========运算符的处理过程==========
        {
            if((newNode = Scanner(pNode, douBuffer)) != NULL)       /// 先对对读取的信息进行次词法扫描
            {
                pNode = newNode;        // 将pNode指向新的末尾
                count++;
            }

            if((newNode = LexOperator(pNode, douBuffer)) != NULL)          /// 再对发现的当前运算符号进行词法分析
            {
                pNode = newNode;
                count++;       // 文件关键标识++
            }
        }
        else if(IsDigit(*douBuffer->m_forward) == true && IsLetter(*(douBuffer->m_forward - sizeof(char))) != true)     /// ==========数字的单独处理[可能遇见了数字常量]==========
        {
            if((newNode = LexConstant(pNode, douBuffer)) != NULL)
            {
                pNode = newNode;
                count++;
            }
        }
        else if(isprint(*(douBuffer->m_forward)) == 0)     /// 否则出现了无法识别的编码符号
        {
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /**/Error(douBuffer->m_coord, "the %d can't distinguish as C Language infomation", *(douBuffer->m_forward));////////////////
        /**/compResult->m_erroCount++;/////////////////////////////////////////////////////////////////////错误数目增加1
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }


    }     // end of FOR(IsBufferEnd(douBuffer) != true)

    /// 最后处理二元组
    #ifdef LEXICAL_HELPS_DEFINE         // C利用帮助宏 -=> 提示词法处理完毕, 显示发现的词法信息数目
    FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
    printf("\n\t******************************************************************\n");
    printf("\t****      We have find %d Lexeical in the file you give...  ****\n", count);
    printf("\t******************************************************************\n");
    PAUSE( );
    #endif  // LEXICAL_HELPS_DEFINE

    if((newNode = InsertEndToken(pNode)) != NULL)
    {
        pNode = newNode;
    }


    FinitBuffer(douBuffer);     // 缓冲区收尾信息
    /////////////////////////////////////////////////////
    //FinitBuffer(coord);         // 文件位置指针的收尾清理工作
    /////////////////////////////////////////////////////
    douTuple->m_tuple.m_coord.m_fileLine = count;  // t头结点的位置标识信息的行号域用于标识词法数目

    //CToolsClose(ifp);

    if(compResult->m_erroCount != 0)
    {
        //printf("因为源程序中出现错误, 在词法分析后直接将文件关闭\n");
        DestroyTuple(douTuple);
        douTuple = NULL;
    }
    return douTuple;
}



// 对源文件进行词法分析
// 如果源文件以.c或者.h为后缀名, 则默认当作源文件进行词法分析
// 如果文件以.i为后缀,　则默认当作预处理文件进行编译
void MainOfLexical( )   // 待处理源文件
{
    #ifdef SYS_WINDOWS_DEF
    system("title 词法分析器");
    system("color 00");
    #endif      // SYS_WINDOWS_DEF

    char sourFile[FILE_NAME_SIZE];        // 源文件名
    BinaryTuple douTuple = NULL;               // 二元组信息


    while(printf("Please enter your sourFile's-url:"), scanf("%s", sourFile) != EOF)
    {

        douTuple = BufferLexical(sourFile);      // 直接处理源文件
        #ifdef LEXICAL_SHOWS_DEFINE
        VisitTuple(douTuple);            // 遍历二元组信息, 查找二元组正确性
        #endif

        DestroyTuple(douTuple);                // 清空二元组空间为系统节省内存空间
    }

    #ifdef LEXICAL_HELPS_DEFINE
    VERSION( );
    #endif          // LEXICAL_HELPS_DEFINE


    #ifdef LEXICAL_DEBUG_DEFINE
    PAUSE( );
    #endif

}


// 对源文件进行词法分析
void TestOfLexical( )    // 待处理源文件
{
    #ifdef SYS_WINDOWS_DEF
    system("title 词法分析器");
    system("color 00");
    #endif      // SYS_WINDOWS_DEF

    clock_t start, finish;
    start = clock( );

    BinaryTuple douTuple;               // 二元组信息

    douTuple = BufferLexical("TEST/test0.c");      // 直接处理源文件

    #ifdef LEXICAL_SHOWS_DEFINE
    VisitTuple(douTuple);            // 遍历二元组信息, 查找二元组正确性
    #endif
    DestroyTuple(douTuple);                // 清空二元组空间为系统节省内存空间

    #ifdef LEXICAL_HELPS_DEFINE
    VERSION( );
    #endif          // LEXICAL_HELPS_DEFINE

    #ifdef LEXICAL_DEBUG_DEFINE
    PAUSE( );
    #endif

    finish = clock( );
    printf("LEXICAL TIME : %lf seconds\n", (double)(finish - start)/(double)CLOCKS_PER_SEC);

}



