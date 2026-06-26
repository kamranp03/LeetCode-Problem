# Problem 960 - Delete Columns to Make Sorted III

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
**Language:** C++

---

## Problem Statement
Given an array of strings all of equal length, delete the minimum number of columns so that the remaining columns form non-decreasing sequences in every row simultaneously. That is, for every kept column pair `(i, j)` with `i < j`, it must hold that `strs[r][i] <= strs[r][j]` for all rows `r`. Return the number of columns deleted.

## Approach: Longest Increasing Subsequence (LIS) on Columns

Find the maximum number of columns we can KEEP such that they form a valid non-decreasing sequence across all rows simultaneously — this is equivalent to finding the LIS where the "ordering" between two columns `i` and `j` is defined as `strs[r][i] <= strs[r][j]` for ALL rows `r`. The answer is `total_columns - LIS_length`.

## Code Walkthrough (Step by Step)

1. **Define `dp[j]`** = length of the longest valid subsequence of columns ending at column `j`. Initialize all `dp[j] = 1`.

2. **Outer loop `j` from 0 to cols-1:** For each column `j`, try all previous columns `i < j`:
   - **Check validity:** Loop over all rows `r`. If `strs[r][i] > strs[r][j]`, column `i` cannot come before column `j` — set `valid = false` and break.
   - **If valid:** `dp[j] = max(dp[j], dp[i] + 1)`.
   - Update `longest = max(longest, dp[j])`.

3. **Return `cols - longest`** — the number of columns to delete.

## Dry Run

**Example Input:** `strs = ["babca", "bbazb"]`

Columns (0-indexed): 0='b','b' | 1='a','b' | 2='b','a' | 3='c','z' | 4='a','b'

- dp[0]=1: no prior column
- dp[1]=1: col 0→1: 'b'>'a' → invalid
- dp[2]=1: col 0→2: 'b'='b','b'>'a'→invalid; col 1→2: 'a'<'b','b'>'a'→invalid
- dp[3]=2: col 0→3: 'b'<'c','b'<'z'→valid, dp[3]=max(1,1+1)=2; col 1→3: 'a'<'c','b'<'z'→valid, dp[3]=max(2,1+1)=2; etc.
- dp[4]=2: col 0→4: 'b'>'a'→invalid; col 1→4: 'a'='a','b'='b'→valid, dp[4]=2; etc.

longest=2, cols=5, answer = 5-2 = 3

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(C^2 * R) | For each pair of columns, validate across all R rows |
| **Space** | O(C) | dp array of size equal to number of columns |
