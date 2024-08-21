//! @file
//! head файл объ€вление дл€ квадратных уравнений


#ifndef QWERHEAD_H_INCLUDED
#define QWERHEAD_H_INCLUDED

/**
@brief solve a * x**2 + b * x + c\

@param a coeff a
@param b coeff b
@param c coeff c
@param ans1 pointer to first ans
@param ans2 pointer to second ans

@return Number of solutions

@note in case of infitity sol return -1
@notein case 1 sol return answer to ans1

*/

int sol_squrt(double a, double b, double c, double *ans1, double *ans2);


/**@brief reads 3 numbers

@param pointer to a
@param pointer to b
@param pointer to c

@note if entered wrong value give 10 attemptions
      if steel wrong, gives an error
*/
void enter_coeff(double *a, double *b, double *c);

/**@brief gives out ansvers  depending ofnumber of ans

@param number_of_sol number of solutions
@param first answer
@param second answer

@note if number_of_sol == 1 gives out ans1
*/

void return_ans(const int number_of_sol, const double ans1, const double ans2);
const double E = 1e-12;  // this is krivo!!!    // this is krivo!!!

int srav_doble(double num);

char do_test(struct test *curr_test);


#endif // QWERHEAD_H_INCLUDED
