# Problem 3432 - Count Partitions with Even Sum Difference

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-partitions-with-even-sum-difference/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, count the number of ways to split it into two non-empty parts (left = `nums[0..i]`, right = `nums[i+1..n-1]`) such that the difference of their sums is even. There are `n-1` possible split positions.

## Approach: Parity Observation

The key insight is mathematical: the difference (left_sum - right_sum) is even if and only if both sums have the same parity (both even or both odd). Since `left_sum + right_sum = total_sum`, both parts have the same parity if and only if the total sum is even. If the total sum is odd, no valid partition exists because the difference of two integers summing to an odd number can never be even.

Therefore:
- If `total_sum % 2 == 0`: all `n-1` split positions are valid.
- If `total_sum % 2 == 1`: answer is `0`.

## Code Walkthrough (Step by Step)

1. **Compute the total sum** using `accumulate`.
2. **Check parity:** if `sum % 2 == 0`, return `nums.size() - 1` (all `n-1` splits are valid).
3. **Otherwise,** return `0`.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 4]`

- Total sum = 10, which is even.
- All n-1 = 3 partitions are valid.

**Output:** `3`

**Example Input:** `nums = [1, 2, 3]`

- Total sum = 6, even → return n-1 = 2.

**Output:** `2`

**Example Input:** `nums = [1, 2]`

- Total sum = 3, odd → return 0.

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | One pass to compute the total sum |
| **Space** | O(1) | No extra data structures used |
