#include <stdio.h>
#include "../number.h"
#include "sortUtilities.h"

void insertionsort(int count, Number *array) {
	for (int i = 1; i < count; i++) {
		for (int j = i; j > 0 && less(array[j], array[j-1]); j--) {
			swap(&array[j], &array[j-1]);
		}
	}
}
