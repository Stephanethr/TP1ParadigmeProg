CC=gcc
CFLAGS=-Wall -Wextra -std=c11

thiryexo1: thiryexo1.o thirylisteint.o
	$(CC) $(CFLAGS) -o thiryexo1 thiryexo1.o thirylisteint.o

thiryexo1.o: thiryexo1.c thirylisteint.h
	$(CC) $(CFLAGS) -c thiryexo1.c

thirylisteint.o: thirylisteint.c thirylisteint.h
	$(CC) $(CFLAGS) -c thirylisteint.c

clean:
	rm -f thiryexo1 thiryexo1.o thirylisteint.o saveliste.bin
