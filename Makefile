GITHUB_COMMIT="修复了一处指针越界问题..."


ROOT_DIR = $(shell pwd)
PLATFORM=$(shell $(ROOT_DIR)/systype.sh)

ifeq ($(PLATFORM), linux)
LIB_FILE_SUFFIX = a
DLL_FILE_SUFFIX = so
else
SHELL=cmd.exe
LIB_FILE_SUFFIX = lib
DLL_FILE_SUFFIX = dll

endif

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
OBJ_ROOT_DIR     = .obj/
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
DLL = $(BIN_ROOT_DIR)libCTools.$(DLL_FILE_SUFFIX)
LIB_DIR = $(BIN_ROOT_DIR)

#  PROP
PROP_DLL_ELF = $(BIN_ROOT_DIR)prop-dynamic.exe
PROP_LIB_ELF = $(BIN_ROOT_DIR)prop-static.exe
OBJ_GLOBAL_PROP_FILE = $(OBJ_GLOBAL_DIR)Prop.o
PROP_ICO = $(ICO_ROOT_DIR)prop.ico
ifeq ($(PLATFORM), windows)
PROP_RES = $(PROP_RES)
else
PROP_RES =
endif

#  CTools
LEXICAL_DLL_ELF = $(BIN_ROOT_DIR)lexical-dynamic.exe
LEXICAL_LIB_ELF = $(BIN_ROOT_DIR)lexical-static.exe
OBJ_GLOBAL_LEXICAL_FILE = $(OBJ_GLOBAL_DIR)Lexical.o
LEXICAL_ICO = $(ICO_ROOT_DIR)Lexical.ico
ifeq ($(PLATFORM), windows)
LEXICAL_RES = $(RES_ROOT_DIR)Lexical.res
else
LEXICAL_RES =
endif


#  Parser
PARSER_ELF = $(BIN_ROOT_DIR)Parser.exe
PARSER_ICO = $(ICO_ROOT_DIR)Parser.ico
OBJ_GLOBAL_PARSE_FILE = $(OBJ_GLOBAL_DIR)Parser.o
ifeq ($(PLATFORM), windows)
PARSER_RES = $(RES_ROOT_DIR)Parser.res
else
PARSER_RES =
endif


OBJ_FILES = $(OBJ_CONFIG_FILE) $(OBJ_TOOLS_FILE) 	\
			$(OBJ_LEXICAL_FILE) $(OBJ_PARSER_FILE) 	\
			$(OBJ_PROP_FILE) 
			#	$(OBJ_GLOBAL_FILE) non't include global files

CC = gcc


#  the compile options
CFLAGS = -Wall -std=c99 -O2 -pedantic -Wextra -g
SHAREDLIB_LINK_OPTIONS = -shared

ifeq ($(PLATFORM), windows)
FPIC =
else
FPIC = -fPIC
endif
#-Wl,-soname,
#  the include directory
INC = -I./Config -I./Tools -I./Lexical -I./Parser -I./Prop -I./Table -I./Global


target	:	$(LEXICAL_DLL_ELF) $(LEXICAL_LIB_ELF)	\
			$(PARSER_DLL_ELF) $(PARSER_LIB_ELF)		\
			$(PROP_DLL_ELF) $(PROP_LIB_ELF) 

all	:	target



#	--------------
#	Compile target
#	--------------

##	Lexical
# Use the Dynamic Link Library libCTools.so to complie the EIF
$(LEXICAL_DLL_ELF): $(OBJ_GLOBAL_LEXICAL_FILE) $(DLL)
	make res
	gcc $(OBJ_GLOBAL_LEXICAL_FILE) $(LEXICAL_RES) -o $@  -L$(LIB_DIR) -lCTools

$(LEXICAL_LIB_ELF): $(OBJ_FILES) $(OBJ_GLOBAL_LEXICAL_FILE)
	gcc $^ $(LEXICAL_RES)  -o $@



##	prop
# Use the Dynamic Link Library libCTools.so to complie the EIF
$(PARSER_DLL_ELF): $(OBJ_GLOBAL_PARSER_FILE) $(DLL)
	make res
	gcc $(OBJ_GLOBAL_PARSER_FILE) $(PARSER_RES) -o $@  -L$(LIB_DIR) -lCTools

$(PARSER_LIB_ELF): $(OBJ_FILES) $(OBJ_GLOBAL_PARSER_FILE)
	gcc $^ $(PARSER_RES) -o $@




##	prop
# Use the Dynamic Link Library libCTools.so to complie the EIF
$(PROP_DLL_ELF): $(OBJ_GLOBAL_PROP_FILE) $(DLL)
	make res
	gcc $(OBJ_GLOBAL_PROP_FILE) $(PROP_RES) -o $@  -L$(LIB_DIR) -lCTools

$(PROP_LIB_ELF): $(OBJ_FILES) $(OBJ_GLOBAL_PROP_FILE)
	gcc $^ $(PROP_RES) -o $@




#  Complie the Dynamic Link Library libCTools.so
$(DLL):$(OBJ_FILES)
	gcc $(SHAREDLIB_LINK_OPTIONS) $(FPIC) $(LDFLAGS) $^ -o $@





#	--------------------------
#	Compiler all the directory
#	--------------------------

#  Complie Config Directory
$(OBJ_CONFIG_DIR)%.o:$(SRC_CONFIG_DIR)%.c
	gcc $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  Complie Tools Package
$(OBJ_TOOLS_DIR)%.o:$(SRC_TOOLS_DIR)%.c
	gcc $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  Complier Lexical Package
$(OBJ_LEXICAL_DIR)%.o:$(SRC_LEXICAL_DIR)%.c
	gcc $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  Parser语法分析
$(OBJ_PARSER_DIR)%.o:$(SRC_PARSER_DIR)%.c
	gcc $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#  插桩器
$(OBJ_PROP_DIR)%.o:$(SRC_PROP_DIR)%.c
	gcc $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC)


#  global全局主文件
$(OBJ_GLOBAL_DIR)%.o:$(SRC_GLOBAL_DIR)%.c
	gcc $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC)

#	-----------
#	compile ico
#	-----------

#	编译ico图标, 仅windows有效
$(RES_ROOT_DIR)%.res:$(ICO_ROOT_DIR)%.rc
	dres  -J rc -O coff -i $^ -o $@


.PHONY: static
static:
	ar -rc libCTools.a $(OBJ_CONFIG_FILE) $(OBJ_TOOLS_FILE) $(OBJ_LEXICAL_FILE) $(OBJ_PARSER_FILE) $(OBJ_PROP_FILE) $(OBJ_GLOBAL_FILE)

.PHONY: clean
clean:
	rm  -rf $(OBJ_CONFIG_FILE)
	rm	-rf $(OBJ_GLOBAL_FILE)
	rm	-rf $(OBJ_LEXICAL_FILE)
	rm	-rf $(OBJ_PARSER_FILE)
	rm	-rf $(OBJ_PROP_FILE)
	rm	-rf $(OBJ_TOOLS_FILE)
	rm	-rf $(OBJ_ROOT_DIR)CTools.res
	rm  -rf $(DLL)
	rm  -rf $(ELF)
	rm  -rf $(target)
	rm  -rf $(LEXICAL_DLL_ELF) $(LEXICAL_LIB_ELF)	\
			$(PARSER_DLL_ELF) $(PARSER_LIB_ELF)		\
			$(PROP_DLL_ELF) $(PROP_LIB_ELF) 


.PHONY: res
ifeq ($(PLATFORM), linux)
res	:
	@echo "you can't res in linux..."
else
res: dres  -J rc -O coff -i $(ICO_ROOT_DIR)Prop.rc -o $(PROP_RES) dres  -J rc -O coff -i $(ICO_ROOT_DIR)Lexical.rc -o $(RES_ROOT_DIR)Lexical.res
	dres  -J rc -O coff -i $(ICO_ROOT_DIR)Parser.rc -o $(RES_ROOT_DIR)Parser.res
endif


objdir	:
	mkdir -p .obj
	cd .obj && mkdir -p Config Global Lexical Parser Prop Release Tools


run_lexical	:	$(LEXICAL_LIB_ELF)
	cd bin && ./lexical-static.exe ./test.c

.PHONY	:	github
github :
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master
