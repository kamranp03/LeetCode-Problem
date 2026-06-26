# Problem 3370 - Smallest Number With All Set Bits

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/smallest-number-with-all-set-bits/
**Language:** C++

---

## Problem Statement

Given a positive integer `n`, return the smallest number that is greater than or equal to `n` and has all bits set to `1` in binary representation (i.e., a number of the form `2^x - 1`).

## Approach: Find Smallest Power of 2 Minus 1 That Is >= n

Numbers with all bits set are of the form `2^x - 1`: 1 (1), 3 (11), 7 (111), 15 (1111), etc. We start with `x = 1` and keep incrementing `x` until `(1 << x) - 1 >= n`. The first such value is our answer.

This works because `(1 << x) - 1` produces a bitmask of `x` ones, and we want the smallest such mask that covers `n`.

## Code Walkthrough (Step by Step)

1. **Initialize** `x = 1`.

2. **Loop:** While `(1 << x) - 1 < n`, increment `x`.

3. **Return** `(1 << x) - 1`.

## Dry Run

**Example Input:** `n = 5`

- x=1: (1<<1)-1 = 1 < 5 → x++
- x=2: (1<<2)-1 = 3 < 5 → x++
- x=3: (1<<3)-1 = 7 >= 5 → stop

**Output:** `7` (binary: 111)

**Example Input:** `n = 7`

- x=1: 1 < 7 → x++
- x=2: 3 < 7 → x++
- x=3: 7 >= 7 → stop

**Output:** `7`

**Example Input:** `n = 1`

- x=1: (1<<1)-1=1 >= 1 → stop immediately

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Loop runs at most log2(n) + 1 times |
| **Space** | O(1) | Single integer variable |
