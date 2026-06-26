# Problem 268 - Missing Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/missing-number/
**Language:** C++

---

## Problem Statement
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the one number in that range that is missing from the array. There is exactly one missing number.

## Approach: Sort and Linear Scan

After sorting the array, each element at index `i` should equal `i` if no number is missing up to that point. The first index where `nums[i] != i` reveals the missing number. If all elements match their indices, the missing number is `n` (the last value in the range).

## Code Walkthrough (Step by Step)

1. **Sort the array:** `sort(nums.begin(), nums.end())` arranges elements in ascending order.

2. **Scan for mismatch:** Iterate from `i = 0` to `n-1`. If `nums[i] != i`, return `i` — this index is the missing number.

3. **Return last element + 1:** If every index matched its value, the missing number is `nums[n-1] + 1`, which equals `n`.

## Dry Run

**Example Input:** `nums = [3, 0, 1]`, `n = 3`

After sorting: `[0, 1, 3]`

Scan:
- `i=0`: nums[0]=0 == 0 → match
- `i=1`: nums[1]=1 == 1 → match
- `i=2`: nums[2]=3 != 2 → return 2

**Output:** `2`

**Example Input:** `nums = [0, 1]`, `n = 2`

After sorting: `[0, 1]`

Scan:
- `i=0`: 0==0 → match
- `i=1`: 1==1 → match

Loop ends. Return `nums[1] + 1 = 2`.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Dominated by sorting; the scan is O(n) |
| **Space** | O(1) | Sorting in place; no extra data structures |
