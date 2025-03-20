# Heap Sort

This is my implementation of the heap sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

heapify(A, n, i)
    let largest be i

    do
        let left = 2 * i + 1
        let right = 2 * i + 2

        if left < n and A[left] > A[largest]
            largest = left

        if right < n and A[right] > A[largest]
            largest = right

        if largest != i
            swap A[i] and A[largest]
            i = largest
    until largest == i

heapSort(A, n)
    for i = (n / 2 - 1) to 0
        heapify(A, n, i)

    for i = (n - 1) to 0
        swap A[0] and A[i]
        heapify(A, i, 0)
```
