# Tournament Sort

This is my implementation of the Tournament sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

TournamentSortOffline(A, n)
    let k = n * 2 - 1

    let tree be an array of length k
    let temp be an axuliary array of length n

    Copy A to temp

    for i = n to k do
        tree[i - 1] = i - n

    let start = k - 1

    for i = 0 to (n - 1) do
        for right = start to 1 : right = right - 2 do
            let left = right - 1
            let parent = left / 2

            if temp[tree[left]] <= temp[tree[right]] then
                tree[parent] = tree[left]
            else
                tree[parent] = tree[right]

        A[i] = temp[tree[0]]
        temp[tree[0]] = INFINITY

        start = (k - (n - tree[0]) - 1) / 2 * 2 + 2

TournamentSortOnlineV1(A, n)
    let tree be an array of length 7

    for i = 3 to 6 do
        tree[i] = A[i - 3]

    for i = 0 to (n - 1) do
        for right = 6 to 1 : right = right - 2 do
            let left = right - 1
            let parent = left / 2

            if left >= 3 then
                if tree[left] <= tree[right] then
                    tree[parent] = left
                else
                    tree[parent] = right
            else
                if tree[tree[left]] <= tree[tree[right]] then
                    tree[parent] = tree[left]
                else
                    tree[parent] = tree[right]

        A[i] = tree[tree[0]]

        if i < (n - 4) then
            tree[tree[0]] = A[i + 4]
        else
            tree[tree[0]] = INFINITY

    Sort the partial sorted array A (e.g. Merge Sort)
```
