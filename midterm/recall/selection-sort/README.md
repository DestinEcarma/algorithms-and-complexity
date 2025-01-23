# Selection Sort

This is my implementation of the selection sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

for i = 0 to n - 1 do
    let min i = i

    for j = i + 1 to n - 1 do
        if A[j] < A[min i] then
            min i = j

    swap A[i] with A[min i]
```
