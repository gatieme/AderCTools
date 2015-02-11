#include <stdio.h>
#include <stdlib.h>



void Display(char *reveived);
void Setnontermainal(char *str);


int main(void)
{
	freopen("2-1.txt", "r", stdin);
	freopen("2-2.txt", "w", stdout);

	int i = 0;
	char str[81]/*读取的文件信息数据*/, received[81]/*读进终结符号*/, nontermainal[81];
	int state/*当前状态*/, action/*移近-归约标记*/, subState/*新状态*/, last = -1;

	gets(str);					// 跳过第一行数据
	for(i = 0; gets(str); i++)	// 从文件中读取的一行信息
	{
		if(strcmp(str, "") == 0)		// 跳过空行
		{
			continue;
		}
		sscanf(str, "%d%s%d", &state, received, &action);	// 格式化读取数据

		if(action == 1)			// 移近项目集合
		{
			sscanf(str, "%d%s%d%s%d", &state, received, &action, nontermainal, &subState);
			Setnontermainal(nontermainal);
		}
		else					// 否则当前标识为归约
		{
			sscanf(str, "%d%s%d%d", &state, received, &action, &subState);
		}

		Display(received);

		if(last != state)
		{
			if(last != -1)
			{
				printf("\n    {    TOKEN_NULL,               ACTION_NULL,                SYN_NULL,  -1,    },    // the %d's action end\n", state);
				printf("};\n\n");
			}
			printf("ActionNode action%d[] = \n", state);
			printf("{\n");
			printf("/** receive	 action     state/(nontermainalID,subID):**/\n");
			// printf("    %-24s%2d,		//%s\n", received, action, str);
			last = state;
		}
		else
		{
			//printf("    %-24s%2d,		//%s\n", received, action, str);
		}

		if(action == 1)			// 移近状态集合
		{
			printf("    {    %-24s    REDUCTION,%24s,%4d,    },    // %s\n", received, nontermainal, subState, str);
		}
		else
		{
			printf("    {    %-24s       MOVING,                SYN_NULL,%4d,    },    // %s\n", received, subState, str);
		}
	}
	printf("\n    {    TOKEN_NULL,               ACTION_NULL,                SYN_NULL,  -1,    },    // the %d's action end\n", state);
	printf("};\n\n");
	return EXIT_SUCCESS;
}


void Setnontermainal(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if(str[i] == '-')
		{
			str[i] = '_';
		}
		i++;
	}
}



void Display(char *received)
{
	if(strcmp(received, "auto") == 0)
	{
		strcpy(received,"AUTO_KEYWORD,");
	}
	else if(strcmp(received, "break") == 0)
	{
		strcpy(received,"BREAK_KEYWORD,");
	}
	else if(strcmp(received, "case") == 0)
	{
		strcpy(received,"CASE_KEYWORD,");
	}
	else if(strcmp(received, "char") == 0)
	{
		strcpy(received,"CHAR_KEYWORD,");
	}
	else if(strcmp(received, "const") == 0)
	{
		strcpy(received,"CONST_KEYWORD,");
	}
	else if(strcmp(received, "continue") == 0)
	{
		strcpy(received,"CONTINUE_KEYWORD,");
	}
	else if(strcmp(received, "default") == 0)
	{
		strcpy(received,"DEFAULT_KEYWORD,");
	}
	else if(strcmp(received, "do") == 0)
	{
		strcpy(received,"DO_KEYWORD,");
	}
	else if(strcmp(received, "double") == 0)
	{
		strcpy(received,"DOUBLE_KEYWORD,");
	}
	else if(strcmp(received, "else") == 0)
	{
		strcpy(received,"ELSE_KEYWORD,");
	}
	else if(strcmp(received, "enum") == 0)
	{
		strcpy(received,"ENUM_KEYWORD,");
	}
	else if(strcmp(received, "extern") == 0)
	{
		strcpy(received,"EXTERN_KEYWORD,");
	}
	else if(strcmp(received, "float") == 0)
	{
		strcpy(received,"FLOAT_KEYWORD,");
	}
	else if(strcmp(received, "for") == 0)
	{
		strcpy(received,"FOR_KEYWORD,");
	}
	else if(strcmp(received, "goto") == 0)
	{
		strcpy(received,"GOTO_KEYWORD,");
	}
	else if(strcmp(received, "if") == 0)
	{
		strcpy(received,"IF_KEYWORD,");
	}
	else if(strcmp(received, "int") == 0)
	{
		strcpy(received,"INT_KEYWORD,");
	}
	else if(strcmp(received, "long") == 0)
	{
		strcpy(received,"LONG_KEYWORD,");
	}
	else if(strcmp(received, "register") == 0)
	{
		strcpy(received,"REGISTER_KEYWORD,");
	}
	else if(strcmp(received, "return") == 0)
	{
		strcpy(received,"RETURN_KEYWORD,");
	}
	else if(strcmp(received, "short") == 0)
	{
		strcpy(received,"SHORT_KEYWORD,");
	}
	else if(strcmp(received, "signed") == 0)
	{
		strcpy(received,"SIGNED_KEYWORD,");
	}
	else if(strcmp(received, "sizeof") == 0)
	{
		strcpy(received,"SIZEOF_OPERATE,");
	}
	else if(strcmp(received, "static") == 0)
	{
		strcpy(received,"STATIC_KEYWORD,");
	}
	else if(strcmp(received, "struct") == 0)
	{
		strcpy(received,"STRUCT_KEYWORD,");
	}
	else if(strcmp(received, "switch") == 0)
	{
		strcpy(received,"SWITCH_KEYWORD,");
	}
	else if(strcmp(received, "typedef") == 0)
	{
		strcpy(received,"TYPEDEF_KEYWORD,");
	}
	else if(strcmp(received, "union") == 0)
	{
		strcpy(received,"UNION_KEYWORD,");
	}
	else if(strcmp(received, "unsigned") == 0)
	{
		strcpy(received,"UNSIGNED_KEYWORD,");
	}
	else if(strcmp(received, "void") == 0)
	{
		strcpy(received,"VOID_KEYWORD,");
	}
	else if(strcmp(received, "volatile") == 0)
	{
		strcpy(received,"VOLATILE_KEYWORD,");
	}
	else if(strcmp(received, "while") == 0)
	{
		strcpy(received,"WHILE_KEYWORD,");
	}
	else if(strcmp(received, ",") == 0)
	{
		strcpy(received,"COMMA_OPERATE,");
	}
	else if(strcmp(received, "+=") == 0)
	{
		strcpy(received,"ADD_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "-=") == 0)
	{
		strcpy(received,"SUB_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "*=") == 0)
	{
		strcpy(received,"MUL_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "/=") == 0)
	{
		strcpy(received,"DIV_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "%=") == 0)
	{
		strcpy(received,"MOD_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "|=") == 0)
	{
		strcpy(received,"BITOR_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "^=") == 0)
	{
		strcpy(received,"BITXOR_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "&=") == 0)
	{
		strcpy(received,"BITAND_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, ">>=") == 0)
	{
		strcpy(received,"RSHIFRT_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "<<=") == 0)
	{
		strcpy(received,"LSHIFRT_ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "||") == 0)
	{
		strcpy(received,"OR_OPERATE,");
	}
	else if(strcmp(received, "&&") == 0)
	{
		strcpy(received,"AND_OPERATE,");
	}
	else if(strcmp(received, "==") == 0)
	{
		strcpy(received,"EQUAL_OPERATE,");
	}
	else if(strcmp(received, "!=") == 0)
	{
		strcpy(received,"UNEQUAL_OPERATE,");
	}
	else if(strcmp(received, ">=") == 0)
	{
		strcpy(received,"GREATER_EQUAL_OPERATE,");
	}
	else if(strcmp(received, "<=") == 0)
	{
		strcpy(received,"LESS_EQUAL_OPERATE,");
	}
	else if(strcmp(received, "<<") == 0)
	{
		strcpy(received,"RSHIFT_OPERATE,");
	}
	else if(strcmp(received, ">>") == 0)
	{
		strcpy(received,"LSHIFT_OPERATE,");
	}
	else if(strcmp(received, "++") == 0)
	{
		strcpy(received,"INC_OPERATE,");
	}
	else if(strcmp(received, "--") == 0)
	{
		strcpy(received,"DEC_OPERATE,");
	}
	else if(strcmp(received, "->") == 0)
	{
		strcpy(received,"POINT_TO_OPERATE,");
	}
	else if(strcmp(received, "...") == 0)
	{
		strcpy(received,"ELLIPSE_OPERATE,");
	}
	else if(strcmp(received, "!") == 0)
	{
		strcpy(received,"NOT_OPERATE,");
	}
	else if(strcmp(received, "=") == 0)
	{
		strcpy(received,"ASSIGN_OPERATE,");
	}
	else if(strcmp(received, "?") == 0)
	{
		strcpy(received,"QUESTION_OPERATE,");
	}
	else if(strcmp(received, ":") == 0)
	{
		strcpy(received,"COLON_OPERATE,");
	}
	else if(strcmp(received, "|") == 0)
	{
		strcpy(received,"BITOR_OPERATE,");
	}
	else if(strcmp(received, "&") == 0)
	{
		strcpy(received,"BITAND_OPERATE,");
	}
	else if(strcmp(received, "^") == 0)
	{
		strcpy(received,"BITXOR_OPERATE,");
	}
	else if(strcmp(received, ">") == 0)
	{
		strcpy(received,"GREATER_OPERATE,");
	}
	else if(strcmp(received, "<") == 0)
	{
		strcpy(received,"LESS_OPERATE,");
	}
	else if(strcmp(received, "+") == 0)
	{
		strcpy(received,"ADD_OPERATE,");
	}
	else if(strcmp(received, "-") == 0)
	{
		strcpy(received,"SUB_OPERATE,");
	}
	else if(strcmp(received, "*") == 0)
	{
		strcpy(received,"MUL_OPERATE,");
	}
	else if(strcmp(received, "/") == 0)
	{
		strcpy(received,"DIV_OPERATE,");
	}
	else if(strcmp(received, "%") == 0)
	{
		strcpy(received,"MOD_OPERATE,");
	}
	else if(strcmp(received, "~") == 0)
	{
		strcpy(received,"COMP_OPERATE,");
	}
	else if(strcmp(received, ")") == 0)
	{
		strcpy(received,"RPAREN_OPERATE,");
	}
	else if(strcmp(received, "(") == 0)
	{
		strcpy(received,"LPAREN_OPERATE,");
	}
	else if(strcmp(received, "]") == 0)
	{
		strcpy(received,"RBRACKET_OPERATE,");
	}
	else if(strcmp(received, "[") == 0)
	{
		strcpy(received,"LBRACKET_OPERATE,");
	}
	else if(strcmp(received, ".") == 0)
	{
		strcpy(received,"DOT_OPERATE,");
	}
	else if(strcmp(received, "{") == 0)
	{
		strcpy(received,"LBRACE_SEPARATOR,");
	}
	else if(strcmp(received, "}") == 0)
	{
		strcpy(received,"RBRACE_SEPARATOR,");
	}
	else if(strcmp(received, ";") == 0)
	{
		strcpy(received,"SEMICOLON_SEPARATOR,");
	}
	else if(strcmp(received, "#") == 0)
	{
		strcpy(received,"POUND_SEPARATOR,");
	}

	else if(strcmp(received, "character-constant") == 0)
	{
		strcpy(received,"CHAR_CONST,");
	}
	else if(strcmp(received, "enumeration-constant") == 0)
	{
		strcpy(received,"ENUM_CONST,");
	}
	else if(strcmp(received, "floating-constant") == 0)
	{
		strcpy(received,"FLOAT_CONST,");
	}
	else if(strcmp(received, "identifier") == 0)
	{
		strcpy(received,"IDENTIFIER,");
	}
	else if(strcmp(received, "integer-constant") == 0)
	{
		strcpy(received,"INT_CONST,");
	}
	else if(strcmp(received, "string-constant") == 0)
	{
		strcpy(received,"STRING_CONST,");
	}
	else if(strcmp(received, "double-constant") == 0)
	{
		strcpy(received,"DOUBLE_CONST,");
	}
	else if(strcmp(received, "_KULV_END_") == 0)
	{
		strcpy(received,"TOKEN_END,");
	}
	else			// 否则当前信息是语法变量
	{				// 转换为必要的格式
		Setnontermainal(received);
		return 1;
	}
	return 0;
}



