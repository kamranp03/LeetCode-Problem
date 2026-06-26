# Problem 0027 - Remove Element

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/remove-element/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. Return the number of elements `k` that are not equal to `val`. The first `k` elements of `nums` should contain the valid elements; the order among them does not matter.

## Approach: Two Pointers (Write Pointer)

The key insight is to use two pointers: `i` (slow/write pointer) tracks where the next valid (non-`val`) element should be written, and `j` (fast/read pointer) scans through the array. Whenever `j` finds an element that is not `val`, it writes that element to position `i` and advances `i`. Elements equal to `val` are simply skipped.

## Code Walkthrough (Step by Step)

1. **Initialize write pointer `i = 0`.**
2. **Iterate `j` from 0 to `nums.size() - 1`:**
   - If `nums[j] != val`: write `nums[j]` to `nums[i]` and increment `i`.
   - If `nums[j] == val`: skip it (don't advance `i`).
3. **Return `i`** — the number of valid elements. All values at indices `0` to `i-1` are the kept elements.

## Dry Run

**Example Input:** `nums = [3, 2, 2, 3]`, `val = 3`

| j | nums[j] | != val? | Action           | i | Array state  |
|---|---------|---------|------------------|---|--------------|
| 0 | 3       | No      | skip             | 0 | [3,2,2,3]    |
| 1 | 2       | Yes     | write, i++       | 1 | [2,2,2,3]    |
| 2 | 2       | Yes     | write, i++       | 2 | [2,2,2,3]    |
| 3 | 3       | No      | skip             | 2 | [2,2,2,3]    |

Return `2`. First 2 elements: `[2, 2]`

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | In-place modification, no extra space used |
