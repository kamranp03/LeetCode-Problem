# Problem 3010 - Divide an Array Into Subarrays With Minimum Cost I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, divide it into exactly 3 non-empty subarrays. The cost of a division is the sum of the first elements of each subarray. The first subarray must start at index 0. Return the minimum possible cost of such a division.

## Approach: Find Two Smallest Elements from Index 1 Onward

The first subarray always starts at `nums[0]`, so `nums[0]` is always part of the cost. The second and third subarrays can start at any two positions in `nums[1..n-1]` (with the second before the third). To minimize cost, we pick the two smallest values from `nums[1..n-1]`. Their order in the array doesn't matter for the cost — we just need the two minimums.

## Code Walkthrough (Step by Step)

1. **Record** `first = nums[0]` (always included in cost).

2. **Find two smallest values** from `nums[1..n-1]`:
   - Initialize `min1 = INT_MAX`, `min2 = INT_MAX`.
   - For each `nums[i]` (i from 1 to n-1): if it's smaller than `min1`, update both; else if smaller than `min2`, update only `min2`.

3. **Return** `first + min1 + min2`.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 12]`

- `first = 1`
- Scan [2, 3, 12]:
  - 2 < INT_MAX → min1=2, min2=INT_MAX
  - 3 < INT_MAX (min2) → min2=3
  - 12 > min2 → no change
- Result: 1 + 2 + 3 = 6

**Output:** `6`

**Example Input:** `nums = [5, 4, 3]`

- first=5, scan [4,3]:
  - 4 → min1=4
  - 3 < 4 → min2=4, min1=3
- Result: 5 + 3 + 4 = 12

**Output:** `12`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass to find two minimums |
| **Space** | O(1) | Only three scalar variables |
