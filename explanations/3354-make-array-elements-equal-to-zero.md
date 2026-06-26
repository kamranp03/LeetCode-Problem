# Problem 3354 - Make Array Elements Equal to Zero

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/make-array-elements-equal-to-zero/
**Language:** C++

---

## Problem Statement

Given a 0-indexed integer array `nums` where exactly one element is `0`, you can start at the zero element and move left or right. Each time you move onto a non-zero element, you subtract 1 from it and reverse your direction. Count the number of starting directions (left or right) from the zero element that result in all elements becoming zero.

## Approach: Simulation

For each zero position `i`, simulate the process twice: once starting with direction right (+1) and once with direction left (-1). After simulation, check if all elements became zero. Count valid starting configurations.

The simulation uses a copy of the array to avoid mutating the original between trials.

## Code Walkthrough (Step by Step)

1. **Iterate** over all indices `i` where `nums[i] == 0`.

2. **For each zero:** Simulate with direction `+1` (right) and `-1` (left):
   - Copy `nums` into `a`.
   - Start at `curr = start`, direction `d`.
   - Loop: if `a[curr] == 0`, advance (`curr += d`). If non-zero, decrement `a[curr]`, reverse direction (`d = -d`), advance.
   - Stop when `curr` goes out of bounds.

3. **After simulation:** Check if all elements in `a` are zero. If yes, increment `ans`.

4. **Return** `ans` (maximum 2 for a single zero position, times the number of zero positions).

## Dry Run

**Example Input:** `nums = [2, 0, 1]`

Zero is at index 1.

**Start right (+1):**
- curr=1 (zero), move right → curr=2 (a[2]=1)
- a[2]-=1=0, reverse → d=-1, curr=1 (zero)
- curr=1 (zero), move left → curr=0 (a[0]=2)
- a[0]-=1=1, reverse → d=+1, curr=1 (zero)
- curr=1, move right → curr=2 (a[2]=0), move right → curr=3 (out of bounds)
- a = [1, 0, 0] → not all zero. Invalid.

**Start left (-1):**
- curr=1, move left → curr=0 (a[0]=2)
- a[0]-=1=1, reverse → d=+1, curr=1 → curr=2 (a[2]=1)
- a[2]-=1=0, reverse → d=-1, curr=1 → curr=0 (a[0]=1)
- a[0]-=1=0, reverse → d=+1, curr=1 → curr=2 → out of bounds
- a = [0, 0, 0] → all zero! Valid. ans=1.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * sum(nums)) | Each simulation runs until all elements are drained |
| **Space** | O(n) | Copy of array for each simulation |
