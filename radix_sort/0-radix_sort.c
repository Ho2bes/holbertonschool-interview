#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_max - Trouve la valeur maximale dans le tableau
 * @array: tableau d'entiers
 * @size: taille du tableau
 * Return: valeur maximale
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Trie le tableau selon un chiffre donné (exp)
 * @array: tableau à trier
 * @size: taille du tableau
 * @exp: chiffre significatif (1, 10, 100, ...)
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
	int output[1024]; /* output array (assume size <= 1024) */
	int count[10] = {0};
	size_t i;

	/* Comptage des occurrences pour le chiffre à l'exp */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Cumul des positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Construire le tableau trié */
	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	/* Copier dans le tableau d'origine */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
}

/**
 * radix_sort - Trie un tableau avec l’algorithme LSD Radix Sort
 * @array: tableau à trier
 * @size: taille du tableau
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_digit(array, size, exp);
}
