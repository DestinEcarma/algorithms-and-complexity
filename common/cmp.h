#ifndef CMP_H
#define CMP_H

/// Compare `a` is less than `b` integers.
static inline int cmp_int_l(const void *a, const void *b) {
	return *(int *)a < *(int *)b;
}

/// Compare `a` is greater than `b` integers.
static inline int cmp_int_g(const void *a, const void *b) {
	return *(int *)a > *(int *)b;
}

#endif
