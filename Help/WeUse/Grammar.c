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
033    type-qualifier: 
034    	const  
035    	volatile  

    struct-or-union-specifier:
036    	struct-or-union { struct-declaration-list } 
037    	struct-or-union identifier   { struct-declaration-list } 
038    	struct-or-union identifier   
039    struct-or-union: 
040    	struct  
041    	union  

    struct-declaration-list:
042    	struct-declaration 
043    	struct-declaration-list struct-declaration 

    init-declarator-list:
044    	init-declarator 
045    	init-declarator-list , init-declarator 

    init-declarator:
046    	declarator 
047    	declarator = initializer 

    struct-declaration:
048    	specifier-qualifier-list struct-declarator-list ; 

    specifier-qualifier-list:
049    	type-specifier 
050    	type-specifier specifier-qualifier-list 
051    	type-qualifier 
052    	type-qualifier specifier-qualifier-list 

    struct-declarator-list:
053    	struct-declarator 
054    	struct-declarator-list , struct-declarator  

    struct-declarator:
055    	declarator 
056    	: constant-expression 
057    	declarator : constant-expression  

    enum-specifier:
058    	enum { enumerator-list } 
059    	enum  identifier   { enumerator-list }
060    	enum  identifier   

    enumerator-list:
061    	enumerator
062    	enumerator-list , enumerator 

    enumerator:
063    	identifier   
064    	identifier   = constant-expression 

    declarator:
065    	direct-declarator 
066    	pointer direct-declarator 

    direct-declarator:
067    	identifier   
068    	( declarator ) 
069    	direct-declarator [ ] 
070    	direct-declarator [ constant-expression ] 
071    	direct-declarator ( parameter-type-list ) 
072    	direct-declarator ( ) 
073    	direct-declarator ( identifier-list ) 

    pointer:
074    	*  
075    	* type-qualifier-list 
076    	* pointer 
077    	* type-qualifier-list pointer 

    type-qualifier-list:
078    	type-qualifier
079    	type-qualifier-list type-qualifier 

    parameter-type-list:
080    	parameter-list 
081    	parameter-list , ... 

    parameter-list:
082    	parameter-declaration
083    	parameter-list , parameter-declaration 

    parameter-declaration:
084    	declaration-specifiers declarator 
085    	declaration-specifiers 
086    	declaration-specifiers abstract-declarator 

    identifier-list:
087    	identifier    
088    	identifier-list , identifier     

    initializer:
089    	assignment-expression 
090    	{ initializer-list } 
091    	{ initializer-list , }  

    initializer-list:
092    	initializer 
093    	initializer-list , initializer  

    type-name:
094    	specifier-qualifier-list  
095    	specifier-qualifier-list abstract-declarator  

    abstract-declarator:
096    	pointer 
097    	direct-abstract-declarator 
098    	pointer direct-abstract-declarator 

    direct-abstract-declarator:
099    	( abstract-declarator ) 
100    	[ ] 
101    	[ constant-expression ] 
102    	direct-abstract-declarator [  ] 
103    	direct-abstract-declarator [ constant-expression ] 
104    	( )
105    	( parameter-type-list ) 
106    	direct-abstract-declarator ( ) 
107    	direct-abstract-declarator ( parameter-type-list )  

    typedef-name:
108    	identifier    

    statement:
109    	labeled-statement 
110    	expression-statement 
111    	compound-statement 
112    	selection-statement 
113    	iteration-statement 
114    	jump-statement  

    labeled-statement:
115    	identifier    : statement
116    	case  constant-expression : statement 
117    	default  : statement 

    expression-statement:
118    	; 
119    	expression ; 

    compound-statement:
120    	{ } 
121    	{ statement-list } 
122    	{ declaration-list } 
123    	{ declaration-list statement-list } 

    statement-list:
124    	statement 
125    	statement-list statement  
126    selection-statement: 
127    	if  ( expression ) statement 
128    	if  ( expression ) statement else  statement 
129    	switch  ( expression ) statement 

    iteration-statement:
130    	while  ( expression ) statement 
131    	do  statement while  ( expression ) ;
132    	for  ( ; ; )  statement 
133    	for  ( ; ; expression )  statement 
134    	for  ( ; expression ; )  statement 
135    	for  ( ; expression ; expression )  statement 
136   	for  ( expression ; ; )  statement 
137    	for  ( expression ; ; expression )  statement 
138    	for  ( expression ; expression ; )  statement 
139    	for  ( expression ; expression ; expression )  statement 

    jump-statement:
140    	goto  identifier    ; 
141    	continue  ; 
142    	break  ; 
142    	return  ; 
144    	return  expression ; 

    expression:
145    	assignment-expression 
146    	expression , assignment-expression 

    assignment-expression:
147    	conditional-expression 
148    	unary-expression assignment-operator assignment-expression  
149    assignment-operator:  
150    	=  
151    	*=  
152    	/=  
153    	%=  
154    	+=  
155    	-=  
156    	<<= 
157    	>>= 
158    	&= 
159    	^=  
160    	|=  

    conditional-expression:
161    	logical-OR-expression 
162    	logical-OR-expression ? expression : conditional-expression  

    constant-expression:
163    	conditional-expression  

    logical-OR-expression:
164    	logical-AND-expression 
165    	logical-OR-expression || logical-AND-expression  

    logical-AND-expression:
166    	inclusive-OR-expression
167    	logical-AND-expression && inclusive-OR-expression  

    inclusive-OR-expression:
168    	exclusive-OR-expression 
169    	inclusive-OR-expression | exclusive-OR-expression 
170     

    exclusive-OR-expression:
171    	AND-expression 
172    	exclusive-OR-expression ^ AND-expression  

    AND-expression:
173    	equality-expression 
174    	AND-expression & equality-expression  

    equality-expression:
175    	relational-expression 
176    	equality-expression == relational-expression 
177    	equality-expression != relational-expression  

    relational-expression:
178    	shift-expression 
179    	relational-expression < shift-expression 
180    	relational-expression > shift-expression 
181    	relational-expression <= shift-expression 
182    	relational-expression >= shift-expression  

    shift-expression:
183    	additive-expression 
184    	shift-expression << additive-expression 
185    	shift-expression >> additive-expression  

    additive-expression:
186    	multiplicative-expression 
187    	additive-expression + multiplicative-expression 
188    	additive-expression - multiplicative-expression  

    multiplicative-expression:
189    	cast-expression 
190    	multiplicative-expression * cast-expression 
191    	multiplicative-expression / cast-expression 
192    	multiplicative-expression % cast-expression  

    cast-expression:
193    	unary-expression 
194    	( type-name ) cast-expression  

    unary-expression:
195    	postfix-expression 
196    	++ unary-expression 
197    	-- unary-expression 
198    	unary-operator cast-expression 
299    	sizeof  unary-expression 
200    	sizeof  ( type-name ) 
201    unary-operator: 
202    	& 
203    	* 
204    	+ 
205    	- 
206    	~ 
207    	! 

    postfix-expression:
208    	primary-expression 
209    	postfix-expression [ expression ] 
210    	postfix-expression ( ) 
211    	postfix-expression ( argument-expression-list ) 
212    	postfix-expression . identifier   
213    	postfix-expression -> identifier    
214    	postfix-expression ++ 
215    	postfix-expression -- 

    primary-expression:
216    	identifier   
217    	constant 
218    	( expression ) 

    argument-expression-list:
219    	assignment-expression 
220    	argument-expression-list , assignment-expression 

    constant:
221    	integer-constant 
222    	character-constant 
223    	floating-constant 
224    	enumeration-constant   
225    	string-constant  

    control-line:
226    	# define identifier token-sequence 
227    	# define identifier ( identifier , ... , identifier ) token-sequence 
228    	# undef identifier 
229    	# include < filename > 
230    	# include " filename " 
231    	# line constant " filename " 
232    	# line constant 
233    	# error 
234    	# error token-sequence 
235    	# pragma 
236    	# pragma token-sequence 
237    	# 
238    	preprocessor-conditional 

    preprocessor-conditional:
239    	if-line text elif-parts # endif  
240    	if-line text elif-parts else-part # endif  

    if-line:
241    	# if constant-expression 
242    	# ifdef identifier 
243    	# ifndef identifier 

    elif-parts:
244    	elif-line text 
245    	elif-parts
246    elif-line: 
247    	# elif constant-expression 

    else-part:
248    	else-line text 

    else-line:
249   	# else 
