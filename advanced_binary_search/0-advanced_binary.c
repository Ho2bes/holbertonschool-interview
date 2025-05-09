#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the array
 * @start: Starting index
 * @end: Ending index
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence of value
 * @array: Pointer to the array
 * @start: Start index
 * @end: End index
 * @value: Value to find
 *
 * Return: Index of first occurrence or -1
 */
int recursive_search(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	print_array(array, start, end);
	mid = start + (end - start) / 2;

	if (array[mid] == value)
	{
		if (mid == start || array[mid - 1] != value)
			return (mid);
		return (recursive_search(array, start, mid, value));
	}
	if (array[mid] >= value)
		return (recursive_search(array, start, mid, value));
	return (recursive_search(array, mid + 1, end, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using recursion
 * @array: Pointer to first element of array
 * @size: Size of array
 * @value: Value to search for
 *
 * Return: Index of the value or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
