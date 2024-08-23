#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include "qwerhead.h"

#define INT_NAN -2147483648
#define MAX_TRY_COUNT 11



int solve_linear(double b, double c, double *otv){
    if(!compar_double_with_zero(b))
            {
                if(!compar_double_with_zero(c))
                    return INFs;
                else
                    return ZEROs;
            }
            else
            {
                *otv = - c/b;
                return ONEs;
            }
    }


int solve_sqrt(double a, double b, double c, double *otv1, double *otv2){
    double D = 0;
    D = (b * b) - (4 * a * c);

    if (!compar_double_with_zero(D) )
    {
        *otv1 = (-b) / (2 * a);
        return ONEs;
    }
    if (D < 0)
        return ZEROs;


    D = sqrt(D);
    *otv1 = (-b - D) / (2 * a);
    *otv2 = (-b + D) / (2 * a);
    return TWOs;
}


int sol_equ(struct equ_coeff curr_equ, double *otv1, double *otv2){
    double a = curr_equ.a, b = curr_equ.b, c = curr_equ.c;
    *otv1 = NAN;
    *otv2 = NAN;
    if(!compar_double_with_zero(a))
    {
        return solve_linear(b, c, otv1);
    }

    return solve_sqrt(a, b, c, otv1, otv2);

}
