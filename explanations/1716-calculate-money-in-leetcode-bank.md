# Problem 1716 - Calculate Money in Leetcode Bank

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/calculate-money-in-leetcode-bank/
**Language:** C++

---

## Problem Statement

Hercy deposits money into the LeetCode Bank each day. On Monday (first day of each week), he deposits $1. Every subsequent day of the same week, he deposits $1 more than the previous day. Each Monday, he starts fresh at $1 more than last Monday. Given `n` days, return the total money deposited after `n` days.

## Approach: Simulate Week by Week

The key insight is to handle complete weeks and remaining days separately. In week `i` (0-indexed), the deposits are `(1+i), (2+i), ..., (7+i)` — a sum of `7*(1+i) + 21` (arithmetic series). The remaining days after full weeks follow the same pattern starting from where the last week left off.

## Code Walkthrough (Step by Step)

1. **Compute `weeks = n / 7`** and `days = n % 7` (remaining days).
2. **Sum complete weeks:** For week `i` (0-indexed), the sum is `7*(1+i) + 21`. Accumulate over all `weeks`.
3. **Sum remaining days:** After `weeks` complete weeks, the next Monday starts at `(1 + weeks)`. The remaining `days` days contribute `(1+weeks) + (2+weeks) + ... = sum of (1+weeks+i)` for `i in 0..days-1`.
4. **Return `total`.**

## Dry Run

**Example Input:** `n = 10`

- weeks=1, days=3
- Week 0: 7*(1+0)+21 = 7+21 = 28
- Remaining days (Mon of week 2 = starts at 2): day0=2, day1=3, day2=4 → sum=9
- Total = 28 + 9 = **37**

**Output:** `37`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two loops but total iterations = n/7 + n%7 ≈ n |
| **Space** | O(1) | Only accumulator and loop variables |
