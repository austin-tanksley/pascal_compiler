#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "machines.h"
#include "globals.h"

//White space
void remove_white_space(char str_in[], int *lexeme_beginning){
  SM_Machine_Info sm;
  sm.current_state = 0;
  strncpy(sm.lexeme, "", 32);
  sm.next_char = *lexeme_beginning;
  while(1){
    switch(sm.current_state){
      case 0: {
        char c = str_in[sm.next_char];
        if (c == ' ' || c == '\t' || c == '\n'){
          sm.current_state = 0;
          sm.next_char++;
        } else {
          *lexeme_beginning = sm.next_char;
          return;
        }
        break;
      }
    }
  }
}

//Relop
Status_T get_token_relop(char str_in[], int *lexeme_beginning, Token **new, char *error_message){
  SM_Machine_Info sm;
  sm.current_state = 0;
  strncpy(sm.lexeme, "", 32);
  sm.next_char = *lexeme_beginning;

  *new = malloc(sizeof(Token));
  if (new == NULL){
    return ERROR;
  }
  while(1){
    switch (sm.current_state) {
      //State Machine Start
      case 0: {
        if      (str_in[sm.next_char] == '<') {sm.current_state = 1; sm.next_char++; strcat(sm.lexeme, "<");}
        else if (str_in[sm.next_char] == '=') {sm.current_state = 5; sm.next_char++; strcat(sm.lexeme, "=");}
        else if (str_in[sm.next_char] == '>') {sm.current_state = 6; sm.next_char++; strcat(sm.lexeme, ">");}
        else {
          *lexeme_beginning = sm.next_char;
          return FAIL;
        }
        break;
      }
      case 1: {
        if      (str_in[sm.next_char] == '=') {sm.current_state = 2; sm.next_char++; strcat(sm.lexeme, "=" );}
        else if (str_in[sm.next_char] == '>') {sm.current_state = 3; sm.next_char++; strcat(sm.lexeme, ">" );}
        else    {sm.current_state = 4;}
        break;
      }
      case 2: {
        strncpy((*new)->lex, sm.lexeme, 32);
        (*new)->tok = RELOP;
        (*new)->att = LTE;
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
      case 3: {
        strncpy((*new)->lex, sm.lexeme, 32);
        (*new)->tok = RELOP;
        (*new)->att = NE;
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
      case 4: {
        strncpy((*new)->lex, sm.lexeme, 32);
        (*new)->tok = RELOP;
        (*new)->att = LT;
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
      case 5: {
        strncpy((*new)->lex, sm.lexeme, 32);
        (*new)->tok = RELOP;
        (*new)->att = EQ;
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
      case 6: {
        if   (str_in[sm.next_char] == '=') {sm.current_state = 7; sm.next_char++; strcat(sm.lexeme, "=");}
        else {sm.current_state = 8;}
        break;
      }
      case 7: {
        strncpy((*new)->lex, sm.lexeme, 32);
        (*new)->tok = RELOP;
        (*new)->att = GTE;
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
      case 8: {
        strncpy((*new)->lex, sm.lexeme, 32);
        (*new)->tok = RELOP;
        (*new)->att = GT;
        *lexeme_beginning = sm.next_char;
        return SUCCESS;
        break;
      }
    }
  }
}
