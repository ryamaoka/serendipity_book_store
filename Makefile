CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = bookType.o bookinfo.o cashier.o invmenu.o reports.o

all:	serendipity
serendipity: main.cpp	bookType.o	bookinfo.o	cashier.o	invmenu.o	reports.o
	$(CC)	$(FLAGS)	main.cpp	-o serendipity	$(OBJS)

bookType.o:	bookType.cpp	bookType.h
	$(CC)	$(FLAGS)	-c	bookType.cpp	-o	bookType.o

bookInfo.o:	bookInfo.cpp	bookInfo.h
	$(CC)	$(FLAGS)	-c	bookInfo.cpp	-o	bookInfo.o

cashier.o:	cashier.cpp	cashier.h
	$(CC)	$(FLAGS)	-c	cashier.cpp	-o	cashier.o

invmenu.o:	invmenu.cpp invmenu.h
	$(CC)	$(FLAGS)	-c	invmenu.cpp	-o	invmenu.o

reports.o:	reports.cpp	reports.h
	$(CC)	$(FLAGS)	-c	reports.cpp	-o	reports.o

clean:
	rm	*.o	serendipity	serendipity.scr	serendipity.tar

tar:
	tar	cf	serendipity.tar	serendipity.scr	Makefile	main.cpp	bookType.cpp	bookType.h	bookInfo.cpp	bookInfo.h	cashier.cpp	cashier.h	invmenu.cpp	invmenu.h	reports.cpp	reports.h	books-1.txt	database-3.txt	linkedList.h	orderedLinkedList.h	outputfile.txt
