CC = gcc 
SRCS = $(wildcard *.c) 
PROGS = $(patsubst %.c, %, $(SRCS)) 

all: 
	$(PROGS) 

%: %.c 
	$(CC) $(CFLAGS) -o $@.out $< 

clean: 
	rm -f $(PROGS) 
