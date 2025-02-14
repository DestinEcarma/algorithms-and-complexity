#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a bucket sort implementation for integers. Making this
/// function generic can be possible but due to the nature of the bucket sort,
/// it makes it difficult to implement a generic version. The method being
/// utilized here is insert sorted, which does not need to sort individual
/// buckets.
int *bucket_sort_int(const int *arr, size_t len);

#endif
