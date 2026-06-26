# Problem 1877 - Minimize Maximum Pair Sum in Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
**Language:** C++

---

## Problem Statement
Given an even-length integer array `nums`, pair every element with exactly one other element so that all elements are covered. The pair sum is the sum of two paired elements. Return the minimum possible maximum pair sum across all pairs.

## Approach: Sort + Two Pointers (Greedy)

The key insight is that to minimize the maximum pair sum, we should pair the largest element with the smallest element, the second largest with the second smallest, and so on. Sorting the array and pairing elements from opposite ends achieves this greedily — balancing large values against small values keeps any single pair sum as low as possible.

## Code Walkthrough (Step by Step)

1. **Sort the array** in ascending order so the smallest element is at index 0 and the largest is at the last index.
2. **Initialize two pointers** `i = 0` (left/smallest) and `j = nums.size()-1` (right/largest).
3. **Track `maxS`** — the running maximum pair sum seen so far (starts at 0).
4. **Loop while `i < j`**: pair `nums[i]` with `nums[j]`, update `maxS` with their sum, then move `i` right and `j` left.
5. **Return `maxS`** — the minimum possible maximum pair sum.

## Dry Run

**Example Input:** `nums = [3, 5, 2, 3]`

After sort: `[2, 3, 3, 5]`

| i | j | nums[i] | nums[j] | pair sum | maxS |
|---|---|---------|---------|----------|------|
| 0 | 3 | 2       | 5       | 7        | 7    |
| 1 | 2 | 3       | 3       | 6        | 7    |

Loop ends (i == j is false, i=2, j=1 → i >= j).

**Output:** `7`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting dominates; the two-pointer loop is O(n) |
| **Space** | O(1) | Sorting in-place; only a few integer variables used |
