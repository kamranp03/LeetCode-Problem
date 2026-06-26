# Problem 955 - Delete Columns to Make Sorted II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
**Language:** C++

---

## Problem Statement
Given an array of strings all of equal length, delete the minimum number of columns so that the remaining columns, when read row by row, form lexicographically sorted strings. Unlike problem 944 (column-wise sort), here we need the entire row strings (formed by kept columns) to be sorted lexicographically.

## Approach: Greedy with Row-Comparison Tracking

Process columns left to right. For each column, check if keeping it would violate the lexicographic ordering of any row pair not yet "settled." A row pair `(r, r+1)` is "settled" if the prefix formed by kept columns already has `strs[r] < strs[r+1]` (strictly less). If a column causes any unsettled pair to have `strs[r][c] > strs[r+1][c]`, delete it. Otherwise keep it and mark newly settled pairs where `strs[r][c] < strs[r+1][c]`.

## Code Walkthrough (Step by Step)

1. **Initialize:** `alrdy[i] = false` for all row pairs — no pairs are settled yet. `deletion = 0`.

2. **For each column `c`:**
   - **Check for violations:** For each unsettled pair `r` where `!alrdy[r]`, if `strs[r][c] > strs[r+1][c]`, this column must be deleted — set `deleted = true`, increment `deletion`, and break.
   - **If deleted:** Skip to the next column (don't update `alrdy`).
   - **If kept:** For each unsettled pair where `strs[r][c] < strs[r+1][c]`, mark `alrdy[r] = true` — this pair is now settled by a strict less-than in this column.

3. **Return `deletion`.**

## Dry Run

**Example Input:** `strs = ["ba", "dc"]`

- c=0: strs[0][0]='b', strs[1][0]='d'. Not deleted (b<d). Mark alrdy[0]=true (b<d strictly).
- c=1: alrdy[0]=true → skip checking. Not deleted. deletion=0.

**Output:** `0` (both columns kept: "ba" < "dc" lexicographically? "b" < "d" so yes)

**Example Input:** `strs = ["zyx", "wvu"]`

- c=0: 'z' > 'w' → delete. deletion=1.
- c=1: 'y' > 'v' → delete. deletion=2.
- c=2: 'x' > 'u' → delete. deletion=3.

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(R * C) | Each column scanned against all row pairs |
| **Space** | O(R) | `alrdy` boolean array of size rows-1 |
