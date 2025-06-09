#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *temp, size_t left, size_t mid, size_t right) {
    size_t i = left, j = mid, k = left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    while (i < mid && j < right) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i < mid)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

void merge_sort_recursive(int *array, int *temp, size_t left, size_t right) {
    if (right - left < 2)
        return;

    size_t mid = left + (right - left) / 2;

    merge_sort_recursive(array, temp, left, mid);
    merge_sort_recursive(array, temp, mid, right);
    merge(array, temp, left, mid, right);
}

void merge_sort(int *array, size_t size) {
    if (!array || size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size);
    free(temp);
}
