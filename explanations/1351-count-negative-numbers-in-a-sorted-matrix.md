# Problem 1351 - Count Negative Numbers in a Sorted Matrix

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
**Language:** C++

---

## Problem Statement

Given an `m x n` matrix `grid` that is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in the grid.

## Approach: Brute Force Linear Scan

The key insight for this simple solution is to iterate through every element of the grid and count those that are strictly less than zero. While a more optimal O(m+n) staircase approach exists, this direct scan is clean and sufficient for the given constraints.

## Code Walkthrough (Step by Step)

1. **Initialize `neg = 0`** to count negatives.
2. **Outer loop:** Iterate over each row `ch` in the grid using a range-based for loop.
3. **Inner loop:** Iterate over each column index `i` in the current row.
4. **Condition:** If `ch[i] < 0`, increment `neg`.
5. **Return `neg`** after scanning the entire grid.

## Dry Run

**Example Input:** `grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]`

- Row 0: -1 is negative → neg=1
- Row 1: -1 is negative → neg=2
- Row 2: -1, -2 are negative → neg=4
- Row 3: -1, -1, -2, -3 are negative → neg=8

**Output:** `8`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n) | Every element is visited exactly once |
| **Space** | O(1) | Only a counter variable is used |
