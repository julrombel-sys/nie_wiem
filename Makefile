CFLAGS = -Wall -Wextra -std=c99 -pedantic
UNAME = $(shell uname -s)
ifeq ($(UNAME),Darwin)
	VALGRIND := leaks --atExit --
else
	VALGRIND := valgrind
endif

test: lmp9
	@for i in $$(ls matr); do echo "$$i:"; ./lmp9 "matr/$$i"; echo "\n"; done

debug: debug_lmp9
	@for i in $$(ls matr); do echo "$$i:"; $(VALGRIND) ./debug_lmp9 "matr/$$i"; echo "\n"; done

override CFLAGS += -O2
lmp9: src/main.o src/mathio.o src/gauss.o src/backsubst.o
	$(CC) $(CFLAGS) -o $@ $^

override CFLAGS += -g -DDEBUG=1
debug_lmp9: src/main.o src/mathio.o src/gauss.o src/backsubst.o
	$(CC) $(DEBUG_CFLAGS) -o $@ $^

clean:
	rm -f src/*.o lmp9 debug_lmp9

src/main.o: src/main.c
src/mathio.o: src/mathio.c src/mathio.h
src/gauss.o: src/gauss.c src/gauss.h
src/backsubst.o: src/backsubst.c src/backsubst.h
