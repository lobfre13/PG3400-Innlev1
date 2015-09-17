#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "number.h"
#include "sortAlgorithms/sorts.h"


int arraySize = 100;
Number *numbers;
int elements = 0;
void readFile(char filename[]);
void parseArgs(int argc, char *argv[]);
void resizeArray();

int main(int argc, char *argv[]){
	numbers = malloc(arraySize * sizeof(Number));
	char *filename = argv[1];
	parseArgs(argc, argv);
	readFile(filename);
	
  	
  	return 0;
}

void parseArgs(int argc, char *argv[]){
	int c;
	while ((c = getopt(argc, argv, "mbisq")) != -1){

		switch(c){
        	case 'm':
        		mergesort(elements, numbers);
				break;
			case 'b':
				printf("Bubble Sort\n");
				break;
			case 'i':
				printf("Insertion Sort\n");
				break;
			case 's':
				printf("Selection Sort\n");
				break;
			case 'q':
				printf("Quick Sort\n");
				break;
 		}	
  	}
}

void readFile(char *filename){
	FILE* f = fopen (filename, "r");
	int i = 0;
	do{
		fscanf (f, "%d", &i);
		if(elements >= arraySize) resizeArray(numbers);
		numbers[elements].value = i;
		numbers[elements].originalIndex = elements;
		elements++;
	}while (!feof (f));

	printf("Antall: %d\n", elements);
	printf("siste: %d\n", numbers[elements-1].value);
	printf("Index: %d\n", numbers[elements-1].originalIndex);
	printf("ArrayStørrelse: %d\n", arraySize);
	fclose(f);
}

void resizeArray(){
	arraySize *= 2;
	numbers = realloc(numbers, arraySize * sizeof(Number));
}
