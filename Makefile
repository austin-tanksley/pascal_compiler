#Makefile 
TARGET= lexer
$(TARGET): main.c
	gcc -o lexer main.c machines.c
