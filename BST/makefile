CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main1

main1: main1.o bst.o binary_tree.o stack_link.o queue_link.o
	$(CC) $(CFLAGS) -o main1 main1.o bst.o binary_tree.o stack_link.o queue_link.o

main1.o: main1.c bst.h
	$(CC) $(CFLAGS) -c main1.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c binary_tree.c

stack_link.o: stack_link.c stack_link.h
	$(CC) $(CFLAGS) -c stack_link.c

queue_link.o: queue_link.c queue_link.h
	$(CC) $(CFLAGS) -c queue_link.c

clean:
	rm -f *.o main1
