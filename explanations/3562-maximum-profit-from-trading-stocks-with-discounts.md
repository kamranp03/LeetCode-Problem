# Problem 3562 - Maximum Profit from Trading Stocks with Discounts

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/
**Language:** C++

---

## Problem Statement

Given a tree of `n` stocks (rooted at node 0) with `present` prices and `future` prices, and a total `budget`, find the maximum profit. If you buy a stock whose parent was also bought, you get a 50% discount on it. Maximize the sum of `(future[i] - price_paid[i])` for bought stocks, subject to total spending not exceeding `budget`.

## Approach: Tree DP (DFS with Knapsack)

This is a tree knapsack problem. For each node `u`, compute `stateP[u][parent_bought][budget]` = maximum profit from the subtree rooted at `u` given the budget used so far, and whether `u`'s parent was bought (affecting `u`'s price).

The DFS merges children's DP tables one by one using a convolution (O(budget^2) per merge).

## Code Walkthrough (Step by Step)

1. **Build adjacency list** from the hierarchy edges.
2. **DFS from root (node 0):** for each node `u`:
   a. Recursively compute DFS for all children.
   b. For each parent state (0 = parent not bought, 1 = parent bought):
      - Compute `price = present[u]/2` if parent bought, else `present[u]`.
      - **Case 1 (don't buy u):** merge children DP tables treating children as "parent not bought".
      - **Case 2 (buy u):** merge children DP tables treating children as "parent bought", then add `profit = future[u] - price` at budgets >= price.
   c. Store `stateP[u][parent] = best`.
3. **Answer** = max over all budgets of `stateP[0][0][b]` (root has no parent bought).

## Dry Run

**Example Input:** `n=2`, `present=[4,2]`, `future=[8,3]`, `hierarchy=[[1,2]]`, `budget=3`

- Node 1 (child): no children. parent=0: buy at 2, profit=1; best[2]=1, best[3]=1. parent=1: buy at 1, profit=2; best[1]=2.
- Node 0: child=node 1. parent=0: buy at 4 (cost>budget=3, can't); don't buy: best from child (parent not bought) → best[2]=1. Answer=1.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * budget^2) | Knapsack convolution per tree node |
| **Space** | O(n * budget) | DP tables for all nodes |
