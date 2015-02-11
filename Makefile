OBJ = obj/
BIN = bin/
CONFIG	 = Config/
GLOBAL	 = Global/
LEXICAL = LEexical/
PARSER  = Parser/
PROP	 = Prop/

C99 = -std=c99
CC  = gcc

INC = -I./Config -I./Tools -I./Lexical -I./Parser -I./Prop
ELF = $(BIN)prop.exe



$(ELF):$(OBJ)$(CONFIG)Config.o
	$(OBJ)$(GLOBAL)CTools.o
	$(OBJ)$(LEXICAL)BinaryTuple.o $(OBJ)$(LEXICAL)Lexical.o
	$(OBJ)$(PARSER)Grammar.o $(OBJ)$(PARSER)AnalyStack.o $(OBJ)$(PARSER)SynAnaTable.o
	$(OBJ)$(PARSER)SynAnaTree.o $(OBJ)$(PARSER)StateStack.o $(OBJ)$(PARSER)SyntaxQueue.o
	$(OBJ)$(PARSER)SyntaxStack.o $(OBJ)$(PARSER)SyntaxTable.o $(OBJ)$(PARSER)SyntaxTree.o
	$(OBJ)$(PARSER)Parser.o
	$(OBJ)$(PROP)Prop.o $(OBJ)$(PROP)PropFor.o $(OBJ)$(PROP)PropFor.o 
	$(OBJ)$(PROP)PropRed.o $(OBJ)$(PROP)PropTable.o
	$(OBJ)$(Tools)Buffer.o $(OBJ)$(Tools)Errors.o $(OBJ)$(Tools)Files.o $(OBJ)Ctools.res
	
	CC $^ -o $@


$(OBJ)$(CONFIG)%.o:$(CONFIG)%.c
	CC -c $^ -o $@ $(INC)

$(OBJ)$(GLOBAL)%.o:$(GLOBAL)%.c
	CC -c $^ -o $@ $(INC)

$(OBJ)$(LEXICAL)%.o:$(LEXICAL)%.c
	CC -c $^ -o $@ $(INC)

$(OBJ)$(PARSER)%.o:$(PARSER)%.c
	CC -c $^ -o $@ $(INC)

$(OBJ)$(PROP)%.o:$(PROP)%.c
	CC -c $^ -o $@ $(INC)

$(OBJ)$(Tools)%.o:$(Tools)%.c
	CC -c $^ -o $@ $(INC)