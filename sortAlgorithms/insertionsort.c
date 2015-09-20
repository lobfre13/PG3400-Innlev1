#include <stdio.h>
#include "../number.h"

void insertionsort(int count, Number *array) {
	for (int i = 1; i < count; i++) {
		for (int j = i; j > 0; j--) {
			if (array[j].value < array[j - 1].value) {
				int tmp = array[j].value;
				array[j].value = array[j - 1].value;
				array[j - 1].value = tmp;
			} else {
				break;
			}
		}
	}
}
