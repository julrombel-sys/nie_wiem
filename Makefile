CFLAGS = -O2 -Wall -Wextra -std=c99 -pedantic

lmp9: src/main.o src/mathio.o src/gauss.o src/backsubst.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f src/*.o lmp9

src/main.o: src/main.c
src/mathio.o: src/mathio.c src/mathio.h
src/gauss.o: src/gauss.c src/gauss.h
src/backsubst.o: src/backsubst.c src/backsubst.h
