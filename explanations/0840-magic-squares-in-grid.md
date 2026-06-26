# Problem 840 - Magic Squares In Grid

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/magic-squares-in-grid/
**Language:** C++

---

## Problem Statement
Given an `m x n` grid of integers, count how many 3x3 contiguous subgrids are "magic squares." A 3x3 magic square contains the distinct integers 1–9 and has every row, column, and both diagonals summing to 15.

## Approach: Brute Force Subgrid Validation

Slide a 3x3 window over every valid top-left corner position `(i, j)` in the grid (where `i + 2 < rows` and `j + 2 < cols`). For each position, call `isMagic()` to validate the subgrid. The `isMagic` function uses three checks: the center must be 5 (since in any 3x3 magic square using 1-9 the center is always 5), all 9 values must be distinct integers in [1,9], and all rows, columns, and diagonals must sum to 15.

## Code Walkthrough (Step by Step)

1. **Center check:** The center element `grid[r+1][c+1]` must equal 5. If not, skip immediately.

2. **Distinctness check:** Use a `seen` boolean array of size 10. For each of the 9 cells, verify the value is in [1,9] and hasn't been seen before.

3. **Row sum check:** For each of 3 rows, sum the 3 elements and verify it equals 15.

4. **Column sum check:** For each of 3 columns, sum the 3 elements and verify it equals 15.

5. **Diagonal check:** Verify both diagonals sum to 15.

6. **Outer loop:** Iterate `i` from 0 to `rows-3` and `j` from 0 to `cols-3`. Count valid magic squares.

## Dry Run

**Example Input:**
```
grid = [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
```

- Check (0,0): center=5, values={4,3,8,9,5,1,2,7,6} all distinct in 1-9.
  - Rows: 4+3+8=15, 9+5+1=15, 2+7+6=15 ✓
  - Cols: 4+9+2=15, 3+5+7=15, 8+1+6=15 ✓
  - Diags: 4+5+6=15, 8+5+2=15 ✓ → count=1
- Check (0,1): center=grid[1][2]=1, not 5 → skip

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(M * N) | Each 3x3 check is O(1) (fixed 9 cells); sliding window over all positions |
| **Space** | O(1) | Only a fixed-size `seen` array of 10 elements |
