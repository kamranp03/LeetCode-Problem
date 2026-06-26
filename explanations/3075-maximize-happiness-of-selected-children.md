# Problem 3075 - Maximize Happiness of Selected Children

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximize-happiness-of-selected-children/
**Language:** C++

---

## Problem Statement

Given an array `happiness` and an integer `k`, select `k` children to maximize the total happiness. Each time you select a child (in order of selection), all unselected children's happiness decreases by 1. A child's effective happiness when selected as the i-th pick (0-indexed) is `max(0, happiness[i] - i)`. Return the maximum total happiness sum.

## Approach: Greedy - Sort Descending, Apply Position Penalty

Since happiness decreases by 1 for each prior selection, the i-th child selected (0-indexed) has their happiness reduced by `i`. To maximize the sum, we should pick children with the highest base happiness first. Sort in descending order and apply the penalty `happiness[i] - i` for each position. Stop early if the adjusted value drops to 0 or below.

## Code Walkthrough (Step by Step)

1. **Sort `happiness` in descending order** so the happiest children are considered first.

2. **Iterate** for `i` from `0` to `k-1`:
   - Compute `current = happiness[i] - i` (base happiness minus how many were already selected).
   - If `current > 0`, add to `ans`.
   - If `current <= 0`, break early — further selections add nothing (all remaining are even lower).

3. **Return** `ans`.

## Dry Run

**Example Input:** `happiness = [1, 2, 3]`, `k = 2`

- Sorted descending: [3, 2, 1]
- i=0: current = 3 - 0 = 3, ans = 3
- i=1: current = 2 - 1 = 1, ans = 4

**Output:** `4`

**Example Input:** `happiness = [1, 2, 3]`, `k = 3`

- i=0: 3-0=3, ans=3
- i=1: 2-1=1, ans=4
- i=2: 1-2=-1 → break

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting the happiness array |
| **Space** | O(1) | Only scalar variables |
