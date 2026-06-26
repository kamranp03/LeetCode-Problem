# Problem 0053 - Maximum Subarray

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-subarray/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, find the contiguous subarray (containing at least one element) that has the largest sum, and return that sum. The subarray must be contiguous.

## Approach: Kadane's Algorithm

The key insight is that at each position, we make a greedy choice: should we extend the current subarray or start a new one from this position? The current subarray is worth extending only if its running sum (`best`) is positive. If `best + a[i] > a[i]`, extend; otherwise start fresh. We track the global maximum across all positions in `ans`.

## Code Walkthrough (Step by Step)

1. **Initialize** `best = a[0]` (best subarray sum ending at current position) and `ans = a[0]` (global maximum).
2. **Iterate `i` from 1 to `a.size()-1`:**
   - **`ch1 = best + a[i]`** — extend the previous subarray.
   - **`ch2 = a[i]`** — start a fresh subarray from this element.
   - **`best = max(ch1, ch2)`** — pick the better option.
   - **`ans = max(ans, best)`** — update global maximum.
3. **Return `ans`.**

Note: `best = max(best + a[i], a[i])` is equivalent to: if `best < 0`, starting fresh is better; otherwise, extending is at least as good.

## Dry Run

**Example Input:** `a = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| i | a[i] | ch1 (best+a[i]) | ch2 (a[i]) | best | ans |
|---|------|-----------------|------------|------|-----|
| — | —    | —               | —          | -2   | -2  |
| 1 | 1    | -2+1=-1         | 1          | 1    | 1   |
| 2 | -3   | 1+(-3)=-2       | -3         | -2   | 1   |
| 3 | 4    | -2+4=2          | 4          | 4    | 4   |
| 4 | -1   | 4+(-1)=3        | -1         | 3    | 4   |
| 5 | 2    | 3+2=5           | 2          | 5    | 5   |
| 6 | 1    | 5+1=6           | 1          | 6    | 6   |
| 7 | -5   | 6+(-5)=1        | -5         | 1    | 6   |
| 8 | 4    | 1+4=5           | 4          | 5    | 6   |

**Output:** `6` (subarray `[4, -1, 2, 1]`)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only two tracking variables (`best` and `ans`) |
