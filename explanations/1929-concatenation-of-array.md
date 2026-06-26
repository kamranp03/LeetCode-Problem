# Problem 1929 - Concatenation of Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/concatenation-of-array/
**Language:** C++

---

## Problem Statement
Given an integer array `nums` of length `n`, return the array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n`. In other words, `ans` is the concatenation of `nums` with itself.

## Approach: Simple Two-Pass Append

The key insight is straightforward: create a new result vector and push all elements of `nums` twice — first pass fills indices `0` to `n-1`, second pass fills indices `n` to `2n-1`. No clever tricks required.

## Code Walkthrough (Step by Step)

1. **Get `n`**: Store the size of the input array.
2. **Create empty `ans` vector**: Will hold `2n` elements.
3. **First loop** (i from 0 to n-1): Push `nums[i]` into `ans` — fills the first half.
4. **Second loop** (i from 0 to n-1): Push `nums[i]` into `ans` again — fills the second half.
5. **Return `ans`**.

## Dry Run

**Example Input:** `nums = [1, 2, 1]`, n = 3

First loop:
- i=0: ans = [1]
- i=1: ans = [1, 2]
- i=2: ans = [1, 2, 1]

Second loop:
- i=0: ans = [1, 2, 1, 1]
- i=1: ans = [1, 2, 1, 1, 2]
- i=2: ans = [1, 2, 1, 1, 2, 1]

**Output:** `[1, 2, 1, 1, 2, 1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two linear passes, each O(n), over the input array |
| **Space** | O(n) | Output array of size 2n (not counting mandatory output space) |
