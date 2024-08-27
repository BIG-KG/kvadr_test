#include "qwerhead.h"

int main(){

    printf("Enter 1 = doing tests, 2 = solve equaluation, any other nuber = EXIT\n");
    int test_or_sol = check_enter_int();

    while(test_or_sol == DO_TESTS || test_or_sol == SOLVING){

        if(test_or_sol == DO_TESTS){
            do_all_tests();
        }

        else if(test_or_sol == SOLVING){
            struct full_equl_struct curr_equl = {};
            enter_coeff(&(curr_equl.in_coeff));

            double ans1 = 0, ans2 = 0; // 2 stroki + 0 = int,
            curr_equl.curr_ans.num_of_sol = sol_equ((const equ_coeff)curr_equl.in_coeff, &curr_equl.curr_ans);
            print_equation_ans((const answers_s)curr_equl.curr_ans);
        }
		printf("Enter 1 = doing tests, 2 = solve equaluation, any other nuber = EXIT\n");
        test_or_sol = check_enter_int();
    }
    return 0;

}

void print_equation_ans(const answers_s curr_ans){

	const int number_of_sol = curr_ans.num_of_sol;
	cdouble ans1 = curr_ans.ans1;
	cdouble ans2 = curr_ans.ans2;

    switch(number_of_sol){
        case (ZEROs):
            printf("there is 0 solutions\n");
            break;
        case (ONEs):
            print_double_with_capt("there is 1 solution ", ans1, 1);
            break;
        case (TWOs):
            printf("there is 2 solution: ", ans1, ans2);
			print_double_with_capt("x1 = ", ans1, 0);
			print_double_with_capt("x2 = ", ans2, 1);
            break;
        case (INFs):
            printf("any R\n");
            break;
        default:
            printf("Error");
    }

}

int compar_double_with_zero(cdouble num){

    assert(isfinite(num));
    return (fabs(num) > E);

}

int compair_two_double(cdouble num1, cdouble num2){

    assert(isfinite(num1) && isfinite(num2));
    return (fabs(num1 - num2) < E);

}

void do_test(struct full_equl_struct * const curr_test, const int n){

	assert(curr_test);

    cdouble r_ans1 = (curr_test->in_ans).r_ans1;
    cdouble r_ans2 = (curr_test->in_ans).r_ans2;
    const int r_num_of_sol = (curr_test->in_ans).r_num_of_sol;

    int num_of_sol = sol_equ(curr_test->in_coeff, &curr_test->curr_ans);
	cdouble ans1 = curr_test->curr_ans.ans1;
	cdouble ans2 = curr_test->curr_ans.ans2;
	curr_test->curr_ans.num_of_sol = num_of_sol;

    bool right_test = true;
    switch(r_num_of_sol){
		case TWOs:
			if (!(  num_of_sol == r_num_of_sol  &&  (compair_two_double (ans1, r_ans1) && compair_two_double(ans2, r_ans2))  )){
				right_test = false;
			}
			break;

		case ONEs:
			if (!(  num_of_sol == r_num_of_sol  &&  compair_two_double (ans1, r_ans1) )){
				right_test = false;
			}
			break;

		case ZEROs: case INFs:
			if (!(num_of_sol == r_num_of_sol)){
				right_test = false;
			}
			break;

		default:
			right_test = false;
	}

    print_test_result(right_test, (const full_equl_struct *)curr_test, n);

}

void print_test_result(bool right_test, const full_equl_struct * const curr_test, const int n){

	assert(curr_test);

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (right_test == false){
        SetConsoleTextAttribute(h, 0x04);

        printf("ERROR test %d failed\n\n\n", n);
        printf("right number of sol = %d " " given number of sol = %d\n", 
				curr_test->in_ans.r_num_of_sol, curr_test->curr_ans.num_of_sol);

		print_double_with_capt("right ans1 = ", curr_test->in_ans.r_ans1, 0);
		print_double_with_capt("right ans2 = ", curr_test->in_ans.r_ans2, 1);
		print_double_with_capt("given ans1 = ", curr_test->curr_ans.ans1, 0);
		print_double_with_capt("given ans2 = ", curr_test->curr_ans.ans2, 1);

        SetConsoleTextAttribute(h, 0x07);
        }

    else{
        SetConsoleTextAttribute(h, 0x02);
        printf("test %d done\n", n);
        SetConsoleTextAttribute(h, 0x07);
    }

}

void do_all_tests(){

    struct full_equl_struct tests[] = {
//  a       b      c       ans1         ans2     num_of_ans
	{1,    -11,    30,     5,            6,          2},
	{1,     4,     4,       -2,          NAN,        1},
	{1,     1.23,  0.297,  -0.9 ,       -0.33,       2},
	{0,     1.27, -0.4191,  0.33,        NAN,        1},
	{0,     0,     0,       NAN,         NAN,       -1},
	{0,     0,     3,       NAN,         NAN,        0},
	{2.581, 0,    -16.6,   -2.536063,    2.536063,   2},
	{2,     581,   4,      -290.493115, -0.00688484, 2},
	{2,     581,   4,      -290.493115, -0.00678484, 2}};

    int num_of_tests_main = sizeof(tests) / sizeof(struct full_equl_struct);

    for(int i = 0; i < num_of_tests_main; i++){
        do_test(tests + i, (const int)i + 1);
    }
}

void print_double_with_capt(const char* a, cdouble f, int end){

	assert(a);

	if(isfinite(f)){
		printf("%s", a);
		if (!compar_double_with_zero(f)){
			printf("%6lg", 0.0);
			if(end == 1){
				printf("\n");
			}
			return;
		}
		else if (compar_double_with_zero(f)){
			printf("%6lg ", f);
			if(end == 1){
				printf("\n");
			}

		}
	}

}
