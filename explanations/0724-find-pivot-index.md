# Problem 724 - Find Pivot Index

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/find-pivot-index/
**Language:** C++

---

## Problem Statement
Given an integer array `nums`, find the pivot index — the index where the sum of all elements to the left equals the sum of all elements to the right. If no such index exists, return -1. If there are multiple pivot indices, return the leftmost one.

## Approach: Prefix Sum with Total Sum

The key insight is: at index `i`, left sum = `leftSum`, and right sum = `total - leftSum - nums[i]`. We don't need to compute the right sum explicitly. If `leftSum == total - leftSum - nums[i]`, then `i` is the pivot. We compute the total sum once upfront and update `leftSum` incrementally as we scan.

## Code Walkthrough (Step by Step)

1. **Compute `total`:** Sum all elements in `nums`.

2. **Initialize `leftSum = 0`.**

3. **Scan from left to right** (index i from 0 to n-1):
   - **Check:** If `leftSum == total - leftSum - nums[i]`, return `i` — this is the pivot index.
   - **Update:** Add `nums[i]` to `leftSum` (include current element in the next iteration's left sum).

4. **Return -1** if no pivot was found.

## Dry Run

**Example Input:** `nums = [1, 7, 3, 6, 5, 6]`

total = 1+7+3+6+5+6 = 28

| i | nums[i] | leftSum | rightSum = 28-leftSum-nums[i] | Equal? |
|---|---------|---------|-------------------------------|--------|
| 0 | 1 | 0 | 28-0-1=27 | 0!=27 |
| 1 | 7 | 1 | 28-1-7=20 | 1!=20 |
| 2 | 3 | 8 | 28-8-3=17 | 8!=17 |
| 3 | 6 | 11 | 28-11-6=11 | 11==11 → return 3 |

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | One pass for total sum, one pass for pivot search |
| **Space** | O(1) | Only two variables (total and leftSum) beyond the input |
