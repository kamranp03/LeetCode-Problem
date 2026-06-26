# Problem 0026 - Remove Duplicates from Sorted Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place so that each unique element appears only once. Return the number of unique elements `k`. The first `k` elements of `nums` should hold the unique values in order.

## Approach: Two Pointers (Slow-Fast)

The key insight is that since the array is sorted, all duplicates are adjacent. We use two pointers: `i` (slow) tracks the position of the last confirmed unique element, and `j` (fast) scans ahead. Whenever `j` finds a value different from `nums[i]`, we advance `i` and overwrite `nums[i]` with the new unique value. This modifies the array in-place without extra space.

## Code Walkthrough (Step by Step)

1. **Handle empty array:** if `nums` is empty, return 0.
2. **Initialize `i = 0`** — `nums[0]` is always unique, so the first unique index starts at 0.
3. **Iterate `j` from 1 to `nums.size() - 1`:**
   - If `nums[j] != nums[i]`: a new unique value is found.
     - Increment `i`.
     - Copy `nums[j]` into `nums[i]`.
   - If `nums[j] == nums[i]`: skip (it's a duplicate of the last unique element).
4. **Return `i + 1`** — the count of unique elements (indices 0 through i, inclusive).

## Dry Run

**Example Input:** `nums = [1, 1, 2, 3, 3]`

| j | nums[j] | nums[i] | Action              | i | Array state       |
|---|---------|---------|---------------------|---|-------------------|
| 1 | 1       | 1       | duplicate, skip     | 0 | [1,1,2,3,3]       |
| 2 | 2       | 1       | new unique: i++, write | 1 | [1,2,2,3,3]   |
| 3 | 3       | 2       | new unique: i++, write | 2 | [1,2,3,3,3]   |
| 4 | 3       | 3       | duplicate, skip     | 2 | [1,2,3,3,3]       |

Return `i + 1 = 3`. First 3 elements: `[1, 2, 3]`

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array with two pointers |
| **Space** | O(1) | In-place modification, no extra data structures |
