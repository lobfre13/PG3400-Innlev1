#include <stdio.h>
#include "headers/numberList.h"
#include "headers/sorts.h"
#include "headers/searches.h"
#include "headers/argumentHandler.h"
#include "headers/staticStrings.h"
#include "headers/staticNumbers.h"
#include "headers/benchmark.h"
#include "headers/streamReader.h"

NumberList numbers;
int benchSize = 1000;

int main(int argc, char *argv[]){
	if(benchmarkFlag(argc, argv, &benchSize)){
		runBenchmark(benchSize);
	} else if (helpFlag()) {
		printf("usage: mbisq [--bench] [--help]\n"); 
		printf("-\n");
		printf("\tmbisq [-m] [-b] [-i] [-s] [-q] [-<some number>]\n");
		//printf("The most commonly used mbisq commands are:\n");
		//printf("\t\n");
	} else {
		initArray(&numbers, ARRAY_INIT_LENGTH);
		char filePath[MAX_PATH_LENGTH];
		getFilePath(filePath, argc, argv);
		readIntsFromFile(filePath, &numbers);
	
		Sort option = getSortOption(argc, argv);
		sort(option, &numbers);
		int target = getTarget(argc, argv);
		int result = binarySearch(&numbers, target);
		if (result == -1) {
			printf(NUMBER_NOT_FOUND, target);
		} else {
			printf(NUMBER_FOUND, target, result);
		}
		deInitArray(&numbers); 
	}
  	return 0;
}