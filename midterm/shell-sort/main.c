#include "./../../common/cmp.h"
#include "./../../common/print-arr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted = shell_sort(arr, len, sizeof(int), cmp_int_g);

	printf("Sorted: ");
	print_arr(sorted, len, sizeof(int), print_int);

	free(sorted);

	return 0;
}
