# Problem 762 - Prime Number of Set Bits in Binary Representation

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
**Language:** C++

---

## Problem Statement
Given two integers `left` and `right`, count how many integers in the range `[left, right]` have a prime number of set bits (1-bits) in their binary representation. Since the numbers are at most 10^6 (< 2^20), the bit count is at most 20, so we only need to check primes up to 20.

## Approach: Brute Force with Built-in Popcount

For each number in the range, use the GCC built-in `__builtin_popcount()` to count the number of 1-bits instantly. Then check if that count is in a precomputed set of primes {2, 3, 5, 7, 11, 13, 17, 19}. This is efficient because the range is bounded and popcount is O(1).

## Code Walkthrough (Step by Step)

1. **Precompute prime set:** Store all primes up to 20 in an `unordered_set<int>`: {2, 3, 5, 7, 11, 13, 17, 19}.

2. **Loop from `left` to `right`:** For each integer `i`:
   - Call `__builtin_popcount(i)` to get the count of 1-bits.
   - Check if that count exists in the prime set.
   - If yes, increment `ans`.

3. **Return `ans`.**

## Dry Run

**Example Input:** `left = 6, right = 10`

| Number | Binary | Set Bits | Prime? |
|--------|--------|----------|--------|
| 6      | 110    | 2        | Yes    |
| 7      | 111    | 3        | Yes    |
| 8      | 1000   | 1        | No     |
| 9      | 1001   | 2        | Yes    |
| 10     | 1010   | 2        | Yes    |

Count = 4

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(R - L) | One pass through the range; popcount is O(1) |
| **Space** | O(1) | Fixed-size prime set (8 elements) |
