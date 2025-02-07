# Merge Sort

This is my implementation of the merge sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

let T be a temporary array with the length of n

Merge(A, T, l, r, n):
    Copy A to T

    let i = 0

    let ll be the length of the left array (i.e. r)
    let rl be the length of the right array (i.e. n - r)

    let li = 0
    let ri = 0

    while li < ll and ri < rl do
        if A[li] < A[ri] then
            A[i++] = T[li++]
        else
            A[i++] = T[ri++]

    Copy T[li..ll] to A
    Copy T[(ll + ri)..n] to A

MergeSortRecursion(A, T, n):
    if n > 1 then
        let mid = n / 2

        MergeSortRecursion(A[0..mid], T, mid)
        MergeSortRecursion(B[mid..n], T, n - mid])

        Merge(A, t, 0, mid, n)

MergeSortIterative(A, T, n):
    for size = 1 to n - 1 : size = 2 * size do
        for start = 0 to n - 1 - size : start = start + 2 * size do
            let mid = start + size
            let end = min(size * 2, n)

            Merge(A, T, start, mid, end)
```
