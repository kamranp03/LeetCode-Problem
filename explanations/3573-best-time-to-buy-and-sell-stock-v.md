# Problem 3573 - Best Time to Buy and Sell Stock V

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/
**Language:** C++

---

## Problem Statement

Given an array of stock prices and an integer `k`, you can make at most `k` transactions. Each transaction is either a long (buy then sell) or short (short sell then buy back). Maximize total profit from at most `k` transactions.

## Approach: DP with 3 States

Track 3 states for each transaction count `t`:
- **State 0:** "free" (no open position), having completed `t` transactions.
- **State 1:** "holding" a long position (bought, not yet sold), in transaction `t`.
- **State 2:** "short-selling" (sold short, not yet covered), in transaction `t`.

Transitions at each price:
- From free: buy (→ state 1, same t) or short-sell (→ state 2, same t).
- From bought: sell (→ state 0, t+1 transactions done).
- From short: cover/buy-back (→ state 0, t+1 transactions done).

## Code Walkthrough (Step by Step)

1. **Initialize** `dp[0][0] = 0`, everything else = NEG (unreachable).
2. **For each price:** compute `next = dp`, then apply all transitions.
3. **Free → buy:** `next[t][1] = max(..., dp[t][0] - price)`.
4. **Free → short sell:** `next[t][2] = max(..., dp[t][0] + price)`.
5. **Bought → sell:** `next[t+1][0] = max(..., dp[t][1] + price)`.
6. **Short → cover:** `next[t+1][0] = max(..., dp[t][2] - price)`.
7. **Answer** = max over all `t` of `dp[t][0]`.

## Dry Run

**Example Input:** `prices = [1, 3, 2]`, `k = 2`

- price=1: buy→dp[0][1]=-1; short sell→dp[0][2]=1.
- price=3: sell from long→dp[1][0]=2; cover short→dp[1][0]=max(2, 1-3)=-2. So dp[1][0]=2. Also buy→dp[0][1]=-3, short→dp[0][2]=3.
- price=2: sell→dp[1][0]=max(2,-1+2)=max(2,1)=2 from prior; cover→...

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * k) | n prices, k transaction states |
| **Space** | O(k) | DP table of size (k+1) x 3 |
