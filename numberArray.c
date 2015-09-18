#include <stdlib.h>
#include "numberArray.h"

int arraySize;
Number *numbers;
int elementCount;

void initArray(int requestedArraySize){
	arraySize = requestedArraySize;
	numbers = malloc(arraySize * sizeof(Number));
}

void addNumber(int number){
	if(elementCount >= arraySize) resizeArray(numbers);
	numbers[elementCount].value = number;
	numbers[elementCount].originalIndex = elementCount;
	elementCount++;
}

void resizeArray(){
	arraySize *= 2;
	numbers = realloc(numbers, arraySize * sizeof(Number));
}