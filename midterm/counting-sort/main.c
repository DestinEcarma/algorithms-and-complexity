#include "./../../common/print-arr.h"
#include "./../../common/stress-test.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 1000000
#define ST_TIMES 100

int main() {
	{
		int arr_non_negative[] = {2, 5, 3, 0, 2, 3, 0, 3, 6};
		int len = sizeof(arr_non_negative) / sizeof(int);

		printf("Initial (Non-Negative): ");
		print_arr(arr_non_negative, len, sizeof(int), print_int);

		int *sorted = counting_sort_int(arr_non_negative, len);

		if (sorted != NULL) {
			printf("Sorted (Original): ");
			print_arr(sorted, len, sizeof(int), print_int);

			free(sorted);
		}

		int *sorted_shifted = counting_sort_shifted_int(arr_non_negative, len);

		if (sorted_shifted != NULL) {
			printf("Sorted (Shifted): ");
			print_arr(sorted_shifted, len, sizeof(int), print_int);

			free(sorted_shifted);
		}
	}

	{
		int arr[] = {2, -5, 3, 0, -2, 3, 0, 3, -6};
		int len = sizeof(arr) / sizeof(int);

		printf("\nInitial (Mixed): ");
		print_arr(arr, len, sizeof(int), print_int);

		int *sorted_min_max = counting_sort_min_max_int(arr, len);

		if (sorted_min_max != NULL) {
			printf("Sorted (Min Max): ");
			print_arr(sorted_min_max, len, sizeof(int), print_int);

			free(sorted_min_max);
		}
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand() % ST_LENGTH;
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n", ST_TIMES);

	unsigned long time =
		stress_test_sort_int(arrST, ST_LENGTH, ST_TIMES, counting_sort_int);

	printf("\nOriginal\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	time = stress_test_sort_int(arrST, ST_LENGTH, ST_TIMES,
								counting_sort_shifted_int);

	printf("\nShifted\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	time = stress_test_sort_int(arrST, ST_LENGTH, ST_TIMES,
								counting_sort_min_max_int);

	printf("\nMin Max\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	return 0;
}
