#include "helper.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *tournament_sort_offline(const int *arr, size_t len) {
	///////////////////////
	// Memory Allocation //
	///////////////////////

	int *sorted = malloc(sizeof(int) * len);

	if (sorted == NULL) {
		return NULL;
	}

	size_t tree_len = len * 2 - 1;
	size_t *tree = malloc(sizeof(size_t) * tree_len);

	if (tree == NULL) {
		free(sorted);
		return NULL;
	}

	int *temp = malloc(sizeof(int) * len);

	if (temp == NULL) {
		free(sorted);
		free(tree);
		return NULL;
	}

	///////////////////////////
	// Algorithm Starts Here //
	///////////////////////////

	memcpy(temp, arr, sizeof(int) * len);

	// Initialize the leaf nodes of the tree as the indices of the array instead
	// of their values to prevent having multiple if-else statements.
	for (size_t i = len; i <= tree_len; i++) {
		tree[i - 1] = i - len;
	}

	// Start at the last leaf node
	size_t start = tree_len - 1;

	for (size_t i = 0; i < len; i++) {
		for (size_t right = start; right > 0; right -= 2) {
			size_t left = right - 1;
			size_t parent = left / 2;

			tree[parent] = (temp[tree[left]] <= temp[tree[right]])
							   ? tree[left]
							   : tree[right];
		}

		sorted[i] = temp[tree[0]];
		temp[tree[0]] = INT_MAX;

		// Start again from the right child that was pushed to sorted array.
		start = (tree_len - (len - tree[0]) - 1) / 2 * 2 + 2;
	}

	free(temp);
	free(tree);

	return sorted;
}
