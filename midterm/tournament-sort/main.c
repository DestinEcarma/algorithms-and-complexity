#include "./../../common/print-arr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 10000
#define ST_TIMES 100

static inline unsigned long
stress_test_sort(const void *arr, size_t len, size_t nt,
				 int *(*radix)(const int *, size_t)) {
	clock_t start = clock();

	for (size_t _ = 0; _ < nt; _++) {
		int *sorted = radix(arr, len);

		if (sorted != NULL) {
			free(sorted);
		}
	}

	return (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
}

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial (Non-Negative): ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted_offline = tournament_sort_offline(arr, len);

	if (sorted_offline != NULL) {
		printf("Sorted (Original): ");
		print_arr(sorted_offline, len, sizeof(int), print_int);

		free(sorted_offline);
	}

	int *sorted_online_k2 = tournament_sort_online_k2(arr, len);

	if (sorted_online_k2 != NULL) {
		printf("Sorted (Online K2): ");
		print_arr(sorted_online_k2, len, sizeof(int), print_int);

		free(sorted_online_k2);
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n", ST_TIMES);

	unsigned long time =
		stress_test_sort(arrST, ST_LENGTH, ST_TIMES, tournament_sort_offline);

	printf("\nOffline\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	return 0;
}
