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
        shift A[j - 1] into A[j]
        decrement j

    insert key into A[j]
```
