#include "helper.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 10

typedef struct NodeInt {
	int value;
	struct NodeInt *next;
} NodeInt;

int find_max_int(const int *arr, size_t len) {
	int max = arr[0];

	for (size_t i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

int *radix_lsd_sort_int(const int *arr, size_t len) {
	int *sorted = malloc(sizeof(int) * len);

	if (sorted != NULL) {
		memcpy(sorted, arr, sizeof(int) * len);

		NodeInt *buckets[BASE];

		int max = find_max_int(arr, len);

		size_t digit = 1;

		while (max / digit > 0) {
			for (size_t i = 0; i < BASE; i++) {
				buckets[i] = NULL;
			}

			for (size_t i = len - 1; i != ULONG_MAX; i--) {
				size_t pos = sorted[i] / digit % 10;

				NodeInt *node = malloc(sizeof(NodeInt));

				if (node != NULL) {
					node->value = sorted[i];
					node->next = buckets[pos];

					buckets[pos] = node;
				} else {
					fprintf(stderr, "NodeInt memory allocation failed\n");
					exit(1);
				}
			}

			for (size_t i = 0, j = 0; i < BASE; i++) {
				NodeInt *curr = buckets[i];

				while (curr != NULL) {
					sorted[j++] = curr->value;

					NodeInt *temp = curr;
					curr = curr->next;
					free(temp);
				}
			}

			digit *= BASE;
		}
	}

	return sorted;
}

void _radix_msd_sort_int(int *arr, size_t low, size_t high, size_t digit) {
	if (digit > 0 && low < high && high < ULONG_MAX) {
		NodeInt *buckets[BASE] = {NULL};

		for (size_t i = low; i <= high; i++) {
			size_t pos = arr[i] / digit % BASE;

			NodeInt *node = malloc(sizeof(NodeInt));

			if (node != NULL) {
				node->value = arr[i];
				node->next = buckets[pos];

				buckets[pos] = node;
			} else {
				fprintf(stderr, "NodeInt memory allocation failed\n");
				exit(1);
			}
		}

		for (size_t i = 0; i < BASE; i++) {
			NodeInt *curr = buckets[i];

			high = low;

			while (curr != NULL) {
				arr[high++] = curr->value;

				NodeInt *temp = curr;
				curr = curr->next;
				free(temp);
			}

			_radix_msd_sort_int(arr, low, high - 1, digit / BASE);

			low = high;
		}
	}
}

int *radix_msd_sort_int(const int *arr, size_t len) {
	int *sorted = malloc(sizeof(int) * len);

	if (sorted != NULL) {
		memcpy(sorted, arr, sizeof(int) * len);

		size_t max = find_max_int(arr, len);

		size_t digit = 1;

		while (max / digit > 1) {
			digit *= BASE;
		}

		_radix_msd_sort_int(sorted, 0, len - 1, digit);
	}

	return sorted;
}
