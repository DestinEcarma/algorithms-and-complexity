#ifndef PRINT_ARR_H
#define PRINT_ARR_H

#include <stddef.h>
#include <stdio.h>

/// A function to display an array onto the stdout/console.
static inline void print_arr(void *arr, size_t len, size_t byte_size,
							 void (*print)(const void *)) {
	printf("[");

	for (size_t i = 0; i < len; i++) {
		print((char *)arr + i * byte_size);

		if (i < len - 1)
			printf(", ");
	}

	printf("]\n");
}

#endif
