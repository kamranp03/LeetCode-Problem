# Problem 3542 - Minimum Operations to Convert All Elements to Zero

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, in one operation you can pick a contiguous subarray where all elements equal the maximum value of that subarray, and set all those elements to 0. Find the minimum number of operations to convert all elements to 0.

## Approach: Monotonic Stack

The key insight: each unique "level" in the histogram of values needs to be cleared independently. When we process elements left to right, we maintain a monotonic stack of values seen so far. Each time we encounter a value that is strictly greater than the stack top (a new "height"), we need one new operation. Values that are already on the stack (or less than the top) are handled by previous operations. Zeros are already at the target state.

## Code Walkthrough (Step by Step)

1. **Initialize** a stack `st` and operation counter `op = 0`.
2. **For each element `nums[i]`:**
   a. **Pop** all stack elements greater than `nums[i]` (those levels are done in this region).
   b. **If `nums[i] == 0`:** skip (already zero).
   c. **If stack is empty or top < nums[i]`:** push `nums[i]` and increment `op` (new operation needed for this value level).
3. **Return** `op`.

## Dry Run

**Example Input:** `nums = [1, 3, 2, 1, 2]`

- i=0, val=1: stack empty → push 1, op=1. Stack:[1]
- i=1, val=3: top=1 < 3 → push 3, op=2. Stack:[1,3]
- i=2, val=2: pop 3 (3>2). top=1 < 2 → push 2, op=3. Stack:[1,2]
- i=3, val=1: pop 2 (2>1). top=1 == 1 → no push, no new op. Stack:[1]
- i=4, val=2: top=1 < 2 → push 2, op=4. Stack:[1,2]

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each element pushed and popped at most once |
| **Space** | O(n) | Stack can hold at most n elements |
