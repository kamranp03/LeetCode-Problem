# Problem 3454 - Separate Squares II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/separate-squares-ii/
**Language:** C++

---

## Problem Statement

Given a list of axis-aligned squares, find a horizontal line `y = H` that splits the total covered area (union of all squares, counting overlapping regions only once) exactly in half. Return the y-coordinate of this horizontal line.

## Approach: Coordinate Compression + Segment Tree Sweep Line

Unlike Part I (which counts total area with multiplicity), here we need the area of the union of squares, which requires handling overlaps. The approach uses a coordinate-compressed segment tree sweep line:
- Compress all x-coordinates.
- Create "enter" and "exit" events at each square's bottom and top y-coordinate.
- Sweep from bottom to top, maintaining covered width via a segment tree.
- Accumulate area in strips and stop when we reach half the total.

## Code Walkthrough (Step by Step)

1. **Segment Tree** `SegmentTree` tracks how many rectangles cover each x-segment (`coveredCount`) and the actual covered width (`coveredWidth`).
2. **Build events:** for each square, create `(y, +1, xl, xr)` and `(y+l, -1, xl, xr)` events.
3. **Sort events by y** (ascending).
4. **Compute total union area** via `getArea()`: sweep through events, accumulating `coveredWidth * height_of_strip`.
5. **Find split line:** sweep again, accumulating area strip by strip. When `area + areaGain >= halfArea`, return `prevY + (halfArea - area) / coveredWidth`.

## Dry Run

**Example Input:** `squares = [[0, 0, 2], [1, 1, 2]]`

- xs = {0, 1, 2, 3}, events sorted by y.
- Sweep up: strips accumulate union area.
- When cumulative area equals half, return the exact y.

**Output:** (exact floating point line that splits union area in half)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting events + O(log n) per segment tree update |
| **Space** | O(n) | Segment tree of size 4n, event list |
