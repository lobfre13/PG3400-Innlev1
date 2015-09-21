// https://www.youtube.com/watch?v=aQiWF4E8flQ
#include <stdio.h>
#include <stdlib.h>
#include "../number.h"
#include "sortUtilities.h"

void quicksort(int count, Number *array){
	if(count < 2) return;

	Number pivot = array[count-1];
	int wall = -1;
	for(int i = 0; i < count-1; i++){
		if(array[i].value <= pivot.value){
			swap(&array[++wall], &array[i]);
		} 
	}
	swap(&array[++wall], &array[count-1]); //Place pivot in final place

	int rightCount = count - wall;
	int leftCount = count - rightCount;
	quicksort(leftCount, array); //Sort left side of pivot
	quicksort(rightCount, &array[leftCount]); //Sort right side of pivot
} 
