#
# Makefile
#


# definitions
CC    = gcc

CFLAG = -O2 

OBJS =  main.o error.o

LIBS =  error.h

TARGET = p2g

.c.o:
	$(CC) $(INCDIR) -c $(CFLAG) $<;

all: p2g

# rules of generations
p2g:  $(OBJS) $(LIBS)
	$(CC) $(CFLAG) -o $@ $(OBJS) ;

main.o: error.h
error.o: error.h 

clean: 
	rm $(OBJS); \
	rm $(TARGET);

