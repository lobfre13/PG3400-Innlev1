#include "../headers/number.h"

//https://en.wikipedia.org/wiki/Binary_search_algorithm
int b_Search(Number *numbers, int start, int end, int target) {
	if(end - start < 0) return -1;
	int middle = (end - start) / 2 + start;
	
	if(numbers[middle].value == target) return middle;
	if(numbers[middle].value > target) return b_Search(numbers, start, middle-1, target);
	return b_Search(numbers, middle+1, end, target);
}

int binarySearch(NumberList *numbers, int target) {
	return b_Search(numbers->array, 0, numbers->count-1, target);
}

