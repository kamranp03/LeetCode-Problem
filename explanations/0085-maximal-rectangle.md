# Problem 85 - Maximal Rectangle

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/maximal-rectangle/
**Language:** C++

---

## Problem Statement

Given a `rows x cols` binary matrix filled with `'0'`s and `'1'`s, find the largest rectangle containing only `'1'`s and return its area. The rectangle must be axis-aligned (rows and columns aligned).

## Approach: Row-by-Row Histogram + Largest Rectangle in Histogram (Stack)

The key insight is to reduce the 2D problem to a series of 1D problems. For each row, build a "heights" array where `heights[j]` represents the number of consecutive `'1'`s ending at the current row in column `j`. Each row's heights array forms a histogram, and finding the largest rectangle in that histogram (using a monotonic stack) gives the best rectangle ending at that row. Take the maximum across all rows.

## Code Walkthrough (Step by Step)

**Part 1: `largestRectangleArea` (Monotonic Stack)**

1. **Sentinel:** Append `0` to `heights` to flush all remaining bars at the end.

2. **Monotonic stack:** Maintain a stack of indices where heights are in increasing order. For each index `i`:
   - While the stack is not empty and `heights[stack.top()] > heights[i]` (current bar is shorter), pop the top index `h_idx`. The height of this bar is `heights[h_idx]`.
   - Width: if the stack is now empty, the bar could span from index 0 to `i-1`, so width = `i`. Otherwise, width = `i - stack.top() - 1`.
   - Update `maxArea = max(maxArea, height * width)`.
3. Push current index `i` onto the stack.

**Part 2: `maximalRectangle` (Build Histograms)**

1. Initialize `heights` vector of size `cols` to all zeros.

2. For each row `i`:
   - Update `heights[j]`: if `matrix[i][j] == '1'`, increment `heights[j]`; otherwise reset to `0`.
   - Call `largestRectangleArea(heights)` and update global answer `ans`.

3. Return `ans`.

## Dry Run

**Example Input:**
```
matrix = [['1','0','1','0','0'],
          ['1','0','1','1','1'],
          ['1','1','1','1','1'],
          ['1','0','0','1','0']]
```

- Row 0 heights: `[1,0,1,0,0]` → max rect = 1
- Row 1 heights: `[2,0,2,1,1]` → max rect = 3
- Row 2 heights: `[3,1,3,2,2]` → max rect = 6
- Row 3 heights: `[4,0,0,3,0]` → max rect = 4

**Output:** `6`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(rows * cols) | Each row processes cols elements; histogram step is O(cols) amortized |
| **Space** | O(cols) | Heights array and stack each hold at most cols elements |
