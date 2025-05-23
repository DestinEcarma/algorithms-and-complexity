#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a generic gnome sort implementation. Be it a integer,
/// float, or even a object/structure, this function can sort those array.
void *gnome_sort(const void *arr, size_t len, size_t byte_size,
				 int (*cmp)(const void *, const void *));

/// This function is a generic gnome sort implementation with memoization. Be it
/// a integer, float, or even a object/structure, this function can sort those
/// array.
void *gnome_sort_memo(const void *arr, size_t len, size_t byte_size,
					  int (*cmp)(const void *, const void *));

#endif
