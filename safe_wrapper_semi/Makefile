# Makefile for C-Minus Scanner
# ./lex/tiny.l --> ./cminus.l

CC = gcc 

CFLAGS = -W -Wall

OBJS = cminus.tab.o lex.yy.o main.o util.o

.PHONY: all clean
all: cminus_parser

clean:
	-rm -vf cminus_parser *.o lex.yy.c cminus.tab.c cminus.tab.h $(OBJS)

cminus_parser: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lfl

main.o: main.c globals.h util.h scan.h parse.h
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h globals.h
	$(CC) $(CFLAGS) -c util.c

lex.yy.o: cminus.l scan.h util.h globals.h
	flex -o lex.yy.c cminus.l
	$(CC) -c lex.yy.c

cminus.tab.o: cminus.y
	bison -d -v cminus.y
	$(CC) -c cminus.tab.c

