#include <stdio.h>
#include <stdlib.h>
#include "numberList.h"
#include "sortAlgorithms/sorts.h"
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void readFile(char filename[], NumberList* numbers);
double getAverage(int times, Sort sortAlgorythm);
double getCurrentTimeInMS ();
void sort();

void benchmark (int times) {
	printf("%s%f\n%s%f\n%s%f\n%s%f\n%s%f\n", "Merge sort: " , getAverage(times, MERGESORT),
		"Insertion sort: " , getAverage(times, INSERTIONSORT) ,
		"Selection sort: " , getAverage(times, SELECTIONSORT) ,
		"Bubble sort: " , getAverage(times, BUBBLESORT) ,
		"Quicksort: " , getAverage(times, QUICKSORT)
		);
}

/*http://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/qnx/clock_gettime.html*/
double getAverage (int times, Sort sortAlgorythm) {
	
	fprintf(stderr, ANSI_COLOR_CYAN"%c: %%[", sortAlgorythm);
	double timeEllapsed = 0.0, start = 0.0, stop = 0.0;
	for (int i = 0; i < times; i++) {
      	NumberList numbers;
    	initArray(&numbers, 100);
		readFile("resources/1.txt", &numbers);

    	start = getCurrentTimeInMS();

    	sort(sortAlgorythm, &numbers);
      	stop = getCurrentTimeInMS();
		
		timeEllapsed += (stop - start);
		free(numbers.array); 
		if(i % (times/20) == 0)
			fprintf(stderr, "#");
	}
	fprintf(stderr, "]\n");
	return timeEllapsed / (double)times;
}

/*http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds*/
double getCurrentTimeInMS () {
    return  ((float)clock() / 1000000.0F ) * 1000;
}