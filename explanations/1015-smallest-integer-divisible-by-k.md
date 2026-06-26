# Problem 1015 - Smallest Integer Divisible by K

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/smallest-integer-divisible-by-k/
**Language:** C++

---

## Problem Statement
Given a positive integer K, find the length of the smallest positive integer consisting only of 1s (i.e., 1, 11, 111, ...) that is divisible by K. If no such number exists, return -1.

## Approach: Modular Arithmetic with Cycle Detection

If K is divisible by 2 or 5, no repunit (number made of all 1s) can be divisible by K, so return -1 immediately (since repunits are odd and don't end in 0 or 5). Otherwise, build the repunit iteratively using modular arithmetic: each next repunit `R_{n+1} = R_n * 10 + 1`. Track `rem = R_n % K`. If `rem == 0`, we found our answer. By the pigeonhole principle, after at most K steps the remainder must repeat, proving termination.

## Code Walkthrough (Step by Step)

1. **Early exit:** If `k % 2 == 0` or `k % 5 == 0`, return -1.

2. **Initialize:** `rem = 0`.

3. **Loop from `i = 1` to `k`:**
   - Update: `rem = (rem * 10 + 1) % k`.
     - This simulates appending a '1': the number goes from R to R*10+1.
   - If `rem == 0`: the current repunit (of length `i`) is divisible by K — return `i`.

4. **Return -1** (unreachable for valid K by pigeonhole, but kept as fallback).

## Dry Run

**Example Input:** `k = 3`

| i | rem = (rem*10+1) % 3 |
|---|----------------------|
| 1 | (0*10+1)%3 = 1       |
| 2 | (1*10+1)%3 = 11%3 = 2|
| 3 | (2*10+1)%3 = 21%3 = 0 → return 3 |

Number is 111, which is 3 × 37.

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(K) | At most K iterations before a remainder repeats |
| **Space** | O(1) | Only one remainder variable tracked |
