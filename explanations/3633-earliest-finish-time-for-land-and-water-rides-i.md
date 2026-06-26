# Problem 3633 - Earliest Finish Time for Land and Water Rides I

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/
**Language:** C++

---

## Problem Statement

You must complete exactly one land ride and one water ride. Each ride has a start time and duration. You can do the rides in any order (land first or water first), but you must finish one before starting the other. Find the earliest possible time to finish both rides.

## Approach: Brute Force Over All Ride Combinations

Since we need to pick exactly one land ride and one water ride, try every pair (one of each). For each pair, try both orderings (land first or water first), and compute the finishing time for each.

## Code Walkthrough (Step by Step)

1. **Initialize** `ans = INT_MAX`.
2. **For each land ride `i` and water ride `j`:**
   a. **Land first:** finish = `max(landStart[i] + landDur[i], waterStart[j]) + waterDur[j]`.
      - You wait until the land ride finishes OR the water ride opens, whichever is later, then do the water ride.
   b. **Water first:** finish = `max(waterStart[j] + waterDur[j], landStart[i]) + landDur[i]`.
   c. `ans = min(ans, min(landFirst, waterFirst))`.
3. **Return** `ans`.

## Dry Run

**Example Input:** `landStartTime=[1]`, `landDuration=[3]`, `waterStartTime=[2]`, `waterDuration=[2]`

- Only one pair: land ride at t=1, duration 3 → ends at t=4. Water ride at t=2, duration 2.
- Land first: max(4, 2) + 2 = 4 + 2 = 6.
- Water first: max(4, 1) + 3 = 4 + 3 = 7.
- ans = min(6, 7) = 6.

**Output:** `6`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(L * W) | L land rides, W water rides — all pairs tried |
| **Space** | O(1) | Only the minimum answer tracked |
