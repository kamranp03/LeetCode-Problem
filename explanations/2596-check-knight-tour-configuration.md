# Problem 2596 - Check Knight Tour Configuration

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/check-knight-tour-configuration/
**Language:** C++

---

## Problem Statement

You are given an `n x n` grid where each cell contains a number from `0` to `n*n - 1`, representing the order in which a knight visits each cell. Return `true` if the sequence of moves is a valid knight's tour starting at `(0, 0)` with move `0`, and `false` otherwise.

## Approach: Recursive DFS / Backtracking Verification

We perform a depth-first search starting from cell `(0, 0)` with expected value `0`. At each step, we check if the current cell holds the expected sequence number, then try all 8 possible knight moves to find the cell with the next sequence number. If we reach the last step (`n*n - 1`) at a valid cell, the tour is valid.

The key insight is that a valid tour is uniquely determined by the sequence values in the grid — there is exactly one correct next cell at each step.

## Code Walkthrough (Step by Step)

1. **Base case (out of bounds or wrong value):** If the current `(row, col)` is out of the grid or `grid[row][col] != exval`, return `false`.

2. **Success case:** If `exval == n*n - 1`, we have successfully visited all cells in valid knight-move order — return `true`.

3. **Try all 8 knight moves:** From `(row, col)`, a knight can jump to 8 positions:
   - `(-2,+1), (-1,+2), (+1,+2), (+2,+1), (+2,-1), (+1,-2), (-1,-2), (-2,-1)`
   - Recursively call `knightT` for each with `exval + 1`.

4. **Return** the logical OR of all 8 recursive results.

5. **Entry point:** `checkValidGrid` calls `knightT(grid, 0, 0, n, 0)` — must start at `(0,0)` with sequence number `0`.

## Dry Run

**Example Input:** `grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]` (5x5 valid tour)

- Start: `(0,0)`, expected value `0` — grid[0][0] = 0 ✓
- Try 8 moves → find `(2,1)` where grid[2][1] = 1 ✓
- Continue until exval = 24 = n*n-1 ✓

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2) | Each cell is visited exactly once in a valid tour; 8 branches but only one is valid |
| **Space** | O(n^2) | Recursion stack depth equals total cells |
