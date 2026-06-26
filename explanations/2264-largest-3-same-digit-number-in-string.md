# Problem 2264 - Largest 3-Same-Digit Number in String

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/largest-3-same-digit-number-in-string/
**Language:** C++

---

## Problem Statement
Given a string `num` of digits, find the largest "good integer" that is a substring of `num`. A good integer is a string of length 3 where all three digits are the same (e.g., "111", "555"). Return the largest good integer found, or an empty string if none exists.

## Approach: Linear Scan for Three Consecutive Equal Digits

The key insight is to scan through `num` looking for positions where `num[i] == num[i-1] == num[i-2]`. Whenever such a triplet is found, form the 3-character string and update the answer by taking the lexicographic (and numeric) maximum. Since the digits are '0'-'9', lexicographic max equals numeric max.

## Code Walkthrough (Step by Step)

1. **Initialize `ans = ""`** (empty string, indicating no good integer found yet).
2. **Loop `i` from 2 to `num.size()-1`**:
   - Check if `num[i] == num[i-1]` and `num[i] == num[i-2]`.
   - If yes: form string `s` = three copies of `num[i]`, update `ans = max(ans, s)`.
3. **Return `ans`** (empty string if no triplet found).

## Dry Run

**Example Input:** `num = "6777133339"`

| i | num[i-2..i] | All same? | s      | ans    |
|---|-------------|-----------|--------|--------|
| 2 | "677"       | No        | -      | ""     |
| 3 | "777"       | Yes       | "777"  | "777"  |
| 4 | "771"       | No        | -      | "777"  |
| 5 | "713"       | No        | -      | "777"  |
| 6 | "133"       | No        | -      | "777"  |
| 7 | "333"       | Yes       | "333"  | "777"  |
| 8 | "333"       | Yes       | "333"  | "777"  |
| 9 | "339"       | No        | -      | "777"  |

**Output:** `"777"`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single linear pass through the string |
| **Space** | O(1) | Only a few string variables of fixed length 3 |
