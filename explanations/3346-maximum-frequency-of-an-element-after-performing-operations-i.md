# Problem 3346 - Maximum Frequency of an Element After Performing Operations I

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and integers `k` and `numOperations`, in each operation you can change one element by at most `k` (increment or decrement). You can perform at most `numOperations` operations total. Return the maximum frequency of any element you can achieve.

## Approach: Prefix Frequency Array with Range Queries

For each candidate target value `t`, we want to know how many elements in `nums` can be changed to `t` (those within `[t-k, t+k]`). We use a prefix sum over a frequency array to answer range count queries in O(1).

For each target `t` that already exists in `nums`:
- `totalCount` = number of elements in `[t-k, t+k]` (can be converted to `t`).
- `targetCount` = current frequency of `t`.
- `needConversion = totalCount - targetCount` (elements that need an operation to become `t`).
- We can convert at most `min(needConversion, numOperations)` extra elements.
- Result candidate = `targetCount + min(needConversion, numOperations)`.

## Code Walkthrough (Step by Step)

1. **Build frequency array:** `freq[v]` = count of `v` in `nums`. Then convert to prefix sum array (cumulative).

2. **For each target `t` with freq > 0:**
   - `leftNum = max(0, t-k)`, `rightNum = min(maxEl, t+k)`
   - `totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0)` (range query using prefix sums)
   - `targetCount = freq[t] - (t > 0 ? freq[t-1] : 0)` (original frequency of `t`)
   - `maxPos = targetCount + min(totalCount - targetCount, numOperations)`
   - Update `result`.

3. **Return** `result`.

## Dry Run

**Example Input:** `nums = [1, 2, 4]`, `k = 1`, `numOperations = 2`

- freq after prefix sum: [0, 1, 2, 2, 3] (for values 0..4)
- Target t=1: range [0,2], totalCount=2, targetCount=1, needConv=1, maxPos=1+min(1,2)=2
- Target t=2: range [1,3], totalCount=2, targetCount=1, needConv=1, maxPos=2
- Target t=4: range [3,5], totalCount=1, targetCount=1, needConv=0, maxPos=1

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(max_val + n) | Build prefix freq + scan all values |
| **Space** | O(max_val) | Frequency/prefix array |
