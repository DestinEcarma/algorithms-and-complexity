#include "./../../common/print-arr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 1000000
#define ST_TIMES 100

static inline unsigned long stress_test_sort(const void *arr, size_t len,
											 size_t nt) {
	clock_t start = clock();

	for (size_t _ = 0; _ < nt; _++) {
		int *sorted = bucket_sort_int(arr, len);

		if (sorted != NULL) {
			free(sorted);
		}
	}

	return (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
}

int main() {
	int arr[] = {9, 9, 5, 10, 7, 3, 2, 6, 4, 1, 3, 100, 8, 21};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted = bucket_sort_int(arr, len);

	if (sorted != NULL) {
		printf("Sorted: ");
		print_arr(sorted, len, sizeof(int), print_int);

		free(sorted);
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n\n", ST_TIMES);

	unsigned long time = stress_test_sort(arrST, ST_LENGTH, ST_TIMES);

	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	return 0;
}
