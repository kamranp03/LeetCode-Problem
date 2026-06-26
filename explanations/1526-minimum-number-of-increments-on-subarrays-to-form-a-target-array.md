# Problem 1526 - Minimum Number of Increments on Subarrays to Form a Target Array

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
**Language:** C++

---

## Problem Statement

Given a target array of integers, you start with an array of all zeros and can, in one operation, choose any subarray and increment all its elements by 1. Return the minimum number of operations to form the target array.

## Approach: Greedy — Sum of Positive Differences

The key insight is that the minimum number of operations equals `target[0]` plus the sum of all positive increases between consecutive elements. Each time `target[i] > target[i-1]`, we need `target[i] - target[i-1]` additional operations that start fresh at position `i`. Decreases are free because existing operations can simply stop earlier.

## Code Walkthrough (Step by Step)

1. **Initialize `op = target[0]`** — we need at least `target[0]` operations to build the first element from 0.
2. **Iterate from `i = 1`:** For each subsequent element, if `target[i] > target[i-1]`, add the difference `target[i] - target[i-1]` to `op`.
3. **When `target[i] <= target[i-1]`:** No extra operations needed — the existing ones from before can cover it (by starting at a wider subarray).
4. **Return `op`.**

## Dry Run

**Example Input:** `target = [3,1,1,2]`

- op = 3 (for target[0]=3)
- i=1: target[1]=1 < 3 → no addition
- i=2: target[2]=1 == 1 → no addition
- i=3: target[3]=2 > 1 → op += 2-1 = 1 → op=4
- Total = **4**

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only one accumulator variable |
