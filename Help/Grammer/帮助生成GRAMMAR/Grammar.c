
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
019    	function-specifier	
020    	function-specifier declaration-specifiers	

    function-specifier:
021    	inline

    storage-class-specifier:
022    	auto
023    	register 
024    	static 
025    	extern 
026    	typedef 

    type-specifier:
027    	void  
028    	char 
029    	short  
030    	int  
031    	long  
032    	float  
033    	double  
034    	signed 
035    	unsigned
036    	bool	
037    	_Bool	
038    	_Complex	
039    	_Imaginary	
040    	struct-or-union-specifier	
041    	enum-specifier
042    	typedef-name

    type-qualifier: 
043    	const  
044    	restrict
045    	volatile  

    struct-or-union-specifier:
046    	struct-or-union { struct-declaration-list } 
047    	struct-or-union identifier   { struct-declaration-list } 
048    	struct-or-union identifier   

	struct-or-union: 
049    	struct  
050    	union  

    struct-declaration-list:
051    	struct-declaration 
052    	struct-declaration-list struct-declaration 

    init-declarator-list:
053    	init-declarator 
054    	init-declarator-list , init-declarator 

    init-declarator:
055    	declarator 
056    	declarator = initializer 

    struct-declaration:
057    	specifier-qualifier-list struct-declarator-list ; 

    specifier-qualifier-list:
058    	type-specifier 
059    	type-specifier specifier-qualifier-list 
060    	type-qualifier 
061    	type-qualifier specifier-qualifier-list 

    struct-declarator-list:
062    	struct-declarator 
063    	struct-declarator-list , struct-declarator  

    struct-declarator:
064    	declarator 
065    	: constant-expression 
066    	declarator : constant-expression  

    enum-specifier:
067    	enum { enumerator-list } 
068    	enum  identifier   { enumerator-list }
069    	enum  identifier   

    enumerator-list:
070    	enumerator
071    	enumerator-list , enumerator 

    enumerator:
072    	identifier   
073    	identifier   = constant-expression 

    declarator:
074    	direct-declarator 
075    	pointer direct-declarator 

    direct-declarator:
076    	identifier   
077    	( declarator ) 
078    	direct-declarator [ ] 
079    	direct-declarator [ constant-expression ] 
080    	direct-declarator ( parameter-type-list ) 
081    	direct-declarator ( ) 
082    	direct-declarator ( identifier-list ) 

    pointer:
083    	*  
084    	* type-qualifier-list 
085    	* pointer 
086    	* type-qualifier-list pointer 

    type-qualifier-list:
087    	type-qualifier
088    	type-qualifier-list type-qualifier 

    parameter-type-list:
089    	parameter-list 
090    	parameter-list , ... 

    parameter-list:
091    	parameter-declaration
092    	parameter-list , parameter-declaration 

    parameter-declaration:
093    	declaration-specifiers declarator 
094    	declaration-specifiers 
095    	declaration-specifiers abstract-declarator 

    identifier-list:
096    	identifier    
097    	identifier-list , identifier     

    initializer:
098    	assignment-expression 
099    	{ initializer-list } 
100    	{ initializer-list , }  

    initializer-list:
101    	initializer 
102    	initializer-list , initializer  

    type-name:
103    	specifier-qualifier-list  
104    	specifier-qualifier-list abstract-declarator  

    abstract-declarator:
105    	pointer 
106    	direct-abstract-declarator 
107    	pointer direct-abstract-declarator 

    direct-abstract-declarator:
108    	( abstract-declarator ) 
109    	[ ] 
110    	[ constant-expression ] 
111    	direct-abstract-declarator [  ] 
112    	direct-abstract-declarator [ constant-expression ] 
113    	( )
114    	( parameter-type-list ) 
115    	direct-abstract-declarator ( ) 
116    	direct-abstract-declarator ( parameter-type-list ) 
     

    typedef-name:
117    	identifier    

    statement:
118    	labeled-statement 
119    	expression-statement 
120    	compound-statement 
121    	selection-statement 
122    	iteration-statement 
123    	jump-statement  

    labeled-statement:
124    	identifier    : statement
125    	case  constant-expression : statement 
126    	default  : statement 

    expression-statement:
127    	; 
128    	expression ; 

    compound-statement:
129    	{ } 
130    	{ statement-list } 
131    	{ declaration-list } 
132    	{ declaration-list statement-list } 

    statement-list:
133    	statement 
134    	statement-list statement  

	selection-statement: 
135    	if  ( expression ) statement 
136    	if  ( expression ) statement else  statement 
137    	switch  ( expression ) statement 

    iteration-statement:
138    	while  ( expression ) statement 
139    	do  statement while  ( expression ) ;
140    	for  ( ; ; )  statement 
141    	for  ( ; ; expression )  statement 
142    	for  ( ; expression ; )  statement 
143    	for  ( ; expression ; expression )  statement 
144    	for  ( expression ; ; )  statement 
145    	for  ( expression ; ; expression )  statement 
146    	for  ( expression ; expression ; )  statement 
147    	for  ( expression ; expression ; expression )  statement 

    jump-statement:
148    	goto  identifier    ; 
149    	continue  ; 
150    	break  ; 
151    	return  ; 
152    	return  expression ; 

    expression:
153    	assignment-expression
154    	expression , assignment-expression

    assignment-expression:
155    	conditional-expression 
156    	unary-expression assignment-operator assignment-expression  

	assignment-operator:  
157    	=  
158    	*=  
159    	/=  
160    	%=  
161    	+=  
162    	-=  
163    	<<= 
164    	>>= 
165    	&= 
166    	^=  
167    	|=  

    conditional-expression:
168    	logical-OR-expression 
169    	logical-OR-expression ? expression : conditional-expression  

    constant-expression:
170    	conditional-expression  

    logical-OR-expression:
171    	logical-AND-expression 
172    	logical-OR-expression || logical-AND-expression  

    logical-AND-expression:
173    	inclusive-OR-expression
174    	logical-AND-expression && inclusive-OR-expression  

    inclusive-OR-expression:
175    	exclusive-OR-expression 
176    	inclusive-OR-expression | exclusive-OR-expression 
     

    exclusive-OR-expression:
177    	AND-expression 
178    	exclusive-OR-expression ^ AND-expression  

    AND-expression:
179    	equality-expression 
180    	AND-expression & equality-expression  

    equality-expression:
181    	relational-expression 
182    	equality-expression == relational-expression 
183    	equality-expression != relational-expression  

    relational-expression:
184    	shift-expression 
185    	relational-expression < shift-expression 
186    	relational-expression > shift-expression 
187    	relational-expression <= shift-expression 
188    	relational-expression >= shift-expression  

    shift-expression:
189    	additive-expression 
190    	shift-expression << additive-expression 
191    	shift-expression >> additive-expression  

    additive-expression:
192    	multiplicative-expression 
193    	additive-expression + multiplicative-expression 
194    	additive-expression - multiplicative-expression  

    multiplicative-expression:
195    	cast-expression 
196    	multiplicative-expression * cast-expression 
197    	multiplicative-expression / cast-expression 
198    	multiplicative-expression % cast-expression  

    cast-expression:
199    	unary-expression 
200    	( type-name ) cast-expression  

    unary-expression:
201    	postfix-expression 
202    	++ unary-expression 
203    	-- unary-expression 
204    	unary-operator cast-expression 
205    	sizeof  unary-expression 
206    	sizeof  ( type-name ) 

	unary-operator: 
207    	& 
208    	* 
209    	+ 
210    	- 
211    	~ 
212    	! 

    postfix-expression:
213    	primary-expression 
214    	postfix-expression [ expression ] 
215    	postfix-expression ( ) 
216    	postfix-expression ( argument-expression-list ) 
217    	postfix-expression . identifier   
218    	postfix-expression -> identifier    
219    	postfix-expression ++ 
220    	postfix-expression -- 
221    	( type-name ) { initializer-list }	
222    	( type-name ) { initializer-list , }	

    primary-expression:
223    	identifier   
224    	constant 
225    	( expression ) 

    argument-expression-list:
226    	assignment-expression 
227    	argument-expression-list , assignment-expression 

    constant:
228    	integer-constant 
229    	character-constant 
230    	floating-constant 
231    	enumeration-constant   
232    	string-constant  

    control-line:
233    	# define identifier token-sequence 
234    	# define identifier ( identifier , ... , identifier ) token-sequence 
235    	# undef identifier 
236    	# include < filename > 
237    	# include " filename " 
238    	# line constant " filename " 
239    	# line constant 
240    	# error 
241    	# error token-sequence 
242    	# pragma 
243    	# pragma token-sequence 
244    	# 
245    	preprocessor-conditional 

    preprocessor-conditional:
246    	if-line text elif-parts # endif  
247    	if-line text elif-parts else-part # endif  

    if-line:
248    	# if constant-expression 
249    	# ifdef identifier 
250    	# ifndef identifier 

    elif-parts:
251    	elif-line text 
252    	elif-parts

	elif-line: 
253    	# elif constant-expression 

    else-part:
254    	else-line text 

    else-line:
255    	# else 
