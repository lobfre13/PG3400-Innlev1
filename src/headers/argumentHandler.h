#ifndef ARGUMENTHANDLER
#define ARGUMENTHANDLER
#include <stdbool.h>

char *getFilePath(char *filePath, int argc, char *argv[]);
Sort getSortOption(int argc, char *argv[]);
int getTarget(int argc,char *argv[]);
bool benchmarkFlag(int argc, char *argv[], int *argument);
bool helperFlag(int argc, char *argv[]);

#endif