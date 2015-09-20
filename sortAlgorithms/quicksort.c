// https://www.youtube.com/watch?v=aQiWF4E8flQ
#include <stdio.h>
#include <stdlib.h>
#include "../number.h"
void swap(Number *a, Number *b);

void quicksort(int count, Number *array){
	if(count < 2) return;

	Number pivot = array[count-1];
	int wall = -1;
	for(int i = 0; i < count-1; i++){
		if(array[i].value <= pivot.value){
			swap(&array[++wall], &array[i]);
		} 
	}
	swap(&array[++wall], &array[count-1]);
	
	quicksort(count-(count - wall), array);
	quicksort(count-wall, &array[count-(count - wall)]);
}

void swap(Number *a, Number *b){
   Number tmp = *a;
   *a = *b;
   *b = tmp;
}    
