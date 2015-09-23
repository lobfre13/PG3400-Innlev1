#include <stdlib.h>
#include "../number.h"

void mergesort2(NumberList *numbers){

}


/*void merge(int start, int mid, int end, Number *array){
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

void copyToTmp(int start, int end, Number *array){
	for(int i = start; i <= end; i++){
		tmpArr[i] = array[i]; 
	}
}*/