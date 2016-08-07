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




#include "BinaryTuple.h"


#ifndef DEBUG
#define DEBUG
#endif


/// Literal的函数声明部分
#ifdef PUBLIC_and_PRIVATE
#
#
// 输出每个二元组Node结点的信息
PRIVATE void
FreeNode(TupleNode *pNode);                 // 将当前词法结点的信息删除
#define free_node   FreeNode
#
#
/// 将二元组结点信息填入ifp所指的文件中
PRIVATE CToolsFILE
WriteNode(
          TupleNode *pNode,             // 词法二元组结点
          CToolsFILE fp);               // 文件指针
#
#
/// 将二元组结点信息从ifp所指的文件中读取出来
PRIVATE TupleNode*                      // 返回结点的指针
ReadNode(
         CToolsFILE fp);               // 文件指针
#
#
/// 销毁二元组信息
void
FinitTuple(
           BinaryTuple douTuple);           // 二元组收尾工作
#define finit_tuple FinitTuple
#
#
#endif


// 来自与TokenKind中的外部变量
extern const char keyword[MAX_KEYWORD_COUNT][MAX_KEYWORD_SIZE];         // 所有的关键字变量
extern const char procom[MAX_PROCOM_COUNT][MAX_PROCOM_SIZE];           // 预编译指令定义
extern const char operate[MAX_OPERATE_COUNT];             // 简单运算符定义
extern const char allOperator[MAX_OPERATE_COUNT][MAX_OPERATE_SIZE];      // 运算符定义
extern const char separator[MAX_SEPARAROR_COUNT];         // 分界符定义



/// 初始化二元组信息
BinaryTuple InitTuple(const char* sourFile)
{
    BinaryTuple douTuple = (TupleNode *)malloc(sizeof(TupleNode));       // 为头结点开辟空间

    // 为存储文件名开辟必要的空间
    char *fileName = (char *)malloc(strlen(sourFile) + sizeof(1));
    strcpy(fileName, sourFile);       // 文件名写入[]

    // 词法元组赋值
    douTuple->m_tuple.m_kind = HEAD;     // 头存放的是HEAD标识

    douTuple->m_tuple.m_data.m_fileName = fileName;         // 文件名指针指向当前的文件名
    // 信息位置标识赋值
    douTuple->m_tuple.m_coord.m_fileName = fileName;                // 词法位置标识文件域同样指向文件名
    douTuple->m_tuple.m_coord.m_fileLine = -1;                      // 初始化文件行数为0

    douTuple->m_next = NULL;
    douTuple->m_last = NULL;

    return douTuple;
}

/// 销毁二元组信息
void FinitTuple(BinaryTuple douTuple)
{
    TupleNode *pNode = douTuple;

    // 销毁头结点空间
    if(pNode != NULL)
    {
        if(pNode->m_tuple.m_data.m_fileName != NULL)          // 销毁为存储文件名开辟的空间
        {
            free(pNode->m_tuple.m_data.m_fileName);
        }
        free(pNode);           // 销毁头结点
    }
}


/// 将一个语法信息[关键字, 运算符, 分界符]插入到二元组中
TupleNode* InsertTupleKey(TupleNode *pNode, TokenKind kind, int keyCode, Coord *coord)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE

    TupleNode *newNode = NULL;

    if((newNode = (TupleNode* )malloc(sizeof(TupleNode))) != NULL)         // 将要插入的新结点
    {
        //printf("keyCode = %d\n", keyCode);
        // 对新结点赋值
        newNode->m_tuple.m_kind = (enum TokenKind)((int)kind + keyCode);      // 当前数据是[运算符OPERATOR, 分界符号SEPARATOE, ]
        newNode->m_tuple.m_data.m_keyCode = (int)kind/**KEYWORD | PROCOM | SEPARATOR | OPERATE**/;        // 计算当前字符串的种别码

//      newNode->m_tuple.m_coord.m_fileName = coord->m_fileName;    // 让当前词法位置的文件指针地址指向文件名的存储地址
//      newNode->m_tuple.m_coord.m_fileLine = coord->m_fileLine;    // 文件的行号赋值
//      newNode->m_tuple.m_coord.m_fileBegOffset = coord->m_fileBegOffset;      // 词法信息开始位置的偏移量
//      newNode->m_tuple.m_coord.m_fileEndOffset = coord->m_fileEndOffset;      // 词法信息结束位置的偏移量

        newNode->m_tuple.m_coord = *coord;
        if(kind == SEPARATOR)                               // [关键字，运算符，标识符，分界符，常量中只有分界面符号是单个的]
        {
            newNode->m_tuple.m_coord.m_fileEndOffset++;      // 词法信息结束位置的偏移量进1指向下一位置
        }

        // 指针数据域双项循环链表的建立
        newNode->m_next = pNode->m_next/* = NULL*/;
        newNode->m_last = pNode;
        if(pNode->m_next != NULL)
        {
            pNode->m_next->m_last = newNode;
        }
        pNode->m_next = (TupleNode *)newNode;

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("添加的信息是[%d, %d]", kind, newNode->m_tuple.m_kind);
        printf("记录下来的行号LINE = %d\n", newNode->m_tuple.m_coord.m_fileLine);
        #endif
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "开辟词法二元组结点失败\n");
    }

    return newNode;
}

/// 将一个常量信息插入到二元组中
TupleNode* InsertTupleLiteral(TupleNode *pNode, char *token, Coord *coord, TokenKind kind)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE
    // 构建二元组的信息
    TupleNode *newNode = NULL;

    if((newNode= (TupleNode* )malloc(sizeof(TupleNode))) != NULL)
    {
        // 确定当前常量信息的种类
        if(kind == CONST)
        {
            newNode->m_tuple.m_kind = CONST;           // 当前信息为常量
        }
        else
        {
            newNode->m_tuple.m_kind = kind;
        }

        newNode->m_tuple.m_data.m_constNum = token;         // 直接让常量指针域指向字符串的地址

//      newNode->m_tuple.m_coord.m_fileName = coord->m_fileName;    // 让当前词法位置的文件指针地址指向文件名的存储地址
//      newNode->m_tuple.m_coord.m_fileLine = coord->m_fileLine;    // 文件的行号赋值
//      newNode->m_tuple.m_coord.m_fileBegOffset = coord->m_fileBegOffset;      // 词法信息开始位置的偏移量
//      newNode->m_tuple.m_coord.m_fileEndOffset = coord->m_fileEndOffset;      // 词法信息结束位置的偏移量
        newNode->m_tuple.m_coord = *coord;

        // 指针数据域双项循环链表的建立
        newNode->m_next = pNode->m_next/* = NULL*/;
        newNode->m_last = pNode;
        if(pNode->m_next != NULL)
        {
            pNode->m_next->m_last = newNode;
        }
        pNode->m_next = (TupleNode *)newNode;
        //pNode = newNode;                // 将pNode重新指向尾结点

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("添加的信息是[%d, %d]", kind, newNode->m_tuple.m_kind);
        printf("记录下来的行号LINE = %d\n", newNode->m_tuple.m_coord.m_fileLine);
        #endif
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "开辟词法二元组结点失败\n");
    }

    return newNode;
}

/// 将一个标识符插入到二元组中
TupleNode* InsertTupleId(TupleNode *pNode, char *token, Coord *coord)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // LEXICAL_DEBUG_DEFINE
    // 构建二元组的信息
    TupleNode *newNode = NULL;

    if((newNode = (TupleNode* )malloc(sizeof(TupleNode))) != NULL)
    {

        // 当前指针域赋值
        newNode->m_tuple.m_kind = IDENTIFIER;           // 当前信息为标识
        newNode->m_tuple.m_data.m_identifier = token;           // 直接让指针域指向字符串的地址

//      newNode->m_tuple.m_coord.m_fileName = coord->m_fileName;    // 让当前词法位置的文件指针地址指向文件名的存储地址
//      newNode->m_tuple.m_coord.m_fileLine = coord->m_fileLine;    // 文件的行号赋值
//      newNode->m_tuple.m_coord.m_fileBegOffset = coord->m_fileBegOffset;      // 词法信息开始位置的偏移量
//      newNode->m_tuple.m_coord.m_fileEndOffset = coord->m_fileEndOffset;      // 词法信息结束位置的偏移量
        newNode->m_tuple.m_coord = *coord;


        // 指针数据域双项循环链表的建立
        newNode->m_next = pNode->m_next/* = NULL*/;
        newNode->m_last = pNode;
        if(pNode->m_next != NULL)
        {
            pNode->m_next->m_last = newNode;
        }
        pNode->m_next = (TupleNode *)newNode;
        //pNode = newNode;                // 将pNode重新指向尾结点

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("添加的信息是[%d, %s]", IDENTIFIER, newNode->m_tuple.m_data.m_identifier);
        printf("记录下来的行号LINE = %d\n", newNode->m_tuple.m_coord.m_fileLine);
        #endif
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "开辟词法二元组结点失败\n");
    }
    return newNode;
}


// 输出每个二元组Node结点的信息
void ShowTupleNode(TupleNode *pNode)
{

//    SHOW_FILE_NAME(pNode->m_tuple.m_coord.m_fileName);
//    printf("Line = %d  ", pNode->m_tuple.m_coord.m_fileLine);
//    printf("Begi = %d ", pNode->m_tuple.m_coord.m_fileBegOffset);
//    printf("Endl = %d ", pNode->m_tuple.m_coord.m_fileEndOffset);

    ShowCoord(&(pNode->m_tuple.m_coord));
    ShowTupleData(pNode);
    printf("\n");

}


/// 遍历词法二元数组
void VisitTuple(BinaryTuple douTuple)
{
    #ifdef LEXICAL_HELPS_DEFINE      // 利用帮助宏输出词法信息的数目
    FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
    printf("\t\t**********************************************\n");
    printf("\t\t*   The Lexical the sourFile has%04d words   *\n", douTuple->m_tuple.m_coord.m_fileLine);
    printf("\t\t**********************************************\n");
    PAUSE( );
    #endif // CTOOLS_HELP_DEFINE
    if(douTuple == NULL)
    {
        return ;
    }

    TupleNode *pNode = (TupleNode *)douTuple->m_next;

    while(pNode != NULL)
    {
        ShowTupleNode(pNode);
        pNode = (TupleNode *)pNode->m_next;      // 指向下一个指针域
    }
}





// 输出每个二元组Node结点的信息
void FreeNode(TupleNode *pNode)
{
    if(pNode->m_next == NULL                            // 最后一个词法信息的时候需要将位置信息的文件名域销毁
    || pNode->m_tuple.m_coord.m_fileName != pNode->m_next->m_tuple.m_coord.m_fileName)  // 下一个词法位置信息的文件名与当前词法所属的文件名不同时
    {
        #ifdef LEXICAL_DEBUG_DEFINE
        printf("销毁了词法位置信息的文件名指针域\n");
        #endif // LEXICAL_DEBUG_DEFINE
        //free(pNode->m_tuple.m_coord.m_fileName);
    }
        /// 0.3.4之后这个函数需要重新定义
    switch((int)pNode->m_tuple.m_kind)          // 依据当前此法结点的编码
    {
		case TOKEN_NULL              :
		case UNKNOW                  :
		case TOKEN_END               :
		case ARRAY                   :
		case FUNCTION                :
		case PARAMETERS              :
        case POINT                   :
		{
			break;
		}

		case HEAD                    :
		{
            free(pNode->m_tuple.m_data.m_fileName);
            // free(pNode->m_tuple.m_coord.m_fileName);     // 两个指针域使用的是同意内存空间
            break;
		}

		case IDENTIFIER              :                  // 标识符号
		{
            free(pNode->m_tuple.m_data.m_identifier);
            break;
		}

		case STRING_CONST           :
        {
            free(pNode->m_tuple.m_data.m_constNum);
            break;
        }
        default                    :
        {
            break;
        }
    }
    free(pNode);                // 将数据的结点信息删除
}


/// 清除词法二元组信息
bool DestroyTuple(BinaryTuple douTuple)
{
    #ifdef LEXICAL_HELPS_DEFINE      // 利用帮助宏输出词法信息的数目
    FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
    printf("\t\t**********************************************\n");
    printf("\t\t*   The Lexical the sourFile has%04d words   *\n", douTuple->m_tuple.m_kind); // 头结点的域信息是词法结点的数目
    printf("\t\t**********************************************\n");
    printf("Starting Destroy BinaryTuple......\b\b");
    PAUSE( );
    #endif  // CTOOLS_HELP_DEFINE

    #ifdef LEXICAL_SHOWS_DEFINE
    int count = 0;
    #endif
    if(douTuple == NULL)
    {
        ///printf("源文件中可能出现错误,词法二元组已经被销毁, 无需再次销毁\n");
        return false;
    }

    TupleNode *pNode = (TupleNode *)douTuple->m_next, *nextNode = NULL;

    while(pNode != NULL)
    {
        #ifdef LEXICAL_SHOWS_DEFINE
        printf("delete the %d tuple node  -=>  ", ++count);
        ShowTupleData(pNode);
        #endif

        nextNode = (TupleNode *)pNode->m_next;           // 保存下一个结点的信息
        FreeNode(pNode);                        // 删除结点
        pNode = nextNode;                   // 指向下一个结点

    }

    FinitTuple(douTuple);       // 对词法二元组进行收尾
    douTuple = NULL;

    return true;
}


/// 将二元组结点信息填入ifp所指的文件中
CToolsFILE WriteNode(TupleNode *pNode, CToolsFILE fp)               // 文件指针
{
    if(pNode == NULL || fp == NULL)     // 参数不合法
    {
        return NULL;
    }

    CToolsWrite(&(pNode->m_tuple.m_kind), sizeof(pNode->m_tuple.m_kind), 1, fp);        // 将种别码写入文件中
    CToolsWrite(&(pNode->m_tuple.m_data), sizeof(pNode->m_tuple.m_data), 1, fp);            // 写入文件信息


    return fp;              // 返回文件指针的信息
}


/// 将二元组结点信息从ifp所指的文件中读取出来
TupleNode *ReadNode(CToolsFILE fp)               // 文件指针
{
    if(fp == NULL)     // 参数不合法
    {
        return NULL;
    }

    TupleNode *pNode = (TupleNode *)malloc(sizeof(TupleNode));          // 为当前信息开辟空间

    CToolsRead(&(pNode->m_tuple.m_kind), sizeof(pNode->m_tuple.m_kind), 1, fp);        // 将种别码写入文件中
    CToolsRead(&(pNode->m_tuple.m_data), sizeof(pNode->m_tuple.m_data), 1, fp);            // 写入文件信息


    return pNode;              // 返回词法结点的信息
}


/// 将词法二元组信息填进去制定的文件中
void WriteTupleFile(BinaryTuple douTuple, char *fname)           // 待处理的词法文件
{
    if((int)douTuple->m_tuple.m_kind == 0)              // 头结点的种别码域m_kind表示的是元组数目
    {
        printf("当前词法信息二元组为空, 无法将信息写入文件中\n");
        //return NULL;
    }

    CToolsFILE ofp = CToolsOpen(fname, WRITE_ONLY_BINARY);       // 打开一个输出文件

    // 写入词法二元组文件头信息
    fwrite(TUPLE_MAGIC_NUM, sizeof(TUPLE_MAGIC_NUM), 1, ofp);      // 词法二元组文件的前10个字节为魔数"ctools.tup"

    TupleNode *pNode = NULL;            // 从头结点开始
    for(pNode = (TupleNode*)douTuple;                // 从头结点开始
        pNode != NULL && WriteNode(pNode, ofp) != NULL;    // 只要当前结点不为空, 就将结点信息填入ofp所指向的文件中
        pNode = pNode->m_next);                    // 只要当前结点不为空


    #ifdef LEXICAL_HELPS_DEFINE          // 利用帮助宏-=>提示词法信息已经写入文件
    FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
    printf("\t\t************************************************\n");
    printf("\t\t*  write the tuple infomation in file already  *\n");
    printf("\t\t************************************************\n");
    PAUSE( );
    #endif // LEXICAL_HELP_DEFINE
    CToolsClose(ofp);               // 关闭文件指针

    //return ofp;             // 返回文件的指针
}


/// 从指定文件中读取词法二元组信息
BinaryTuple ReadTupleFile(char *fname)           // 待处理的词法文件
{
    CToolsFILE ifp = CToolsOpen(fname, READ_ONLY_BINARY);       // 打开一个输出文件

    // 写入词法二元组文件头信息
    fseek(ifp, sizeof(TUPLE_MAGIC_NUM), SEEK_SET);                  // 跳过开始的10个字节的魔数

    ReadNode(ifp);
    CToolsClose(ifp);               // 关闭文件指针
    return NULL;                     // 返回词法二元组
}



BinaryTuple InsertEndToken(TupleNode *pNode)
{
    TupleNode *newNode = (TupleNode* )malloc(sizeof(TupleNode));

    // 当前指针域赋值
    newNode->m_tuple.m_kind = TOKEN_END;           // 当前信息为标识
    newNode->m_tuple.m_data.m_keyCode = TOKEN_END;           // 直接让指针域指向字符串的地址

    newNode->m_tuple.m_coord.m_fileName = "";    // 让当前词法位置的文件指针地址指向文件名的存储地址
    newNode->m_tuple.m_coord.m_fileLine = CToolsIsEOF;    // 文件的行号赋值
    newNode->m_tuple.m_coord.m_fileBegOffset = CToolsIsEOF;      // 词法信息开始位置的偏移量
    newNode->m_tuple.m_coord.m_fileEndOffset = CToolsIsEOF;      // 词法信息结束位置的偏移量

    newNode->m_next = NULL;              // 新结点的指针域置空

    // 建立新结点与其他结点的联系
    pNode->m_next = (TupleNode *)newNode;        // 将当前尾结点的指针域指向刚建立的结点, 也就是说现在newNode是尾结点
    pNode = newNode;                // 将pNode重新指向尾结点

    return pNode;
}

//  判断当前节点是不是END词法节点
bool IsEndToken(TupleNode *pNode)
{
    return (pNode->m_tuple.m_kind == TOKEN_END
         || pNode->m_tuple.m_data.m_keyCode == TOKEN_END);           // 直接让指针域指向字符串的地址
}

// 输出每个二元组Node结点的信息
void ShowTupleData(TupleNode *pNode)
{
 /// 0.3.4之后这个函数需要重新定义
    switch((int)pNode->m_tuple.m_kind)          // 依据当前此法结点的编码
    {
        case TOKEN_END               :                  // 标识符号
		{
            //printf("[%d, %d]", TOKEN_END, pNode->m_tuple.m_data.m_keyCode);
            printf("[END, END]", TOKEN_END, pNode->m_tuple.m_data.m_keyCode);
			break;
		}
		case TOKEN_NULL              :
		case UNKNOW                  :
		case ARRAY                   :
		case FUNCTION                :
		case PARAMETERS              :
        case POINT                   :
		{
			break;
		}

		case HEAD                    :
		{
		    printf("COUNT = %d", pNode->m_tuple.m_coord.m_fileLine);
		    printf("COUNT = %d", pNode->m_tuple.m_data.m_keyCode);
			break;
		}

		case IDENTIFIER              :                  // 标识符号
		{
            printf("[%d, %s]", IDENTIFIER, pNode->m_tuple.m_data.m_identifier);
			break;
		}

		case KEYWORD                 :                  /// 关键字信息
		case AUTO_KEYWORD            :
        case BOOL_KEYWORD            :
		case BREAK_KEYWORD           :
		case CASE_KEYWORD            :
		case CHAR_KEYWORD            :
		case CONST_KEYWORD           :
		case CONTINUE_KEYWORD        :
		case DEFAULT_KEYWORD         :
		case DO_KEYWORD              :
		case DOUBLE_KEYWORD          :
		case ELSE_KEYWORD            :
		case ENUM_KEYWORD            :
		case EXTERN_KEYWORD          :
		case FLOAT_KEYWORD           :
		case FOR_KEYWORD             :
		case GOTO_KEYWORD            :
		case IF_KEYWORD              :
		case INLINE_KEYWORD          :
		case INT_KEYWORD             :
		case LONG_KEYWORD            :
		case REGISTER_KEYWORD        :
		case RETURN_KEYWORD          :
		case SHORT_KEYWORD           :
		case SIGNED_KEYWORD          :
		case SIZEOF_OPERATE          :
		case STATIC_KEYWORD          :
		case STRUCT_KEYWORD          :
		case SWITCH_KEYWORD          :
		case TYPEDEF_KEYWORD         :
		case UNION_KEYWORD           :
		case UNSIGNED_KEYWORD        :
		case VOID_KEYWORD            :
		case VOLATILE_KEYWORD        :
		case WHILE_KEYWORD           :
        case _BOOL_KEYWORD           :
        case _COMPLEX_KEYWORD        :
        case _IMAGINARY_KEYWORD      :
        {
            int pos = pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode;
            printf("[%d, %s]", KEYWORD, keyword[pos]);
            printf("[%d, %d]", pNode->m_tuple.m_data.m_keyCode, pNode->m_tuple.m_kind);
            break;
        }

		case OPERATE                 :                  /// 运算符号
		case COMMA_OPERATE           :                  // ,
		case ASSIGN_OPERATE          :                  // =
		case ADD_ASSIGN_OPERATE      :                  // +=
		case SUB_ASSIGN_OPERATE      :                  // -=
		case MUL_ASSIGN_OPERATE      :                  // *=
		case DIV_ASSIGN_OPERATE      :                  // /=
		case MOD_ASSIGN_OPERATE      :                  // %=
		case BITOR_ASSIGN_OPERATE    :                  // |=
		case BITXOR_ASSIGN_OPERATE   :                  // ^=
		case BITAND_ASSIGN_OPERATE   :                  // &=
		case RSHIFT_ASSIGN_OPERATE   :                  // >>=
		case LSHIFT_ASSIGN_OPERATE   :                  // <<=
		case QUESTION_OPERATE        :                  // ?
		case COLON_OPERATE           :                  // :
		case OR_OPERATE              :                  // ||
		case AND_OPERATE             :                  // &&
		case BITOR_OPERATE           :                  // |
		case BITXOR_OPERATE          :                  // ^
		case BITAND_OPERATE          :                  // &
		case EQUAL_OPERATE           :                  // ==
		case UNEQUAL_OPERATE         :                  // !=
		case GREATER_OPERATE         :                  // >
		case GREATER_EQUAL_OPERATE   :                  // >=
		case LESS_OPERATE            :                  // <
		case LESS_EQUAL_OPERATE      :                  // <=
		case RSHIFT_OPERATE          :                  // >>
		case LSHIFT_OPERATE          :                  // <<
		case ADD_OPERATE             :                  // +
		case SUB_OPERATE             :                  // -
		case MUL_OPERATE             :                  // *
		case DIV_OPERATE             :                  // /
		case MOD_OPERATE             :                  // %
		case NOT_OPERATE             :                  // !
		case COMP_OPERATE            :                  // ~
		case INC_OPERATE             :                  // ++
		case DEC_OPERATE             :                  // --
//		case RPAREN_OPERATE          :                  // )
//		case LPAREN_OPERATE          :                  // (
//        case RBRACKET_OPERATE        :                  // ]
//		case LBRACKET_OPERATE        :                  // [
		case DOT_OPERATE             :                  // .
        case POINT_TO_OPERATE        :                  // ->
		case ELLIPSE_OPERATE         :                  // ...
		{
            int pos = pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode;
            printf("[%d, %s]", OPERATE, allOperator[pos]);
            printf("[%d, %d]", pNode->m_tuple.m_data.m_keyCode, pNode->m_tuple.m_kind);
			break;
		}

		case SEPARATOR               :
        case SPACE_SEPARATOR         :
		case LBRACE_SEPARATOR        :
		case RBRACE_SEPARATOR        :
		case SEMICOLON_SEPARATOR     :
		case POUND_SEPARATOR         :
        case SINGLE_QUOTE_SEPARATOR  :
        case DOUBLE_QUOTE_SEPARATOR  :
		case NEWLINE_SEPARATOR       :
//		case ELLIPSE_SEPARATOR       :
        case RPAREN_OPERATE          :                  // )
		case LPAREN_OPERATE          :                  // (
        case RBRACKET_OPERATE        :                  // ]
		case LBRACKET_OPERATE        :                  // [
		{
            int pos = pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode;
            printf("[%d, %c]", SEPARATOR, separator[pos]);
            printf("[%d, %d]", pNode->m_tuple.m_data.m_keyCode, pNode->m_tuple.m_kind);
            break;
		}

		case CONST                   :
		case INT_CONST               :
		case UINT_CONST              :
		case LONG_CONST              :
		case ULONG_CONST             :
		case LLONG_CONST             :
		case ULLONG_CONST            :
		case FLOAT_CONST             :
		case DOUBLE_CONST            :
		case LDOUBLE_CONST           :
		case CHAR_CONST              :
		case WCHAR_CONST             :
		case STRING_CONST            :
        {
            printf("[%d, %s]", pNode->m_tuple.m_kind, pNode->m_tuple.m_data.m_constNum);
            break;
        }
		case ENUM_CONST              :
		{
			break;
		}
    }
}


// 在以pNode为起始的词法二元组链表中，正向查找找到数据为终结符treinal的结点
TupleNode* FindFirstTupleTreinal(TupleNode *pNode, TokenKind terinal)
{
    TupleNode *tupleNode = pNode;

    while(tupleNode != NULL)     // 函数名称的种类是IDENTIFIER
    {
        if(tupleNode->m_tuple.m_kind == terinal
       || tupleNode->m_tuple.m_data.m_keyCode == terinal)
        {
            break;
        }
        tupleNode = tupleNode->m_next;
    }

    if(tupleNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在词法二元组中找不到终结符%d\n", terinal);
        return NULL;
    }
    else if(tupleNode->m_tuple.m_kind == terinal
       || tupleNode->m_tuple.m_data.m_keyCode == terinal)
    {

        return tupleNode;
    }

    return tupleNode;
}



// 在以pNode为起始的词法二元组链表中， 正向查找到找到第count个数据为终结符terinal的结点
TupleNode* FindTupleTreinal(TupleNode *pNode, TokenKind terinal, int count)
{
    int         num = 0;
    TupleNode *tupleNode = pNode;

    while(tupleNode != NULL)     // find in the tuple nodes...
    {
        if(tupleNode->m_tuple.m_kind == terinal
       || tupleNode->m_tuple.m_data.m_keyCode == terinal)
        {
            num++;
            if(num == count)            // break this "WHILE", when you have find count "TERINALS"
            {
                break;
            }
        }
        tupleNode = tupleNode->m_next;
        //num++;
    }

    //
    if(tupleNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在词法二元组中找不到终结符%d\n", terinal);
        return NULL;
    }
    else if((tupleNode->m_tuple.m_kind == terinal
        || tupleNode->m_tuple.m_data.m_keyCode == terinal)
    && num == count)
    {
        //ShowTupleData(tupleNode);
        return tupleNode;
    }
    return tupleNode;
}


// 在pNode结尾的词法二元组串中，反向查找到第一个符号是terinal的词法二元组结点
TupleNode* ReFindFirstTupleTreinal(TupleNode *pNode, TokenKind terinal)
{
    TupleNode *tupleNode = pNode;

    while(tupleNode != NULL)     // 函数名称的种类是IDENTIFIER
    {
        if(tupleNode->m_tuple.m_kind == terinal
       || tupleNode->m_tuple.m_data.m_keyCode == terinal)
        {
            break;
        }
        tupleNode = tupleNode->m_last;
    }

    if(tupleNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在词法二元组中找不到终结符%d\n", terinal);
        return NULL;
    }
    else if(tupleNode->m_tuple.m_kind == terinal
       || tupleNode->m_tuple.m_data.m_keyCode == terinal)
    {
        return tupleNode;
    }

    return tupleNode;
}


// 在以pNode结尾的词法二元组链表串中, 找到第count个符号是terinal的词法二元组
TupleNode* ReFindTupleTreinal(TupleNode *pNode, TokenKind terinal, int count)
{
    int         num = 0;
    TupleNode *tupleNode = pNode;

    while(tupleNode != NULL)     // find in the tuple nodes...
    {
        if(tupleNode->m_tuple.m_kind == terinal
       || tupleNode->m_tuple.m_data.m_keyCode == terinal)
        {
            num++;
            if(num == count)            // break this "WHILE", when you have find count "TERINALS"
            {
                break;
            }
        }
        tupleNode = tupleNode->m_last;
        //num++;
    }

    //
    if(tupleNode == NULL)
    {
        #ifdef PROP_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        #endif // PROP_DEBUG_DEFINE
        fprintf(stderr, "在词法二元组中找不到终结符%d\n", terinal);
        return NULL;
    }
    else if((tupleNode->m_tuple.m_kind == terinal
        || tupleNode->m_tuple.m_data.m_keyCode == terinal)
    && num == count)
    {
        //ShowTupleData(tupleNode);
        return tupleNode;
    }

    return tupleNode;
}


// 判断当前结点是不是预编译指令
bool IsProComTupleNode(TupleNode *tupleNode)
{
    ShowTupleData(tupleNode);
    return (tupleNode->m_tuple.m_kind == POUND_SEPARATOR             // 预编译指令以'#'开头
         && tupleNode->m_next->m_tuple.m_data.m_keyCode == PROCOM);  // '#'后面是预编译指令
}


