# Problem 3531 - Count Covered Buildings

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-covered-buildings/
**Language:** C++

---

## Problem Statement

Given an `n x n` grid and a list of building coordinates `(x, y)`, count buildings that are "covered" — meaning there exists another building in the same row with a smaller x-coordinate AND another with a larger x-coordinate, AND another building in the same column with a smaller y-coordinate AND another with a larger y-coordinate.

## Approach: Range Tracking per Row and Column

For each row (y-value), track the minimum and maximum x-coordinate of buildings in that row. For each column (x-value), track the minimum and maximum y-coordinate. A building at `(x, y)` is covered if it is strictly between the row's x-min and x-max, and strictly between the column's y-min and y-max.

## Code Walkthrough (Step by Step)

1. **Initialize** `maxRow[y]`, `minRow[y]` (x-range for each row y), and `maxCol[x]`, `minCol[x]` (y-range for each column x).
2. **First pass:** for each building `(x, y)`, update the min/max x for row `y` and min/max y for column `x`.
3. **Second pass:** for each building `(x, y)`, check if:
   - `x > minRow[y]` and `x < maxRow[y]` (covered horizontally)
   - `y > minCol[x]` and `y < maxCol[x]` (covered vertically)
   - If both true, increment result.
4. **Return** `res`.

## Dry Run

**Example Input:** `n=5`, `buildings = [[1,1],[1,3],[3,1],[3,3],[2,2]]`

- Row y=1: min_x=1, max_x=3. Row y=3: min_x=1, max_x=3. Row y=2: min_x=2, max_x=2.
- Col x=1: min_y=1, max_y=3. Col x=3: min_y=1, max_y=3. Col x=2: min_y=2, max_y=2.
- Building (2,2): minRow[2]=2, maxRow[2]=2. 2>2? No. Not covered.
- Buildings at corners are not covered (they are the min/max).

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m) | Two passes over m buildings |
| **Space** | O(n) | Arrays of size n+1 for row/column ranges |
