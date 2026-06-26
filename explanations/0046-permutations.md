# Problem 0046 - Permutations

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/permutations/
**Language:** C++

---

## Problem Statement

Given an array `nums` of distinct integers, return all possible permutations in any order. A permutation is an arrangement of all elements where every element appears exactly once.

## Approach: Backtracking with Visited Array

The key insight is to build each permutation position by position. At each recursive call, we try every element of `nums` that hasn't been used yet. We mark elements as "used" before recursing and unmark them after (backtrack) so they become available for other branches. A boolean `used` array tracks which indices have been included in the current permutation being built (`diary`).

## Code Walkthrough (Step by Step)

1. **`perm(nums, n, diary, res, used)`:**
   - **Base case:** if `diary.size() == n`, all elements have been placed — push `diary` to `res` and return.
   - **Loop `i` from 0 to n-1:**
     - If `used[i]` is `true`: skip (already in current permutation).
     - Otherwise:
       - Add `nums[i]` to `diary`.
       - Mark `used[i] = true`.
       - Recurse.
       - Remove `nums[i]` from `diary` (pop_back).
       - Mark `used[i] = false` (unmark).
2. **`permute`** creates a `used` vector of `false` values and calls `perm`.

## Dry Run

**Example Input:** `nums = [1, 2, 3]`

```
perm(diary=[]): try i=0 (1), i=1 (2), i=2 (3)
  take 1 → diary=[1]: try i=1 (2), i=2 (3)
    take 2 → diary=[1,2]: try i=2 (3)
      take 3 → diary=[1,2,3] → push [1,2,3] ✓
    take 3 → diary=[1,3]: try i=1 (2)
      take 2 → diary=[1,3,2] → push [1,3,2] ✓
  take 2 → diary=[2]: ...
    → [2,1,3], [2,3,1]
  take 3 → diary=[3]: ...
    → [3,1,2], [3,2,1]
```

**Output:** `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n × n!) | n! permutations, each of length n to construct and copy |
| **Space** | O(n) | Recursion depth n; `diary` and `used` arrays of size n |
