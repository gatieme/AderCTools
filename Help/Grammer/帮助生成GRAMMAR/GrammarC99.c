translation-unit:
	external-declaration 
	translation-unit external-declaration 

external-declaration:
	function-definition 
	declaration 

function-definition:
	declarator compound-statement 
	declarator declaration-list compound-statement 
	declaration-specifiers declarator compound-statement 
	declaration-specifiers declarator declaration-list compound-statement 

declaration:
	declaration-specifiers ; 
	declaration-specifiers init-declarator-list ; 

declaration-list:
	declaration 
	declaration-list declaration 

	declaration-specifiers:
	storage-class-specifier 
	storage-class-specifier declaration-specifiers 
	type-specifier 
	type-specifier declaration-specifiers 
	type-qualifier 
	type-qualifier declaration-specifiers
	function-specifier	
	function-specifier declaration-specifiers	

function-specifier:
	inline

storage-class-specifier:
	auto
	register 
	static 
	extern 
	typedef 

type-specifier:
	void  
	char 
	short  
	int  
	long  
	float  
	double  
	signed 
	unsigned
	bool	
	_Bool	
	_Complex	
	_Imaginary	
	struct-or-union-specifier	
	enum-specifier
	typedef-name 

type-qualifier: 
	const  
	restrict
	volatile  

struct-or-union-specifier:
	struct-or-union { struct-declaration-list } 
	struct-or-union identifier   { struct-declaration-list } 
	struct-or-union identifier   

struct-or-union: 
	struct  
	union  

struct-declaration-list:
	struct-declaration 
	struct-declaration-list struct-declaration 

init-declarator-list:
	init-declarator 
	init-declarator-list , init-declarator 

init-declarator:
	declarator 
	declarator = initializer 

struct-declaration:
	specifier-qualifier-list struct-declarator-list ; 

specifier-qualifier-list:
	type-specifier 
	type-specifier specifier-qualifier-list 
	type-qualifier 
	type-qualifier specifier-qualifier-list 

struct-declarator-list:
	struct-declarator 
	struct-declarator-list , struct-declarator  

struct-declarator:
	declarator 
	: constant-expression 
	declarator : constant-expression  

enum-specifier:
	enum { enumerator-list } 
	enum  identifier   { enumerator-list }
	enum  identifier   

enumerator-list:
	enumerator
	enumerator-list , enumerator 

enumerator:
	identifier   
	identifier   = constant-expression 

declarator:
	direct-declarator 
	pointer direct-declarator 

direct-declarator:
	identifier   
	( declarator ) 
	direct-declarator [ ] 
	direct-declarator [ constant-expression ] 
	direct-declarator ( parameter-type-list ) 
	direct-declarator ( ) 
	direct-declarator ( identifier-list ) 

pointer:
	*  
	* type-qualifier-list 
	* pointer 
	* type-qualifier-list pointer 

type-qualifier-list:
	type-qualifier
	type-qualifier-list type-qualifier 

parameter-type-list:
	parameter-list 
	parameter-list , ... 

parameter-list:
	parameter-declaration
	parameter-list , parameter-declaration 

parameter-declaration:
	declaration-specifiers declarator 
	declaration-specifiers 
	declaration-specifiers abstract-declarator 

identifier-list:
	identifier    
	identifier-list , identifier     

initializer:
	assignment-expression 
	{ initializer-list } 
	{ initializer-list , }  

initializer-list:
	initializer 
	initializer-list , initializer  

type-name:
	specifier-qualifier-list  
	specifier-qualifier-list abstract-declarator  

abstract-declarator:
	pointer 
	direct-abstract-declarator 
	pointer direct-abstract-declarator 

direct-abstract-declarator:
	( abstract-declarator ) 
	[ ] 
	[ constant-expression ] 
	direct-abstract-declarator [  ] 
	direct-abstract-declarator [ constant-expression ] 
	( )
	( parameter-type-list ) 
	direct-abstract-declarator ( ) 
	direct-abstract-declarator ( parameter-type-list ) 
 
typedef-name:
	identifier    

statement:
	labeled-statement 
	expression-statement 
	compound-statement 
	selection-statement 
	iteration-statement 
	jump-statement  

labeled-statement:
	identifier    : statement
	case  constant-expression : statement 
	default  : statement 

expression-statement:
	; 
	expression ; 

compound-statement:
	{ } 
	{ statement-list } 
	{ declaration-list } 
	{ declaration-list statement-list } 

statement-list:
	statement 
	statement-list statement  

selection-statement: 
	if  ( expression ) statement 
	if  ( expression ) statement else  statement 
	switch  ( expression ) statement 

iteration-statement:
	while  ( expression ) statement 
	do  statement while  ( expression ) ;
	for  ( ; ; )  statement 
	for  ( ; ; expression )  statement 
	for  ( ; expression ; )  statement 
	for  ( ; expression ; expression )  statement 
	for  ( expression ; ; )  statement 
	for  ( expression ; ; expression )  statement 
	for  ( expression ; expression ; )  statement 
	for  ( expression ; expression ; expression )  statement 


jump-statement:
	goto  identifier    ; 
	continue  ; 
	break  ; 
	return  ; 
	return  expression ; 

expression:
	assignment-expression 
	expression , assignment-expression 

assignment-expression:
	conditional-expression 
	unary-expression assignment-operator assignment-expression  

assignment-operator:  
	=  
	*=  
	/=  
	%=  
	+=  
	-=  
	<<= 
	>>= 
	&= 
	^=  
	|=  

conditional-expression:
	logical-OR-expression 
	logical-OR-expression ? expression : conditional-expression  

constant-expression:
	conditional-expression  

logical-OR-expression:
	logical-AND-expression 
	logical-OR-expression || logical-AND-expression  

logical-AND-expression:
	inclusive-OR-expression
	logical-AND-expression && inclusive-OR-expression  

inclusive-OR-expression:
	exclusive-OR-expression 
	inclusive-OR-expression | exclusive-OR-expression 
 
exclusive-OR-expression:
	AND-expression 
	exclusive-OR-expression ^ AND-expression  

AND-expression:
	equality-expression 
	AND-expression & equality-expression  

equality-expression:
	relational-expression 
	equality-expression == relational-expression 
	equality-expression != relational-expression  

relational-expression:
	shift-expression 
	relational-expression < shift-expression 
	relational-expression > shift-expression 
	relational-expression <= shift-expression 
	relational-expression >= shift-expression  

shift-expression:
	additive-expression 
	shift-expression << additive-expression 
	shift-expression >> additive-expression  

additive-expression:
	multiplicative-expression 
	additive-expression + multiplicative-expression 
	additive-expression - multiplicative-expression  

multiplicative-expression:
	cast-expression 
	multiplicative-expression * cast-expression 
	multiplicative-expression / cast-expression 
	multiplicative-expression % cast-expression  

cast-expression:
	unary-expression 
	( type-name ) cast-expression  

unary-expression:
	postfix-expression 
	++ unary-expression 
	-- unary-expression 
	unary-operator cast-expression 
	sizeof  unary-expression 
	sizeof  ( type-name ) 

unary-operator: 
	& 
	* 
	+ 
	- 
	~ 
	! 

postfix-expression:
	primary-expression 
	postfix-expression [ expression ] 
	postfix-expression ( ) 
	postfix-expression ( argument-expression-list ) 
	postfix-expression . identifier   
	postfix-expression -> identifier    
	postfix-expression ++ 
	postfix-expression -- 
	( type-name ) { initializer-list }	
	( type-name ) { initializer-list , }	


primary-expression:
	identifier   
	constant 
	( expression ) 

argument-expression-list:
	assignment-expression 
	argument-expression-list , assignment-expression 

constant:
	integer-constant 
	character-constant 
	floating-constant 
	enumeration-constant   
	string-constant  

control-line:
	# define identifier token-sequence 
	# define identifier ( identifier , ... , identifier ) token-sequence 
	# undef identifier 
	# include < filename > 
	# include " filename " 
	# line constant " filename " 
	# line constant 
	# error 
	# error token-sequence 
	# pragma 
	# pragma token-sequence 
	# 
	preprocessor-conditional 

preprocessor-conditional:
	if-line text elif-parts # endif  
	if-line text elif-parts else-part # endif  

if-line:
	# if constant-expression 
	# ifdef identifier 
	# ifndef identifier 

elif-parts:
	elif-line text 
	elif-parts

elif-line: 
	# elif constant-expression 

else-part:
	else-line text 

else-line:
	# else 
