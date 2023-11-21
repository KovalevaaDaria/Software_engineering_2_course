#ifndef unit_testing_h
#define unit_testing_h

#include <stdio.h>

int read_array(FILE *file, int *array);
int print_number(int num);
void test_read_file(void);
int print_binary_number(int binary[], int size);
void assert_equal(int actual, int expected, const char *message);
void test_read_array(void);
void test_check_for_parity(void);
void test_calculate_sum_of_digits_numbers(void);
void test_decimal_to_binary(void);
void test_reverse_number(void);
void run_module_tests(void);
void test_print_functions(void);

#endif 
