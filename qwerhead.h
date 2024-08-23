//! @file

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#define INT_NAN -214
#define MAX_TRY_COUNT 11

typedef const double cdouble;

enum num_of_solu {
  ZEROs = 0,
  ONEs = 1,
  TWOs = 2,
  INFs = -1,
};


enum solushon{
    DO_TESTS = 1,
    SOLVING = 2,
};


struct equ_coeff{
    double a, b, c;
};

struct test_ans{
    double r_ans1, r_ans2;
    int r_num_of_sol;
};


struct equ{
    struct equ_coeff in_coeff;
    struct test_ans in_ans;
};
         //разделить на две структуры


/**
@brief solve a * x**2 + b * x + c

@param a coeff a
@param b coeff b
@param c coeff c
@param ans1 pointer to first ans
@param ans2 pointer to second ans

@return Number of solutions

@note in case of infitity sol return -1
@note in case 1 sol return answer to ans1

*/

int sol_equ(const struct equ_coeff curr_equ, double *ans1, double *ans2);
int solve_sqrt(cdouble a, cdouble b, cdouble c, double *ans1, double *ans2);
int solve_linear(cdouble b, cdouble c, cdouble *ans1);

int check_r_int();
double check_r_double();



/**@brief reads 3 numbers(a, b, c) from struct test

@param pointer struct test

@note if entered wrong value give 10 attemptions
      if steel wrong, gives an error
*/
void enter_coeff(struct equ_coeff *curr_equl);
double enter_one_coeff(const char *c);

/**@brief print ansvers  depending ofnumber of ans

@param number_of_sol number of solutions
@param first answer
@param second answer

@note if number_of_sol == 1 gives out ans1
*/

void print_ans(const int number_of_sol, const double ans1, const double ans2);
const double E = 1e-12;

void do_all_tests();

int compar_double_with_zero(double num);
int ct_double(double , double); // приписать названия
/**@brief testing


**/
void do_test(const struct equ *curr_test, int);
void print_test_result(_Bool flag, cdouble ans1, cdouble ans2, const struct test_ans * in_coef, int n, int num_of_sol);

