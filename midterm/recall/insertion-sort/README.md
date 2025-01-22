# Insertion Sort

This is my implementation of the insertion sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

for i = 1 to n - 1 do
    let key = A[i]
    let j = i

    while j > 0 and A[j - 1] > key do
        A[j] = A[j - 1]
        j = j - 1

    A[j] = key
```
