SRC = main.c sortAlgorithms/*.c searchAlgorithms/*.c numberList.c argumentHandler.c benchmarks.c
PROG = main
CFLAGS = -Wall -Werror -std=c11 -g
$(PROG): $(SRC)
	gcc $(CFLAGS) $(SRC) -o $(PROG)

