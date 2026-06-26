# Problem 3651 - Minimum Cost Path with Teleportations

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-cost-path-with-teleportations/
**Language:** C++

---

## Problem Statement

Given an `m x n` grid where each cell has a value, find the minimum cost to travel from the top-left `(0,0)` to the bottom-right `(m-1,n-1)`. You can move right or down normally (cost = value of the destination cell). Additionally, you have `k` "teleportation" tokens: a teleport lets you jump to any cell with the same value as your current cell for free. Find the minimum cost.

## Approach: Reverse DP + Iterative Teleport Passes

Work backwards: compute `dp[i][j]` = minimum cost to reach the bottom-right from `(i,j)`. Base: `dp[m-1][n-1]=0`. Normal moves: `dp[i][j] = min(grid[i+1][j] + dp[i+1][j], grid[i][j+1] + dp[i][j+1])`. Then apply `k` teleportation passes, each time allowing cells of the same value to share the best dp value (since teleporting is free, any cell with the same value can inherit the minimum dp among all same-value cells).

## Code Walkthrough (Step by Step)

1. **Initialize dp** with reverse DP (standard bottom-right to top-left).
2. **Sort cells** by `grid` value to group same-valued cells together.
3. **For each of `k` teleportation tokens:**
   a. Scan sorted cells; for each group of same-value cells, find the minimum `dp` in that group (`best`).
   b. Update every cell in the group: `dp[x][y] = min(dp[x][y], best)`.
   c. Re-run normal reverse DP to propagate these improvements.
4. **Return** `dp[0][0]`.

## Dry Run

**Example Input:** `grid=[[1,2],[2,1]]`, `k=1`

- Reverse DP: dp[1][1]=0, dp[0][1]=1+0=1, dp[1][0]=1+0=1, dp[0][0]=min(2+1,2+1)=3.
- k=1 pass: value-1 cells: (0,0)→dp=3, (1,1)→dp=0. best=0. Update dp[0][0]=min(3,0)=0.
- Re-run reverse DP from bottom-right: dp[0][0] stays 0.
- Return dp[0][0]=0.

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(k * m * n) | k teleportation passes each with an O(mn) DP sweep |
| **Space** | O(m * n) | DP table and sorted cell list |
