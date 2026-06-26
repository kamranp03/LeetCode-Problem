# Problem 3918 - Sum of Primes Between Number and Its Reverse

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/
**Language:** C++

---

## Problem Statement

Given an integer `n`, compute the reverse of `n` (digit reversal, no leading zeros). Then sum all prime numbers in the inclusive range `[min(n, reverse(n)), max(n, reverse(n))]`.

## Approach: Direct Primality Testing in Range

Reverse `n` digit by digit, then iterate through every integer in the range and test each for primality using trial division up to the square root.

## Code Walkthrough (Step by Step)

1. **`reverseNum(n)`:** extract digits one by one using `n % 10` and build the reverse by `rev * 10 + digit`.
2. **Compute range:** `low = min(n, r)`, `high = max(n, r)`.
3. **Iterate from `low` to `high`:** for each integer `i`, call `isPrime(i)`.
4. **`isPrime(num)`:** return false for `num < 2`. Trial divide from `2` to `sqrt(num)`.
5. **Accumulate** sum of all primes found.
6. **Return** `sum`.

## Dry Run

**Example Input:** `n = 17`

- reverse(17) = 71.
- Range: [17, 71].
- Primes in [17, 71]: 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71.
- Sum = 17+19+23+29+31+37+41+43+47+53+59+61+67+71 = 597.

**Output:** `597`

**Example Input:** `n = 121`

- reverse(121) = 121. Range: [121, 121].
- 121 = 11*11, not prime.

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(R * sqrt(R)) | R = range size; each primality test is O(sqrt(val)) |
| **Space** | O(1) | No extra data structures |
