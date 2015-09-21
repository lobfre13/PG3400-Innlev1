#include "../number.h"
#include <stdbool.h>

void swap(Number *one, Number *two){
   Number tmp = *one;
   *one = *two;
   *two = tmp;
}

bool less(Number one, Number two){
	return one.value < two.value;
}