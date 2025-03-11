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
        set tree[i] to (i - n)

    let start = k - 1

    for i = 0 to (n - 1) do
        for right = start to 1 : right = right - 2 do
            let left = right - 1
            let parent = left / 2

            if temp[tree[left]] <= temp[tree[right]] then
                set tree[parent] to tree[left]
            else
                set tree[parent] to tree[right]

        set A[i] to temp[tree[0]]
        set temp[tree[0]] to INFINITY

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
                    set tree[parent] to left
                else
                    set tree[parent] to right
            else
                if tree[tree[left]] <= tree[tree[right]] then
                    set tree[parent] to tree[left]
                else
                    set tree[parent] to tree[right]

        set A[i] to tree[tree[0]]

        if i < (n - 4) then
            set tree[tree[0]] to A[i + 4]
        else
            set tree[tree[0]] to INFINITY

    Sort the partial sorted array A (e.g. Merge Sort)

TournamentSortOnlineK2(A, n)
    let tree be an array of length 7

    let partial sorted be a 2D array of length 2, such that both arrays have length of n

    for i = 3 to 6 do
        tree[i] = i - 3

    let k = 0

    for i = 0 to (n - 1) do
        let pushed = false

        for right = 6 to 1 : right = right - 2 do
            let left = right - 1
            let parent = left / 2

            let left flagged = false
            let right flagged = false

            if partial sorted[k] is not empty then
                if tree[tree[left]] < last element of partial sorted[k] then
                    set left flagged to true

                if tree[tree[right]] < last element of partial sorted[k] only if any then
                    set right flagged to true

            if both left and right flagged are false then
                if tree[tree[left]] <= tree[tree[right]] then
                    set tree[parent] to tree[left]
                else
                    set tree[parent] to tree[right]

            else if left flagged is false then
                set tree[parent] to tree[left]
            else if right flagged is false then
                set tree[parent] to tree[right]

            if pushed is false then
                set pushed to left flagged xor right flagged

        if pushed is true then
            push tree[tree[0]] to partial sorted[k]

            if i < (n - 4) then
                set tree[tree[0]] to i + 4

        else
            increment k

            if k = 2 then
                merge both partial sorted arrays
                set k to 0

    if k = 1 then
        merge both partial sorted arrays

    return the merged array
```
