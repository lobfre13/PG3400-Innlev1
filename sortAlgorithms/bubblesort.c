#include <stdio.h>
#include "../number.h"

void bubblesort(int count, Number *array) {
	int swap = 1;
	for (int i = 0; i < count - 1; i++) {
		if (swap == 1) {
			swap = 0;
			for (int j = 0; j < count - 1; j++) {
				if (array[j].value < array[j+1].value) {
					int tmp = array[j].value;
					array[j].value = array[j+1].value;
					array[j+1].value = tmp;
					swap = 1;
				} 
			}
		} else {
			return;
		}
	}
}