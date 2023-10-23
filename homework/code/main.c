#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 128

void read_array(FILE *file, int *array, int size);
int count_digits_in_array(int *array, int size);
bool check_for_parity(int num);
void decimal_to_binary(int *num, bool is_even);
void reverse_number(int *num, bool is_even);
int calculate_sum_of_digits_numbers(int num);
void print_array(int *array, int size);

int main() {
    char filename[100];
    printf("Введите имя файла: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка! Файл не существует!\n");
        return 1;
    }

    int size = SIZE;

    int *numbers = malloc(size * sizeof(int));
    if (numbers == NULL) {
        printf("Ошибка! Проблемы с выделением памяти!\n");
        fclose(file);
        return 1;
    }

    read_array(file, numbers, size);

    fclose(file);

    int count = count_digits_in_array(numbers, size);
    if (count == 0) {
        printf("Ошибка! В файле нет данных!\n");
        free(numbers);
        return 1;
    }

    for (int i = 0; i < size; i++) {
        bool is_even = check_for_parity(numbers[i]);
        if (is_even) {
            decimal_to_binary(&numbers[i], is_even);
        } else {
            reverse_number(&numbers[i], is_even);
        }
    }

    print_array(numbers, size);
    free(numbers);
    return 0;
}

void read_array(FILE *file, int *array, int size) {
    int n = 0;
    while (n < size && fscanf(file, "%d", &array[n]) == 1) {
        n++;
    }
}

int count_digits_in_array(int *array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            count++;
        }
    }
    return count;
}

bool check_for_parity(int num) {
    int sum = calculate_sum_of_digits_numbers(num);
    return sum % 2 == 0;
}

void decimal_to_binary(int *num, bool is_even) {
    if (is_even) {
        int binary_num = 0, base = 1;
        while (*num != 0) {
            binary_num += (*num % 2) * base;
            *num /= 2;
            base *= 10;
        }
        *num = binary_num;
    }
}

void reverse_number(int *num, bool is_even) {
    if (!is_even) {
        int reversed_num = 0;
        while (*num != 0) {
            reversed_num = reversed_num * 10 + *num % 10;
            *num /= 10;
        }
        *num = reversed_num;
    }
}

int calculate_sum_of_digits_numbers(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            printf("%d\n", array[i]);
        }
    }
}


