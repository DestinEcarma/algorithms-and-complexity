# Comb Sort

This is my implementation of the comb sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

let gap = n
let swapped = true

while gap > 1 or swapped is true do
    set swapped to false
    set gap to gap / 1.3

    if gap < 1 then
        set gap to 1

    for i = 0 to n - gap - 1 do
        if A[i] > A[i + gap] then
            swap A[i] and A[i + gap]
            set swapped to true
```
