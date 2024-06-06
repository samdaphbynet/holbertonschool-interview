#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * error_and_exit - Function to handle errors and exit the program.
 *
 * This function prints an error message and exits the program with a status code of 98.
 */
void error_and_exit() {
    printf("Error\n");
    exit(98);
}

/**
 * is_digit_string - checks if string is number
 *
 * @str: string
 *
 * Return: 1 if number, 0 if not
 */
int is_digit_string(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}


/**
 * multiply - two numbers represented as strings.
 *
 * This function takes two strings representing numbers and multiplies them.
 * The result is also returned as a string.
 *
 * @num1: The first number as a string.
 * @num2:The second number as a string.
 *
 * Return The product of the two numbers as a string.
 */
void multiply(char *num1, char *num2) {
    int i, j;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_res = len1 + len2;
    int *result = (int *)calloc(len_res, sizeof(int));
    if (!result) {
        error_and_exit();
    }

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    i = 0;
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

/**
 * main - function that takes two command-line arguments representing numbers,
 * checks if they are valid digits, and then calls the multiply function to compute
 * their product.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings, where the first two elements are the command-line
 * arguments representing the numbers to be multiplied.
 *
 * Return 0 if the program runs successfully, 98 otherwise.
 */
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
