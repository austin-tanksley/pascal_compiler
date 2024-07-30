#Makefile 
TARGET= lexer
$(TARGET): main.c
	cc -o lexer main.c
