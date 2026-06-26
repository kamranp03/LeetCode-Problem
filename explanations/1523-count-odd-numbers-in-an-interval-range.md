# Problem 1523 - Count Odd Numbers in an Interval Range

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
**Language:** C++

---

## Problem Statement

Given two non-negative integers `low` and `high`, return the count of odd numbers between `low` and `high` (inclusive).

## Approach: Math Formula

The key insight is that the number of odd integers in `[1, n]` is `(n+1)/2` using integer division. So the count of odds in `[low, high]` equals `(high+1)/2 - low/2`. This works because `low/2` counts odds in `[1, low-1]`, and `(high+1)/2` counts odds in `[1, high]`.

## Code Walkthrough (Step by Step)

1. **Formula:** Return `(high + 1) / 2 - low / 2`.
   - `(high + 1) / 2` = number of odd integers in range `[0, high]`
   - `low / 2` = number of odd integers in range `[0, low - 1]`
   - Their difference = count of odds in `[low, high]`

## Dry Run

**Example Input:** `low = 3`, `high = 7`

- Odd numbers: 3, 5, 7 → count = 3
- Formula: (7+1)/2 - 3/2 = 4 - 1 = **3**

**Example Input:** `low = 8`, `high = 10`

- Odd numbers: 9 → count = 1
- Formula: (10+1)/2 - 8/2 = 5 - 4 = **1**

**Output:** `3` for first example, `1` for second

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Single arithmetic expression |
| **Space** | O(1) | No extra memory used |
