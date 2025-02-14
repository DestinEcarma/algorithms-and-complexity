#include "helper.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int *bucket_sort_int(const int *arr, size_t len) {
	int *sorted = malloc(sizeof(int) * len);

	if (sorted != NULL) {
		memcpy(sorted, arr, sizeof(int) * len);

		NodeInt **buckets = calloc(len, sizeof(NodeInt *));

		if (buckets != NULL) {
			int max = find_max_int(arr, len) + 1;

			for (size_t i = len - 1; i != ULONG_MAX; i--) {
				size_t pos = len * sorted[i] / max;

				NodeInt *node = malloc(sizeof(NodeInt));

				if (node != NULL) {
					node->value = sorted[i];

					NodeInt **curr = &buckets[pos];

					while (*curr != NULL && (*curr)->value < sorted[i]) {
						curr = &(*curr)->next;
					}

					node->next = *curr;
					*curr = node;
				}
			}

			for (size_t i = 0, j = 0; i < len; i++) {
				NodeInt *curr = buckets[i];

				while (curr != NULL) {
					sorted[j++] = curr->value;

					NodeInt *temp = curr;
					curr = curr->next;
					free(temp);
				}
			}

			free(buckets);
		}
	}

	return sorted;
}
