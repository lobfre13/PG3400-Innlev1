//http://geeksquiz.com/merge-sort/
#include <stdio.h>
#include <stdlib.h>
#include "../number.h"
void split(int start, int end, Number *array);
void merge(int start, int end, int mid, Number *array);

void mergesort(int count, Number *array){
	printf("Count: %d\n", count);
	split(0, count-1, array);
	
}

void split(int start, int end, Number *array){
	int size = (end - start) + 1;
	if(size <= 1) return; 
	
	int mid = start+(end-start)/2;
	split(start, mid, array);
	split(mid+1, end, array);
	merge(start, end, mid, array);
}

void merge(int start, int end, int mid, Number *array){
	
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	Number *leftArr = malloc(leftSize * sizeof(Number));
	Number *rightArr = malloc(rightSize * sizeof(Number));

	for(int i = 0; i < leftSize; i++){
		leftArr[i] = array[start+i]; 
	}
	for(int i = 0; i < rightSize; i++){
		rightArr[i] = array[mid+1+i];
	}

	int leftCount = 0, rightCount = 0, orgCount = start;
	while(leftCount < leftSize && rightCount < rightSize){
		if(leftArr[leftCount].value <= rightArr[rightCount].value){
			array[orgCount] = leftArr[leftCount];
			leftCount++;
		}
		else{
			array[orgCount] = rightArr[rightCount];
			rightCount++;
		}
		orgCount++;
	}

	while(leftCount < leftSize){
		array[orgCount] = leftArr[leftCount];
		leftCount++;
		orgCount++;
	}
	while(rightCount < rightSize){
		array[orgCount] = rightArr[rightCount];
		rightCount++;
		orgCount++;
	}

}
