#ifndef functional_testing_h
#define functional_testing_h

#include <stdio.h>

#define SIZE 568

#define VALID_ALL_TEST_FILE "/Users/daria/Documents/Бауманка предметы/2 курс/3 семестр/Прог инж/homework/code/code_for_homework/code_for_homework/tests/valid_all_test_file.txt"
#define VALID_BINARY_TEST_FILE "/Users/daria/Documents/Бауманка предметы/2 курс/3 семестр/Прог инж/homework/code/code_for_homework/code_for_homework/tests/valid_test_binary_file.txt"
#define VALID_REVERSED_TEST_FILE "/Users/daria/Documents/Бауманка предметы/2 курс/3 семестр/Прог инж/homework/code/code_for_homework/code_for_homework/tests/valid_test_reverse_file.txt"
#define INVALID_TEST_FILE_PUNCTIONAL_MARKS "/Users/daria/Documents/Бауманка предметы/2 курс/3 семестр/Прог инж/homework/code/code_for_homework/code_for_homework/tests/invalid_test_punctuation_marks_file.txt"
#define INVALID_TEST_LETTERS_FILE "/Users/daria/Documents/Бауманка предметы/2 курс/3 семестр/Прог инж/homework/code/code_for_homework/code_for_homework/tests/invalid_test_letters_file.txt"
#define EMPTY_TEST_FILE "/Users/daria/Documents/Бауманка предметы/2 курс/3 семестр/Прог инж/homework/code/code_for_homework/code_for_homework/tests/empty_file_file.txt"
#define NOT_EXITING_FILE "/Users/daria/Library/Mobile Documents/com~apple~CloudDocs/.Trash/_not_existing_file.txt"

const char* choose_file_and_run_tests(void);

#endif
