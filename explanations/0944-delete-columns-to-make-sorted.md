# Problem 944 - Delete Columns to Make Sorted

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/delete-columns-to-make-sorted/
**Language:** C++

---

## Problem Statement
Given an array of strings all of equal length, we arrange the strings as rows of a grid. We want to delete the minimum number of columns so that each remaining column is sorted (non-decreasing) from top to bottom. Return the number of columns to delete.

## Approach: Column-by-Column Scan

For each column index, check if the characters in that column are in non-decreasing order across all rows. If any adjacent pair of rows has a character in this column that is greater in the earlier row, this column must be deleted — increment the counter and move to the next column immediately (no need to check further rows for this column).

## Code Walkthrough (Step by Step)

1. **Get dimensions:** `rows = strs.size()`, `cols = strs[0].length()`.

2. **Outer loop over columns `col` from 0 to cols-1:**
   - **Inner loop over rows `row` from 0 to rows-2:**
     - If `strs[row][col] > strs[row+1][col]`: column is unsorted — increment `count` and `break` out of inner loop.

3. **Return `count`** — total number of columns to delete.

## Dry Run

**Example Input:** `strs = ["cba", "daf", "ghi"]`

| Column | Values (top→bottom) | Sorted? |
|--------|---------------------|---------|
| 0      | c, d, g             | Yes     |
| 1      | b, a, h             | No (b > a) → delete |
| 2      | a, f, i             | Yes     |

count = 1

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(R * C) | Check each cell once; R = rows, C = columns |
| **Space** | O(1) | Only loop counters and a count variable |
