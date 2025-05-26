#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: the string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
    while (*s)
    {
        if (!isdigit(*s))
            return (0);
        s++;
    }
    return (1);
}

/**
 * print_error - prints error and exits
 */
void print_error(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, i, j, *result, carry, n1, n2, start;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        print_error();

    num1 = argv[1];
    num2 = argv[2];
    len1 = strlen(num1);
    len2 = strlen(num2);
    result = calloc(len1 + len2, sizeof(int));
    if (!result)
        print_error();

    // Multiply digits from the end
    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            result[i + j + 1] += n1 * n2;
        }
    }

    // Handle carry over
    for (i = len1 + len2 - 1; i > 0; i--)
    {
        carry = result[i] / 10;
        result[i] %= 10;
        result[i - 1] += carry;
    }

    // Skip leading zeros
    start = 0;
    while (start < len1 + len2 && result[start] == 0)
        start++;

    if (start == len1 + len2)
        printf("0\n");
    else
    {
        for (i = start; i < len1 + len2; i++)
            printf("%d", result[i]);
        printf("\n");
    }

    free(result);
    return (0);
}
