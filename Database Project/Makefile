CC = gcc
INC_DIR = include
SRC_DIR = src
BIN_DIR = bin
CFLAGS = -Wall -I $(INC_DIR)

all: app

app: main.o my_string.o database.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)\app main.o my_string.o database.o

main.o: $(SRC_DIR)\main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)\main.c

my_string.o: src\my_string.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)\my_string.c
	
database.o: src\database.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)\database.c

clean:
	rm -f *.o
	rm -f $(BIN_DIR)\app

run:
	$(BIN_DIR)\app
