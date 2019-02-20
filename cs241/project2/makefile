test:
	./p2 e "GOODMORNING" data.txt data.en; 
	./p2 d "GOODMORNING" data.en data.de;

encrypt_compare:
	diff -s data.txt data.en
decrypt_compare:
	diff -s data.en data.de;

project:
	gcc -Wall -g ./p2.c ./functions.c -o p2
functions:
	gcc -Wall -g ./functions.c -o functions
clean:
	rm -rf ./p2 ./functions
