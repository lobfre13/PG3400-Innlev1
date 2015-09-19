//http://geeksquiz.com/merge-sort/
#include <stdlib.h>
#include "../number.h"
void split(int start, int end, Number *array);
void merge(int start, int mid, int end, Number *array);
void copyToTmp(int start, int end, Number *array);
Number *tmpArr;

void mergesort(int count, Number *array){
	tmpArr = malloc(count * sizeof(Number));
	split(0, count-1, array);
	free(tmpArr);
}

void split(int start, int end, Number *array){
	if(end - start < 1) return; 
	
	int mid = (end - start) / 2 + start;
	split(start, mid, array);
	split(mid+1, end, array);

	copyToTmp(start, end, array);
	merge(start, mid, end, array);
}

void merge(int start, int mid, int end, Number *array){
	int leftCursor = start, rightCursor = mid+1, destCursor = start;

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

void copyToTmp(int start, int end, Number *array){
	for(int i = start; i <= end; i++){
		tmpArr[i] = array[i]; 
	}
}
