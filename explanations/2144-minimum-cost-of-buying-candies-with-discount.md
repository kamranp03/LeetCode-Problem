# Problem 2144 - Minimum Cost of Buying Candies With Discount

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
**Language:** C++

---

## Problem Statement
A shop offers a discount: every time you buy 2 candies, you get a 3rd candy for free (the cheapest of the three). Given the cost of `n` candies, return the minimum amount of money needed to buy all of them.

## Approach: Sort Descending + Skip Every Third

The key insight is that to minimize total cost, we want the free candies to be as expensive as possible. By sorting in descending order, the free candy (every 3rd in sorted order at indices 2, 5, 8...) is always the cheapest of each group of three. We simply skip adding the cost at every index where `i % 3 == 2`.

## Code Walkthrough (Step by Step)

1. **Sort `cost` in descending order** (most expensive first).
2. **Initialize `ans = 0`**.
3. **Loop** through all indices `i`:
   - If `i % 3 == 2`: skip this candy (it's free — the cheapest in its group of 3).
   - Otherwise: add `cost[i]` to `ans`.
4. **Return `ans`**.

## Dry Run

**Example Input:** `cost = [1, 2, 3]`

After sort descending: `[3, 2, 1]`

| i | cost[i] | i%3==2? | ans |
|---|---------|---------|-----|
| 0 | 3       | No      | 3   |
| 1 | 2       | No      | 5   |
| 2 | 1       | Yes     | 5   |

Candy at index 2 (cost=1, cheapest) is free.

**Output:** `5`

**Another Example:** `cost = [6, 5, 7, 9, 2, 2]`

After sort: `[9, 7, 6, 5, 2, 2]`

- i=0: pay 9 → ans=9
- i=1: pay 7 → ans=16
- i=2: free (6 skipped)
- i=3: pay 5 → ans=21
- i=4: pay 2 → ans=23
- i=5: free (2 skipped)

**Output:** `23`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting dominates; the loop is O(n) |
| **Space** | O(1) | In-place sort; only one accumulator variable |
