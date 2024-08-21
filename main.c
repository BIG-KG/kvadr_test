#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "qwerhead.h"

#define min(a,b) (a) < (b) ? (a) : (b)

enum {
  ZEROs = 0,   //?
  ONEs = 1,
  TWOs = 2,
  INFs = -1,
};


struct test
    {
            double a;
            double b;
            double c;
            double ans1;
            double ans2;
            double r_ans1;
            double r_ans2;
            int num_of_sol;
            int r_num_of_sol;

    };


int main(){

    struct test tests[1];

    tests->a = 1;
    tests->b = -11;
    tests->c = 30;
    tests->r_ans1 = 5;
    tests->r_ans2 = 6;
    tests->r_num_of_sol = 2;

    char t = do_test(tests);

    printf("%d", t);











}

int sol_squrt(const double a, const double b, const double c, double *otv1, double *otv2){
    double D = 0;

    if(!srav_doble(a) && srav_doble(b) && srav_doble(c)){   // this is krivo!!!{
        *otv1 = - c/b;
        return ONEs;}
    if(!srav_doble(a) && !srav_doble(b) && !srav_doble(c))   // this is krivo!!!
        return INFs;
    if(!srav_doble(a) && srav_doble(b) && srav_doble(c))
        return ZEROs;


    D = (b * b) - (4 * a * c);

    if (D < 0)
        return ZEROs;
    if (!srav_doble(D) )
    {
        *otv1 = (-b) / (2 * a);
        return ONEs;
    }
    else
    {
        D = sqrt(D);
        *otv1 = (-b - sqrt(D)) / (2 * a);
        *otv2 = (-b + sqrt(D)) / (2 * a);
        return TWOs;
    }
}


void enter_coeff(double *a, double *b, double *c){
    assert(a && b && c);
    *a = NAN;
    *b = NAN;
    *c = NAN;


    int right_enter = 1;
    int try_count = 11;
    do{
        printf("a * x**2 + b * x + c = 0\n");
        printf("\nenter a = ");
        right_enter = min(scanf("%lf", a), right_enter);

        printf("\nenter b = ");
        right_enter = min(scanf("%lf", b), right_enter);

        printf("\nenter c = ");
        right_enter = min(scanf("%lf", c), right_enter);

        if (right_enter == 0){
            printf("\n\nERROR: entered wrong value, try again.\n\n");
            scanf("%*s");
        }

       try_count--;


    }while(right_enter == 0 && try_count >0);


    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));

}


void return_ans(const int number_of_sol, const double ans1, const double ans2 ){
    switch(number_of_sol)
        {
        case (ZEROs):
            printf("there is 0 solutions\n");
            break;
        case (ONEs):
            printf("there is 1 solution %lg\n", ans1);
            break;
        case (TWOs):
            printf("there is 2 solution %lg, %lg\n", ans1, ans2);
            break;
        case (INFs):
            printf("any R\n");
            break;
        default:
            printf("Error");
        }
}


int srav_doble(double num){
    if (fabs(num) > E)
        return 1;
    else
        return 0;
}

char do_test(struct test *curr_test){
    curr_test->num_of_sol = sol_squrt (curr_test->a, curr_test->b, curr_test->c,
    &curr_test->ans1, &curr_test->ans2);

    if(curr_test->num_of_sol == curr_test->r_num_of_sol &&
        curr_test->ans1 == curr_test->r_ans1 &&
        curr_test->ans2 == curr_test->r_ans2){
        return 1;

       }
    else{
        printf("phignia");
        return 0;
    }

}
