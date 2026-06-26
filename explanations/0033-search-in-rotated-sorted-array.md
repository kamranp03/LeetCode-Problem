# Problem 0033 - Search in Rotated Sorted Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/search-in-rotated-sorted-array/
**Language:** C++

---

## Problem Statement

Given a sorted integer array `nums` that has been rotated at an unknown pivot, and a `target` value, return the index of `target` if it exists, or `-1` if it does not. The algorithm must run in O(log n) time.

## Approach: Modified Binary Search

The key insight is that even after rotation, at least one half of the array (left or right of `mid`) must be sorted. We can check which half is sorted by comparing `nums[low]` with `nums[mid]`. Once we know which half is sorted, we check if `target` falls within that half's range — if yes, narrow the search to that half; if no, search the other half.

## Code Walkthrough (Step by Step)

1. **Initialize** `low = 0`, `high = nums.size() - 1`.
2. **Binary search loop** while `low <= high`:
   - Compute `mid = (low + high) / 2`.
   - If `nums[mid] == target`: return `mid`.
   - **Check if left half is sorted** (`nums[low] <= nums[mid]`):
     - If `target` is in range `[nums[low], nums[mid])`: `high = mid - 1` (search left).
     - Else: `low = mid + 1` (search right).
   - **Right half must be sorted** (else branch):
     - If `target` is in range `(nums[mid], nums[high]]`: `low = mid + 1` (search right).
     - Else: `high = mid - 1` (search left).
3. **Return `-1`** if target not found.

## Dry Run

**Example Input:** `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 0`

| low | high | mid | nums[mid] | Left sorted? | Action |
|-----|------|-----|-----------|--------------|--------|
| 0   | 6    | 3   | 7         | nums[0]=4 <= 7: Yes | target=0 not in [4,7) → low=4 |
| 4   | 6    | 5   | 1         | nums[4]=0 <= 1: Yes | target=0 in [0,1) → high=4 |
| 4   | 4    | 4   | 0         | nums[mid]==target | return 4 |

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Search space halves at every step |
| **Space** | O(1) | Only pointer variables, no extra data structures |
