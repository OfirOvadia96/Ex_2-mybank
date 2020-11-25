FLAGS = -Wall -g
CC = gcc

all: mains
	
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
#create statc libary
libmyBank.a: myBank.o myBank.h
	ar -rcs libmyBank.a myBank.o main.o

mybank: libmyBank.a

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libBank.a
	

.PHONY: clean all

clean:
	rm -f *.o *.a mains
