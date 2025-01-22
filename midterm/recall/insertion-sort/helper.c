#include "helper.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *insertion_sort(void *arr, size_t len, size_t byte_size,
					 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = 1; i < len; i++) {
		memcpy(temp, sorted + i * byte_size, byte_size);

		size_t j = 0;

		while (j < i && cmp(temp, sorted + j * byte_size)) {
			j++;
		}

		for (size_t k = i; k > j; k--) {
			memcpy(sorted + k * byte_size, sorted + (k - 1) * byte_size,
				   byte_size);
		}

		memcpy(sorted + j * byte_size, temp, byte_size);
	}

	free(temp);

	return sorted;
}

void *insertion_sort_reverse(void *arr, size_t len, size_t byte_size,
							 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = len - 2; i != ULONG_MAX; i--) {
		memcpy(temp, sorted + i * byte_size, byte_size);

		size_t j = len - 1;

		while (j >= i && !cmp(temp, sorted + j * byte_size)) {
			j--;
		}

		for (size_t k = i; k < j; k++) {
			memcpy(sorted + k * byte_size, sorted + (k + 1) * byte_size,
				   byte_size);
		}

		memcpy(sorted + j * byte_size, temp, byte_size);
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
