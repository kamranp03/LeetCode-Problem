# Problem 1975 - Maximum Matrix Sum

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-matrix-sum/
**Language:** C++

---

## Problem Statement
Given an `n x n` integer matrix, you may multiply any two adjacent elements (horizontally or vertically) by `-1` any number of times. Return the maximum possible sum of all matrix elements after performing any number of such operations.

## Approach: Greedy — Count Negatives and Track Minimum Absolute Value

The key insight is that multiplying two adjacent elements by -1 effectively "moves" a negative sign across the matrix. If there is an even number of negatives, we can eliminate all of them (sum all absolute values). If there is an odd number, we must leave exactly one negative — the best choice is to negate the element with the smallest absolute value (minimizes the loss). So the answer is: sum of all absolute values, minus twice the minimum absolute value if negative count is odd.

## Code Walkthrough (Step by Step)

1. **Initialize** `totalSum = 0`, `negCount = 0`, `minAbs = INT_MAX`.
2. **Iterate over all elements**:
   - If element is negative, increment `negCount`.
   - Add `abs(x)` to `totalSum`.
   - Update `minAbs = min(minAbs, abs(x))`.
3. **If `negCount` is odd**: We must leave one negative sign. Subtract `2 * minAbs` from `totalSum` (because we had already added `minAbs`, but we need it to count as `-minAbs`, a difference of `2 * minAbs`).
4. **Return `totalSum`**.

## Dry Run

**Example Input:**
```
matrix = [[1, -1],
          [-1,  1]]
```

Elements: 1, -1, -1, 1
- negCount = 2, totalSum = 1+1+1+1 = 4, minAbs = 1
- negCount is even → no adjustment

**Output:** `4`

**Another Example:** `matrix = [[-1, 1], [-1, 1]]`
- negCount = 2, totalSum = 4, minAbs = 1
- Even → Output: `4`

**Odd negatives example:** `matrix = [[1, 2], [3, -4]]`
- negCount = 1 (odd), totalSum = 10, minAbs = 1
- totalSum -= 2*1 = 8

**Output:** `8`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n²) | Single pass over all n² elements of the matrix |
| **Space** | O(1) | Only three scalar variables maintained |
