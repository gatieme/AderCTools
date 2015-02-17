
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
# the objectfile files
#--------------------------
OBJ_CONFIG_FILE  =  $(OBJ_CONFIG_DIR)Config.o
OBJ_TOOLS_FILE   =  $(OBJ_TOOLS_DIR)Buffer.o $(OBJ_TOOLS_DIR)Errors.o $(OBJ_TOOLS_DIR)Files.o
OBJ_LEXICAL_FILE =  $(OBJ_LEXICAL_DIR)BinaryTuple.o $(OBJ_LEXICAL_DIR)Lexical.o $(OBJ_LEXICAL_DIR)TokenKind.o
OBJ_PARSER_FILE  =  $(OBJ_PARSER_DIR)Grammar.o $(OBJ_PARSER_DIR)Parser.o $(OBJ_PARSER_DIR)StateStack.o $(OBJ_PARSER_DIR)SyntaxQueue.o $(OBJ_PARSER_DIR)SyntaxStack.o $(OBJ_PARSER_DIR)SyntaxTable.o  $(OBJ_PARSER_DIR)SyntaxTree.o
OBJ_PROP_FILE    =  $(OBJ_PROP_DIR)Prop.o $(OBJ_PROP_DIR)PropFor.o $(OBJ_PROP_DIR)PropRed.o $(OBJ_PROP_DIR)PropTable.o
OBJ_GLOBAL_FILE  =  $(OBJ_GLOBAL_DIR)CTools.o

#--------------------------
# the ico file directory
#--------------------------
ICO_ROOT_DIR     =  $(SRC_ROOT_DIR)Ico/
RES_ROOT_DIR     =  $(BIN_ROOT_DIR)Res/


#--------------------------
# the elf file directory
#--------------------------
BIN_ROOT_DIR      = ./bin/
DLL = $(BIN_ROOT_DIR)libCTools.dll
LIB_DIR = $(BIN_ROOT_DIR)

#  PROP
PROP_ELF = $(BIN_ROOT_DIR)prop.exe
PROP_ICO = $(ICO_ROOT_DIR)prop.ico
PROP_RES = $(RES_ROOT_DIR)Prop.res


#  CTools
LEXICAL_ELF = $(BIN_ROOT_DIR)Lexical.exe
LEXICAL_ICO = $(ICO_ROOT_DIR)Lexical.ico
LEXICAL_RES = $(RES_ROOT_DIR)Lexical.res

#  Parser
PARSER_ELF = $(BIN_ROOT_DIR)Parser.exe
PARSER_ICO = $(ICO_ROOT_DIR)Parser.ico
PARSER_RES = $(RES_ROOT_DIR)Parser.res


CC = gcc


#  the compile options
CFLAGS = -Wall -std=c99 -O2 -pedantic -Wextra
SHAREDLIB_LINK_OPTIONS = -shared 
FPIC = 
#-Wl,-soname,
#  the include directory
INC = -I./Config -I./Tools -I./Lexical -I./Parser -I./Prop -I./Table -I./Global




# Use the Dynamic Link Library libCTools.so to complie the EIF 
$(PROP_ELF): $(OBJ_GLOBAL_FILE) $(DLL)
	make res
	gcc $(OBJ_GLOBAL_FILE) $(RES_ROOT_DIR)Prop.res -o $@  -L$(LIB_DIR) -lCTools

#  Complie the Dynamic Link Library libCTools.so
$(DLL):$(OBJ_CONFIG_FILE) $(OBJ_TOOLS_FILE) $(OBJ_LEXICAL_FILE) $(OBJ_PARSER_FILE) $(OBJ_PROP_FILE) $(OBJ_GLOBAL_FILE)
	gcc $(SHAREDLIB_LINK_OPTIONS) $(LDFLAGS) -o $@ $^

#  Complie Config Directory
$(OBJ_CONFIG_DIR)%.o:$(SRC_CONFIG_DIR)%.c
	gcc $(fPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  Complie Tools Package
$(OBJ_TOOLS_DIR)%.o:$(SRC_TOOLS_DIR)%.c
	gcc $(fPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  Complier Lexical Package 
$(OBJ_LEXICAL_DIR)%.o:$(SRC_LEXICAL_DIR)%.c
	gcc $(fPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  Parser语法分析
$(OBJ_PARSER_DIR)%.o:$(SRC_PARSER_DIR)%.c
	gcc $(fPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  插桩器
$(OBJ_PROP_DIR)%.o:$(SRC_PROP_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)


$(RES_ROOT_DIR)%.res:$(ICO_ROOT_DIR)%.rc
	dres  -J rc -O coff -i $^ -o $@

#  global全局主文件
$(OBJ_GLOBAL_DIR)%.o:$(SRC_GLOBAL_DIR)%.c
	gcc $(CFLAGS) -c $^ -o $@ $(INC)



.PHONY: static
static:
	ar -rc libCTools.a $(OBJ_CONFIG_FILE) $(OBJ_TOOLS_FILE) $(OBJ_LEXICAL_FILE) $(OBJ_PARSER_FILE) $(OBJ_PROP_FILE) $(OBJ_GLOBAL_FILE) 

.PHONY: clean
clean:
	rm  $(OBJ_CONFIG_FILE)
	rm	$(OBJ_GLOBAL_FILE)
	rm	$(OBJ_LEXICAL_FILE)
	rm	$(OBJ_PARSER_FILE)
	rm	$(OBJ_PROP_FILE)
	rm	$(OBJ_TOOLS_FILE)
	rm	$(OBJ_ROOT_DIR)CTools.res
	rm  $(DLL)
	rm  $(ELF)


.PHONY: res
res:
	dres  -J rc -O coff -i $(ICO_ROOT_DIR)Prop.rc -o $(RES_ROOT_DIR)Prop.res
	dres  -J rc -O coff -i $(ICO_ROOT_DIR)Lexical.rc -o $(RES_ROOT_DIR)Lexical.res
	dres  -J rc -O coff -i $(ICO_ROOT_DIR)Parser.rc -o $(RES_ROOT_DIR)Parser.res
