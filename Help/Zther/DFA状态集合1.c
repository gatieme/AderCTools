

af = VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED	
bt = IDENTIFIER CONSTANT STRING_LITERAL (
gm = CONTINUE BREAK RETURN
st = WHILE FOR


I0	
START->.S0


I1: I0 <- A
S0 -> A. |$
A -> A .B |$ * af

I2: I0 <- B
A -> B. |$ * af

I3: I0 <- D
B -> D. |$ * af

I4: I0 <- C
B -> C. |$ * af

I5: I0 <- E
D -> E .I K L |$ * af
D -> E .I L |$ * af
C -> E .; |$ * af
C -> E .F ; |$ * af

I6: I0 <- I
D -> I .K L |$ * af
D -> I .L |$ * af

I7: I0 <- G
E -> G. |* IDENTIFIER ;
E -> G .E | * IDENTIFIER ;

I8: I0 <- J
I -> J .IDENTIFIER |{ af

I9: I0 <- IDENTIFIER
I -> IDENTIFIER. |{ af

I10: I0 <- VOID
G -> VOIDENTIFIER. |* ; IDENTIFIER af

I11: I0 <- CHAR
G -> CHAR. |* ; IDENTIFIER af

I12: I0 <- SHORT
G -> SHORT. |* ; IDENTIFIER af

I13: I0 <- INT
G -> INT. |* ; IDENTIFIER af

I14: I0 <- LONG
G -> LONG. |* ; IDENTIFIER af

I15: I0 <- FLOAT
G -> FLOAT. |* ; IDENTIFIER af

I16: I0 <- DOUBLE
G -> DOUBLE. |* ; IDENTIFIER af

I17: I0 <- SIGNED
G -> SIGNED. |* ; IDENTIFIER af

I18: I0 <- UNSIGNED
G -> UNSIGNED. |* ; IDENTIFIER af

I19: I0 <- *
J -> *. |IDENTIFIER
J -> * .J |IDENTIFIER

I20: I1 <- B
A -> A B. |$ * af

I21: I5 <- I
D -> E I .K L  |$ * af
D -> E I .L |$ * af
F -> I. |; ,

I22: I5 <- ;
C -> E ;. |$ * af

I23: I5 <- F
C -> E F .; |$ * af
F -> F ., I |; ,

I24: I5 <- J
I -> J .IDENTIFIER |{ ; , af

I25: I5 <- IDENTIFIER
I -> IDENTIFIER. |{ ; , af

I26: I6 <- K
D -> I K .L |$ * af
K -> K .C |{ af

I27: I6 <- L
D -> I L. |$ * af

I28: I6 <- C
K -> C. |{ af

I29: I6 <- {
L -> { .} |$ * af
L -> { .K } |$ * af
L -> { .M } |$ * af
L -> { .K M } |$ * af

I30: I7 <- E
E -> G E. | * IDENTIFIER ;

I31: I8 <- IDENTIFIER
I -> J IDENTIFIER. |{ af

I32: I19 -> J
J -> * J. |IDENTIFIER

I33: I21 <- K
D -> E I K .L |$ * af
K -> K .C |{ af

I34: I21 <- L
D -> E I L. |$ * af


I35: I21 <- C    INTER I28
K -> C. |{ af

I36: I21 <- E
C -> E .; |{ af
C -> E .F ; |{ af

I37: I23 <- ;
C -> E F ;. |$ * af

I38: I23 <- ,
F -> F , .I |; ,

I39: I24 <- IDENTIFIER
I -> J IDENTIFIER. |{ ; , af

I40: I26 <- L
D -> I K L. |$ * af

I41: I26 <- C
K -> K C. |{ af

I42: I29 <- }
L -> { }. |$ * af

I43: I29 <- K
L -> { K .} |$ * af
L -> { K .M } |$ * af
K -> K .C |{ } ; IF st af bt gm

I44: I29 <- M
L -> { M .} |$ * af
M -> M .N |{ } ; IF st bt gm

I45: I29 <- C
K -> K C. |{ } ; IF st af bt gm



I46: I29 <- N
M -> N. |{ } ; IF st bt gm


I47: I29 <- E
C -> E .; |{ } ; IF st af bt gm
C -> E .F ; |{ } ; IF st af bt gm

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

I73: I33 <- L
D -> E I K L. |$ * af


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

I79: I38 <- I
F -> F , I. |; ,

I80: I43 <- }
L -> { K }. |$ * af

I81: I44 <- }
L -> { M }. |$ * af

I82: I44 <- N
M -> M N. |{ } ; IF st bt gm


I83: I47 <- ;
C -> E ;. |{ } ; IF st af bt gm


I84: I47 <- F
C -> E F. ; |{ } ; IF st af bt gm
F -> F ., I |; ,

I85: I53 <- }
L -> { }. |{ } ; IF st bt gm

I86: I53 <- K
L -> { K .} |{ } ; IF st bt gm
L -> { K .M } |{ } ; IF st bt gm
K -> K .C |{ } ; IF st af bt gm

I87: I53 <- M
L -> { M .} |{ } ; IF st bt gm
M -> M .N |{ } ; IF st bt gm

I88: I53 <- C
K -> C. |{ } ; IF st af bt gm

I89: I55 <- ;
O -> S ;. |{ } ; IF st bt gm


I90: I55 <- ,
S -> S , .T |; ,

I91: I56 <- (
P -> IF ( .S ) N |{ } ; IF st bt gm
P -> IF ( .S ) N ELSE N |{ } ; IF st bt gm

I92: I57 <- (
Q -> WHILE ( .S ) N |{ } ; IF st bt gm

I93: I58 <- (
Q -> FOR ( .O O ) N   |{ } ; IF st bt gm
Q -> FOR ( .O O S ) N |{ } ; IF st bt gm

I94: I59 <- ;
R -> CONTINUE ;. |{ } ; IF st bt gm


I95: I60 <- ;
R -> BREAK ;. |{ } ; IF st bt gm


I96: I61 <- ;
R -> RETURN ;. |{ } ; IF st bt gm


I97: I61 <- S
R -> RETURN S .;     |{ } ; IF st bt gm
S -> S ., T          |; ,

I98: I62 <- OR_OP
T -> T OR_OP .U      |; , OR_OP

I99: I63 <- AND_OP
U -> U AND_OP .V     |; , OR_OP AND_OP

I100: I64 <- NE_OP
V -> V NE_OP .W      |; , OR_OP AND_OP NE_OP EQ_OP

I101: I64 <- EQ_OP
V -> V EQ_OP .W      |; , OR_OP AND_OP NE_OP EQ_OP

I102: I65 <- <
W -> W < .X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >

I103: I65 <- >
W -> W > .X          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >

I104: I65 <- LE_OP
W -> W LE_OP .X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >

I105: I65 <- GE_OP
W -> W GE_OP .X      |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < >

I106: I66 <- -
X -> X - .Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -

I107: I66 <- +
X -> X + .Y          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + -

I108: I67 <- *
Y -> Y * .Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I109: I67 <- /
Y -> Y / .Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I110: I67 <- %
Y -> Y % .Z          |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I111: I70 <- CONSTANT
Z -> CONSTANT.       |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %

I112: I71 <- STRING_LITERAL
Z -> STRING_LITERAL. |; , OR_OP AND_OP NE_OP EQ_OP LE_OP GE_OP < > + - * / %












