CC = gcc 
SRCS = $(wildcard *.c) 
PROGS = $(patsubst %.c, %, $(SRCS)) 

all: 
	$(PROGS) 

%: %.c 
	$(CC) $(CFLAGS) -o $@.o $< 

clean: 
	rm -f $(PROGS) 
