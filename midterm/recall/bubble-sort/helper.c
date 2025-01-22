#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *bubble_sort(void *arr, size_t len, size_t byte_size,
				  int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	memcpy(sorted, arr, len * byte_size);

	int swapped = 1;

	for (size_t i = 1; i < len && swapped; i++) {
		swapped = 0;

		for (size_t j = 0; j < len - i; j++) {
			size_t curr = j * byte_size;
			size_t next = curr + byte_size;

			if (cmp(sorted + curr, sorted + next)) {
				void *temp = malloc(byte_size);

				memcpy(temp, sorted + curr, byte_size);
				memcpy(sorted + curr, sorted + next, byte_size);
				memcpy(sorted + next, temp, byte_size);
				swapped = 1;

				free(temp);
			}
		}
	}

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
