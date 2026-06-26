# Problem 0075 - Sort Colors

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/sort-colors/
**Language:** C++

---

## Problem Statement

Given an array `nums` containing only `0`, `1`, and `2` (representing red, white, and blue), sort them in-place so that objects of the same color are adjacent, in the order 0, 1, 2. You must solve this without using a library sort function and in a single pass.

## Approach: Dutch National Flag Algorithm (Three Pointers)

The key insight is to maintain three regions in the array using three pointers:
- `[0, low-1]` — all 0s (red)
- `[low, mid-1]` — all 1s (white)
- `[high+1, n-1]` — all 2s (blue)
- `[mid, high]` — unprocessed region

We move `mid` forward, and based on the value at `mid`, either swap it to the front (0), leave it (1), or swap it to the back (2).

## Code Walkthrough (Step by Step)

1. **Initialize:** `low = 0`, `mid = 0`, `high = nums.size() - 1`.
2. **Loop while `mid <= high`** (process the unexamined region):
   - **If `nums[mid] == 0`:** swap `nums[low]` and `nums[mid]`; increment both `low` and `mid` (0 is placed in the 0-region; the element brought to `mid` is known to be 1, so we can advance `mid` too).
   - **If `nums[mid] == 1`:** it's already in the correct region; increment `mid` only.
   - **If `nums[mid] == 2`:** swap `nums[mid]` and `nums[high]`; decrement `high` only (we don't increment `mid` because the swapped value at `mid` is unknown and needs to be re-examined).
3. **Array is fully sorted** when `mid > high`.

## Dry Run

**Example Input:** `nums = [2, 0, 2, 1, 1, 0]`

| mid | high | low | nums[mid] | Action              | nums              |
|-----|------|-----|-----------|---------------------|-------------------|
| 0   | 5    | 0   | 2         | swap(mid,high), high-- | [0,0,2,1,1,2]  |
| 0   | 4    | 0   | 0         | swap(low,mid), low++, mid++ | [0,0,2,1,1,2] |
| 1   | 4    | 1   | 0         | swap(low,mid), low++, mid++ | [0,0,2,1,1,2] |
| 2   | 4    | 2   | 2         | swap(mid,high), high-- | [0,0,1,1,2,2]  |
| 2   | 3    | 2   | 1         | mid++               | [0,0,1,1,2,2]  |
| 3   | 3    | 2   | 1         | mid++               | [0,0,1,1,2,2]  |
| 4   > 3, loop ends                                                    |

**Output:** `[0, 0, 1, 1, 2, 2]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass — each element is processed at most once |
| **Space** | O(1) | In-place with only three pointer variables |
