# Problem 0029 - Divide Two Integers

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/divide-two-integers/
**Language:** C++

---

## Problem Statement

Given two integers `dividend` and `divisor`, divide them without using multiplication, division, or mod operators. Return the quotient after truncating toward zero. If the result overflows a 32-bit signed integer, return `INT_MAX`.

## Approach: Bit Manipulation (Exponential Search)

The key insight is that we can subtract the divisor repeatedly, but that's O(n/divisor). Instead, we use bit shifting to subtract the largest multiple of the divisor that fits — specifically, we keep doubling the divisor (via left shift) until it exceeds the dividend. This is equivalent to finding the highest bit in the quotient, giving O(log²n) performance.

## Code Walkthrough (Step by Step)

1. **Handle overflow edge case:** `dividend == INT_MIN && divisor == -1` would overflow; return `INT_MAX`.
2. **Work with absolute values** using `long long` to avoid overflow during intermediate calculations.
3. **Outer while loop** while `a >= b`:
   - Start with `temp = b` and `multiple = 1`.
   - **Inner while loop:** double `temp` (via `temp << 1`) while `a >= temp * 2`. Each doubling also doubles `multiple`.
   - Subtract the largest fitting `temp` from `a` and add `multiple` to `result`.
4. **Apply sign:** if exactly one of dividend/divisor is negative (checked via XOR `^`), negate `result`.
5. **Clamp** result to the 32-bit signed range and return as `int`.

## Dry Run

**Example Input:** `dividend = 10`, `divisor = 3`

`a = 10`, `b = 3`

| Outer iteration | temp (doubled) | multiple | a after subtraction | result |
|-----------------|----------------|----------|---------------------|--------|
| 1               | 3→6→12 (stop at 6) | 1→2→4 (stop at 2) | 10-6=4    | 2      |
| 2               | 3→6 (stop at 3)    | 1→2 (stop at 1)   | 4-3=1     | 3      |
| a=1 < b=3, stop | —              | —        | —                   | 3      |

Both positive → sign is positive.

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log² n) | Outer loop runs O(log n) times; inner loop doubles, so also O(log n) |
| **Space** | O(1) | Only a fixed number of long long variables |
