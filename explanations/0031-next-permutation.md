# Problem 0031 - Next Permutation

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/next-permutation/
**Language:** C++

---

## Problem Statement

Given an array of integers `nums`, rearrange it to the next lexicographically greater permutation. If no such permutation exists (array is in descending order), rearrange it to the lowest possible order (ascending). The replacement must be done in-place.

## Approach: Find Pivot + Swap + Reverse

The key insight relies on three observations:
1. The next permutation's suffix starts at the first position (from the right) where the sequence is no longer descending — call this the "pivot" index.
2. Swap the pivot element with the smallest element to its right that is still larger than it.
3. After the swap, reverse everything to the right of the pivot to get the smallest possible suffix.

## Code Walkthrough (Step by Step)

1. **Find the pivot `idx`:** scan from right to left; find the first `i` where `nums[i] < nums[i+1]`. Set `idx = i`.
2. **If `idx == -1`:** the entire array is in descending order (last permutation). Reverse the whole array to get the first permutation and return.
3. **Find the swap target:** scan from the right end to `idx+1`; find the first element `nums[i] > nums[idx]`. Swap `nums[i]` with `nums[idx]`.
4. **Reverse the suffix** from `idx+1` to the end. Since the right portion was descending before the swap, reversing it gives the smallest possible suffix.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 6, 5, 4]`

Step 1 — Find pivot: scan right to left
- i=4: nums[4]=5, nums[5]=4 → 5 > 4, not ascending — skip
- i=3: nums[3]=6, nums[4]=5 → 6 > 5, not ascending — skip
- i=2: nums[2]=3, nums[3]=6 → 3 < 6 — pivot found! `idx = 2`

Step 3 — Find swap target (rightmost > nums[2]=3): nums[5]=4 > 3 → swap
Array: `[1, 2, 4, 6, 5, 3]`

Step 4 — Reverse from idx+1=3 to end: `[6,5,3]` → `[3,5,6]`
Array: `[1, 2, 4, 3, 5, 6]`

**Output:** `[1, 2, 4, 3, 5, 6]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Three linear passes: find pivot, find swap, reverse suffix |
| **Space** | O(1) | In-place operations only |
