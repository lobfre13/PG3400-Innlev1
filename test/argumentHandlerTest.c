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

void testAskForFilePath(CuTest *tc){
    createTmpFile();
    fprintf(tmp, "%s\n", tmpFile); 
    char *filePath = calloc(260, sizeof(char)); 
    fclose(tmp);
    tmp = fopen(tmpFile, "r");

    askForFilePath(filePath, tmp); 

    CuAssertStrEquals(tc, tmpFile, filePath);
    rmTmpFile();
    free(filePath);
}

void testTargetInArgs(CuTest *tc){
    char *argv[] = {
        "testing",
        tmpFile,
        "42"
    };
    int num = 0;
    CuAssertIntEquals(tc, true, targetInArgs(&num, 3, argv));
    CuAssertIntEquals(tc, 42, num);
}

void testTargetInArgs_notSupplied(CuTest *tc){
    char *argv[] = {
        "testing",
        tmpFile
    };
    int num = 0;
    CuAssertIntEquals(tc, false, targetInArgs(&num, 2, argv));
}

CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testFilePathInArgs);
    SUITE_ADD_TEST(suite, testFilePathInArgs_invalidPath);
    SUITE_ADD_TEST(suite, testAskForFilePath);
    SUITE_ADD_TEST(suite, testTargetInArgs);
    SUITE_ADD_TEST(suite, testTargetInArgs_notSupplied);
    return suite;
}
