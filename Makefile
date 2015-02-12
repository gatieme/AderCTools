
SHELL := cmd.exe 

#--------------------------
# the source file directory
#--------------------------
SRC_ROOT_DIR     = ./
SRC_CONFIG_DIR	 = $(SRC_ROOT_DIR)Config/
SRC_TOOLS_DIR    = $(SRC_ROOT_DIR)Tools/
SRC_LEXICAL_DIR  = $(SRC_ROOT_DIR)Lexical/
SRC_PARSER_DIR   = $(SRC_ROOT_DIR)Parser/
SRC_PROP_DIR	 = $(SRC_ROOT_DIR)Prop/
SRC_GLOBAL_DIR	 = $(SRC_ROOT_DIR)Global/

#--------------------------
# the objectfile directory
#--------------------------
OBJ_ROOT_DIR     = obj/
OBJ_CONFIG_DIR	 = $(OBJ_ROOT_DIR)Config/
OBJ_TOOLS_DIR    = $(OBJ_ROOT_DIR)Tools/
OBJ_LEXICAL_DIR  = $(OBJ_ROOT_DIR)Lexical/
OBJ_PARSER_DIR   = $(OBJ_ROOT_DIR)Parser/
OBJ_PROP_DIR	 = $(OBJ_ROOT_DIR)Prop/
OBJ_GLOBAL_DIR	 = $(OBJ_ROOT_DIR)Global/

#--------------------------
# the elf file directory
#--------------------------
BIN_ROOT_DIR      = ./bin/
ELF = $(BIN_ROOT_DIR)prop.exe


CC = gcc

CFLAGS = -Wall -std=c99 -O2 -pedantic -Wextra

INC = -I./Config -I./Tools -I./Lexical -I./Parser -I./Prop





$(ELF):$(OBJ_CONFIG_DIR)Config.o $(OBJ_TOOLS_DIR)Buffer.o $(OBJ_TOOLS_DIR)Errors.o $(OBJ_TOOLS_DIR)Files.o $(OBJ_LEXICAL_DIR)BinaryTuple.o $(OBJ_LEXICAL_DIR)Lexical.o $(OBJ_LEXICAL_DIR)TokenKind.o $(OBJ_PARSER_DIR)Grammar.o $(OBJ_PARSER_DIR)Parser.o $(OBJ_PARSER_DIR)StateStack.o $(OBJ_PARSER_DIR)SyntaxQueue.o $(OBJ_PARSER_DIR)SyntaxStack.o $(OBJ_PARSER_DIR)SyntaxTable.o $(OBJ_PARSER_DIR)SyntaxTree.o $(OBJ_PROP_DIR)Prop.o $(OBJ_PROP_DIR)PropFor.o $(OBJ_PROP_DIR)PropRed.o $(OBJ_PROP_DIR)PropTable.o $(OBJ_GLOBAL_DIR)CTools.o $(OBJ_DIR)CTools.res  

	gcc $^ -o $@



#  Config配置目录的目标文件
$(OBJ_CONFIG_DIR)%.o:$(SRC_CONFIG_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)

#  CTools编译工具链Tools工具包
$(OBJ_TOOLS_DIR)%.o:$(SRC_TOOLS_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)

#  Lexical词法分析
$(OBJ_LEXICAL_DIR)%.o:$(SRC_LEXICAL_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)

#  Parser语法分析
$(OBJ_PARSER_DIR)%.o:$(SRC_PARSER_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)

#  插桩器
$(OBJ_PROP_DIR)%.o:$(SRC_PROP_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)


$(OBJ_DIR)CTools.res:CTools.rc
	dres  -J rc -O coff -i $^ -o $@

#  global全局主文件
$(OBJ_GLOBAL_DIR)%.o:$(SRC_GLOBAL_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)


.PHONY: clean
clean:
	rm  $(OBJ_CONFIG_DIR)Config.o
	rm	$(OBJ_GLOBAL_DIR)CTools.o
	rm	$(OBJ_LEXICAL_DIR)BinaryTuple.o $(OBJ_LEXICAL_DIR)Lexical.o
	rm	$(OBJ_PARSER_DIR)Grammar.o $(OBJ_PARSER_DIR)AnalyStack.o $(OBJ_PARSER_DIR)SynAnaTable.o
	rm	$(OBJ_PARSER_DIR)SynAnaTree.o $(OBJ_PARSER_DIR)StateStack.o $(OBJ_PARSER_DIR)SyntaxQueue.o
	rm	$(OBJ_PARSER_DIR)SyntaxStack.o $(PARSER_DIR)SyntaxTable.o $(PARSER_DIR)SyntaxTree.o
	rm	$(OBJ_PARSER_DIR)Parser.o
	rm	$(OBJ_PROP_DIR)Prop.o $(OBJ_PROP_DIR)PropFor.o $(OBJ_PROP_DIR)PropFor.o 
	rm	$(OBJ_(PROP_DIR)PropRed.o $(OBJ_PROP_DIR)PropTable.o
	rm	$(OBJ_TOOLS_DIR)Buffer.o $(OBJ_TOOLS_DIR)Errors.o $(OBJ_TOOLS_DIR)Files.o 
	rm	$(OBJ_ROOT_DIR)CTools.res)