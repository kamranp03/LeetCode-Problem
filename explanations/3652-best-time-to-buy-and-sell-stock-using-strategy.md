# Problem 3652 - Best Time to Buy and Sell Stock Using Strategy

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/
**Language:** C++

---

## Problem Statement

Given `n` stocks on `n` days with `prices[i]` and a strategy array `strategy[i]` (either 0 or 1), and a window size `k`. The "actual profit" from day `i` is `strategy[i] * prices[i]`. You can choose to replace one window of `k` consecutive days with actual prices (ignoring the strategy for those days). The total gain from the window replacement is `sum(prices[j..j+k-1]) - sum(profit[j..j+k-1])` for positions `j+k/2` to `j+k-1`. Find the maximum total profit.

## Approach: Sliding Window for Maximum Gain

Compute `profit[i] = strategy[i] * prices[i]` (baseline profit from following strategy). Then slide a window of size `k` to find the window replacement that maximizes the gain `sum(prices[j+k/2..j+k-1]) - sum(profit[j..j+k-1])`. The gain for a window starting at `i` is the sum of actual prices for the second half minus the strategy profit for the whole window.

## Code Walkthrough (Step by Step)

1. **Compute `actualP`** = sum of all `profit[i] = strategy[i] * prices[i]`.
2. **Slide a window of size `k`** using two pointers `i` and `j`:
   - Add `profit[j]` to `originalP` (strategy profit over window).
   - When `j - i + 1 > k/2`, add `prices[j]` to `modifiedP` (real prices for second half of window).
   - When window exceeds `k`, subtract the contributions of `i` and advance `i`.
   - When window exactly equals `k`, compute gain = `modifiedP - originalP` and update `maxG`.
3. **Return** `actualP + maxG`.

## Dry Run

**Example Input:** `prices=[1,2,3,4,5]`, `strategy=[1,0,1,0,1]`, `k=4`

- profit = [1,0,3,0,5]. actualP=9.
- Window i=0,j=3: originalP=1+0+3+0=4. modifiedP=prices[2]+prices[3]=3+4=7. gain=7-4=3.
- Window i=1,j=4: originalP=0+3+0+5=8. modifiedP=prices[3]+prices[4]=4+5=9. gain=9-8=1.
- maxG=3.

**Output:** `9 + 3 = 12`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single sliding window pass |
| **Space** | O(n) | Profit array of size n |
