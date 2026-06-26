# Problem 2110 - Number of Smooth Descent Periods of a Stock

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
**Language:** C++

---

## Problem Statement
A smooth descent period of a stock consists of one or more contiguous days where each day (after the first) the price is exactly 1 less than the previous day. Given an array `prices`, return the total number of smooth descent periods (including single-day periods).

## Approach: Dynamic Programming — Running Length Count

The key insight is that if the last `k` prices form a smooth descent of length `k`, then every suffix of that descent is also a valid period. So at each position, the number of new smooth descent periods ending at position `i` equals the current streak length (`count`). Summing all these streak lengths gives the total.

## Code Walkthrough (Step by Step)

1. **Initialize `res = 1`** (the first day is always a period of length 1) and **`count = 1`** (current streak length).
2. **Loop from i=1 to prices.size()-1**:
   - If `prices[i-1] - prices[i] == 1` (price dropped by exactly 1): extend the streak, `count++`.
   - Otherwise: reset `count = 1` (start a new streak from this day alone).
   - Add `count` to `res`.
3. **Return `res`**.

## Dry Run

**Example Input:** `prices = [3, 2, 1, 4]`

| i | prices[i-1]-prices[i] | count | res |
|---|----------------------|-------|-----|
| - | -                    | 1     | 1   |
| 1 | 3-2=1                | 2     | 3   |
| 2 | 2-1=1                | 3     | 6   |
| 3 | 1-4=-3 (not 1)       | 1     | 7   |

The 7 periods are: [3],[2],[1],[4],[3,2],[2,1],[3,2,1].

**Output:** `7`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the prices array |
| **Space** | O(1) | Only two scalar variables `count` and `res` |
