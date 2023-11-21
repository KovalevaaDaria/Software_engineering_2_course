#include "unit_testing.h"
#include "functional_testing.h"
#include "program_functions.h"


void assert_equal(int actual, int expected, const char *message) {
    if (actual == expected) {
        printf("PASS: %s\n", message);
    } else {
        printf("FAIL: %s\n", message);
    }
}


void test_read_file() {
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("\nTest Data: read_array\n");
    FILE *file = fopen("test_input.txt", "r");
    printf("Test case 1: Passing NULL file pointer as input\n");
    assert_equal(read_array(NULL, (int[]){1, 2, 3}), -1, "read_array should return -1 when file pointer is NULL");

    printf("\nTest case 2: Passing NULL array pointer as input\n");
    assert_equal(read_array(file, NULL), -1, "read_array should return -1 when array pointer is NULL");

    fclose(file);
    remove("test_input.txt");
}



void test_read_array() {
    FILE *file = fopen(VALID_ALL_TEST_FILE, "r");
    if (file == NULL) {
        printf("Error opening file for test_read_array!\n");
        return;
    }

    int array[SIZE];
    int size = read_array(file, array);
    fclose(file);

    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("\nTest Data: read_array(size)\n");
    assert_equal(size, 7, "read_array should return the correct size");
    
    printf("\nTest Data: read_array(array[0])\n");
    assert_equal(array[0], 10, "read_array should read the first element correctly");
    
    printf("\nTest Data: read_array(array[1])\n");
    assert_equal(array[1], 11, "read_array should read the last element correctly");
    
    printf("\nTest Data: read_array(array[2])\n");
    assert_equal(array[2], 12, "read_array should read the last element correctly");
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
}


void test_calculate_sum_of_digits_numbers() {
    printf("\nTest Data: calculate_sum_of_digits_numbers(123)\n");
    printf("Input: 123\n");
    assert_equal(calculate_sum_of_digits_numbers(123), 6, "calculate_sum_of_digits_numbers should return the correct sum for positive numbers\n\n");

    printf("Test Data: calculate_sum_of_digits_numbers(-123)\n");
    printf("Input: -123\n");
    assert_equal(calculate_sum_of_digits_numbers(-123), 6, "calculate_sum_of_digits_numbers should return the correct sum for negative numbers\n\n");

    printf("Test Data: calculate_sum_of_digits_numbers(0)\n");
    printf("Input: 0\n");
    assert_equal(calculate_sum_of_digits_numbers(0), 0, "calculate_sum_of_digits_numbers should return 0 for single-digit numbers\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}


void test_check_for_parity() {
    printf("\nTest Data: check_for_parity(10)\n");
    printf("Input: 10\n");
    assert_equal(check_for_parity(10), false, "check_for_parity should return false for even number\n\n");

    printf("Test Data: check_for_parity(15)\n");
    printf("Input: 15\n");
    assert_equal(check_for_parity(15), true, "check_for_parity should return true for odd number\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}


void test_decimal_to_binary() {
    printf("\nTest Data: decimal_to_binary(11)\n");
    printf("Input: 11\n");
    char *binary_result_positive = decimal_to_binary(11);
    assert_equal(strtol(binary_result_positive, NULL, 2), 0b1011, "decimal_to_binary should convert a positive number correctly\n\n");
    free(binary_result_positive);

    printf("Test Data: decimal_to_binary(-11)\n");
    printf("Input: -11\n");
    char *binary_result_negative = decimal_to_binary(-11);
    assert_equal(atoi(binary_result_negative), 11011, "decimal_to_binary should convert a negative number correctly\n");
    free(binary_result_negative);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}



void test_reverse_number() {
    printf("\nTest Data: reverse_number(123)\n");
    printf("Input: 123\n");
    assert_equal(reverse_number(123), 321, "reverse_number should reverse digits of a positive number\n\n");

    printf("Test Data: reverse_number(-456)\n");
    printf("Input: -456\n");
    assert_equal(reverse_number(-456), -654, "reverse_number should reverse digits of a negative number\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}


void test_print_functions() {
    printf("\nTest Data: print_number\n");
    printf("Test case 1: Passing NULL to print_number\n");
    assert_equal(print_number(NULL), -1, "print_number should return -1 when NULL is passed as input");
    
    printf("\nTest Data: print_binary_number\n");
    printf("Test case 2: Passing NULL array and 0 as size to print_binary_number\n");
    assert_equal(print_binary_number(NULL, 0), -1, "print_binary_number should return -1 when NULL is passed as input");
    
    printf("\nTest Data: print_number\n");
    printf("Test case 1: Passing NULL to print_number\n");
    assert_equal(print_number(6), 0, "print_number should return -1 when NULL is passed as input");
    
    printf("\nTest Data: print_binary_number\n");
    printf("Input: binary=[0, 1, 0, 1, 1], size=5\n");
    assert_equal(print_binary_number((int[]){0, 1, 0, 1, 1}, 5), 0, "print_binary_number should properly print the binary number");
    printf("\n--------------------------------------------------------------------------------------------------------------------\n\n");
}


void run_module_tests() {
    printf("\nМодульное тестирование:\n");
    test_read_file();
    test_read_array();
    test_calculate_sum_of_digits_numbers();
    test_check_for_parity();
    test_decimal_to_binary();
    test_reverse_number();
    test_print_functions();
}
