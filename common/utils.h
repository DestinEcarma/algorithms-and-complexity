#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/// A function to swap two values.
static inline void swap(void *a, void *b, size_t byte_size) {
	unsigned char temp;

	for (size_t i = 0; i < byte_size; i++) {
		temp = *((unsigned char *)a + i);
		*((unsigned char *)a + i) = *((unsigned char *)b + i);
		*((unsigned char *)b + i) = temp;
	}
}

#endif
