*****************************************************************************
*							本程序所使用的C文法集合							*
*****************************************************************************


    translation-unit:
001    	external-declaration 
002    	translation-unit external-declaration 

    external-declaration:
003    	function-definition 
004    	declaration 

    function-definition:
005    	declarator compound-statement 
006    	declarator declaration-list compound-statement 
007    	declaration-specifiers declarator compound-statement 
008    	declaration-specifiers declarator declaration-list compound-statement 

    declaration:
009    	declaration-specifiers ; 
010    	declaration-specifiers init-declarator-list ; 

    declaration-list:
011    	declaration 
012    	declaration-list declaration 

    declaration-specifiers:
013    	storage-class-specifier 
014    	storage-class-specifier declaration-specifiers 
015    	type-specifier 
016    	type-specifier declaration-specifiers 
017    	type-qualifier 
018    	type-qualifier declaration-specifiers 

    storage-class-specifier:
019    	auto
020    	register 
021    	static 
022    	extern 
023    	typedef 

    type-specifier:
024    	void  
025    	char 
026    	short  
027    	int  
028    	long  
029    	float  
030    	double  
031    	signed 
032    	unsigned  struct-or-union-specifier enum-specifier typedef-name 

   type-qualifier: 
033    	const  
034    	volatile  

    struct-or-union-specifier:
035    	struct-or-union { struct-declaration-list } 
036    	struct-or-union identifier   { struct-declaration-list } 
037    	struct-or-union identifier   

   
   struct-or-union: 
038    	struct  
039    	union  

    struct-declaration-list:
040    	struct-declaration 
041    	struct-declaration-list struct-declaration 

    init-declarator-list:
042    	init-declarator 
043    	init-declarator-list , init-declarator 

    init-declarator:
044    	declarator 
045    	declarator = initializer 

    struct-declaration:
046    	specifier-qualifier-list struct-declarator-list ; 

    specifier-qualifier-list:
047    	type-specifier 
048    	type-specifier specifier-qualifier-list 
049    	type-qualifier 
050    	type-qualifier specifier-qualifier-list 

    struct-declarator-list:
051    	struct-declarator 
052    	struct-declarator-list , struct-declarator  

    struct-declarator:
053    	declarator 
054    	: constant-expression 
055    	declarator : constant-expression  

    enum-specifier:
056    	enum { enumerator-list } 
057    	enum  identifier   { enumerator-list }
058    	enum  identifier   

    enumerator-list:
059    	enumerator
060    	enumerator-list , enumerator 

    enumerator:
061    	identifier   
062    	identifier   = constant-expression 

    declarator:
063    	direct-declarator 
064    	pointer direct-declarator 

    direct-declarator:
065    	identifier   
066    	( declarator ) 
067    	direct-declarator [ ] 
068    	direct-declarator [ constant-expression ] 
069    	direct-declarator ( parameter-type-list ) 
070    	direct-declarator ( ) 
071    	direct-declarator ( identifier-list ) 

    pointer:
072    	*  
073    	* type-qualifier-list 
074    	* pointer 
075    	* type-qualifier-list pointer 

    type-qualifier-list:
076    	type-qualifier
077    	type-qualifier-list type-qualifier 

    parameter-type-list:
078    	parameter-list 
079    	parameter-list , ... 

    parameter-list:
080    	parameter-declaration
081    	parameter-list , parameter-declaration 

    parameter-declaration:
082    	declaration-specifiers declarator 
083    	declaration-specifiers 
084    	declaration-specifiers abstract-declarator 

    identifier-list:
085    	identifier    
086    	identifier-list , identifier     

    initializer:
087    	assignment-expression 
088    	{ initializer-list } 
089    	{ initializer-list , }  

    initializer-list:
090    	initializer 
091    	initializer-list , initializer  

    type-name:
092    	specifier-qualifier-list  
093    	specifier-qualifier-list abstract-declarator  

    abstract-declarator:
094    	pointer 
095    	direct-abstract-declarator 
096    	pointer direct-abstract-declarator 

    direct-abstract-declarator:
097    	( abstract-declarator ) 
098    	[ ] 
099    	[ constant-expression ] 
100    	direct-abstract-declarator [  ] 
101    	direct-abstract-declarator [ constant-expression ] 
102   	( )
103    	( parameter-type-list ) 
104    	direct-abstract-declarator ( ) 
105    	direct-abstract-declarator ( parameter-type-list ) 
     

    typedef-name:
106    	identifier    

    statement:
107    	labeled-statement 
108    	expression-statement 
109    	compound-statement 
110    	selection-statement 
111    	iteration-statement 
112    	jump-statement  

    labeled-statement:
113    	identifier    : statement
114    	case  constant-expression : statement 
115    	default  : statement 

    expression-statement:
116    	; 
117    	expression ; 

    compound-statement:
118    	{ } 
119    	{ statement-list } 
120    	{ declaration-list } 
121    	{ declaration-list statement-list } 

    statement-list:
122    	statement 
123    	statement-list statement  

// 124以后的每个减少1   
   selection-statement: //124
124    	if  ( expression ) statement 
125    	if  ( expression ) statement else  statement 
126    	switch  ( expression ) statement 

    iteration-statement:
127		while  ( expression ) statement 
128    	do  statement while  ( expression ) ;
129    	for  ( ; ; )  statement 
130    	for  ( ; ; expression )  statement 
131    	for  ( ; expression ; )  statement 
132    	for  ( ; expression ; expression )  statement 
133    	for  ( expression ; ; )  statement 
134    	for  ( expression ; ; expression )  statement 
135    	for  ( expression ; expression ; )  statement 
136    	for  ( expression ; expression ; expression )  statement 

    jump-statement:
137    	goto  identifier    ; 
138    	continue  ; 
139    	break  ; 
140    	return  ; 
141    	return  expression ; 

    expression:
142    	assignment-expression 
143    	expression , assignment-expression 

    assignment-expression:
144    	conditional-expression 
145    	unary-expression assignment-operator assignment-expression

	assignment-operator:  
146    	=  
147    	*=  
148    	/=  
149    	%=  
150    	+=  
151    	-=  
152    	<<= 
153    	>>= 
154    	&= 
155    	^=  
156    	|=  

    conditional-expression:
157    	logical-OR-expression 
158    	logical-OR-expression ? expression : conditional-expression  

    constant-expression:
159    	conditional-expression  

    logical-OR-expression:
160    	logical-AND-expression 
161    	logical-OR-expression || logical-AND-expression  

    logical-AND-expression:
162    	inclusive-OR-expression
163    	logical-AND-expression && inclusive-OR-expression  

    inclusive-OR-expression:
164    	exclusive-OR-expression 
165    	inclusive-OR-expression | exclusive-OR-expression 
     

    exclusive-OR-expression:
166    	AND-expression 
167    	exclusive-OR-expression ^ AND-expression  

    AND-expression:
168    	equality-expression 
169    	AND-expression & equality-expression  

    equality-expression:
170    	relational-expression 
171    	equality-expression == relational-expression 
172    	equality-expression != relational-expression  

    relational-expression:
173    	shift-expression 
174    	relational-expression < shift-expression 
175    	relational-expression > shift-expression 
176    	relational-expression <= shift-expression 
177    	relational-expression >= shift-expression  

    shift-expression:
178    	additive-expression 
179    	shift-expression << additive-expression 
180    	shift-expression >> additive-expression  

    additive-expression:
181    	multiplicative-expression 
182    	additive-expression + multiplicative-expression 
183    	additive-expression - multiplicative-expression  

   multiplicative-expression:
184    	cast-expression 
185    	multiplicative-expression * cast-expression 
186    	multiplicative-expression / cast-expression 
187    	multiplicative-expression % cast-expression  

    cast-expression:
188    	unary-expression 
189   	( type-name ) cast-expression  

    unary-expression:
190    	postfix-expression 
191    	++ unary-expression 
192    	-- unary-expression 
193    	unary-operator cast-expression 
194    	sizeof  unary-expression 
195    	sizeof  ( type-name ) 
  
  unary-operator: 
196    	& 
197    	* 
198    	+ 
199    	- 
200    	~ 
201    	! 

    postfix-expression:
202    	primary-expression 
203    	postfix-expression [ expression ] 
204    	postfix-expression ( ) 
205    	postfix-expression ( argument-expression-list ) 
206    	postfix-expression . identifier   
207    	postfix-expression -> identifier    
208    	postfix-expression ++ 
209    	postfix-expression -- 

    primary-expression:
210    	identifier   
211    	constant 
212    	( expression ) 

    argument-expression-list:
213    	assignment-expression 
214    	argument-expression-list , assignment-expression 

    constant:
215    	integer-constant 
216    	character-constant 
217    	floating-constant 
218    	enumeration-constant   
219    	string-constant  

    control-line:
220    	# define identifier token-sequence 
221    	# define identifier ( identifier , ... , identifier ) token-sequence 
222    	# undef identifier 
223    	# include < filename > 
224    	# include " filename " 
225    	# line constant " filename " 
226    	# line constant 
227    	# error 
228		# error token-sequence 
229    	# pragma 
230    	# pragma token-sequence 
231    	# 
232    	preprocessor-conditional 

    preprocessor-conditional:
233    	if-line text elif-parts # endif  
234    	if-line text elif-parts else-part # endif  

    if-line:
235    	# if constant-expression 
236    	# ifdef identifier 
237    	# ifndef identifier 

    elif-parts:
238    	elif-line text 
239    	elif-parts
240    elif-line: 
241    	# elif constant-expression 

    else-part:
242    	else-line text 

    else-line:
243    	# else 
