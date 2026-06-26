# Problem 3381 - Maximum Subarray Sum With Length Divisible by K

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `k`, find the maximum sum of a non-empty subarray whose length is divisible by `k`. The subarray must be contiguous, and its length must be a multiple of `k`.

## Approach: Kadane's Algorithm on Interleaved Segments

The key insight is that any subarray of length divisible by `k` can be expressed as a union of consecutive blocks of size `k`. We independently apply Kadane's algorithm on `k` different "starting offset" groups. For starting offset `st` (0 to k-1), we process blocks `[st, st+k-1]`, `[st+k, st+2k-1]`, etc. Within each group, a Kadane-style update lets us decide whether to extend the previous best or start fresh.

## Code Walkthrough (Step by Step)

1. **Build prefix sum array** `prefSum` so that the sum of `nums[i..j]` = `prefSum[j] - prefSum[i-1]`.
2. **Outer loop** over `st` from `0` to `k-1`: each value of `st` represents a group of non-overlapping blocks starting at that offset.
3. **Inner loop** advances `i` by `k` each iteration, computing the block sum `nums[i..i+k-1]` using the prefix sum.
4. **Kadane update:** `cur = max(blockSum, cur + blockSum)` — either start a new group at this block or extend.
5. **Track global maximum** across all starting offsets and all positions.

## Dry Run

**Example Input:** `nums = [1, -1, 2, -2, 3, -3]`, `k = 2`

- st=0: blocks [1,-1]=0, [2,-2]=0, [3,-3]=0 → cur sequences: 0, 0, 0 → max=0
- st=1: blocks [-1,2]=1, [-2,3]=1 → cur: 1, 2 → max=2

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each element visited once across all starting offsets |
| **Space** | O(n) | Prefix sum array |
