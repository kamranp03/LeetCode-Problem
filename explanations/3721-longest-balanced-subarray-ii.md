# Problem 3721 - Longest Balanced Subarray II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/longest-balanced-subarray-ii/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, find the length of the longest subarray where the number of distinct even values equals the number of distinct odd values. Handle large inputs efficiently with a segment tree approach.

## Approach: Segment Tree with Lazy Propagation + Difference Tracking

The key insight: assign each position a +1 if the value is even, -1 if odd. But since we track distinct values (not counts), the contribution of a value at position `r` changes based on whether that value appeared previously: the first occurrence contributes +1/-1, but subsequent occurrences in the same subarray must undo the old contribution and add the new one at the current position.

A segment tree with lazy propagation tracks cumulative "difference" values (even_distinct - odd_distinct) for all starting positions. The subarray `[l, r]` is balanced when its cumulative difference is 0. We use `findLeftMostZero` to find the leftmost start `l` such that the subarray `[l, r]` has equal distinct counts.

## Code Walkthrough (Step by Step)

1. **Segment tree** maintains range min/max with lazy add, supporting range updates and "find leftmost zero" queries.
2. **For each right endpoint `r`:**
   - Compute `val = +1` (if even) or `-1` (if odd).
   - If `nums[r]` appeared before at `prev`, undo its previous contribution: `updateRange(0, prev, -val)`.
   - Add `val` for all starting positions `[0, r]`: `updateRange(0, r, val)`.
   - Find the leftmost starting index `l` where the cumulative value is 0.
   - If found: `maxL = max(maxL, r - l + 1)`.
   - Record `mp[nums[r]] = r` for future deduplication.
3. **Return** `maxL`.

## Dry Run

**Example Input:** `nums = [1, 2, 1, 2]`

- r=0, val=-1 (1 is odd): update[0,0] by -1. cumSum[0]=-1. No zero.
- r=1, val=+1 (2 is even): update[0,1] by +1. cumSum=[0,1]. Find leftmost zero at l=0. maxL=2.
- r=2, val=-1 (1 is odd, prev=0): undo [0,0] by +1. Then add [0,2] by -1. cumSum changes.
- r=3, val=+1 (2 is even, prev=1): undo [0,1] by -1. Add [0,3] by +1. Find leftmost zero.

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Each step: 2 range updates + 1 query, each O(log n) |
| **Space** | O(n) | Segment tree of size 4n |
