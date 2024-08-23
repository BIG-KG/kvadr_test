#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include "qwerhead.h"

#define INT_NAN -214
#define MAX_TRY_COUNT 11

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



int main(){
    const int num_of_tests_main = 3;
    int test_or_sol = 0;
    printf("HI, its me, Mario!\nEnter 1 = doing tests, 2 = solve equaluation, any other nuber = EXIT\n");
    test_or_sol = check_r_int();

    while(test_or_sol == DO_TESTS || test_or_sol == SOLVING){

        if(test_or_sol == DO_TESTS){
            int run_test = 0;
            struct equ tests[num_of_tests_main] = {
            1, -11,  30, 6,   6, 2,
            1,   4,   4, 2, NAN, 0,                     //hfpltkbnm yf c
            1,   1.23,   0.297,   -0.9 , -0.33, 2};


            for(int i = 0; i < num_of_tests_main; i++){
                do_test(tests + i, i + 1);
                }
        }

        else if(test_or_sol == SOLVING){
            struct equ curr_equl = {};
            enter_coeff(&(curr_equl.in_coeff));

            double ans1 = 0, ans2 = 0;
            int num_ans = sol_equ(curr_equl.in_coeff, &ans1, &ans2);
            print_ans(num_ans, ans1, ans2);
            }
        test_or_sol = check_r_int();
        }

      return 0;
}






void print_ans(const int number_of_sol, const double ans1, const double ans2 ){
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

int compar_double_with_zero(double num){
    assert(isfinite(num));
    return (fabs(num) > E);
}

int ct_double(double num1, double num2){
    assert(isfinite(num1) && isfinite(num2));
    return (fabs(num1 - num2) < E);

}

void do_test(struct equ *curr_test, int n){
    assert(curr_test != NULL);

    double r_ans1 = (curr_test->in_ans).r_ans1;
    double r_ans2 = (curr_test->in_ans).r_ans2;
    int r_num_of_sol = (curr_test->in_ans).r_num_of_sol;

    double ans1 = NAN, ans2 = NAN;
    int num_of_sol = sol_equ(curr_test->in_coeff, &ans1, &ans2);

    char flag = 1;
    if( r_num_of_sol == 2                                                 &&
        !(num_of_sol == r_num_of_sol  &&
        (ct_double(ans1, r_ans1)&& ct_double(ans2, r_ans2))
          ))
        {

        flag = 0;
        }

    else if((r_num_of_sol == 1)                                            &&
          !(num_of_sol == r_num_of_sol && ct_double(ans1, r_ans1) )){

        flag = 0;

        }


    else if((r_num_of_sol == 0 || r_num_of_sol == -1) &&
            (num_of_sol == r_num_of_sol)){

        flag = 0;
        }
    print_test_result(flag, ans1, ans2, &(curr_test->in_ans), n, num_of_sol);

}

void print_test_result(int flag, double ans1, double ans2, struct test_ans * in_ans, int n, int num_of_sol){
    double r_ans1 = in_ans->r_ans1;
    double r_ans2 = in_ans->r_ans2;
    double r_num_of_sol = in_ans->r_num_of_sol;
    HANDLE h  = GetStdHandle(STD_OUTPUT_HANDLE);

    if (flag == 0){
        SetConsoleTextAttribute(h, 0x04);
        printf("ERROR test %d failed\n\n\n", n);
        printf("right number of sol = %d "
               " given number of sol = %d\n", r_num_of_sol, num_of_sol);

        if(isfinite(r_ans1)){
            printf("right ans1 = %lf", r_ans1);}
        if(isfinite(ans1)){
            printf("  given ans1 = %lf\n",ans1);}

        if(isfinite(r_ans2)){
            printf("right ans2 = %lf", r_ans2);}

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






double enter_one_coeff(const char *c){
    assert(c != NULL);

    while(*c != '\0'){
        putchar(*c);
        c++;
    }
    return check_r_double();

}
