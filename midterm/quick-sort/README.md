# Quick Sort

This is my implementation of the Quick sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

QuickSortLomuto(A, li, hi):
    if li < hi then
        let pivot = A[hi]
        let i = li

        for j = li to (hi - 1) do
            if A[j] < pivot then
                swap A[i] and A[j]
                increment i

        swap A[i] and A[hi]

        Sort the left partition
        Sort the right partition

QuickSortHoare(A, li, hi):
    if li < hi then
        let pivot = A[li]

        let i = li - 1
        let j = hi + 1

        while i < j do
            increment i until A[i] >= pivot
            increment j until A[j] <= pivot

            if i < j then
                swap A[i] and A[j]

        Sort the left partition
        Sort the right partition
```
