SRC = main.c sortAlgorithms/*.c numberArray.c
PROG = main
CFLAGS = -Wall -Werror -std=c11
$(PROG): $(SRC)
	gcc $(CFLAGS) $(SRC) -o $(PROG)

