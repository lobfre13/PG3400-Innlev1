#include <stdlib.h>
#include "CuTest.h"
#include "../src/argumentHandler.c"

char *tmpFile = "temptestfiletemptestfile.txt";
FILE *tmp;

void createTmpFile(){
    tmp = fopen (tmpFile, "w+");
}
void rmTmpFile(){
    fclose(tmp);
    unlink(tmpFile);
}
    
void testFilePathInArgs(CuTest *tc) {
    createTmpFile();
    char *filePath = calloc(260, sizeof(char));
    char *argv[] = {
        "testing",
        tmpFile
    };
    CuAssertIntEquals(tc, true, filePathInArgs(filePath, 2, argv));
    rmTmpFile();
    free(filePath);
}

void testFilePathInArgs_invalidPath(CuTest *tc){
    char *filePath = calloc(260, sizeof(char));
    char *argv[] = {
        "testing",
        tmpFile
    };
    CuAssertIntEquals(tc, false, filePathInArgs(filePath, 2, argv));
    free(filePath);
}

/*
* This test failed if infinite loop 
*/
void testAskForFilePath(CuTest *tc){
    createTmpFile();
    fprintf(tmp, "%s\n", tmpFile); 
    char *filePath = calloc(260, sizeof(char)); 
    
    fclose(tmp);
    tmp = fopen(tmpFile, "r");

    CuAssertStrNotEquals(tc, tmpFile, filePath);
    askForFilePath(filePath, tmp);

    CuAssertStrEquals(tc, tmpFile, filePath);
    rmTmpFile();
    free(filePath);
}
   
CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testFilePathInArgs);
    SUITE_ADD_TEST(suite, testFilePathInArgs_invalidPath);
    SUITE_ADD_TEST(suite, testAskForFilePath);
    return suite;
}
