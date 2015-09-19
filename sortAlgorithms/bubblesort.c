#include <stdio.h>
#include "../number.h"

void bubblesort(int count, Number *array) {
	int swap = 1;
	for (int i = 0; i < count - 1; i++) {
		if (swap == 1) {
			swap = 0;
			for (int j = 0; j < count - 1; j++) {
				if (array[j] < array[j+1]) {
					Number tmp = array[j];
					array[j] = array[j+1];
					array[j+1] = tmp;
					swap = 1;
				} 
			}
		} else {
			return;
		}
	}
}
