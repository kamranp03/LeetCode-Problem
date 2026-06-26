# Problem 1895 - Largest Magic Square

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/largest-magic-square/
**Language:** C++

---

## Problem Statement
A `k x k` magic square is a `k x k` grid where every row sum, every column sum, and both diagonal sums are all equal. Given an `m x n` grid of integers, find the largest `k` such that a `k x k` magic square exists as a contiguous subgrid.

## Approach: Prefix Sums + Brute Force Square Checking

The key insight is to precompute row-wise and column-wise prefix sums so that any subgrid row/column sum can be computed in O(1). Then, iterate over all possible square sizes from largest to smallest and check every top-left corner position. The first valid magic square found (largest k) is returned immediately.

## Code Walkthrough (Step by Step)

1. **Build `rowCumSum`**: `rowCumSum[i][j]` = prefix sum of row `i` from column 0 to `j`.
2. **Build `colCumSum`**: `colCumSum[i][j]` = prefix sum of column `j` from row 0 to `i`.
3. **Iterate sizes** from `min(rows, cols)` down to `2`. For each size `side`:
   - For each valid top-left corner `(i, j)`:
     - Compute `tarSum` = sum of the first row of the candidate square using `rowCumSum`.
     - **Check all rows**: Use `rowCumSum` to get each row's sum and compare to `tarSum`. Break early if mismatch.
     - **Check all columns**: Use `colCumSum` to get each column's sum and compare to `tarSum`. Break early if mismatch.
     - **Check both diagonals**: Traverse the main diagonal (top-left to bottom-right) and anti-diagonal (top-right to bottom-left) by iterating `k` from 0 to `side-1`.
     - If all checks pass, return `side`.
4. **Return 1** if no magic square of size >= 2 is found (every single cell is a 1x1 magic square).

## Dry Run

**Example Input:**
```
grid = [[7, 1, 4, 5, 6],
        [2, 5, 1, 6, 4],
        [1, 5, 4, 3, 2],
        [1, 2, 7, 3, 4]]
```

Try side=3, top-left at (0,1): row sums = 1+4+5=10, 5+1+6=12 — mismatch, skip.
Try side=3, top-left at (1,1): row sums = 5+1+6=12, 5+4+3=12, 2+7+3=12. Col sums = 5+5+2=12, 1+4+7=12, 6+3+3=12. Diagonal = 5+4+3=12, anti-diagonal = 6+4+2=12. All match!

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n * min(m,n)²) | Iterating sizes, corners, and checking rows/cols/diagonals |
| **Space** | O(m * n) | Two prefix sum matrices of the same size as the grid |
