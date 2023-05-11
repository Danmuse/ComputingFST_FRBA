gcc -Wall -pedantic -c server.c client.c sock-lib.c
gcc server.o sock-lib.o -o server.out -lm -lpthread
gcc client.o sock-lib.o -o client.out -lm -lpthread