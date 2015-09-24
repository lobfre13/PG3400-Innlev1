#include <stdio.h>
#include "../number.h"
Number* binarySearch2(int count, Number *array, int target);

/*void binarySearch(int count, Number *array, int target) {
	int splitPoint = count;
	while (array[splitPoint].value != target) {
		if (array[splitPoint].value < target) {

		} else {

		}
	}



	for (int i = 0; i < count; i++) {
		splitPoint = splitPoint / 2;
		if (array[splitPoint] == target) {
			break;
		} else if (array[splitPoint] > target) {

		} else if (array[splitPoint] < target) {

		}
	}
}*/
int binarySearch(NumberList *numbers, int target) {
	Number *num = binarySearch2((*numbers).count, (*numbers).array, target);
	return num - (*numbers).array;
	
}

Number* binarySearch2(int count, Number *array, int target) {
	if(count < 2) return &array[-1];
	int middle = count / 2;
	if(array[middle].value == target) return &array[middle]; 
	if(array[middle].value > target) return binarySearch2(count - middle, array, target);
	else return binarySearch2(count - middle, &array[middle+1], target);
}