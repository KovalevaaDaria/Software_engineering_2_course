#include "program_functions.h"
#include "unit_testing.h"
#include "functional_testing.h"


int main() {
    const char *selected_file = choose_file_and_run_tests();

    if (selected_file != NULL) {
        FILE *file = fopen(selected_file, "r");


        if (file == NULL) {
            printf("Ошибка! Файл не существует!\n\n");
            return 1;
        }

        int *numbers = malloc(SIZE * sizeof(int));
        if (numbers == NULL) {
            printf("Ошибка! Проблемы с выделением памяти!\n\n");
            fclose(file);
            return 1;
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("Работа основной программы:\n\n");
        int size = read_array(file, numbers);

        if (size == 0) {
            printf("Ошибка! В файле нет данных!\n\n");
            free(numbers);
            fclose(file);
            return 1;

        } else if (size == -1) {
            free(numbers);
            fclose(file);
            return 1;
        }

        fclose(file);

        printf("Входные данные: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");

        printf("\nРезультаты операций:\n\n");
        for (int i = 0; i < size; i++) {
            bool is_even = check_for_parity(numbers[i]);

            if (is_even) {
                char *binary_result = decimal_to_binary(numbers[i]);
                printf("Двоичночное число: %s\n", binary_result);
                free(binary_result);
            } else {
                int reversed_number = reverse_number(numbers[i]);
                printf("Обратное число: ");
                print_number(reversed_number);
            }
        }

        free(numbers);
        printf("\n");

        run_module_tests();
    }
}
