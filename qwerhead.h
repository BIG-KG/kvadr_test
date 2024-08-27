//! @file
#ifndef QWER_MAIN_HEADER
#define QWER_MAIN_HEADER

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#define INT_NAN -214
#define MAX_TRY_COUNT 11

//!@brief new type cdouble because of frequent use of (const double)
typedef const double cdouble;
//typedef const cint;


//!@brief minimum difference between double numbers in wich they are taken as equal
const double E = 0.000001;

//!@brief constants denote number of solutions
enum num_of_solu {
  ZEROs = 0,
  ONEs = 1,
  TWOs = 2,
  INFs = -1,
};

void print_double_num(const char* a, cdouble f, int end);

//!@brief make decision to program between making UNITtests and solving equals
enum solution{
    DO_TESTS = 1,
    SOLVING = 2,
};

//!@brief struct in wich  coeff to equaluation
struct equ_coeff{
    double a, b, c;
};

//!@brief struct in wich anwers to test
struct test_ans{
    double r_ans1, r_ans2;
    int r_num_of_sol;
};

struct answers_s{
    double ans1, ans2;
    int num_of_sol;
};

//!@brief struct in wich contain full info about equaluation to UNITtest
struct equ{
    struct equ_coeff in_coeff;
    struct test_ans  in_ans;
	struct answers_s curr_ans;
};


/**
@brief solve a * x**2 + b * x + c = 0
	Solving a * x**2 + b * x + c. Ansvers vrites to variables with addresses double *ans1 and ans2.
	Return int number of ansvers
	
@param double a coeff a
@param double b coeff b
@param double c coeff c
@param double *ans1 pointer to first ans
@param double *ans2 pointer to second ans

@return Number of solutions

@note in case of infitity sol return -1
@note in case 1 sol return answer to ans1
@note for the solution it calls either solve_linear or solve_sqrt depending on the equation 
@see solve_sqrt()
@see solve_linear()

*/
int sol_equ( const equ_coeff curr_equ, answers_s *curr_ans);

/**
@brief solve a * x**2 + b * x + c = 0
	Solving a * x**2 + b * x + c. Ansvers vrites to variables with addresses double *ans1 and ans2.
	Return int number of ansvers


@param double a 
@param double b 
@param double c 
@param double *ans1 
@param double *ans2 

@return Number of solutions

@note in case 1 sol return answer to ans1

*/
int solve_sqrt(const equ_coeff curr_equ, answers_s *curr_ans);

/**
@brief solve b * x + c = 0 or special case 0 * x**2 + b * x + c = 0
	Solving b * x + c. Ansvers vrites to variable with addresse double *ans1
	Return int number of ansvers
	
@param double b coeff b
@param double c coeff c
@param double *ans1 pointer to first ans

@return Number of solutions

@note in case of infitity sol return -1
*/
int solve_linear(const equ_coeff curr_equ, answers_s *curr_ans);

/**
@brief Check for right entering int number.
	Checks if (int) number was entered right. If in enterng data has error giv 11 trys to enter again.
	Returns int number wich was entered. 
	

@return int out 

@note Go to ERROR if after 11 attempts nuber still not entered.
@note  Works only with stdin.
*/
int check_r_int();

/**
@brief Check for right entering double number.
	Checks if (double) number was entered right. If in enterng data has error giv 11 trys to enter again.
	Returns doube number wich was entered. 
	

@return double out 

@note Go to ERROR if after 11 attempts nuber still not entered.
@note  Works only with stdin.
*/
double check_r_double(const char *printing_string);



/**@brief reads 3 numbers(a, b, c) from struct test

@param pointer struct test

@note if entered wrong value give 10 attemptions
      if steel wrong, gives an error
*/
void enter_coeff(struct equ_coeff *curr_equl);

/**@brief Reads and returns double number. Before the introduction, the line located at the pointer C is written.  Use check_r_double.

@param const char *c 
	Pointer on start of string wich need to be printed before scanned number.
	
@return doube - entered number

@note If entered wrong value give 10 attemptions
      If steel wrong, gives out error
	  

/**
@brief Print ansvers(ans1, ans2) depending of number_of_sol
	In case num_of_sol == 1, prints ans1
	and in case num_of_sol == 2. prints ans1 and ans2.

@param const int number_of_sol number of solutions
@param const double ans1 first answer
@param const double ans2 second answer

@note if number_of_sol == 1 gives out only ans1
*/
void print_ans(const answers_s curr_ans);

/**
@brief Doing all unit-tests. Using do_test


@see do_test 
*/
void do_all_tests();

/**
@brief compares a (double)num with zero.

@param double num 

@return int
	if number equals zero return 1, 0 otherwise.
@note if the absolute value of a number is less than E, the function considers it 0.

@see E
*/
int compar_double_with_zero(double num);

/**
@brief compares two double nombers.

@param double num1
@param double num2

@return int
	if num1 == num2 return 1, 0 otherwise.
@note if the difference between the numbers is less than E, the numbers are considered the same.

@see E
*/
int ct_double(double , double);

/**@brief Substitutes parameters passed by (struct equ *)curr_test into solve_equ and compares with answers received from (struct equ *)curr_test.
	Using sol_equ, print_test_result.
@param const struct equ *curr_test
	Pointer to struct with answers for test end eualuation coefficents.
@param n - number of current test

@see sol_equ() print_test_result()

**/
void do_test(struct equ *curr_test, const int n);

void print_test_result(_Bool flag, const equ *curr_test, const int n);

#endif