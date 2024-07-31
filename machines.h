#ifndef _MACHINES_H_
#define _MACHINES_H_

typedef struct{
  int line_number;
  char lex[32];
  int tok;
  int att;
} Token;

typedef struct {
  int current_state;
  int next_char;
  char lexeme[32];
} SM_Machine_Info;

Token* get_token_relop(char str_in[], int *lexeme_beginning);

#endif // !_MACHINES_H_
