# Problem 1200 - Minimum Absolute Difference

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-absolute-difference/
**Language:** C++

---

## Problem Statement
Given an integer array, find all pairs of elements with the minimum absolute difference. Return a list of all such pairs `[a, b]` (with `a < b`) sorted in ascending order by the first element.

## Approach: Sort then Linear Scan

Once the array is sorted, the minimum absolute difference can only occur between adjacent elements. Sort the array, find the minimum difference by scanning adjacent pairs, then collect all adjacent pairs that achieve this minimum difference.

## Code Walkthrough (Step by Step)

1. **Sort** the array in ascending order.

2. **Find minimum difference:** Initialize `minDiff = INT_MAX`. Loop through adjacent pairs `(arr[i], arr[i+1])` and update `minDiff = min(minDiff, arr[i+1] - arr[i])`.

3. **Collect pairs:** Loop through adjacent pairs again. If `arr[i+1] - arr[i] == minDiff`, push `{arr[i], arr[i+1]}` to result.

4. **Return result.** The pairs are automatically in sorted order since the array was sorted.

## Dry Run

**Example Input:** `arr = [4, 2, 1, 3]`

- After sort: `[1, 2, 3, 4]`
- Adjacent differences: 2-1=1, 3-2=1, 4-3=1. minDiff=1.
- All pairs: (1,2), (2,3), (3,4)

**Output:** `[[1,2],[2,3],[3,4]]`

**Example Input:** `arr = [1, 3, 6, 10, 15]`

- After sort: `[1, 3, 6, 10, 15]`
- Adjacent differences: 2, 3, 4, 5. minDiff=2.
- Pairs with diff=2: (1,3)

**Output:** `[[1,3]]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N log N) | Sorting dominates; two linear scans are O(N) |
| **Space** | O(1) | Sorting is in-place; result array not counted as extra |
