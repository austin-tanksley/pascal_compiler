#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "machines.h"

char* process_line(char* line_in, FILE* log_file, int line_num){
  int  lex_begin = 0;
  char error_message[32];
  Token *token;
  char tok_buf[72] = "";


  fprintf(log_file, "%d %s", line_num, line_in);
  while(line_in[lex_begin] != '\0' && line_in[lex_begin] != '\n' ){
    Status_T status = get_token_relop(line_in, &lex_begin, &token, error_message);
    if (status == SUCCESS){
      //add token to lex_buf
      strcat(tok_buf, token->lex);
      strcat(tok_buf, "\n");
      free(token);
    }else if (status == ERROR){
      fprintf(log_file, "%s\n", error_message);
    }
  }
  char *result = malloc(72);
  if(result != NULL);
    strcpy(result, tok_buf);
  return result;
}
int main(void) {
  FILE *input = fopen("input.txt", "r");
  FILE *tokens_out = fopen("tokens_out.txt", "w");
  FILE *lexer_log = fopen("lexer_log.txt", "w");

  char line_buffer[72];
  int line_num = 0;
  while (fgets(line_buffer, 72, input)){
    char* lex_buf = process_line(line_buffer, lexer_log, line_num);
    if (lex_buf != NULL){
      fprintf(tokens_out, "%s", lex_buf);
      free(lex_buf);
    }
    line_num++;
  }
  fclose(input);
  fclose(tokens_out);
  fclose(lexer_log);
  return 0;
}




