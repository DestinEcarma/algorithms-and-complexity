#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// Due to the nature of bucket sort, it is difficult to implement a generic
/// version.

/// This function is a radix LSD sort implementation for integers.
int *radix_lsd_sort_int(const int *arr, size_t len);

/// This function is a radix MSD sort implementation for integers.
int *radix_msd_sort_int(const int *arr, size_t len);

#endif
