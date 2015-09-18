typedef struct {
	int value;
	int originalIndex;
} Number;

int arraySize;
Number *numbers;
int elementCount;
void resizeArray();

void initArray(int requestedArraySize){
	arraySize = requestedArraySize;
	numbers = malloc(arraySize * sizeof(Number));
}

void addNumber(int number){
	if(elementCount >= arraySize) resizeArray(numbers);
	numbers[elementCount].value = number;
	numbers[elementCount].originalIndex = elementCount;
	elementCount++;
}

void resizeArray(){
	arraySize *= 2;
	numbers = realloc(numbers, arraySize * sizeof(Number));
}
