enum {
    NOSOLUTIONS = 0,
    ONESOLUTION = 1,
    TWOSOLUTIONS = 2,
    INFINITYSOLUTIONS = 3
};

double discriminant(double a, double b, double c);

void input (double* a, double*b, double* c);

bool compare_two_numbers(double a, double b);

void linear_solution(double b, double c, double* result1, double* result2, int* amount);

void quadratic_solution(double a, double b, double c, double* result1, double* result2, int* amount);

void output(double result1, double result2, int amount);

void clean_stdinput();

void solve(double a, double b, double c, double* result1, double* result2, int* amount);