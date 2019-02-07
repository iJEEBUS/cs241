p1: sort.o sort.h p1.o
	gcc -o p1 sort.o p1.o

p1.o: sort.h sort.c p1.c
	gcc -c p1.c

sort.o: sort.h sort.c
	gcc -c sort.c

run:
	./p1
clean:
	rm -f p1 p1.o sort.o

