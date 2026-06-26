# Problem 1925 - Count Square Sum Triples

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-square-sum-triples/
**Language:** C++

---

## Problem Statement
Given a positive integer `n`, count the number of triples `(a, b, c)` where `1 <= a, b, c <= n` and `a² + b² = c²`. Return the total count of such triples.

## Approach: Brute Force with Square Root Check

The key insight is that for each pair `(a, b)`, we compute `a² + b²` and check if its square root is a perfect integer `c` that is also within bounds `[1, n]`. To avoid double-counting ordered pairs, we iterate `b` from `a+1` upward and multiply the count by 2 (since `(a, b, c)` and `(b, a, c)` are both valid distinct triples).

## Code Walkthrough (Step by Step)

1. **Outer loop `a` from 1 to n**: Fix the smaller value.
2. **Inner loop `b` from a+1 to n**: Fix the second value (always > a to avoid repeat pairs).
3. **Compute `s = a*a + b*b`**: The candidate for `c²`.
4. **Check `x = sqrt(s)`**: If `x*x == s` (perfect square) and `x <= n`, we found a valid triple.
5. **Add 2 to the count**: Because `(a, b, c)` and `(b, a, c)` are two distinct triples.
6. **Return the count**.

## Dry Run

**Example Input:** `n = 5`

| a | b | s = a²+b² | x = √s | x*x==s? | x<=5? | count |
|---|---|-----------|--------|---------|-------|-------|
| 1 | 2 | 5         | 2      | No      | -     | 0     |
| 1 | 3 | 10        | 3      | No      | -     | 0     |
| 1 | 4 | 17        | 4      | No      | -     | 0     |
| 1 | 5 | 26        | 5      | No      | -     | 0     |
| 2 | 3 | 13        | 3      | No      | -     | 0     |
| 2 | 4 | 20        | 4      | No      | -     | 0     |
| 2 | 5 | 29        | 5      | No      | -     | 0     |
| 3 | 4 | 25        | 5      | Yes     | Yes   | 2     |
| 3 | 5 | 34        | 5      | No      | -     | 2     |
| 4 | 5 | 41        | 6      | No      | -     | 2     |

Triples found: (3,4,5) and (4,3,5).

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n²) | Double nested loop over all pairs (a, b) |
| **Space** | O(1) | Only a counter and a few integer variables used |
