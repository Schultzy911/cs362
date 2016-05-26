CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

tests: unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o cardtest4.o

unittest1.o: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2.o: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3.o: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4.o: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1.o: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2.o: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3.o: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4.o: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	unittest1 >> unittestresults.out
	unittest2 >> unittestresults.out
	unittest3 >> unittestresults.out
	unittest4 >> unittestresults.out
	cardtest1 >> unittestresults.out
	cardtest2 >> unittestresults.out
	cardtest3 >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
