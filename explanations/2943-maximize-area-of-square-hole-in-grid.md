# Problem 2943 - Maximize Area of Square Hole in Grid

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
**Language:** C++

---

## Problem Statement

You have a grid of `(n+2) x (m+2)` cells with `n` horizontal bars and `m` vertical bars. You can remove some bars (given in `hBars` and `vBars`). Removing consecutive bars creates larger holes. Return the area of the largest square hole you can make.

## Approach: Find Maximum Consecutive Run in Each Direction

When consecutive numbered bars are all removed, they merge into a single larger opening. The side length of the opening equals the count of consecutive bars removed plus 1 (for the gap they create). We find the longest run of consecutive bar numbers in `hBars` and `vBars` separately. The largest square we can fit has side = `min(maxH + 1, maxV + 1)`.

## Code Walkthrough (Step by Step)

1. **Sort both `hBars` and `vBars`** to process bar numbers in order.

2. **Find max consecutive run in `hBars`:** Initialize `maxH = 1`, `curr = 1`. For each adjacent pair, if `hBars[i] == hBars[i-1] + 1`, increment `curr`; else reset to `1`. Track `maxH`.

3. **Find max consecutive run in `vBars`:** Same logic, result stored in `maxV`.

4. **Compute side length:** `side = min(maxH + 1, maxV + 1)`. Adding 1 converts "number of consecutive bars removed" into "gap width in cells."

5. **Return** `side * side`.

## Dry Run

**Example Input:** `n=2, m=1, hBars=[2,3], vBars=[2]`

- Sorted hBars = [2, 3] → consecutive run of 2 → maxH = 2
- Sorted vBars = [2] → single bar → maxV = 1
- side = min(2+1, 1+1) = min(3, 2) = 2
- area = 2 * 2 = 4

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(h log h + v log v) | Sorting both bar arrays |
| **Space** | O(1) | Only a few counters beyond the sorted arrays |
