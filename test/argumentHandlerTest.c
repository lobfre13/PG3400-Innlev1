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
    char filePath[260];
    char *argv[] = {
        "testing",
        tmpFile
    };
    CuAssertIntEquals(tc, true, filePathInArgs(filePath, 2, argv));
    rmTmpFile();
}

void testFilePathInArgs_invalidPath(CuTest *tc){
    char filePath[260];
    char *argv[] = {
        "testing",
        tmpFile
    };
    CuAssertIntEquals(tc, false, filePathInArgs(filePath, 2, argv));
}

void testAskForFilePath(CuTest *tc){
    createTmpFile();
    fprintf(tmp, "%s\n", tmpFile); 
    char filePath[260]; 
    fclose(tmp);
    tmp = fopen(tmpFile, "r");
    //askForFilePath(filePath, tmp);

    CuAssertStrEquals(tc, tmpFile, filePath);
    //createTmpFile();
    rmTmpFile();

}
/*void testFile2PathInArgs(CuTest *tc) {
    char* input = "hello world";
    //char* actual = StrToUpper(input);
    char* expected = "HELLO WORLD";
    CuAssertStrEquals(tc, expected, actual);
}*/
   
CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testFilePathInArgs);
    SUITE_ADD_TEST(suite, testFilePathInArgs_invalidPath);
    SUITE_ADD_TEST(suite, testAskForFilePath);
    return suite;
}
