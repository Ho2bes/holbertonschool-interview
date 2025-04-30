#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * sift_down - Sift down the element at index i in the heap
 * @array: array of ints
 * @size: full size of the array
 * @n: size of the heap being sorted
 * @i: index to sift down from
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		sift_down(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm
 * @array: array of ints
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
