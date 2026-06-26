# Problem 0011 - Container With Most Water

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/container-with-most-water/
**Language:** C++

---

## Problem Statement

Given an integer array `height` of length `n`, where `height[i]` represents the height of a vertical line at position `i`, find two lines that together with the x-axis form a container that holds the most water. Return the maximum amount of water a container can store.

## Approach: Two Pointers (Greedy)

The key insight is: water volume = width × min(height[left], height[right]). Starting with the widest possible container (pointers at both ends), we can only potentially increase volume by moving the pointer with the shorter height inward — moving the taller one would reduce width while keeping the height bounded by the same shorter line, which can only decrease or maintain the volume. This greedy strategy guarantees we find the maximum.

## Code Walkthrough (Step by Step)

1. **Initialize** `maxWater = 0`, `lp = 0` (left pointer), `rp = height.size() - 1` (right pointer).
2. **Loop while `lp < rp`:**
   - **Compute width:** `w = rp - lp`.
   - **Compute effective height:** `ht = min(height[lp], height[rp])` (water can only fill up to the shorter line).
   - **Compute current water:** `curWater = w * ht`.
   - **Update maximum:** `maxWater = max(maxWater, curWater)`.
   - **Move the shorter pointer inward:** if `height[lp] < height[rp]`, increment `lp`; else decrement `rp`.
3. **Return `maxWater`.**

## Dry Run

**Example Input:** `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`

| lp | rp | height[lp] | height[rp] | w | ht | water | maxWater |
|----|----|------------|------------|---|----|-------|----------|
| 0  | 8  | 1          | 7          | 8 | 1  | 8     | 8        |
| 1  | 8  | 8          | 7          | 7 | 7  | 49    | 49       |
| 1  | 7  | 8          | 3          | 6 | 3  | 18    | 49       |
| 1  | 6  | 8          | 8          | 5 | 8  | 40    | 49       |
| 2  | 6  | 6          | 8          | 4 | 6  | 24    | 49       |
| ... | ... | ...      | ...        | ...| ...| ... | 49       |

**Output:** `49`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each pointer moves at most n steps total |
| **Space** | O(1) | Only a fixed number of pointer/tracking variables |
