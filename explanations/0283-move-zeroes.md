# Problem 283 - Move Zeroes

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/move-zeroes/
**Language:** C++

---

## Problem Statement
Given an integer array `nums`, move all zeros to the end while maintaining the relative order of the non-zero elements. The operation must be done in-place without making a copy of the array.

## Approach: Two-Pointer In-Place Swap

The key insight is to maintain a write pointer `j` that always points to the leftmost zero. Then we scan ahead with a read pointer `i` looking for non-zero elements. Whenever we find one, we swap it with the zero at position `j` and advance `j`. This naturally preserves the relative order of non-zero elements while pushing zeros to the end.

## Code Walkthrough (Step by Step)

1. **Find the first zero:** Scan from left to right with index `i`. Set `j = i` when the first zero is found. If no zero exists (`j == -1` after the loop), nothing to do.

2. **Early exit:** If `j == -1`, the array has no zeros — return immediately.

3. **Two-pointer scan:** Start `i` at `j + 1` (one past the first zero). For each `i`:
   - If `nums[i] != 0`: swap `nums[j]` and `nums[i]`, then increment `j` (the next zero position).
   - If `nums[i] == 0`: skip (do nothing).

4. **Result:** All non-zero elements are now compacted to the front in their original relative order; zeros fill the tail.

## Dry Run

**Example Input:** `nums = [0, 1, 0, 3, 12]`

Find first zero: `j = 0` (nums[0] = 0).

Two-pointer scan starting at `i = 1`:
- `i=1`: nums[1]=1 != 0 → swap(nums[0], nums[1]) → `[1, 0, 0, 3, 12]`, j=1
- `i=2`: nums[2]=0 → skip
- `i=3`: nums[3]=3 != 0 → swap(nums[1], nums[3]) → `[1, 3, 0, 0, 12]`, j=2
- `i=4`: nums[4]=12 != 0 → swap(nums[2], nums[4]) → `[1, 3, 12, 0, 0]`, j=3

**Output:** `[1, 3, 12, 0, 0]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two linear passes at most (finding first zero + the swap scan) |
| **Space** | O(1) | All operations done in-place with two index variables |
