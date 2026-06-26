# Problem 2154 - Keep Multiplying Found Values by Two

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/keep-multiplying-found-values-by-two/
**Language:** C++

---

## Problem Statement
You are given an integer array `nums` and an integer `original`. If `original` is found in `nums`, multiply it by 2 and repeat the search from the beginning of the array. Return the final value of `original` after no more matches are found.

## Approach: Linear Scan with Reset

The key insight is that every time we find a match, we double the target and must restart the search from index 0 (since earlier elements might now match the doubled value). The while loop with index reset implements this faithfully.

## Code Walkthrough (Step by Step)

1. **Initialize `i = 0`**.
2. **While `i < n`**:
   - If `nums[i] == original`: reset `i = 0`, double `original = original * 2`.
   - Else: advance `i++`.
3. **Return `original`** after the loop (no more matches found).

**Note:** This approach restarts the scan from index 0 each time a match is found. A more efficient approach would use a hash set, but this brute force is acceptable for small inputs (n <= 1000, values <= 1000).

## Dry Run

**Example Input:** `nums = [5, 3, 6, 1, 12], original = 3`

| i | nums[i] | original | action     |
|---|---------|----------|------------|
| 0 | 5       | 3        | no match, i++ |
| 1 | 3       | 3        | match! i=0, original=6 |
| 0 | 5       | 6        | no match, i++ |
| 1 | 3       | 6        | no match, i++ |
| 2 | 6       | 6        | match! i=0, original=12 |
| 0 | 5       | 12       | no match, i++ |
| 1 | 3       | 12       | no match, i++ |
| 2 | 6       | 12       | no match, i++ |
| 3 | 1       | 12       | no match, i++ |
| 4 | 12      | 12       | match! i=0, original=24 |
| 0-4 | - | 24 | no matches |

**Output:** `24`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n²) worst case | Each match causes a full restart; at most n matches possible |
| **Space** | O(1) | Only scalar variables; no extra data structures |
