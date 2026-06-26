# Problem 3507 - Minimum Pair Removal to Sort Array I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
**Language:** C++

---

## Problem Statement

Given an integer array, repeatedly find the adjacent pair with the minimum sum, remove both elements, and insert their sum at that position (effectively merging them). Count the minimum number of such operations needed to make the array non-decreasing.

## Approach: Brute Force Simulation

For the Easy version (small input sizes), a direct simulation suffices. At each step, scan the array for the adjacent pair with the smallest sum, merge them, and repeat until the array is sorted.

## Code Walkthrough (Step by Step)

1. **`isSorted` helper:** checks if the array is already non-decreasing.
2. **While not sorted:**
   a. Scan all adjacent pairs to find the one with the minimum sum.
   b. Replace `nums[idx]` with `nums[idx] + nums[idx+1]`.
   c. Erase `nums[idx+1]` from the vector (shift left).
   d. Increment `count`.
3. **Return** `count`.

## Dry Run

**Example Input:** `nums = [5, 2, 3, 1]`

- Is sorted? No (5>2).
- Pairs: (5,2)=7, (2,3)=5, (3,1)=4. Min at idx=2. Merge: [5, 2, 4]. count=1.
- Is sorted? No (5>2).
- Pairs: (5,2)=7, (2,4)=6. Min at idx=1. Merge: [5, 6]. count=2.
- Is sorted? Yes (5<=6).

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^3) | Up to n merges, each scanning O(n) pairs; erase is O(n) |
| **Space** | O(1) | In-place modification of input vector |
