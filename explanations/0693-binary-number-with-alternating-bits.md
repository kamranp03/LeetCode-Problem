# Problem 693 - Binary Number with Alternating Bits

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-number-with-alternating-bits/
**Language:** C++

---

## Problem Statement
Given a positive integer `n`, check whether it has alternating bits in its binary representation — that is, no two adjacent bits are the same (it alternates between 0 and 1). Return `true` if it does, `false` otherwise. Examples: 5 = 101 (yes), 7 = 111 (no), 10 = 1010 (yes).

## Approach: XOR Bit Trick

The key insight is a clever two-step bit manipulation:
1. `res = n ^ (n >> 1)`: XOR `n` with itself shifted right by 1. If all adjacent bits differ, every bit pair produces a 1, so `res` becomes all 1s (in the relevant positions).
2. Check if `res` is all 1s: A number is all 1s if and only if `res & (res + 1) == 0`. Adding 1 to all-1s causes a carry that produces a power of 2; ANDing with the original all-1s then gives 0.

## Code Walkthrough (Step by Step)

1. **Compute `res = n ^ (n >> 1)`:**
   - Shift `n` right by 1 to align each bit with its right neighbor.
   - XOR: adjacent bits that differ → 1, adjacent bits that are same → 0.
   - If alternating, all bits in `res` are 1.

2. **Check `(res & (res + 1)) == 0`:**
   - If `res` is all 1s (e.g., 0b0111), then `res + 1` is the next power of 2 (e.g., 0b1000).
   - Their AND is 0 → alternating bits confirmed.
   - If any adjacent bits were the same, `res` has a 0 somewhere, and this check fails.

3. **Return the boolean result.**

## Dry Run

**Example Input:** `n = 10` (binary: 1010)

- `n >> 1 = 5` (binary: 0101)
- `res = 1010 XOR 0101 = 1111` (decimal 15)
- `res + 1 = 16` (binary: 10000)
- `res & (res+1) = 1111 & 10000 = 0` → return `true`

**Example Input:** `n = 11` (binary: 1011)

- `n >> 1 = 5` (binary: 0101)
- `res = 1011 XOR 0101 = 1110` (decimal 14)
- `res + 1 = 15` (binary: 1111)
- `res & (res+1) = 1110 & 1111 = 1110 != 0` → return `false`

**Output:** `true` for 10, `false` for 11

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Three bit operations, each O(1) for fixed-width integers |
| **Space** | O(1) | One extra variable `res` |
