# Problem 2975 - Maximum Square Area by Removing Fences From a Field

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/
**Language:** C++

---

## Problem Statement

You have an `m x n` field with horizontal fences at given rows and vertical fences at given columns (boundary fences always present). You can remove any subset of the interior fences. Return the maximum area of a square region you can form modulo `10^9 + 7`, or `-1` if impossible.

## Approach: Store All Horizontal Gaps, Check Against Vertical Gaps

A square region is bounded by two horizontal fences and two vertical fences, with equal width and height. We enumerate all possible distances between pairs of horizontal fences, store them in a hash set, then enumerate all distances between pairs of vertical fences. If a vertical distance also appears as a horizontal distance, it can form a square. We track the maximum such distance.

## Code Walkthrough (Step by Step)

1. **Add boundary fences:** Push `1` and `m` into `hFences`, and `1` and `n` into `vFences`. Sort both.

2. **Collect all horizontal distances:** Use a nested loop over all pairs in `hFences`. Compute `hFences[j] - hFences[i]` and insert into hash set `hDist`.

3. **Check vertical distances:** Use a nested loop over all pairs in `vFences`. For each distance `d = vFences[j] - vFences[i]`, if `d` is in `hDist`, update `maxSide`.

4. **Return** `-1` if no common distance found, otherwise `(maxSide * maxSide) % MOD`.

## Dry Run

**Example Input:** `m=4, n=3, hFences=[2,3], vFences=[2]`

- hFences (with boundaries): [1, 2, 3, 4]
- vFences (with boundaries): [1, 2, 3]
- Horizontal gaps: {1, 2, 3} (all pairs)
- Vertical gaps: 1 (1→2), 1 (2→3), 2 (1→3)
- Common: 1 and 2 both exist. maxSide = 2
- Area = (2 * 2) % MOD = 4

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(h^2 + v^2) | All pairs enumerated for each direction |
| **Space** | O(h^2) | Hash set stores all horizontal pairwise distances |
