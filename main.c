#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "numberArray.h"
#include "sortAlgorithms/sorts.h"

void readFile(char filename[]);
void sort();

extern Number *numbers;
extern int elementCount;


int main(int argc, char *argv[]){
	initArray(100);
	readFile(argv[1]);
	sort(getopt(argc, argv, "mbisq"));

	for(int i = 0; i < elementCount; i++){ 
		printf("Value: %d\torig: %d\n", numbers[i].value, numbers[i].originalIndex);
	}
	//printf("Fant lol: %d\n", binarySearch(elementCount, numbers, 8949));
  	free(numbers);
  	return 0;
}

void sort(int sortOption){
	switch(sortOption){
		case 'b':
			bubblesort(elementCount, numbers);
			break;
		case 'i':
			insertionsort(elementCount, numbers);
			break;
		case 's':
			selectionsort(elementCount, numbers);
			break;
		case 'q':
			quicksort(elementCount, numbers);
			break;
		default:
			mergesort(elementCount, numbers);
			break;
 	}	
}

void readFile(char *filename){
	FILE *f = fopen (filename, "r");
	int i = 0;
	do{
		fscanf (f, "%d", &i);
		addNumber(i);
	}while (!feof (f));
	fclose(f);
}


