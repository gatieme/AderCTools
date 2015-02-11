





G':
S0 -> translation_unit
//	
translation_unit -> external_declaration
translation_unit -> translation_unit external_declaration

//	
external_declaration -> function_definition
external_declaration -> declaration

//	
declaration -> type_specifier;
declaration -> type_specifier init_declarator_list;

//	
declaration_specifiers -> type_specifier
declaration_specifiers -> type_specifier declaration_specifiers

//	类型说明
type_specifier -> VOID
type_specifier -> CHAR
type_specifier -> SHORT
type_specifier -> INT
type_specifier -> LONG
type_specifier -> FLOAT
type_specifier -> SIGNED
type_specifier -> DOUBLE
type_specifier -> UNSIGNED

// 初始化列表
init_declarator_list -> init_declarator
init_declarator_list -> init_declarator_list , init_declarator

// 变量初始化
init_declarator -> pointer direct_declarator
init_declarator -> IDENTIFIER direct_declarator

// 指针变量
pointer -> *
pointer -> * pointer

// 函数实现
function_definition -> type_specifier init_declarator decalration_list compound_statement
function_definition -> type_specifier init_declarator compound_statement
function_definition -> init_declarator decalration_list compound_statement
function_definition -> init_declarator compound_statement

// 
decalration_list -> declaration
decalration_list -> decalration_list declaration

//
compound_statement -> { }
compound_statement -> { decalration_list }
compound_statement -> { statement_list }
compound_statement -> { decalration_list statement_list }

//
statement_list -> statement
statement_list -> statement_list statement

statement -> compound_statement
statement -> expression_statement
statement -> selection_statement
statement -> iteration_statement
statement -> jump_statement

// 
expression_statement -> ;
expression_statement -> expression ;
expression -> assignment_expression
expression -> expression , assignment_expression

//
logical_or_expression -> logical_or_expression OR_OP logical_and_expression
logical_or_expression -> logical_and_expression
logical_and_expression -> logical_and_expression AND_OP equality_expression
logical_and_expression -> equality_expression

//
equality_expression -> equality_expression NE_OP relational_expression
equality_expression -> equality_expression EQ_OP relational_expression
equality_expression -> relational_expression

//
relational_expression -> relational_expression < additive_expression
relational_expression -> relational_expression > additive_expression
relational_expression -> relational_expression LE_OP additive_expression
relational_expression -> relational_expression GE_OP additive_expression
relational_expression -> additive_expression

//
additive_expression -> additive_expression - multiplicative_expression
additive_expression -> additive_expression + multiplicative_expression
additive_expression -> multiplicative_expression

//
multiplicative_expression -> multiplicative_expression * primary_expression
multiplicative_expression -> multiplicative_expression / primary_expression
multiplicative_expression -> multiplicative_expression % primary_expression
multiplicative_expression -> primary_expression

//
primary_expression -> IDENTIFIER
primary_expression -> CONSTANT
primary_expression -> STRING_LITERAL
primary_expression -> primary_expression[ expression ]
primary_expression -> ( expression )

//
selection_statement -> IF ( expression ) statement
selection_statement -> IF ( expression ) statement ELSE statement

//
iteration_statement -> WHILE ( expression ) statement
iteration_statement -> FOR ( expression_statement expression_statement ) statement
iteration_statement -> FOR ( expression_statement expression_statement expression ) statement

//
jump_statement -> CONTINUE ;
jump_statement -> BREAK ;
jump_statement -> RETURN ;
jump_statement -> RETURN expression ;

//
assignment_expression -> primary_expression=assignment_expression
assignment_expression -> logical_or_expression

//
postfix_expression -> postfix_expression [ expression ]
postfix_expression -> postfix_expression( )
postfix_expression -> primary_expression

//
direct_declarator- > direct_declarator[logical_or_expression]
direct_declarator- > direct_declarator[ ]
direct_declarator- > direct_declarator(parameter_list)
direct_declarator- > direct_declarator(identifier_list)
direct_declarator- > direct_declarator( )
direct_declarator- > i
direct_declarator- > ( init_declarator )

//
parameter_list -> parameter_list,parameter_declaration
parameter_list -> parameter_declaration

//
identifier_list -> identifier_list,i
identifier_list -> i

//
parameter_declaration -> type_specifier init_declarator
parameter_declaration -> type_specifier abstract_declarator
parameter_declaration -> type_specifier

//
abstract_declarator -> pointer
abstract_declarator -> pointer direct_abstract_declarator
abstract_declarator -> direct_abstract_declarator

//
direct_abstract_declarator -> direct_abstract_declarator( parameter_list )
direct_abstract_declarator -> direct_abstract_declarator( )
direct_abstract_declarator -> direct_abstract_declarator[logical_or_expression]
direct_abstract_declarator -> direct_abstract_declarator[]
direct_abstract_declarator -> (parameter_list)
direct_abstract_declarator -> [ logical_or_expression ]
direct_abstract_declarator -> ( )
direct_abstract_declarator -> [ ]
direct_abstract_declarator -> ( abstract_declarator )











