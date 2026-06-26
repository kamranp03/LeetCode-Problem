# Problem 1749 - Maximum Absolute Sum of Any Subarray

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, return the maximum absolute sum of any (possibly empty) subarray of `nums`. The absolute sum of a subarray is the absolute value of the sum.

## Approach: Dual Kadane's Algorithm

The key insight is that the maximum absolute sum is either the maximum subarray sum or the absolute value of the minimum subarray sum (most negative subarray). We run two Kadane's algorithms simultaneously — one for maximum subarray sum and one for minimum subarray sum — and return the larger absolute value.

## Code Walkthrough (Step by Step)

1. **Initialize:** `maxEnding = minEnding = maxSum = minSum = a[0]`.
2. **Iterate from `i = 1`:**
   - `maxEnding = max(a[i], maxEnding + a[i])` — Kadane's for maximum sum ending at i.
   - `minEnding = min(a[i], minEnding + a[i])` — Kadane's for minimum sum ending at i.
   - Update global `maxSum` and `minSum`.
3. **Return `max(abs(maxSum), abs(minSum))`** — the larger of the two extreme subarray sums.

## Dry Run

**Example Input:** `nums = [1,-3,2,3,-4]`

| i | a[i] | maxEnding | minEnding | maxSum | minSum |
|---|------|-----------|-----------|--------|--------|
| 0 | 1 | 1 | 1 | 1 | 1 |
| 1 | -3 | -2 | -3 | 1 | -3 |
| 2 | 2 | 2 | -1 | 2 | -3 |
| 3 | 3 | 5 | 2 | 5 | -3 |
| 4 | -4 | 1 | -2 | 5 | -3 |

max(abs(5), abs(-3)) = max(5, 3) = **5**

**Output:** `5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only four tracking variables |
