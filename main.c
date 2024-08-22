#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include "qwerhead.h"


#define min(a,b) (a) < (b) ? (a) : (b)

enum num_of_solu {
  ZEROs = 0,
  ONEs = 1,
  TWOs = 2,
  INFs = -1,
};


enum num_of_solushons {
    DO_TESTS = 1,
    SOLVING = 2,
};



int main(){
    const int num_of_tests_main = 3;               // this is krivo!!!
    double test_or_sol = 0;
    printf("Enter 1 = doing tests, 2 = solve equaluation, any other nuber = EXIT\n");
    test_or_sol = check_right_enter();

    while(test_or_sol == DO_TESTS || test_or_sol == SOLVING){ //kto takoe dva?

        if(test_or_sol == DO_TESTS){
            int run_test = 0;
            struct equ tests[num_of_tests_main] = {
            1, -11,  30, 5,   6, 2,
            1,   4,   4, 2, NAN, 0,
            1,   1.23,   0.297,   -0.9 , -0.33, 2};


            for(int i = 0; i < num_of_tests_main; i++){
                do_test(tests + i, i + 1);
                }
            }

        else if(test_or_sol == SOLVING){
            struct equ curr_equl;    // kill!
            enter_coeff(&curr_equl);

            double ans1, ans2;         // kill!
            int num_ans = sol_squrt(curr_equl, &ans1, &ans2);
            return_ans(num_ans, ans1, ans2);
            }
        scanf("%d", &test_or_sol);
        }
      return 0;
}

int sol_squrt(struct equ curr_equ, double *otv1, double *otv2){
    double a = curr_equ.a, b = curr_equ.b, c = curr_equ.c;
    *otv1 = NAN;
    *otv2 = NAN;
    double D = 0;
    if(!compar_double(a))
    {
        if(!compar_double(b))
        {
            if(!compar_double(c))
                return INFs;
            else
                return ZEROs;
        }
        else
        {
            if(!compar_double(c))
            {
                *otv1 = 0;
                return ONEs;
            }
            else
            {
                *otv1 = - c/b;
                return ONEs;
            }
        }
    }

    D = (b * b) - (4 * a * c);


    if (!compar_double(D) )
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

void enter_coeff(struct equ *curr_equl){
    assert(curr_equl);

    double *a = &(curr_equl->a),*b = &(curr_equl->b), *c = &(curr_equl->c);

    *a = NAN;
    *b = NAN;
    *c = NAN;


    int right_enter = 1;
    int try_count = 11;
    char drop =0;
    do{
        if (right_enter == 0){

            printf("\n\nERROR: entered wrong value, try again.\n\n");
            while((drop = getchar()) != '\n' && drop != EOF)
            ;
        }

        printf("a * x**2 + b * x + c = 0\n");
        printf("\nenter a = ");
        if(scanf("%lf%*c", a) == 0){
            right_enter = 0;
            continue;}

        printf("\nenter b = ");
        if(scanf("%lf%*c", b) == 0){
            right_enter = 0;
            continue;}


        printf("\nenter c = ");
        if(scanf("%lf%*c", c) == 0){
            right_enter = 0;
            continue;


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

int compar_double(double num){
    assert(isfinite(num));
    return (fabs(num) > E);
}

int ct_double(double num1, double num2){
    assert(isfinite(num1) && isfinite(num2));
    return (fabs(num1 - num2) < E);

}

void do_test(struct equ *curr_test, int n){
    assert(curr_test != NULL);
    double ans1 = NAN, ans2 = NAN;
    int num_of_sol = -10;

    num_of_sol = sol_squrt(*curr_test, &ans1, &ans2);

    char flag = 1;
    if( curr_test->r_num_of_sol == 2                                                 &&
        !(num_of_sol == curr_test->r_num_of_sol  &&
        (ct_double(ans1, curr_test->r_ans1)&& ct_double(ans2, curr_test->r_ans2))
          ))
        {

        flag = 0;
        }

    else if((curr_test->r_num_of_sol == 1)                                            &&
          !(num_of_sol == curr_test->r_num_of_sol && ct_double(ans1, curr_test->r_ans1) )){

        flag = 0;

        }


    else if((curr_test->r_num_of_sol == 0 || curr_test->r_num_of_sol == -1) &&
            (num_of_sol == curr_test->r_num_of_sol)){

        flag = 0;
        }

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (flag == 0){
        SetConsoleTextAttribute(h, 0x04);
        printf("ERROR test %d failed\n\n\n", n);
        printf("right number of sol = %d "
               " given number of sol = %d\n", curr_test->r_num_of_sol, num_of_sol);

        if(isfinite(curr_test->r_ans1)){
            printf("right ans1 = %lf", curr_test->r_ans1);}
        if(isfinite(ans1)){
            printf("  given ans1 = %lf\n",ans1);}

        if(isfinite(curr_test->r_ans2)){
            printf("right ans2 = %lf", curr_test->r_ans2);}

        if(isfinite(ans2)){
            printf("  given ans2 = %lf\n", ans2);}
        SetConsoleTextAttribute(h, 0x07);
        }

    else{
        SetConsoleTextAttribute(h, 0x02);
        printf("test %d done\n\n", n);
        SetConsoleTextAttribute(h, 0x07);
    }
}


double check_right_enter(){
    int right_enter = 1, try_counter = 0;
    double output = NAN;
    do{
        if (right_enter == 0){
            printf("ERROR try again");
            for(char drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;}
       right_enter = scanf("%lf%*c", &output);

    }while(right_enter == 0 && try_counter < 11);

    assert(isfinite(output));

    return output;

}
