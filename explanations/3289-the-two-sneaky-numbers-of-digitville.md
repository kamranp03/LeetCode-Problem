# Problem 3289 - The Two Sneaky Numbers of Digitville

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
**Language:** C++

---

## Problem Statement

In Digitville, every integer from `0` to `n-1` should appear exactly once in the array `nums` (which has length `n+2`). Exactly two numbers appear twice and the rest appear once. Find and return these two "sneaky" (duplicate) numbers.

## Approach: Frequency Count Array

Since `nums` has exactly `n+2` elements and values range from `0` to `n-1`, we use a frequency array of size `n`. We count occurrences of each value, and whenever a value's count reaches 2, it is a sneaky (duplicate) number.

## Code Walkthrough (Step by Step)

1. **Determine `n`:** `n = nums.size() - 2` (since the array has exactly 2 extra elements).

2. **Initialize** `freq` as a vector of zeros of size `n`.

3. **Scan `nums`:** For each `num`, increment `freq[num]`. If `freq[num] == 2`, push `num` into result.

4. **Return** result (which will have exactly 2 elements).

## Dry Run

**Example Input:** `nums = [0, 1, 2, 0, 1, 3]`

- n = 6 - 2 = 4
- freq starts as [0, 0, 0, 0]

| num | freq after | action |
|-----|------------|--------|
| 0 | [1,0,0,0] | — |
| 1 | [1,1,0,0] | — |
| 2 | [1,1,1,0] | — |
| 0 | [2,1,1,0] | freq[0]==2 → res=[0] |
| 1 | [2,2,1,0] | freq[1]==2 → res=[0,1] |
| 3 | [2,2,1,1] | — |

**Output:** `[0, 1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass over the array |
| **Space** | O(n) | Frequency array of size n |
