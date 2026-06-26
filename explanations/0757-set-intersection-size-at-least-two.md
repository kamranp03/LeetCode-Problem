# Problem 757 - Set Intersection Size At Least Two

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/set-intersection-size-at-least-two/
**Language:** C++

---

## Problem Statement
Given a list of intervals, find the minimum size of a set S such that every interval contains at least two elements of S. The answer is the total count of elements that must be added to S to satisfy all intervals simultaneously.

## Approach: Greedy with Sorted Intervals

Sort intervals by their right endpoint (ascending), and by left endpoint descending when right endpoints tie. This ordering ensures we process the most constrained intervals first. We maintain the two largest elements currently in our set (`first` = second largest, `second` = largest). For each interval, if its left boundary already covers both tracked elements, skip it. If it covers only one, add one element. Otherwise add two new elements (the last two of that interval's range).

## Code Walkthrough (Step by Step)

1. **Sort:** Sort by `right` ascending; on ties sort by `left` descending. This ensures tighter intervals (smaller ranges) are handled first.

2. **Initialize:** `first = -1`, `second = -1` — no elements in set yet. `res = 0`.

3. **Iterate each interval `[l, r]`:**
   - If `l <= first`: both `first` and `second` are inside `[l, r]` — skip, already covered.
   - If `l > second`: neither tracked element is in the interval — add 2 new elements (`r-1` and `r`). Update `first = r-1`, `second = r`.
   - Else (`first < l <= second`): exactly one element (`second`) is inside — add 1 more. Update `first = second`, `second = r`.

4. **Return** `res`.

## Dry Run

**Example Input:** `intervals = [[1,3],[3,7],[8,9]]`

- Sorted: [[1,3],[3,7],[8,9]]
- i=0, [1,3]: l=1 > second=-1 → add 2, first=2, second=3, res=2
- i=1, [3,7]: l=3 > first=2, l=3 <= second=3 → add 1, first=3, second=7, res=3
- i=2, [8,9]: l=8 > second=7 → add 2, first=8, second=9, res=5

**Output:** `5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N log N) | Sorting dominates; single pass is O(N) |
| **Space** | O(1) | Only a constant number of variables used |
