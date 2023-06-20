CC = gcc

INC_DIR = ./inc
BIN_DIR = ./bin
OBJ_DIR = ./obj
SRC_DIR = ./src

CFLAGS = -g -Wall -Wextra -pedantic -I $(INC_DIR)
LDFLAGS = -lm -pthread
TARGET = $(BIN_DIR)/result.out

SOURCES = $(wildcard $(SRC_DIR)/*.c)
HEADERS = $(wildcard $(INC_DIR)/*.h)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: clean all run 

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $^ -o $(TARGET) $(LDFLAGS)

	@# '$<' = '$(SRC_DIR/%c)'
	@# '$@' = '$(OBJ_DIR)/%.o'
	@# '-MD' Generate dependency files

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo $(OBJ_DIR) and $(BIN_DIR) directories removed

run: $(TARGET)
	@$(TARGET)

debug: $(TARGET)
	@gdb -ex "run" ./$(TARGET)

help:
	@echo "Makefile targets:"
	@echo "- make 		Compile the program"
	@echo "- make run 	Execute the program"
	@echo "- make clean	Remove compiled files"
	@echo "- make debug	Debug the program"
