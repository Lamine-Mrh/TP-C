CC = gcc
CFLAGS = -Wall -pedantic -Wfatal-errors

expression: binary_tree.o expression.o queue_link.o
	$(CC) $(CFLAGS) -o expression binary_tree.o expression.o queue_link.o

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c binary_tree.c

expression.o: expression.c binary_tree.h queue_link.h
	$(CC) $(CFLAGS) -c expression.c

queue_link.o: queue_link.c queue_link.h binary_tree.h
	$(CC) $(CFLAGS) -c queue_link.c

clean:
	rm -f *.o expression
