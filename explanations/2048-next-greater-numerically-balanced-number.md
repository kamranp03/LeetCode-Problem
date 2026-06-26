# Problem 2048 - Next Greater Numerically Balanced Number

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/next-greater-numerically-balanced-number/
**Language:** C++

---

## Problem Statement
An integer `x` is numerically balanced if for every digit `d` that appears in `x`, it appears exactly `d` times. Given an integer `n`, return the smallest numerically balanced number strictly greater than `n`.

## Approach: Brute Force Linear Search + Digit Frequency Check

The key insight is that numerically balanced numbers are sparse and the maximum constraint on `n` is small enough (up to 10^6) that a linear scan from `n+1` upward is feasible. The upper bound of 1,224,444 covers all possible balanced numbers in range. For each candidate, count digit frequencies and verify the balance condition.

## Code Walkthrough (Step by Step)

1. **`balanced(num)` helper**:
   - Build a frequency array `freq[10]` by extracting digits of `num` one by one (`num % 10`, then `num /= 10`).
   - For each digit `d` from 0 to 9: if `freq[d] != 0` and `freq[d] != d`, return false (either digit 0 must not appear, or digit d must appear exactly d times).
   - Return true if all conditions hold.

2. **`nextBeautifulNumber(n)`**:
   - Iterate `i` from `n+1` to `1224444`.
   - Return the first `i` for which `balanced(i)` is true.
   - The upper bound 1,224,444 is hard-coded because it's the largest balanced number fitting in a reasonable range.

## Dry Run

**Example Input:** `n = 1`

Check i=2: freq = {2:1} → freq[2]=1 ≠ 2 → false
Check i=3: freq = {3:1} → false
...
Check i=22: freq = {2:2} → freq[2]=2 == 2 → true!

**Output:** `22`

**Example Input:** `n = 1000`

Check 1333: freq={1:1, 3:3} → freq[1]=1==1 ✓, freq[3]=3==3 ✓ → true!

**Output:** `1333`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(D * C) where D = digits per number, C = candidates scanned | At most ~1.2M candidates checked; each check is O(10) for digit count |
| **Space** | O(1) | Fixed-size frequency array of size 10 |
