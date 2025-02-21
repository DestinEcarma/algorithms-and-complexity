# Shell Sort

This is my implementation of the shell sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

for gap = (n / 2) to 0 : gap = gap / 2 do
    for i = gap to (n - 1) do
        let key = A[i]
        let j = i

        while j >= gap and A[j - gap] > key do
            insert A[j - gap] into A[j]
            set j to j - gap

        set A[j] to key
```
