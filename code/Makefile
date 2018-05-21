CC=g++
CFLAGS=-Wall

all:	
	bison bis.y
	flex .l
	$(CC)  m.cpp lex.yy.c bis.tab.c -lfl
