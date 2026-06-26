# Problem 3314 - Construct the Minimum Bitwise Array I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
**Language:** C++

---

## Problem Statement

Given an array `nums` of prime numbers, for each `nums[i]`, find the minimum non-negative integer `x` such that `x OR (x + 1) == nums[i]`. If no such `x` exists, use `-1`.

## Approach: Brute Force Search for Each Prime

For each prime `n` in `nums`, we try every integer `x` from `0` to `n` and check if `x | (x + 1) == n`. The first `x` that satisfies this condition is the answer for that prime.

The key bitwise insight: `x | (x+1)` always sets the lowest `0` bit of `x` to `1`, so it equals a number that differs from `x` only in a trailing run of zeros that becomes ones. Since the input values are primes (which are odd, except 2), most have a specific bit pattern that enables finding such an `x`.

## Code Walkthrough (Step by Step)

1. **Iterate** over each `n` in `nums`.

2. **Linear search** from `x = 0` to `x = n`:
   - If `(x | (x + 1)) == n`: record `found = x`, break.

3. **Push** `found` (or `-1` if not found) into `ans`.

4. **Return** `ans`.

## Dry Run

**Example Input:** `nums = [2, 3, 5, 7]`

- n=2: x=0: 0|1=1≠2; x=1: 1|2=3≠2; x=2: 2|3=3≠2. Not found → -1
- n=3: x=0: 0|1=1≠3; x=1: 1|2=3=3 ✓ → found=1
- n=5: x=0..5: x=4: 4|5=5 ✓ → found=4
- n=7: x=0..7: x=3: 3|4=7 ✓ → found=3

**Output:** `[-1, 1, 4, 3]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * max_val) | For each prime, linear scan up to its value |
| **Space** | O(n) | Output array |
