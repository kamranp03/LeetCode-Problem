# Problem 167 - Two Sum II - Input Array Is Sorted

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
**Language:** C++

---

## Problem Statement

Given a 1-indexed array of integers `numbers` that is already sorted in non-decreasing order, find two numbers such that they add up to a specific `target` number. Return the indices of the two numbers (1-indexed) as an integer array of size 2. Each input has exactly one solution, and you may not use the same element twice.

## Approach: Two Pointers (Exploit Sorted Order)

The key insight is that the array is already sorted. Place one pointer at the start (`i=0`) and one at the end (`j=n-1`). Compute their sum:
- If the sum equals the target, we found the answer.
- If the sum is too large, move the right pointer left (to decrease the sum).
- If the sum is too small, move the left pointer right (to increase the sum).

Because the array is sorted, this greedy approach is guaranteed to find the answer without trying all pairs.

## Code Walkthrough (Step by Step)

1. **Initialize:** `i = 0` (leftmost index), `j = numbers.size() - 1` (rightmost index).

2. **Loop while `i < j`:**
   - Compute `sum = numbers[i] + numbers[j]`.
   - If `sum == target`: return `{i+1, j+1}` (convert 0-indexed to 1-indexed).
   - If `sum > target`: the right element is too large — decrement `j`.
   - If `sum < target`: the left element is too small — increment `i`.

3. **Return `{}`:** The problem guarantees a solution exists, so this line is never reached in practice.

## Dry Run

**Example Input:** `numbers = [2, 7, 11, 15]`, `target = 9`

| i | j | numbers[i] | numbers[j] | sum | action |
|---|---|------------|------------|-----|--------|
| 0 | 3 | 2 | 15 | 17 | sum > 9, j-- |
| 0 | 2 | 2 | 11 | 13 | sum > 9, j-- |
| 0 | 1 | 2 | 7 | 9 | sum == 9! return {1,2} |

**Output:** `[1, 2]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each pointer moves at most n steps in total |
| **Space** | O(1) | Only two pointer variables used |
