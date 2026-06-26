# Problem 3640 - Trionic Array II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/trionic-array-ii/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, find the maximum sum subarray that is "trionic" — strictly increasing, then strictly decreasing, then strictly increasing again (each phase with at least one step). Return the maximum sum, or `LLONG_MIN` if no such subarray exists.

## Approach: Greedy Sweep with Landmark Tracking

Track landmarks `l` (start of current valid window), `p` (start of current decreasing phase), and `q` (start of last increasing-to-decreasing flip). Maintain a running prefix sum `psum`. When the sequence pattern breaks (equal elements or wrong direction), reset appropriately. Maximize the sum whenever all three phases (l<p<q) are present and the current element extends phase 3.

## Code Walkthrough (Step by Step)

1. **Initialize** `l=0`, `p=0`, `q=0`, `r=1`, `psum=nums[0]`, `res=LLONG_MIN`.
2. **For each `r` from 1 to n-1:**
   - Add `nums[r]` to `psum`.
   - **Equal elements** (`nums[r-1] == nums[r]`): reset `l=r`, `psum=nums[r]` (restart window).
   - **Decreasing** (`nums[r-1] > nums[r]`): if the previous step was increasing (a flip to decrease), update `p=r-1`. Trim the left of window to remove negatives.
   - **Increasing** (`nums[r-1] < nums[r]`): if previous step was decreasing (a flip back up), update `q=r-1`. If all three phases present (`l<p<q`), update `res = max(res, psum)`.
3. **Return** `res`.

## Dry Run

**Example Input:** `nums = [1, 3, 2, 4]`

- r=1: psum=4, 1<3 increasing. q still 0.
- r=2: psum=6, 3>2 decreasing. nums[r-2]=1<nums[r-1]=3 → flip to decrease → p=1.
- r=3: psum=10, 2<4 increasing. nums[r-2]=3>nums[r-1]=2 → flip to increase → q=2. l=0<p=1<q=2 → res=max(LLONG_MIN, 10)=10.

**Output:** `10`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass with O(1) operations per step |
| **Space** | O(1) | Only landmark indices and running sum |
