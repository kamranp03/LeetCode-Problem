# Problem 1411 - Number of Ways to Paint N x 3 Grid

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/number-of-ways-to-paint-n-x-3-grid/
**Language:** C++

---

## Problem Statement

You have an `n x 3` grid to paint with 3 colors such that no two adjacent cells (horizontally or vertically) share the same color. Return the number of ways to paint the grid modulo 10^9 + 7.

## Approach: Dynamic Programming on Row Pattern Types

The key insight is that valid 3-cell rows (no two adjacent same color) fall into exactly two structural categories:
- **Type A (ABA patterns):** 3 colors, alternating — e.g., "aba". There are 6 such patterns (3 choices for first, 2 for second, 1 forced for third).
- **Type B (ABC patterns):** All 3 different — e.g., "abc". There are 6 such patterns (3! = 6).

The DP transition counts how many of the next row's A-type and B-type patterns are compatible with the current row.

## Code Walkthrough (Step by Step)

1. **Initialize:** `dpA = 6` (6 ABA-type patterns for row 1), `dpB = 6` (6 ABC-type patterns for row 1).
2. **Transition for rows 2..n:**
   - Each A-type row is compatible with 2 A-type and 2 B-type next rows → `newA = 2*dpA + 2*dpB`
   - Each B-type row is compatible with 2 A-type and 3 B-type next rows → `newB = 2*dpA + 3*dpB`
3. **Apply modulo** at each step to prevent overflow.
4. **Return `(dpA + dpB) % MOD`** — total ways across all pattern types.

## Dry Run

**Example Input:** `n = 2`

- Row 1: dpA=6, dpB=6
- Row 2: newA = 2*6+2*6 = 24, newB = 2*6+3*6 = 30
- Total = 24 + 30 = **54**

**Output:** `54`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single loop over n rows |
| **Space** | O(1) | Only two DP state variables |
