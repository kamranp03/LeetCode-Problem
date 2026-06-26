# Problem 509 - Fibonacci Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/fibonacci-number/
**Language:** C++

---

## Problem Statement
The Fibonacci numbers form the sequence: F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1. Given `n`, calculate and return `F(n)`.

## Approach: Iterative Bottom-Up DP (Space-Optimized)

The key insight is to avoid the exponential time of naive recursion by computing Fibonacci numbers iteratively from the bottom up. We only need the two most recent values at any time (F(n-1) and F(n-2)), so we use three variables instead of an array. This gives optimal O(n) time with O(1) space.

## Code Walkthrough (Step by Step)

1. **Base case:** If `n <= 1`, return `n` directly (F(0)=0, F(1)=1).

2. **Initialize:** Set `a = 0` (F(0)) and `b = 1` (F(1)).

3. **Iterate from i=2 to n:**
   - Compute `c = a + b` (the next Fibonacci number).
   - Shift: `a = b` (move one step forward).
   - Shift: `b = c` (b now holds F(i)).

4. **Return `b`** — after the loop, `b` holds F(n).

## Dry Run

**Example Input:** `n = 6`

| i | a | b | c = a+b |
|---|---|---|---------|
| start | 0 | 1 | - |
| 2 | 1 | 1 | 1 |
| 3 | 1 | 2 | 2 |
| 4 | 2 | 3 | 3 |
| 5 | 3 | 5 | 5 |
| 6 | 5 | 8 | 8 |

After loop: b = 8

**Output:** `8` (F(6) = 0,1,1,2,3,5,8)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single loop from 2 to n, each iteration is O(1) |
| **Space** | O(1) | Only three integer variables used, no array needed |
