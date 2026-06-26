# Problem 2536 - Increment Submatrices by One

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/increment-submatrices-by-one/
**Language:** C++

---

## Problem Statement

You are given an `n x n` integer matrix `mat` initialized with all zeros and a list of queries. Each query `[row1, col1, row2, col2]` asks you to increment all elements in the submatrix from `(row1, col1)` to `(row2, col2)` by 1. Return the resulting matrix after all queries are applied.

## Approach: 1D Difference Array Per Row

Instead of incrementing every cell in every submatrix (which would be O(n^2) per query), we apply a **difference array trick row by row**. For each row `i` in the range `[row1, row2]`, we mark `+1` at column `col1` and `-1` at column `col2+1`. After processing all queries, we compute the prefix sum across each row to restore the actual values.

The key insight is that a 2D range update can be decomposed into row-wise 1D difference array updates, reducing query cost from O(n^2) to O(n).

## Code Walkthrough (Step by Step)

1. **Initialize matrix:** Create an `n x n` matrix `mat` filled with zeros.

2. **Apply difference array per row:** For each query `[row1, col1, row2, col2]`, iterate over rows from `row1` to `row2`. For each such row `i`:
   - Add `+1` at `mat[i][col1]` (start of range).
   - Subtract `1` at `mat[i][col2+1]` if that column is within bounds (end marker).

3. **Prefix sum restoration:** After all queries, iterate each row and compute the running prefix sum from left to right. This converts the difference markers back into actual incremented values.

4. **Return** the final matrix.

## Dry Run

**Example Input:** `n = 3`, queries = `[[0,0,1,1]]`

After query processing (difference array markers):
```
mat[0][0] += 1, mat[0][2] -= 1  → row 0: [1, 0, -1]
mat[1][0] += 1, mat[1][2] -= 1  → row 1: [1, 0, -1]
row 2: [0, 0, 0]  (untouched)
```

After prefix sum per row:
```
row 0: [1, 1+0=1, 1-1=0]  → [1, 1, 0]
row 1: [1, 1,     0]       → [1, 1, 0]
row 2: [0, 0,     0]       → [0, 0, 0]
```

**Output:**
```
[[1,1,0],
 [1,1,0],
 [0,0,0]]
```

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(Q * n + n^2) | Q queries each touch at most n rows; prefix sum is O(n^2) |
| **Space** | O(n^2) | The output matrix itself |
