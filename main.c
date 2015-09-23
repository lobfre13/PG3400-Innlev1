#include <stdio.h>
#include <stdlib.h>

#include "numberList.h"
#include "sortAlgorithms/sorts.h"
#include "argumentHandler.h"

void readFile(char filename[]);
void sort();

NumberList numbers;

int main(int argc, char *argv[]){
	initArray(&numbers, 100);
	readFile(argv[1]);
	
	Sort option = getSortOption(argc, argv);
	sort(option);
	//for(int i = 0; i < numbers.count; i++){ 
	//	printf("Value: %d\torig: %d\n", numbers.array[i].value, numbers.array[i].originalIndex);
	//}
  	free(numbers.array); 
  	return 0;
}

void sort(Sort sortOption){
	switch(sortOption){
		case BUBBLESORT:
			bubblesort(&numbers);
			break;
		case INSERTIONSORT:
			insertionsort(&numbers);
			break;
		case SELECTIONSORT:
			selectionsort(&numbers);
			break;
		case QUICKSORT:
			quicksort(&numbers);
			break;
		default:
			mergesort(&numbers);
			break;
 	}	
}

void readFile(char *filename){
	FILE *f = fopen (filename, "r");
	int i = 0;
	do{
		fscanf (f, "%d", &i);
		addNumber(&numbers, i);
	}while (!feof (f));
	fclose(f);
}


