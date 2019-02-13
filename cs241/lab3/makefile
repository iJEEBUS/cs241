cipher: cipher.o
	gcc -Wall -g cipher.o -o cipher
cipher.o: cipher.c

test: test1 test2
test1:
	./cipher 1 SPOON data.txt data.out
test2:
	./cipher 2 SPOON data.out data.bak

encrypted_compare:
	diff -s data.txt data.out

decrypted_compare:
	diff -s data.txt data.bak
clean:
	rm -rf ./cipher ./cipher.o ./data.out ./data.bak
