# Problem 1391 - Check if There is a Valid Path in a Grid

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
**Language:** C++

---

## Problem Statement

Given an `m x n` grid where each cell contains a street type (1-6), determine if there is a valid path from the top-left corner `(0,0)` to the bottom-right corner `(m-1, n-1)`. Streets have fixed connection directions: type 1 connects left-right, type 2 connects up-down, types 3-6 are L-shaped corners.

## Approach: DFS with Bidirectional Connection Check

The key insight is that moving to a neighbor is valid only if the current cell's street connects to the neighbor AND the neighbor's street connects back to the current cell. The `directions` map defines valid exit directions for each street type, and we verify the reverse direction in the neighbor.

## Code Walkthrough (Step by Step)

1. **`directions` map:** Each street type maps to its two exit directions as `{di, dj}` pairs. For example, type 1 exits left `{0,-1}` and right `{0,1}`.
2. **`dfs(grid, i, j, visited)`:** If we've reached `(m-1, n-1)`, return true. Mark current cell visited.
3. **For each exit direction of `grid[i][j]`:** Compute the neighbor `(new_i, new_j)`. Skip if out of bounds or visited.
4. **Bidirectional check:** Look through the neighbor's exit directions and verify one points back to `(i, j)`. Only if valid, recurse into the neighbor.
5. **`hasValidPath`:** Initialize visited matrix and call `dfs(grid, 0, 0, visited)`.

## Dry Run

**Example Input:** `grid = [[2,4,3],[6,5,2]]`

- Start at (0,0): street type 2 (up/down), can go down to (1,0)
- (1,0): street type 6 (connects up and right), checks back to (0,0) — valid; moves right to (1,1)
- (1,1): street type 5, connects left and down — checks back to (1,0) — valid; can reach (1,2)
- (1,2): street type 2, checks back — valid; reaches bottom-right

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n) | Each cell visited at most once |
| **Space** | O(m * n) | Visited matrix + recursion stack |
