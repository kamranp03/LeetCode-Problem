# Problem 852 - Peak Index in a Mountain Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/peak-index-in-a-mountain-array/
**Language:** C++

---

## Problem Statement
A mountain array strictly increases to a peak and then strictly decreases. Given such an array, find the index of the peak element. The array is guaranteed to be a valid mountain array, so there is always exactly one peak.

## Approach: Binary Search

Since the array has a unimodal (mountain) shape, binary search can find the peak in O(log N) instead of a linear scan. At any midpoint, if `arr[mid-1] < arr[mid] > arr[mid+1]`, that is the peak. If the left neighbor is smaller but the right is not (ascending slope), the peak is to the right. Otherwise (descending slope at mid), the peak is to the left.

## Code Walkthrough (Step by Step)

1. **Set bounds:** `st = 1`, `end = arr.size()-2` — skip the first and last elements since they can never be the peak.

2. **Binary search loop** while `st <= end`:
   - Compute `mid = st + (end - st) / 2`.
   - **Peak found:** If `arr[mid-1] < arr[mid]` AND `arr[mid] > arr[mid+1]`, return `mid`.
   - **On ascending slope:** If `arr[mid-1] < arr[mid]` (but right side not smaller), peak is to the right — set `st = mid + 1`.
   - **On descending slope:** Otherwise peak is to the left — set `end = mid - 1`.

3. Return `-1` (unreachable for valid mountain arrays).

## Dry Run

**Example Input:** `arr = [0, 1, 0]`

- st=1, end=1, mid=1
- arr[0]=0 < arr[1]=1 AND arr[1]=1 > arr[2]=0 → peak found at index 1

**Output:** `1`

**Example Input:** `arr = [0, 2, 1, 0]`

- st=1, end=2, mid=1
- arr[0]=0 < arr[1]=2 but arr[1]=2 > arr[2]=1 → peak at index 1

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log N) | Binary search halves the search space each iteration |
| **Space** | O(1) | Only a few index variables used |
