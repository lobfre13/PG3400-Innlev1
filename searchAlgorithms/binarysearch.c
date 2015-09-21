#include <stdio.h>
#include "../number.h"

void binarySearch(int count, Number *array, int target) {
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
}