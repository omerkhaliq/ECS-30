connectn.out: connectn.o board.o
	gcc connectn.o board.o -o connectn.out

connectn.o: connectn.c board.c board.h
	gcc -g -Wall -c connectn.c

board.o: board.c connectn.h
	gcc -g -Wall -c board.c

clean: 
	rm *.o connectn.out
