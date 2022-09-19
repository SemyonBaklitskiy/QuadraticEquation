#include <stdio.h>

/*!
	\brief This function cleans extra spaces (' ') and '\n' in testing file
	\param[in] FILE* file - pointer to struct FILE (pointer to testing file)
	\param[out] int* check - pointer to variable check

	\code 
	void clean_spaces_in_file (FILE* file, int* check) {
        assert(file != NULL);
        assert(check != NULL);

        do {
            *check = getc(file);
        } while ((*check != '\n') && (*check != EOF));
    }
	\endcode
*/

void clean_spaces_in_file (FILE* file, int* check);

/*!
	\brief This function reads data from file lines
	\param[in] FILE* file - pointer to struct FILE (pointer to testing file)
	\param[out] double* abc - array[3] of coefficients a, b, c
	\param[out] double* expectedResults - array[2] of expected solutions
	\param[out] int* expectedAmount - pointer to variable which stands for expected number of solutions
	\param[out] int* check - pointer to variable check

	\code 
	void read_file(FILE* file, double* abc, double* expectedResults, int* expectedAmount, int* check) {
        assert(file != NULL);
        assert(abc != NULL);
        assert(expectedResults != NULL);
        assert(expectedAmount != NULL);
        assert(check != NULL);
        assert(abc != expectedResults);
        assert(expectedAmount != check);

        fscanf(file, "%lf %lf %lf", abc, abc + 1, abc + 2); 

        char s = ' '; 
        fscanf(file, " %c", &s);

        switch (s) { 
        case '0': 
            *expectedAmount = NOSOLUTIONS; 
            break;

        case 'i': 
            *expectedAmount = INFINITYSOLUTIONS; 
            break;

        case '1': 
            fscanf(file, "%lf", expectedResults); 
            *(expectedResults + 1) = *expectedResults;

            *expectedAmount = ONESOLUTION;
            break;

       case '2': 
            fscanf(file, "%lf %lf", expectedResults, expectedResults + 1); 

            *expectedAmount = TWOSOLUTIONS;
            break;
    
        default: 
            printf("Wrong symbol in file!\n");
            assert(0);
            break;
        }   

        clean_spaces_in_file(file, check);
    }
	\endcode
*/

void read_file(FILE* file, double* abc, double* expectedResults, int* expectedAmount, int* check);

/*!
	\brief This function compares expected results from the testing file with results got by function solve
	\param[in] const char* name - name of testing file

	\code
    void test(const char* name) {
        assert(name != NULL);

        FILE* file = fopen(name, "r");

        if (file == NULL) {
            printf("File wasn`t open\n");
            return;
        }

        int check = 0;
        int count = 1;

        while (check != EOF) {
            double abc[3];
            int expectedAmount = NOSOLUTIONS;
            double expectedResults[2];

            read_file(file, abc, expectedResults, &expectedAmount, &check);

            double result1 = 0.0, result2 = 0.0;
            int amount = NOSOLUTIONS;

            solve(abc[0], abc[1], abc[2], &result1, &result2, &amount);

            if (expectedAmount == ONESOLUTION) {
                if (amount == expectedAmount) {
                    if (compare_two_numbers(result1, expectedResults[0])) {
                        printf("Test %d OK!\n", count);

                    }   else {
                        printf("Test %d wrong answer. Expected %lf, but got %lf\n", count, expectedResults[0], result1);
                    }

                }   else {
                    printf("Test %d wrong amount. Expected %d, but got %d\n", count, expectedAmount, amount);
                }

            }   else if (expectedAmount == TWOSOLUTIONS) {
                if (amount == expectedAmount) {
                    if ((compare_two_numbers(expectedResults[0], result1) && compare_two_numbers(expectedResults[1], result2)) ||
                        (compare_two_numbers(expectedResults[0], result2) && compare_two_numbers(expectedResults[1], result1))) {
                        printf("Test %d OK!\n", count);

                    }   else {
                        printf("Test %d wrong answer. Expected %lf %lf, but got %lf %lf\n", count, expectedResults[0], expectedResults[1], result1, result2);
                    }

                }   else {
                    printf("Test %d wrong amount. Expected %d, but got %d\n", count, expectedAmount, amount);
                }

            }   else if (expectedAmount == NOSOLUTIONS) {
                if (amount == expectedAmount) {
                    printf("Test %d OK!\n", count);

                }   else {
                    printf("Test %d wrong amount. Expected %d, but got %d\n", count, expectedAmount, amount);
                }

            }   else {
                if (amount == expectedAmount) {
                    printf("Test %d OK!\n", count);

                }   else {
                    printf("Test %d wrong amount. Expected %d, but got %d\n", count, expectedAmount, amount);
                }
            }

            ++count;
        }

        fclose(file);

    }
    \endcode
*/

void test(const char* name);
