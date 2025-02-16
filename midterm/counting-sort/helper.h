#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// Due to the nature of counting sort, it is difficult to implement a generic
/// version.

/// This function is a counting sort implementation for integers.
int *counting_sort_int(const int *arr, size_t len);

/// This function is a counting sort implementation for integers, where the
/// count array is shifted by 1.
int *counting_sort_shifted_int(const int *arr, size_t len);

/// This function is a counting sort implementation for integers, where the
/// count array is shifted by 1 and the minimum and maximum values are known.
/// This allows for negative values to be sorted and minimizing the size of the
/// count array.
int *counting_sort_min_max_int(const int *arr, size_t len);

#endif
