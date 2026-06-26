# Problem 88 - Merge Sorted Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/merge-sorted-array/
**Language:** C++

---

## Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n` representing the number of valid elements in `nums1` and `nums2` respectively. Merge `nums2` into `nums1` as one sorted array in-place. `nums1` has a total length of `m + n` to accommodate the extra elements.

## Approach: Three Pointers from the End (Reverse Merge)

The key insight is to fill `nums1` from the back instead of the front. Since `nums1` has `m + n` slots and only the first `m` are valid, the last `n` positions are free. By comparing elements from the ends of both valid portions and placing the larger one at position `k = m + n - 1`, we avoid overwriting elements we still need to process. This eliminates the need for any extra array.

## Code Walkthrough (Step by Step)

1. **Initialize three pointers:**
   - `i = m - 1` → points to the last valid element of `nums1`
   - `j = n - 1` → points to the last element of `nums2`
   - `k = m + n - 1` → points to the last position of the merged array (in `nums1`)

2. **Compare and place from the back:** While both `i >= 0` and `j >= 0`:
   - If `a[i] > b[j]`, place `a[i]` at `a[k]` and decrement `i`.
   - Otherwise, place `b[j]` at `a[k]` and decrement `j`.
   - Decrement `k` after each placement.

3. **Copy remaining elements of `nums2`:** If `j >= 0` still (meaning `nums2` still has elements), copy them into `nums1`. Note: if `i >= 0` remaining, those elements are already in place in `nums1`, so no action needed.

## Dry Run

**Example Input:** `nums1 = [1,2,3,0,0,0]`, m=3, `nums2 = [2,5,6]`, n=3

| Step | i | j | k | a[k] placed |
|------|---|---|---|-------------|
| 1 | 2 | 2 | 5 | max(3,6)=6 from b → a[5]=6 |
| 2 | 2 | 1 | 4 | max(3,5)=5 from b → a[4]=5 |
| 3 | 2 | 0 | 3 | max(3,2)=3 from a → a[3]=3 |
| 4 | 1 | 0 | 2 | max(2,2)=2 from b → a[2]=2 |
| 5 | 1 | -1 | 1 | j<0, loop ends |

Remaining j<0, nothing to copy. Result: `[1,2,2,3,5,6]`

**Output:** `nums1 = [1,2,2,3,5,6]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m + n) | Each element from both arrays is placed exactly once |
| **Space** | O(1) | Merge is done in-place with no extra arrays |
