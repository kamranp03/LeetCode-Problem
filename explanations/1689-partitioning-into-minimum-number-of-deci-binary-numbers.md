# Problem 1689 - Partitioning Into Minimum Number Of Deci-Binary Numbers

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
**Language:** C++

---

## Problem Statement

A deci-binary number is a positive integer where each digit is either 0 or 1. Given a string `n` representing a positive integer, return the minimum number of deci-binary numbers needed to sum to `n`.

## Approach: Find Maximum Digit

The key insight is elegantly simple: each deci-binary number contributes at most 1 to each digit position. To build a digit of value `d`, you need at least `d` deci-binary numbers. Therefore, the answer is simply the maximum digit in the string `n`.

For example, to get "32", you need at least 3 deci-binary numbers (since the '3' requires 3 ones in that position): e.g., 11 + 11 + 10 = 32.

## Code Walkthrough (Step by Step)

1. **Initialize `maxn = 0`.**
2. **Iterate over each character `s` in the string `n`:**
   - Convert the character to its digit value: `s - '0'`.
   - Update `maxn = max(maxn, s - '0')`.
3. **Return `maxn`** — the maximum digit is the answer.

## Dry Run

**Example Input:** `n = "82734"`

- Digits: 8, 2, 7, 3, 4
- Maximum digit = 8
- Need 8 deci-binary numbers to contribute 8 at the first position

**Output:** `8`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(|n|) | Single pass through all digits of n |
| **Space** | O(1) | Only one variable to track maximum |
