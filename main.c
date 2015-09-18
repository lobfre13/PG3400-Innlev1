#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "numberArray.h"
#include "sortAlgorithms/sorts.h"

void readFile(char filename[]);
void parseArgs(int argc, char *argv[]);


int main(int argc, char *argv[]){
	initArray(100);
	char *filename = argv[1];
	parseArgs(argc, argv);
	readFile(filename);
	
  	
  	return 0;
}

void parseArgs(int argc, char *argv[]){
	int c;
	if ((c = getopt(argc, argv, "mbisq")) != -1){

		switch(c){
        	case 'm':
        		sort = MERGESORT;
				break;
			case 'b':
				sort = BUBBLESORT;
				break;
			case 'i':
				sort = INSERTIONSORT;
				break;
			case 's':
				sort = SELECTIONSORT;
				break;
			case 'q':
				sort = QUICKSORT;
				break;
 		}	
  	}
}

void readFile(char *filename){
	FILE *f = fopen (filename, "r");
	int i = 0;
	do{
		fscanf (f, "%d", &i);
		addNumber(i);
	}while (!feof (f));
	fclose(f);
}


