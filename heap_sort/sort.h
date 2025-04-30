#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t base, size_t root);
void swap(int *a, int *b);

#endif
