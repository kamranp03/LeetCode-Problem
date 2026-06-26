# Problem 122 - Best Time to Buy and Sell Stock II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
**Language:** C++

---

## Problem Statement

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `i`th day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share at a time, but you can buy and sell on the same day. Return the maximum profit you can achieve with unlimited transactions.

## Approach: Greedy - Collect Every Upward Slope

The key insight is that with unlimited transactions, the maximum profit equals the sum of all positive daily differences. Whenever `prices[i] > prices[i-1]`, it means the stock went up from yesterday to today — we can always profit from this by "buying yesterday and selling today." We don't need to find peaks and valleys explicitly; just summing every positive increment gives the same result.

## Code Walkthrough (Step by Step)

1. **Initialize:** Set `profit = 0`.

2. **Iterate from day 1:** For each index `i` starting from 1:
   - If `prices[i] > prices[i-1]`, the price increased — add the difference `prices[i] - prices[i-1]` to `profit`.
   - If `prices[i] <= prices[i-1]`, the price dropped or stayed flat — do nothing (we wouldn't buy and then sell at a loss or break-even).

3. **Return `profit`:** The accumulated sum of all positive gains.

## Dry Run

**Example Input:** `prices = [7, 1, 5, 3, 6, 4]`

| i | prices[i] | prices[i-1] | Gain | profit |
|---|-----------|-------------|------|--------|
| 1 | 1         | 7           | 0    | 0      |
| 2 | 5         | 1           | +4   | 4      |
| 3 | 3         | 5           | 0    | 4      |
| 4 | 6         | 3           | +3   | 7      |
| 5 | 4         | 6           | 0    | 7      |

(Buy at 1, sell at 5 = +4; Buy at 3, sell at 6 = +3. Total = 7)

**Output:** `7`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the prices array |
| **Space** | O(1) | Only one variable `profit` needed |
