# Problem 3047 - Find the Largest Area of Square Inside Two Rectangles

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
**Language:** C++

---

## Problem Statement

Given `n` axis-aligned rectangles defined by their bottom-left and top-right corners, find the largest area of a square that fits inside the intersection of at least two different rectangles. Return `0` if no such square exists.

## Approach: Pairwise Rectangle Intersection

For every pair of rectangles `(i, j)`, compute their intersection rectangle. The intersection exists when the overlapping region has positive width and height. The largest square fitting inside has side equal to `min(width, height)`. We track the maximum such side length squared.

## Code Walkthrough (Step by Step)

1. **Iterate all pairs** `(i, j)` where `i < j` using two nested loops.

2. **Compute intersection:**
   - `left = max(bottomLeft[i][0], bottomLeft[j][0])`
   - `right = min(topRight[i][0], topRight[j][0])`
   - `bottom = max(bottomLeft[i][1], bottomLeft[j][1])`
   - `top = min(topRight[i][1], topRight[j][1])`

3. **Check validity:** Intersection is non-empty only if `left < right && bottom < top`.

4. **Compute max square:** `side = min(right - left, top - bottom)`. Update `ans = max(ans, side * side)`.

5. **Return** `ans`.

## Dry Run

**Example Input:**
```
bottomLeft = [[1,1],[2,2],[3,1]]
topRight   = [[3,3],[4,4],[6,6]]
```

Pair (0,1): left=2, right=3, bottom=2, top=3 → width=1, height=1 → side=1, area=1
Pair (0,2): left=3, right=3 → left not < right → no intersection
Pair (1,2): left=3, right=4, bottom=2, top=4 → width=1, height=2 → side=1, area=1

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2) | Check all pairs of rectangles |
| **Space** | O(1) | Only a few variables for intersection computation |
