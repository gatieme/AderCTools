/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Files.h                                                        *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/



#ifndef FILES_H
#define FILES_H

#include "..\Config\Config.h"     // Global compiler configuration file



/// macro defined functions are defined information
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
// the function is external, it can called by the function in current and other file
#define PUBLIC  extern
// the function is static, so that it can only called by the function of the current file
#define PRIVATE static
#
#endif


/// the part of the macro definition
// to support for different system environments
#if defined(__MSDOS__) || defined(_WIN32) || defined(__OS2__) || defined (__CYGWIN__)
#
#
#else  /* not DOSish */
#
#define IS_DIR_SEPARATOR(c)	((c) == '/')
#define IS_ABSOLUTE_PATH(f)	(IS_DIR_SEPARATOR((f)[0]))
#
#
#endif /* not DOSish */


/// type declaration
typedef FILE*  CToolsFILE;           // general files, all files
typedef FILE*  SOURCE;               // source files
typedef FILE*  DESTINATION;          // destination file

#define CToolsIsEOF  EOF
#define CToolsToEOF  1
#define CToolsNotEOF 0
#
#define FILE_NAME_SIZE  256


/// the following macro defines a way to open the file
#define WRITE_ONLY_BINARY "wb"      // open a binary file for output, if the file does not exist in it is created
#define WRITE_BINARY      "wb+"     // open a binary file for write and read, as "wb+"
#define READ_ONLY_BINARY  "rb"      // open a binary file for the output, if the file does exist will make an error
#define READ_BINARY       "rb+"     // open a binary file for write and read, as "rb+"
#define ADD_BINARY        "ab"      // open a binary file for the additional, if the file does exist will make an error
#
#define WRITE_ONLY_TEXT   "w"
#define WRITE_TEXT        "w+"
#define READ_ONLY_TEXT    "r"
#define READ_TEXT         "r+"
#define ADD_TEXT          "a"





#define CToolsClose  fclose                 // close file
#define ctools_close fclose
#
#define CToolsGetc  fgetc                   // gets a character from a file
#define ctolls_getc fgetc
#
#define CToolsGets  fgets                   // read characters stream from the file
#define ctools_gets fgets
#
#define CToolsPutc  fputc                   // write a character to the output
#define ctools_putc fputc
#
#define CToolsPuts  fputs                   // write the character streams to the output
#define ctolls_puts fputs
#
#define CToolsScanf fscanf                  // formatted input the datas
#define ctools_scanf fscanf
#
#define CToolsPrintf  fprintf               // formatted output the datas
#define ctools_printf fprintf
#
#define CToolsRead    fread                 // read some block datas from file
#define ctools_read   fread
#
#define CToolsWrite  fwrite                 // write some block datas from file
#define ctools_write fwirte
#
#define CToolsFseek  fseek                  // re-set the file pointer position
#define ctools_fessk fseek



/// the part to define the function
#ifdef PUBLIC_and_PRIVATE
#
#
/// the external function to open the file
PUBLIC CToolsFILE CToolsOpen(
                      const char* fileName,     // the url of the file you want to open
                      const char *openWay);     // the way to open the file
#define  ctools_open    CToolsOpen
#
#
///  open file functions after optimized
/*  Variable parameters given in the table before the program opens but does not close the file,
*   If you open this file error, it will not open before closing all files.
*/
PUBLIC CToolsFILE CToolsFineOpen(const char* fileName,      // the url of the file you want to open
                                 const char* openWay,       // the way to open the file
                                 CToolsFILE ifp,             // the file pointer point to the file
                                 ...);                       // variable parameters show the other file pointer
#define ctools_fine_open CToolsFineOpen
#
#
/// th function to close all the file
PUBLIC int
CToolsCloseAll(
               FILE* fp,          // the header file pointer
                ...);             // variable parameters show the other file pointer
#define ctools_close_all  CToolsCloseAll
#
#
/// destruction the space of the pointer
PUBLIC void
CToolsFree(
           void *point);        // the information of the pointer
#define ctools_free     CToolsFree
#
#
#endif




#endif /* FILES_H */
