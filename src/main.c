#include <stdio.h>
#include "headers/numberList.h"
#include "headers/sorts.h"
#include "headers/argumentHandler.h"

void readFile(char filename[], NumberList* numbers);
void sort(Sort sortOption, NumberList* numbers);
void runBenchmark(int arraySize);

NumberList numbers;
int benchSize = 1000;
int main(int argc, char *argv[]){
	if(benchmarkFlag(argc, argv, &benchSize)){
		printf("Benchmark average of a thousand sorts:\n");
		runBenchmark(benchSize);
	}
	else {
		initArray(&numbers, 100);
		char filePath[260];
		getFilePath(filePath, argc, argv);
		readFile(filePath, &numbers);
	
		Sort option = getSortOption(argc, argv);
		sort(option, &numbers);
		int target = getTarget(argc, argv);
		int result = binarySearch(&numbers, target);
		if (result == -1) {
			printf("Did not find number %d in the selected file.\n", target);
		} else {
			printf("Found number %d in index %d.\n", target, result);
		}
		deInitArray(&numbers); 
	}
  	return 0;
}

void sort(Sort sortOption, NumberList* numbers){
	switch(sortOption){
		case BUBBLESORT:
			bubblesort(numbers);
			break;
		case INSERTIONSORT:
			insertionsort(numbers);
			break;
		case SELECTIONSORT:
			selectionsort(numbers);
			break;
		case QUICKSORT:
			quicksort(numbers);
			break;
		default:
			mergesort(numbers);
			break;
 	}	
}

void readFile(char *filename, NumberList* numbers){
	FILE *f = fopen (filename, "r");
	int i = 0;
	do{
		if(fscanf(f, "%d", &i) == 1){ //read int
			addNumber(numbers, i);
		}
		else fscanf(f, "%*c"); //eat chars
	}while(!feof (f));
	fclose(f);
}


