# Problem 2220 - Minimum Bit Flips to Convert Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
**Language:** C++

---

## Problem Statement
Given two integers `start` and `goal`, return the minimum number of bit flips needed to convert `start` to `goal`. A bit flip changes a `0` to `1` or a `1` to `0` at any bit position.

## Approach: XOR + Popcount

The key insight is that `start XOR goal` produces a number where each bit is `1` if and only if the corresponding bits of `start` and `goal` differ. The number of `1` bits in this XOR result equals exactly the number of bit positions that need to be flipped.

## Code Walkthrough (Step by Step)

1. **Compute `xorV = start ^ goal`**: The XOR highlights all differing bits.
2. **Count set bits**: Use `__builtin_popcount(xorV)` — a GCC built-in that counts the number of 1-bits in an integer (equivalent to Hamming weight).
3. **Return the count**.

## Dry Run

**Example Input:** `start = 10, goal = 7`

Binary representations:
- `start = 10` → `1010`
- `goal  =  7` → `0111`
- `XOR       ` → `1101`

`__builtin_popcount(1101₂)` = count of 1s = 3

**Output:** `3`

**Another Example:** `start = 3, goal = 4`
- `3` = `011`, `4` = `100`, XOR = `111` → 3 flips.

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | XOR and popcount are single hardware instructions |
| **Space** | O(1) | Only one integer variable used |
