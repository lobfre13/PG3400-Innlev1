#include <stdio.h>
#include "../number.h"

void selectionsort(int count, Number *array){
	for (int i = 0; i < count; i++) {
		Number smallestIndex = array[i];
		for (int j = i; j < count; j++) {
			if (array[j].value < smallestIndex.value) {
				smallestIndex = array[j];
			} 
		}
		Number tmp = array[i];
		array[i] = smallestIndex;
		
	}
}
