# Problem 3379 - Transformed Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/transformed-array/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, construct a transformed array `ans` of the same length. For each index `i`, `ans[i]` is set to `nums[j]` where `j` is the index obtained by jumping `nums[i]` steps forward (positive) or backward (negative) from `i`, wrapping around in a circular fashion.

## Approach: Circular Index Arithmetic

The key insight is that moving `nums[i]` steps from index `i` in a circular array of size `n` gives target index `(i + nums[i]) % n`. We must handle negative remainders by adding `n` when the computed index is negative.

## Code Walkthrough (Step by Step)

1. **Compute size** `n` of the input array.
2. **Create result array** `ans` of size `n`.
3. **For each index `i`:** compute the target index `j = (i + nums[i]) % n`.
4. **Handle negatives:** The expression `j + (-(j < 0) & n)` adds `n` when `j` is negative (a branchless trick: `-(j<0)` is `-1` (all bits set) when `j < 0`, so `& n` gives `n`; otherwise `0`).
5. **Store result:** `ans[i] = nums[corrected_j]`.

## Dry Run

**Example Input:** `nums = [3, -2, 1, -1]`, n = 4

| i | nums[i] | j = (i + nums[i]) % 4 | corrected j | ans[i] |
|---|---------|----------------------|-------------|--------|
| 0 | 3       | (0+3)%4 = 3          | 3           | -1     |
| 1 | -2      | (1-2)%4 = -1         | -1+4 = 3    | -1     |
| 2 | 1       | (2+1)%4 = 3          | 3           | -1     |
| 3 | -1      | (3-1)%4 = 2          | 2           | 1      |

**Output:** `[-1, -1, -1, 1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(n) | Output array of size n |
