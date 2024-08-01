#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "machines.h"


int main(void) {
  int b = 0;
  char error_message[32];
  Token *token;

  Status_T status = get_token_relop("=", &b, &token, error_message);
  if (status == SUCCESS){
    printf("Lexeme: %s\n", token->lex);
    free(token);
  }else if (status == ERROR){
    printf("%s\n", error_message);
  }
  return 0;
}


