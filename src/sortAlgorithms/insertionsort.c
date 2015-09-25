#include <stdio.h>
#include "../headers/number.h"
#include "../headers/sortUtilities.h"

void insertionsort(NumberList *numbers) {
	for (int i = 1; i < numbers->count; i++) {
		for (int j = i; j > 0 && less(numbers->array[j], numbers->array[j-1]); j--) {
			swap(&numbers->array[j], &numbers->array[j-1]);
		}
	}
}
