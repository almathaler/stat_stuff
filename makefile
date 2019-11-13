ifeq ($(DEBUG), true)
CC = gcc -g
else
CC = gcc
endif

all: stat_stuff.o
	$(CC) -o program stat_stuff.o
stat_stuff.o: stat_stuff.c
	$(CC) -c stat_stuff.c
clean:
	rm *.o
	rm program

run:
	./program
