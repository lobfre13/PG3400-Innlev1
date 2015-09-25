#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include "headers/numberList.h"
#include "headers/sorts.h"
char *shortArguments = "mbisq";
struct option longOptions[] = {{"bench", optional_argument, 0,  999}};

bool flush(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
	return true;
}

bool filePathInArgs(char *filePath, int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		if(argv[i][0] != '-' && access(argv[i], F_OK) != -1 ) {
    		memcpy(filePath, argv[i], strlen(argv[i])+1); //including null terminator
    		return true;
    	}
	}
	return false;
}

void askForFilePath(char *filePath, int argc, char *argv[]){
	do{
		printf("Please enter a valid file path: ");
		scanf("%s", filePath);
		flush();
	} while(access(filePath, F_OK) == -1);
}

bool targetInArgs(int *num, int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		if(sscanf(argv[i], "%d", num) == 1) {
	    	return true;
	    }
	}
	return false;
}

//http://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c
void askForTarget(int *num, int argc, char *argv[]){
	char term;
	do{
		printf("Please enter a valid integer to search for: ");
	}while((scanf("%d%c", num, &term) != 2 || term != '\n') && flush());
}

void getFilePath(char *filePath, int argc, char *argv[]){
	if(filePathInArgs(filePath, argc, argv)) return;
	else askForFilePath(filePath, argc, argv);
}

Sort getSortOption(int argc, char *argv[]){
	Sort option = getopt(argc, argv, shortArguments);
	while(option == UNDEFINED){
		printf("Please enter your choice of sorting algorithm:\nm (mergesort)\nb (bubblesort)\ns (selection sort)\ni (insertion sort)\nq (quicksort)\nYour choice: ");
		char i = getchar();
		flush();
		option = (memchr(shortArguments, i, 5) != NULL) ? i : -1;
	}
	return option;

}

int getTarget(int argc, char *argv[]){
	int num;
	if(targetInArgs(&num, argc, argv));
	else askForTarget(&num, argc, argv);
	return num;
}

int benchmarking(int argc, char *argv[], int *argument){
	int c = getopt_long(argc, argv, shortArguments, longOptions, 0);
	optind=1; //reseting getopt
	if(c == 999 && optarg != NULL)
		sscanf(optarg, "%d", argument);
	return c == 999 ? 1 : 0;
}