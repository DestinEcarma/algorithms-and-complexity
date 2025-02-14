#include "./../../common/cmp.h"
#include "./../../common/print-arr.h"
#include "./../../common/stress-test.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

#define ST_LENGTH 1000000
#define ST_TIMES 100

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted_lomuto = quick_sort_lomuto(arr, len, sizeof(int), cmp_int_l);

	if (sorted_lomuto != NULL) {
		printf("Sorted (Lomuto): ");
		print_arr(sorted_lomuto, len, sizeof(int), print_int);

		free(sorted_lomuto);
	}

	int *sorted_hoare = quick_sort_hoare(arr, len, sizeof(int), cmp_int_l);

	if (sorted_hoare != NULL) {
		printf("Sorted (Hoare): ");
		print_arr(sorted_hoare, len, sizeof(int), print_int);

		free(sorted_hoare);
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n\n", ST_TIMES);

	unsigned long time =
		stress_test_sort(&arrST, ST_LENGTH, sizeof(int), ST_TIMES,
						 quick_sort_lomuto, *cmp_int_l);

	printf("Lomuto\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n\n", (unsigned long)(double)time / ST_TIMES);

	time = stress_test_sort(&arrST, ST_LENGTH, sizeof(int), ST_TIMES,
							quick_sort_hoare, *cmp_int_l);

	printf("Hoare\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", (unsigned long)(double)time / ST_TIMES);

	return 0;
}
