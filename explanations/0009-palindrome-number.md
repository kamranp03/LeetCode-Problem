# Problem 0009 - Palindrome Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/palindrome-number/
**Language:** C++

---

## Problem Statement

Given an integer `x`, return `true` if `x` is a palindrome (reads the same forwards and backwards), and `false` otherwise. Negative numbers are never palindromes.

## Approach: Integer Reversal and Comparison

The key insight is that a number is a palindrome if reversing all its digits produces the exact same number. We immediately reject negative numbers (they have a leading `-` which can't match). Then we reverse the entire integer and compare with the original using the same digit-extraction technique as Problem 7. A `long long` buffer catches potential overflow during reversal.

## Code Walkthrough (Step by Step)

1. **Reject negatives immediately:** `if (x < 0) return false`.
2. **Save the original value** in `original = x`.
3. **Reverse the digits** of `x` into `rev` (a `long long`):
   - Extract last digit: `rem = x % 10`.
   - Build reversed: `rev = rev * 10 + rem`.
   - Check overflow: if `rev > INT_MAX` or `rev < INT_MIN`, return false (0).
   - Strip last digit: `x = x / 10`.
4. **Compare** `rev == original` and return the boolean result.

## Dry Run

**Example Input:** `x = 121`

| Iteration | x   | rem | rev |
|-----------|-----|-----|-----|
| Start     | 121 | —   | 0   |
| 1         | 12  | 1   | 1   |
| 2         | 1   | 2   | 12  |
| 3         | 0   | 1   | 121 |

`rev (121) == original (121)` → **Output:** `true`

**Example Input:** `x = -121`

Immediately returns `false` because `x < 0`.

**Example Input:** `x = 10`

Reversed = 01 = 1, original = 10 → `1 != 10` → **Output:** `false`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log x) | One iteration per digit of x |
| **Space** | O(1) | Only a constant number of variables |
