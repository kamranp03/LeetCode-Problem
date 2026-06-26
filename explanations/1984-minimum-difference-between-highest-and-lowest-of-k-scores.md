# Problem 1984 - Minimum Difference Between Highest and Lowest of K Scores

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
**Language:** C++

---

## Problem Statement
Given a 0-indexed integer array `nums` representing scores and an integer `k`, pick exactly `k` scores from the array. Return the minimum possible difference between the highest and lowest scores among the chosen `k` scores.

## Approach: Sort + Sliding Window of Size K

The key insight is that to minimize the difference between max and min of k chosen elements, the optimal k elements must be consecutive in sorted order (since sorting brings values as close together as possible). So we sort the array and slide a window of size `k`, checking the difference between the last and first element of each window.

## Code Walkthrough (Step by Step)

1. **Special case**: If `k == 1`, return 0 — picking one element means min and max are the same.
2. **Sort `nums`** in ascending order.
3. **Initialize `ans = INT_MAX`**.
4. **Slide window**: For each starting index `i` from 0 to `n-k`:
   - The window spans `nums[i]` to `nums[i + k - 1]`.
   - Compute `nums[i + k - 1] - nums[i]` and update `ans` with the minimum.
5. **Return `ans`**.

## Dry Run

**Example Input:** `nums = [9, 4, 1, 7], k = 2`

After sort: `[1, 4, 7, 9]`

| i | Window        | Difference | ans |
|---|---------------|------------|-----|
| 0 | [1, 4]        | 3          | 3   |
| 1 | [4, 7]        | 3          | 3   |
| 2 | [7, 9]        | 2          | 2   |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting dominates; the window scan is O(n) |
| **Space** | O(1) | Only a few scalar variables; sort is in-place |
