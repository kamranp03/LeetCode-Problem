# Problem 152 - Maximum Product Subarray

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-product-subarray/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, find a contiguous subarray (containing at least one number) which has the largest product, and return that product. The array can contain negative numbers, zeros, and positive numbers, which makes this problem more complex than maximum sum subarray.

## Approach: Dynamic Programming - Track Both Max and Min

The key insight is that because of negative numbers, a large negative product times another negative number can become the largest positive product. So at each position, we must track both the maximum product and the minimum product of subarrays ending here. For each new element, we consider three choices: extend the max subarray, extend the min subarray, or start fresh with just the current element.

## Code Walkthrough (Step by Step)

1. **Initialize:** `bestMax = a[0]`, `bestMin = a[0]`, `ans = a[0]` (handle the case where n=1).

2. **Iterate from index 1:** For each element `a[i]`, compute three candidates:
   - `ch1 = bestMax * a[i]` — extend the current maximum subarray.
   - `ch2 = bestMin * a[i]` — extend the current minimum subarray (if a[i] is negative, this could become the new maximum).
   - `ch3 = a[i]` — start a fresh subarray at this element (useful after a zero).

3. **Update bestMax and bestMin:**
   - `bestMax = max(ch1, max(ch2, ch3))`
   - `bestMin = min(ch1, min(ch2, ch3))`

4. **Update global answer:** `ans = max(ans, max(bestMax, bestMin))`.

5. **Return `ans`**.

## Dry Run

**Example Input:** `nums = [2, 3, -2, 4]`

| i | a[i] | bestMax | bestMin | ch1 | ch2 | ch3 | ans |
|---|------|---------|---------|-----|-----|-----|-----|
| 0 | 2 | 2 | 2 | — | — | — | 2 |
| 1 | 3 | 6 | 6 | 6 | 6 | 3 | 6 |
| 2 | -2 | -2 | -12 | -12 | -12 | -2 | 6 |
| 3 | 4 | 4 | -48 | -8 | -48 | 4 | 6 |

Wait — let me redo step 2: at i=1, ch1=2*3=6, ch2=2*3=6, ch3=3 → bestMax=6, bestMin=6.
At i=2 (a[i]=-2): ch1=6*(-2)=-12, ch2=6*(-2)=-12, ch3=-2 → bestMax=-2, bestMin=-12.
At i=3 (a[i]=4): ch1=-2*4=-8, ch2=-12*4=-48, ch3=4 → bestMax=4, bestMin=-48. ans=max(6,4)=6.

**Output:** `6` (subarray [2,3])

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only three variables: bestMax, bestMin, ans |
