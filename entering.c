#include "qwerhead.h"


void enter_coeff(struct equ_coeff *curr_equl){
    assert(curr_equl);

    double *a = &(curr_equl->a),*b = &(curr_equl->b),
           *c = &(curr_equl->c); // 3 строки

    *a = NAN;
    *b = NAN;
    *c = NAN;

    int right_enter = 1;
    int try_count = 11; // const
    int drop =0;
    printf("a * x**2 + b*x + c = 0\nEnter coefficents\n");
    *a = enter_one_coeff("a = ");
    *b = enter_one_coeff("b = ");
    *c = enter_one_coeff("c = ");

    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));
}

int check_r_int(){
    int right_enter = 1, try_counter = 0;
    int output = INT_NAN;
    do{
        if (right_enter == 0){
            printf("ERROR try again\n");
            // нужен другой цикл,
            for(int drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;
        }

       right_enter = scanf("%d%*c", &output);

    }while(right_enter == 0 && try_counter < MAX_TRY_COUNT);

    assert(output != INT_NAN);//В MIAN IFом

    return output;
}


double check_r_double(){
    int right_enter = 1, try_counter = 0;
    double output = INT_NAN;
    do{
        if (right_enter == 0){
            printf("ERROR try again\n");
            // в функцию
            for(int drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;}

       right_enter = scanf("%lg%*c", &output);

    }while(right_enter == 0 && try_counter < MAX_TRY_COUNT);

    assert(output != INT_NAN);//В MIAN IFом
    return output;
}

