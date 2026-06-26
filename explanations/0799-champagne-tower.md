# Problem 799 - Champagne Tower

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/champagne-tower/
**Language:** C++

---

## Problem Statement
Champagne is poured into the top glass of a pyramid. When a glass is full (holds exactly 1 unit), any excess overflows equally to the two glasses directly below it. Given how much champagne is poured and a target row and glass position, return how full that glass is (at most 1.0).

## Approach: Top-Down Memoization (Recursive DP)

The key insight is that the amount in glass `(i, j)` depends on the overflow from its two parent glasses `(i-1, j-1)` and `(i-1, j)`. Each parent contributes `max(0, parent_amount - 1) / 2` to the child. We memoize results in a 2D table `t[i][j]` to avoid recomputation. The final answer is clamped to `min(1.0, result)` since a glass can hold at most 1 unit.

## Code Walkthrough (Step by Step)

1. **Base case:** `solve(p, 0, 0)` returns `p` — the top glass receives all poured champagne.

2. **Boundary cases:** If `i < 0`, `j < 0`, or `i < j` (invalid glass), return 0.

3. **Recursive relation:**
   - `left = (solve(p, i-1, j-1) - 1) / 2.0` — overflow from upper-left parent.
   - `right = (solve(p, i-1, j) - 1) / 2.0` — overflow from upper-right parent.
   - Clamp both to 0 if negative (no overflow when parent isn't full).
   - `t[i][j] = left + right`

4. **Initialize** all `t[i][j] = -1` and call `min(1.0, solve(poured, query_row, query_glass))`.

## Dry Run

**Example Input:** `poured = 2, query_row = 1, query_glass = 1`

- `solve(2, 0, 0) = 2` (top glass has 2 units)
- `solve(2, 1, 1)`:
  - left = `(solve(2,0,0) - 1) / 2 = (2-1)/2 = 0.5`
  - right = `(solve(2,0,1) - 1) / 2 = (0-1)/2 = -0.5` → clamped to 0
  - result = 0.5 + 0 = 0.5
- `min(1.0, 0.5) = 0.5`

**Output:** `0.5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(R^2) | Each of the R*(R+1)/2 glasses computed at most once |
| **Space** | O(101 * 101) | Fixed memoization table for rows 0..100 |
