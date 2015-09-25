#include <stdlib.h>
#include "CuTest.h"
#include "../src/argumentHandler.c"

void testGetFilePath(CuTest *tc){
    
}
    
    
void testFilePathInArgs(CuTest *tc) {
    char* input = "hello world";
    char* actual = StrToUpper(input);
    char* expected = "HELLO WORLD";
    CuAssertStrEquals(tc, expected, actual);
}
   
CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestStrToUpper);
    return suite;
}
