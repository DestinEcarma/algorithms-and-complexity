#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *selection_sort(void *arr, size_t len, size_t byte_size,
					 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = 1; i < len; i++) {
		size_t min_i = i;
		size_t k = i - 1;

		for (size_t j = i; j < len; j++) {
			if (cmp(sorted + min_i * byte_size, sorted + j * byte_size)) {
				min_i = j;
			}
		}

		memcpy(temp, sorted + k * byte_size, byte_size);
		memcpy(sorted + k * byte_size, sorted + min_i * byte_size, byte_size);
		memcpy(sorted + min_i * byte_size, temp, byte_size);
	}

	free(temp);

	return sorted;
}

void print_arr(void *arr, size_t len, size_t byte_size,
			   void (*print)(const void *)) {
	printf("[");

	for (size_t i = 0; i < len; i++) {
		print(arr + i * byte_size);

		if (i < len - 1)
			printf(", ");
	}

	printf("]\n");
}
