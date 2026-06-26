# Problem 3392 - Count Subarrays of Length Three With a Condition

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, count the number of subarrays of exactly length 3 where the middle element is equal to twice the sum of the two outer elements. Specifically, count triples `(i, i+1, i+2)` such that `nums[i+1] == 2 * (nums[i] + nums[i+2])`.

## Approach: Linear Scan with Direct Condition Check

Since the subarray length is fixed at 3, we simply slide a window of size 3 across the array and check the condition at each position. No complex data structures are needed.

## Code Walkthrough (Step by Step)

1. **Initialize counter** `cnt = 0`.
2. **Loop from index 1 to n-2** (these are all valid middle positions of a 3-element window).
3. **Check condition:** if `nums[i] == 2 * (nums[i-1] + nums[i+1])`, increment `cnt`.
4. **Return** `cnt`.

## Dry Run

**Example Input:** `nums = [1, 2, 1, 4, 3]`

- i=1: nums[1]=2, 2*(nums[0]+nums[2])=2*(1+1)=4. 2 != 4. No.
- i=2: nums[2]=1, 2*(nums[1]+nums[3])=2*(2+4)=12. 1 != 12. No.
- i=3: nums[3]=4, 2*(nums[2]+nums[4])=2*(1+3)=8. 4 != 8. No.

**Example Input:** `nums = [1, 2, 1, 2, 1]`

- i=1: 2 == 2*(1+1)=4? No.
- i=2: 1 == 2*(2+2)=8? No.
- i=3: 2 == 2*(1+1)=4? No.

**Example Input:** `nums = [3, 1, 2]`

- i=1: nums[1]=1, 2*(3+2)=10. No.

**Example Input:** `nums = [1, 4, 1]`

- i=1: nums[1]=4, 2*(1+1)=4. Yes! cnt=1.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through array |
| **Space** | O(1) | Only a counter variable used |
