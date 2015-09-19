//https://www.youtube.com/watch?v=y_G9BkAm6B8
#include <stdio.h>
#include <stdlib.h>
#include "../number.h"

void quicksort(int count, Number *array){
	if(count < 2) return;
	Number pivot = array[rand() % count];
	int l = 0, u = count -1;
	while (l < u){
		while(array[l].value < pivot.value){
			l++;
		}
		while(array[u].value > pivot.value){
			u--;
		}
		if (array[l].value == array[u].value)
    		++l;
    	else{
    		Number tmp = array[l];
			array[l] = array[u];
			array[u] = tmp; 
    	}
		
	}
	quicksort(l, array);
	quicksort(count - l - 1, &array[l + 1]);
}
