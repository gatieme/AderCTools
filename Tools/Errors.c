/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Errors.c                                                      *
*   Description: CTools                                              *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/




#include "Errors.h"
#include "CTools.h"    //  #include "..\Global\CTools.h"






int ErrorCount;         // 定义的全局变量编译错误的数目
int WarningCount;       // 定义的全局变量编译警告的数目


Coord* InitCoord(const char *sourFile)            // 初始化定位信息
{
    Coord *coord = malloc(sizeof(Coord));           // 开始定位信息的空间

    char *str = malloc(strlen(sourFile) + sizeof(char));
    strcpy(str, sourFile);
    coord->m_fileName = str;            // 文件域
    coord->m_fileLine = 1;              // 行号初始化为0
    coord->m_fileBegOffset = 0;         // 起始偏移信息初始化为0
    coord->m_fileEndOffset = 0;         // 结束偏移信息初始化为0
    return coord;
}


/// 增加Coord位置标识的词法结点结束偏移
void AddCoordEndOffset(Coord *coord)
{
    coord->m_fileEndOffset += sizeof(char);
}


/// 增加Coord位置标识的词法开始偏移
void AddCoordBegOffset(Coord *coord)
{
    coord->m_fileBegOffset += sizeof(char);
}

/// 增加Coord位置标识的词法开始偏移
void SubCoordBegOffset(Coord *coord)
{
    coord->m_fileBegOffset -= sizeof(char);
}

/// 增加Coord位置标识的词法结点结束偏移
void SubCoordEndOffset(Coord *coord)
{
    coord->m_fileEndOffset -= sizeof(char);
}


// 显示当前位置偏移信息
void ShowCoord(Coord *coord)
{
    SHOW_FILE_NAME(coord->m_fileName);
    printf("Line = %d  ", coord->m_fileLine);
    printf("Begi = %d ", coord->m_fileBegOffset);
    printf("Endl = %d ", coord->m_fileEndOffset);
}



/// 将词法开始位置偏移对齐到结束位置标识
void CheckBegOffsetToEndOffset(Coord *coord)
{
    coord->m_fileBegOffset = coord->m_fileEndOffset;
}

// 文件位置标识的收尾标志
void FinitCoord(Coord *coord)
{
    if(coord != NULL)
    {
        free(coord);            // 将文件位置标识的指针堆空间回收
    }
}



CompResult* InitCompResult( )                          // 初始化编译结果
{
    CompResult *compResult = malloc(sizeof(CompResult));

    compResult->m_erroCount = 0;        // 初始化无错误
    compResult->m_warnCount = 0;        // 初始化无警告
    compResult->m_stop = NO_ERR;        // 初始化终止信息为无错误返回

    return compResult;          // 返回编译结果集
}

/// 函数实现部分
void Error(Coord *coord, const char *format, ...)
{
	va_list ap;

	ErrorCount++;
	if (coord)
	{
		fprintf(stderr, "[%s, %4d]\t", coord->m_fileName, coord->m_fileLine);
	}
	fprintf(stderr, "error:");
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fprintf(stderr, "\n");
	va_end(ap);
}

void Fatal(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fprintf(stderr, "\n");
	va_end(ap);

	exit(-1);
}

void Warning(Coord *coord, const char *format, ...)
{
	va_list ap;

	WarningCount++;
	if (coord)
	{
		fprintf(stderr, "[%s,%4d]:\t", coord->m_fileName, coord->m_fileLine);
	}

	fprintf(stderr, "warning:");
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fprintf(stderr, "\n");
	va_end(ap);

	return;
}




