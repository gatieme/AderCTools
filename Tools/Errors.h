/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Tuple.h                                                        *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/

/*
Fatal       -=> ÖÂÃü´íÎó
Critical    -=> ÑÏÖØ´íÎó
Major       -=> Ò»°ã´íÎó
Minor       -=> Î¢Ð¡´íÎó
*/



#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED


/// Macro defined functions are defined information
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
// the function is external, it can called by the function in current and other file
#define PUBLIC  extern
// the function is static, so that it can only called by the function of the current file
#define PRIVATE static
#
#endif



/// Used to identify the error message structure coordinates
/*
*   the "Coord" structure used in Lexical, to show the position of the lexical tuple...
*   this structure used as a member of the "TupleData"  structure which defined in the file "Lexical/BinaryTuple.h"
*/
typedef struct Coord
{
	char    *m_fileName;       // the url of the file that this data in
	int     m_fileLine;        // the line of the data
    long    m_fileBegOffset;   // current lexical information relative to the starting position offset from the beginning of the file
    long    m_fileEndOffset;   // the end of the current lexical information relative to the beginning of the file position offset
}Coord;



/// Used to identify the cause of the interrupt which make the compiler break
typedef enum Stop
{
    NO_ERR      =      -1,
    ACCEP       =       0,            // 0 errors, 0 warings
    LEX_ERR     =       1,            // lexical error
    SYN_ERR     =       2,            // parse error
    ANY_ERR     =       3,            // semantic errors
    LINK_ERR    =       4,            // link error
}Stop;

/// The result after complier the source files
typedef struct CompResult
{
    Stop    m_stop;                  // the position where te complier stopped when find some error
    int     m_warnCount;             // the count of the warings
    int     m_erroCount;             // the count of the errors;
}CompResult;


/// The data structure is used to store the error or warning message
typedef struct ErrorOrWarning
{
    Coord   m_coord;              // the postion of the current error or warning
    char    *m_desc;              // the message of the current error or warning
}ErrWarn;


///The List node to storing error or warning
typedef struct ErrorOrWarningNode
{
    ErrWarn m_error;                        // Current node identification error or warning message
    struct ErrorOrWarningNode *m_next;     // the node pointer point to the next node information
}ErrWarnNode;

/// This type sed to store list structure errors or warnings
typedef ErrWarnNode* ErrWarnTable;          // The type of a list identifies of errors or warnings


/// The part to define the function
#ifdef PUBLIC_and_PRIVATE
#
#
/// initialize the position information of the lexical coord information
PUBLIC Coord*
InitCoord(
          const char *sourFile);            // the url of the source file
#define init_coord InitCoord
#
#
/// add the member "m_fileEndOffset" of the coord
PUBLIC void
AddCoordEndOffset(
                  Coord *coord);
#define add_coord_end_offset    AddCoordEndOffet
#
#
/// add the member "m_fileBegOffset" of the coord
PUBLIC void
AddCoordBegOffset(
                  Coord *coord);
#define add_coord_beg_offset    AddCoordBegOffset
#
#
/// add the member "m_fileLine" of the Coord
PUBLIC void
AddCoordFileLine(
                 Coord *coord);
#define add_coord_file_line AddCoordFileLine
#
#
/// add the member "m_fileBegOffset" of the coord
PUBLIC void
SubCoordBegOffset(
                  Coord *coord);
#define sub_coord_beg_offset    SubCoordBegOffset
#
#
/// add the member "m_fileLine" of the Coord
PUBLIC void
SubCoordEndOffset(
                 Coord *coord);
#define sub_coord_end_offset  SubCoordEndOffset
#
#
/// Destroy the head space of the coord node...
PUBLIC void
FinitCoord(
           Coord *coord);
#
#
// 显示当前位置偏移信息
PUBLIC void
ShowCoord(
          Coord *coord);
#
#
/// set the member "m_fileBegOffset" to the "m_fileEndOffset"
PUBLIC void
CheckBegOffsetToEndOffset(
                          Coord *coord);
#define check_beg_offset_to_end_offset  CheckBegOffsetToEndOffset
#
#
/// initialize the "CompResult"
PUBLIC CompResult*                          // return the pointer of the "CompResult"
InitCompResult( );                          // the function to initialize  "CompResulr"
#define init_comp_result InitCompResult
#
#
/// show the "Compresult"
PUBLIC void
ShowCompResult(
               CompResult *compResult);     // the "CompResult" you want to show or print
#define show_comp_result    ShowCompResult
#
#
/// show the message of the error the complier find
PUBLIC void
Error(
      Coord *coord,               // the position where find the error
      const char *format,        // the information of the error
      ...);                       // variable argument list point to the other error list
#define error   Error
#
#
/// show the message of the error the complier find
PUBLIC void
Warning(
        Coord *coord,           // the position where find the warning
        const char *format,    // the information of the warning
        ...);                   // variable argument list point to the other warning list
#define warning     Warning
#
#
/// insert the error information "ErrWarnNode" into the error list
PUBLIC ErrWarnNode*
InsertError(
            ErrWarnNode *pNode,     // the end pointer of the error list
            Coord *coord,           // the information of the error you want to insert
            char *format);
#
#
/// insert the warning information "ErrWarnNode"
PUBLIC ErrWarnNode*
InSertEarning( );
#
#
#endif




#endif // ERRORS_H_INCLUDED
