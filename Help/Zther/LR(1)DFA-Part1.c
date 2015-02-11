I0:
A0	->	.A		"$
A	->	.B		"$
B	->	.B-D	"$/-/+
B	->	.B+D	"$/-/+
B	->	.D		"$/-/+
D	->	.D%E	"$/-/+/%///*
D	->	.D/E	"$/-/+/%///*
D	->	.D*E	"$/-/+/%///*




I1: I0 <- A
A0	->	A.		"$







I2: I0 <- B
A	->	B.		"$
B	->	B.-D	"$/-/+
B	->	B.+D	"$/-/+


I3: I0 <- D
B	->	D.		"$/-/+
D	->	D.%E	"$/-/+/%///*
D	->	D./E	"$/-/+/%///*
D	->	D.*E	"$/-/+/%///*



I4: I2 <- -
B	->	B-.D	"$/-/+
D	->	.D%E	"$/-/+/%///*
D	->	.D/E	"$/-/+/%///*
D	->	.D*E	"$/-/+/%///*


I5: I2 <- +
B	->	B+.D	"$/-/+
D	->	.D%E	"$/-/+/%///*
D	->	.D/E	"$/-/+/%///*
D	->	.D*E	"$/-/+/%///*


I6: I3 <- %
D -> D%.E "$/-/+/%///*
E -> .(A) "$/-/+/%///*
E -> .STRING_LITERAL "$/-/+/%///*
E -> .CONSTANT "$/-/+/%///*
E -> .IDENTIFIER "$/-/+/%///*


I7: I3 <- /
D -> D/.E "$/-/+/%///*
E -> .(A) "$/-/+/%///*
E -> .STRING_LITERAL "$/-/+/%///*
E -> .CONSTANT "$/-/+/%///*
E -> .IDENTIFIER "$/-/+/%///*




I8: I3 <- *
D -> D*.E "$/-/+/%///*
E -> .(A) "$/-/+/%///*
E -> .STRING_LITERAL "$/-/+/%///*
E -> .CONSTANT "$/-/+/%///*
E -> .IDENTIFIER "$/-/+/%///*


I9: I4 <- D
B -> B - D. "$/-/+
D -> D. % E "$/-/+/%///*
D -> D. / E "$/-/+/%///*
D -> D. * E "$/-/+/%///*



I10: I5 <- D
B -> B + D. "$/-/+
D -> D. % E "$/-/+/%///*
D -> D. / E "$/-/+/%///*
D -> D. * E "$/-/+/%///*


I11: I6 <- E
D -> D % E. "$/-/+/%///*


I12: I6 <- (
E -> ( .A ) "$/-/+/%///*
A -> .B "$/-/+/%///*
B -> .B - D "$/-/+/%///*/
B -> .B + D "$/-/+/%///*/
B -> .D "$/-/+/%///*/
D -> .D % E "$/-/+/%///*/
D -> .D / E "$/-/+/%///*/
D -> .D * E "$/-/+/%///*/


I13: I6 <- STRING_LITERAL
E -> STRING_LITERAL. "$/-/+/%///*


I14: I6 <- CONSTANT
E -> CONSTANT. "$/-/+/%///*



I15: I6 <- IDENTIFIER
E -> IDENTIFIER. "$/-/+/%///*




I16: I7 <- E
D -> D / E. "$/-/+/%///*
I7 <- ( INTER I12
I7 <- STRING_LITERAL INTER I13
I7 <- CONSTANT INTER I14
I7 <- IDENTIFIER INTER I15







I17: I8 <- E
D -> D * E. "$/-/+/%///*

I8 <- ( INTER I12
I8 <- STRING_LITERAL INTER I13
I8 <- CONSTANT INTER I14
I8 <- IDENTIFIER INTER I15



I18: I9 <- %
D -> D % .E "$/-/+/%///*
E -> .STRING_LITERAL "$/-/+/%///*/
E -> .CONSTANT "$/-/+/%///*/
E -> .IDENTIFIER "$/-/+/%///*/

I19: I9 <- /
D -> D / .E "$/-/+/%///*
E -> .STRING_LITERAL "$/-/+/%///*/
E -> .CONSTANT "$/-/+/%///*/
E -> .IDENTIFIER "$/-/+/%///*/

I20: I9 <- *
D -> D * .E "$/-/+/%///*
E -> .STRING_LITERAL "$/-/+/%///*/
E -> .CONSTANT "$/-/+/%///*/
E -> .IDENTIFIER "$/-/+/%///*/


I10 <- % INTER I18
I10 <- / INTER I19
I10 <- * INTER I20




I12: I6 <- (
E -> ( .A ) "$/-/+/%///*
A -> .B "$/-/+/%///*
B -> .B - D "$/-/+/%///*/
B -> .B + D "$/-/+/%///*/
B -> .D "$/-/+/%///*/
D -> .D % E "$/-/+/%///*/
D -> .D / E "$/-/+/%///*/
D -> .D * E "$/-/+/%///*/

I21: I12 <- B
E -> B. "$/-/+/%///*
B -> B .- D "$/-/+/%///*/
B -> B .+ D "$/-/+/%///*/

I22: I12 <- D
B -> D. "$/-/+/%///*/
D -> D. % E "$/-/+/%///*/
D -> D. / E "$/-/+/%///*/
D -> D. * E "$/-/+/%///*/

I23: I12 <- A
E -> ( A .) "$/-/+/%///*




I18 <- E INTER I11
I18 <- STRING_LITERAL INTER I13
I18 <- CONSTANT INTER I14
I18 <- IDENTIFIER INTER I15

I19 <- E INTER I16
I19 <- STRING_LITERAL INTER I13
I19 <- CONSTANT INTER I14
I19 <- IDENTIFIER INTER I15


I20 <- E INTER I17
I20 <- STRING_LITERAL INTER I13
I20 <- CONSTANT INTER I14
I20 <- IDENTIFIER INTER I15


I24: I21 <- -
B -> B - .D "$/-/+/%///*/
D -> .D % E "$/-/+/%///*/
D -> .D / E "$/-/+/%///*/
D -> .D * E "$/-/+/%///*/

I25: I21 <- +
B -> B + .D "$/-/+/%///*/
D -> .D % E "$/-/+/%///*/
D -> .D / E "$/-/+/%///*/
D -> .D * E "$/-/+/%///*/


I22 <- % INTER I18
I22 <- / INTER I19
I22 <- * INTER I20


I26: I23 <- )
E -> ( A ). "$/-/+/%///*

I27: I24 <- D
B -> B - D. "$/-/+/%///*/
D -> D. % E "$/-/+/%///*/
D -> D. / E "$/-/+/%///*/
D -> D. * E "$/-/+/%///*/

I28: I25 <- D
B -> B + D. "$/-/+/%///*/
D -> D. % E "$/-/+/%///*/
D -> D. / E "$/-/+/%///*/
D -> D. * E "$/-/+/%///*/


I27 <- % INTER I18
I27 <- / INTER I19
I27 <- * INTER I20

I28 <- % INTER I18
I28 <- / INTER I19
I28 <- * INTER I20

G':
A0 -> A
A -> B
B -> B - D
B -> B + D
B -> D
D -> D % E
D -> D / E
D -> D * E
E -> ( B )
E -> STRING_LITERAL
E -> CONSTANT
E -> IDENTIFIER



















G':
S0 -> A
A -> B
A -> A B
B -> D
B -> C
C -> E;
C -> E F;
E -> G
E -> G E
G -> VOID
G -> CHAR
G -> SHORT
G -> INT
G -> LONG
G -> FLOAT
G -> DOUBLE
G -> SIGNED
G -> UNSIGNED
F -> I
F -> F , I
I -> J IDENTIFIER
I -> IDENTIFIER
J -> *
J -> * J
D -> E I K L
D -> E I L
D -> I K L
D -> I L
K -> C
K -> K C
L -> { }
L -> { K }
L -> { M }
L -> { K M }
M -> N
M -> M N
N -> L
N -> O
N -> P
N -> Q
N -> R
O -> ;
O -> S ;
S -> T
S -> S , T
T -> T OR_OP U
T -> U
U -> U AND_OP V
U -> V
V -> V NE_OP W
V -> V EQ_OP W
V -> W
W -> W < X
W -> W > X
W -> W LE_OP X
W -> W GE_OP X
W -> X
X -> X - Y
X -> X + Y
X -> Y
Y -> Y * Z
Y -> Y / Z
Y -> Y % Z
Y -> Z
Z -> IDENTIFIER
Z -> CONSTANT
Z -> STRING_LITERAL
Z -> ( S )
P -> IF ( S ) N
P -> IF ( S ) N ELSE N
Q -> WHILE ( S ) N
Q -> FOR ( O O ) N
Q -> FOR ( O O S ) N
R -> CONTINUE ;
R -> BREAK ;
R -> RETURN ;
R -> RETURN S ;
