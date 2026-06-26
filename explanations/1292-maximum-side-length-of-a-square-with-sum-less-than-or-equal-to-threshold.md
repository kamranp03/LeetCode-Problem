# Problem 1292 - Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
**Language:** C++

---

## Problem Statement

Given an `m x n` integer matrix `mat` and an integer `threshold`, return the maximum side length of a square submatrix whose sum is less than or equal to `threshold`. If no such square exists, return 0.

## Approach: Binary Search + Row Prefix Sums

The key insight is to binary search on the answer (the side length), and for each candidate side, check whether any square of that size fits within the threshold. Row prefix sums are precomputed to quickly sum any rectangular region row by row, making each check efficient.

## Code Walkthrough (Step by Step)

1. **Build row prefix sums:** For each row `i`, `row[i][j]` stores the sum of elements from column 0 to column `j` in that row. This allows O(1) sum queries for any row range.
2. **Binary search on side length** from 0 to `min(n, m)`. The mid-point is the candidate side.
3. **For each candidate side `s`**, try all possible top-left corners `(i, j)` of a square. Sum the rows within the square using the prefix rows — each row's contribution is `row[r][j+s-1] - (j>0 ? row[r][j-1] : 0)`.
4. **If `sum <= threshold`**, set `flag = true`, record this side as the answer, and search the right half (larger sides).
5. **If no valid square found**, search the left half (smaller sides).
6. **Return `ans`** — the largest valid side length found.

## Dry Run

**Example Input:** `mat = [[1,1,3],[1,1,3],[1,1,3]]`, `threshold = 5`

- Row prefix sums: `row = [[1,2,5],[1,2,5],[1,2,5]]`
- Binary search: try side=2 → square at (0,0): rows 0 and 1, cols 0-1 → (2-0)+(2-0)=4 ≤ 5 → valid
- Try side=3 → sum of entire matrix = 15 > 5 → invalid
- Answer = **2**

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * m * min(n,m)) | Binary search (log) * O(side * m * n) check per candidate |
| **Space** | O(n * m) | Row prefix sum matrix |
