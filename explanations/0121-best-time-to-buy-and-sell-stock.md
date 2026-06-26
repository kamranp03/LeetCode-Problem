# Problem 121 - Best Time to Buy and Sell Stock

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
**Language:** C++

---

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve. If no profit is possible, return 0.

## Approach: Greedy - Track Minimum Price

The key insight is to make a single pass through the prices, keeping track of the minimum price seen so far (`mini`). At each day, the best profit we could make if we sold today is `prices[i] - mini`. We update the running maximum profit (`maxi`) with this value. We also update `mini` if today's price is lower. This works because selling always happens after buying — `mini` is always from a day before the current day.

## Code Walkthrough (Step by Step)

1. **Initialize:** Set `mini = prices[0]` (the best buy price so far) and `maxi = 0` (no profit yet).

2. **Iterate from day 1:** For each day `i` from index 1 to `n-1`:
   - Compute `cost = prices[i] - mini`. This is the profit if we had bought at `mini` and sell today.
   - Update `maxi = max(maxi, cost)`. If this is better than the current best, record it.
   - Update `mini = min(mini, prices[i])`. If today's price is lower than any seen before, update the cheapest buy price.

3. **Return `maxi`:** The maximum profit achievable with a single buy-sell transaction.

## Dry Run

**Example Input:** `prices = [7, 1, 5, 3, 6, 4]`

| Day | price | mini | cost (profit if sold today) | maxi |
|-----|-------|------|-----------------------------|------|
| 0   | 7     | 7    | —                           | 0    |
| 1   | 1     | 1    | 1-7 = -6                   | 0    |
| 2   | 5     | 1    | 5-1 = 4                    | 4    |
| 3   | 3     | 1    | 3-1 = 2                    | 4    |
| 4   | 6     | 1    | 6-1 = 5                    | 5    |
| 5   | 4     | 1    | 4-1 = 3                    | 5    |

**Output:** `5` (buy at price 1, sell at price 6)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the prices array |
| **Space** | O(1) | Only two extra variables: `mini` and `maxi` |
