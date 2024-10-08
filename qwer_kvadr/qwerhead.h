//! @file


struct equ{
    double a, b, c, r_ans1, r_ans2;
    int r_num_of_sol;


};



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

int sol_squrt(struct equ curr_equ, double *otv1, double *otv2);


/**@brief reads 3 numbers(a, b, c) from struct test

@param pointer struct test

@note if entered wrong value give 10 attemptions
      if steel wrong, gives an error
*/
void enter_coeff(struct equ *curr_equl);

/**@brief print ansvers  depending ofnumber of ans

@param number_of_sol number of solutions
@param first answer
@param second answer

@note if number_of_sol == 1 gives out ans1
*/

void return_ans(const int number_of_sol, const double ans1, const double ans2);
const double E = 1e-12;

int compar_double(double num);
int ct_double(double, double);
/**@brief testing

**/
void do_test(struct equ *curr_test, int);


