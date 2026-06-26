# Problem 941 - Valid Mountain Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/valid-mountain-array/
**Language:** C++

---

## Problem Statement
An array is a valid mountain array if it has at least 3 elements, strictly increases to a peak (not at the first or last position), and then strictly decreases. Given an integer array, return true if it is a valid mountain array.

## Approach: Two-Phase Linear Scan

Walk up the ascending slope with one pointer until it stops increasing. Verify the peak is neither the first nor last element (otherwise it's flat or monotone). Then walk down the descending slope. If the pointer reaches the last element, the array is a valid mountain.

## Code Walkthrough (Step by Step)

1. **Phase 1 — Ascend:** Start at index 0. While `arr[i] < arr[i+1]`, increment `i`.

2. **Validity check:** If `i == 0`, there was no ascent (peak at start — invalid). If `i == n-1`, there was no descent after the peak (all ascending — invalid). Return `false` in either case.

3. **Phase 2 — Descend:** While `arr[i] > arr[i+1]`, increment `i`.

4. **Final check:** Return `i == n-1`. If we consumed all remaining elements in the descent, the array is a valid mountain.

## Dry Run

**Example Input:** `arr = [0, 3, 2, 1]`

- Phase 1: i=0, arr[0]=0 < arr[1]=3 → i=1; arr[1]=3 > arr[2]=2 → stop. i=1.
- Check: i=1, not 0, not 3 (n-1) → valid peak position.
- Phase 2: arr[1]=3 > arr[2]=2 → i=2; arr[2]=2 > arr[3]=1 → i=3; stop.
- Return i==3 == n-1=3 → `true`

**Output:** `true`

**Example Input:** `arr = [3, 5, 5]`

- Phase 1: arr[0]=3 < arr[1]=5 → i=1; arr[1]=5 == arr[2]=5 → stop. i=1.
- Phase 2: arr[1]=5 == arr[2]=5 → stop immediately. i=1.
- Return i==2? No → `false`

**Output:** `false`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Each index visited at most once across both phases |
| **Space** | O(1) | Only index variable `i` used |
