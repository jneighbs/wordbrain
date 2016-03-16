CC = cc
IDIR = .
CFLAGS = -Wall -g -I$(IDIR)

# TODO: create a 'make clean' rule

solver: solver.o tree.o utilities.o cell.o
	$(CC) -o solver solver.o tree.o utilities.o cell.o $(CFLAGS)
