#include <stdio.h>
#include "headers/numberList.h"

void readInts(FILE *inputStream, NumberList* numbers){
	int i = 0;
	do{
		if(fscanf(inputStream, "%d", &i) == 1){ //read int
			addNumber(numbers, i);
		}
		else fscanf(inputStream, "%*c"); //eat chars
	}while(!feof (inputStream));
}

void readIntsFromFile(char *filename, NumberList* numbers){
	FILE *f = fopen (filename, "r");
	readInts(f, numbers);
	fclose(f);
}