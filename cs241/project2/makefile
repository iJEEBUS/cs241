project:
	gcc -Wall -g ./p2.c ./functions.c -o p2
test:
	./p2 e "GOODMORNING" data cipher; 
	./p2 d "GOODMORNING" cipher rdata;
	diff -s data rdata;
clean:
	rm -rf ./p2 ./functions ./cipher ./rdata
