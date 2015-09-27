#include <stdio.h>
#include "../headers/sorts.h"
#include "../headers/staticStrings.h"

void sort(Sort sortOption, NumberList* numbers){
	printf(SORTING_STARTED);
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
 	printf(SORTING_FINISHED);
}