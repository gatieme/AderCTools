I29: I6 <- {
L -> { .} |$ af *
L -> { .K } |$ af *
L -> { .M } |$ af *
L -> { .K M } |$ af *
K -> .C |{ } ; IF st af bt gm
K -> .K C |{ } ; IF st af bt gm
M -> .N |{ } ; IF st bt gm
M -> .M N |{ } ; IF st bt gm
C -> .E ; |{ } ; IF st af bt gm
C -> .E F ; |{ } ; IF st af bt gm
N -> .L |{ } ; IF st bt gm
N -> .O |{ } ; IF st bt gm
N -> .P |{ } ; IF st bt gm
N -> .Q |{ } ; IF st bt gm
N -> .R |{ } ; IF st bt gm
E -> .G |; * IDENTIFIER
E -> .G E |; * IDENTIFIER
L -> .{ } |{ } ; IF st bt gm
L -> .{ K } |{ } ; IF st bt gm
L -> .{ M } |{ } ; IF st bt gm
L -> .{ K M } |{ } ; IF st bt gm
O -> .; |{ } ; IF st bt gm
O -> .S ; |{ } ; IF st bt gm
P -> .IF ( S ) N |{ } ; IF st bt gm
P -> .IF ( S ) N ELSE N |{ } ; IF st bt gm
Q -> .WHILE ( S ) N |{ } ; IF st bt gm
Q -> .FOR ( O O ) N |{ } ; IF st bt gm
Q -> .FOR ( O O S ) N |{ } ; IF st bt gm
R -> .CONTINUE ; |{ } ; IF st bt gm
R -> .BREAK ; |{ } ; IF st bt gm
R -> .RETURN ; |{ } ; IF st bt gm
R -> .RETURN S ; |{ } ; IF st bt gm
G -> .VOID |; * af IDENTIFIER
G -> .CHAR |; * af IDENTIFIER
G -> .SHORT |; * af IDENTIFIER
G -> .INT |; * af IDENTIFIER
G -> .LONG |; * af IDENTIFIER
G -> .FLOAT |; * af IDENTIFIER
G -> .DOUBLE |; * af IDENTIFIER
G -> .SIGNED |; * af IDENTIFIER
G -> .UNSIGNED |; * af IDENTIFIER
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



/////////////////
TRANSACTION ON I7

//////////////////////
I30: I7 <- E
E -> G E. | * IDENTIFIER ;



I31: I8 <- IDENTIFIER
I -> J IDENTIFIER. |{ af



I32: I19 -> J
J -> * J. |IDENTIFIER


I33: I21 <- K
D -> E I K .L |$ * af
K -> K .C |{ af
L -> .{ } |$ * af
L -> .{ K } |$ * af
L -> .{ M } |$ * af
L -> .{ K M } |$ * af
C -> .E ; |{ af
C -> .E F ; |{ af
E -> .G |; * IDENTIFIER
E -> .G E |; * IDENTIFIER
G -> .VOID |; * IDENTIFIER af
G -> .CHAR |; * IDENTIFIER af
G -> .SHORT |; * IDENTIFIER af
G -> .INT |; * IDENTIFIER af
G -> .LONG |; * IDENTIFIER af
G -> .FLOAT |; * IDENTIFIER af
G -> .DOUBLE |; * IDENTIFIER af
G -> .SIGNED |; * IDENTIFIER af
G -> .UNSIGNED |; * IDENTIFIER af


I34: I21 <- L
D -> E I L. |$ * af


I35: I21 <- C
K -> C. |{ af


I21 <- { INTER I29


I36: I21 <- E
C -> E .; |{ af
C -> E .F ; |{ af
F -> .I |; ,
F -> .F , I |; ,
I -> .J IDENTIFIER |; ,
I -> .IDENTIFIER |; ,
J -> .* |IDENTIFIER
J -> .* J |IDENTIFIER


I21 <- G INTER I7
I21 <- VOID INTER I10
I21 <- CHAR INTER I11
I21 <- SHORT INTER I12
I21 <- INT INTER I13
I21 <- LONG INTER I14
I21 <- FLOAT INTER I15
I21 <- DOUBLE INTER I16
I21 <- SIGNED INTER I17
I21 <- UNSIGNED INTER I18


I37: I23 <- ;
C -> E F ;. |$ * af



I38: I23 <- ,
F -> F , .I |; ,
I -> .J IDENTIFIER |; ,
I -> .IDENTIFIER |; ,
J -> .* |IDENTIFIER
J -> .* J |IDENTIFIER


I39: I24 <- IDENTIFIER
I -> J IDENTIFIER. |{ ; , af


I40: I26 <- L
D -> I K L. |$ * af


I41: I26 <- C
K -> K C. |{ af



I26 <- { INTER I29
I26 <- E INTER I36


I26 <- G INTER I7
I26 <- VOID INTER I10
I26 <- CHAR INTER I11
I26 <- SHORT INTER I12
I26 <- INT INTER I13
I26 <- LONG INTER I14
I26 <- FLOAT INTER I15
I26 <- DOUBLE INTER I16
I26 <- SIGNED INTER I17
I26 <- UNSIGNED INTER I18





I42: I29 <- }
L -> { }. |$ * af


I43: I29 <- K
L -> { K .} |$ af *
L -> { K .M } |$ af *
K -> K .C |{ } ; IF st af bt gm
M -> .N |{ } ; IF st bt gm
M -> .M N |{ } ; IF st bt gm
C -> .E ; |{ } ; IF st af bt gm
C -> .E F ; |{ } ; IF st af bt gm
N -> .L |{ } ; IF st bt gm
N -> .O |{ } ; IF st bt gm
N -> .P |{ } ; IF st bt gm
N -> .Q |{ } ; IF st bt gm
N -> .R |{ } ; IF st bt gm
E -> .G |; * IDENTIFIER
E -> .G E |; * IDENTIFIER
L -> .{ } |{ } ; IF st bt gm
L -> .{ K } |{ } ; IF st bt gm
L -> .{ M } |{ } ; IF st bt gm
L -> .{ K M } |{ } ; IF st bt gm
O -> .; |{ } ; IF st bt gm
O -> .S ; |{ } ; IF st bt gm
P -> .IF ( S ) N |{ } ; IF st bt gm
P -> .IF ( S ) N ELSE N |{ } ; IF st bt gm
Q -> .WHILE ( S ) N |{ } ; IF st bt gm
Q -> .FOR ( O O ) N |{ } ; IF st bt gm
Q -> .FOR ( O O S ) N |{ } ; IF st bt gm
R -> .CONTINUE ; |{ } ; IF st bt gm
R -> .BREAK ; |{ } ; IF st bt gm
R -> .RETURN ; |{ } ; IF st bt gm
R -> .RETURN S ; |{ } ; IF st bt gm
G -> .VOID |; * af IDENTIFIER
G -> .CHAR |; * af IDENTIFIER
G -> .SHORT |; * af IDENTIFIER
G -> .INT |; * af IDENTIFIER
G -> .LONG |; * af IDENTIFIER
G -> .FLOAT |; * af IDENTIFIER
G -> .DOUBLE |; * af IDENTIFIER
G -> .SIGNED |; * af IDENTIFIER
G -> .UNSIGNED |; * af IDENTIFIER
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I44: I29 <- M
L -> { M .} |$ * af
M -> M .N |{ } ; IF st bt gm
N -> .L |{ } ; IF st bt gm
N -> .O |{ } ; IF st bt gm
N -> .P |{ } ; IF st bt gm
N -> .Q |{ } ; IF st bt gm
N -> .R |{ } ; IF st bt gm
L -> .{ } |{ } ; IF st bt gm
L -> .{ K } |{ } ; IF st bt gm
L -> .{ M } |{ } ; IF st bt gm
L -> .{ K M } |{ } ; IF st bt gm
O -> .; |{ } ; IF st bt gm
O -> .S ; |{ } ; IF st bt gm
P -> .IF ( S ) N |{ } ; IF st bt gm
P -> .IF ( S ) N ELSE N |{ } ; IF st bt gm
Q -> .WHILE ( S ) N |{ } ; IF st bt gm
Q -> .FOR ( O O ) N |{ } ; IF st bt gm
Q -> .FOR ( O O S ) N |{ } ; IF st bt gm
R -> .CONTINUE ; |{ } ; IF st bt gm
R -> .BREAK ; |{ } ; IF st bt gm
R -> .RETURN ; |{ } ; IF st bt gm
R -> .RETURN S ; |{ } ; IF st bt gm
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %




I45: I29 <- C
K -> K C. |{ } ; IF st af bt gm



I46: I29 <- N
M -> N. |{ } ; IF st bt gm


I47: I29 <- E
C -> E .; |{ } ; IF st af bt gm
C -> E .F ; |{ } ; IF st af bt gm
F -> .I |; ,
F -> .F , I |; ,
I -> .J IDENTIFIER |; ,
I -> .IDENTIFIER |; ,
J -> .* |IDENTIFIER
J -> .* J |IDENTIFIER


I48: I29 <- L
N -> L. |{ } ; IF st bt gm

I49: I29 <- O
N -> O. |{ } ; IF st bt gm

I50: I29 <- P
N -> P. |{ } ; IF st bt gm

I51: I29 <- Q
N -> Q. |{ } ; IF st bt gm

I52: I29 <- R
N -> R. |{ } ; IF st bt gm

I29 <- G INTER I7

I53: I29 <- {
L -> { .} |{ } ; IF st bt gm
L -> { .K } |{ } ; IF st bt gm
L -> { .M } |{ } ; IF st bt gm
L -> { .K M } |{ } ; IF st bt gm
K -> .C |{ } ; IF st af bt gm
K -> .K C |{ } ; IF st af bt gm
M -> .N |{ } ; IF st bt gm
M -> .M N |{ } ; IF st bt gm
C -> .E ; |{ } ; IF st af bt gm
C -> .E F ; |{ } ; IF st af bt gm
N -> .L |{ } ; IF st bt gm
N -> .O |{ } ; IF st bt gm
N -> .P |{ } ; IF st bt gm
N -> .Q |{ } ; IF st bt gm
N -> .R |{ } ; IF st bt gm
E -> .G |; * IDENTIFIER
E -> .G E |; * IDENTIFIER
L -> .{ } |{ } ; IF st bt gm
L -> .{ K } |{ } ; IF st bt gm
L -> .{ M } |{ } ; IF st bt gm
L -> .{ K M } |{ } ; IF st bt gm
O -> .; |{ } ; IF st bt gm
O -> .S ; |{ } ; IF st bt gm
P -> .IF ( S ) N |{ } ; IF st bt gm
P -> .IF ( S ) N ELSE N |{ } ; IF st bt gm
Q -> .WHILE ( S ) N |{ } ; IF st bt gm
Q -> .FOR ( O O ) N |{ } ; IF st bt gm
Q -> .FOR ( O O S ) N |{ } ; IF st bt gm
R -> .CONTINUE ; |{ } ; IF st bt gm
R -> .BREAK ; |{ } ; IF st bt gm
R -> .RETURN ; |{ } ; IF st bt gm
R -> .RETURN S ; |{ } ; IF st bt gm
G -> .VOID |; * af IDENTIFIER
G -> .CHAR |; * af IDENTIFIER
G -> .SHORT |; * af IDENTIFIER
G -> .INT |; * af IDENTIFIER
G -> .LONG |; * af IDENTIFIER
G -> .FLOAT |; * af IDENTIFIER
G -> .DOUBLE |; * af IDENTIFIER
G -> .SIGNED |; * af IDENTIFIER
G -> .UNSIGNED |; * af IDENTIFIER
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I54: I29 <- ;
O -> ;. |{ } ; IF st bt gm


I55: I29 <- S
O -> S .; |{ } ; IF st bt gm
S -> S ., T |; ,


I56: I29 <- IF
P -> IF .( S ) N |{ } ; IF st bt gm
P -> IF .( S ) N ELSE N |{ } ; IF st bt gm


I57: I29 <- WHILE
Q -> WHILE .( S ) N |{ } ; IF st bt gm


I58: I29 <- FOR
Q -> FOR .( O O ) N |{ } ; IF st bt gm
Q -> FOR .( O O S ) N |{ } ; IF st bt gm

I59: I29 <- CONTINUE
R -> CONTINUE .; |{ } ; IF st bt gm


I60: I29 <- BREAK
R -> BREAK .; |{ } ; IF st bt gm

I61: I29 <- RETURN
R -> RETURN .; |{ } ; IF st bt gm
R -> RETURN .S ; |{ } ; IF st bt gm
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I29 <- VOID INTER I10
I29 <- CHAR INTER I11
I29 <- SHORT INTER I12
I29 <- INT INTER I13
I29 <- LONG INTER I14
I29 <- FLOAT INTER I15
I29 <- DOUBLE INTER I16
I29 <- SIGNED INTER I17
I29 <- UNSIGNED INTER I18


I62: I29 <- T
S -> T.              |; ,
T -> T .OR_OP U      |; , OR_OP

I63: I29 <- U
T -> U.              |; , OR_OP
U -> U. AND_OP V     |; , OR_OP AND_OP


I64: I29 <- V
U -> V.              |; , OR_OP AND_OP
V -> V. NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> V. EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP

I65: I29 <- W
V -> W.              |; , OR_OP AND_OP NE_OP EQ_OP
W -> W. < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> W. > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> W. LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> W. GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >


I66: I29 <- X
W -> X.              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> X. - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> X. + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -


I67: I29 <- Y
X -> Y.              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> Y. * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> Y. / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> Y. % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I68: I29 <- Z
Y -> Z.              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I69: I29 <- IDENTIFIER
Z -> IDENTIFIER.     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I70: I29 <- CONSTANT
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I71: I29 <- STRING_LITERAL
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I72: I29 <- (
Z -> ( .S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
S -> .T              |) ,
S -> .S , T          |) ,
T -> .T OR_OP U      |) , OR_OP
T -> .U              |) , OR_OP
U -> .U AND_OP V     |) , OR_OP AND_OP
U -> .V              |) , OR_OP AND_OP
V -> .V NE_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |) , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %




I73: I33 <- L
D -> E I K L. |$ * af


I33 <- C INTER I41
I33 <- { INTER I29
I33 <- E INTER I36
I33 <- G INTER I7
I33 <- VOID INTER I10
I33 <- CHAR INTER I11
I33 <- SHORT INTER I12
I33 <- INT INTER I13
I33 <- LONG INTER I14
I33 <- FLOAT INTER I15
I33 <- DOUBLE INTER I16
I33 <- SIGNED INTER I17
I33 <- UNSIGNED INTER I18




I74: I36 <- ;
C -> E ;. |{ af


I75: I36 <- F
C -> E F .; |{ af
F -> F ., I |; ,

I76: I36 <- I
F -> I. |; ,

I77: I36 <- J
I -> J .IDENTIFIER |; ,

I78: I36 <- IDENTIFIER
I -> IDENTIFIER. |; ,

I36 <- * INTER I19



I79: I38 <- I
F -> F , I. |; ,

I38 <- J INTER I77
I38 <- IDENTIFIER INTER I78
I38 <- * INTER I19




//////////////
I80: I43 <- }
L -> { K }. |$ * af


I43 <- M INTER I44
I43 <- C INTER I45
I43 <- N INTER I46
I43 <- E INTER I47
I43 <- L INTER I48
I43 <- O INTER I49
I43 <- P INTER I50
I43 <- Q INTER I51
I43 <- R INTER I52
I43 <- G INTER I7
I43 <- { INTER I53
I43 <- ; INTER I54
I43 <- S INTER I55
I43 <- IF INTER I56
I43 <- WHILE INTER I57
I43 <- FOR INTER I58
I43 <- CONTINUE INTER I59
I43 <- BREAK INTER I60
I43 <- RETURN INTER I61
I43 <- VOID INTER I10
I43 <- CHAR INTER I11
I43 <- SHORT INTER I12
I43 <- INT INTER I13
I43 <- LONG INTER I14
I43 <- FLOAT INTER I15
I43 <- DOUBLE INTER I16
I43 <- SIGNED INTER I17
I43 <- UNSIGNED INTER I18
I43 <- T INTER I62
I43 <- U INTER I63
I43 <- V INTER I64
I43 <- W INTER I65
I43 <- X INTER I66
I43 <- Y INTER I67
I43 <- Z INTER I68
I43 <- IDENTIFIER INTER I69
I43 <- CONSTANT INTER I70
I43 <- STRING_LITERAL INTER I71
I43 <- ( INTER I72



//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
I81: I44 <- }
L -> { M }. |$ * af


I82: I44 <- N
M -> M N. |{ } ; IF st bt gm
I43 <- L INTER I48
I44 <- O INTER I49
I44 <- P INTER I50
I44 <- Q INTER I51
I44 <- R INTER I52
I44 <- { INTER I53
I44 <- ; INTER I54
I44 <- S INTER I55
I44 <- IF INTER I56
I44 <- WHILE INTER I57
I44 <- FOR INTER I58
I44 <- CONTINUE INTER I59
I44 <- BREAK INTER I60
I44 <- RETURN INTER I61
I44 <- T INTER I62
I44 <- U INTER I63
I44 <- V INTER I64
I44 <- W INTER I65
I44 <- X INTER I66
I44 <- Y INTER I67
I44 <- Z INTER I68
I44 <- IDENTIFIER INTER I69
I44 <- CONSTANT INTER I70
I44 <- STRING_LITERAL INTER I71
I44 <- ( INTER I72



I83: I47 <- ;
C -> E ;. |{ } ; IF st af bt gm



I84: I47 <- F
C -> E F. ; |{ } ; IF st af bt gm
F -> F ., I |; ,

I47 <- I INTER I76
I47 <- J INTER I77
I47 <- IDENTIFIER INTER I78
I47 <- * INTER I19


I85: I53 <- }
L -> { }. |{ } ; IF st bt gm




I86: I53 <- K
L -> { K .} |{ } ; IF st bt gm
L -> { K .M } |{ } ; IF st bt gm
K -> K .C |{ } ; IF st af bt gm
M -> .N |{ } ; IF st bt gm
M -> .M N |{ } ; IF st bt gm
C -> .E ; |{ } ; IF st af bt gm
C -> .E F ; |{ } ; IF st af bt gm
N -> .L |{ } ; IF st bt gm
N -> .O |{ } ; IF st bt gm
N -> .P |{ } ; IF st bt gm
N -> .Q |{ } ; IF st bt gm
N -> .R |{ } ; IF st bt gm
E -> .G |; * IDENTIFIER
E -> .G E |; * IDENTIFIER
L -> .{ } |{ } ; IF st bt gm
L -> .{ K } |{ } ; IF st bt gm
L -> .{ M } |{ } ; IF st bt gm
L -> .{ K M } |{ } ; IF st bt gm
O -> .; |{ } ; IF st bt gm
O -> .S ; |{ } ; IF st bt gm
P -> .IF ( S ) N |{ } ; IF st bt gm
P -> .IF ( S ) N ELSE N |{ } ; IF st bt gm
Q -> .WHILE ( S ) N |{ } ; IF st bt gm
Q -> .FOR ( O O ) N |{ } ; IF st bt gm
Q -> .FOR ( O O S ) N |{ } ; IF st bt gm
R -> .CONTINUE ; |{ } ; IF st bt gm
R -> .BREAK ; |{ } ; IF st bt gm
R -> .RETURN ; |{ } ; IF st bt gm
R -> .RETURN S ; |{ } ; IF st bt gm
G -> .VOID |; * af IDENTIFIER
G -> .CHAR |; * af IDENTIFIER
G -> .SHORT |; * af IDENTIFIER
G -> .INT |; * af IDENTIFIER
G -> .LONG |; * af IDENTIFIER
G -> .FLOAT |; * af IDENTIFIER
G -> .DOUBLE |; * af IDENTIFIER
G -> .SIGNED |; * af IDENTIFIER
G -> .UNSIGNED |; * af IDENTIFIER
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %




I87: I53 <- M
L -> { M .} |{ } ; IF st bt gm
M -> M .N |{ } ; IF st bt gm
N -> .L |{ } ; IF st bt gm
N -> .O |{ } ; IF st bt gm
N -> .P |{ } ; IF st bt gm
N -> .Q |{ } ; IF st bt gm
N -> .R |{ } ; IF st bt gm
L -> .{ } |{ } ; IF st bt gm
L -> .{ K } |{ } ; IF st bt gm
L -> .{ M } |{ } ; IF st bt gm
L -> .{ K M } |{ } ; IF st bt gm
O -> .; |{ } ; IF st bt gm
O -> .S ; |{ } ; IF st bt gm
P -> .IF ( S ) N |{ } ; IF st bt gm
P -> .IF ( S ) N ELSE N |{ } ; IF st bt gm
Q -> .WHILE ( S ) N |{ } ; IF st bt gm
Q -> .FOR ( O O ) N |{ } ; IF st bt gm
Q -> .FOR ( O O S ) N |{ } ; IF st bt gm
R -> .CONTINUE ; |{ } ; IF st bt gm
R -> .BREAK ; |{ } ; IF st bt gm
R -> .RETURN ; |{ } ; IF st bt gm
R -> .RETURN S ; |{ } ; IF st bt gm
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %




I88: I53 <- C
K -> C. |{ } ; IF st af bt gm


I53 <- N INTER I46
I53 <- E INTER I47
I53 <- L INTER I48
I53 <- O INTER I49
I53 <- P INTER I50
I53 <- Q INTER I51
I53 <- R INTER I52
I53 <- G INTER I17
I53 <- { INTER I53
I53 <- ; INTER I54
I53 <- S INTER I55
I53 <- IF INTER I56
I53 <- WHILE INTER I57
I53 <- FOR INTER I58
I53 <- CONTINUE INTER I59
I53 <- BREAK INTER I60
I53 <- RETURN INTER I61
I53 <- VOID INTER I10
I53 <- CHAR INTER I11
I53 <- SHORT INTER I12
I53 <- INT INTER I13
I53 <- LONG INTER I14
I53 <- FLOAT INTER I15
I53 <- DOUBLE INTER I16
I53 <- SIGNED INTER I17
I53 <- UNSIGNED INTER I18
I53 <- T INTER I62
I53 <- U INTER I63
I53 <- V INTER I64
I53 <- W INTER I65
I53 <- X INTER I66
I53 <- Y INTER I67
I53 <- Z INTER I68
I53 <- IDENTIFIER INTER I69
I53 <- CONSTANT INTER I70
I53 <- STRING_LITERAL INTER I71
I53 <- ( INTER I72




I89: I55 <- ;
O -> S ;. |{ } ; IF st bt gm


I90: I55 <- ,
S -> S , .T |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I91: I56 <- (
P -> IF ( .S ) N |{ } ; IF st bt gm
P -> IF ( .S ) N ELSE N |{ } ; IF st bt gm
S -> .T              |) ,
S -> .S , T          |) ,
T -> .T OR_OP U      |) , OR_OP
T -> .U              |) , OR_OP
U -> .U AND_OP V     |) , OR_OP AND_OP
U -> .V              |) , OR_OP AND_OP
V -> .V NE_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |) , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I92: I57 <- (
Q -> WHILE ( .S ) N |{ } ; IF st bt gm
S -> .T              |) ,
S -> .S , T          |) ,
T -> .T OR_OP U      |) , OR_OP
T -> .U              |) , OR_OP
U -> .U AND_OP V     |) , OR_OP AND_OP
U -> .V              |) , OR_OP AND_OP
V -> .V NE_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |) , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I93: I58 <- (
Q -> FOR ( .O O ) N   |{ } ; IF st bt gm
Q -> FOR ( .O O S ) N |{ } ; IF st bt gm
O -> .;               |; bt
O -> .S ;             |; bt
S -> .T              |; ,
S -> .S , T          |; ,
T -> .T OR_OP U      |; , OR_OP
T -> .U              |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I94: I59 <- ;
R -> CONTINUE ;. |{ } ; IF st bt gm


I95: I60 <- ;
R -> BREAK ;. |{ } ; IF st bt gm




I96: I61 <- ;
R -> RETURN ;. |{ } ; IF st bt gm


I97: I61 <- S
R -> RETURN S .;     |{ } ; IF st bt gm
S -> S ., T          |; ,


I61 <- T INTER I62
I61 <- U INTER I63
I61 <- V INTER I64
I61 <- W INTER I65
I61 <- X INTER I66
I61 <- Y INTER I67
I61 <- Z INTER I68
I61 <- IDENTIFIER INTER I69
I61 <- CONSTANT INTER I70
I61 <- STRING_LITERAL INTER I71
I61 <- ( INTER I72








I98: I62 <- OR_OP
T -> T OR_OP .U      |; , OR_OP
U -> .U AND_OP V     |; , OR_OP AND_OP
U -> .V              |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I99: I63 <- AND_OP
U -> U AND_OP .V     |; , OR_OP AND_OP
V -> .V NE_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |; , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I100: I64 <- NE_OP
V -> V NE_OP .W      |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I101: I64 <- EQ_OP
V -> V EQ_OP .W      |; , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I102: I65 <- <
W -> W < .X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I103: I65 <- >
W -> W > .X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I104: I65 <- LE_OP
W -> W LE_OP .X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I105: I65 <- GE_OP
W -> W GE_OP .X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %





I106: I66 <- -
X -> X - .Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I107: I66 <- +
X -> X + .Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %




I108: I67 <- *
Y -> Y * .Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I109: I67 <- /
Y -> Y / .Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I110: I67 <- %
Y -> Y % .Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %



I111: I70 <- CONSTANT
Z -> CONSTANT.       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I112: I71 <- STRING_LITERAL
Z -> STRING_LITERAL. |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


I113: I72 <- S
Z -> ( S .)          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
S -> S ., T          |) ,





I72: I29 <- (
S -> .T              |) ,
T -> .T OR_OP U      |) , OR_OP
T -> .U              |) , OR_OP
U -> .U AND_OP V     |) , OR_OP AND_OP
U -> .V              |) , OR_OP AND_OP
V -> .V NE_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .V EQ_OP W      |) , OR_OP AND_OP NE_OP EQ_OP
V -> .W              |) , OR_OP AND_OP NE_OP EQ_OP
W -> .W < X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W > X          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W LE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .W GE_OP X      |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
W -> .X              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >
X -> .X - Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .X + Y          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
X -> .Y              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -
Y -> .Y * Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y / Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Y % Z          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Y -> .Z              |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .IDENTIFIER     |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .CONSTANT       |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .STRING_LITERAL |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %
Z -> .( S )          |) , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %


G':
S0 -> .A
A -> .B
A -> .A B
B -> .D
B -> .C
C -> .E;
C -> .E F;
E -> .G
E -> .G E
G -> .VOID
G -> .CHAR
G -> .SHORT
G -> .INT
G -> .LONG
G -> .FLOAT
G -> .DOUBLE
G -> .SIGNED
G -> .UNSIGNED
F -> .I
F -> .F , I

I: declarator J: pointer   1: direct_declarator
T: logical_or_expression
2: parameter_list 3: identifier_list
4: parameter_declaration 5: abstract_declarator 6: direct_abstract_declarator

I -> .J 1
I -> 1
J -> .*
J -> .* J
1 -> IDENTIFIER
1 -> (I)
1 -> 1[T]
1 -> 1 '[' ']'
1 -> 1 '(' 2 ')'
1 -> 1 '(' 3 ')'
1 -> 1 '(' ')'
2 -> 4
2 -> 2 ',' 4
4 -> E I
4 -> E 5
4 -> E
3 -> IDENTIFIER
3 -> 3 ',' IDENTIFIER
5 -> J
5 -> 6
5 -> J 6
6 -> '(' 5 ')'
6 -> '[' ']'
6 -> '[' T ']'
6 -> 6 '[' ']'
6 -> 6 '[' T ']'
6 -> '(' ')'
6 -> '(' 2 ')'
6 -> 6 '(' ')'
6 -> 6 '(' 2 ')'


D -> .E I K L
D -> .E I L
D -> .I K L
D -> .I L
K -> .C
K -> .K C
L -> .{ }
L -> .{ K }
L -> .{ M }
L -> .{ K M }
M -> .N
M -> .M N
N -> .L
N -> .O
N -> .P
N -> .Q
N -> .R
O -> .;
O -> .S ;
S -> .T
S -> .S , T
T -> .T OR_OP U
T -> .U
U -> .U AND_OP V
U -> .V
V -> .V NE_OP W
V -> .V EQ_OP W
V -> .W
W -> .W < X
W -> .W > X
W -> .W LE_OP X
W -> .W GE_OP X
W -> .X
X -> .X - Y
X -> .X + Y
X -> .Y
Y -> .Y * Z
Y -> .Y / Z
Y -> .Y % Z
Y -> .Z
Z -> .IDENTIFIER
Z -> .CONSTANT
Z -> .STRING_LITERAL
Z -> .( S )
P -> .IF ( S ) N
P -> .IF ( S ) N ELSE N
Q -> .WHILE ( S ) N
Q -> .FOR ( O O ) N
Q -> .FOR ( O O S ) N
R -> .CONTINUE ;
R -> .BREAK ;
R -> .RETURN ;
R -> .RETURN S ;

/*
*  OR_OP            o
   AND_OP           a
   NE_OP            n
   EQ_OP            e
   LE_OP            l
   GE_OP            g
   VOID             1  d
   CHAR             2  t
   SHORT            3  u
   INT              4  j
   LONG             5  k
   FLOAT            6  m
   DOUBLE           7  v
   SIGNED           8  p
   UNSIGNED         9  q
   IDENTIFIER       i
   CONSTANT         c
   STRING_LITERAL   s
   BREAK            b
   RETURN           r
   WHILE            h
   FOR              f
   IF               y
   ELSE             x
   CONTINUE         z
   { } ( ) ; , > < + - * / %

*/















