all: chessviz

chessviz: main.o
	gcc main.o -o chessviz

main.o: main.c
	gcc -Wall -Werror -c main.c

clean:
	rm -rf *.o chessviz
