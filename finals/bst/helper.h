#ifndef BST_HELPER_H
#define BST_HELPER_H

#include "./../../common/doubly-linked-list.h"

void bst_insert(DNode **root, const void *value, size_t byte_size,
				int (*cmp)(const DNode *, const DNode *));

void bst_delete(DNode **root, const void *value, size_t byte_size,
				int (*diff)(const DNode *, const DNode *));

#endif
