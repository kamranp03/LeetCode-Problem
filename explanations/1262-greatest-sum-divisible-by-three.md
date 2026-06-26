# Problem 1262 - Greatest Sum Divisible by Three

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/greatest-sum-divisible-by-three/
**Language:** C++

---

## Problem Statement
Given an integer array, find the maximum sum of a subset of numbers such that the sum is divisible by 3. Return that maximum sum.

## Approach: Dynamic Programming with Remainder States

For each position, track the maximum sum achievable for each possible remainder (0, 1, 2) when divided by 3. The DP table `t[i][rem]` stores the maximum sum using elements from index `i` onwards with target remainder `rem`. At each element, we either take it (changing the target remainder) or skip it. The answer is `t[0][0]` — maximum sum from the start with remainder 0.

## Code Walkthrough (Step by Step)

1. **Initialize base case:** `t[n][0] = 0` (empty subset, sum=0, divisible by 3). `t[n][1] = t[n][2] = INT_MIN` (impossible).

2. **Fill from right to left** (i from n-1 to 0), for each `rem` in {0, 1, 2}:
   - `newRem = (rem + nums[i]) % 3` — if we take `nums[i]`, what remainder do we need from the suffix?
   - `take = t[i+1][newRem] + nums[i]` (if `t[i+1][newRem] != INT_MIN`, else INT_MIN).
   - `skip = t[i+1][rem]` — don't take this element.
   - `t[i][rem] = max(take, skip)`.

3. **Return `t[0][0]`** — maximum sum with total remainder 0.

## Dry Run

**Example Input:** `nums = [3, 6, 5, 1, 8]`

- n=5. t[5] = {0, INT_MIN, INT_MIN}
- i=4, nums[4]=8:
  - rem=0: newRem=(0+8)%3=2, take=t[5][2]+8=INT_MIN, skip=0 → t[4][0]=0
  - rem=1: newRem=(1+8)%3=0, take=t[5][0]+8=8, skip=INT_MIN → t[4][1]=8
  - rem=2: newRem=(2+8)%3=1, take=INT_MIN, skip=INT_MIN → t[4][2]=INT_MIN
- Continue filling... eventually t[0][0] gives the best sum divisible by 3.

Best subset: {3,6,8,1} = 18, or {3,6,5,1} = 15, or {6,5,1,8} = 20... 18 is divisible by 3. 18%3=0 ✓

**Output:** `18`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | O(N * 3) = O(N); three remainder states per element |
| **Space** | O(N) | DP table of size (N+1) * 3; can be optimized to O(1) |
