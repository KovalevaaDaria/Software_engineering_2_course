#include "functional_testing.h"


const char* choose_file_and_run_tests() {
    printf("\nФункциональное тестирование:\n");
    printf("\nВыберите файл для тестирования:\n");
    printf("1. valid_all_test_file.txt\n");
    printf("2. valid_test_binary_file.txt\n");
    printf("3. valid_test_reverse_file.txt\n");
    printf("4. invalid_test_punctuation_marks_file.txt\n");
    printf("5. invalid_test_letters_file.txt\n");
    printf("6. empty_file_file.txt\n");
    printf("7. no_exiting_file.txt\n");

    int choice;
        printf("\nВведите номер файла: ");
        scanf("%d", &choice);

        const char *filenames[] = {
            VALID_ALL_TEST_FILE,
            VALID_BINARY_TEST_FILE,
            VALID_REVERSED_TEST_FILE,
            INVALID_TEST_FILE_PUNCTIONAL_MARKS,
            INVALID_TEST_LETTERS_FILE,
            EMPTY_TEST_FILE,
            NOT_EXITING_FILE
        };

        if (choice >= 1 && choice <= sizeof(filenames) / sizeof(filenames[0])) {
            return filenames[choice - 1];
        } else {
            printf("Ошибка! Некорректный выбор файла!\n");
            return NULL;
        }
    }
