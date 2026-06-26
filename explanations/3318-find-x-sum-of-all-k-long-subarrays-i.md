# Problem 3318 - Find X-Sum of All K-Long Subarrays I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and integers `k` and `x`, for each subarray of length `k`, compute the "x-sum": take the `x` most frequent elements (by frequency, then by value for ties) and sum `frequency * value` for each. Return the array of x-sums for all k-length subarrays.

## Approach: Sliding Window with Frequency Map and Min-Heap

We use a sliding window of size `k`. For each window, we maintain a frequency map. To find the top-`x` elements efficiently, we use a min-heap of size `x` (storing `(frequency, value)` pairs). Elements at the bottom of the heap (lowest priority) get evicted when the heap exceeds size `x`.

For each window, we rebuild the top-x selection using a helper function that processes the frequency map with a min-heap.

## Code Walkthrough (Step by Step)

1. **Sliding window:** Use pointers `i` (left) and `j` (right). As `j` advances, add `nums[j]` to frequency map `mp`.

2. **Window ready (size == k):** Call `findTopXsum(mp, x)` to compute the x-sum for this window. Push result to `result`.

3. **Slide window:** Remove `nums[i]` from `mp` (decrement frequency, erase if 0), advance `i`.

4. **findTopXsum helper:** Build a min-heap of `(frequency, value)` pairs. Insert each entry from `mp`, evict the smallest if heap exceeds size `x`. Sum up `freq * val` for all elements remaining in the heap.

5. **Return** `result`.

## Dry Run

**Example Input:** `nums = [1, 1, 2, 2, 3]`, `k = 3`, `x = 2`

- Window [1,1,2]: freq={1:2, 2:1}. Top 2: (2,1) and (1,2). Sum = 2*1 + 1*2 = 4.
- Window [1,2,2]: freq={1:1, 2:2}. Top 2: (2,2) and (1,1). Sum = 2*2 + 1*1 = 5.
- Window [2,2,3]: freq={2:2, 3:1}. Top 2: (2,2) and (1,3). Sum = 2*2 + 1*3 = 7.

**Output:** `[4, 5, 7]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * k) | Each window rebuilds heap from frequency map |
| **Space** | O(k) | Frequency map holds at most k distinct elements |
