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

void merge_arr(int *arr, int *temp, size_t len, size_t mid) {
	memcpy(temp, arr, sizeof(int) * len);

	size_t left = 0;
	size_t right = mid;

	while (left < mid && right < len) {
		if (temp[left] <= temp[right]) {
			*arr++ = temp[left++];
		} else {
			*arr++ = temp[right++];
		}
	}

	memcpy(arr, temp + left, sizeof(int) * (mid - left));
	memcpy(arr, temp + right, sizeof(int) * (len - right));
}

int *tournament_sort_online_k2(const int *arr, size_t len) {
	///////////////////////
	// Memory Allocation //
	///////////////////////

	int *sorted = malloc(sizeof(int) * len);
	size_t sl = 0;

	if (sorted == NULL) {
		return NULL;
	}

	// Partial Sorted
	int(*ps)[len] = malloc(sizeof(int) * len * 2);
	size_t ps_len[2] = {0, 0};

	if (ps == NULL) {
		free(sorted);
		return NULL;
	}

	///////////////////////////
	// Algorithm Starts Here //
	///////////////////////////

	int tree[7];

	for (size_t i = 3; i < 7; i++) {
		tree[i] = arr[i - 3];
	}

	size_t k = 0;

	for (size_t i = 0; i < len; i++) {
		bool can_push = false;

		// No need to use the logic from before where we start from the
		// right child of the pushed element, since we only have 4 leaf
		// nodes. That logic is only useful when we have more than 4 leaf
		// nodes.
		for (size_t current = 6; current > 0; current -= 2) {
			size_t right = current;
			size_t left = right - 1;
			size_t parent = left / 2;

			// left and right flags
			bool lf = false;
			bool rf = false;

			if (right < 3) {
				// Indices are no longer within the leaf nodes.
				left = tree[left];
				right = tree[right];
			}

			// Flag the leaf node if it is less than the last element from
			// the partial sorted array.
			if (ps_len[k] > 0) {
				lf = tree[left] == INT_MAX || tree[left] < ps[k][ps_len[k] - 1];
				rf = tree[right] == INT_MAX ||
					 tree[right] < ps[k][ps_len[k] - 1];
			}

			if (!(lf || rf)) {
				tree[parent] = (tree[left] <= tree[right]) ? left : right;
			} else if (!lf) {
				tree[parent] = left;
			} else if (!rf) {
				tree[parent] = right;
			}

			if (!can_push) {
				can_push = !(lf && rf);
			}
		}

		if (can_push) {
			ps[k][ps_len[k]++] = tree[tree[0]];

			if (i < (len - 4)) {
				tree[tree[0]] = arr[i + 4];
			} else {
				tree[tree[0]] = INT_MAX;
			}
		} else {
			// This means that all elements in the leaf nodes are less than the
			// last element of the partial sorted array.
			k++;

			// If we have 2 partial sorted arrays, merge them.
			if (k >= 2) {
				memcpy(sorted + sl, ps[0], sizeof(int) * ps_len[0]);
				memcpy(sorted + sl + ps_len[0], ps[1], sizeof(int) * ps_len[1]);
				sl += ps_len[0] + ps_len[1];

				merge_arr(sorted, ps[0], sl, sl - ps_len[0]);
				k = 0;

				// Reset the partial sorted array lengths.
				ps_len[0] = 0;
				ps_len[1] = 0;
			}

			// Decrement i because nothing was pushed to the partial sorted
			i--;
		}
	}

	memcpy(sorted + sl, ps[0], sizeof(int) * ps_len[0]);
	memcpy(sorted + sl + ps_len[0], ps[1], sizeof(int) * ps_len[1]);
	sl += ps_len[0] + ps_len[1];
	merge_arr(sorted, ps[0], sl, sl - ps_len[0]);

	free(ps);

	return sorted;
}
