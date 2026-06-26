# Problem 2654 - Minimum Number of Operations to Make All Array Elements Equal to 1

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
**Language:** C++

---

## Problem Statement

Given an array of positive integers `nums`, in one operation you can choose two adjacent elements and replace them both with their GCD. Return the minimum number of operations needed to make all elements equal to `1`. If it is impossible, return `-1`.

## Approach: Count Existing Ones + Minimum Subarray GCD = 1

Two cases are handled:

**Case 1:** If there is already at least one `1` in the array, we need exactly `n - count` operations (one operation per non-1 element, since a `1` adjacent to any value produces GCD = 1).

**Case 2:** If there are no `1`s, we need to first create a `1` using the fewest adjacent replacements. We find the shortest subarray `[i..j]` whose GCD equals 1. That subarray takes `j - i` operations to collapse to 1, and then we need `n - 1` more operations to spread that `1` to all other elements. Total: `(j - i) + (n - 1)`.

If no such subarray exists (GCD of entire array > 1), return `-1`.

## Code Walkthrough (Step by Step)

1. **Count existing 1s:** Scan `nums` and count elements equal to `1`. If `count > 0`, return `n - count` directly.

2. **Find shortest subarray with GCD = 1:** Use two nested loops. For each starting index `i`, compute the running GCD with each `j > i`. When GCD reaches `1`, record `j - i` as a candidate for `step` and break the inner loop.

3. **Handle impossible case:** If `step` remains `INT_MAX`, no subarray has GCD = 1 — return `-1`.

4. **Return** `step + (n - 1)`: `step` operations to create the first `1`, then `n - 1` operations to propagate it.

## Dry Run

**Example Input:** `nums = [2, 6, 3, 4]`

- No existing 1s.
- i=0: GCD(2,6)=2, GCD(2,3)=1 → step = min(INF, 2) = 2
- i=1: GCD(6,3)=3, GCD(3,4)=1 → step = min(2, 2) = 2
- i=2: GCD(3,4)=1 → step = min(2, 1) = 1

Best: subarray `[3,4]` has GCD = 1, needs 1 operation. Then `n-1 = 3` to spread.

**Output:** `1 + 3 = 4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2 * log(max)) | Nested loops with GCD computation at each pair |
| **Space** | O(1) | Only scalar variables used |
