# Problem 3453 - Separate Squares I

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/separate-squares-i/
**Language:** C++

---

## Problem Statement

Given a list of axis-aligned squares defined by `[x, y, side]` (bottom-left corner coordinates and side length), find a horizontal line `y = H` that divides the total area of squares equally — the area below `H` equals the area above `H`. Return the y-coordinate of this line.

## Approach: Binary Search on the Answer

The key insight is that the function "area below height H" is monotonically non-decreasing as H increases. So we can binary search on H. For a given H, we compute how much square area lies strictly below it, and adjust our search window accordingly.

## Code Walkthrough (Step by Step)

1. **Compute total area** by summing `side * side` for all squares.
2. **Set binary search bounds:** `low` = minimum y-coordinate, `high` = maximum y + side.
3. **Target area** = `totalArea / 2.0`.
4. **Lambda `areaBelow(H)`:** for each square, add:
   - 0 if H is at or below the square's base.
   - `side * side` if H is at or above the top of the square.
   - `(H - y) * side` for partial overlap.
5. **Binary search** until `high - low < 1e-6`, returning `low` as the answer.

## Dry Run

**Example Input:** `squares = [[0, 0, 1], [0, 1, 1]]`

- Total area = 1 + 1 = 2. Target = 1.
- low=0, high=2. mid=1.0 → areaBelow(1.0) = 1 (exactly square 1) = 1.0 >= 1 → high=1.0.
- Eventually converges to H = 1.0.

**Output:** `1.0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log(range/eps)) | ~50 binary search iterations, each O(n) area check |
| **Space** | O(1) | No extra data structures |
