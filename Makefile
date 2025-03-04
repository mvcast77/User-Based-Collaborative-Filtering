CC	= g++
CFLAGS	= -g -Wall
LDFLAGS	=
PROGS	= recommender

all:	$(PROGS)

recommender: recommender.o csr_utility.o vector_utility.o
	$(CC) -o $@ $(LDFLAGS) recommender.o csr_utility.o vector_utility.o

clean:;	$(RM) $(PROGS) *.o core
