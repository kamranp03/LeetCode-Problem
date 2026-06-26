# Problem 189 - Rotate Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/rotate-array/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative. Rotating right by 1 means the last element moves to the front. The rotation should be done in-place (the original array is modified).

## Approach: Extra Array with Modular Index Mapping

The key insight is that when we rotate right by `k` positions, the element originally at index `i` moves to index `(i + k) % n`. By computing the new position for each element and placing it directly into a result array, we avoid the complexity of in-place rotation. Then we copy the result back to `nums`.

## Code Walkthrough (Step by Step)

1. **Get size:** `n = nums.size()`.

2. **Create result array:** `vector<int> res(n)` of the same size, initialized to zeros.

3. **Place each element at its rotated position:**
   - For each index `i` from 0 to n-1:
   - Compute `newp = (i + k) % n`. The modulo handles wrapping around past the end.
   - Set `res[newp] = nums[i]`.

4. **Copy back:** Copy all elements of `res` back into `nums`.

**Alternative in-place approach (not used here):** Triple reversal — reverse entire array, reverse first k elements, reverse remaining n-k elements.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`

| i | nums[i] | newp = (i+3)%7 | res[newp] |
|---|---------|----------------|-----------|
| 0 | 1 | 3 | res[3]=1 |
| 1 | 2 | 4 | res[4]=2 |
| 2 | 3 | 5 | res[5]=3 |
| 3 | 4 | 6 | res[6]=4 |
| 4 | 5 | 0 | res[0]=5 |
| 5 | 6 | 1 | res[1]=6 |
| 6 | 7 | 2 | res[2]=7 |

`res = [5, 6, 7, 1, 2, 3, 4]` → copy to nums.

**Output:** `nums = [5, 6, 7, 1, 2, 3, 4]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two passes over the array (placement + copy) |
| **Space** | O(n) | Extra result array of size n |
