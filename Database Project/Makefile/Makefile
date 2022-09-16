CC = gcc
INC_DIR = include
CFLAGS = -Wall -I $(INC_DIR)
SRC_DIR = src
BIN_DIR = bin

all: file_main
file_main: main.o my_string.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/file_main main.o my_string.o

main.o: src/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

my_string.o: src/my_string.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/util.c

clean:
	rm -f *.o
	rm -f file_main

run:
	$(BIN_DIR)/file_main
