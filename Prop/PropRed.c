#include "PropRed.h"




// 存储每个产生式归约动作函数指针的数组
void (*PropRedFuncPointArray[233])(PropTable, SyntaxTree) =
{
   PropReduction0,     PropReduction1,     PropReduction2,     PropReduction3,     PropReduction4,
   PropReduction5,     PropReduction6,     PropReduction7,     PropReduction8,     PropReduction9,
  PropReduction10,    PropReduction11,    PropReduction12,    PropReduction13,    PropReduction14,
  PropReduction15,    PropReduction16,    PropReduction17,    PropReduction18,    PropReduction19,
  PropReduction20,    PropReduction21,    PropReduction22,    PropReduction23,    PropReduction24,
  PropReduction25,    PropReduction26,    PropReduction27,    PropReduction28,    PropReduction29,
  PropReduction30,    PropReduction31,    PropReduction32,    PropReduction33,    PropReduction34,
  PropReduction35,    PropReduction36,    PropReduction37,    PropReduction38,    PropReduction39,
  PropReduction40,    PropReduction41,    PropReduction42,    PropReduction43,    PropReduction44,
  PropReduction45,    PropReduction46,    PropReduction47,    PropReduction48,    PropReduction49,
  PropReduction50,    PropReduction51,    PropReduction52,    PropReduction53,    PropReduction54,
  PropReduction55,    PropReduction56,    PropReduction57,    PropReduction58,    PropReduction59,
  PropReduction60,    PropReduction61,    PropReduction62,    PropReduction63,    PropReduction64,
  PropReduction65,    PropReduction66,    PropReduction67,    PropReduction68,    PropReduction69,
  PropReduction70,    PropReduction71,    PropReduction72,    PropReduction73,    PropReduction74,
  PropReduction75,    PropReduction76,    PropReduction77,    PropReduction78,    PropReduction79,
  PropReduction80,    PropReduction81,    PropReduction82,    PropReduction83,    PropReduction84,
  PropReduction85,    PropReduction86,    PropReduction87,    PropReduction88,    PropReduction89,
  PropReduction90,    PropReduction91,    PropReduction92,    PropReduction93,    PropReduction94,
  PropReduction95,    PropReduction96,    PropReduction97,    PropReduction98,    PropReduction99,
 PropReduction100,   PropReduction101,   PropReduction102,   PropReduction103,   PropReduction104,
 PropReduction105,   PropReduction106,   PropReduction107,   PropReduction108,   PropReduction109,
 PropReduction110,   PropReduction111,   PropReduction112,   PropReduction113,   PropReduction114,
 PropReduction115,   PropReduction116,   PropReduction117,   PropReduction118,   PropReduction119,
 PropReduction120,   PropReduction121,   PropReduction122,   PropReduction123,   PropReduction124,
 PropReduction125,   PropReduction126,   PropReduction127,   PropReduction128,   PropReduction129,
 PropReduction130,   PropReduction131,   PropReduction132,   PropReduction133,   PropReduction134,
 PropReduction135,   PropReduction136,   PropReduction137,   PropReduction138,   PropReduction139,
 PropReduction140,   PropReduction141,   PropReduction142,   PropReduction143,   PropReduction144,
 PropReduction145,   PropReduction146,   PropReduction147,   PropReduction148,   PropReduction149,
 PropReduction150,   PropReduction151,   PropReduction152,   PropReduction153,   PropReduction154,
 PropReduction155,   PropReduction156,   PropReduction157,   PropReduction158,   PropReduction159,
 PropReduction160,   PropReduction161,   PropReduction162,   PropReduction163,   PropReduction164,
 PropReduction165,   PropReduction166,   PropReduction167,   PropReduction168,   PropReduction169,
 PropReduction170,   PropReduction171,   PropReduction172,   PropReduction173,   PropReduction174,
 PropReduction175,   PropReduction176,   PropReduction177,   PropReduction178,   PropReduction179,
 PropReduction180,   PropReduction181,   PropReduction182,   PropReduction183,   PropReduction184,
 PropReduction185,   PropReduction186,   PropReduction187,   PropReduction188,   PropReduction189,
 PropReduction190,   PropReduction191,   PropReduction192,   PropReduction193,   PropReduction194,
 PropReduction195,   PropReduction196,   PropReduction197,   PropReduction198,   PropReduction199,
 PropReduction200,   PropReduction201,   PropReduction202,   PropReduction203,   PropReduction204,
 PropReduction205,   PropReduction206,   PropReduction207,   PropReduction208,   PropReduction209,
 PropReduction210,   PropReduction211,   PropReduction212,   PropReduction213,   PropReduction214,
 PropReduction215,   PropReduction216,   PropReduction217,   PropReduction218,   PropReduction219,
 PropReduction220,   PropReduction221,   PropReduction222,   PropReduction223,   PropReduction224,
 PropReduction225,   PropReduction226,   PropReduction227,   PropReduction228,   PropReduction229,
 PropReduction230,   PropReduction231,   PropReduction232,
};


// 初始化插桩信息
void InitProp(CToolsFILE destFp, const char *srcFname)
{
    // 打开输入输出文件, 在输出文件中添加插桩预处理头
    //CToolsFILE  destFp = CToolsOpen(destFname, "w");     // 打开输出文件
    //CToolsFILE  srcFp = CToolsOpen(srcFname, "r");
    #ifdef PROP_DEBUG_DEFINE
    printf("%s\n", START_DEFINE_PROP_STR);
    PAUSE( );
    #endif // PROP_DEBUG_DEFINE

    fprintf(destFp, "%s\n", START_DEFINE_PROP_STR);
    //fprintf(destFp, "%s\n", INCLUDE_DEFINE_PROP_STR);          // 将开始的信息添加入文件中
    //fprintf(destFp, "%s\n", LINE_DEFINE_PROP_STR);             // 将行插桩宏的定义信息串添加入文件中
    //fprintf(destFp, "%s\n", GLOBAL_FILE_POINT_PROP_STR);             // 将行插桩宏的定义信息串添加入文件中

    WritePropLineStr(destFp, srcFname, 1);              // 插入行号初始化数据
    //WritePropStr(fp, "fp");

}

////
//PropTableNode* FinitProp(const char *destFname, const char *srcFname)
//{
//    fclose( );
//}

// 对语法子树parentRoot依照第id个产生式的形式进行插桩
void PropRed(PropTable propTable, SyntaxTree parentRoot, int id)
{
    // FILE_FUNC_LINE( );
    (*PropRedFuncPointArray[id])(propTable, parentRoot);

}


// 按照第0个产生式归约时的插桩动作
void PropReduction0(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第1个产生式归约时的插桩动作
void PropReduction1(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE


}



// 按照第2个产生式归约时的插桩动作
void PropReduction2(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第3个产生式归约时的插桩动作
void PropReduction3(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第4个产生式归约时的插桩动作
void PropReduction4(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第5个产生式归约时的插桩动作
void PropReduction5(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第6个产生式归约时的插桩动作
void PropReduction6(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第7个产生式归约时的插桩动作
// function-definition -=> declaration-specfiers declarator declaration compound-statement
// 函数定义式
// eg
// int main( )
// {
//
// }
// int main( )
// {
//
// }
// 执行动作, 首先判断当前函数名称是不是main,
// 思路   如果是主入口函数，则在函数开始的位置, 添加插桩文件打开信息宏，否则则执行其他操作
//       添加插桩
void PropReduction7(PropTable propTable, SyntaxTree parentRoot)
{
#ifdef PROP_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // PROP_DEBUG_DEFINE

    if(IsMainFunc(parentRoot) == true)          // 如果当前函数定义式子是main函数
    {                                       // 需要在"{"后面的位置插入插桩文件打开描述符号代码
        #ifdef PROP_SHOWS_DEFINE
        printf("当前函数是main主入口函数\n");
        #endif // PROP_SHOWS_DEFINE


        // 首先找到"{"的位置
        TupleNode   *tupleNode = NULL;
        if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, LBRACE_SEPARATOR)) != NULL)
        {   // 在"{"的后面插入一个插桩文件安打开描述符号

            #ifdef PROP_SHOWS_DEFINE
            printf("在main函数{的后面插入插桩文件打开描述符\n");
            #endif // PROP_SHOWS_DEFINE

            int offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
            int line = tupleNode->m_tuple.m_coord.m_fileLine;
            // 添加文件打开描述符插桩信息串,  重新定位行号
            //InsertPropDataWithLine(propTable, offset, FILE_OPEN_DEFINE_PROP_KIND, line + 1);
            InsertPropData(propTable, offset, FILE_OPEN_DEFINE_PROP_KIND);

            // 在主函数返回之前插入文件关闭描述符
            tupleNode = NULL;
            if((tupleNode = FindFuncRegPos(parentRoot)) != NULL)
            {
                #ifdef PROP_DEBUG_DEFINE
                ShowTupleData(tupleNode);
                PAUSE( );
                #endif // PROP_DEBUG_DEFINE

                offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
                //line = tupleNode->m_tuple.m_coord.m_fileLine;
                InsertPropData(propTable, offset, FILE_CLOSE_DEFINE_PROP_KIND);
            }
        }
        else
        {
            FILE_FUNC_LINE( );
            fprintf(stderr, "未在函数定义式中找到\"{\"的位置\n");
            PAUSE( );
        }
    }

}



// 按照第8个产生式归约时的插桩动作
void PropReduction8(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第9个产生式归约时的插桩动作
void PropReduction9(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE

}



// 按照第10个产生式归约时的插桩动作
// declaration -=> declaration-specifiers init-declaration-list ;
// 变量定义式暂时决定不进行插桩， 如果是函数或者全局变量定义， 插桩语句无法执行
void PropReduction10(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PROP_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PROP_DEBUG_DEFINE
    //PropWritePropLineInEnd(dest, src, parentRoot);
    //
    // 对于int a = 10;
    // 插桩int a = 10;Line(__prop__);
    //
    // 在末尾添加一个基本的插桩语句
//    int offset = parentRoot->m_syntax.m_endCoord.m_fileEndOffset;
//
//    InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
}




// 按照第11个产生式归约时的插桩动作
void PropReduction11(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第12个产生式归约时的插桩动作
void PropReduction12(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第13个产生式归约时的插桩动作
void PropReduction13(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第14个产生式归约时的插桩动作
void PropReduction14(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第15个产生式归约时的插桩动作
void PropReduction15(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第16个产生式归约时的插桩动作
void PropReduction16(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第17个产生式归约时的插桩动作
void PropReduction17(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第18个产生式归约时的插桩动作
void PropReduction18(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第19个产生式归约时的插桩动作
void PropReduction19(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第20个产生式归约时的插桩动作
void PropReduction20(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第21个产生式归约时的插桩动作
void PropReduction21(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第22个产生式归约时的插桩动作
void PropReduction22(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第23个产生式归约时的插桩动作
void PropReduction23(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第24个产生式归约时的插桩动作
void PropReduction24(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第25个产生式归约时的插桩动作
void PropReduction25(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第26个产生式归约时的插桩动作
void PropReduction26(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第27个产生式归约时的插桩动作
void PropReduction27(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第28个产生式归约时的插桩动作
void PropReduction28(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第29个产生式归约时的插桩动作
void PropReduction29(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第30个产生式归约时的插桩动作
void PropReduction30(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第31个产生式归约时的插桩动作
void PropReduction31(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第32个产生式归约时的插桩动作
void PropReduction32(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第33个产生式归约时的插桩动作
void PropReduction33(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第34个产生式归约时的插桩动作
void PropReduction34(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第35个产生式归约时的插桩动作
void PropReduction35(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第36个产生式归约时的插桩动作
void PropReduction36(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第37个产生式归约时的插桩动作
void PropReduction37(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第38个产生式归约时的插桩动作
void PropReduction38(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第39个产生式归约时的插桩动作
void PropReduction39(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第40个产生式归约时的插桩动作
void PropReduction40(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第41个产生式归约时的插桩动作
void PropReduction41(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第42个产生式归约时的插桩动作
void PropReduction42(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第43个产生式归约时的插桩动作
void PropReduction43(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第44个产生式归约时的插桩动作
void PropReduction44(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第45个产生式归约时的插桩动作
void PropReduction45(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第46个产生式归约时的插桩动作
void PropReduction46(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第47个产生式归约时的插桩动作
void PropReduction47(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第48个产生式归约时的插桩动作
void PropReduction48(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第49个产生式归约时的插桩动作
void PropReduction49(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第50个产生式归约时的插桩动作
void PropReduction50(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第51个产生式归约时的插桩动作
void PropReduction51(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第52个产生式归约时的插桩动作
void PropReduction52(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第53个产生式归约时的插桩动作
void PropReduction53(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第54个产生式归约时的插桩动作
void PropReduction54(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第55个产生式归约时的插桩动作
void PropReduction55(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第56个产生式归约时的插桩动作
void PropReduction56(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第57个产生式归约时的插桩动作
void PropReduction57(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第58个产生式归约时的插桩动作
void PropReduction58(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第59个产生式归约时的插桩动作
void PropReduction59(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第60个产生式归约时的插桩动作
void PropReduction60(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第61个产生式归约时的插桩动作
void PropReduction61(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第62个产生式归约时的插桩动作
void PropReduction62(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第63个产生式归约时的插桩动作
void PropReduction63(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第64个产生式归约时的插桩动作
void PropReduction64(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第65个产生式归约时的插桩动作
void PropReduction65(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第66个产生式归约时的插桩动作
void PropReduction66(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第67个产生式归约时的插桩动作
void PropReduction67(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第68个产生式归约时的插桩动作
void PropReduction68(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第69个产生式归约时的插桩动作
void PropReduction69(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第70个产生式归约时的插桩动作
void PropReduction70(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第71个产生式归约时的插桩动作
void PropReduction71(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第72个产生式归约时的插桩动作
void PropReduction72(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第73个产生式归约时的插桩动作
void PropReduction73(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第74个产生式归约时的插桩动作
void PropReduction74(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第75个产生式归约时的插桩动作
void PropReduction75(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第76个产生式归约时的插桩动作
void PropReduction76(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第77个产生式归约时的插桩动作
void PropReduction77(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第78个产生式归约时的插桩动作
void PropReduction78(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第79个产生式归约时的插桩动作
void PropReduction79(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第80个产生式归约时的插桩动作
void PropReduction80(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第81个产生式归约时的插桩动作
void PropReduction81(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第82个产生式归约时的插桩动作
void PropReduction82(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第83个产生式归约时的插桩动作
void PropReduction83(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第84个产生式归约时的插桩动作
void PropReduction84(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第85个产生式归约时的插桩动作
void PropReduction85(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第86个产生式归约时的插桩动作
void PropReduction86(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第87个产生式归约时的插桩动作
void PropReduction87(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第88个产生式归约时的插桩动作
void PropReduction88(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第89个产生式归约时的插桩动作
void PropReduction89(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第90个产生式归约时的插桩动作
void PropReduction90(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第91个产生式归约时的插桩动作
void PropReduction91(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第92个产生式归约时的插桩动作
void PropReduction92(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第93个产生式归约时的插桩动作
void PropReduction93(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第94个产生式归约时的插桩动作
void PropReduction94(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第95个产生式归约时的插桩动作
void PropReduction95(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第96个产生式归约时的插桩动作
void PropReduction96(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第97个产生式归约时的插桩动作
void PropReduction97(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第98个产生式归约时的插桩动作
void PropReduction98(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第99个产生式归约时的插桩动作
void PropReduction99(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第100个产生式归约时的插桩动作
void PropReduction100(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第101个产生式归约时的插桩动作
void PropReduction101(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第102个产生式归约时的插桩动作
void PropReduction102(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第103个产生式归约时的插桩动作
void PropReduction103(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第104个产生式归约时的插桩动作
void PropReduction104(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第105个产生式归约时的插桩动作
void PropReduction105(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第106个产生式归约时的插桩动作
void PropReduction106(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第107个产生式归约时的插桩动作
// statement -=> labeledstatement
void PropReduction107(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第108个产生式归约时的插桩动作
// statement -=> expression-statement
void PropReduction108(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第109个产生式归约时的插桩动作
// statement -=> compound-statement
void PropReduction109(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第110个产生式归约时的插桩动作
// statement -=> seletion-statement
void PropReduction110(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第111个产生式归约时的插桩动作
// statement -=> iteration-statement
void PropReduction111(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第112个产生式归约时的插桩动作
// statement -=> jump-statement
void PropReduction112(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第113个产生式归约时的插桩动作
// labeled-statement -=> idenfitier : statement
void PropReduction113(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第114个产生式归约时的插桩动作
// label-statement -=> case constant-expression : statement
void PropReduction114(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第115个产生式归约时的插桩动作
// labeled-atatement -=> defautt : statement;
void PropReduction115(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}




// 按照第116个产生式归约时的插桩动作
void PropReduction116(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第117个产生式归约时的插桩动作
void PropReduction117(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第118个产生式归约时的插桩动作
void PropReduction118(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第119个产生式归约时的插桩动作
void PropReduction119(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第120个产生式归约时的插桩动作
void PropReduction120(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第121个产生式归约时的插桩动作
void PropReduction121(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第122个产生式归约时的插桩动作
void PropReduction122(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第123个产生式归约时的插桩动作
void PropReduction123(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第124个产生式归约时的插桩动作
void PropReduction124(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第125个产生式归约时的插桩动作
void PropReduction125(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第126个产生式归约时的插桩动作
void PropReduction126(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}

// 按照第127个产生式归约时的插桩动作
// expression-statement -=> ;
void PropReduction127(PropTable propTable, SyntaxTree parentRoot)
{
#ifdef PARSER_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // PARSER_DEBUG_DEFINE
    TupleNode       *tupleNode = NULL;
    int         offset = -1;

    // 首先在语法子树中找到最后一个终结符
    if((tupleNode = FindFirstChildTupleNode(parentRoot)) != NULL)
    {
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    }
}



// 按照第128个产生式归约时的插桩动作
// expression-statement -=> expression ;
void PropReduction128(PropTable propTable, SyntaxTree parentRoot)
{
#ifdef PARSER_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // PARSER_DEBUG_DEFINE
   //  TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode = NULL;
    int         offset = -1;

    // 首先在语法子树中找到最后一个终结符
    if((tupleNode = FindFirstChildTupleNode(parentRoot)) != NULL)
    {
        offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }
    /*
    if((tupleNode = FindFinalChildTupleNode(parentRoot)) != NULL)
    {
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    }*/
}




// 按照第129个产生式归约时的插桩动作
void PropReduction129(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第130个产生式归约时的插桩动作
void PropReduction130(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第131个产生式归约时的插桩动作
void PropReduction131(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第132个产生式归约时的插桩动作
void PropReduction132(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第133个产生式归约时的插桩动作
void PropReduction133(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第134个产生式归约时的插桩动作
void PropReduction134(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第135个产生式归约时的插桩动作
// selection-statement -=> if( expression ) statement
// EG   if(left == right) printf("124");
// AS   if(LINE(stream), left == right) printf("124");
void PropReduction135(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode = NULL;
    int         offset = -1;

    // 首先查找到语法树中第一个词法节点终结符信息
    if((headTupleNode = FindFirstChildTupleNode(parentRoot)) != NULL)
    {
        // 查找到第一个"("的位置
        if((tupleNode = FindFirstTupleTreinal(headTupleNode, LPAREN_OPERATE)) != NULL)
        {
            // 在"("的位置上添加一个带","号的插桩信息串
            offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
            InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
        }
        else
        {
            FILE_FUNC_LINE( );
            fprintf(stderr, "在IF语句结构中找不到\"(\"符号的位置\n");
        }
    }
    else
    {
        FILE_FUNC_LINE( );
        fprintf(stderr, "当前IF语句语法子树中找不到终结符结点\n");
    }


}



// 按照第136个产生式归约时的插桩动作
// selection-statement -=> if( expression ) statement else statement
// if(left == right) printf("125YES"); else printf("125NO");
void PropReduction136(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode = NULL;
    PropTableNode   *newPropNode = NULL;
    int         offset = -1;

    // 首先查找到语法树中第一个词法节点终结符信息
    if((headTupleNode = FindFirstChildTupleNode(parentRoot)) != NULL)
    {
        // 查找到第一个"("的位置
        if((tupleNode = FindFirstTupleTreinal(headTupleNode, LPAREN_OPERATE)) != NULL)
        {
            // 在"("的位置上添加一个带","号的插桩信息串
            offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
            InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
        }
    }


}



// 按照第137个产生式归约时的插桩动作
// selection-statement -=> switch( expression ) statement
// switch(choice)
void PropReduction137(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode = NULL;
    PropTableNode   *newPropNode = NULL;
    int         offset = -1;

    // 首先查找到语法树中第一个词法节点终结符信息
    if((headTupleNode = FindFirstChildTupleNode(parentRoot)) != NULL)
    {
        // 查找到第一个"("的位置
        if((tupleNode = FindFirstTupleTreinal(headTupleNode, LPAREN_OPERATE)) != NULL)
        {
            // 在"("的位置上添加一个带","号的插桩信息串
            offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
            InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
        }
    }


}



// 按照第138个产生式归约时的插桩动作
// iteration-statement -=> while( expression ) statement ;
// EG while(i < 10) i++;
// AS while(LINE(stream), i < 10) i++;
void PropReduction138(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

    TupleNode     *tupleNode = NULL;

    // 找到"("LPAREN_OPERATE关键字的位置
    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, LPAREN_OPERATE)) != NULL)
    {
        // 在(运算符的后面插入数据LINE(stream),
        long offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }


}



// 按照第139个产生式归约时的插桩动作
// iteration-statement -=> do statement while ( expression ) ;
// EG do i++ while(i < 10);
// AS do i++ while(LINE(STREAM), i < 10);
void PropReduction139(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

    TupleNode     *tupleNode = NULL;
    TupleNode     *terinalNode = NULL;
    // 找到"("LPAREN_OPERATE关键字的位置
    // 我们不能直接用FindFirstSyntaxTreeTreinal(parentRoot, LPAREN_OPERATE)
    // 因为循环体statement中可能存在"("运算符，
    // 因此正确的方法应该是
    //      先找到while关键字, 然后在词法二元组链表中顺着while关键字往下找,
    //      找到的第一个"("就是所需要找到的那个"("符号
    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, WHILE_KEYWORD)) != NULL)      // 先找到while关键字
    {
        if((terinalNode = FindFirstTupleTreinal(tupleNode, LPAREN_OPERATE)) != NULL)
        {
            // 在(运算符的后面插入数据LINE(stream),
            long offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
            InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
        }

    }


}



// 按照第140个产生式归约时的插桩动作
// iteration-statement -=> for( ; ; ) statement
// EG for( ; ; ) i++;
// AS for( LINE(stream) ;  ; LINE(stream)) i++;
void PropReduction140(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置,
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在此位置插入一个带","的插桩数据串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {
        // 在第2个";"后面插入一个插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }
}



// 按照第141个产生式归约时的插桩动作
// iteration-statement -=> for( ; ;  expression ) statement
// eg for( ; ; i++) printf("130");
// AS for( LINE(strean); ; LINE(stream), i++) printf("130");
void PropReduction141(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置,
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在此位置插入一个带","的插桩数据串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {   //////////////////////////////////
        // 在第1个";"前面插入带","号的插桩信息串
        //offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
        //InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
        //////////////////////////////////
        // 在第2个";"后面插入一个插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }


}



// 按照第142个产生式归约时的插桩动作
// iteration-statement -=> for ( ; expression ; ) statement
// EG for( ; i < 10; ) i++;
// AS for( LINE(stream) ; i < 10; LINE(stream)) i++;
void PropReduction142(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置,
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在此位置插入一个带","的插桩数据串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {
        // 在第2个";"后面插入一个插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }


}



// 按照第143个产生式归约时的插桩动作
// iteration-statement -=> for( ; expression ; expression ) statement
// EG for( ; i < 10; i++) printf("132");
// AS for( LINE(stream); i < 10; LINE(stream), i++) printf("132");
void PropReduction143(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置,
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在此位置插入一个带","的插桩数据串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {
        // 在第2个";"后面插入一个插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }

}



// 按照第144个产生式归约时的插桩动作
// iteration-statemnt -=> for( expression ; ; ) statement
// EG for( i = 0 ; ;) printf("133");
// AS for( LINE(stream), i = 0 ; ; LINE(stream) ) printf("133");
void PropReduction144(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置,
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在此位置插入一个带","的插桩数据串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {   //////////////////////////////////
        // 在第1个";"前面插入带","号的插桩信息串
        //offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
        //InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
        //////////////////////////////////
        // 在第2个";"后面插入一个插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }


}



// 按照第145个产生式归约时的插桩动作
// iteration-statement -=> for( expression ; ; expression) printf("134");
// EG   for(i = 0 ; ; i++) printf("134");
// AS   for(LINE(stream), i = 0 ; ; LINE(stream), i++) printf("134");
void PropReduction145(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在第1个"("后面插入带","号的插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);

        tupleNode = NULL;       // 下面还要重新查找新的tupleNode，为防止出错, 将指针置空
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {
        // 在第2个";"后面插入带","号的插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }


}



// 按照第146个产生式归约时的插桩动作
// iteration-statement -=> for( expression ; expression ; ) printf("135");
// EG for(i = 0 ; i < 10 ; ) printf("135");
// AS for(LINE(stream), i = 0; i < 10; LINE(stream) ) printf("135");
void PropReduction146(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode      *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在第1个"("后面插入带","号的插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);

        tupleNode = NULL;       // 下面还要重新查找新的tupleNode，为防止出错, 将指针置空
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {
        // 在第2个";"后面插入一个基本插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_BASE_PROP_KIND);
    }


}



// 按照第147个产生式归约时的插桩动作
// iteraition-statement -=> for( expression ; expression ; expression ) statement
// EG   for(i = 0; i < 10; i++) printf("136");
// AS   for(LINE(stream), i = 10 ; i < 10; LINE(stream), i++) printf("136");
void PropReduction147(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
    TupleNode       *headTupleNode = NULL;
    TupleNode       *tupleNode  = NULL;
    PropTableNode   *newPropNode = NULL;
    int              offset = -1;


    // 在语法子树中找到第一个终结符结点
    headTupleNode = FindFirstChildTupleNode(parentRoot);

    // 找到第1个"("的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, LPAREN_OPERATE, 1)) != NULL)
    {
        // 在第1个";"前面插入带","号的插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }

    // 找到第2个";"的位置, 在此位置插入一个基本的插桩数据串
    if((tupleNode = FindTupleTreinal(headTupleNode, SEMICOLON_SEPARATOR, 2)) != NULL)
    {
        // 在第2个";"后面插入一个插桩信息串
        offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
    }


}



// 按照第148个产生式归约时的插桩动作
// jump-statement -=> goto identifier ;
// EG goto label
// AS  LINE(stream); goto label
void PropReduction148(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

//    TupleNode     *tupleNode = NULL;
//
//    // 找到goto关键字的位置
//    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, GOTO_KEYWORD)) != NULL)
//    {
//        // 在goto关键字的前面插入数据
//        long offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
//        InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
//    }
    long offset = -1;
    SyntaxTreeNode *treeNode = parentRoot;

    // 在起始位置添加一个" { LINE(strewam);"
    offset = treeNode->m_syntax.m_startCoord.m_fileBegOffset;
    InsertPropData(propTable, offset, PROP_LBRACE_SEPARATOR_KIND);
    InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    // 在起始位置添加一个" } "
    offset = treeNode->m_syntax.m_endCoord.m_fileEndOffset;
    InsertPropData(propTable, offset, PROP_RBRACE_SEPARATOR_KIND);
}



// 按照第149个产生式归约时的插桩动作
// jump-statement -=> continue ;
// EG continue ;
// AS LINE(stream); continue;
// AS
void PropReduction149(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

//    TupleNode     *tupleNode = NULL;
//
//    // 找到continue关键字的位置
//    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, CONTINUE_KEYWORD)) != NULL)
//    {
//        // 在continue关键字的前面插入数据
//        long offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
//        InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
//
//    }
    long offset = -1;
    SyntaxTreeNode *treeNode = parentRoot;

    // 在起始位置添加一个" { LINE(strewam);"
    offset = treeNode->m_syntax.m_startCoord.m_fileBegOffset;
    InsertPropData(propTable, offset, PROP_LBRACE_SEPARATOR_KIND);
    InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    // 在起始位置添加一个" } "
    offset = treeNode->m_syntax.m_endCoord.m_fileEndOffset;
    InsertPropData(propTable, offset, PROP_RBRACE_SEPARATOR_KIND);
}



// 按照第150个产生式归约时的插桩动作
// jump-statement -=> break;
void PropReduction150(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

    TupleNode     *tupleNode = NULL;

//    // 找到break关键字的位置
//    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, BREAK_KEYWORD)) != NULL)
//    {
//        // 在break关键字的前面插入数据
//        long offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
//        InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
//    }
    long offset = -1;
    SyntaxTreeNode *treeNode = parentRoot;

    // 在起始位置添加一个" { LINE(strewam);"
    offset = treeNode->m_syntax.m_startCoord.m_fileBegOffset;
    InsertPropData(propTable, offset, PROP_LBRACE_SEPARATOR_KIND);
    InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    // 在起始位置添加一个" } "
    offset = treeNode->m_syntax.m_endCoord.m_fileEndOffset;
    InsertPropData(propTable, offset, PROP_RBRACE_SEPARATOR_KIND);
}



// 按照第151个产生式归约时的插桩动作
// jump-statement -=> return;
// EG return ;
// AS LINE(stream); return ;
void PropReduction151(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

//    TupleNode     *tupleNode = NULL;
//
//    // 找到return关键字的位置
//    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, RETURN_KEYWORD)) != NULL)
//    {
//        // 在return关键字的前面插入数据
//        long offset = tupleNode->m_tuple.m_coord.m_fileBegOffset;
//        InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
//    }
    long offset = -1;
    SyntaxTreeNode *treeNode = parentRoot;

    // 在起始位置添加一个" { LINE(strewam);"
    offset = treeNode->m_syntax.m_startCoord.m_fileBegOffset;
    InsertPropData(propTable, offset, PROP_LBRACE_SEPARATOR_KIND);
    InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    // 在起始位置添加一个" } "
    offset = treeNode->m_syntax.m_endCoord.m_fileEndOffset;
    InsertPropData(propTable, offset, PROP_RBRACE_SEPARATOR_KIND);

}



// 按照第152个产生式归约时的插桩动作
// jump-statement -=> return expression ;
// 返回返回一个expression;的数据值
// EG   return NULL;
// AS   return Line(stream), NULL;
void PropReduction152(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

//
//    TupleNode     *tupleNode = NULL;
//
//    // 找到return字句的位置
//    if((tupleNode = FindFirstSyntaxTreeTreinal(parentRoot, RETURN_KEYWORD)) != NULL)
//    {
//        long offset = tupleNode->m_tuple.m_coord.m_fileEndOffset;
//        InsertPropData(propTable, offset, PROP_COMMA_PROP_KIND);
//    }
    long offset = -1;
    SyntaxTreeNode *treeNode = parentRoot;

    // 在起始位置添加一个" { LINE(strewam);"
    offset = treeNode->m_syntax.m_startCoord.m_fileBegOffset;
    InsertPropData(propTable, offset, PROP_LBRACE_SEPARATOR_KIND);
    InsertPropData(propTable, offset, PROP_SEMICOLON_PROP_KIND);
    // 在起始位置添加一个" } "
    offset = treeNode->m_syntax.m_endCoord.m_fileEndOffset;
    InsertPropData(propTable, offset, PROP_RBRACE_SEPARATOR_KIND);
}






// 按照第153个产生式归约时的插桩动作
void PropReduction153(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第154个产生式归约时的插桩动作
void PropReduction154(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第155个产生式归约时的插桩动作
void PropReduction155(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第156个产生式归约时的插桩动作
void PropReduction156(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第157个产生式归约时的插桩动作
void PropReduction157(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第158个产生式归约时的插桩动作
void PropReduction158(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第159个产生式归约时的插桩动作
void PropReduction159(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第160个产生式归约时的插桩动作
void PropReduction160(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第161个产生式归约时的插桩动作
void PropReduction161(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第162个产生式归约时的插桩动作
void PropReduction162(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第163个产生式归约时的插桩动作
void PropReduction163(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第164个产生式归约时的插桩动作
void PropReduction164(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第165个产生式归约时的插桩动作
void PropReduction165(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第166个产生式归约时的插桩动作
void PropReduction166(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第167个产生式归约时的插桩动作
void PropReduction167(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第168个产生式归约时的插桩动作
void PropReduction168(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第169个产生式归约时的插桩动作
void PropReduction169(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第170个产生式归约时的插桩动作
void PropReduction170(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第171个产生式归约时的插桩动作
void PropReduction171(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第172个产生式归约时的插桩动作
void PropReduction172(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第173个产生式归约时的插桩动作
void PropReduction173(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第174个产生式归约时的插桩动作
void PropReduction174(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第175个产生式归约时的插桩动作
void PropReduction175(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第176个产生式归约时的插桩动作
void PropReduction176(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第177个产生式归约时的插桩动作
void PropReduction177(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第178个产生式归约时的插桩动作
void PropReduction178(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第179个产生式归约时的插桩动作
void PropReduction179(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第180个产生式归约时的插桩动作
void PropReduction180(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第181个产生式归约时的插桩动作
void PropReduction181(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第182个产生式归约时的插桩动作
void PropReduction182(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第183个产生式归约时的插桩动作
void PropReduction183(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第184个产生式归约时的插桩动作
void PropReduction184(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第185个产生式归约时的插桩动作
void PropReduction185(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第186个产生式归约时的插桩动作
void PropReduction186(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第187个产生式归约时的插桩动作
void PropReduction187(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第188个产生式归约时的插桩动作
void PropReduction188(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第189个产生式归约时的插桩动作
void PropReduction189(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第190个产生式归约时的插桩动作
void PropReduction190(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第191个产生式归约时的插桩动作
void PropReduction191(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第192个产生式归约时的插桩动作
void PropReduction192(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第193个产生式归约时的插桩动作
void PropReduction193(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第194个产生式归约时的插桩动作
void PropReduction194(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第195个产生式归约时的插桩动作
void PropReduction195(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第196个产生式归约时的插桩动作
void PropReduction196(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第197个产生式归约时的插桩动作
void PropReduction197(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第198个产生式归约时的插桩动作
void PropReduction198(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第199个产生式归约时的插桩动作
void PropReduction199(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第200个产生式归约时的插桩动作
void PropReduction200(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第201个产生式归约时的插桩动作
void PropReduction201(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第202个产生式归约时的插桩动作
void PropReduction202(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第203个产生式归约时的插桩动作
void PropReduction203(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第204个产生式归约时的插桩动作
void PropReduction204(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第205个产生式归约时的插桩动作
void PropReduction205(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第206个产生式归约时的插桩动作
void PropReduction206(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第207个产生式归约时的插桩动作
void PropReduction207(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第208个产生式归约时的插桩动作
void PropReduction208(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第209个产生式归约时的插桩动作
void PropReduction209(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第210个产生式归约时的插桩动作
void PropReduction210(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第211个产生式归约时的插桩动作
void PropReduction211(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第212个产生式归约时的插桩动作
void PropReduction212(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第213个产生式归约时的插桩动作
void PropReduction213(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第214个产生式归约时的插桩动作
void PropReduction214(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第215个产生式归约时的插桩动作
void PropReduction215(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第216个产生式归约时的插桩动作
void PropReduction216(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第217个产生式归约时的插桩动作
void PropReduction217(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第218个产生式归约时的插桩动作
void PropReduction218(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}



// 按照第219个产生式归约时的插桩动作
void PropReduction219(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE

}

// 按照第220个产生式归约时的插桩动作
void PropReduction220(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第221个产生式归约时的插桩动作
void PropReduction221(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第222个产生式归约时的插桩动作
void PropReduction222(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第223个产生式归约时的插桩动作
void PropReduction223(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第224个产生式归约时的插桩动作
void PropReduction224(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第225个产生式归约时的插桩动作
void PropReduction225(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第226个产生式归约时的插桩动作
void PropReduction226(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第227个产生式归约时的插桩动作
void PropReduction227(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第228个产生式归约时的插桩动作
void PropReduction228(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第229个产生式归约时的插桩动作
void PropReduction229(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第230个产生式归约时的插桩动作
void PropReduction230(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第231个产生式归约时的插桩动作
void PropReduction231(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}



// 按照第232个产生式归约时的插桩动作
void PropReduction232(PropTable propTable, SyntaxTree parentRoot)
{
//#ifdef PARSER_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // PARSER_DEBUG_DEFINE
//    return NULL;
}

