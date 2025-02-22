#ifndef STRAND_SORT_HELPER_H
#define STRAND_SORT_HELPER_H

#include "./../../common/linked-list.h"
#include <stddef.h>

/// This function is a generic strand sort implementation. Be it a integer,
/// float, or even a object/structure, this function can sort those array.
void *strand_sort_array(const void *arr, size_t len, size_t byte_size,
						int (*cmp)(const void *, const void *),
						int (*cmp_merge)(const void *, const void *));

/// This function is a generic strand sort implementation. Be it a integer,
/// float, or even a object/structure, this function can sort those linked list.
void strand_sort_ll_int(Node **head, int (*cmp)(const Node *, const Node *),
						int (*cmp_merge)(const Node *, const Node *));

#endif
