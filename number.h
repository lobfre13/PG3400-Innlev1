typedef struct {
	int value;
	int originalIndex;
} Number;

typedef struct {
	Number *array;
	int length;
	int count;
}NumberList;
