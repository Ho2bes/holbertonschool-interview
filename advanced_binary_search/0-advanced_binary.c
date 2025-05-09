#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the elements of the array being searched
 * @array: The array to print
 * @left: The starting index
 * @right: The ending index
 */
void print_array(int *array, int left, int right)
{
    printf("Searching in array: ");
    for (int i = left; i <= right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * recursive_search - Recursive binary search to find first occurrence
 * @array: The array to search in
 * @left: The starting index
 * @right: The ending index
 * @value: The value to search for
 * Return: The index of the first occurrence, or -1
 */
int recursive_search(int *array, int left, int right, int value)
{
    int mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);
    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return mid;
        return recursive_search(array, left, mid, value);
    }
    else if (array[mid] > value)
    {
        return recursive_search(array, left, mid - 1, value);
    }
    else
    {
        return recursive_search(array, mid + 1, right, value);
    }
}

/**
 * advanced_binary - Wrapper function for recursive binary search
 * @array: The array to search in
 * @size: The size of the array
 * @value: The value to search for
 * Return: The index of the first occurrence, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return recursive_search(array, 0, (int)size - 1, value);
}
