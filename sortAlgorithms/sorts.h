#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selectionsort.h"

typedef enum {MERGESORT, QUICKSORT, SELECTIONSORT, BUBBLESORT, INSERTIONSORT} Sorts;
Sorts sort;

void selectionsort(int count, Number *array);
void bubblesort(int count, Number *array);
void insertionsort(int count, Number *array);
void mergesort(int count, Number *array);
void quicksort(int count, Number *array);
