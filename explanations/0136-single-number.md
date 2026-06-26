# Problem 136 - Single Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/single-number/
**Language:** C++

---

## Problem Statement

Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single element and return it. The solution must run in O(n) time and use only O(1) extra space.

## Approach: Bit Manipulation - XOR

The key insight relies on two XOR properties:
1. `a ^ a = 0` — any number XORed with itself is 0.
2. `a ^ 0 = a` — any number XORed with 0 is itself.

When we XOR all elements together, every pair of duplicate numbers cancels out (becomes 0), and the single unpaired number remains. XOR is also commutative and associative, so order does not matter.

## Code Walkthrough (Step by Step)

1. **Initialize `ans = 0`.**

2. **XOR every element:** Iterate over `nums` and compute `ans ^= x` for each element `x`.
   - Duplicate pairs cancel out: if `x` appears twice, `x ^ x = 0`.
   - The single number `s` XORed with 0 gives `s`.

3. **Return `ans`:** After all elements, `ans` equals the single number.

## Dry Run

**Example Input:** `nums = [4, 1, 2, 1, 2]`

| Step | x | ans (binary) | ans (decimal) |
|------|---|--------------|---------------|
| init | — | 000 | 0 |
| i=0 | 4 | 000 ^ 100 = 100 | 4 |
| i=1 | 1 | 100 ^ 001 = 101 | 5 |
| i=2 | 2 | 101 ^ 010 = 111 | 7 |
| i=3 | 1 | 111 ^ 001 = 110 | 6 |
| i=4 | 2 | 110 ^ 010 = 100 | 4 |

**Output:** `4`

(1 ^ 1 = 0, 2 ^ 2 = 0, 4 ^ 0 = 4 — the pairs cancel, leaving 4.)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only one variable `ans` regardless of input size |
