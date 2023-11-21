#include "program_functions.h"


int read_array(FILE *file, int *array) {
    if (file == NULL) {
        return -1;
    }
    
    if (array == NULL) {
        return -1;
    }
    
    int i = 0;
    int num;
    int result;

    while ((result = fscanf(file, "%d", &num)) == 1) {
        array[i] = num;
        i++;
    }

    if (result == 0) {
        printf("Ошибка! Данные в файле некорректны!\n\n");
        return -1;
    }

    return i;
}


int calculate_sum_of_digits_numbers(int num) {
    int sum = 0;

    while (num != 0) {
        sum += abs(num % 10);
        num /= 10;
    }

    return sum;
}


bool check_for_parity(int num) {
    int sum = calculate_sum_of_digits_numbers(num);
    return sum % 2 == 0;
}


char *decimal_to_binary(int num) {
    int binary[32];
    int i = 0;

    int sign = (num >= 0) ? 0 : 1;

    num = (num >= 0) ? num : -num;

    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    char *result = (char *)malloc((i + 2) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        return NULL;
    }

    sprintf(result, "%d", sign);

    for (int j = i - 1; j >= 0; j--) {
        char digit[2];
        sprintf(digit, "%d", binary[j]);
        strcat(result, digit);
    }

    return result;
}


int reverse_number(int num) {
    int reversed_num = 0;
    while (num != 0) {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }

    return reversed_num;
}


int print_number(int num) {
    if (num == 0) {
        return -1;
    }
    printf("%d\n", num);
    return 0;
}


int print_binary_number(int binary[], int size) {
    if (binary == NULL) {
        return -1;
    }
    
    if (size == 0) {
        return -1;
    }
    
    for (int j = 0; j < size; j++) {
        printf("%d", binary[j]);
    }
    printf("\n");
    return 0;
}

