# Problem 1458 - Max Dot Product of Two Subsequences

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/max-dot-product-of-two-subsequences/
**Language:** C++

---

## Problem Statement

Given two integer arrays `nums1` and `nums2`, return the maximum dot product between non-empty subsequences of `nums1` and `nums2` with the same length. The dot product of sequences of equal length is the sum of `nums1[i] * nums2[j]` for all selected pairs.

## Approach: Top-Down Dynamic Programming (Memoization)

The key insight is to define `solve(i, j)` = the maximum dot product using elements from `nums1[i..m-1]` and `nums2[j..n-1]`. At each position, we choose to either pair `nums1[i]` with `nums2[j]` (and optionally continue), or skip one of the elements. The memoization table avoids recomputing states.

## Code Walkthrough (Step by Step)

1. **Base case:** If `i == m` or `j == n`, return `-1e9` (no elements left, cannot form a valid pair — must pick at least one pair).
2. **Memoization check:** If `t[i][j] != -1e9`, return cached result.
3. **Compute options:**
   - `val = nums1[i] * nums2[j]` — take just this one pair
   - `take_i_j = val + solve(i+1, j+1)` — take this pair and continue matching
   - `take_i = solve(i, j+1)` — skip nums2[j]
   - `take_j = solve(i+1, j)` — skip nums1[i]
4. **Store and return** `max({val, take_i_j, take_i, take_j})`.
5. **Main function:** Initialize `t` with `-1e9`, then call `solve(0, 0)`.

## Dry Run

**Example Input:** `nums1 = [2,1,-2,5]`, `nums2 = [3,0,-6]`

- Best pairing: nums1[0]*nums2[0] + nums1[3]*nums2[2] = 2*3 + 5*(-6) = 6 - 30 = -24
- Or: nums1[3]*nums2[0] = 5*3 = 15
- Maximum = **18** (nums1[0]*nums2[2] + nums1[3]*nums2[2]... DP finds optimal)

**Output:** `18`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n) | Each (i,j) state computed at most once |
| **Space** | O(m * n) | Memoization table of size 501x501 |
