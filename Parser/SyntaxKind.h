#ifndef SYNTAXKIND_H_INCLUDED
#define SYNTAXKIND_H_INCLUDED




#include "Config.h"     //  #include "..\Config\Config.h"


/// 语法[文法]结点的种别码
typedef enum SyntaxKind
{
    SYN_UNKOWN                  =   -1, // 未知的状态集合
    SYN_NULL                    =   00, // 空的文法信息
    SYN_STARTER                 =    1, // 文法的开始符号

    AND_EXPRESSION              =    2, //
    ABSTRACT_DECLARATOR         =    3, //
    ADDITIVE_EXPRESSION         =    4,
    ARGUMENT_EXPRESSION_LIST    =    5,
    ASSIGNMENT_EXPRESSION       =    6,
    ASSIGNMENT_OPERATOR         =    7,
    CAST_EXPRESSION             =    8,
    COMPOUND_STATEMENT          =    9,
    CONDITIONAL_EXPRESSION      =   10,
    CONSTANT                    =   11,
    CONSTANT_EXPRESSION         =   12,
    DECLARATION                 =   13,
    DECLARATION_LIST            =   14,
    DECLARATION_SPECIFIERS      =   15,
    DECLARATOR                  =   16,
    DIRECT_ABSTRACT_DECLARATOR  =   17,
    DIRECT_DECLARATOR           =   18,
    ENUM_SPECIFIER              =   19,
    ENUMERATOR                  =   20,
    ENUMERATOR_LIST             =   21,
    ERROR                       =   22,
    EQUALITY_EXPRESSION         =   23,
    EXCLUSIVE_OR_EXPRESSION     =   24,
    EXPRESSION                  =   25,
    EXPRESSION_STATEMENT        =   26,
    EXTERNAL_DECLARATION        =   27,
    FUNCTION_DEFINITION         =   28,
    FUNCTION_SPECIFIER          =   29,
    IDENTIFIER_LIST             =   30,
    INCLUSIVE_OR_EXPRESSION     =   31,
    INIT_DECLARATOR             =   32,
    INIT_DECLARATOR_LIST        =   33,
    INITIALIZER                 =   34,
    INITIALIZER_LIST            =   35,
    ITERATION_STATEMENT         =   36,
    JUMP_STATEMENT              =   37,
    LABELED_STATEMENT           =   38,
    LOGICAL_AND_EXPRESSION      =   39,
    LOGICAL_OR_EXPRESSION       =   40,
    MULTIPLICATIVE_EXPRESSION   =   41,
    PARAMETER_DECLARATION       =   42,
    PARAMETER_LIST              =   43,
    PARAMETER_TYPE_LIST         =   44,
    POINTER                     =   45,
    POSTFIX_EXPRESSION          =   46,
    PRIMARY_EXPRESSION          =   47,
    RELATIONAL_EXPRESSION       =   48,
    SELECTION_STATEMENT         =   49,
    SHIFT_EXPRESSION            =   50,
    SPECIFIER_QUALIFIER_LIST    =   51,
    STATEMENT                   =   52,
    STATEMENT_LIST              =   53,
    STORAGE_CLASS_SPECIFIER     =   54,
    STRUCT_DECLARATION          =   55,
    STRUCT_DECLARATION_LIST     =   56,
    STRUCT_DECLARATOR           =   57,
    STRUCT_DECLARATOR_LIST      =   58,
    STRUCT_OR_UNION             =   59,
    STRUCT_OR_UNION_SPECIFIER   =   60,
    TOKEN_SEQUENCE              =   61,
    TRANSLATION_UNIT            =   62,
    TYPE_NAME                   =   63,
    TYPE_QUALIFIER              =   64,
    TYPE_QUALIFIER_LIST         =   65,
    TYPE_SPECIFIER              =   66,
    TYPEDEF_NAME                =   67,
    UNARY_EXPRESSION            =   68,
    UNARY_OPERATOR              =   69,


    CONTROL_LINE                =   70, //
    DEFINE                      =   71, // #define
    ENDIF                       =   72, // #endif
    ELIF                        =   73, //
    ELIF_LINE                   =   74, //
    ELIF_PARTS                  =   75, //
    ELSE_PART                   =   76, //
    ELSE_LINE                   =   77, //
    FILENAME                    =   78, //
    IFDEF                       =   79, // #ifdef
    IFNDEF                      =   80, // #ifndef
    IF_LINE                     =   81, // #if
    INCLUDE                     =   82, // #include
    LINE                        =   83, // #line
    PRAGMA                      =   84, //
    PREPROCESSOR_CONDITIONAL    =   85, //
    TEXT                        =   86, //
    UNDEF                       =   87, // #undef

}SyntaxKind;

#endif // SYNTAXKIND_H_INCLUDED
