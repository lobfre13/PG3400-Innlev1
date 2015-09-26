#ifndef SORTS
#define SORTS

#include "number.h"

typedef enum {
	UNDEFINED = -1,
	MERGESORT = 'm',
	BUBBLESORT = 'b',
	INSERTIONSORT = 'i',
	QUICKSORT = 'q',
	SELECTIONSORT = 's'
}Sort;

void selectionsort(NumberList *numbers);
void bubblesort(NumberList *numbers);
void insertionsort(NumberList *numbers);
void mergesort(NumberList *numbers);
void quicksort(NumberList *numbers);
void sort(Sort sortOption, NumberList* numbers);

#endif