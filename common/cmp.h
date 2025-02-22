#ifndef CMP_H
#define CMP_H

#include "linked-list.h"

/// Compare `a` is less than `b` integers.
static inline int cmp_int_l(const void *a, const void *b) {
	return *(int *)a < *(int *)b;
}

/// Compare `a` is greater than `b` integers.
static inline int cmp_int_g(const void *a, const void *b) {
	return *(int *)a > *(int *)b;
}

/// Compare `a` is less than or equal to `b` integers.
static inline int cmp_int_leq(const void *a, const void *b) {
	return *(int *)a <= *(int *)b;
}

/// Compare `a` is greater than or equal to `b` integers.
static inline int cmp_int_geq(const void *a, const void *b) {
	return *(int *)a >= *(int *)b;
}

/// Compare `a` is less than `b` Node integers.
static inline int cmp_ll_int_l(const Node *a, const Node *b) {
	return (int)a->value[0] < (int)b->value[0];
}

/// Compare `a` is greater than `b` Node integers.
static inline int cmp_ll_int_g(const Node *a, const Node *b) {
	return (int)a->value[0] > (int)b->value[0];
}

/// Compare `a` is less than or equal to `b` Node integers.
static inline int cmp_ll_int_leq(const Node *a, const Node *b) {
	return (int)a->value[0] <= (int)b->value[0];
}

/// Compare `a` is greater than or equal to `b` Node integers.
static inline int cmp_ll_int_geq(const Node *a, const Node *b) {
	return (int)a->value[0] >= (int)b->value[0];
}

#endif
