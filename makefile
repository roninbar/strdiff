
CC = gcc
CFLAGS  = -Wall -g -I ~/projects -D __USE_POSIX

all: mystrdiff multistrdiff a b

a:  a.o mystrlib.o
	$(CC) $(CFLAGS) -o a a.o mystrlib.o

a.o:  a.c mystrlib.h
	$(CC) $(CFLAGS) -c a.c

b:  b.o mystrlib.o
	$(CC) $(CFLAGS) -o b b.o mystrlib.o

b.o:  b.c mystrlib.h
	$(CC) $(CFLAGS) -c b.c

mystrdiff:  mystrdiff.o mystrlib.o
	$(CC) $(CFLAGS) -o mystrdiff mystrdiff.o mystrlib.o

multistrdiff:  multistrdiff.o mystrlib.o
	$(CC) $(CFLAGS) -o multistrdiff multistrdiff.o mystrlib.o

mystrdiff.o:  mystrdiff.c mystrlib.h
	$(CC) $(CFLAGS) -c mystrdiff.c

mystrlib.o:  mystrlib.c mystrlib.h 
	$(CC) $(CFLAGS) -c mystrlib.c

clean: 
	rm -f mystrdiff multistrdiff a b c *.o

