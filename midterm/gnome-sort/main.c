#include "./../../common/cmp.h"
#include "./../../common/print-arr.h"
#include "./../../common/stress-test.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 10000
#define ST_TIMES 100

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted = gnome_sort(arr, len, sizeof(int), cmp_int_geq);

	if (sorted != NULL) {
		printf("Sorted (Original): ");
		print_arr(sorted, len, sizeof(int), print_int);

		free(sorted);
	}

	int *sorted_memoization =
		gnome_sort_memo(arr, len, sizeof(int), cmp_int_geq);

	if (sorted_memoization != NULL) {
		printf("Sorted (Memoization): ");
		print_arr(sorted_memoization, len, sizeof(int), print_int);

		free(sorted_memoization);
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n", ST_TIMES);

	unsigned long time = stress_test_sort(&arrST, ST_LENGTH, sizeof(int),
										  ST_TIMES, gnome_sort, cmp_int_geq);

	printf("\nOriginal\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	time = stress_test_sort(&arrST, ST_LENGTH, sizeof(int), ST_TIMES,
							gnome_sort_memo, cmp_int_geq);

	printf("\nMemoization\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	return 0;
}
