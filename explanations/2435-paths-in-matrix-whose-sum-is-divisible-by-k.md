# Problem 2435 - Paths in Matrix Whose Sum Is Divisible by K

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
**Language:** C++

---

## Problem Statement
Given an `m x n` integer matrix and an integer `k`, return the number of paths from the top-left cell `(0,0)` to the bottom-right cell `(m-1, n-1)` where the path sum is divisible by `k`. You can only move right or down. Return the answer modulo 10^9 + 7.

## Approach: 3D Dynamic Programming (Remainder Tracking)

The key insight is to track not just reachability but the running sum modulo `k`. Define `t[i][j][rem]` = number of paths from `(i,j)` to `(m-1, n-1)` such that (current cell value + sum of remaining path) has remainder `rem` when divided by `k`. The answer is `t[0][0][0]`.

## Code Walkthrough (Step by Step)

1. **Base case** (bottom-right cell `(m-1, n-1)`): For each `rem` from 0 to k-1, `t[m-1][n-1][rem] = 1` if `(rem + grid[m-1][n-1]) % k == 0`, else 0.
2. **Fill DP from bottom-right to top-left** (reverse order):
   - For cell `(i,j)` and remainder `rem`:
     - Compute `R = (rem + grid[i][j]) % k` — what remaining remainder we need from the next cell.
     - `t[i][j][rem] = t[i+1][j][R] + t[i][j+1][R]` (go down or go right, mod M).
3. **Return `t[0][0][0]`**: paths from start with sum remainder 0 (divisible by k).

## Dry Run

**Example Input:**
```
grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
```

m=3, n=3, k=3.

Base case at (2,2): grid[2][2]=2.
- t[2][2][rem]: (rem+2)%3==0 → rem=1 → t[2][2][1]=1. Others=0.

Work backwards... (full table omitted for brevity)

Final answer `t[0][0][0]` = number of paths with sum divisible by 3.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n * k) | Three nested loops over grid cells and remainders |
| **Space** | O(m * n * k) | 3D DP table of size (m+1)×(n+1)×(k+1) |
