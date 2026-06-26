# Problem 0007 - Reverse Integer

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/reverse-integer/
**Language:** C++

---

## Problem Statement

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing causes the value to go outside the 32-bit signed integer range `[-2^31, 2^31 - 1]`, return 0 instead.

## Approach: Digit-by-Digit Reversal with Overflow Check

The key insight is to extract the last digit of `x` using modulo (`x % 10`), then build the reversed number by multiplying the accumulator by 10 and adding the digit. We use a `long long` accumulator so we can detect overflow before casting back to `int`.

## Code Walkthrough (Step by Step)

1. **Declare** `rem` for the current digit and `rev = 0` as a `long long` to store the reversed number.
2. **Loop while `x != 0`:**
   - Extract the last digit: `rem = x % 10`.
   - Append it to the reversed number: `rev = rev * 10 + rem`.
   - **Check for overflow:** if `rev > INT_MAX` or `rev < INT_MIN`, return 0 immediately.
   - Remove the last digit from `x`: `x = x / 10`.
3. **Cast and return** `(int)rev` once the loop ends.

Note: The modulo operation in C++ preserves the sign of `x`, so negative numbers are handled automatically (e.g., `-123 % 10 = -3`).

## Dry Run

**Example Input:** `x = 123`

| Iteration | x   | rem | rev  |
|-----------|-----|-----|------|
| Start     | 123 | —   | 0    |
| 1         | 12  | 3   | 3    |
| 2         | 1   | 2   | 32   |
| 3         | 0   | 1   | 321  |

**Output:** `321`

**Example with overflow:** `x = 1534236469` → reversed would be `9646324351` > INT_MAX → **Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log x) | Number of digits in x determines loop iterations |
| **Space** | O(1) | Only a fixed number of variables used |
