CFLAGS = -Wall -Wextra -std=c11 -O2
EXEC = lmp9
FILES = src/main.c src/mathio.c src/backsubst.c src/gauss.c

all: $(EXEC)

$(EXEC): $(FILES)
	$(CC) $(CFLAGS) -o $(EXEC) $(FILES)
