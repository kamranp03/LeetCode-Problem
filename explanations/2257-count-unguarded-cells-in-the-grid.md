# Problem 2257 - Count Unguarded Cells in the Grid

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
**Language:** C++

---

## Problem Statement
Given an `m x n` grid with guards and walls, each guard can see all cells in the four cardinal directions until blocked by a wall or another guard. Return the number of cells that are neither occupied (by a guard or wall) nor guarded (seen by any guard).

## Approach: Simulation — Mark Guarded Cells in All Four Directions

The key insight is to simulate the visibility of each guard directly on the grid. Place guards (value 2) and walls (value 3) first, then for each guard, mark all visible cells (value 1) by scanning outward in each of the four directions until a wall or guard blocks the view. Finally, count cells that remain 0.

## Code Walkthrough (Step by Step)

1. **Initialize grid** of size `m x n` with 0.
2. **Place guards**: `grid[i][j] = 2` for each guard position.
3. **Place walls**: `grid[i][j] = 3` for each wall position.
4. **For each guard**, call `markG(row, col, grid)`:
   - **Up**: Scan `i` from `row-1` down to 0. Stop if `grid[i][col] == 2` (guard) or `3` (wall). Otherwise mark `grid[i][col] = 1`.
   - **Down**: Scan from `row+1` to `m-1` similarly.
   - **Left**: Scan `j` from `col-1` down to 0 in row `row`.
   - **Right**: Scan from `col+1` to `n-1` in row `row`.
5. **Count** all cells with `grid[i][j] == 0` (never marked or blocked).
6. **Return count**.

## Dry Run

**Example Input:** `m=4, n=6, guards=[[0,0],[1,1],[2,3]], walls=[[0,1],[2,2],[1,4]]`

After placing guards (2) and walls (3), run markG for each guard:
- Guard at (0,0): mark right until wall at (0,1); mark down until guard at (1,0)... etc.
- Each guard marks cells with 1 in its sightlines.
- Count remaining 0s.

**Output:** `7`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(g * (m + n) + m * n) | Each guard scans up to m+n cells; final count is O(m*n) |
| **Space** | O(m * n) | The simulation grid |
