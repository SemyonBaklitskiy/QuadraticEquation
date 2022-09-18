#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#ifdef TEST
    #include "test.h"
#endif

int main() {
#ifdef TEST 
    char* name = NULL;
    printf("Enter file name to test (or enter D to use default test file (tests.txt)): ");
    scanf("%ms[\n]", &name);

    if (name[0] == 'D') {
        test("tests.txt");

    }   else {
        test(name);
    }

    free(name);

#else
    double a = 0.0, b = 0.0, c = 0.0;  

    input(&a, &b, &c);

    double result1 = 0.0, result2 = 0.0;
    int amount = NOSOLUTIONS;

    solve(a, b, c, &result1, &result2, &amount);

    output(result1, result2, amount);
#endif

    return 0;
}