#ifndef CMP_H
#define CMP_H

/// Compare `a` is greater than `b` integers.
static inline int cmp_int_g(const void *a, const void *b) {
	return *(int *)a > *(int *)b;
}

#endif
