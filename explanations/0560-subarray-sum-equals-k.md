# Problem 560 - Subarray Sum Equals K

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/subarray-sum-equals-k/
**Language:** C++

---

## Problem Statement
Given an integer array `nums` and an integer `k`, return the total number of subarrays whose sum equals exactly `k`. A subarray is a contiguous non-empty sequence of elements.

## Approach: Brute Force O(n^2) — All Subarrays

The approach used here enumerates every possible starting index `i` and extends a running `sum` to each ending index `j`. Whenever the running sum equals `k`, the count is incremented. This checks all O(n^2) subarrays explicitly.

## Code Walkthrough (Step by Step)

1. **Outer loop — start index `i`:** Ranges from 0 to n-1. For each starting position, reset `sum = 0`.

2. **Inner loop — end index `j`:** Ranges from `i` to n-1. Extends the subarray one element at a time by adding `arr[j]` to `sum`.

3. **Check:** If `sum == k`, increment `count`.

4. **Return `count`** after all pairs are checked.

Note: A more optimal O(n) solution uses prefix sums with a hash map, but this implementation uses the straightforward brute-force approach.

## Dry Run

**Example Input:** `arr = [1, 1, 1]`, `k = 2`

Outer i=0:
- j=0: sum=1 (!=2)
- j=1: sum=2 (==2) → count=1
- j=2: sum=3 (!=2)

Outer i=1:
- j=1: sum=1 (!=2)
- j=2: sum=2 (==2) → count=2

Outer i=2:
- j=2: sum=1 (!=2)

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2) | Two nested loops: n starting positions × up to n ending positions |
| **Space** | O(1) | Only a counter and a running sum variable |
