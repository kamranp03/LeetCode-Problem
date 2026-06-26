# Problem 733 - Flood Fill

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/flood-fill/
**Language:** C++

---

## Problem Statement
Given an `m x n` image represented as a 2D integer array, a starting pixel `(sr, sc)`, and a new color, perform a flood fill. Starting from `(sr, sc)`, change all connected pixels of the same original color (4-directionally) to the new color. Return the modified image.

## Approach: Depth-First Search (DFS) Recursion

The key insight is that flood fill is exactly graph traversal on a grid: starting from the source pixel, recursively visit all 4-directional neighbors that have the same original color and repaint them. The recursion naturally handles any shape of connected region.

## Code Walkthrough (Step by Step)

1. **Entry point `floodFill`:** Call `dfs(image, sr, sc, color, image[sr][sc])` where `oldColor = image[sr][sc]` captures the color to be replaced.

2. **`dfs(image, i, j, newColor, oldColor)` — recursive helper:**
   - **Boundary check:** If `i < 0`, `j < 0`, `i >= rows`, or `j >= cols` → return (out of bounds).
   - **Color check:** If `image[i][j] != oldColor` → return (wrong region; don't fill).
   - **Cycle prevention / already filled:** If `image[i][j] == newColor` → return (already painted; prevents infinite loops when newColor == oldColor).
   - **Paint:** Set `image[i][j] = newColor`.
   - **Recurse in all 4 directions:** top (i-1,j), right (i,j+1), bottom (i+1,j), left (i,j-1).

3. **Return the modified `image`.**

## Dry Run

**Example Input:**
```
image = [[1,1,1],
         [1,1,0],
         [1,0,1]]
sr=1, sc=1, color=2
```

oldColor = image[1][1] = 1

DFS from (1,1):
- Paint (1,1)=2. Recurse: top=(0,1), right=(1,2), bottom=(2,1), left=(1,0)
- (0,1)=1==oldColor: paint=2. Recurse top=(invalid at bounds? No), etc.
  - (0,0)=1: paint=2. Recurse: (0,-1) invalid, (-1,0) invalid, (1,0) already will be visited
  - (0,2)=1: paint=2. Recurse: neighbors are 0s or invalid
- (1,2)=0: 0!=oldColor → return
- (2,1)=0: 0!=oldColor → return
- (1,0)=1: paint=2. Recurse: (0,0) already 2, (2,0)=1: paint=2

Result:
```
[[2,2,2],
 [2,2,0],
 [2,0,1]]
```

**Output:** `[[2,2,2],[2,2,0],[2,0,1]]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m × n) | Each pixel is visited at most once |
| **Space** | O(m × n) | Recursion stack depth can reach the total number of pixels in worst case |
