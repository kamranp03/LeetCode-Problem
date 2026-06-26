# Problem 961 - N-Repeated Element in Size 2N Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
**Language:** C++

---

## Problem Statement
Given an integer array of size 2N where one element appears exactly N times and all other N elements are distinct (appearing once each), find and return the element that appears N times.

## Approach: Hash Set for Duplicate Detection

Since the repeated element appears N times and all others appear only once, the repeated element is the first one we encounter a second time when scanning left to right. Use an `unordered_set` to track seen elements. As soon as we try to insert an element that is already in the set, that element is the answer.

## Code Walkthrough (Step by Step)

1. **Initialize** an empty `unordered_set<int> s`.

2. **Iterate** through each element `x` in `nums`:
   - If `s.count(x) > 0`: `x` has been seen before — return `x` immediately.
   - Otherwise: insert `x` into `s`.

3. Return `-1` (unreachable given problem constraints).

## Dry Run

**Example Input:** `nums = [5, 1, 5, 2, 5, 3, 5, 4]` (N=4)

| Index | x | Set before | Action         |
|-------|---|-----------|----------------|
| 0     | 5 | {}        | Insert 5       |
| 1     | 1 | {5}       | Insert 1       |
| 2     | 5 | {5,1}     | 5 found! Return 5 |

**Output:** `5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | At most 2N elements scanned; repeated element found within N+1 steps |
| **Space** | O(N) | Set holds at most N+1 unique elements before the duplicate is found |
