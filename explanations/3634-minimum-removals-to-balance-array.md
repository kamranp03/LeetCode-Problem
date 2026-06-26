# Problem 3634 - Minimum Removals to Balance Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-removals-to-balance-array/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `k`, remove the minimum number of elements so that for every pair of remaining elements `(a, b)` with `a <= b`, the ratio `b / a <= k` (i.e., `b <= a * k`). Return the minimum number of removals.

## Approach: Sorting + Sliding Window

After sorting the array, the condition `max / min <= k` for any subarray is equivalent to `nums[j] <= nums[i] * k` for the rightmost and leftmost elements. Use a two-pointer (sliding window) approach on the sorted array to find the longest subarray where `nums[j] <= nums[i] * k`. The answer is `n - maxLen`.

## Code Walkthrough (Step by Step)

1. **Sort** `nums` ascending.
2. **Initialize** left pointer `i = 0`, `maxLen = 1`.
3. **For each right pointer `j`:** while `nums[j] > nums[i] * k` (window is invalid), advance `i`.
4. **Update** `maxLen = max(maxLen, j - i + 1)`.
5. **Return** `n - maxLen` (elements not in the largest valid window must be removed).

## Dry Run

**Example Input:** `nums = [1, 3, 7, 10]`, `k = 3`

- Sort: [1, 3, 7, 10].
- j=0, i=0: 1 <= 1*3=3. maxLen=1.
- j=1, i=0: 3 <= 1*3=3. maxLen=2.
- j=2, i=0: 7 <= 1*3=3? No. Advance i=1. 7 <= 3*3=9. maxLen=max(2,2)=2.
- j=3, i=1: 10 <= 3*3=9? No. Advance i=2. 10 <= 7*3=21. maxLen=max(2,2)=2.

n - maxLen = 4 - 2 = 2.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting dominates; sliding window is O(n) |
| **Space** | O(1) | Only pointers and max length |
