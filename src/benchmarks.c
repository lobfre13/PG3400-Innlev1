#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/numberList.h"
#include "headers/sorts.h"
#include "headers/colors.h"
#include "headers/staticStrings.h"

double getAverage(int times, Sort sortAlgorithm, char *algorithmName);
double getCurrentTimeInMS ();
void fillListRandom(NumberList *numbers, int count);
void printProgress(int i, int total, char *algorithmName);
void updateProgress(int i, int total, char *algorithmName);

void runBenchmark(int arraySize) {
	printf(BENCHMARK_HEADER);
	getAverage(arraySize, QUICKSORT, "Quicksort");
	getAverage(arraySize, MERGESORT, "Mergesort");
	getAverage(arraySize, INSERTIONSORT, "Insertionsort");
	getAverage(arraySize, SELECTIONSORT, "Selectionsort");
	getAverage(arraySize, BUBBLESORT, "Bubblesort");
}

/*http://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/qnx/clock_gettime.html*/
double getAverage(int arraySize, Sort sortAlgorithm, char *algorithmName) {
	int times = 1000;
	printProgress(0, times, algorithmName);
	double timeEllapsed = 0.0, startTime;
	for (int i = 0; i < times; i++) {
      	static NumberList numbers;
    	initArray(&numbers, 100);
    	fillListRandom(&numbers, arraySize);

    	startTime = getCurrentTimeInMS();
    	sort(sortAlgorithm, &numbers);
		timeEllapsed += getCurrentTimeInMS() - startTime;
		
		if(i % (times/100) == 0) updateProgress(i, times, algorithmName);
		deInitArray(&numbers); 
	}
	updateProgress(times, times, algorithmName);
	timeEllapsed = timeEllapsed / (double)times;
	printf("\033[F\033[43C %.5f ms\n", timeEllapsed);
	return timeEllapsed;
}

void printProgress(int i, int total, char *algorithmName){
	int percent = i/(double)total*100;
	printf("%s:\t%3d%%[", algorithmName, percent);
	for(int i = 0; i < percent/5; i++){
		printf("#");
	}
	for(int i = 0; i < 20-(percent/5); i++){
		printf(" ");
	}
	printf("]\n");
}

void updateProgress(int i, int total, char *algorithmName){
	printf("\033[F\033[J"); //Remove last output line
	printProgress(i, total, algorithmName);
}

/*http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds*/
double getCurrentTimeInMS() {
    return  ((double)clock() / CLOCKS_PER_SEC ) * 1000;
}

void fillListRandom(NumberList *numbers, int count){
	for(int i = 0; i < count; i++){
		addNumber(numbers, rand());
	}
}