#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

void *selection_sort(void *arr, size_t len, size_t byte_size,
					 int (*cmp)(const void *, const void *));

void print_arr(void *arr, size_t len, size_t byte_size,
			   void (*print)(const void *));

#endif
