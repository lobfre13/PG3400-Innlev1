#include <stdio.h>
#include "../number.h"
#include "sortUtilities.h"

void bubblesort(int count, Number *array) {
	bool swapped;
	do{
		swapped = false;
		for (int j = 0; j < count - 1; j++) {
			if(less(array[j+1], array[j])){
				swap(&array[j], &array[j+1]);
				swapped = true;
			}
		}
	}while(swapped);
}