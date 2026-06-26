# Problem 918 - Maximum Sum Circular Subarray

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-sum-circular-subarray/
**Language:** C++

---

## Problem Statement
Given a circular integer array, find the maximum possible sum of a non-empty subarray. The array is circular, meaning the subarray can wrap around from the end back to the beginning.

## Approach: Kadane's Algorithm + Circular Trick

There are two cases for the maximum circular subarray:
1. **Non-wrapping case:** The max subarray lies entirely within the array — solved by standard Kadane's algorithm.
2. **Wrapping case:** The max subarray wraps around. This is equivalent to `total - min_subarray_sum` (removing the minimum middle portion).

The answer is `max(maxSum, total - minSum)`. Special case: if all elements are negative, `maxSum < 0`, and `total - minSum` would give 0 (empty), which is invalid — so return `maxSum` directly.

## Code Walkthrough (Step by Step)

1. **Initialize:** `total = 0`, `maxEnding = a[0]`, `maxSum = a[0]`, `minEnding = a[0]`, `minSum = a[0]`.

2. **Single pass** from i=0 to n-1:
   - Add `a[i]` to `total`.
   - For i > 0:
     - `maxEnding = max(a[i], maxEnding + a[i])` — extend or restart max subarray.
     - `maxSum = max(maxSum, maxEnding)` — track global max.
     - `minEnding = min(a[i], minEnding + a[i])` — extend or restart min subarray.
     - `minSum = min(minSum, minEnding)` — track global min.

3. **If `maxSum < 0`**, all elements negative — return `maxSum`.

4. **Return `max(maxSum, total - minSum)`.**

## Dry Run

**Example Input:** `a = [1, -2, 3, -2]`

- total=0, pass:
  - i=0: total=1, maxEnding=1, maxSum=1, minEnding=1, minSum=1
  - i=1: total=-1, maxEnding=max(-2,1-2)=-1, maxSum=1, minEnding=min(-2,1-2)=-2, minSum=-2? Wait: minEnding=min(-2, 1+(-2))=min(-2,-1)=-2, minSum=-2
  - i=2: total=2, maxEnding=max(3,-1+3)=3, maxSum=3, minEnding=min(3,-2+3)=1, minSum=-2
  - i=3: total=0, maxEnding=max(-2,3-2)=1, maxSum=3, minEnding=min(-2,1-2)=-2, minSum=-2

- maxSum=3 > 0, return max(3, 0-(-2))=max(3,2)=3

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single pass through the array |
| **Space** | O(1) | Only a constant number of variables |
