#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "machines.h"


int main(int argc, char *argv[]) {
  int b = 0;
  Token *new = get_token_relop("<=", &b);
  printf("Lexeme: %s\n", new->lex);
  free(new);
  return 0;
}
