# Problem 3713 - Longest Balanced Substring I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/longest-balanced-substring-i/
**Language:** C++

---

## Problem Statement

Given a string `s` containing only lowercase English letters, find the length of the longest substring where every character that appears has the same frequency. A "balanced" substring is one where all present characters occur the same number of times.

## Approach: Brute Force with Frequency Check

For every possible substring `s[i..j]`, maintain a frequency array and check whether all non-zero frequencies are equal. Since the constraints for the Easy variant are small, an O(n^3) or O(n^2) brute force with a helper function suffices.

## Code Walkthrough (Step by Step)

1. **`check(freq)` helper:** scan the 26-character frequency array; ignore zero entries. The first non-zero frequency becomes the "common" value. Return false if any other non-zero frequency differs.
2. **Outer loop `i`:** starting position.
3. **Inner loop `j`:** ending position. Maintain running `freq` array. After each character addition, call `check(freq)`. If balanced, update `maxL`.
4. **Return** `maxL`.

## Dry Run

**Example Input:** `s = "aabbc"`

- i=0:
  - j=0: freq=[1,0,...] → check=true. maxL=1.
  - j=1: freq=[2,0,...] → check=true. maxL=2.
  - j=2: freq=[2,1,...] → check=false. 2≠1.
  - j=3: freq=[2,2,...] → check=true. maxL=4.
  - j=4: freq=[2,2,1,...] → check=false.
- i=1,j=4: freq=[1,2,1] → false. (Various others...)

**Output:** `4` (substring "aabb")

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2 * 26) | O(n^2) substrings, each O(26) check |
| **Space** | O(26) | Frequency array of fixed size 26 |
