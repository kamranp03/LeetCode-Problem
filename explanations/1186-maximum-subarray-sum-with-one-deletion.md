# Problem 1186 - Maximum Subarray Sum with One Deletion

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
**Language:** C++

---

## Problem Statement
Given an integer array, find the maximum sum of a non-empty subarray with at most one element deletion. You may choose to delete any one element (or none) from the subarray.

## Approach: DP with Two States (Kadane's Variant)

Maintain two DP values at each position:
- `noDel`: maximum subarray sum ending at the current index with no deletion used.
- `oneDel`: maximum subarray sum ending at the current index with exactly one deletion used.

For `noDel`, apply standard Kadane's: max of starting fresh or extending. For `oneDel`, either delete the current element (take `prevNo` — the best sum up to the previous element with no deletion) or extend a subarray that already had one deletion (`oneDel + a[i]`).

## Code Walkthrough (Step by Step)

1. **Initialize:** `noDel = a[0]`, `oneDel = INT_MIN`, `res = a[0]`.

2. **Loop from i=1:**
   - Save `prevNo = noDel` (before updating).
   - `noDel = max(a[i], noDel + a[i])` — Kadane's step for no-deletion subarray.
   - For `oneDel`:
     - If `oneDel != INT_MIN`: `oneDel = max(prevNo, oneDel + a[i])` — either delete `a[i]` (use prevNo) or extend with deletion already used.
     - Else: `oneDel = prevNo` — first deletion opportunity (delete current element).
   - `res = max(res, max(noDel, oneDel))`.

3. **Return `res`.**

## Dry Run

**Example Input:** `a = [1, -2, 0, 3]`

| i | a[i] | prevNo | noDel         | oneDel       | res |
|---|------|--------|---------------|--------------|-----|
| 0 |  1   |   -    | 1             | INT_MIN      | 1   |
| 1 | -2   |  1     | max(-2,1-2)=-1| max(1,INT_MIN+(-2))=1 | 1 |
| 2 |  0   | -1     | max(0,-1+0)=0 | max(-1,1+0)=1 | 1  |
| 3 |  3   |  0     | max(3,0+3)=3  | max(0,1+3)=4 | 4  |

**Output:** `4` (delete -2, subarray [1,0,3] = 4)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single pass through the array |
| **Space** | O(1) | Only a constant number of DP variables |
