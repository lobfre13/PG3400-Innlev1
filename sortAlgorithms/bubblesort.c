#include <stdio.h>
#include "../number.h"
#include "sortUtilities.h"

void bubblesort(NumberList *numbers) {
	Number *array = (*numbers).array;
	bool swapped;
	do{
		swapped = false;
		for (int j = 0; j < (*numbers).count-1; j++) {
			if(less(array[j+1], array[j])){
				swap(&array[j], &array[j+1]);
				swapped = true;
			}
		}
	}while(swapped);
}