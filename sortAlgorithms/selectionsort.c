#include <stdio.h>
#include "../number.h"
#include "sortUtilities.h"

void selectionsort(NumberList *numbers){
	for (int i = 0; i < (*numbers).count-1; i++) {
		int smallestIndex = i;
		for (int j = i+1; j < (*numbers).count; j++) {
			if(less((*numbers).array[j], (*numbers).array[i])){
				smallestIndex = j;
			} 
		}
		if(i != smallestIndex)
			swap(&(*numbers).array[i], &(*numbers).array[smallestIndex]);
	}
}
