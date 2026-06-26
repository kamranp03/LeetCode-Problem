# Problem 3347 - Maximum Frequency of an Element After Performing Operations II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and integers `k` and `numOperations`, in each operation you can change one element by at most `k`. You can perform at most `numOperations` operations total. Return the maximum frequency of any element you can achieve. Values can be very large (not bounded by n), requiring a coordinate-compressed approach.

## Approach: Difference Array (Sweep Line) on Sorted Coordinates

Since values can be large, we can't use a simple frequency array indexed by value. Instead we use a **difference array on a sorted coordinate map**. Each element `nums[i]` contributes to the range `[nums[i]-k, nums[i]+k]` for any target within that range. We use a difference array `diff` (via `std::map`) to record +1 at `nums[i]-k` and -1 at `nums[i]+k+1` for each element.

When we sweep through coordinates, the cumulative sum at any target `t` tells us how many elements can be converted to `t` via one operation. Combined with the original frequency of `t`, we compute the maximum achievable frequency.

## Code Walkthrough (Step by Step)

1. **Build frequency map** `freq` and difference map `diff`:
   - For each `nums[i]`: `freq[nums[i]]++`, `diff[max(nums[i]-k, 0)]++`, `diff[min(nums[i]+k, maxVal)+1]--`.
   - Also ensure `diff[nums[i]] += 0` to register the coordinate.

2. **Sweep through `diff` in sorted order:**
   - Maintain `cumSum` (running prefix sum of diff values = count of elements that can reach this target).
   - For each coordinate `target`: update `cumSum += diff[target]`.
   - `tarF = freq[target]` (original count at this value).
   - `needConversion = cumSum - tarF` (elements needing an operation to reach target).
   - `maxPos = tarF + min(needConversion, numOperations)`.
   - Update `result`.

3. **Return** `result`.

## Dry Run

**Example Input:** `nums = [1, 4, 8, 13]`, `k = 5`, `numOperations = 2`

- For target=6: elements 1 (range [-4,6]), 4 (range [-1,9]), 8 (range [3,13]) → cumSum=3, freq[6]=0, needConv=3, maxPos=0+min(3,2)=2
- Other targets similarly computed.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Building and sweeping sorted map |
| **Space** | O(n) | Map stores at most 2n+1 coordinate entries |
