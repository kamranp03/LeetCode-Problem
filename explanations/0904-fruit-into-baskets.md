# Problem 904 - Fruit Into Baskets

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/fruit-into-baskets/
**Language:** C++

---

## Problem Statement
You have two baskets, each holding only one type of fruit. Walking through an array where each element represents a fruit type, you must pick consecutive fruits starting from some tree. You can only hold two distinct fruit types at a time. Return the maximum number of fruits you can collect in one continuous subarray containing at most 2 distinct fruit types.

## Approach: Sliding Window with HashMap

This is a classic "at most K distinct elements" sliding window problem with K=2. Maintain a window `[low, high]` and a frequency map of fruit types in the window. Expand `high` by adding the new fruit. When the map has more than 2 distinct types, shrink from `low` by decrementing counts and removing types that reach 0. Track the maximum window size throughout.

## Code Walkthrough (Step by Step)

1. **Initialize:** `low = 0`, frequency map `f` empty, `res = INT_MIN`.

2. **Expand `high`** from 0 to n-1:
   - Add `a[high]` to map: `f[a[high]]++`.
   - **Shrink window while `f.size() > 2`:**
     - Decrement `f[a[low]]`.
     - If count reaches 0, erase the type from the map.
     - Increment `low`.
   - Update `res = max(res, high - low + 1)`.

3. **Return `res`** — the longest valid window.

## Dry Run

**Example Input:** `a = [1, 2, 1, 2, 3]`

| high | a[high] | f              | low | window size |
|------|---------|----------------|-----|-------------|
| 0    | 1       | {1:1}          | 0   | 1           |
| 1    | 2       | {1:1, 2:1}     | 0   | 2           |
| 2    | 1       | {1:2, 2:1}     | 0   | 3           |
| 3    | 2       | {1:2, 2:2}     | 0   | 4           |
| 4    | 3       | {1:2,2:2,3:1}→ shrink: remove 1→{2:2,3:1}→still 2 types | 2 | 3 |

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Each element enters and exits the window at most once |
| **Space** | O(1) | Map holds at most 3 entries at any time |
