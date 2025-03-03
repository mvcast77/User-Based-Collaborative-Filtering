CC	= g++
CFLAGS	= -g -Wall
LDFLAGS	=
PROGS	= recommender

all:	$(PROGS)

recommender: recommender.o csr_utility.o
	$(CC) -o $@ $(LDFLAGS) recommender.o csr_utility.o

graph: graph_script.cpp
	$(CC) -o $@ $(LDFLAGS) graph_script.cpp

clean:;	$(RM) $(PROGS) *.o core
