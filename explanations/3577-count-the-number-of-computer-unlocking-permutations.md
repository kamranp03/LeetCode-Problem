# Problem 3577 - Count the Number of Computer Unlocking Permutations

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
**Language:** C++

---

## Problem Statement

Given an array `complexity` of `n` computers, count the number of valid permutations to unlock them. The first computer (index 0) must be unlocked first. Computer `i` (for i > 0) can only be unlocked after some earlier computer in the sequence has complexity strictly greater than `complexity[i]`. Essentially, all other computers must have complexity strictly greater than `complexity[0]`.

## Approach: Combinatorial Counting

The key insight: computer 0 must be unlocked first and must have the smallest complexity value. If any other computer has complexity <= `complexity[0]`, it's impossible (return 0). Otherwise, the remaining `n-1` computers can be arranged in any order after computer 0. There are `(n-1)!` valid permutations, since computer 0 acts as the "key" for all others.

## Code Walkthrough (Step by Step)

1. **For each computer `i` from 1 to n-1:** if `complexity[i] <= complexity[0]`, return `0` (impossible).
2. **Multiply result** by `i` (computing `(n-1)!` incrementally), taking modulo `1e9+7`.
3. **Return** `res`.

## Dry Run

**Example Input:** `complexity = [2, 5, 3, 7]`

- i=1: complexity[1]=5 > 2. res = 1*1 = 1.
- i=2: complexity[2]=3 > 2. res = 1*2 = 2.
- i=3: complexity[3]=7 > 2. res = 2*3 = 6.

**Output:** `6` (= 3! = 6 valid permutations of the remaining 3 computers)

**Example Input:** `complexity = [5, 3, 7]`

- i=1: complexity[1]=3 <= 5. Return 0.

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only a running product variable |
