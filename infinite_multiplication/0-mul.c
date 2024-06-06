#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print error message and exit with status 98
void error_and_exit() {
    printf("Error\n");
    exit(98);
}

// Function to check if a string is composed only of digits
int is_digit_string(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to multiply two large numbers represented as strings
void multiply(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_res = len1 + len2;
    int *result = (int *)calloc(len_res, sizeof(int));
    if (!result) {
        error_and_exit();
    }

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    int i = 0;
    while (i < len_res && result[i] == 0) {
        i++;
    }

    if (i == len_res) {
        printf("0\n");
    } else {
        for (; i < len_res; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
    }

    free(result);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        error_and_exit();
    }

    if (!is_digit_string(argv[1]) || !is_digit_string(argv[2])) {
        error_and_exit();
    }

    multiply(argv[1], argv[2]);
    return 0;
}
