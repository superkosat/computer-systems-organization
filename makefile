CC = gcc
CFLAGS = -Wall -std=c99

child:
	$(CC) $(CFLAGS) child.c -o child
run:
	$(CC) $(CFLAGS) child.c -o child
	$(CC) $(CLFAGS) parent.c -o parent
	parent

clean:
	rm -f parent child