/// enum type 1
enum {
    NOSOLUTIONS = 0, ///< parameter NOSOLUTIONS = 0 (if equation has no solutions)
    ONESOLUTION = 1, ///< parameter ONESOLUTION = 1 (if equation has one solution)
    TWOSOLUTIONS = 2, ///< parameter TWOSOLUTIONS = 2 (if equation has two solutions)
    INFINITYSOLUTIONS = 3 ///< parameter INFINITYSOLUTIONS = 3 (if equation has infinity solutions)
};

/*!
    \brief This function calculates discriminant

    \param[in] double a - corresponding coefficients a of the quadratic equation 
    \param[in] double b - corresponding coefficients b of the quadratic equation
    \param[in] double c - corresponding coefficients c of the quadratic equation
    \return double number - result of the discriminant
    
    This function calculate discriminant using formula: b^2 - 4 * a * c 

    \code
    double discriminant(double a, double b, double c) {
        return b * b - 4 * a * c;
    }
    \endcode
*/

double discriminant(double a, double b, double c);

/*!
    This function inputs coefficients a, b, c from stdinput and assign a value to them 

    \param[out] double* a - pointer to a corresponding coefficients a of the quadratic equation
    \param[out] double* b - pointer to a corresponding coefficients b of the quadratic equation
    \param[out] double* c - pointer to a corresponding coefficients c of the quadratic equation

    \code
    void input (double* a, double* b, double* c) {
        assert(a != NULL);
        assert(b != NULL);
        assert(c != NULL);
        assert(a != b);
        assert(a != c);
        assert(b != c);

        printf("Enter coefficients a, b, c: "); 
        int n = scanf("%lf %lf %lf", a, b, c); 

        while (n != 3) {
            clean_stdinput();

            printf("Wrong input try again\n");
            n = scanf("%lf %lf %lf", a, b, c);
        }
    }
    \endcode
*/

void input (double* a, double* b, double* c);

/*!
    \brief This function compares with each other two double numbers a and b

    \param[in] double a - first number
    \param[in] double b - second number 

    \return true - if |a - b| <= 0.00001
    \return false - else

    This function compares with each other two double numbers a and b
    and returns TRUE if the difference is smaller or equals than 0.00001
    in absolute value, FALSE in other case

    \code
    bool compare_two_numbers(double a, double b) {
        double epsilon = 0.00001;
        if (fabs(a - b) <= epsilon) {
            return true;

        }   else { 
            return false;
        }
    }
    \endcode
*/

bool compare_two_numbers(double a, double b);

/*!
    \brief This function finds solution in linear case
    \param[in] double b - corresponding coefficients b of the quadratic equation
    \param[in] double c - corresponding coefficients c of the quadratic equation
    \param[out] double* result1 - pointer to a variable which stands for first result
    \param[out] double* result2 - pointer to a variable which stands for second result 
    \param[out] int* amount - pointer to a variable which stand for number of solutions of quadratic equation

    This finction finds solution in linear case (a = 0) and assign a value to *result1, *result2 and assign number of them to *amount

    \code 
    void linear_solution(double b, double c, double* result1, double* result2, int* amount) { 
        assert(result1 != NULL);
        assert(result2 != NULL);
        assert(amount != NULL);
        assert(result1 != result2);

        *result1 = -c / b;
        *result2 = *result1; 

        *amount = ONESOLUTION;
    }
    \endcode
*/

void linear_solution(double b, double c, double* result1, double* result2, int* amount);

/*!
    \brief This function finds solution in quadratic case
    \param[in] double a - corresponding coefficients b of the quadratic equation
    \param[in] double b - corresponding coefficients b of the quadratic equation
    \param[in] double c - corresponding coefficients c of the quadratic equation
    \param[out] double* result1 - pointer to a variable which stands for first result
    \param[out] double* result2 - pointer to a variable which stands for second result
    \param[out] int* amount - pointer to a variable which stand for number of solutions of quadratic equation

    This finction finds solution in quadratic case (a != 0) and assign a value to *result1, *result2 and assign number of them to *amount

    \code 
    void quadratic_solution(double a, double b, double c, double* result1, double* result2, int* amount) {
        assert(result1 != NULL);
        assert(result2 != NULL);
        assert(amount != NULL);
        assert(result1 != result2);

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
    \endcode
*/

void quadratic_solution(double a, double b, double c, double* result1, double* result2, int* amount);

/*!
    This function outputs solutions result1, result2 and number of them to stdoutput

    \param[in] double result1 - first solution
    \param[in] double b - second solution
    \param[in] int c - number of the solutions

    \code
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
    \endcode
*/

void output(double result1, double result2, int amount);

/*!
    \brief This function cleans stdinput if input was wrong

    \code
    void clean_stdinput() {
        int s = getchar();
        while (s != EOF && s != '\n') {
            s = getchar();
        }

        return;
    }
    \endcode
*/

void clean_stdinput();

/*!
    \brief This function solves the qudratic equation
    \param[in] double a - corresponding coefficients b of the quadratic equation
    \param[in] double b - corresponding coefficients b of the quadratic equation
    \param[in] double c - corresponding coefficients c of the quadratic equation
    \param[out] double* result1 - pointer to a variable which stands for first result
    \param[out] double* result2 - pointer to a variable which stands for second result
    \param[out] int* amount - pointer to a variable which stand for number of solutions of quadratic equation

    void solve(double a, double b, double c, double* result1, double* result2, int* amount) { 
        assert(result1 != NULL);
        assert(result2 != NULL);
        assert(amount != NULL);
        assert(result1 != result2);
        
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
    \endcode
*/

void solve(double a, double b, double c, double* result1, double* result2, int* amount);