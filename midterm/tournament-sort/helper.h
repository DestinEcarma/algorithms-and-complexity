#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// Due to the nature of tournament sort, it is difficult to implement a generic
/// version.

/// This function is a tournament sort offline implementation for
/// integers.
int *tournament_sort_offline(const int *arr, size_t len);

/// This function is a tournament sort online V1 implementation for integers.
int *tournament_sort_online_v1(const int *arr, size_t len);

#endif
