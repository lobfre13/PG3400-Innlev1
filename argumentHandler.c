#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "numberList.h"
#include "sortAlgorithms/sorts.h"
void flush(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

Sort getSortOption(int argc, char *argv[]){
	Sort option = getopt(argc, argv, "mbisq");
	while(option == UNDEFINED){
		printf("Please enter your choice of sorting algorithm:\nm (mergesort)\nb (bubblesort)\ns (selection sort)\ni (insertion sort)\nq (quicksort)\nYour choice: ");
		char i = getchar();
		flush();
		option = (memchr("mbisq", i, 5) != NULL) ? i : -1;
	}
	 return option;

}
int benchmarking(int argc, char *argv[], int *argument){
	struct option options[] = {
		{"bench", optional_argument, 0,  'b'}
	};
	int c = getopt_long(argc, argv, "b:", options, 0);
	if(optarg != NULL)
		*argument = *optarg;
	return c == -1 ? 0 : 1;
}
/*http://stackoverflow.com/questions/865284/what-is-the-easiest-way-to-get-an-int-in-a-console-app*/

int getUserInput () {

	int num = 0, nitems = 0;

	for (;;) {

		printf("Please enter the number you wish to search for:");

		nitems = scanf("%d", &num);

			if (nitems == EOF) {

    			printf("Invalid input.\n");

			} else if (nitems == 0) {

    			printf("Invalid input.\n");

			} else {

    			break;

		}

	}

	return num;

}