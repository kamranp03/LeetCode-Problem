# Problem 3013 - Divide an Array Into Subarrays With Minimum Cost II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, divide it into exactly `k` non-empty subarrays such that the second subarray's start index is at most `dist + 1` from the previous split point. The cost is the sum of the first elements of all subarrays. Return the minimum possible cost.

More precisely: choose `k-1` split points from `nums[1..n-1]` where consecutive split points are at most `dist` indices apart. Minimize `nums[0]` + sum of values at split points.

## Approach: Sliding Window with Two Ordered Sets

We maintain a sliding window of size `dist` over `nums[1..n-1]`. Within this window, we need to track the `k-1` smallest values (to minimize cost). We use two ordered sets:
- `kMinimum`: holds the current best `k-1` values (top candidates).
- `remaining`: holds the other values in the window.

As the window slides, we efficiently insert and remove elements while maintaining the invariant that `kMinimum` always has the `k-1` smallest values in the window.

## Code Walkthrough (Step by Step)

1. **Initialize window:** Fill the window with indices `1` to `dist` (the first valid window). Keep `kMinimum` at size `k-1`, moving excess to `remaining`. Track `sum` of `kMinimum`.

2. **Slide the window** (index `i` from `dist+1` to `n-1`):
   - Insert `nums[i]` into `kMinimum`, update `sum`.
   - If `kMinimum` size exceeds `k-1`, move the largest element to `remaining`.
   - Record `result = min(result, sum)`.
   - Remove element leaving the window (`nums[i-dist]`):
     - If it's in `kMinimum`, remove it and pull the largest from `remaining` into `kMinimum`.
     - If it's in `remaining`, simply remove it.

3. **Return** `nums[0] + result`.

## Dry Run

**Example Input:** `nums=[10,1,2,2,2,1], k=4, dist=3`

Window slides over [1,2,2,2,1] picking best k-1=3 smallest elements in windows of size dist=3.

Best window might be [1,2,2] giving sum=5. Result = 10 + 5 = 15.

**Output:** `15`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Each element inserted/removed from ordered sets once |
| **Space** | O(dist) | At most `dist` elements in both sets combined |
