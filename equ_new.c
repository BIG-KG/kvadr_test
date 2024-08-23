
#include "qwerhead.h"





int solve_linear(cdouble b, cdouble c, double *otv){
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


int solve_sqrt(cdouble a, cdouble b, cdouble c, double *otv1, double *otv2){
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


int sol_equ(const struct equ_coeff curr_equ, double *otv1, double *otv2){
    cdouble a = curr_equ.a;
    cdouble b = curr_equ.b;
    cdouble c = curr_equ.c;
    *otv1 = NAN;
    *otv2 = NAN;
    if(!compar_double_with_zero(a))
    {
        return solve_linear(b, c, otv1);
    }

    return solve_sqrt(a, b, c, otv1, otv2);

}
