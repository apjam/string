CC=gcc -std=c11 -Wall -Wextra -Werror -g 
ASAN=#-fsanitize=address

all: clean main

main: main_tests.c
	$(CC) $(ASAN) main_tests.c tests/part_1.c s21_sprintf.c `pkg-config --cflags --libs check`


clean:
	rm -rf *.o main