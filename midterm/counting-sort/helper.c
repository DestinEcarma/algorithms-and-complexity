#include "helper.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max_int(const int *arr, size_t len) {
	int max = arr[0];

	for (size_t i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

int find_min_int(const int *arr, size_t len) {
	int min = arr[0];

	for (size_t i = 1; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}

int *counting_sort_int(const int *arr, size_t len) {
	///////////////////////
	// Memory Allocation //
	///////////////////////

	int *sorted = malloc(len * sizeof(int));

	if (sorted == NULL) {
		return NULL;
	}

	size_t max = find_max_int(arr, len);

	int *count = calloc(max + 1, sizeof(int));

	if (count == NULL) {
		free(sorted);
		return NULL;
	}

	///////////////
	// Algorithm //
	///////////////

	for (size_t i = 0; i < len; i++) {
		count[arr[i]]++;
	}

	for (size_t i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (size_t i = len - 1; i != ULONG_MAX; i--) {
		sorted[--count[arr[i]]] = arr[i];
	}

	free(count);

	return sorted;
}

int *counting_sort_shifted_int(const int *arr, size_t len) {
	int *sorted = malloc(len * sizeof(int));

	if (sorted != NULL) {
		size_t max = find_max_int(arr, len);

		int *count = calloc(max + 1, sizeof(int));

		if (count != NULL) {
			for (size_t i = 0; i < len; i++) {
				if (arr[i] != (int)max) {
					count[arr[i] + 1]++;
				}
			}

			for (size_t i = 1; i <= max; i++) {
				count[i] += count[i - 1];
			}

			for (size_t i = 0; i < len; i++) {
				sorted[count[arr[i]]++] = arr[i];
			}

			free(count);
		} else {
			free(sorted);
			sorted = NULL;
		}
	}

	return sorted;
}

int *counting_sort_min_max_int(const int *arr, size_t len) {
	int *sorted = malloc(len * sizeof(int));

	if (sorted != NULL) {
		int min = find_min_int(arr, len);
		int max = find_max_int(arr, len);

		size_t range = max - min + 1;

		int *count = calloc(range, sizeof(int));

		if (count != NULL) {
			for (size_t i = 0; i < len; i++) {
				if (arr[i] != max) {
					count[arr[i] - min + 1]++;
				}
			}

			for (size_t i = 1; i < range; i++) {
				count[i] += count[i - 1];
			}

			for (size_t i = 0; i < len; i++) {
				sorted[count[arr[i] - min]++] = arr[i];
			}

			free(count);
		} else {
			free(sorted);
			sorted = NULL;
		}
	}

	return sorted;
}
