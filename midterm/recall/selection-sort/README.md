# Selection Sort

This is my implementation of the selection sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

for i = 1 to n - 1 do
    let min i = i - 1

    for j = i to n - 1 do
        if A[j] < A[min i] then
            min i = j

    swap A[i - 1] with A[min i]
```
