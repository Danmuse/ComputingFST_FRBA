rm -f *.o output.out
gcc -c -Wall -I include main.c
gcc -c -Wall -I include functions.c
gcc -o output.out main.o functions.o
./output.out
