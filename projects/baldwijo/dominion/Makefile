CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)	

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

runtests: randomtestcard1 randomtestcard2 randomtestadventurer unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	
	echo "Results for unittest1:" > testresults.out
	./unittest1 >> testresults.out
	echo "Results for unittest2:" >> testresults.out
	./unittest2 >> testresults.out
	echo "Results for unittest3:" >> testresults.out
	./unittest3 >> testresults.out
	echo "Results for unittest4:" >> testresults.out
	./unittest4 >> testresults.out
	echo "Results for cardtest1:" >> testresults.out
	./cardtest1 >> testresults.out
	echo "Results for cardtest2:" >> testresults.out
	./cardtest2 >> testresults.out
	echo "Results for cardtest3:" >> testresults.out
	./cardtest3 >> testresults.out
	echo "Results for cardtest4:" >> testresults.out
	./cardtest4 >> testresults.out
	echo "Results for randomtestcard1:" >> testresults.out
	./randomtestcard1 >> testresults.out
	#gcov dominion.c -bf >> testresults.out
	echo "Results for randomtestcard2:" >> testresults.out
	./randomtestcard2 >> testresults.out
	#gcov dominion.c -bf >> randomtestcard2.out
	echo "Results for randomtestadventurer:" >> testresults.out
	./randomtestadventurer >> testresults.out
	#gcov dominion.c -bf >> randomtestadventurer.out
	echo "**********gcov results***********" >> testresults.out
	gcov dominion.c -bf >> testresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player randomtestcard1 randomtestcard2 randomtestadventurer unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 runtests

clean:
	rm -f *.o randomtestadventurer.exe randomtestadventurer randomtestcard2.exe randomtestcard2 randomtestcard1.exe randomtestcard1 cardtest4.exe cardtest4 cardtest3.exe cardtest3 cardtest2.exe cardtest2 unittest4.exe unittest4 unittest3.exe unittest3 unittest1.exe unittest1 unittest2.exe unittest2 cardtest1.exe cardtest1 playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out 