# Problem 3190 - Find Minimum Operations to Make All Elements Divisible by Three

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, in one operation you can increment or decrement any element by 1. Return the minimum number of operations to make all elements divisible by 3.

## Approach: Check Remainder and Apply Single Operation

For each element, compute its remainder when divided by 3:
- Remainder 0: already divisible, no operation needed.
- Remainder 1: subtract 1 (one operation) to make it divisible by 3.
- Remainder 2: add 1 (one operation) to make it divisible by 3.

Every non-zero remainder requires exactly 1 operation. The answer is simply the count of elements not divisible by 3.

## Code Walkthrough (Step by Step)

1. **Initialize** `count = 0`.

2. **Iterate** over each element `nums[i]`:
   - If `nums[i] % 3 == 0`: skip (already divisible).
   - If `nums[i] % 3 == 1`: decrement by 1 and increment `count`.
   - If `nums[i] % 3 == 2`: increment by 1 and increment `count`.

3. **Return** `count`.

Note: The code actually modifies `nums[i]` in place (though this is not necessary for the count; the modifications don't affect subsequent elements since each is processed independently).

## Dry Run

**Example Input:** `nums = [1, 2, 3, 4]`

| i | nums[i] | remainder | action | count |
|---|---------|-----------|--------|-------|
| 0 | 1 | 1 | -1 | 1 |
| 1 | 2 | 2 | +1 | 2 |
| 2 | 3 | 0 | skip | 2 |
| 3 | 4 | 1 | -1 | 3 |

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass over the array |
| **Space** | O(1) | Only a counter variable |
