# Problem 0070 - Climbing Stairs

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/climbing-stairs/
**Language:** C++

---

## Problem Statement

You are climbing a staircase with `n` steps. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

## Approach: Dynamic Programming (Space-Optimized Fibonacci)

The key insight is that to reach step `n`, you can come either from step `n-1` (by taking 1 step) or from step `n-2` (by taking 2 steps). So `ways(n) = ways(n-1) + ways(n-2)` — exactly the Fibonacci recurrence. Base cases: `ways(1) = 1`, `ways(2) = 2`. Instead of storing all values, we only need the previous two, making the space O(1).

## Code Walkthrough (Step by Step)

1. **Handle base cases:** if `n <= 2`, return `n` directly (1 way for n=1, 2 ways for n=2).
2. **Initialize:** `prev2 = 1` (ways for step 1), `prev1 = 2` (ways for step 2).
3. **Loop `i` from 3 to `n`:**
   - `curr = prev1 + prev2` (Fibonacci: sum of previous two values).
   - Shift: `prev2 = prev1`, `prev1 = curr`.
4. **Return `prev1`** (which holds `ways(n)` after the loop).

## Dry Run

**Example Input:** `n = 5`

| i | prev2 | prev1 | curr (prev1+prev2) |
|---|-------|-------|---------------------|
| — | 1     | 2     | —                   |
| 3 | 2     | 3     | 2+1=3               |
| 4 | 3     | 5     | 3+2=5               |
| 5 | 5     | 8     | 5+3=8               |

Return `prev1 = 8`

**Output:** `8`

Verification: ways to climb 5 stairs = 8
(1+1+1+1+1, 2+1+1+1, 1+2+1+1, 1+1+2+1, 1+1+1+2, 2+2+1, 2+1+2, 1+2+2)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single loop from 3 to n |
| **Space** | O(1) | Only two rolling variables (`prev1` and `prev2`) |
