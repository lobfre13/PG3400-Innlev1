
void selectionsort(NumberList *numbers);
void bubblesort(NumberList *numbers);
void insertionsort(NumberList *numbers);
void mergesort(NumberList *numbers);
void quicksort(NumberList *numbers);
int binarySearch(NumberList *numbers, int target);
typedef enum {
	MERGESORT = 'm',
	BUBBLESORT = 'b',
	INSERTIONSORT = 'i',
	QUICKSORT = 'q',
	SELECTIONSORT = '1'
}Sort;