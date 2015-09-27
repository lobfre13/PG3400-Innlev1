//http://geeksquiz.com/merge-sort/
#include <stdlib.h>
#include <string.h>
#include "../headers/number.h"
void split(int start, int end, Number *array);
void merge(int start, int mid, int end, Number *array);
Number *tmpArr;

void mergesort(NumberList *numbers){
	tmpArr = malloc(numbers->count * sizeof(Number));
	split(0, numbers->count-1, numbers->array);
	free(tmpArr);
}

void split(int start, int end, Number *array){
	if(end - start < 1) return; 
	
	int mid = (end - start) / 2 + start;
	split(start, mid, array);
	split(mid+1, end, array);

	memcpy(&tmpArr[start], &array[start], ((end - start) + 1) * sizeof(Number));
	merge(start, mid, end, array);
}

void merge(int start, int mid, int end, Number *array){
	int leftCursor = start;
	int rightCursor = mid+1; 
	int destCursor = start;

	while(leftCursor <= mid && rightCursor <= end){
		if(tmpArr[leftCursor].value <= tmpArr[rightCursor].value){
			array[destCursor++] = tmpArr[leftCursor++];
		}
		else{
			array[destCursor++] = tmpArr[rightCursor++];
		}
	}

	while(leftCursor <= mid){
		array[destCursor++] = tmpArr[leftCursor++];
	}
	while(rightCursor <= end){
		array[destCursor++] = tmpArr[rightCursor++];
	}

}
