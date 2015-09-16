#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int file[200000];
void readFile(char filename[]);
void parseArgs(int argc, char *argv[]);

int main(int argc, char *argv[]){
	char *filename = argv[1];
	readFile(filename);
	parseArgs(argc, argv);
  	
  	return 0;
}

void parseArgs(int argc, char *argv[]){
	int c;
	while ((c = getopt(argc, argv, "mbisq")) != -1){

		switch(c){
        	case 'm':
        		printf("Merge Sort\n");
				break;
			case 'b':
				printf("Bubble Sort\n");
				break;
			case 'i':
				printf("Insertion Sort\n");
				break;
			case 's':
				printf("Selection Sort\n");
				break;
			case 'q':
				printf("Quick Sort\n");
				break;
 		}	
  	}
}

void readFile(char filename[]){
	FILE* f = fopen (filename, "r");
	int i = 0;
	int cursor = 0;
	do{
		fscanf (f, "%d", &i);
		file[cursor] = i;
		cursor++;
	}while (!feof (f));

	printf("Antall: %d\n", cursor);
	printf("siste: %d\n", file[cursor-1]);
	fclose(f);
}
