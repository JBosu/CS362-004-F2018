CFLAGS= -Wall -std=c99

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)

runfile: testme
	./testme

all: testme runfile

clean:
	rm -f *.o testme testme.exe