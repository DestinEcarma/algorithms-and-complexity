#include "./../../common/print-arr.h"
#include "./../../common/stress-test.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 1000000
#define ST_TIMES 100

int main() {
	int arr[] = {9, 9, 5, 10, 7, 3, 2, 6, 4, 1, 3, 100, 8, 21};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted_lsd = radix_lsd_sort_int(arr, len);

	if (sorted_lsd != NULL) {
		printf("Sorted (LSD): ");
		print_arr(sorted_lsd, len, sizeof(int), print_int);

		free(sorted_lsd);
	}

	int *sorted_msd = radix_msd_sort_int(arr, len);

	if (sorted_msd != NULL) {
		printf("Sorted (MSD): ");
		print_arr(sorted_msd, len, sizeof(int), print_int);

		free(sorted_msd);
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n\n", ST_TIMES);

	unsigned long time =
		stress_test_sort_int(arrST, ST_LENGTH, ST_TIMES, radix_lsd_sort_int);

	printf("LSD\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	time = stress_test_sort_int(arrST, ST_LENGTH, ST_TIMES, radix_msd_sort_int);

	printf("MSD\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	return 0;
}
