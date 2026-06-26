# Problem 2396 - Strictly Palindromic Number

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/strictly-palindromic-number/
**Language:** C++

---

## Problem Statement
An integer `n` is strictly palindromic if, for every base `b` with `2 <= b <= n-2`, the representation of `n` in base `b` is a palindrome. Given an integer `n >= 4`, return `true` if `n` is strictly palindromic, and `false` otherwise.

## Approach: Mathematical Proof — Always Return False

The key insight is a mathematical proof: no integer `n >= 4` is ever strictly palindromic. Consider base `n-2`: the representation of `n` in base `n-2` is always `"12"` (since `n = 1*(n-2) + 2`), and `"12"` is never a palindrome. Therefore the answer is always `false` for any valid input.

## Code Walkthrough (Step by Step)

1. The function immediately returns `false` without any computation.
2. This is a valid and complete solution because of the mathematical argument above.

**Why does this work?**
- In base `b = n-2`: `n = 1 * (n-2) + 2`, so `n` in base `n-2` is `"12"`.
- `"12"` reversed is `"21"`, which is not equal to `"12"`.
- Therefore, `n` fails the palindrome test in base `n-2` for all `n >= 4`.
- Since it must hold for ALL bases `b` in `[2, n-2]`, and it fails for `b = n-2`, the answer is always `false`.

## Dry Run

**Example Input:** `n = 9`

We would need to check bases 2 through 7:
- Base 2: 9 = "1001" → palindrome ✓
- Base 3: 9 = "100" → not palindrome ✗ → already false

(The function returns `false` without checking, because mathematically guaranteed.)

**Output:** `false`

**Example Input:** `n = 4`
- Base 2: 4 = "100" → not palindrome → false.

**Output:** `false`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Immediate return; no computation needed |
| **Space** | O(1) | No variables or data structures used |
