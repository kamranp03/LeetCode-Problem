# Problem 3321 - Find X-Sum of All K-Long Subarrays II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and integers `k` and `x`, for each subarray of length `k`, compute the x-sum (sum of `freq * val` for the top `x` most frequent elements). Return the array of x-sums. This is the large-value version of problem 3318 requiring an efficient O(n log n) solution.

## Approach: Two Ordered Sets with Lazy Sum Maintenance

We maintain two ordered sets of `(frequency, value)` pairs:
- `main`: the top `x` elements by `(freq, val)` (highest priority elements that contribute to x-sum).
- `sec`: all remaining elements in the window.

A running `sum` tracks the current x-sum for `main`. When the window slides, we insert or remove elements while keeping `main` exactly size `x` with the top elements.

The ordering trick: `set<pair<int,int>>` sorts by `(freq, val)` ascending, so `*rbegin()` is the highest-priority element.

## Code Walkthrough (Step by Step)

1. **insertInPair(p, x):** If `p` belongs in `main` (either main has fewer than `x` elements or `p > *main.begin()`), insert into `main` and update `sum`. If `main` grows beyond `x`, move the smallest (lowest priority) to `sec`.

2. **removeFromSet(p):** If `p` is in `main`, remove it from `sum` and `main`, then promote the largest element from `sec` into `main`. Otherwise just erase from `sec`.

3. **Sliding window:** For each new element `nums[j]`:
   - Remove its old `(freq, val)` from sets, increment frequency in `mp`, re-insert with updated frequency.
   - When window size hits `k`: record `sum` in result. Then remove the leaving element `nums[i]`, decrement its frequency, and re-insert if freq > 0.

4. **Return** `result`.

## Dry Run

**Example Input:** `nums = [1, 1, 2, 2, 3]`, `k = 3`, `x = 2`

- j=0: insert (1,1). main={(1,1)}, sum=1
- j=1: remove (1,1), freq[1]=2, insert (2,1). main={(2,1)}, sum=2
- j=2: insert (1,2). main has <2 → main={(1,2),(2,1)}, sum=4. Window=3 → result=[4]. Remove nums[0]=1: remove (2,1), freq[1]=1, insert (1,1).
- Continue sliding...

**Output:** e.g. `[4, 5, 7]` for this input.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Each element inserted/removed from ordered sets once |
| **Space** | O(k) | Sets hold at most k elements total |
