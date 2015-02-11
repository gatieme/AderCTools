/**************
*
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe
*   File Name  : Parser.h
*   Description: CTools-SyntacicParser
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-11-5  18:38:23
*   Content    : CTools-Lexical
*
*   This file is the CodeProp...
***************/




#include "Prop.h"

//extern const char keyword[MAX_KEYWORD][20];
//extern const char procom[MAX_PROCOM][10];
//extern const char operate[MAX_OPERATE];
//extern const char allOperator[MAX_OPERATE][4];
//extern const char separator[MAX_SEPARAROR];



// 在文件中添加重定义文件行的信息
//void WritePropLineStr(CToolsFILE fp, const char *fileName, int fileLine)
//{
//    fprintf(fp, "#line %d \"%s\"\n", fileLine, fileName);
//}

// 在文件中添加文件插桩信息
//void WritePropStr(CToolsFILE fp, const char *streamName)
//{
//    fprintf(fp, "line(%s);", streamName);
//}

// 将源文件src中偏移start到end的数据写入dest文件中
void PropWriteSrcToDest(CToolsFILE dest, CToolsFILE src, int start, int end)
{
    int ch;
    fseek(src, start, SEEK_SET);            // 将文件定位到文件偏移start的位置

    //printf("将\"");
    for(int pos = start; pos < end; pos++)
    {
        //if((ch = fgetc(src)) != 0)
        if(fscanf(src, "%c", &ch) == 1)
        {
            if(ch == '\r')
            {
                //printf("\\r");
                continue;
            }
            else if(ch == '\n')
            {
                //pos++;
                //printf("读出来一个换行符号%d", pos);
                //printf("\\n");
            }
            fprintf(dest, "%c", ch);
            //printf("偏移%d%c\n", pos, ch);
            //printf("%c", ch);
        }
    }

    fprintf(src, " ");
    //printf("\"写入dest插桩目的文件中\n");
}


// 将源文件中从当前位置开始到末尾的所有字符写入目标文件中
void PropWriteAllSrcToDest(CToolsFILE destFp, CToolsFILE srcFp)
{
    int ch;

    #ifdef PROP_DEBUG_DEFINE
    printf("将从源文件偏移%d处开始所有的数据写入文件\n", ftell(srcFp));
    //printf("%d", ftell(srcFp), )
    #endif // PROP_DEBUG_DEFINE
    while(feof(srcFp) == 0)
    {
        if(fscanf(srcFp, "%c", &ch) ==  1)
        {

            #ifdef PROP_DEBUG_DEFINE
            printf("读取出来的字符%c\n", ch);
            #endif // PROP_DEBUG_DEFINE

            fprintf(destFp, "%c", ch);
        }
    }
}


// 将srcFp文件指针中的count个字符写入destFp指向的文件中
void PropWriteCountSrcToDest(CToolsFILE destFp, CToolsFILE srcFp, int count)
{
    int ch;
    int num = 0;
    #ifdef PROP_DEBUG_DEFINE
    printf("将从源文件偏移%d处开始写入%d个数据\n", ftell(srcFp), count);
    //printf("%d", ftell(srcFp), )
    #endif // PROP_DEBUG_DEFINE

    while(num < count)
    {
        if(fscanf(srcFp, "%c", &ch) ==  1)
        {
            #ifdef PROP_DEBUG_DEFINE
            printf("读取出来的字符%c\n", ch);
            #endif // PROP_DEBUG_DEFINE

            fprintf(destFp, "%c", ch);
            num++;
        }
        else
        {
            if(feof(srcFp) != 0)
            {
                break;
            }
            //FILE_FUNC_LINE( );
            fprintf(stderr, "读取数据失败");
        }
    }
    //FILE_FUNC_LINE( );
}

// 直接在源文件一条语句的终结符后面添加插桩数据域
void PropWritePropLineInEnd(CToolsFILE dest, CToolsFILE src, SyntaxTree parentRoot)
{

    long start   =   parentRoot->m_syntax.m_startCoord.m_fileBegOffset;
    long end     =   parentRoot->m_syntax.m_endCoord.m_fileEndOffset;

    PropWriteSrcToDest(dest, src, start, end);          // 将数据写入文件中
    WritePropStr(dest, "__propFP__");                     // 填入插桩信息
    //printf("将Line(__prop__);插桩信息写入插目标文件\n");

}


// 判断当前语法子树所表示的函数定义信息是不是主main函数入口
// 实现    首先找到语法子树中代码函数名称的标识符信息的位置, 查看其名称是不是main
//         有两种实现思路实现找到这个位置,
//         一种方式是遍历语法子树,
//         另一种方式是首先找到语法子树的第一个终结符, 这个终结符号必定就是词法序列的第一个结点
//         而归约的过程中，语法子树中几个终结符号必定是连续的, 因此
//         在语法子树中找到第一个终结符号信息, 然后以这个节点为首结点, 遍历各个词法结点
//         找到词法序列中第一个标识符结点必定就是函数名称的标识符信息
bool IsMainFunc(SyntaxTree parentRoot)
{
    TupleNode      *headTupleNode = NULL;
    TupleNode      *tupleNode = NULL;

    /// 首先先找到语法子树中第一个叶子结点
    if((headTupleNode = FindFirstChildTupleNode(parentRoot)) != NULL)
    {
        if((tupleNode = FindFirstTupleTreinal(headTupleNode, IDENTIFIER)) != NULL)
        {
            if(strcmp(tupleNode->m_tuple.m_data.m_identifier, "main") == 0)
            {
                return true;
            }
            else
            {
                #ifdef PROP_SHOWS_DEFINE
                printf("当前函数不是main主函数\n");
                #endif // PROP_SHOWS_DEFINE

                return false;
            }
        }
        else
        {
            FILE_FUNC_LINE( );
            fprintf(stderr, "找到词法二元组的末尾仍然未找到标识符\n");
            return false;
        }
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "无法查找到语法树的第一个终结符结点数据域\n");

        return false;
    }
}


// 在进行插桩的时候, 我们在main函数之前插入了一个文件打开插桩描述串FILE_OPEN_DEFINE_PROP_STR
// 因为需要在主函数结束的时候将文件关闭
TupleNode* FindFuncRegPos(SyntaxTree parentRoot)
{
#ifdef PROP_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(IsMainFunc(parentRoot) == true);
#endif // PROP_DEBUG_DEFINE

    TupleNode   *finalTupleNode = NULL;
    TupleNode   *posTupleNode = NULL;

    // 首先找到函数定义式子的结束位置
    if((finalTupleNode = FindFinalChildTupleNode(parentRoot)) != NULL)
    {
        // 函数定义式的结束位置应该是一个"}"终结符词法二元组结点
        if(finalTupleNode->m_tuple.m_kind == RBRACE_SEPARATOR)
        {
            // 在主函数定义式中找到当前return 类型关键字的位置
            if((posTupleNode = ReFindFirstTupleTreinal(finalTupleNode, RETURN_KEYWORD)) != NULL)
            {   // 找到了return关键字, 则返回关键位置, 因为需要在return之前添加文件关闭描述符号
                return posTupleNode;
            }
            else
            {   // 未找到retunr关键， 则直接在"}"之前插入描述符, 需在"}"之前插入文件关闭描述
                ///////////////////////////////////////////////////////////////////////////////////////
                // 说明主函数未返回WARING
                ///////////////////////////////////////////////////////////////////////////////////////
                return finalTupleNode;
            }
        }
        else
        {
            FILE_FUNC_LINE( );
            fprintf(stderr, "此函数定义式有错误, 最后一个终结符号不是\"}\"");
            return NULL;
        }
    }
}



void PropWriteFileOpenDefineStr(CToolsFILE destFp, const char *srcFname, int srcLine)
{
    fprintf(destFp, "%s", FILE_OPEN_DEFINE_PROP_STR);        // 将文件打开信息宏写入文件中
    WritePropLineStr(destFp, srcFname, srcLine);        // 将重定向行号信息写入文件中
}





//// 将词法二元组符号添加到目的文件中
//void PropWriteTupleNode(CToolsFILE destfp, TupleNode* pNode)
//{
//    switch((int)pNode->m_tuple.m_kind)          // 依据当前此法结点的编码
//    {
//        case TOKEN_END               :                  // 标识符号
//		{
//            printf("[%d, %d]", TOKEN_END, pNode->m_tuple.m_data.m_keyCode);
//			break;
//		}
//		case TOKEN_NULL              :
//		case UNKNOW                  :
//		case ARRAY                   :
//		case FUNCTION                :
//		case PARAMETERS              :
//        case POINT                   :
//		{
//			break;
//		}
//
//		case HEAD                    :
//		{
//		    printf("COUNT = %d", pNode->m_tuple.m_coord.m_fileLine);
//		    printf("COUNT = %d", pNode->m_tuple.m_data.m_keyCode);
//			break;
//		}
//
//		case IDENTIFIER              :                  // 标识符号
//		{
//            fprintf(destfp, "%s", pNode->m_tuple.m_data.m_identifier);
//			break;
//		}
//
//		case KEYWORD                 :                  /// 关键字信息
//		case AUTO_KEYWORD            :
//		case BREAK_KEYWORD           :
//		case CASE_KEYWORD            :
//		case CHAR_KEYWORD            :
//		case CONST_KEYWORD           :
//		case CONTINUE_KEYWORD        :
//		case DEFAULT_KEYWORD         :
//		case DO_KEYWORD              :
//		case DOUBLE_KEYWORD          :
//		case ELSE_KEYWORD            :
//		case ENUM_KEYWORD            :
//		case EXTERN_KEYWORD          :
//		case FLOAT_KEYWORD           :
//		case FOR_KEYWORD             :
//		case GOTO_KEYWORD            :
//		case IF_KEYWORD              :
//		case INT_KEYWORD             :
//		case LONG_KEYWORD            :
//		case REGISTER_KEYWORD        :
//		case RETURN_KEYWORD          :
//		case SHORT_KEYWORD           :
//		case SIGNED_KEYWORD          :
//		case SIZEOF_OPERATE          :
//		case STATIC_KEYWORD          :
//		case STRUCT_KEYWORD          :
//		case SWITCH_KEYWORD          :
//		case TYPEDEF_KEYWORD         :
//		case UNION_KEYWORD           :
//		case UNSIGNED_KEYWORD        :
//		case VOID_KEYWORD            :
//		case VOLATILE_KEYWORD        :
//		case WHILE_KEYWORD           :
//        {
//            fprintf(destfp, "%s", keyword[pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode]);
//            break;
//        }
//
//		case OPERATE                 :                  /// 运算符号
//		case COMMA_OPERATE           :                  // ,
//		case ASSIGN_OPERATE          :                  // =
//		case ADD_ASSIGN_OPERATE      :                  // +=
//		case SUB_ASSIGN_OPERATE      :                  // -=
//		case MUL_ASSIGN_OPERATE      :                  // *=
//		case DIV_ASSIGN_OPERATE      :                  // /=
//		case MOD_ASSIGN_OPERATE      :                  // %=
//		case BITOR_ASSIGN_OPERATE    :                  // |=
//		case BITXOR_ASSIGN_OPERATE   :                  // ^=
//		case BITAND_ASSIGN_OPERATE   :                  // &=
//		case RSHIFT_ASSIGN_OPERATE   :                  // >>=
//		case LSHIFT_ASSIGN_OPERATE   :                  // <<=
//		case QUESTION_OPERATE        :                  // ?
//		case COLON_OPERATE           :                  // :
//		case OR_OPERATE              :                  // ||
//		case AND_OPERATE             :                  // &&
//		case BITOR_OPERATE           :                  // |
//		case BITXOR_OPERATE          :                  // ^
//		case BITAND_OPERATE          :                  // &
//		case EQUAL_OPERATE           :                  // ==
//		case UNEQUAL_OPERATE         :                  // !=
//		case GREATER_OPERATE         :                  // >
//		case GREATER_EQUAL_OPERATE   :                  // >=
//		case LESS_OPERATE            :                  // <
//		case LESS_EQUAL_OPERATE      :                  // <=
//		case RSHIFT_OPERATE          :                  // >>
//		case LSHIFT_OPERATE          :                  // <<
//		case ADD_OPERATE             :                  // +
//		case SUB_OPERATE             :                  // -
//		case MUL_OPERATE             :                  // *
//		case DIV_OPERATE             :                  // /
//		case MOD_OPERATE             :                  // %
//		case NOT_OPERATE             :                  // !
//		case COMP_OPERATE            :                  // ~
//		case INC_OPERATE             :                  // ++
//		case DEC_OPERATE             :                  // --
//		//case RPAREN_OPERATE          :                  // )
//		//case LPAREN_OPERATE          :                  // (
//        //case RBRACKET_OPERATE        :                  // ]
//		//case LBRACKET_OPERATE        :                  // [
//		case DOT_OPERATE             :                  // .
//        case POINT_TO_OPERATE        :                  // ->
//		case ELLIPSE_OPERATE         :                  // ...
//		{
//            fprintf("%s", allOperator[pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode]);
//			break;
//		}
//
//		case SEPARATOR               :
//        case SPACE_SEPARATOR         :
//		case LBRACE_SEPARATOR        :
//		case RBRACE_SEPARATOR        :
//		case SEMICOLON_SEPARATOR     :
//		case POUND_SEPARATOR         :
//        case SINGLE_QUOTE_SEPARATOR  :
//        case DOUBLE_QUOTE_SEPARATOR  :
//		case NEWLINE_SEPARATOR       :
//		//case ELLIPSE_SEPARATOR       :
//        case RPAREN_OPERATE          :                  // )
//		case LPAREN_OPERATE          :                  // (
//        case RBRACKET_OPERATE        :                  // ]
//		case LBRACKET_OPERATE        :                  // [
//		{
//            fprintf("[%d, %d]", separator[pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode]);
//            break;
//		}
//
//		case CONST                   :
//		case INT_CONST               :
//		case UINT_CONST              :
//		case LONG_CONST              :
//		case ULONG_CONST             :
//		case LLONG_CONST             :
//		case ULLONG_CONST            :
//		case FLOAT_CONST             :
//		case DOUBLE_CONST            :
//		case LDOUBLE_CONST           :
//		case CHAR_CONST              :
//		case WCHAR_CONST             :
//		case STRING_CONST            :
//        {
//            fprintf(destfp, "%s", pNode->m_tuple.m_data.m_constNum);
//            break;
//        }
//		case ENUM_CONST              :
//		{
//			break;
//		}
//    }
//}



// 对源文件srcFname进行插桩， 插桩结果生成destFname
void PropFile(const char *destFname, const char *srcFname)
{
    ParseFilePropRed(destFname, srcFname);
}



int MainOfProp(int argc, char **argv)
{
    // 首先确认执行了插桩编译
    //#ifndef PROP_REDUCTION_DEFINE
    //#error "ErrorPROP: can't find PROP_REDUCTION_DEFINE in elf...\n"
    //#endif // PROP_REDUCTION_DEFINE

    const char propDestFname[FILE_NAME_SIZE];
    const char propSrcFname[FILE_NAME_SIZE];


    // 确认输入输出文件
    if(argc < 2)
    {
        printf("Please input the file name of the SOURCE FILE:\n");
        scanf("%s", propSrcFname);
        printf("Please input the file name of the DEST FILE:\n");
        scanf("%s", propDestFname);
    }
    else if(argc > 3)
    {
        printf("ErrorPROP: too many file...\n");
        exit(-1);
    }

    // 获取输入输出文件
    strcpy(propSrcFname, argv[1]);           // 取出输入文件
    if(argc == 2)
    {
        strcpy(propDestFname, PROP_FILE_NAME);
    }
    else if(argc == 3)
    {
        strcpy(propDestFname, argv[2]);
    }

    // 语法分析的同时对源文件进行插桩分析...
    PropFile(propDestFname, propSrcFname);

    return EXIT_SUCCESS;
}

//
//#ifdef PROP_REDUCTION_DEFINE
//// 插桩器的主函数PROP_main
//int main(int argc, char **argv)
//{
//    // 首先确认执行了插桩编译
//    #ifndef PROP_REDUCTION_DEFINE
//    // printf("ErrorPROP: can't find PROP_REDUCTION_DEFINE in %s(elf)\n", argv[0]);
//    // exit(-1);
//    #error "ErrorPROP: can't find PROP_REDUCTION_DEFINE in elf...\n"
//    #endif // PROP_REDUCTION_DEFINE
//
//    const char *propDestFname = NULL;
//    const char *propSrcFname = NULL;
//
//
//
//    // 确认输入输出文件
//    if(argc < 2)
//    {
//        printf("ErroePROP: no input file... \n");
//        exit(-2);
//    }
//    else if(argc > 3)
//    {
//        printf("ErrorPROP: too many file...\n");
//    }
//
//    // 获取输入输出文件
//    propSrcFname = argv[1];           // 取出输入文件
//    if(argc == 2)
//    {
//        propDestFname = PROP_FILE_NAME;
//    }
//    else if(argc == 3)
//    {
//        propDestFname = argv[2];
//    }
//
//    // 语法分析的同时对源文件进行插桩分析...
//    PropFile(propDestFname, propSrcFname);
//
//    return EXIT_SUCCESS;
//}
//#endif
