# Problem 209 - Minimum Size Subarray Sum

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-size-subarray-sum/
**Language:** C++

---

## Problem Statement

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a contiguous subarray whose sum is greater than or equal to `target`. If no such subarray exists, return `0`.

## Approach: Sliding Window (Variable Size)

The key insight is to use a variable-size sliding window. Expand the right boundary of the window by adding elements to the running `sum`. Whenever `sum >= target`, the current window is valid — record its length if it is smaller than the current minimum, then try to shrink the window from the left (to find a possibly smaller valid window). Since all elements are positive, shrinking always decreases the sum.

## Code Walkthrough (Step by Step)

1. **Initialize:** `l = 0` (left pointer), `r = 0` (right pointer), `sum = 0`, `res = INT_MAX`.

2. **Expand right:** Loop while `r < n`:
   - Add `nums[r]` to `sum`.

3. **Shrink from left:** While `sum >= target`:
   - Compute window length `len = r - l + 1`.
   - Update `res = min(res, len)`.
   - Subtract `nums[l]` from `sum`.
   - Increment `l` to shrink the window.

4. **Advance right:** `r++`.

5. **Return result:** If `res` was never updated (remains `INT_MAX`), no valid subarray exists — return `0`. Otherwise return `res`.

## Dry Run

**Example Input:** `target = 7`, `nums = [2, 3, 1, 2, 4, 3]`

| r | nums[r] | sum | Action | l | res |
|---|---------|-----|--------|---|-----|
| 0 | 2 | 2 | 2<7, no shrink | 0 | INF |
| 1 | 3 | 5 | 5<7, no shrink | 0 | INF |
| 2 | 1 | 6 | 6<7, no shrink | 0 | INF |
| 3 | 2 | 8 | 8>=7: len=4, res=4, sub nums[0]=2, l=1, sum=6 | 1 | 4 |
| 4 | 4 | 10 | 10>=7: len=4, res=4, sub nums[1]=3, l=2, sum=7 | 2 | 4 |
|   |   | 7 | 7>=7: len=3, res=3, sub nums[2]=1, l=3, sum=6 | 3 | 3 |
| 5 | 3 | 9 | 9>=7: len=3, res=3, sub nums[3]=2, l=4, sum=7 | 4 | 3 |
|   |   | 7 | 7>=7: len=2, res=2, sub nums[4]=4, l=5, sum=3 | 5 | 2 |

**Output:** `2` (subarray `[4, 3]`)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each element is added once (right pointer) and removed at most once (left pointer) |
| **Space** | O(1) | Only a constant number of pointer and sum variables |
