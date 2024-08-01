#include "machines.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

Status_T get_token_relop(char str_in[], int *lexeme_beginning, Token **new, char *error_message){
  SM_Machine_Info sm;
  sm.current_state = 0;
  strncpy(sm.lexeme, "", 32);
  sm.next_char = *lexeme_beginning;

  *new = malloc(sizeof(Token));
  if (new == NULL)
    return ERROR;
  while(1){
    switch (sm.current_state) {
      //State Machine Start
      case 0: {
        if      (str_in[sm.next_char] == '<') {sm.current_state = 1; sm.next_char++; strcat(sm.lexeme, "<");}
        else if (str_in[sm.next_char] == '=') {sm.current_state = 5; sm.next_char++; strcat(sm.lexeme, "=");}
        else if (str_in[sm.next_char] == '>') {sm.current_state = 6; sm.next_char++; strcat(sm.lexeme, ">");}
        else {
          strncpy(error_message, "Error: not a relop", 32);
          sm.next_char++;
          *lexeme_beginning = sm.next_char;
          return ERROR;
        }
        break;
      }
      case 1: {
        if      (str_in[sm.next_char] == '=') {sm.current_state = 2; sm.next_char++; strcat(sm.lexeme, "=" );}
        else if (str_in[sm.next_char] == '>') {sm.current_state = 3; sm.next_char++; strcat(sm.lexeme, ">" );}
        else    {sm.current_state = 4;}
        break;
      }
      case 2 ... 5: {
        strncpy((*new)->lex, sm.lexeme, 32);
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
      case 6: {
        if   (str_in[sm.next_char] == '=') {sm.current_state = 7; sm.next_char++; strcat(sm.lexeme, "=");}
        else {sm.current_state = 8;}
      }
      case 7 ... 8: {
        strncpy((*new)->lex, sm.lexeme, 32);
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
    }
  }
}
