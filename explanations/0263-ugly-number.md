# Problem 263 - Ugly Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/ugly-number/
**Language:** C++

---

## Problem Statement
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer `n`, return `true` if `n` is an ugly number, and `false` otherwise. Note: 1 is conventionally considered ugly.

## Approach: Repeated Division by 2, 3, and 5

The key insight is that if a number is ugly, we can completely reduce it to 1 by repeatedly dividing out all factors of 2, then all factors of 3, then all factors of 5. If anything remains after this process (other than 1), then the number has a prime factor other than 2, 3, or 5 and is not ugly.

## Code Walkthrough (Step by Step)

1. **Handle zero:** `n == 0` is not a positive integer, so return `false` immediately (0 has no prime factorization).

2. **Divide out all factors of 2:** While `n % 2 == 0`, set `n = n / 2`. This removes every factor of 2.

3. **Divide out all factors of 3:** While `n % 3 == 0`, set `n = n / 3`.

4. **Divide out all factors of 5:** While `n % 5 == 0`, set `n = n / 5`.

5. **Check remainder:** After all three loops, if `n == 1`, all prime factors were 2, 3, or 5 → return `true`. If `n > 1`, some other prime factor remains → return `false`.

## Dry Run

**Example Input:** `n = 12`

- n=12: 12 % 2 == 0 → n=6 → n=3
- n=3: 3 % 2 != 0 (skip), 3 % 3 == 0 → n=1
- n=1: 1 % 5 != 0 (skip)
- n == 1 → return `true`

**Example Input:** `n = 14`

- n=14: 14 % 2 == 0 → n=7
- n=7: 7 % 2 != 0, 7 % 3 != 0, 7 % 5 != 0
- n=7 != 1 → return `false` (14 = 2 × 7, and 7 is not 2/3/5)

**Output:** `true` for 12, `false` for 14

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Each division reduces n by at least half; total iterations are logarithmic |
| **Space** | O(1) | Only the input variable is modified, no extra space used |
