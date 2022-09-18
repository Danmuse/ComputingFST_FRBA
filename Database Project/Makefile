CC = gcc
INC_DIR = include
SRC_DIR = src
BIN_DIR = bin
CFLAGS = -Wall -I $(INC_DIR)

all: app

app: main.o database.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/app main.o database.o

main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c
	
database.o: $(SRC_DIR)/database.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/database.c

clean:
	rm -f *.o
	rm -f $(BIN_DIR)/app

run:
	$(BIN_DIR)/app
