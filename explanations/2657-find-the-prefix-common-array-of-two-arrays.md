# Problem 2657 - Find the Prefix Common Array of Two Arrays

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
**Language:** C++

---

## Problem Statement

Given two 0-indexed permutations `A` and `B` of `[1, n]`, compute the prefix common array `C` where `C[i]` is the count of values that appear in both `A[0..i]` and `B[0..i]` (i.e., values seen so far in both arrays).

## Approach: Frequency Counting with Shared Array

We maintain a single frequency array `freq` of size `n+1`. When any value appears in both `A` and `B` up to index `i`, its frequency becomes exactly `2`. We track a running `common` counter: each time a value's frequency hits `2`, it means that value has now been seen in both arrays, so we increment `common`.

This works because `A` and `B` are permutations — each value appears exactly once in each array, so frequency `2` is the exact threshold for "seen in both."

## Code Walkthrough (Step by Step)

1. **Initialize** `freq` as a vector of zeros of size `n+1`, and `common = 0`.

2. **Iterate** from `i = 0` to `n-1`:
   - Increment `freq[A[i]]`. If it becomes `2`, this value was already in `B[0..i]`, so increment `common`.
   - Increment `freq[B[i]]`. If it becomes `2`, this value was already in `A[0..i]`, so increment `common`.
   - Push current `common` into result.

3. **Return** the result array.

## Dry Run

**Example Input:** `A = [1, 3, 2, 4]`, `B = [3, 1, 2, 4]`

| i | A[i] | B[i] | freq after | common | C[i] |
|---|------|------|------------|--------|------|
| 0 | 1 | 3 | freq[1]=1, freq[3]=1 | 0 | 0 |
| 1 | 3 | 1 | freq[3]=2→common++, freq[1]=2→common++ | 2 | 2 |
| 2 | 2 | 2 | freq[2]=1, freq[2]=2→common++ | 3 | 3 |
| 3 | 4 | 4 | freq[4]=1, freq[4]=2→common++ | 4 | 4 |

**Output:** `[0, 2, 3, 4]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through both arrays |
| **Space** | O(n) | Frequency array of size n+1 |
