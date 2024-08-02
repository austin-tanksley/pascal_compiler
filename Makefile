#Makefile
lexer: main.c machines.c
	gcc -o lexer main.c machines.c
