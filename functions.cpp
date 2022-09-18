#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "functions.h"

double discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

void input (double* a, double* b, double* c) {
    assert(a != NULL && b != NULL && c != NULL);

    printf("Enter coefficients a, b, c: "); 
    int n = scanf("%lf %lf %lf", a, b, c); 

    while (n != 3) {
        clean_stdinput();

        printf("Wrong input try again\n");
        n = scanf("%lf %lf %lf", a, b, c);
    }
}

bool compare_two_numbers(double a, double b) {
    double epsilon = 0.00001;
    if (fabs(a - b) <= epsilon) {
        return true;

    }   else { 
        return false;
    }
}

void linear_solution(double b, double c, double* result1, double* result2, int* amount) { 
    assert(result1 != NULL && result2 != NULL && amount != NULL);

    *result1 = -c / b;
    *result2 = *result1; 

    *amount = ONESOLUTION;
}

void quadratic_solution(double a, double b, double c, double* result1, double* result2, int* amount) {
    assert(result1 != NULL && result2 != NULL && amount != NULL);

    double d = discriminant(a, b, c);
    double doubleA = 2 * a;

    if (d > 0.0) {
        double sqrtD = sqrt(d);

        *result1 = (-b + sqrtD) / doubleA; 
        *result2 = (-b - sqrtD) / doubleA;

        *amount = TWOSOLUTIONS;

    }   else if (compare_two_numbers(d, 0.0)) { 
        *result1 = -b / doubleA;
        *result2 = *result1;

        *amount = ONESOLUTION;

    }   else {
        *amount = NOSOLUTIONS;
    }
}

void output(double result1, double result2, int amount) { 
    switch (amount) {
    case NOSOLUTIONS: 
        printf("No solutions\n"); 
        break;

    case ONESOLUTION: 
        printf("X = %lf\n", result1); 
        break;

    case TWOSOLUTIONS: 
        printf("X1 = %lf\n", result1); 
        printf("X2 = %lf\n", result2); break;
                                            
    case INFINITYSOLUTIONS: 
        printf("Infinity solutions\n"); 
        break;

    default:
        printf("Wrong amount of solutions\n");
        break;
    }
}

void clean_stdinput() {
    int s = getchar();
    while (s != EOF && s != '\n') {
        s = getchar();
    }

}

void solve(double a, double b, double c, double* result1, double* result2, int* amount) { 
    assert(result1 != NULL && result2 != NULL && amount != NULL);
        
    if (compare_two_numbers(a, 0.0) && !compare_two_numbers(b, 0.0)) {
        linear_solution(b, c, result1, result2, amount);

    }   else if (compare_two_numbers(a, 0.0) && compare_two_numbers(b, 0.0) && compare_two_numbers(c, 0.0)) {
        *amount = INFINITYSOLUTIONS;

    }   else if (compare_two_numbers(b, 0.0) && compare_two_numbers(a, 0.0)) {
        *amount = NOSOLUTIONS;

    }   else {
        quadratic_solution(a, b, c, result1, result2, amount);
    }  
}
