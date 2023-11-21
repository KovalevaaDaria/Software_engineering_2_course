#ifndef program_functions_h
#define program_functions_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int read_array(FILE *file, int *array);
bool check_for_parity(int num);
int calculate_sum_of_digits_numbers(int num);
char *decimal_to_binary(int num);
int reverse_number(int num);
int print_number(int num);
int print_binary_number(int binary[], int size);


#endif 
