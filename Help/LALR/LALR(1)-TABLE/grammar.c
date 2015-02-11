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
108     

    typedef-name:
109    	identifier    

    statement:
110    	labeled-statement 
111    	expression-statement 
112    	compound-statement 
113    	selection-statement 
114    	iteration-statement 
115    	jump-statement  

    labeled-statement:
116    	identifier    : statement
117    	case  constant-expression : statement 
118    	default  : statement 

    expression-statement:
119    	; 
120    	expression ; 

    compound-statement:
121    	{ } 
122    	{ statement-list } 
123    	{ declaration-list } 
124    	{ declaration-list statement-list } 

    statement-list:
125    	statement 
126    	statement-list statement  
127    selection-statement: 
128    	if  ( expression ) statement 
129    	if  ( expression ) statement else  statement 
130    	switch  ( expression ) statement 

    iteration-statement:
131    	while  ( expression ) statement 
132    	do  statement while  ( expression ) ;
133    	for  ( ; ; )  statement 
134    	for  ( ; ; expression )  statement 
135    	for  ( ; expression ; )  statement 
136    	for  ( ; expression ; expression )  statement 
137    	for  ( expression ; ; )  statement 
138    	for  ( expression ; ; expression )  statement 
139    	for  ( expression ; expression ; )  statement 
140    	for  ( expression ; expression ; expression )  statement 

    jump-statement:
141    	goto  identifier    ; 
142    	continue  ; 
143    	break  ; 
144    	return  ; 
145    	return  expression ; 

    expression:
146    	assignment-expression 
147    	expression , assignment-expression 

    assignment-expression:
148    	conditional-expression 
149    	unary-expression assignment-operator assignment-expression  
150    assignment-operator:  
151    	=  
152    	*=  
153    	/=  
154    	%=  
155    	+=  
156    	-=  
157    	<<= 
158    	>>= 
159    	&= 
160    	^=  
161    	|=  

    conditional-expression:
162    	logical-OR-expression 
163    	logical-OR-expression ? expression : conditional-expression  

    constant-expression:
164    	conditional-expression  

    logical-OR-expression:
165    	logical-AND-expression 
166    	logical-OR-expression || logical-AND-expression  

    logical-AND-expression:
167    	inclusive-OR-expression
168    	logical-AND-expression && inclusive-OR-expression  

    inclusive-OR-expression:
169    	exclusive-OR-expression 
170    	inclusive-OR-expression | exclusive-OR-expression 
171     

    exclusive-OR-expression:
172    	AND-expression 
173    	exclusive-OR-expression ^ AND-expression  

    AND-expression:
174    	equality-expression 
175    	AND-expression & equality-expression  

    equality-expression:
176    	relational-expression 
177    	equality-expression == relational-expression 
178    	equality-expression != relational-expression  

    relational-expression:
179    	shift-expression 
180    	relational-expression < shift-expression 
181    	relational-expression > shift-expression 
182    	relational-expression <= shift-expression 
183    	relational-expression >= shift-expression  

    shift-expression:
184    	additive-expression 
185    	shift-expression << additive-expression 
186    	shift-expression >> additive-expression  

    additive-expression:
187    	multiplicative-expression 
188    	additive-expression + multiplicative-expression 
189    	additive-expression - multiplicative-expression  

    multiplicative-expression:
190    	cast-expression 
191    	multiplicative-expression * cast-expression 
192    	multiplicative-expression / cast-expression 
193    	multiplicative-expression % cast-expression  

    cast-expression:
194    	unary-expression 
195    	( type-name ) cast-expression  

    unary-expression:
196    	postfix-expression 
197    	++ unary-expression 
198    	-- unary-expression 
199    	unary-operator cast-expression 
200    	sizeof  unary-expression 
201    	sizeof  ( type-name ) 
202    unary-operator: 
203    	& 
204    	* 
205    	+ 
206    	- 
207    	~ 
208    	! 

    postfix-expression:
209    	primary-expression 
210    	postfix-expression [ expression ] 
211    	postfix-expression ( ) 
212    	postfix-expression ( argument-expression-list ) 
213    	postfix-expression . identifier   
214    	postfix-expression -> identifier    
215    	postfix-expression ++ 
216    	postfix-expression -- 

    primary-expression:
217    	identifier   
218    	constant 
219    	( expression ) 

    argument-expression-list:
220    	assignment-expression 
221    	argument-expression-list , assignment-expression 

    constant:
222    	integer-constant 
223    	character-constant 
224    	floating-constant 
225    	enumeration-constant   
226    	string-constant  

    control-line:
227    	# define identifier token-sequence 
228    	# define identifier ( identifier , ... , identifier ) token-sequence 
229    	# undef identifier 
230    	# include < filename > 
231    	# include " filename " 
232    	# line constant " filename " 
233    	# line constant 
234    	# error 
235    	# error token-sequence 
236    	# pragma 
237    	# pragma token-sequence 
238    	# 
239    	preprocessor-conditional 

    preprocessor-conditional:
240    	if-line text elif-parts # endif  
241    	if-line text elif-parts else-part # endif  

    if-line:
242    	# if constant-expression 
243    	# ifdef identifier 
244    	# ifndef identifier 

    elif-parts:
245    	elif-line text 
246    	elif-parts
247    elif-line: 
248    	# elif constant-expression 

    else-part:
249    	else-line text 

    else-line:
250    	# else 
