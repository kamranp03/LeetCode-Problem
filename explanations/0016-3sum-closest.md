# Problem 0016 - 3Sum Closest

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/3sum-closest/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `target`, find three integers in `nums` such that their sum is closest to `target`. Return the sum of the three integers. Exactly one answer is guaranteed.

## Approach: Sort + Two Pointers

This is a variant of 3Sum. After sorting, we fix one element and use two pointers to explore all pairs. At each step we track the closest sum seen so far by comparing the absolute difference between the current three-sum and the target. The sorted order lets us deterministically move the left or right pointer to bring the sum closer to target.

## Code Walkthrough (Step by Step)

1. **Sort** `nums`.
2. **Initialize** `maxDiff = INT_MAX` and `resSum = 0`.
3. **Outer loop** over `i` from `0` to `n-3`:
   - Set `left = i+1`, `right = n-1`.
4. **Inner two-pointer loop** while `left < right`:
   - Compute `total = nums[i] + nums[left] + nums[right]`.
   - Compute `diff = abs(total - target)`.
   - If `diff < maxDiff`: update `maxDiff = diff` and `resSum = total`.
   - If `total == target`: return immediately (perfect match).
   - If `total > target`: `right--` (sum is too large, reduce it).
   - Else: `left++` (sum is too small, increase it).
5. **Return `resSum`.**

## Dry Run

**Example Input:** `nums = [-1, 2, 1, -4]`, `target = 1`

After sorting: `[-4, -1, 1, 2]`

| i | nums[i] | left | right | total         | diff | maxDiff | resSum |
|---|---------|------|-------|---------------|------|---------|--------|
| 0 | -4      | 1    | 3     | -4+-1+2 = -3  | 4    | 4       | -3     |
| 0 | -4      | 2    | 3     | -4+1+2 = -1   | 2    | 2       | -1     |
| 0 | -4      | 3    | 3     | loop ends     | —    | —       | —      |
| 1 | -1      | 2    | 3     | -1+1+2 = 2    | 1    | 1       | 2      |
| 1 | -1      | 2    | 2     | loop ends     | —    | —       | —      |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n²) | O(n log n) sort + O(n) two-pointer per outer element |
| **Space** | O(1) | In-place sort, constant extra variables |
