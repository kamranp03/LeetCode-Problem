# Problem 2540 - Minimum Common Value

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-common-value/
**Language:** C++

---

## Problem Statement

Given two integer arrays `nums1` and `nums2`, both sorted in non-decreasing order, return the minimum integer common to both arrays. If no common integer exists, return `-1`.

## Approach: Two Pointers

Since both arrays are already sorted, we can use two pointers — one for each array — and advance the pointer pointing to the smaller value. When both pointers point to the same value, we have found the minimum common element and return it immediately.

This avoids building a hash set and achieves linear time by exploiting the sorted order.

## Code Walkthrough (Step by Step)

1. **Initialize two pointers** `i = 0` and `j = 0`, starting at the beginning of `nums1` and `nums2` respectively.

2. **Loop** while both pointers are within bounds:
   - If `nums1[i] == nums2[j]`: the current values match — return this value immediately (it is the minimum common since we traverse left to right).
   - If `nums1[i] < nums2[j]`: advance `i` to try a larger value from `nums1`.
   - Otherwise: advance `j` to try a larger value from `nums2`.

3. If the loop ends without finding a match, **return -1**.

## Dry Run

**Example Input:** `nums1 = [1, 2, 3]`, `nums2 = [2, 4]`

| i | j | nums1[i] | nums2[j] | Action |
|---|---|----------|----------|--------|
| 0 | 0 | 1 | 2 | 1 < 2, advance i |
| 1 | 0 | 2 | 2 | Equal! Return 2 |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n + m) | Each pointer advances at most n and m steps respectively |
| **Space** | O(1) | Only two integer pointers used |
