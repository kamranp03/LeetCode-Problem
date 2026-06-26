# Problem 3623 - Count Number of Trapezoids I

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-number-of-trapezoids-i/
**Language:** C++

---

## Problem Statement

Given a list of points on a 2D plane, count the number of trapezoids that can be formed using exactly 4 of these points, where the trapezoid has exactly one pair of parallel sides (both sides must be horizontal, i.e., at the same y-coordinate). Return the count modulo `10^9 + 7`.

## Approach: Count Horizontal Pairs per Y-Level

A trapezoid needs exactly two horizontal segments at different y-values. For each y-level with `count` points, there are `C(count, 2) = count*(count-1)/2` horizontal line segments. Two horizontal segments at different y-levels (one from level A, one from level B) form a trapezoid. We accumulate: for each new y-level, add `newPairs * prevTotalPairs` to the result, then add `newPairs` to `prevTotalPairs`.

## Code Walkthrough (Step by Step)

1. **Count points per y-value** using a hash map `mp`.
2. **Initialize** `prevHoriLine = 0` and `res = 0`.
3. **For each y-level** with `count` points:
   a. Compute `horiLine = count * (count - 1) / 2` (segments at this level).
   b. `res += horiLine * prevHoriLine` (pair each new segment with every previous segment from different y-levels).
   c. `prevHoriLine += horiLine` (accumulate for future levels).
4. **Return** `res % M`.

## Dry Run

**Example Input:** `points = [[0,0],[1,0],[2,1],[3,1]]`

- y=0: count=2, horiLine=1. res += 1*0 = 0. prevHoriLine=1.
- y=1: count=2, horiLine=1. res += 1*1 = 1. prevHoriLine=2.

**Output:** `1` (one trapezoid with base y=0 and top y=1)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | One pass to count per y-level, one pass over levels |
| **Space** | O(n) | Hash map storing point counts per y |
