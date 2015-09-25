#include <stdlib.h>
#include "headers/numberList.h"

void initArray(NumberList *numbers, int length){
	numbers->length = length;
	numbers->array = malloc(numbers->length * sizeof(Number));
	numbers->count = 0;
}

void addNumber(NumberList *numbers, int number){
	if(numbers->count >= numbers->length) resizeArray(numbers);
	numbers->array[numbers->count].value = number;
	numbers->array[numbers->count].originalIndex = numbers->count;
	numbers->count++;
}

void resizeArray(NumberList *numbers){
	numbers->length *= 2;
	numbers->array = realloc(numbers->array, numbers->length * sizeof(Number));
}

void deInitArray(NumberList *numbers){
	free(numbers->array);
	numbers->array = NULL;
	numbers->count = 0;
	numbers->length = 0;
}