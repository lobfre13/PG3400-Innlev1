#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "numberList.h"
#include "sortAlgorithms/sorts.h"
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

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
	unsigned long timeEllapsed = 0, start = 0, stop = 0;
	for (int i = 0; i < times; i++) {
      NumberList numbers;
    	initArray(&numbers, 100);
		  readFile("resources/3.txt", &numbers);

    	start = getCurrentTimeInMS();

    	sort(sortAlgorythm, &numbers);
      stop = getCurrentTimeInMS();
		
		  timeEllapsed += stop - start;
		  free(numbers.array); 
	}
	return timeEllapsed / (unsigned long)times;
}

/*http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds*/
double getCurrentTimeInMS () {
    struct timespec spec;
    clock_gettime(CLOCK_MONOTONIC, &spec);
    return spec.tv_nsec / 1000000L/* / 1.0e6*/; // Convert nanoseconds to milliseconds
}