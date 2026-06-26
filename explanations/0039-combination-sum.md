# Problem 0039 - Combination Sum

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/combination-sum/
**Language:** C++

---

## Problem Statement

Given an array of distinct integers `candidates` and a `target`, return all unique combinations where the chosen numbers sum to `target`. Each number may be used an unlimited number of times. The same combination (just in different order) should not appear twice.

## Approach: Backtracking (Take / Not-Take)

The key insight is to use a "take or not-take" decision at each index. When we "take" the element at `idx`, we stay at the same index (allowing reuse) and reduce the target. When we "not-take", we advance to `idx+1`. This prevents counting the same combination in different orders (e.g., [2,3] vs [3,2] both starting from the same index). We stop a branch early if the current candidate exceeds the remaining target.

## Code Walkthrough (Step by Step)

1. **`solve(candidates, target, idx, diary, res)`:**
   - **Base case:** if `idx == candidates.size()`: if `target == 0`, push `diary` to `res`; return.
   - **Take:** if `candidates[idx] <= target`:
     - Add `candidates[idx]` to `diary`.
     - Recurse with same `idx` and reduced target: `target - candidates[idx]`.
     - Pop from `diary` (backtrack).
   - **Not-take:** recurse with `idx+1` and same `target`.
2. **`combinationSum`** initializes empty `diary` and calls `solve` from `idx = 0`.

## Dry Run

**Example Input:** `candidates = [2, 3, 6, 7]`, `target = 7`

```
solve(idx=0, target=7): take 2 → solve(idx=0, target=5)
  take 2 → solve(idx=0, target=3)
    take 2 → solve(idx=0, target=1)
      2 > 1, skip take; not-take → solve(idx=1, target=1)
        3 > 1, skip take; not-take → solve(idx=2, target=1) → ... base: target≠0
    not-take → solve(idx=1, target=3)
      take 3 → solve(idx=1, target=0)
        3 > 0, skip; not-take → solve(idx=2, target=0) → base: push [2,2,3] ✓
  not-take → solve(idx=1, target=5)
    take 3 → solve(idx=1, target=2) → ... eventually no match
    not-take → solve(idx=2, target=5) → ...
not-take → solve(idx=1, target=7)
  take 3 → ... → [3,3] → no, need 7
  not-take → solve(idx=2, target=7)
    take 6 → ... base: push [7] (via not-take to idx=3, take 7) 
    → also found [2,2,3] already
```

**Output:** `[[2,2,3],[7]]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(2^(target/min)) | In worst case, exponential branches due to unlimited reuse |
| **Space** | O(target/min) | Maximum recursion depth (taking smallest element each time) |
