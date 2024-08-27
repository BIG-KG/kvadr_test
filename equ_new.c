#include "qwerhead.h"

int solve_linear(const equ_coeff curr_equ, answers_s * const curr_ans){
	
	assert(curr_ans);
		
	cdouble b = curr_equ.b;
	cdouble c = curr_equ.c;
	
    if(!compar_double_with_zero(b))
            {
                if(!compar_double_with_zero(c)){
                    return INFs;
				}
                else{
                    return ZEROs;
					printf("\nqwertyuiolkjhgfdsdfghjkl\n");
				}
            }
            else
            {
                (curr_ans->ans1) = - c/b;
                return ONEs;
            }
    }

int solve_sqrt(const equ_coeff curr_equ, answers_s * const curr_ans){
	
	assert(curr_ans);	
	
	cdouble a = curr_equ.a;
	cdouble b = curr_equ.b;
	cdouble c = curr_equ.c;	
	
    double D = 0;
    D = (b * b) - (4 * a * c);

    if (!compar_double_with_zero(D) )
    {
        (curr_ans->ans1) = (-b) / (2 * a);
        return ONEs;
    }
    if (D < 0){
        return ZEROs;
	}

    D = sqrt(D);
    (curr_ans->ans1) = (-b - D) / (2 * a);
    (curr_ans->ans2) = (-b + D) / (2 * a);
    return TWOs;
}

int sol_equ( const equ_coeff curr_equ, answers_s *const curr_ans){

	assert(curr_ans);

    if(!compar_double_with_zero(curr_equ.a))
    {			
        return solve_linear(curr_equ, curr_ans);
    }
	
    return (solve_sqrt(curr_equ, curr_ans));
}