#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include "numberList.h"
#include "sortAlgorithms/sorts.h"
void flush(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

void getFilePath(char *filePath, int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		if(argv[i][0] != '-' && access(argv[i], F_OK) != -1 ) {
    		memcpy(filePath, argv[i], strlen(argv[i])+1); //including null terminator
    		return;
    	}
	}
	do{
		printf("Please enter a valid file path: ");
		scanf("%s", filePath);
		flush();
	} while(access(filePath, F_OK) == -1);
}

Sort getSortOption(int argc, char *argv[]){
	Sort option = getopt(argc, argv, "mbisq");
	while(option == UNDEFINED){
		printf("Please enter your choice of sorting algorithm:\nm (mergesort)\nb (bubblesort)\ns (selection sort)\ni (insertion sort)\nq (quicksort)\nYour choice: ");
		char i = getchar();
		flush();
		option = (memchr("mbisq", i, 5) != NULL) ? i : -1;
	}
	 return option;

}
//http://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c
int getTarget(int argc,char *argv[]){
	int num;
	for(int i = 1; i < argc; i++){
		if(sscanf(argv[i], "%d", &num) == 1) {
    		return num;
    	}
	}
	printf("Please enter a valid integer to search for: ");
	char term;
	while(scanf("%d%c", &num, &term) != 2 || term != '\n'){
		flush();
		printf("Please enter a valid integer to search for: ");
	}
	return num;
}

int benchmarking(int argc, char *argv[], int *argument){
	struct option options[] = {
		{"bench", optional_argument, 0,  999},
	};
	int c = getopt_long(argc, argv,"mbisq", options, 0);
	optind=1; //reseting getopt
	if(c == 999 && optarg != NULL)
		sscanf(optarg, "%d", argument);
	return c == 999 ? 1 : 0;
}