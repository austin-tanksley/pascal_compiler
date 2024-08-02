#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char lexeme[32];
    char token_str[32];
    int token_int;
    char att_str[32];
    int att_int;
} token;

#define MAX_TOKENS 48

int main(void){
    token tokens[MAX_TOKENS];

    char buffer[72];
    FILE* in = fopen("reserved_words.txt", "r");
    if (in == NULL){
        perror("Error opening file");
        return 1;
    }

    int index=0;
    while(fgets(buffer, 72, in) && index < MAX_TOKENS){
        sscanf(buffer, "%32s %32s %d %32s %d",
        tokens[index].lexeme,
        tokens[index].token_str,
        &tokens[index].token_int,
        tokens[index].att_str,
        &tokens[index].att_int);
        index++;
    } 
    fclose(in);

     for (int i = 0; i < index; i++) {
        printf("\033[1;32mToken %2d: \033[0;34mLexeme: \033[0m%10s\t \033[0;34mtoken_str: \033[0m%10s\t \033[0;34mtoken_int: \033[0m%2d\t \033[0;34matt_str: \033[0m%6s    \033[0;34matt_int: \033[0m%d\n", i, tokens[i].lexeme,
        tokens[i].token_str, tokens[i].token_int, tokens[i].att_str, tokens[i].att_int);
    }

    return 0;
}