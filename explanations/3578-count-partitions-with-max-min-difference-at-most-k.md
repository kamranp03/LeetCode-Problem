# Problem 3578 - Count Partitions With Max-Min Difference at Most K

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `k`, count the number of ways to partition `nums` into contiguous subarrays such that in every subarray the difference between the maximum and minimum elements is at most `k`. Return the count modulo `10^9 + 7`.

## Approach: DP with Sliding Window (Two Pointers + Prefix Sum)

Let `dp[i]` = number of valid partitions of `nums[0..i-1]`. For each ending position `i`, the valid starting positions `j` are those where `max(nums[j..i-1]) - min(nums[j..i-1]) <= k`. We maintain a sliding window [j, i] using a multiset to track the max-min difference, and use a prefix sum array to query the sum of valid dp values in O(1).

## Code Walkthrough (Step by Step)

1. **Initialize** `dp[0]=1` (empty partition), `pref[0]=1`, multiset `s` empty, left pointer `j=0`.
2. **For each i from 0 to n-1:**
   a. Insert `nums[i]` into multiset.
   b. **Shrink window** while `max - min > k`: remove `nums[j]` from multiset, advance `j`.
   c. **Compute dp[i+1]:** sum of dp values from index `j` to `i` = `pref[i] - pref[j-1]` (using prefix sums).
   d. Update `pref[i+1] = pref[i] + dp[i+1]`.
3. **Return** `dp[n]`.

## Dry Run

**Example Input:** `nums = [2, 5, 1, 4]`, `k = 3`

- i=0 (val=2): s={2}, j=0. max-min=0<=3. dp[1]=pref[0]=1. pref=[1,1,...].
- i=1 (val=5): s={2,5}, j=0. max-min=3<=3. dp[2]=pref[1]-pref[-1]=1. pref[2]=2.
- i=2 (val=1): s={1,2,5}, j=0. max-min=4>3→erase 2, j=1. s={1,5}, 4>3→erase 5, j=2. s={1}. dp[3]=pref[2]-pref[1]=2-1=1. pref[3]=3.
- i=3 (val=4): s={1,4}, j=2. max-min=3<=3. dp[4]=pref[3]-pref[1]=3-1=2. pref[4]=5.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Multiset insert/erase is O(log n) per step |
| **Space** | O(n) | dp, pref arrays and multiset |
