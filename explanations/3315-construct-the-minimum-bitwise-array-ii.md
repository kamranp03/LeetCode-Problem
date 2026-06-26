# Problem 3315 - Construct the Minimum Bitwise Array II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
**Language:** C++

---

## Problem Statement

Given an array `nums` of prime numbers, for each `nums[i]`, find the minimum non-negative integer `x` such that `x OR (x + 1) == nums[i]`. If no such `x` exists, return `-1` for that element. This is the same as Problem 3314 but optimized for larger primes.

## Approach: Bit Manipulation - Remove the Lowest Set Bit in a Trailing Run

For a prime `n` (which is odd, hence its last bit is 1), `x | (x+1) == n` is satisfied when `x` is `n` with its lowest-order contiguous block of set bits reduced by one bit. Specifically:

1. If `n == 2` (the only even prime): impossible → `-1`.
2. Otherwise, count the trailing set bits of `n` (how many consecutive `1`s from the LSB). Let this count be `count`.
3. Then `x = n - (1 << (count - 1))`: we subtract the value of the highest bit in that trailing run, effectively turning the lowest bit of that block to `0`.

This gives the minimum `x` directly without brute-force iteration.

## Code Walkthrough (Step by Step)

1. **Handle n=2:** Return `-1` directly (2 = `10` in binary; no `x` satisfies `x|x+1 = 2`).

2. **Count trailing set bits:** Start from LSB. While the current bit is `1`, increment `count` and right-shift.

3. **Compute x:** `x = n - (1 << (count - 1))`. This clears the least significant `1` in the trailing block.

4. **Push x to answer.**

## Dry Run

**Example Input:** `nums = [2, 3, 5, 7]`

- n=2: special case → push -1
- n=3 (binary 11): trailing 1s → count=2, x = 3 - (1<<1) = 3 - 2 = 1. Check: 1|2=3 ✓
- n=5 (binary 101): trailing 1s → count=1, x = 5 - (1<<0) = 5 - 1 = 4. Check: 4|5=5 ✓
- n=7 (binary 111): trailing 1s → count=3, x = 7 - (1<<2) = 7 - 4 = 3. Check: 3|4=7 ✓

**Output:** `[-1, 1, 4, 3]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * log(max_val)) | For each prime, count trailing bits (log factor) |
| **Space** | O(n) | Output array |
