/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : BinaryTuple.h                                                  *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/


#include "Buffer.h"

///**
//说明:
//①  每个缓冲区的大小为 -=> BUFFER_SIZE + sizeof(char) = 4097
//    则缓冲区的下标为[0..BUFFER_SIZE - 1], 而[BUFFER_SIZE]将存储EOF
//
//②  每次起初两个指针之间的字符串应该取出来的区间是[m_lexeme, m_forward);
//
//
//③ 当向前指针指向了一个新的缓冲区时，开始指针仍然指向前一个旧的缓冲区
//    这是使用m_using缓冲区仍然指旧的缓冲区, 只有在执行了Check后使用缓冲区才指向新的缓冲区
//
//④   检索向前指针和开始指针在不在同一个缓冲区的时候，根据③，使用的仍然是旧的缓冲区
//    由于向前指针一定在现在新填充的缓冲区，
//    因此只需要看向前指针在不在当前使用的缓冲区内即可
//**/

/**
说明:0.6.9对缓冲区进行了重新修改
    原始版本的实现中，需要在Check和AddbufLexeme的函数中都修改缓冲区使用标识
    现在的版本， 只要在PutBuffer后，使用标识m_using和向前m_forward均已经指向了新的缓冲区

    这样只有一个地方可以实现m_using的修改，可以使缓冲区的实现对程序员透明

①  每个缓冲区的大小为 -=> BUFFER_SIZE + sizeof(char) = 4097
    则缓冲区的下标为[0..BUFFER_SIZE - 1], 而[BUFFER_SIZE]将存储EOF

②  每次起初两个指针之间的字符串应该取出来的区间是[m_lexeme, m_forward);
    前闭后开

③ 当向前指针指向了一个新的缓冲区时，开始指针仍然指向前一个旧的缓冲区
    这是使用m_using缓冲区已经指向了新的缓冲区,

④   检索向前指针和开始指针在不在同一个缓冲区的时候，根据③，使用的已经是新的缓冲区
    因此由于向前指针一定在现在新填充的缓冲区(使用缓冲区)，而开始指针可能仍然在前一个旧的缓冲区中
    因此只需要看开始指针在不在当前使用的缓冲区内即可
**/


/// 将字符串str填入到缓冲区中
/*[实现方法]
    依据档当前向前指针的位置, 将字符串信息str填入文件
    填入完成后, 调整开始指针和向前指针均指向当前填入字符串后缓冲区的位置
    返回值：如果填入过程中修改了缓冲区的位置, 返回非零值false, 否则返回true
*/
bool WriteStrInBuffer(DouBuffer *douBuffer, char *str)
{
    assert(douBuffer->m_lexeme  == douBuffer->m_forward);       // 必须要求开始指针和向前指针都指向起始位置

    char *pStr = str;                   // 新指针指向当前字符串的首地址

    // 只要字符串没有结束同时当前缓冲区没有结束就将整个字符串中的数据填入缓冲区
    while(*pStr != '\0' && douBuffer->m_forward < BufferEnd(douBuffer, THIS))                // 循环整个字符串
    {
        *(douBuffer->m_forward) = *pStr;        // 将字符串存入缓冲区的向前指针中
        (douBuffer->m_forward)++;                 // 向前指针指向下一个位置
        pStr++;                 // 字符串指向下一个位置
    }

    if(douBuffer->m_forward == BufferEnd(douBuffer, THIS)/*&& pStr != '\0'*/)        // 如果缓冲区结束了但是字符串还没有完全存进去
    {   // 将剩余的字符填到另外的缓冲区中
        /// 首先将缓冲缓冲区中的内容写入输出文件中
        douBuffer->m_forward = BufferBegin(douBuffer, OTHER);           // 切换到另外一个缓冲区的开始位置
        while(*pStr != '\0')            // 将上一过程字符串中剩余没有填入缓冲区的字符串填进去
        {
            *(douBuffer->m_forward) = *pStr;        // 将字符串存入缓冲区的向前指针中
            (douBuffer->m_forward)++;                 // 向前指针指向下一个位置
            pStr++;                 // 字符串指向下一个位置
        }

        douBuffer->m_using *= -1;       // 更改使用缓冲区
        douBuffer->m_lexeme = douBuffer->m_forward;      // 向前指针和开始指针都指向缓冲区

        return false;              // 如果修改了缓冲区的使用情况-=>返回false
    }
    return true;                   //没有修改缓冲区的使用情况返回true
}


/// 将缓冲区中的信息填入文件中
int WriteBufferToFile(DouBuffer *douBuffer, CToolsFILE ofp, int choice)
{
    #ifdef CTOOLS__DEBUG_DEFINE
    assert(ofp != NULL);
    #endif
    if(douBuffer->m_fp == NULL)             // 如果输出文件指针为空参数错误
    {
        return 0;
    }

    switch(choice)          // 依据将要处理的信息进行处理
    {
    case LEFT:              // 如果将要处理的是左部缓冲区
        WriteLeftBufferToFile(douBuffer, ofp);      // 将左部缓冲区的信息写入输出文件

        break;
    case RIGHT:             // 如果将要处理的是右部缓冲区
        WriteRightBufferToFile(douBuffer, ofp);     // 将右部缓冲区的信息写入输出文件
        break;
    case ALL:               // 如果将要处理的全部的缓冲区
        WriteLeftBufferToFile(douBuffer, ofp);      // 先将左部缓冲区的数据写会文件
        WriteRightBufferToFile(douBuffer, ofp);     // 先将右部缓冲区的数据写会文件
        break;
    }

    return 0;
}

/// 将缓冲区中的信息填入文件中
int WriteLeftBufferToFile(DouBuffer *douBuffer, CToolsFILE ofp)
{
    #ifdef CTOOLS_DEBUG_DEFINE
    assert(douBuffer != NULL && douBuffer->m_leftBuffer != NULL && douBuffer->m_fp != NULL);
    #endif      //  CTOOLS_DEBUG_DEFINE

    // 将左部缓冲区指针开始的BUFFER_SZIE个字节的数据写入ofp文件中
    #ifdef CTOOLS_FILE_OPEN_BINARY
    fwrite(douBuffer->m_leftBuffer, BUFFER_SIZE, 1, douBuffer->m_fp);
    #endif // CTOOLS_FILE_OPEN_BINARY
    #ifdef CTOOLS_FILE_OPEN_TEXT
    //fputs(douBuffer->m_leftBuffer, BUFFER_SIZE, douBuffer->m_fp);

    #endif // CTOOLS_FILE_OPEN_TEXT

    return 0;
}

/// 将缓冲区中的信息填入文件中
int WriteRightBufferToFile(DouBuffer *douBuffer, CToolsFILE ofp)
{
    #ifdef CTOOLS_DEBUG_DEFINE
    assert(douBuffer != NULL && douBuffer->m_rightBuffer != NULL && douBuffer->m_fp != NULL);
    #endif      //  CTOOLS_DEBUG_DEFINE

    // 将右部缓冲区指针开始的BUFFER_SZIE个字节的数据写入ofp文件中
    #ifdef CTOOLS_FILE_OPEN_BINARY
    fwrite(douBuffer->m_rightBuffer, BUFFER_SIZE, 1, ofp);
    #endif // CTOOLS_FILE_OPEN_BINARY
    #ifdef CTOOLS_FILE_OPEN_TEXT
    fgets(douBuffer->m_rightBuffer, BUFFER_SIZE, douBuffer->m_fp);
    #endif // CTOOLS_FILE_OPEN_TEXT
    return 0;
}


/// 将待处理源文件m_fp文件中信息以字符为单位读入缓冲区
int PutBuffer(DouBuffer *douBuffer)
{
    if(feof(douBuffer->m_fp) != 0)           // 首先检测是否数据文件末尾
    {
        return CToolsIsEOF;       // #define -1
    }

    int i = 0;
    int ch;

    switch((int)douBuffer->m_using)
    {
        case LEFT  :        // 如果当前正在处理缓冲区的左部分
            while((i < (int)BUFFER_SIZE) && ((ch = CToolsGetc(douBuffer->m_fp)) != EOF))          // 将数据填入右部分缓冲区
            {
                douBuffer->m_rightBuffer[i++] = ch;
                //printf("%d\n", douBuffer->m_rightBuffer[i-1]);
            }
            douBuffer->m_rightBuffer[i] = (char)EOF;      // 缓冲区末尾填入文件结束标志EOF

            douBuffer->m_forward = douBuffer->m_rightBuffer;      // 向前指针初始化指向缓冲区开头

            douBuffer->m_using = RIGHT;
            #ifdef CTOOLS_HELPS_DEFINE       // 利用帮助信息宏-=>提示数据已经写入右缓冲区
            FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
            printf("\n\t\t***********************************************\n");
            printf("\t\t**Data are already write in the RightBuffer..**\n");
            printf("\t\t***********************************************\n");
            PAUSE( );
            #endif      // CTOOLS_HELPS_DEFINE

            break;

        case NOT_USE:                       // 刚刚初始化完毕
            douBuffer->m_lexeme =  douBuffer->m_forward = douBuffer->m_leftBuffer;      // 调整指针指向左部缓冲区开始位置
            //douBuffer->m_using = LEFT;                // 初始会使用左部缓冲区
            /*break;*/
        case RIGHT :        // 如果当前正在处理缓冲区的右部分, 则接下来直接将数据写入左缓冲区
            while(i < (int)BUFFER_SIZE && ((ch = CToolsGetc(douBuffer->m_fp)) != EOF))          // 将数据填入右部分缓冲区
            {
                douBuffer->m_leftBuffer[i++] = ch;
                //printf("%d\n", douBuffer->m_leftBuffer[i-1]);
            }
            douBuffer->m_leftBuffer[i] = (char)EOF;      // 缓冲区末尾填入文件结束标志EOF

            douBuffer->m_forward = douBuffer->m_leftBuffer;          // 向前指针初始化指向缓冲区开头

            douBuffer->m_using = LEFT;
            #ifdef CTOOLS_HELPS_DEFINE               // 利用帮助信息宏-=>提示数据已经写入左缓冲区
            FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
            printf("\n\t\t***********************************************\n");
            printf("\t\t**Data are already write in the LeftBuffer...**\n");
            printf("\t\t***********************************************\n");
            PAUSE( );
            #endif        // CTOOLS_HELPS_DEFINE

            break;
        default :
            #ifdef CTOOLS_HELPS_DEFINE
            FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
            printf("\n\t\t***********************************************\n");
            printf("\t\t**     Error When Date Put in PutBuffer...   **\n");
            printf("\t\t***********************************************\n");
            PAUSE( );
            #endif      // CTOOLS_HELPS_DEFINE
            break;
    }

    //PAUSE( );
    if(feof(douBuffer->m_fp) != 0)
    {
        return CToolsToEOF;       // #define 1
    }
    else
    {
        return CToolsNotEOF;    // #define 0
    }
}

/* 建立双缓冲区文件
DouBuffer* CreateBuffer()
{
    DouBuffer *douBuffer = (DouBuffer *)malloc(sizeof(DouBuffer));          // 开破缓冲区的结构存储信息

    // 首先初始化缓冲区的区域信息
    douBuffer->m_leftBuffer = (char *)malloc(BUFFER_SIZE + sizeof(char));     // 开辟左缓冲区的空间
    douBuffer->m_rightBuffer = (char *)malloc(BUFFER_SIZE + sizeof(char));    // 开辟右缓冲区的空间

    // 初始化向左部缓冲区写入信息
    douBuffer->m_using = NOT_USE;     // 初始化缓冲区为RIGHT, 这样会优先使用做缓冲区进行写入

    return douBuffer;
}
*/

// 初始化缓冲区的信息
DouBuffer* InitBuffer(const char *fileName)
{
    DouBuffer *douBuffer = (DouBuffer *)malloc(sizeof(DouBuffer));          // 开破缓冲区的结构存储信息
    // 首先初始化缓冲区的区域信息
    douBuffer->m_leftBuffer = (char *)malloc(BUFFER_SIZE + sizeof(char));     // 开辟左缓冲区的空间
    douBuffer->m_rightBuffer = (char *)malloc(BUFFER_SIZE + sizeof(char));    // 开辟右缓冲区的空间

    douBuffer->m_using = NOT_USE;               // 当前缓冲区刚初始化, 还未有使用位置

    /// 打开源文件
    #ifdef CTOOLS_FILE_OPEN_TEXT
    douBuffer->m_fp = CToolsOpen(fileName, READ_ONLY_TEXT);
    #endif // CTOOLS_FILE_OPEN_TEXT
    // 这两个代码是不能共存的...
    #ifdef CTOOLS_FILE_OPEN_BINARY
    douBuffer->m_fp = CToolsOpen(fileName, READ_ONLY_BINARY);
    #endif // CTOOLS_FILE_OPEN_BINARY

    douBuffer->m_lexeme = NULL;
    douBuffer->m_forward = NULL;

    douBuffer->m_coord = InitCoord(fileName);       // 根据源文件信息初始化偏移信息

    #ifdef CTOOLS_HELPS_DEFINE         // 利用帮助宏 -=> 提示缓冲区已经初始化
    FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
    printf("\n\t*****************************************************************\n");
    printf("\t**The Double Buffer has been init for you to read infomation...**\n");
    printf("\t*****************************************************************\n");
    PAUSE( );
    #endif          // CTOOLS_HELPS_DEFINE

    return douBuffer;
}




// 缓冲区收尾工作
void FinitBuffer(DouBuffer *douBuffer)
{
    // 销毁左部缓冲区
    if(douBuffer->m_leftBuffer != NULL)
    {
        free(douBuffer->m_leftBuffer);
    }

    // 销毁右部缓冲区
    if(douBuffer->m_rightBuffer != NULL)
    {
        free(douBuffer->m_rightBuffer);
    }

    // 关闭文件
    CToolsClose(douBuffer->m_fp);

    // 销毁位置信息标识
    if(douBuffer->m_coord != NULL)
    {
        free(douBuffer->m_coord);
    }

    // 销毁缓冲区结构
    if(douBuffer != NULL)           // 销毁为缓冲区指针开辟的空间
    {
        free(douBuffer);
    }



    #ifdef CTOOLS_HELPS_DEFINE         // 利用帮助宏 -=> 提示缓冲区已经完成收尾
    FILE_FUNC_LINE( );      // 显示文件名-函数名-行号
    printf("\n\t*****************************************************************\n");
    printf("\t**       Dis End...The Double Buffer has been destroy...       **\n");
    printf("\t*****************************************************************\n");
    PAUSE( );
    #endif          // CTOOLS_HELPS_DEFINE
}

// 计算缓冲区两个指针之间字符串的长度
int TokenLength(DouBuffer *douBuffer)
{
    if(IsInSameBuffer(douBuffer) == true)   // 如果两个指针在一个缓冲区
    {
        #ifdef CTOOLS_DEBUG_DEFINE
        printf("两个指针在同一个缓冲区\n");
        #endif // CTOOLS_DEBUG_DEFINE

        return (douBuffer->m_forward - douBuffer->m_lexeme);    // 返回
    }
    else        // 此时两个指针同一个缓冲区
    {
        #ifdef CTOOLS_DEBUG_DEFINE
        printf("两个指针不在同一缓冲区\n");
        FILE_FUNC_LINE( );
        printf("正在使用%d缓冲区\n", douBuffer->m_using);
        printf("开始指针%p\n", douBuffer->m_lexeme);
        printf("向前指针%p\n", douBuffer->m_forward);
        printf("左缓冲区开始[%p, %p]\n", douBuffer->m_leftBuffer, douBuffer->m_leftBuffer + BUFFER_SIZE);
        printf("右缓冲区开始[%p, %p]\n", douBuffer->m_rightBuffer, douBuffer->m_rightBuffer + BUFFER_SIZE);
        #ifdef CTOOLS_STEP_DEFINE
        PAUSE( );
        #endif
        #endif // CTOOLS_DEBUG_DEFINE


        return ((douBuffer->m_forward - BufferBegin(douBuffer, THIS))/*向前指针与所在缓冲区开始的差值*/ + (BufferEnd(douBuffer, OTHER) - douBuffer->m_lexeme));
    }
}



// 将开始字符与向前指针之间的字符区出来
char* CopyBufToken(DouBuffer *douBuffer)
{
#ifdef CTOOLS_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // CTOOLS_DEBUG_DEFINE
    #ifdef CTOOLS_DEBUG_DEFINE
    printf("%p %p %d\n", douBuffer->m_lexeme, douBuffer->m_forward, TokenLength(douBuffer));
    #endif // CTOOLS_DEBUG_DEFINE

    if(TokenLength(douBuffer) < 1)               // 串长度小于1, 说明中间没有串可以提取-=>返回
    {
        if(TokenLength(douBuffer) < 0)
        {
            FILE_FUNC_LINE( );
            printf("正在使用%d缓冲区\n", douBuffer->m_using);
            printf("开始指针%p\n", douBuffer->m_lexeme);
            printf("向前指针%p\n", douBuffer->m_forward);
            printf("左缓冲区开始[%p, %p]\n", douBuffer->m_leftBuffer, douBuffer->m_leftBuffer + BUFFER_SIZE);
            printf("右缓冲区开始[%p, %p]\n", douBuffer->m_rightBuffer, douBuffer->m_rightBuffer + BUFFER_SIZE);
            printf("前面的串长度%p - %p = %d\n", BufferEnd(douBuffer, OTHER), douBuffer->m_lexeme, (BufferEnd(douBuffer, OTHER) - douBuffer->m_lexeme));
            printf("后面的串长度%p - %p = %d\n", douBuffer->m_forward, BufferBegin(douBuffer, THIS), (douBuffer->m_forward - BufferBegin(douBuffer, THIS)));
            printf("检索缓冲区串时都时出错\n");

            PAUSE( );

        }
        return NULL;
    }

    char    *token = (char *)malloc(TokenLength(douBuffer) + 1);
    char    *pbuf = douBuffer->m_lexeme, *pstr = token;

    if(IsInSameBuffer(douBuffer) == true)          // 如果两个指针在同一个缓冲区
    {//FILE_FUNC_LINE( );
        //printf("连个指针在同一个缓冲区\n");
        while(pbuf < (douBuffer->m_forward))     // 复制每个字符串
        {
            //printf("%p %p\n", pbuf, douBuffer->m_forward);
            *(pstr++) = *(pbuf++);
            //printf("%p %p\n", pbuf, douBuffer->m_forward);
        }
        *pstr = '\0';
    }
    else
    {
        while(pbuf < BufferEnd(douBuffer, OTHER))            // 首先取出当前指针中的串
        {
            *pstr++ = *pbuf++;
        }

        // 再取出在另一个缓冲区的信息
        pbuf = BufferBegin(douBuffer, THIS);
        while(pbuf < douBuffer->m_forward)
        {
            *pstr++ = *pbuf++;
        }
        *pstr = '\0';
    }
//    else if(douBuffer->m_using == LEFT)      // 仍然在使用左缓冲区, 但是向前指针
//    {//FILE_FUNC_LINE( );
//         //printf("开始指针在左缓冲区, 向前指针在右缓冲区\n");
//         while(pbuf < LeftBufferEnd(douBuffer))     //  先将现在缓冲区中的信息返回
//         {
//             *pstr++ = *pbuf++;
//         }
//         pbuf = douBuffer->m_rightBuffer;     // 将赋值指针定位在缓冲区开始位置
//         while(pbuf < douBuffer->m_forward)          // 复制现在缓冲区中的缓冲块
//         {
//             *pstr++ = *pbuf++;
//         }
//         *pstr = '\0';
//    }
//    else if(douBuffer->m_using == RIGHT)
//    {//FILE_FUNC_LINE( );
//         //printf("开始指针在右缓冲区, 向前指针在左缓冲区\n");
//         while(pbuf < RightBufferEnd(douBuffer))
//         {
//             *pstr++ = *pbuf++;
//         }
//         pbuf = douBuffer->m_leftBuffer;
//         while(pbuf < douBuffer->m_forward)
//         {
//             *pstr++ = *pbuf++;
//         }
//         *pstr = '\0';
//    }

    #ifdef CTOOLS_DEBUG_DEFINE
    printf("提取出来的字符串为：%s\n", token);
    #endif // CTOOLS_DEBUG_DEFINE

    return token;       // 返回串指针
}


// 将开始指针指向下一位置, 同时增加位置便偏移针的开始偏移
void AddBufLexeme(DouBuffer *douBuffer)
{
    douBuffer->m_lexeme++;
    AddCoordBegOffset(douBuffer->m_coord);

    if(IsLexmeAtBufEnd(douBuffer) == true)           // 如果开始指针指向了缓冲区的末尾
    {
        if(IsInSameBuffer(douBuffer) == true)
        {
            douBuffer->m_lexeme = BufferBegin(douBuffer, OTHER);
        }
        else
        {
            douBuffer->m_lexeme = BufferBegin(douBuffer, THIS);
        }
    }
    // return
}

// 将向前指针指向下一个位置, 同时增加位置指针的结束偏移
int AddBufForward(DouBuffer *douBuffer)
{

    douBuffer->m_forward++;                 // 让向前指针往前跑一个单位
    AddCoordEndOffset(douBuffer->m_coord);  // 每次向前指针进1, 则需要将位置指针偏移进1

    if(IsBufferEnd(douBuffer) == true)
    {
        //printf("%d, 文件末尾返回非零值%d\n", __LINE__, feof(douBuffer->m_fp));PAUSE( );
        //PAUSE( );
        return PutBuffer(douBuffer);
    }

    return CToolsNotEOF;
}


// 将开始指针指向下一位置, 同时增加位置便偏移针的开始偏移
void SubBufLexeme(DouBuffer *douBuffer)
{
    if(douBuffer->m_lexeme == BufferBegin(douBuffer, 0))        // 如果开始指针在当前缓冲区的开始
    {
        douBuffer->m_lexeme = BufferEnd(douBuffer, 1);
    }
    else
    {
        douBuffer->m_lexeme--;
    }

    SubCoordBegOffset(douBuffer->m_coord);
}

// 将向前指针指向下一个位置, 同时增加位置指针的结束偏移
void SubBufForward(DouBuffer *douBuffer)
{
    if(douBuffer->m_forward == BufferBegin(douBuffer, 0))        // 如果开始指针在当前缓冲区的开始
    {
        douBuffer->m_forward = BufferEnd(douBuffer, 1);
    }
    else
    {
        douBuffer->m_lexeme--;
    }

    SubCoordEndOffset(douBuffer->m_coord);

}






// 检查开始指针是不是位于缓冲区末尾
bool IsLexmeAtBufEnd(DouBuffer *douBuffer)
{
    switch((int)douBuffer->m_using)
    {
        case LEFT  :        // 如果当前正在处理缓冲区的左部分
            return (douBuffer->m_lexeme == (douBuffer->m_leftBuffer + BUFFER_SIZE)
                    || *(douBuffer->m_lexeme) == (char)EOF );     // 返回向前指针是否到达缓冲区末尾
            //break;
        case RIGHT :        // 如果当前正在处理的缓冲区右部分
            return (douBuffer->m_lexeme == (douBuffer->m_rightBuffer + BUFFER_SIZE)    // 返回向前指针是否到达缓冲区末尾
                    || *(douBuffer->m_lexeme) == (char)EOF);
        default:
            return false;
    }
    return false;
}


bool IsBufferEnd(DouBuffer *douBuffer)
{
    switch((int)douBuffer->m_using)
    {
        case LEFT  :        // 如果当前正在处理缓冲区的左部分
            return (douBuffer->m_forward == (douBuffer->m_leftBuffer + BUFFER_SIZE)
                    || *(douBuffer->m_forward) == (char)EOF );     // 返回向前指针是否到达缓冲区末尾
            //break;
        case RIGHT :        // 如果当前正在处理的缓冲区右部分
            return (douBuffer->m_forward == (douBuffer->m_rightBuffer + BUFFER_SIZE)    // 返回向前指针是否到达缓冲区末尾
                    || *(douBuffer->m_forward) == (char)EOF);
        default:
            return false;
    }
    return false;
}


// 获取当前的字符信息
char NowData(DouBuffer *douBuffer)
{
    return *(douBuffer->m_forward);
}

// 获取下一个字符的信息
char NextData(DouBuffer *douBuffer)
{
    return *(douBuffer->m_forward + 1);
}



// 判断当前两个指针是否在同一个缓冲区内部
bool IsInSameBuffer(DouBuffer *douBuffer)
{
    switch((int)douBuffer->m_using)
    {
    case LEFT :
        return  (douBuffer->m_lexeme >= douBuffer->m_leftBuffer
             && douBuffer->m_lexeme <= douBuffer->m_leftBuffer + BUFFER_SIZE);
    case RIGHT:
        return  (douBuffer->m_lexeme >= douBuffer->m_rightBuffer
             && douBuffer->m_lexeme <= douBuffer->m_rightBuffer + BUFFER_SIZE);
    default :
        ///Error();
        break;
    }
    return false;
}


// 返回当前左部缓冲区的末尾
char*  LeftBufferEnd(DouBuffer *douBuffer)
{
    return (douBuffer->m_leftBuffer + BUFFER_SIZE);
}

// 返回当前右部缓冲区的末尾
char* RightBufferEnd(DouBuffer *douBuffer)
{
    return (douBuffer->m_rightBuffer + BUFFER_SIZE);
}

// 返回当前缓冲区末尾
char* BufferEnd(DouBuffer *douBuffer, int choice)
{   // LEFT = -1, RIGHT = 1
    // 参数 , 表示当前使用的缓冲区的末尾
    // 参数 -1, 表示当前未使用缓冲区的末尾
    // unsing + choice
    // 0  0 左缓冲区末尾0 / 2 = 0
    // 0  1 右缓冲区末尾1 / 2 = 1
    // 1  0 右缓冲区末尾1 / 2 = 1
    // 1  1 左缓冲区末尾2 / 2 = 0
    #ifdef CTOOLS_DEBUG_DEFINE
    printf("计算缓冲区的结束\n");
    printf("正在使用%d缓冲区\n", douBuffer->m_using);
    #endif // CTOOLS_DEBUG_DEFINE

    switch(((int)douBuffer->m_using + choice) % 2)
    {
        case LEFT :
            #ifdef CTOOLS_DEBUG_DEFINE
            printf("返回左缓冲区结束%p\n", douBuffer->m_leftBuffer + BUFFER_SIZE);
            #endif // CTOOLS_DEBUG_DEFINE
            return (char *)(douBuffer->m_leftBuffer + BUFFER_SIZE);     // LeftBufferEnd(douBuffer);
            //break;

        case RIGHT:
            #ifdef CTOOLS_DEBUG_DEFINE
            printf("返回右缓冲区结束%p\n", douBuffer->m_rightBuffer + BUFFER_SIZE);
            #endif // CTOOLS_DEBUG_DEFINE
            return (char *)(douBuffer->m_rightBuffer + BUFFER_SIZE);    // RightBufferEnd(douBuffer);
            //break;
        default:
            return (char *)NULL;
            break;
    }
    return NULL;
}


/// 缓冲区的开始位置
char* BufferBegin(DouBuffer *douBuffer, int choice)
{   // LEFT = 0, RIGHT = 1
    // 参数 0, 表示当前使用的缓冲区的开始
    // 参数 1, 表示当前未使用缓冲区的开始
    // unsing + choice
    //0 0 左缓冲区开始0 % 2 = 0
    //0 1 右缓冲区开始1 % 2 = 1
    //1 0 右缓冲区开始1 % 2 = 1
    //1 1 左缓冲区开始2 % 2 = 0
    #ifdef CTOOLS_DEBUG_DEFINE
    printf("计算缓冲区的开始\n");
    printf("正在使用%d缓冲区\n", douBuffer->m_using);
    #endif // CTOOLS_DEBUG_DEFINE
    switch(((int)douBuffer->m_using + choice) % 2)
    {
        case LEFT :         // 0
            #ifdef CTOOLS_DEBUG_DEFINE
            printf("返回左缓冲区开始%p\n", douBuffer->m_leftBuffer);
            #endif // CTOOLS_DEBUG_DEFINE
            return (char *)(douBuffer->m_leftBuffer);
            //break;
        case RIGHT:         // 1
            #ifdef CTOOLS_DEBUG_DEFINE
            printf("返回右缓冲区开始%p\n", douBuffer->m_rightBuffer);
            #endif // CTOOLS_DEBUG_DEFINE

            return (char *)(douBuffer->m_rightBuffer);
            //break;
        default:
            return (char *)NULL;
    }

    return NULL;
}

/// 将开始指针调整至向前指针的位置
void CheckLexemeToForward(DouBuffer *douBuffer)
{

//    if(IsInSameBuffer(douBuffer) != true)      // 如果当前两个指针不在同一区域
//    {
//        printf("调整前使用%d缓冲区\n", douBuffer->m_using);
//        // LEFT 0, RIGHT 1
//        int using = douBuffer->m_using;
//        douBuffer->m_using  = (using == 1) ? 0 : 1;           // 调整使用区域
//        //#ifdef CTOOLS_DEBUG_DEFINE
//        printf("调整使用区域为%d\n", douBuffer->m_using);
//        //#ifdef CTOOLS_STEPS_DEFINE
//        PAUSE( );
//        //#endif      // CTOOLS_STEPS_DEFINE
//        //#endif      // CTOOLS_DEBUG_DEFINE
//        printf("调整前，开始指针%p，向前指针%p\n", douBuffer->m_lexeme, douBuffer->m_forward);
//    }

    douBuffer->m_lexeme = douBuffer->m_forward;
    CheckBegOffsetToEndOffset(douBuffer->m_coord);

    #ifdef CTOOLS_DEBUG_DEFINE
    printf("调整后，开始指针%p，向前指针%p\n", douBuffer->m_lexeme, douBuffer->m_forward);
    printf("两个指针复位\n");
    #endif
}



bool IsBufSpace(DouBuffer *douBuffer)
{
    return (*(douBuffer->m_forward) == ' '
        || *(douBuffer->m_forward) == '\t'
        || *(douBuffer->m_forward) == '\r'
        || *(douBuffer->m_forward) == '\n');
}

/// 进行预编译处理时,跳过空白字符的信息-=>空格制表符号
void DisBufSpace(DouBuffer *douBuffer)
{
#ifdef CTOOLS_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(IsBufSpace(douBuffer) == true);
#endif // CTOOLS_DEBUG_DEFINE

    while(IsBufSpace(douBuffer) == true)     // 由于预编译指令后面可以跟上任意的空白字符
    {
        if(*(douBuffer->m_forward) == '\n')
        {
            douBuffer->m_coord->m_fileLine++;       // 文件行数增加1

            #ifdef LEXICAL_DEBUG_DEFINE
            FILE_FUNC_LINE( );
            printf("增加一行后LINE = %d\n", douBuffer->m_coord->m_fileLine);
            #ifdef CTOOLS_STEPS_DEFINE
            PAUSE( );
            #endif      // CTOOLS_STEPS_DEFINE
            #endif
        }
        AddBufForward(douBuffer);      // 持续让向前指针增加

        #ifdef CTOOLS_DEBUG_EFINE
        printf("跳过了空白字符\n");
        #endif // CTOOLS_DEBUG_EFINE


    }
    CheckLexemeToForward(douBuffer);        // 定位开始指针到当前循环找的位置
}




/// 处理控制字符
void DisBufControl(DouBuffer *douBuffer)
{
#ifdef CTOOLS_DEBUG_DEFINE
FILE_FUNC_LINE( );
assert(iscntrl(*(douBuffer->m_forward)) != 0);
#endif // CTOOLS_DEBUG_DEFINE
    // 输出分隔符，空格、换行符、制表符除外

    /// 如果下一个字符还是空格、换行、制表符、或者不可打印字符
    while(iscntrl(*(douBuffer->m_forward)) != 0)
    {
        if(*(douBuffer->m_forward) == '\n')
        {
            douBuffer->m_coord->m_fileLine++;       // 文件行数增加1

            #ifdef LEXICAL_DEBUG_DEFINE
            FILE_FUNC_LINE( );
            printf("增加一行后LINE = %d\n", douBuffer->m_coord->m_fileLine);
            #ifdef CTOOLS_STEPS_DEFINE
            PAUSE( );
            #endif      // CTOOLS_STEPS_DEFINE
            #endif      // LEXICAL_DEBUG_DEFINE
        }
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1


        #ifdef LEXICAL_DEBUG_DEFINE
        printf("跳过控制字符%c = %d\n", *(douBuffer->m_forward), *(douBuffer->m_forward));
        #endif  // LEXICAL_DEBUG_DEFINE
    }
}


void DisBufCurrLine(DouBuffer *douBuffer)
{
#ifdef CTOOLS_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // CTOOLS_DEBUG_DEFINE
    while (*(douBuffer->m_forward) != '\n')  //直到这一行结束为止
    {
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }

    if(*(douBuffer->m_forward) == '\n')
    {
        #ifdef LEXICAL_DEBUG_DEFINE
        FILE_FUNC_LINE( );
        printf("增加了一行\n");
        #ifdef CTOOLS_STEPS_DEFINE
        PAUSE( );
        #endif      // CTOOLS_STEPS_DEFINE
        #endif // LEXICAL_DEBUG_DEFINE
        douBuffer->m_coord->m_fileLine++;                // 增加了一行
    }
}



void DisBufCommentLine(DouBuffer *douBuffer)
{
#ifdef CTOOLS_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif // CTOOLS_DEBUG_DEFINE
    while (!(*(douBuffer->m_forward - 1) == '*' && *(douBuffer->m_forward) == '/') )   //直到遇见*/为止
    {
        if(*(douBuffer->m_forward) == '\n')     // 到了改行的结束需要将文件的行号进1
        {
            #ifdef LEXICAL_DEBUG_DEFINE
            FILE_FUNC_LINE( );
            printf("增加了一行\n");
            #ifdef CTOOLS_STEPS_DEFINE
            PAUSE( );
            #endif  //CTOOLS_STEPS_DEFINE
            #endif // LEXICAL_DEBUG_DEFINE
            douBuffer->m_coord->m_fileLine++;                // 增加了一行
        }
            // DisCommentLine(douBuffer);
        AddBufForward(douBuffer);
    }
}



// 跳过预编译指令信息
void DisBufProcom(DouBuffer *douBuffer)
{
#ifdef LEXICAL_DEBUG_DEFINE
FILE_FUNC_LINE( );
#endif
    /// 跳过该预编译命令的后面其他信息
    while( 1 )
    {

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("当前字符%c, 偏移%d %d\n", *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
        #endif  // LEXICAL_DEBUG_DEFINE

        #ifdef LEXICAL_DEBUG_DEFINE
        printf("%c", *(douBuffer->m_forward));
        #endif // LEXICAL_DEBUG_DEFINE

        if(*(douBuffer->m_forward) == '\n')
        {
            douBuffer->m_coord->m_fileLine++;

            #ifdef LEXICAL_DEBUG_DEFINE
            FILE_FUNC_LINE( );
            printf("增加了一行\n");
            #ifdef CTOOLS_STEPS_DEFINE
            PAUSE( );
            #endif  //CTOOLS_STEPS_DEFINE
            #endif // LEXICAL_DEBUG_DEFINE

            if(*(douBuffer->m_forward - 1) == '\\')      // 预编译指令使用了续行符
            {
                //continue;
            }
            else if(*(douBuffer->m_forward + 1) == '#')
            {
               // continue;
            }
            else
            {
                #ifdef LEXICAL_DEBUG_DEFINE
                printf("当前字符%c, 偏移%d %d\n", *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
                #endif  // LEXICAL_DEBUG_DEFINE
                break;
            }
        }
        AddBufForward(douBuffer);
        //AddCoordEndOffert(coord);           // 每向前进移进字符, 偏移就增加1
    }

    #ifdef LEXICAL_DEBUG_DEFINE
    printf("当前字符%c, 偏移%d %d\n", *(douBuffer->m_forward), douBuffer->m_coord->m_fileBegOffset, douBuffer->m_coord->m_fileEndOffset);
    #endif  // LEXICAL_DEBUG_DEFINE
}
