# Problem 3625 - Count Number of Trapezoids II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/count-number-of-trapezoids-ii/
**Language:** C++

---

## Problem Statement

Given a list of points on a 2D plane, count the number of trapezoids (sets of 4 points) that have exactly one pair of parallel sides (the parallel sides need not be horizontal). Return the total count.

## Approach: Count Parallel-Line Pairs, Subtract Parallelograms

A trapezoid with exactly one pair of parallel sides = (pairs of collinear point-pairs with same slope) - (pairs of point-pairs with same slope AND same midpoint, which are parallelograms). 

The algorithm:
1. For every pair of points, compute their slope (normalized fraction) and the line they lie on (slope + intercept).
2. Group pairs by (slope, intercept): pairs on the same line. Count combinations C(k,2) for k pairs on the same line.
3. Subtract pairs that share the same slope AND same midpoint (these form parallelograms, not trapezoids).

## Code Walkthrough (Step by Step)

1. **For each pair (i,j):** compute reduced slope `(dy/dx)` as a normalized fraction. Handle vertical lines specially. Compute intercept. Compute midpoint packed into a 64-bit key.
2. **Map `m1`:** slope key → list of intercepts. Group same-slope, same-intercept pairs (they're on the same line).
3. **Map `m2`:** midpoint key → list of slopes. Group same-midpoint, same-slope pairs (parallelogram diagonals).
4. **For each group in `m1`:** accumulate `c * prev` for each intercept count `c` (counting how many same-line pair-pairs exist). This gives pairs of parallel segments.
5. **For each group in `m2`:** subtract `c * prev` for same-slope, same-midpoint pairs (parallelograms).
6. **Return** result.

## Dry Run

**Example Input:** `points = [[0,0],[2,0],[1,1],[3,1]]`

- Pair (0,0)-(2,0): slope=(0,1), intercept=(0,1). Pair (1,1)-(3,1): slope=(0,1), intercept=(1,1).
- Both have slope (0,1) but different intercepts → they are parallel, different lines. result += 1.
- No same-midpoint same-slope pairs.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2 log n) | O(n^2) pairs, each grouped in maps |
| **Space** | O(n^2) | Storing all pair slopes and intercepts |
