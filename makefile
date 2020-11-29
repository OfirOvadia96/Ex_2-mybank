CC = gcc
FLAGS = -Wall -g


all: mybanks mains

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

libmyBank.a: myBank.o myBank.h
	ar -rcs libmyBank.a myBank.o
	
mybanks: libmyBank.a

mains: main.o mybanks 
	$(CC) $(FLAGS) -o mains main.o libmyBank.a
	
	
.PHONY: clean all mybanks

clean: 
	rm -f *.o *.a mains
