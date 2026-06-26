# Problem 3917 - Count Indices With Opposite Parity

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-indices-with-opposite-parity/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, for each index `i`, count how many indices `j > i` exist such that `nums[i]` and `nums[j]` have opposite parity (one is even, one is odd). Return the result as an array.

## Approach: Suffix Count Scan

Scan from right to left, maintaining a running count of even and odd values seen so far (to the right of the current position). For each index `i`:
- If `nums[i]` is even, the answer is the count of odd numbers seen after `i`.
- If `nums[i]` is odd, the answer is the count of even numbers seen after `i`.

Then increment the appropriate counter for the current element.

## Code Walkthrough (Step by Step)

1. **Initialize** `even_count = 0`, `odd_count = 0`.
2. **Scan from right to left (i = n-1 to 0):**
   - If `nums[i]` is even: `answer[i] = odd_count` (count of odds to the right), then `even_count++`.
   - If `nums[i]` is odd: `answer[i] = even_count` (count of evens to the right), then `odd_count++`.
3. **Return** `answer`.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 4]`

- i=3, val=4 (even): answer[3]=odd_count=0. even_count=1.
- i=2, val=3 (odd): answer[2]=even_count=1. odd_count=1.
- i=1, val=2 (even): answer[1]=odd_count=1. even_count=2.
- i=0, val=1 (odd): answer[0]=even_count=2. odd_count=2.

**Output:** `[2, 1, 1, 0]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single right-to-left scan |
| **Space** | O(1) | Only two counter variables (output array not counted) |
