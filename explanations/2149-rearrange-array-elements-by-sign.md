# Problem 2149 - Rearrange Array Elements by Sign

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/rearrange-array-elements-by-sign/
**Language:** C++

---

## Problem Statement
Given an integer array `nums` with an equal number of positive and negative integers, rearrange the elements such that every positive integer is at an even index and every negative integer is at an odd index, while preserving the relative order of positives and negatives respectively.

## Approach: Two-Pointer Placement into Result Array

The key insight is that positives go at even indices (0, 2, 4, ...) and negatives go at odd indices (1, 3, 5, ...). Maintain two pointers: `pos` (starts at 0, increments by 2) and `neg` (starts at 1, increments by 2). A single pass through the input places each element at the correct position in the result array without needing extra sorting.

## Code Walkthrough (Step by Step)

1. **Initialize `ans`** as a vector of size `nums.size()` filled with 0.
2. **Set `pos = 0`** (next even index for positives) and **`neg = 1`** (next odd index for negatives).
3. **Loop** through each element `nums[i]`:
   - If `nums[i] > 0`: place at `ans[pos]`, then `pos += 2`.
   - If `nums[i] < 0` (or just else): place at `ans[neg]`, then `neg += 2`.
4. **Return `ans`**.

## Dry Run

**Example Input:** `nums = [3, 1, -2, -5, 2, -4]`

| i | nums[i] | pos | neg | ans (changes)           |
|---|---------|-----|-----|-------------------------|
| 0 | 3 (+)   | 0   | 1   | ans[0]=3, pos=2         |
| 1 | 1 (+)   | 2   | 1   | ans[2]=1, pos=4         |
| 2 | -2 (-)  | 4   | 1   | ans[1]=-2, neg=3        |
| 3 | -5 (-)  | 4   | 3   | ans[3]=-5, neg=5        |
| 4 | 2 (+)   | 4   | 5   | ans[4]=2, pos=6         |
| 5 | -4 (-)  | 6   | 5   | ans[5]=-4, neg=7        |

**Output:** `[3, -2, 1, -5, 2, -4]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the input array |
| **Space** | O(n) | Output array of the same size as input |
