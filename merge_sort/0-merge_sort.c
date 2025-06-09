#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sorted subarrays into the original array
 * @array: Original array to store merged result
 * @left: Left subarray
 * @right: Right subarray
 * @left_size: Size of left subarray
 * @right_size: Size of right subarray
 */
void merge(int *array, int *left, int *right,
	   size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort_recursive - Helper recursive function for merge sort
 * @array: Array to sort
 * @temp: Temporary buffer array
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = temp;
	right = temp + mid;

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort_recursive(left, array, mid);
	merge_sort_recursive(right, array, size - mid);
	merge(array, left, right, mid, size - mid);
}

/**
 * merge_sort - Sorts an array using top-down merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, temp, size);
	free(temp);
}
