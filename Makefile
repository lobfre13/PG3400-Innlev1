SRC = src/main.c\
src/sortAlgorithms/*.c\
src/searchAlgorithms/*.c\
src/numberList.c\
src/argumentHandler.c\
src/benchmarks.c\
src/streamReader.c
PROG = main
CFLAGS = -Wall -Werror -std=c11 -g
$(PROG): $(SRC)
	gcc $(CFLAGS) $(SRC) -o $(PROG)

