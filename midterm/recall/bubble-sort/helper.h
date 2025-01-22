#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a generic bubble sort implementation.
/// Be it a integer, float, or even a object/structure,
/// this function can sort those array.
void *bubble_sort(void *arr, size_t len, size_t byte_size,
				  int (*cmp)(const void *, const void *));

/// A function to display an array onto the stdout/console.
void print_arr(void *arr, size_t len, size_t byte_size,
			   void (*print)(const void *));

#endif
