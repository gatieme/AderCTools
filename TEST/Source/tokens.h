/* tokens.h code */

#include <stdio.h> 
#include "stream.h"
#define error 0
#define keyword 1
#define spec_symbol 2
#define identifier 3
#define num_constant 41
#define str_constant 42
#define char_constant 43
#define comment 5
#define end 6

typedef
    FILE *token_stream;
typedef   
    char *token;

extern token_stream open_token_stream();
extern token get_token();
extern int print_token();
extern int is_eof_token();
extern int compare_token();


static int token_type();

static int is_spec_symbol(token str);
static int is_token_end(int str_com_id,char ch);
static int unget_error(character_stream *fp);
static int is_keyword(token str);
static int is_identifier(token str);
static int is_num_constant(token str);
static int is_char_constant(token str);
static int is_str_constant(token str);
static int is_comment(token ident);
static void print_spec_symbol(token str);

