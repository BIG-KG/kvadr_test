#include "qwerhead.h"
int aqqyu = 0;


void enter_coeff(struct equ_coeff *curr_equl){
    if (curr_equl == NULL){
		printf("ERROR pointer curr_equl == NULL, in funk enter_coeff");
		assert(curr_equl);
	}

    double *a = &(curr_equl->a),*b = &(curr_equl->b),
           *c = &(curr_equl->c); 

    *a = NAN;
    *b = NAN;
    *c = NAN;

    int right_enter = 1;
    int try_count = 11; // const
    int drop =0;
    printf("a * x**2 + b*x + c = 0\nEnter coefficents\n");
    *a = check_r_double("a = ");
    *b = check_r_double("b = ");
    *c = check_r_double("c = ");

    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));
}

int check_r_int(){
	int right_enter = 1, try_counter = 0;
    int output = NAN;
	int drop = 0;
    do{	
		drop = 0;
        if (right_enter != 1){
            printf("ERROR try again\n");
			
            for(drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;}
		
		right_enter = scanf("%d%c", &output, &drop);
		
		 if(drop != '\n'){
			printf("\nYOU CAN ENTER ONLY NUMBERS\n");
			right_enter = 0;
		 }
		
		
		try_counter ++;
    }while((right_enter == 0 || drop != '\n') && try_counter < MAX_TRY_COUNT);

    
    return output;
}


double check_r_double(const char *print_str ){
	
	if (print_str == NULL){
		printf("ERROR pointer print_str == NULL, in funk chech_r_double");
		assert(print_str);
	}
	
    int right_enter = 1, try_counter = 0;
    double output = NAN;
	int drop = 0;
	
    do{	
		drop = 0;
        if (right_enter != 1){
            printf("ERROR try again\n");
			
            for(drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;}
		
		printf("%s", print_str);
		right_enter = scanf("%lg%c", &output, &drop);
		
		 if(!isfinite(output)){
			printf("\nYOU CAN ENTER ONLY FINITE NUMBERS ");
			 right_enter = 0;
		 }
		 if(drop != '\n'){
			 printf("\nYOU CAN ENTER ONLY NUMBERS\n");
			 right_enter = 0;
		 }
		
		
		try_counter ++;
    }while((right_enter == 0 || drop != '\n') && try_counter < MAX_TRY_COUNT);

    
    return output;
}