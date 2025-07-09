#include <stdio.h>

/**
 * print_array - Imprime un tableau d'entiers
 * @array: Le tableau à imprimer
 * @size: Le nombre d'éléments
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; array && i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
