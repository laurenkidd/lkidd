CC = gcc
CFLAGS = -g -lm -Wall -std=c99
OBJECTS = neighbor.o
all : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o neighbor


neighbor: neighbor.c
	$(CC) $(CFLAGS) -c neighbor.c
