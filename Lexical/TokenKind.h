


#ifndef TOKEN_KIND_H_INCLUDED
#define TOKEN_KIND_H_INCLUDED

#include "..\Config\Config.h"         // 配置文件信息

/// 宏定义函数的定义方式信息
#ifndef PUBLIC_and_PUBLIC
#define PUBLIC_and_PUBLIC
#
#define PUBLIC  extern          // 函数可以被外界访问
#define PRIVATE static      // 函数只能被本文件的函数调用
#
#endif


#define MAX_KEYWORD_COUNT     40      // 关键字个数
#define MAX_PROCOM_COUNT      15      // 预编译指令的个数
#define MAX_OPERATE_COUNT     50      // 运算符个数
#define MAX_SEPARAROR_COUNT   20      // 分隔符个数
#define MAX_STR_SIZE_COUNT    81      // 定义最大字符缓冲区大小


#define MAX_KEYWORD_SIZE      20      // 单个关键字的串长度
#define MAX_PROCOM_SIZE       10      // 单个预编译指令的串长度
#define MAX_OPERATE_SIZE       4      // 单个运算符的串长度

#define NOT_FIND        -1       // 未找到此关键字信息



/// 标识符的信息数组
typedef enum TokenKind
{

    /*负数部分作为保留信息*/
    TOKEN_NULL                  =   -3,         // 没有值
    UNKNOW                      =   -2,         // 标识符的属性未知
    TOKEN_END                   =   -1,         // 结束的标志
    HEAD                        =   00,
    ARRAY                       =   01,
    FUNCTION                    =   02,         // 函数
    PARAMETERS                  =   03,         // 函数参数
    POINT                       =   04,         // 指针

    /// 标识符
    IDENTIFIER                  =   05,         // 标识符

    /*6 7 8 9 作为保留信息*/

    /// 关键字
    KEYWORD                     =   10,         // 关键字
    AUTO_KEYWORD                =   11,         // auto
    BOOL_KEYWORD                =   12,         // bool
    BREAK_KEYWORD               =   13,         // break
    CASE_KEYWORD                =   14,         // case
    CHAR_KEYWORD                =   15,         // char
    CONST_KEYWORD               =   16,         // const
    CONTINUE_KEYWORD            =   17,         // continue
    DEFAULT_KEYWORD             =   18,         // default
    DO_KEYWORD                  =   19,         // do
    DOUBLE_KEYWORD              =   20,         // double
    ELSE_KEYWORD                =   21,         // else
    ENUM_KEYWORD                =   22,         // enum
    EXTERN_KEYWORD              =   23,         // extern
    FLOAT_KEYWORD               =   24,         // float
    FOR_KEYWORD                 =   25,         // for
    GOTO_KEYWORD                =   26,         // goto
    IF_KEYWORD                  =   27,         // if
    INLINE_KEYWORD              =   28,         // inline
    INT_KEYWORD                 =   29,         // int
    LONG_KEYWORD                =   30,         // long
    REGISTER_KEYWORD            =   31,         // register
    RESTRICT_KEYWORD            =   32,         // restrict
    RETURN_KEYWORD              =   33,         // return
    SHORT_KEYWORD               =   34,         // short
    SIGNED_KEYWORD              =   35,         // signed
    SIZEOF_OPERATE              =   36,         // sizeof
    STATIC_KEYWORD              =   37,         // static
    STRUCT_KEYWORD              =   38,         // struct
    SWITCH_KEYWORD              =   39,         // switch
    TYPEDEF_KEYWORD             =   40,         // typedef
    UNION_KEYWORD               =   41,         // union
    UNSIGNED_KEYWORD            =   42,         // unsigned
    VOID_KEYWORD                =   43,         // void
    VOLATILE_KEYWORD            =   44,         // volatile
    WHILE_KEYWORD               =   45,         // while
    _BOOL_KEYWORD               =   46,         // _Bool
    _COMPLEX_KEYWORD            =   47,         // _Complex
    _IMAGINARY_KEYWORD          =   48,         // _Imaginary

    /// 运算符号
    OPERATE                     =   50,         // 运算符
    COMMA_OPERATE               =   51,         // ,    15-level
    ASSIGN_OPERATE              =   52,         // =    14-level
    ADD_ASSIGN_OPERATE          =   53,         // +=
    SUB_ASSIGN_OPERATE          =   54,         // -=
    MUL_ASSIGN_OPERATE          =   55,         // *=
    DIV_ASSIGN_OPERATE          =   56,         // /=                                 // /=
    MOD_ASSIGN_OPERATE          =   57,         // %=
    BITOR_ASSIGN_OPERATE        =   58,         // |=
    BITXOR_ASSIGN_OPERATE       =   59,         // ^=
    BITAND_ASSIGN_OPERATE       =   60,         // &=
    RSHIFT_ASSIGN_OPERATE       =   61,         // >>=
    LSHIFT_ASSIGN_OPERATE       =   62,         // <<=
    QUESTION_OPERATE            =   63,         // ?    13-level
    COLON_OPERATE               =   64,         // :
    OR_OPERATE                  =   65,         // ||   12-level
    AND_OPERATE                 =   66,         // &&   11-level
    BITOR_OPERATE               =   67,         // |    10-level
    BITXOR_OPERATE              =   68,         // ^    09-level
    BITAND_OPERATE              =   69,         // &    08-level
    EQUAL_OPERATE               =   70,         // ==   07-level
    UNEQUAL_OPERATE             =   71,         // !=
    GREATER_OPERATE             =   72,         // >    06-level
    GREATER_EQUAL_OPERATE       =   73,         // >=
    LESS_OPERATE                =   74,         // <
    LESS_EQUAL_OPERATE          =   75,         // <=
    RSHIFT_OPERATE              =   76,         // >>   05-level
    LSHIFT_OPERATE              =   77,         // <<
    ADD_OPERATE                 =   78,         // +    04-level
    SUB_OPERATE                 =   79,         // -
    MUL_OPERATE                 =   80,         // *    03-level
//    DMUL_OPERATE                =   81,         // **
//    TMUL_OPERATE                =   82,         // ***
//    FMUL_OPERATE                =   83,         // ****
                                                // 为其他指针定义标识预留的位置
    DIV_OPERATE                 =   81,         // /
    MOD_OPERATE                 =   82,         // %
    NOT_OPERATE                 =   83,         // !    02-level
    COMP_OPERATE                =   84,         // ~
                                                // 负号
    INC_OPERATE                 =   85,         // ++
    DEC_OPERATE                 =   86,         // --
                                                // 取地址&，取指针*，（type）类型转换，sizeof
    DOT_OPERATE                 =   87,         // .
    POINT_TO_OPERATE            =   88,         // ->
    ELLIPSE_OPERATE             =   89,         // ...

    ///  分界符
    SEPARATOR                   =   100,        // 分界符
    SPACE_SEPARATOR             =   101,        // _

    LPAREN_OPERATE              =   102,        // (
    RPAREN_OPERATE              =   103,        // )    01-level
    LBRACKET_OPERATE            =   104,        // [
    RBRACKET_OPERATE            =   105,        // ]

    LBRACE_SEPARATOR            =   106,        // {
    RBRACE_SEPARATOR            =   107,        // }
    SEMICOLON_SEPARATOR         =   108,        // ;
    POUND_SEPARATOR             =   109,        // #
    SINGLE_QUOTE_SEPARATOR      =   110,        // '
    DOUBLE_QUOTE_SEPARATOR      =   111,        // "
    BACKSLASH_SEPARATOR         =   112,        // '\'
    NEWLINE_SEPARATOR           =   113,        // \n
//    ELLIPSE_SEPARATOR           =   113,        // ...
//    EOF_SEPARATOR               =   113,        // eof[\0]


    /// 常量
    CONST                       =   120,        // 常数const
    INT_CONST                   =   121,        // 整形常量
    UINT_CONST                  =   122,        // 无符号整型常量
    LONG_CONST                  =   123,        // 长整型常量
    ULONG_CONST                 =   124,        // 无符号长整型常量
    LLONG_CONST                 =   125,        // 长长整形常量
    ULLONG_CONST                =   126,        // 无符号长整型常量
    FLOAT_CONST                 =   127,         // 浮点数常量
    DOUBLE_CONST                =   128,         // 双精度浮点数常量
    LDOUBLE_CONST               =   129,         // 长型双精度浮点数常量
    CHAR_CONST                  =   130,         // 字符常量
    WCHAR_CONST                 =   131,         // 宽字符常量信息
    STRING_CONST                =   132,         // 字符串常量
    ENUM_CONST                  =   133,         // 枚举常量


    /// 预编译指令
    PROCOM                      =   140,        // 预编译指令
    NULL_PROCOM                 =   141,        // #空预编译指令
    INCLUDE_PROCOM              =   142,        // #include
    LINE_PROCOM                 =   143,        // #line
    DEFINE_PROCOM               =   144,        // #define
    UNDEF_PROCOM                =   145,        // #undef
    IF_PROCOM                   =   146,        // #if
    ELIF_PROCOM                 =   147,        // #elif
    ELSE_PROCOM                 =   148,        // #else
    IFDEF_PROCOM                =   149,        // #ifdef
    IFNDEF_PROCOM               =   150,        // #ifndef
    ENDIF_PROCOM                =   151,        // #endif
    ERROR_PROCOM                =   152,        // #error
    PRAGMA_PROCOM               =   153,        // #pragma
    IMPORT_PROCOM               =   154,        // #import

}TokenKind;




#ifdef PUBLIC_and_PUBLIC
///是否为分隔符
PUBLIC int
IsSeparator(
            const char ch);
#define is_separator   IsSeparator
#
#
///是否为运算符号
PUBLIC int
IsOperate(
          const char ch);
#define is_operate IsOperate
#
#
///是否是运算符
PUBLIC int
IsAllOperate(
             const const char *token);
#define is_all_operate  IsAllOperate
#
#
///是否为关键字
PUBLIC int
IsKeyword(
          const char *str);
#define is_keyword IsKeyWord
#
#
///是否为常量
PUBLIC TokenKind
IsConstant(
           const char *str);
#define is_constant IsConstant
#
#
/// 是否是预编译指令
PUBLIC int
IsProCom(
         const char *token);
///// 判断当前运算符号是不是形如*********的指针类型
//PUBLIC int
//IsPoint(
//        char *token);           // 提取出来的运算符号
#define is_point IsPoint
#
#endif





#endif // KIND_H_INCLUDED
