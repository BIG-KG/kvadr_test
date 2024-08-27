#include "qwerhead.h"

void enter_coeff(struct equ_coeff * const curr_equl){
	
	assert(curr_equl);

    double *a = &(curr_equl->a), *b = &(curr_equl->b),
           *c = &(curr_equl->c); 

    *a = NAN;
    *b = NAN;
    *c = NAN;

    int right_enter = 1;
    int try_count = 11; // const
    int drop =0;
    printf("a * x**2 + b*x + c = 0\nEnter coefficents\n");
    *a = check_enter_double("a = ");
    *b = check_enter_double("b = ");
    *c = check_enter_double("c = ");

    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));
}

int check_enter_int(){
	int right_enter = 1, try_counter = 0;
    int output = NAN;
	int drop = 0;
    do{	
		drop = 0;
        if (right_enter != 1){
            printf("ERROR try again\n");
			
            for(drop = 0; (drop = getchar()) != '\n' && drop != EOF;){
			;
			}
		}
		
		right_enter = scanf("%d%c", &output, &drop);
		
		 if(drop != '\n'){
			printf("\nYOU CAN ENTER ONLY NUMBERS\n");
			right_enter = 0;
		 }
		
		
		try_counter ++;
    }while((right_enter == 0 || drop != '\n') && try_counter < MAX_TRY_COUNT);

    
    return output;
}


double check_enter_double(const char * const printing_str ){
	
	assert(printing_str);
	
    int right_enter = 1, try_counter = 0;
    double output = NAN;
	int drop = 0, last_char = 0;
	
    do{	
		drop = 0;
        if (right_enter != 1){
            printf("ERROR try again\n");
			
            for(drop = 0; (drop = getchar()) != '\n' && drop != EOF;)
            ;
		}
		
		printf("%s", printing_str);
		right_enter = scanf("%lg%c", &output, &last_char);
		
		 if(!isfinite(output)){
			printf("\nYOU CAN ENTER ONLY FINITE NUMBERS ");
			 right_enter = 0;
		 }
		 if(last_char != '\n'){
			 printf("\nYOU CAN ENTER ONLY NUMBERS\n");
			 right_enter = 0;
		 }
			
		try_counter ++;
    }while((right_enter == 0 || last_char != '\n') && try_counter < MAX_TRY_COUNT);

    
    return output;
}