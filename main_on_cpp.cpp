#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "TXlib.h"
#include "qwerhead.h"

#define min(a,b) (a) < (b) ? (a) : (b)

enum num_of_solu {
  ZEROs = 0,
  ONEs = 1,
  TWOs = 2,
  INFs = -1,
};






int main(){
    txCreateWindow(200,200);
    int run_test = 0;
    scanf(r)
    struct equ tests[2];

    tests->a = 1;
    tests->b = -11;
    tests->c = 30;
    tests->r_ans1 = 5;   //e,hfnm pyfxtybz
    tests->r_ans2 = 6;
    tests->r_num_of_sol = 2;

    (tests + 1)->a = 1;
    (tests + 1)->b = 4;
    (tests + 1)->c = 4;
    (tests + 1)->r_ans1 =2;
    (tests + 1)->r_ans2 = NAN;
    (tests + 1)->r_num_of_sol = 0;


    //for(int i = 0; i < 2; i++){
      //  do_test(tests + i);


       // }

}

// ðåøàåò óð-íèå
int sol_squrt(struct equ *curr_equ, double *otv1, double *otv2){
    assert(curr_equ != NULL);
    double a = curr_equ->a, b = curr_equ->b, c = curr_equ->c;
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
    *otv1 = (-b - sqrt(D)) / (2 * a);
    *otv2 = (-b + sqrt(D)) / (2 * a);
    return TWOs;

}

// âïèñûâàåò êîýô â a b c
void enter_coeff(double *a, double *b, double *c){
    assert(a && b && c);
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
        if(scanf("%lf%*ñ", c) == 0){
            right_enter = 0;
            continue;}

       try_count--;


    }while(right_enter == 0 && try_count >0);


    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));

}

//âîçâðàùàåò îòâåòû â çàâèñèìîñòè îò êîë-âà îòâåòîâ
void return_ans(const int number_of_sol, const double ans1, const double ans2 ){
    assert(isfinite(number_of_sol));
    assert(isfinite(ans1));
    assert(isfinite(ans2));
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

// ñðàâíåíèå âåëè÷èí doube  ñ 0
int compar_double(double num){
    assert(isfinite(num));
    return (fabs(num) > E);
}

// òåñò
void do_test(struct equ *curr_test){
    assert(curr_test != NULL);
    double ans1 = NAN, ans2 = NAN;
    int num_of_sol = -10;

    num_of_sol = sol_squrt (curr_test, &ans1, &ans2);

    char flag = 1;

    //ñëó÷àé ñ 2ìÿ îòåòàìè
    if(curr_test->r_num_of_sol == 2 &&
        !(num_of_sol == curr_test->r_num_of_sol &&
        ans1 == curr_test->r_ans1 &&
        ans2 == curr_test->r_ans2)){

        flag = 0;
        }

    //ñëó÷àé ñ 1 îòâåòîì
    else if((curr_test->r_num_of_sol == 1) && !(num_of_sol == curr_test->r_num_of_sol &&
        ans1 == curr_test->r_ans1 )){

        flag = 0;

        }


    // ñëó÷àé ñ 0 îòâåòîâ
    else if((curr_test->r_num_of_sol == 0 || curr_test->r_num_of_sol == -1) &&
     (num_of_sol == curr_test->r_num_of_sol)){

        flag = 0;
        }


    if (flag == 0){
    printf("ERROR \n\n\n");
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
    }

    else{
        printf("test done");
    }
                        // äîáàâèòü öâåòà
}
