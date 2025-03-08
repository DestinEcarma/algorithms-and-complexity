#include "helper.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MergeMetaData {
	size_t mid;
	size_t length;
} MergeMeta;

void merge_arr(void *arr, void *temp, MergeMeta meta, size_t byte_size,
			   int (*cmp)(const void *, const void *)) {
	memcpy(temp, arr, meta.length * byte_size);

	size_t right_len = meta.length - meta.mid;

	size_t left_idx = 0;
	size_t right_idx = 0;
	size_t i = 0;

	while (left_idx < meta.mid && right_idx < right_len) {
		void *value = NULL;

		void *left_value = temp + left_idx * byte_size;
		void *right_value = temp + (meta.mid + right_idx) * byte_size;

		if (cmp(left_value, right_value)) {
			value = left_value;
			left_idx++;
		} else {
			value = right_value;
			right_idx++;
		}

		memcpy(arr + i++ * byte_size, value, byte_size);
	}

	memcpy(arr + i * byte_size, temp + left_idx * byte_size,
		   byte_size * (meta.mid - left_idx));
	memcpy(arr + i * byte_size, temp + (meta.mid + right_idx) * byte_size,
		   byte_size * (right_len - right_idx));
}

void *strand_sort_array(const void *arr, size_t len, size_t byte_size,
						int (*cmp)(const void *, const void *),
						int (*cmp_merge)(const void *, const void *)) {
	///////////////////////
	// Memory Allocation //
	///////////////////////

	void *sorted = malloc(len * byte_size);
	size_t sorted_len = 0;

	if (sorted == NULL) {
		return NULL;
	}

	void *arr_copy = malloc(len * byte_size);

	if (arr_copy == NULL) {
		free(sorted);
		return NULL;
	}

	void *temp = malloc(len * byte_size);

	if (temp == NULL) {
		free(sorted);
		free(arr_copy);
		return NULL;
	}

	///////////////
	// Algorithm //
	///////////////

	while (len > 0) {
		// Pop the first element of the array.
		memcpy(sorted + sorted_len * byte_size, arr_copy, byte_size);

		if (--len > 0) {
			memmove(arr_copy, arr_copy + byte_size, len * byte_size);
		}

		size_t inserted_pos = 0;

		for (size_t i = 0; i < len; i++) {
			void *position = arr_copy + i * byte_size;

			if (cmp(position,
					sorted + (sorted_len + inserted_pos) * byte_size)) {
				// Pop the element from the array.
				memcpy(sorted + (sorted_len + ++inserted_pos) * byte_size,
					   position, byte_size);

				if ((i + 1) < len--) {
					memmove(arr_copy + i * byte_size,
							arr_copy + (i + 1) * byte_size,
							(len - i) * byte_size);
				}
			}
		}

		merge_arr(sorted, temp,
				  (MergeMeta){.mid = sorted_len,
							  .length = sorted_len + ++inserted_pos},
				  byte_size, cmp_merge);

		sorted_len += inserted_pos;
	}

	free(temp);
	free(arr_copy);

	return sorted;
}

Node *merge_ll_int(Node *left, Node *right,
				   int (*cmp)(const Node *, const Node *)) {
	Node *head = NULL;
	Node **curr = &head;

	while (left != NULL && right != NULL) {
		if (cmp(left, right)) {
			*curr = left;
			left = left->next;
		} else {
			*curr = right;
			right = right->next;
		}

		curr = &(*curr)->next;
	}

	*curr = left == NULL ? right : left;

	return head;
}

void strand_sort_ll_int(Node **head, int (*cmp)(const Node *, const Node *),
						int (*cmp_merge)(const Node *, const Node *)) {
	Node *sorted = NULL;

	while (*head != NULL) {
		Node *sublist = *head;
		*head = (*head)->next;
		sublist->next = NULL;

		Node **curr = head;

		while (*curr != NULL) {
			if (cmp((*curr), sublist)) {
				Node *temp = *curr;
				*curr = (*curr)->next;

				temp->next = sublist;
				sublist = temp;
			} else {
				curr = &(*curr)->next;
			}
		}

		if (sorted == NULL) {
			sorted = sublist;
		} else {
			sorted = merge_ll_int(sorted, sublist, cmp_merge);
		}
	}

	*head = sorted;
}
