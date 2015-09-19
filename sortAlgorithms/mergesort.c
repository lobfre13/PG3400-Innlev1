#include <stdio.h>
#include "../number.h"
void split(int start, int end, Number *array);
void merge(int start, int end, Number *array);

void mergesort(int count, Number *array){
	printf("Count: %d\n", count);
	split(0, count, array);
}

void split(int start, int end, Number *array){
	int size = end - start;
	printf("Count: %d\t%d\n", start,end);
	if(size <= 1) return;

	split(start, start+(size/2), array);
	split((size/2)+start, end, array);
	merge(start, end, array);

}

void merge(int start, int end, Number *array){
	printf("mergingRange: %d\t%d\n", start,end);
	for(int i = start; i < end; i++){
		if(array[i].value > array[i+1].value){
			int tmp = array[i].value;
			array[i].value = array[i+1].value;
			array[i+1].value = tmp;
		}
	}
}
