# Problem 0035 - Search Insert Position

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/search-insert-position/
**Language:** C++

---

## Problem Statement

Given a sorted array of distinct integers `nums` and a `target`, return the index where `target` is found. If `target` is not found, return the index where it would be inserted to keep the array sorted. The algorithm must run in O(log n) time.

## Approach: Binary Search

The key insight is that standard binary search naturally lands on the correct insertion position when the target is not found. When the loop ends without finding the target, `st` holds the position where `target` would fit — it's the first index where `nums[st] > target`, which is exactly where the target should be inserted to maintain sorted order.

## Code Walkthrough (Step by Step)

1. **Initialize** `st = 0`, `end = nums.size() - 1`.
2. **Binary search loop** while `st <= end`:
   - Compute `mid = st + (end - st) / 2` (overflow-safe calculation).
   - If `nums[mid] == target`: return `mid`.
   - If `nums[mid] < target`: `st = mid + 1` (target is in the right half).
   - Else: `end = mid - 1` (target is in the left half).
3. **Return `st`** — after the loop, `st` is the insertion point.

## Dry Run

**Example Input:** `nums = [1, 3, 5, 6]`, `target = 5`

| st | end | mid | nums[mid] | Action   |
|----|-----|-----|-----------|----------|
| 0  | 3   | 1   | 3         | 3 < 5, st=2 |
| 2  | 3   | 2   | 5         | found! return 2 |

**Output:** `2`

**Example Input:** `nums = [1, 3, 5, 6]`, `target = 2`

| st | end | mid | nums[mid] | Action        |
|----|-----|-----|-----------|---------------|
| 0  | 3   | 1   | 3         | 3 > 2, end=0  |
| 0  | 0   | 0   | 1         | 1 < 2, st=1   |
| 1  > 0, loop ends                              |

Return `st = 1` (insert between index 0 and 1)

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Search space halves at each step |
| **Space** | O(1) | Only two pointer variables |
