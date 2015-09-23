#include <stdio.h>
#include "../number.h"

<<<<<<< HEAD
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
=======
void selectionsort(NumberList *numbers){
	printf("selection\n");
>>>>>>> 34e9697e1c3e3736d5efd87e025247387424fb8b
}
