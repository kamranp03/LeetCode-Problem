# Problem 1437 - Check If All 1's Are at Least Length K Places Away

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
**Language:** C++

---

## Problem Statement

Given a binary array `nums` and an integer `k`, return `true` if all 1's in the array are at least `k` places away from each other, otherwise return `false`.

## Approach: Linear Scan with Gap Counter

The key insight is to track the count of zeros between consecutive 1's. When we encounter a 1, we check if the gap since the last 1 is at least `k`. If at any point the gap is less than `k` (and it's not the first 1), the condition is violated.

## Code Walkthrough (Step by Step)

1. **Initialize `count = 0`** (zeros between 1's), `ones = 0` (number of 1's seen), `res = false`.
2. **Iterate through `nums`:**
   - If `nums[i] == 0`: increment `count`.
   - If `nums[i] == 1`: increment `ones`. Check if `count >= k` → set `res = true`, else `res = false`. Reset `count = 0`.
3. **Edge case:** If `ones <= 1` (zero or one 1 exists), set `res = true` because no pair of 1's can violate the constraint.
4. **Return `res`.**

## Dry Run

**Example Input:** `nums = [1,0,0,0,1,0,0,1]`, `k = 2`

- i=0: nums[0]=1, ones=1, count=0 (first 1, res stays false)
- i=1,2,3: zeros, count=3
- i=4: nums[4]=1, ones=2, count=3 >= 2 → res=true, count=0
- i=5,6: zeros, count=2
- i=7: nums[7]=1, ones=3, count=2 >= 2 → res=true, count=0
- ones=3 > 1, return **true**

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array |
| **Space** | O(1) | Only a few counters used |
