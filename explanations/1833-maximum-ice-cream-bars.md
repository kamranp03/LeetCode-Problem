# Problem 1833 - Maximum Ice Cream Bars

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-ice-cream-bars/
**Language:** C++

---

## Problem Statement

Given an array `costs` where `costs[i]` is the price of the i-th ice cream bar, and an integer `coins` representing your budget, return the maximum number of ice cream bars you can buy (in any order).

## Approach: Greedy — Sort and Buy Cheapest First

The key insight is that to maximize the number of ice cream bars, we should always buy the cheapest available ones first. By sorting `costs` in ascending order and greedily purchasing until we run out of coins, we guarantee the maximum count.

## Code Walkthrough (Step by Step)

1. **Sort `costs` in ascending order** so the cheapest bars come first.
2. **Initialize `ans = 0`.**
3. **Iterate through each `cost` in sorted `costs`:**
   - If `coins < cost`: break (can't afford this or anything more expensive).
   - Otherwise: subtract `cost` from `coins` and increment `ans`.
4. **Return `ans`.**

## Dry Run

**Example Input:** `costs = [1,3,2,4,1]`, `coins = 7`

- Sorted: [1, 1, 2, 3, 4]
- Buy cost=1: coins=6, ans=1
- Buy cost=1: coins=5, ans=2
- Buy cost=2: coins=3, ans=3
- Buy cost=3: coins=0, ans=4
- cost=4 > 0 → break
- Return **4**

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting dominates |
| **Space** | O(1) | In-place sort, no extra space |
