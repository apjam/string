CC=gcc -std=c11 -Wall -Wextra -Werror -g
ASAN=#-fsanitize=address -g

all: clean main

main: main.c
	$(CC) $(ASAN) main.c

clean:
	rm -rf *.o main