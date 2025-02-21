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

/// Compare `a` is less than or equal to `b` integers.
static inline int cmp_int_leq(const void *a, const void *b) {
	return *(int *)a <= *(int *)b;
}

/// Compare `a` is greater than or equal to `b` integers.
static inline int cmp_int_geq(const void *a, const void *b) {
	return *(int *)a >= *(int *)b;
}

#endif
