#include "machines.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

Token* get_token_relop(char str_in[], int *lexeme_beginning){
  SM_Machine_Info sm;
  sm.current_state = 0;
  sm.next_char = *lexeme_beginning;

  Token* new = malloc(sizeof(Token));
  if (new == NULL)
    return NULL;
  while(1){
    switch (sm.current_state) {
      //State Machine Start
      case 0: {
        if      (str_in[sm.next_char] == '<') {sm.current_state = 1; sm.next_char++; strcat(sm.lexeme, "<");}
        else if (str_in[sm.next_char] == '=') {sm.current_state = 5; sm.next_char++; strcat(sm.lexeme, "=");}
        else if (str_in[sm.next_char] == '>') {sm.current_state = 6; sm.next_char++; strcat(sm.lexeme, ">");}
        else    {return NULL;} //return null here with no changes, passing along to next machine
        break;
      }
      case 1: {
        if      (str_in[sm.next_char] == '=') {sm.current_state = 2; sm.next_char++; strcat(sm.lexeme, "=" );}
        else if (str_in[sm.next_char] == '>') {sm.current_state = 3; sm.next_char++; strcat(sm.lexeme, ">" );}
        else    {sm.current_state = 4; sm.next_char++;}
        break;
      }
      case 2 ... 5: {
        strncpy(new->lex, sm.lexeme, 32);
        *lexeme_beginning = sm.next_char++;
        return new;
        break;
      }
    }
  }
}
