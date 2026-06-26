# Problem 1752 - Check if Array Is Sorted and Rotated

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
**Language:** C++

---

## Problem Statement

Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return `false`.

## Approach: Count Descent Points

The key insight is that a sorted and rotated array can have at most one "descent" — a position where `nums[i] > nums[(i+1) % n]`. If there are zero or one such descents, the array is a valid sorted rotation. Two or more descents mean it cannot be a rotation of a sorted array.

## Code Walkthrough (Step by Step)

1. **Initialize `count = 0`** and `n = nums.size()`.
2. **Loop `i` from 0 to n-1:** Compare `nums[i]` with `nums[(i+1) % n]` (wraps around using modulo).
3. **If `nums[i] > nums[(i+1) % n]`:** Increment `count` (found a descent point).
4. **Return `count <= 1`:** If at most one descent exists, the array is a valid rotation.

## Dry Run

**Example Input:** `nums = [3,4,5,1,2]`

- i=0: 3 < 4 → no descent
- i=1: 4 < 5 → no descent
- i=2: 5 > 1 → count=1 (the rotation point)
- i=3: 1 < 2 → no descent
- i=4: 2 < 3 (wrap: nums[4]=2 > nums[0]=3? No: 2 < 3) → no descent
- count=1 ≤ 1 → **true**

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only a counter variable |
