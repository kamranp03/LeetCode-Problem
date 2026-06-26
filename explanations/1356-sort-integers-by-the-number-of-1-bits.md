# Problem 1356 - Sort Integers by The Number of 1 Bits

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
**Language:** C++

---

## Problem Statement

Given an integer array `arr`, sort it in increasing order based on the number of 1's in the binary representation of each element. If two or more integers have the same number of 1's, sort them in ascending order by value. Return the sorted array.

## Approach: Custom Comparator with Bit Counting

The key insight is to use a standard sort with a custom comparator. The comparator computes the popcount (number of set bits) for each element using Brian Kernighan's bit trick, then sorts primarily by popcount and secondarily by value.

## Code Walkthrough (Step by Step)

1. **`countOnes(x)`:** Counts set bits using `x &= (x-1)` which clears the lowest set bit each iteration. This is Brian Kernighan's algorithm — efficient and clean.
2. **`sortByBits(arr)`:** Calls `std::sort` with a lambda comparator.
3. **Comparator logic:** Compute `ca = countOnes(a)` and `cb = countOnes(b)`. If `ca == cb`, sort by value (`a < b`). Otherwise, sort by popcount (`ca < cb`).
4. **Return the sorted array.**

## Dry Run

**Example Input:** `arr = [0,1,2,3,4,5,6,7,8]`

| Value | Binary | Ones |
|-------|--------|------|
| 0 | 0000 | 0 |
| 1 | 0001 | 1 |
| 2 | 0010 | 1 |
| 4 | 0100 | 1 |
| 8 | 1000 | 1 |
| 3 | 0011 | 2 |
| 5 | 0101 | 2 |
| 6 | 0110 | 2 |
| 7 | 0111 | 3 |

**Output:** `[0,1,2,4,8,3,5,6,7]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n * log max_val) | Sort with O(log max_val) bit count per comparison |
| **Space** | O(1) | In-place sort, no extra space |
