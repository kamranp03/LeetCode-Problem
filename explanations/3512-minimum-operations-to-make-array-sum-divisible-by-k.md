# Problem 3512 - Minimum Operations to Make Array Sum Divisible by K

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and a positive integer `k`, in each operation you can decrement any element by 1. Find the minimum number of operations needed to make the sum of the array divisible by `k`.

## Approach: Remainder Math

The key insight is that to make the sum divisible by `k`, we need to reduce it by exactly `sum % k`. Each decrement operation reduces the sum by 1, so the minimum number of operations equals the remainder `sum % k`.

## Code Walkthrough (Step by Step)

1. **Compute the total sum** of the array.
2. **Compute `r = sum % k`** (the remainder when divided by k).
3. **If `r == 0`:** the sum is already divisible by `k`, return `0`.
4. **Otherwise:** return `r` (we need exactly `r` decrement operations).

## Dry Run

**Example Input:** `nums = [3, 9, 7]`, `k = 5`

- Sum = 3 + 9 + 7 = 19.
- r = 19 % 5 = 4.
- We need 4 operations (e.g., decrement any element 4 times).

**Output:** `4`

**Example Input:** `nums = [2, 4, 6]`, `k = 3`

- Sum = 12. r = 12 % 3 = 0.

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass to compute sum |
| **Space** | O(1) | Only sum and remainder stored |
