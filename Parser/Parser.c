/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Parser.h                                                       *
*   Description: CTools-SyntacicParser                                          *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/








#include "Parser.h"    //  #include "..\Parser\Parser.h"





/// 对词法二元组链表进行语法分析
SyntaxTree ParseTuple(BinaryTuple douTuple)       // 词法二元组信息
{
//#ifdef LEXICAL_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // LEXICAL_DEBUG_DEFINE

    // 处理的词法分析模块
    TupleNode       *tupleNode = (TupleNode *)douTuple;       // 指向词法二元组的头结点

    // 语法分析栈
    StateStack      *stateStack = CreateStateStack( );         // 状态栈 -=> 存放每一步的状态信号
    SyntaxStack     *syntaxStack = CreateSyntaxStack( );         // 分析栈 -=> 存放已经识别出来的语法变量

    // 语法树模块
    SyntaxTreeNode  *parentNode = NULL;

    // 语法分析表
    ActionNode      *actionpNode = NULL;        // ACTON状态转移结点
    GoToNode        *gotopNode   = NULL;          // OTO状态转移结点

    // 归约时插桩处理
    #ifdef PROP_REDUCTION_DEFINE                // 初始化信息 -=》 在归约同时进行的插桩
    PropTable        propTable = CreatePropTable( );                  // 建立插桩信息表
    const char *destPropFname = PROP_FILE_NAME;                       // 插桩目标文件
    const char *srcPropFname = douTuple->m_tuple.m_coord.m_fileName;  // 待插桩源文件
    #endif // PROP_REDUCTION_DEFINE

    #ifdef PARSER_HELPS_DEFINE
    printf("*************************************************\n");
    printf("**  The File we Display is %10s   **\n", douTuple->m_tuple.m_data.m_fileName);       // 头结点的指针域指示着文件名
    printf("**  The File we Display is %10s   **\n", douTuple->m_tuple.m_coord.m_fileName);       // 头结点的指针域指示着文件名
    printf("*************************************************\n");
    PAUSE( );
    #endif



    // 栈信息进行初始化
    ///PushGrammarInSyntaxStack(SyntaxStack, SYN_ANA_TREE_NULL);             // 将#压入栈顶
    PushState(stateStack, (State)(0));                // 将初始状态压入栈中

    for(tupleNode = tupleNode->m_next;          // 指向第一个词法信息
        tupleNode != NULL; )                // 只要词法指针不为空
    {

//        if(IsProComTupleNode(tupleNode) == true)            // 当前结点是预编译指令
//        {
//            tupleNode = SkipProComTupleNode(tupleNode);              // 跳过预编译指令
//        }
        #ifdef PARSER_SHOWS_DEFINE
        printf("\n\n当前处理的词法信息:");
        ShowTupleNode(tupleNode);                // 显示当前处理词法信息
        #endif         // CTOOLS_SHOWS_DEINFE

        #ifdef PARSER_DEBUG_DEFINE
        printf("开始计算ACTION[%d, %d]\n", TopState(stateStack), tupleNode->m_tuple.m_kind);
        #endif // PARSER_DEBUG_DEFINE


        if((actionpNode = ACTION(TopState(stateStack), tupleNode)) != NULL)                  // 判断当前处理状态
        {
            #ifdef PARSER_SHOWS_DEFINE
            printf("ACTION[%d, %d] = action:%d, state:%d\n", TopState(stateStack), tupleNode->m_tuple.m_kind, (int)actionpNode->m_action, actionpNode->m_actState);
            #endif     // PARSER_HELPS_DEFINE
        }
        else
        {
            #ifdef PARSER_SHOWS_DEFINE
            printf("ACTION[%d, %d] = NULL\n", TopState(stateStack), tupleNode->m_tuple.m_kind, (int)actionpNode->m_action, actionpNode->m_actState);
            #endif     // PARSER_SHOWS_DEFINE
            fprintf(stderr, "在actionTable找不到对应的信息, 请检查语句的正确性，或者ActionTable的正确性\n");
            PAUSE( );
        }

        if(actionpNode->m_action == MOVING)     // 如果处理信息状态为移近-=>如果当前ACTION(状态, 读入符号) = S[i]
        {
            /// 移进 -=> 压入状态和符号
            #ifdef PARSER_SHOWS_DEFINE
            printf("正在开始移进....\n");
            #endif // PARSER_SHOWS_DEFINE

            PushTupleInSyntaxStack(syntaxStack, tupleNode);                // 移近输入符号 -=> 将符号信息压入分析栈
            PushState(stateStack, actionpNode->m_actState);      // 移近状态 -=> 将状态信息压入状态栈


            tupleNode = tupleNode->m_next;                            // 继续读入下一个词法信息
        }
        else if(actionpNode->m_action == REDUCTION)   // 如果处理信息状态为归约-=>如果当前ACTION(状态, 读入符号) = R[i]
        {
            /// 归约 -=>

            #ifdef PARSER_DEBUG_DEFINE
            ShowStateStack(stateStack);
            ShowSyntaxStack(syntaxStack);
            #endif // PARSER_DEBUG_DEFINE


            #ifdef PARSER_SHOWS_DEFINE          // 帮助信息-=>输出按照第几个产生式归约
            printf("正在开始归约....\n");
            printf("按照第%d个产生式开始规约\n", actionpNode->m_actState);                          // 按照第个actInfo.m_state个文法开始规约
            #endif      // PARSER_SHOWS_DEFINE

            // 首先将归约产生式的右部弹出分析栈
            parentNode = InsertSyntaxTree(syntaxStack, actionpNode->m_actState);           // 按照第actionpNode->m_actState个产生式建立语法子树

            #ifdef PROP_REDUCTION_DEFINE
//            if(actionpNode->m_actState <= 219)
//            {
//                printf("当前产生式编号%d\n", actionpNode->m_actState);
//                PAUSE( );
//            }
            // 按照第actionpNode->m_actState个产生式的形式对语法子树将插桩信息插入插桩信息表
            PropRed(propTable, parentNode, actionpNode->m_actState);
            #endif // PROP_REDUCTION_DEFINE

            PopedSyntax(syntaxStack, (int)RightGrammarLength(actionpNode->m_actState));
            PopedState(stateStack, (int)RightGrammarLength(actionpNode->m_actState));

            // 然后再将归约产生式的左部压入分析栈
            //PushGrammarInSyntaxStack(SyntaxStack, (SyntaxKind)LeftGrammarData(actionpNode->m_actState));      // 将左部文法符号压入
            PushSynTreeNodeInSynStack(syntaxStack, parentNode);

            #ifdef PARSER_DEBUG_DEFINE
            printf("开始计算GOTO[%d, %d]\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState));
            #endif // PARSER_DEBUG_DEFINE

            // 归约后需要转到一个新的状态重新开始, 依据gotoTable查询到这个状态, 将新的状态压入状态栈中
            if((gotopNode = GOTO((int)TopState(stateStack), (SyntaxKind)LeftGrammarData(actionpNode->m_actState))) != NULL)           // 归约后需要转到一个新的状态重新开售
            {
                #ifdef PARSER_SHOWS_DEFINE
                printf("GOTO[%d, %d] = goto%d\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState), gotopNode->m_gotoState);
                #endif      // PARSER_SHOWS_DEFINE
                PushState(stateStack, gotopNode->m_gotoState);                                    // 将新状态压入状态栈中
            }
            else
            {
                #ifdef PARSER_SHOWS_DEFINE
                printf("GOTO[%d, %d] = NULL\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState));
                #endif // PARSER_SHOWS_DEFINE
                fprintf(stderr, "在gotoTable找不到对应的信息, 请检查语句的正确性，或者GoToTable的正确性\n");
                PAUSE( );
            }
        }
        else if(actionpNode->m_action == ACCEPT)               // 否则接受了文法信息
        {
            // 当前字符被规约为正常符号
            printf("\nAccpet the Grammar\n");
            #ifdef PARSER_SHOWS_DEFINE
            printf("**********************************\n");
            printf("**\tACCEPT This Grammer\t**\n");
            printf("**********************************\n");
            #endif // PARSER_SHOWS_DEFINE

            DestroyStateStack(stateStack);                       // 销毁状态栈
            DestroySyntaxStack(syntaxStack);                       // 销毁分析栈
            break;
        }
        else if(actionpNode == NULL)
        {
            printf("\nThe Grammer you give is Wrong\n");
            DestroyStateStack(stateStack);                       // 销毁状态栈
            DestroySyntaxStack(syntaxStack);                       // 销毁分析栈
            break;
        }

//        #ifdef PARSER_DEBUG_DEFINE
//        PAUSE( );
//        #endif   // PARSER_DEBUG_DEFINE
    }

    #ifdef PROP_REDUCTION_DEFINE                // 初始化信息 -=》 在归约同时进行的插桩
    #ifdef PROP_SHOWS_DEFINE
    ShowPropTable(propTable);       // 显示插桩信息表
    #endif // PROP_REDUCTION_DEFINE
    #endif // PROP_SHOWS_DEFINE

    #ifdef PROP_REDUCTION_DEFINE
    WriteProp(propTable, destPropFname, srcPropFname);
    #endif // PROP_REDUCTION_DEFINE

//    printf("函数中语法树头结点%p\n", root);
//    PAUSE( );

    return (SyntaxTreeNode *)parentNode;
}


/// 对词法分析二元组进行语法分析，同时在归约时进行插桩，将插桩信息写入destFname中
SyntaxTree ParseTuplePropRed(BinaryTuple douTuple, const char *destFname)       // 词法二元组信息
{
//#ifdef LEXICAL_DEBUG_DEFINE
//FILE_FUNC_LINE( );
//#endif // LEXICAL_DEBUG_DEFINE

    // 处理的词法分析模块
    TupleNode       *tupleNode = (TupleNode *)douTuple;       // 指向词法二元组的头结点

    // 语法分析栈
    StateStack      *stateStack = CreateStateStack( );         // 状态栈 -=> 存放每一步的状态信号
    SyntaxStack     *syntaxStack = CreateSyntaxStack( );         // 分析栈 -=> 存放已经识别出来的语法变量

    // 语法树模块
    SyntaxTreeNode  *parentNode = NULL;

    // 语法分析表
    ActionNode      *actionpNode = NULL;        // ACTON状态转移结点
    GoToNode        *gotopNode   = NULL;          // OTO状态转移结点

    // 归约时插桩处理
    //#ifdef PROP_REDUCTION_DEFINE                // 初始化信息 -=》 在归约同时进行的插桩
    PropTable        propTable = CreatePropTable( );                  // 建立插桩信息表
    const char       *destPropFname = destFname;                       // 插桩目标文件
    const char       *srcPropFname = douTuple->m_tuple.m_coord.m_fileName;  // 待插桩源文件
    //#endif // PROP_REDUCTION_DEFINE

    #ifdef PARSER_HELPS_DEFINE
    printf("*************************************************\n");
    printf("**  The File we Display is %10s   **\n", douTuple->m_tuple.m_data.m_fileName);       // 头结点的指针域指示着文件名
    printf("**  The File we Display is %10s   **\n", douTuple->m_tuple.m_coord.m_fileName);       // 头结点的指针域指示着文件名
    printf("*************************************************\n");
    PAUSE( );
    #endif



    // 栈信息进行初始化
    ///PushGrammarInSyntaxStack(SyntaxStack, SYN_ANA_TREE_NULL);             // 将#压入栈顶
    PushState(stateStack, (State)(0));                // 将初始状态压入栈中

    for(tupleNode = tupleNode->m_next;          // 指向第一个词法信息
        tupleNode != NULL; )                // 只要词法指针不为空
    {
//        if(IsProComTupleNode(tupleNode) == true)            // 当前结点是预编译指令
//        {
//            tupleNode = SkipProComTupleNode(tupleNode);              // 跳过预编译指令
//        }

        #ifdef PARSER_SHOWS_DEFINE
        printf("\n\n当前处理的词法信息:");
        ShowTupleNode(tupleNode);                // 显示当前处理词法信息
        #endif         // PARSER_SHOWS_DEFINE

        #ifdef PARSER_DEBUG_DEFINE
        printf("开始计算ACTION[%d, %d]\n", TopState(stateStack), tupleNode->m_tuple.m_kind);
        #endif // PARSER_DEBUG_DEFINE
//        int top = TopState(stateStack);
//        if(top == 114 || top == 144 || top == 169 || top == 180 || top == 304 || top == 22 || top == 59)
//        {
//            FILE_FUNC_LINE( );
//            PAUSE( );
//        }

        if((actionpNode = ACTION(TopState(stateStack), tupleNode)) != NULL)                  // 判断当前处理状态
        {
            #ifdef PARSER_SHOWS_DEFINE
            printf("ACTION[%d, %d] = action:%d, state:%d\n", TopState(stateStack), tupleNode->m_tuple.m_kind, (int)actionpNode->m_action, actionpNode->m_actState);
            #endif     // PARSER_HELPS_DEFINE
        }
        else
        {
            #ifdef PARSER_SHOWS_DEFINE
            printf("ACTION[%d, %d] = NULL\n", TopState(stateStack), tupleNode->m_tuple.m_kind, (int)actionpNode->m_action, actionpNode->m_actState);
            #endif     // PARSER_SHOWS_DEFINE

            ShowCoord(&(tupleNode->m_tuple.m_coord));
            printf("\n");
            printf("ACTION[%d, %d]\n", TopState(stateStack), tupleNode->m_tuple.m_kind);
            fprintf(stderr, "在actionTable找不到对应的信息, 请检查语句的正确性，或者ActionTable的正确性\n");
            PAUSE( );
        }

        if(actionpNode->m_action == MOVING)     // 如果处理信息状态为移近-=>如果当前ACTION(状态, 读入符号) = S[i]
        {
            /// 移进 -=> 压入状态和符号
            #ifdef PARSER_SHOWS_DEFINE
            printf("正在开始移进....\n");
            #endif // PARSER_SHOWS_DEFINE

            PushTupleInSyntaxStack(syntaxStack, tupleNode);                // 移近输入符号 -=> 将符号信息压入分析栈
            PushState(stateStack, actionpNode->m_actState);      // 移近状态 -=> 将状态信息压入状态栈


            tupleNode = tupleNode->m_next;                            // 继续读入下一个词法信息
        }
        else if(actionpNode->m_action == REDUCTION)   // 如果处理信息状态为归约-=>如果当前ACTION(状态, 读入符号) = R[i]
        {
            /// 归约 -=>

            #ifdef PARSER_DEBUG_DEFINE
            ShowStateStack(stateStack);
            ShowSyntaxStack(syntaxStack);
            #endif // PARSER_DEBUG_DEFINE


            #ifdef PARSER_SHOWS_DEFINE          // 帮助信息-=>输出按照第几个产生式归约
            printf("正在开始归约....\n");
            printf("按照第%d个产生式开始规约\n", actionpNode->m_actState);                          // 按照第个actInfo.m_state个文法开始规约
            #endif      // PARSER_SHOWS_DEFINE

            // 首先将归约产生式的右部弹出分析栈
            parentNode = InsertSyntaxTree(syntaxStack, actionpNode->m_actState);           // 按照第actionpNode->m_actState个产生式建立语法子树

            //#ifdef PROP_REDUCTION_DEFINE
//            if(actionpNode->m_actState == 223)
//            {
//                printf("当前产生式编号%d\n", actionpNode->m_actState);
//                PAUSE( );
//            }
            // 按照第actionpNode->m_actState个产生式的形式对语法子树将插桩信息插入插桩信息表
            PropRed(propTable, parentNode, actionpNode->m_actState);
            //#endif // PROP_REDUCTION_DEFINE

            PopedSyntax(syntaxStack, (int)RightGrammarLength(actionpNode->m_actState));
            PopedState(stateStack, (int)RightGrammarLength(actionpNode->m_actState));

            // 然后再将归约产生式的左部压入分析栈
            //PushGrammarInSyntaxStack(SyntaxStack, (SyntaxKind)LeftGrammarData(actionpNode->m_actState));      // 将左部文法符号压入
            PushSynTreeNodeInSynStack(syntaxStack, parentNode);

            #ifdef PARSER_DEBUG_DEFINE
            printf("开始计算GOTO[%d, %d]\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState));
            #endif // PARSER_DEBUG_DEFINE

            // 归约后需要转到一个新的状态重新开始, 依据gotoTable查询到这个状态, 将新的状态压入状态栈中
            if((gotopNode = GOTO((int)TopState(stateStack), (SyntaxKind)LeftGrammarData(actionpNode->m_actState))) != NULL)           // 归约后需要转到一个新的状态重新开售
            {
                #ifdef PARSER_SHOWS_DEFINE
                printf("GOTO[%d, %d] = goto%d\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState), gotopNode->m_gotoState);
                #endif      // PARSER_SHOWS_DEFINE
                PushState(stateStack, gotopNode->m_gotoState);                                    // 将新状态压入状态栈中
            }
            else
            {
                #ifdef PARSER_SHOWS_DEFINE
                printf("GOTO[%d, %d] = NULL\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState));
                #endif // PARSER_SHOWS_DEFINE

                ShowCoord(&(tupleNode->m_tuple.m_coord));
                printf("\n");
                printf("开始计算GOTO[%d, %d]\n", TopState(stateStack), LeftGrammarData(actionpNode->m_actState));
                fprintf(stderr, "在gotoTable找不到对应的信息, 请检查语句的正确性，或者GoToTable的正确性\n");
                PAUSE( );
            }
        }
        else if(actionpNode->m_action == ACCEPT)               // 否则接受了文法信息
        {
            // 当前字符被规约为正常符号
            #ifdef PARSER_SHOWS_DEFINE
            printf("**********************************\n");
            printf("**\tACCEPT This Grammer\t**\n");
            printf("**********************************\n");
            #endif // PARSER_SHOWS_DEFINE
            printf("*****Accept the Grammar*****\n");

            DestroyStateStack(stateStack);                       // 销毁状态栈
            DestroySyntaxStack(syntaxStack);                       // 销毁分析栈
            break;
        }
        else if(actionpNode == NULL)
        {
            printf("\nThe Grammer you give is Wrong\n");
            //DestroyStack(stateStack);                       // 销毁状态栈
            //DestroyStack(SyntaxStack);                       // 销毁分析栈
            break;
        }

        /// STEP BY STEP
//        #ifdef PARSER_DEBUG_DEFINE
//        PAUSE( );
//        #endif   // PARSER_DEBUG_DEFINE
    }

    #ifdef PROP_SHOWS_DEFINE
    ShowPropTable(propTable);       // 显示插桩信息表
    #endif // PROP_SHOWS_DEFINE


    //#ifdef PROP_REDUCTION_DEFINE
    WriteProp(propTable, destPropFname, srcPropFname);          // 将插桩信息写入插桩目标文件
    DestroyPropTable(propTable);                                // 销毁插桩信息表
    //#endif // PROP_REDUCTION_DEFINE

    return (SyntaxTreeNode *)parentNode;
}

/// 对文件fileName进行语法分析
SyntaxTree ParseFile(const char *sourFile)          // 源文件名称
{
    SyntaxTree     syntaxRoot;
    #ifdef PARSER_HELPS_DEFINE
    printf("**********************************************************\n");
    printf("**  The file you want to syntax is \"%10s\"  **\n", sourFile);
    printf("**********************************************************\n");
    #endif // PARSER_HELPS_DEFINE

    BinaryTuple douTuple = NULL;               // 二元组信息

    douTuple = BufferLexical(sourFile);      // 直接处理源文件


    #ifdef PARSER_SHOWS_DEFINE
    VisitTuple(douTuple);            // 遍历二元组信息, 查找二元组正确性
    #endif // PARSER_SHOWS_DEFINE

    syntaxRoot = ParseTuple(douTuple);

    if(syntaxRoot != NULL)
    {
        #ifdef PARSER_SHOWS_DEFINE
        printf("语法树深度%d\n", GetSyntaxTreeHeight(syntaxRoot));
        printf("语法树结点%d\n", GetSyntaxTreeNodeCount(syntaxRoot));
        PAUSE( );
        #endif // PARSER_SHOWS_DEFINE



        //printf("树形显示语法树\n");
        //ShowSyntaxTree(syntaxRoot);

        #ifdef PARSER_DEBUG_DEFINE
        printf("先序遍历语法树\n");
        PreOrderSytaxTree(syntaxRoot);
        PAUSE( );

        printf("中序遍历语法树\n");
        InOrderSyntaxTree(syntaxRoot);
        PAUSE( );

        printf("后序遍历语法树\n");
        PostOrderSyntaxTree(syntaxRoot);
        PAUSE( );
        #endif // PARSER_DEBUG_DEFINE

    }

    #ifdef PARSER_HELPS_DEFINE
    VERSION( );
    #endif          // LEXICAL_HELPS_DEFINE

    DestroyTuple(douTuple);                // 清空二元组空间为系统节省内存空间

    return syntaxRoot;                  // 对词法二元组进行语法分析
}


/// 对文件fileName进行语法分析, 同时进行插桩分析
SyntaxTree ParseFilePropRed(const char *destFname, const char *sourFname)          // 源文件名称
{
     SyntaxTree     syntaxRoot;
    #ifdef PARSER_HELPS_DEFINE
    printf("**********************************************************\n");
    printf("**  The file you want to syntax is \"%10s\"  **\n", sourFname);
    printf("**********************************************************\n");
    #endif // PARSER_HELPS_DEFINE

    BinaryTuple douTuple = NULL;               // 二元组信息

    /// 对源文件sourFname词法处理
    douTuple = BufferLexical(sourFname);      // 直接处理源文件

    #ifdef PARSER_SHOWS_DEFINE
    VisitTuple(douTuple);            // 遍历二元组信息, 查找二元组正确性
    #endif // PARSER_SHOWS_DEFINE

    /// 对源文件进行语法分析，并将插桩信息写入destFname
    syntaxRoot = ParseTuplePropRed(douTuple, destFname);


    #ifdef PARSER_HELPS_DEFINE
    VERSION( );
    #endif          // LEXICAL_HELPS_DEFINE

    DestroyTuple(douTuple);                // 清空二元组空间为系统节省内存空间

    return syntaxRoot;                  // 对词法二元组进行语法分析
}


/// 语法分析测试主程序
bool TestOfParse( )
{
    return ParseFile("TEST/test0.c");
}





/// 0.6.0更新
/// 语法析的时候需要将预编译指令跳过
/// 跳过所有预编译命令的行
TupleNode* SkipProComTupleNode(TupleNode *tupleNode)
{
    assert(tupleNode->m_tuple.m_kind == POUND_SEPARATOR             // 预编译指令以'#'开头
        && tupleNode->m_next->m_tuple.m_data.m_keyCode == PROCOM);   // '#'后面一个指令为预编译命令

    int line = tupleNode->m_tuple.m_coord.m_fileLine;

    while( 1 )
    {
        //ShowTupleData(tupleNode);
        tupleNode = tupleNode->m_next;

        if(tupleNode->m_tuple.m_coord.m_fileLine != line)           // 编译指令是以行为单位的
        {
            if(tupleNode->m_last->m_tuple.m_kind == BACKSLASH_SEPARATOR)       // '\'续行符号可以作为让预编译占用多行
            {
                line = tupleNode->m_tuple.m_coord.m_fileLine;
            }
            else            // 遇到了一个新的行，而上一行没有续行，则说明预编译指令的结束
            {
                break;
            }
        }
    }

    return tupleNode;
}
