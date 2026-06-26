# Problem 581 - Shortest Unsorted Continuous Subarray

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
**Language:** C++

---

## Problem Statement
Given an integer array `nums`, find the shortest subarray that, if sorted, makes the entire array sorted. Return the length of that subarray. If the array is already sorted, return 0.

## Approach: Two-Pass Boundary Narrowing + Expansion

The key insight is to find the initial boundary of the "unsorted" region, then expand it outward to include any elements that are out of place relative to the subarray's min and max. We find the first left violation and first right violation, then expand these boundaries to account for elements outside the initial window that would still be out of order.

## Code Walkthrough (Step by Step)

1. **Find left boundary `l`:** Scan from left; advance `l` as long as `nums[l] <= nums[l+1]`. If `l == n-1`, the array is sorted → return 0.

2. **Find right boundary `r`:** Scan from right; advance `r` left as long as `nums[r] >= nums[r-1]`.

3. **Find subMin and subMax** in the range `[l, r]` — these are the extreme values of the out-of-order region.

4. **Expand left:** Move `l` left while `nums[l-1] > subMin`. Elements to the left of `l` that are larger than `subMin` must be included in the unsorted region.

5. **Expand right:** Move `r` right while `nums[r+1] < subMax`. Elements to the right that are smaller than `subMax` must also be included.

6. **Return `r - l + 1`** — the length of the final subarray.

## Dry Run

**Example Input:** `nums = [2, 6, 4, 8, 10, 9, 15]`

Step 1 — Find l: nums[0]=2<=6, nums[1]=6>4 → l=1
Step 2 — Find r: nums[6]=15>=9, nums[5]=9>8? No: 9>10? No: nums[5]=9<nums[4]=10 → r=5. Wait: scan from right: nums[6]>=nums[5]? 15>=9 yes → r stays. nums[5]=9>=nums[4]=10? No → r=5.

Step 3 — subMin and subMax in [1,5]: [6,4,8,10,9] → subMin=4, subMax=10

Step 4 — Expand left: l=1, nums[0]=2 > subMin=4? No → l stays at 1.

Step 5 — Expand right: r=5, nums[6]=15 < subMax=10? No → r stays at 5.

Length = 5 - 1 + 1 = 5

**Output:** `5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each of the five passes (find l, find r, find min/max, expand l, expand r) is linear |
| **Space** | O(1) | Only a few index and value variables used |
