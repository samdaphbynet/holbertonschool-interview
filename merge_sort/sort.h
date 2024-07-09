#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *holder, int *array, int mid, size_t size);
void merge_sort_holder(int *array, size_t size, int *holder);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */