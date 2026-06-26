# Problem 1266 - Minimum Time Visiting All Points

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-time-visiting-all-points/
**Language:** C++

---

## Problem Statement

Given an array of `points` on a 2D plane, where `points[i] = [xi, yi]`, return the minimum time in seconds to visit all points in the given order. You can move one unit in any of the 8 directions (horizontal, vertical, or diagonal) per second.

## Approach: Chebyshev Distance

The key insight is that diagonal movement costs just 1 step, so the minimum steps to travel from one point to another equals the Chebyshev distance: `max(|dx|, |dy|)`. Moving diagonally covers both axes simultaneously, so the bottleneck is whichever axis has the larger difference.

## Code Walkthrough (Step by Step)

1. **Initialize `time = 0`** to accumulate total travel time.
2. **Iterate from index 1** through all points, considering each consecutive pair `(i-1, i)`.
3. **Compute `dx` and `dy`** — the absolute differences in x and y coordinates.
4. **Add `max(dx, dy)`** to `time` — this is the minimum steps needed (diagonal moves handle the smaller axis for free).
5. **Return `time`** after processing all consecutive pairs.

## Dry Run

**Example Input:** `points = [[1,1],[3,4],[-1,0]]`

- Pair `[1,1] -> [3,4]`: dx = |3-1| = 2, dy = |4-1| = 3 → max(2,3) = 3
- Pair `[3,4] -> [-1,0]`: dx = |-1-3| = 4, dy = |0-4| = 4 → max(4,4) = 4
- Total time = 3 + 4 = **7**

**Output:** `7`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through all n points |
| **Space** | O(1) | Only a few integer variables used |
