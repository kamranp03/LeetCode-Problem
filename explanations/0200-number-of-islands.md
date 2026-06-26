# Problem 200 - Number of Islands

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/number-of-islands/
**Language:** C++

---

## Problem Statement

Given an `m x n` 2D binary grid where `'1'` represents land and `'0'` represents water, return the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.

## Approach: DFS with Visited Array (Flood Fill)

The key insight is to use DFS to "flood fill" each island. When we find an unvisited land cell (`'1'`), we increment the island counter and launch a DFS from that cell. The DFS marks all connected land cells as visited, so they won't trigger a new island count later. Each time DFS is launched from the outer loop, a new distinct island has been discovered.

## Code Walkthrough (Step by Step)

1. **Initialize:** Create a `vis` (visited) 2D boolean array of the same size as `grid`, all set to `false`.

2. **Outer loop:** Iterate over every cell `(i, j)`. If `grid[i][j] == '1'` AND `vis[i][j] == false` (unvisited land):
   - Call `dfs(grid, i, j, n, m, vis)`.
   - Increment `island++`.

3. **DFS function:**
   - **Return conditions (base cases):** Return immediately if `i < 0`, `j < 0`, `i >= n`, `j >= m` (out of bounds), `vis[i][j]` is true (already visited), or `grid[i][j] != '1'` (water cell).
   - **Mark visited:** `vis[i][j] = true`.
   - **Recurse in 4 directions:** Up `(i-1,j)`, Right `(i,j+1)`, Down `(i+1,j)`, Left `(i,j-1)`.

4. **Return `island`** count.

## Dry Run

**Example Input:**
```
grid = [['1','1','1','1','0'],
        ['1','1','0','1','0'],
        ['1','1','0','0','0'],
        ['0','0','0','0','0']]
```

- (0,0) = '1', unvisited → DFS floods all connected 1s: (0,0),(0,1),(0,2),(0,3),(1,0),(1,1),(1,3),(2,0),(2,1). island=1.
- All remaining '1' cells are already visited.
- Result: island = 1.

**Example 2:** `[['1','1','0'],['0','0','1']]` → Two separate islands → Output: `2`

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n) | Each cell is visited at most once by DFS |
| **Space** | O(m * n) | Visited array + recursion stack (at most m*n depth in worst case) |
