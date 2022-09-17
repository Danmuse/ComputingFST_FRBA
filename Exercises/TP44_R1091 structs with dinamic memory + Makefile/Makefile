CC = gcc
INC_DIR = include
CFLAGS = -Wall -I $(INC_DIR)

all: program

program: TP44.o student.o
	$(CC) TP44.o student.o -o app.out

TP44.o: TP44.c
	$(CC) $(CFLAGS) -c TP44.c
	
student.o: student.c
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f *.o
	rm -f app.out

run:
	app.out
