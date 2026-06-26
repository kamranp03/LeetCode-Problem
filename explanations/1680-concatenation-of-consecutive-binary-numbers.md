# Problem 1680 - Concatenation of Consecutive Binary Numbers

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
**Language:** C++

---

## Problem Statement

Given an integer `n`, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.

## Approach: Bit Manipulation with Running Result

The key insight is to build the concatenated value incrementally. For each number `i`, left-shift the current result by the number of bits in `i`, then add `i`. The bit length only increases when `i` is a power of 2 (when `i & (i-1) == 0`).

## Code Walkthrough (Step by Step)

1. **Initialize `result = 0`** and `bitLength = 0`.
2. **Iterate `i` from 1 to n:**
   - **Check power of 2:** If `(i & (i - 1)) == 0`, increment `bitLength`. A power of 2 marks the start of a new bit-length group (1-bit: {1}, 2-bit: {2,3}, 3-bit: {4-7}, etc.).
   - **Update result:** `result = ((result << bitLength) % MOD + i) % MOD`. Left-shift makes room for `i`'s bits, then add `i` itself.
3. **Return `result`.**

## Dry Run

**Example Input:** `n = 3`

- i=1: i&(i-1)=0 → bitLength=1; result=(0<<1)+1=1
- i=2: i&(i-1)=0 → bitLength=2; result=(1<<2)+2=6 (binary: 110)
- i=3: not power of 2; result=(6<<2)+3=27 (binary: 11011)
- 27 mod (10^9+7) = **27**

**Output:** `27`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single loop from 1 to n |
| **Space** | O(1) | Only result and bitLength variables |
