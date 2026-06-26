# Problem 0028 - Find the Index of the First Occurrence in a String

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
**Language:** C++

---

## Problem Statement

Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Approach: Sliding Window (Naive String Matching)

The key insight is that we slide a window of size `m` (length of `needle`) across `haystack`. At each position `i`, we check whether the substring starting at `i` matches `needle` character by character. The loop runs only up to `n - m` to avoid out-of-bounds access (there can't be a match starting at a position where `needle` would extend beyond `haystack`).

## Code Walkthrough (Step by Step)

1. **Get lengths** `n = haystack.size()` and `m = needle.size()`.
2. **Outer loop** `i` from `0` to `n - m` (inclusive):
   - Initialize inner pointer `j = 0`.
   - **Inner while loop:** advance `j` as long as `j < m` and `haystack[i + j] == needle[j]`.
   - **After inner loop:** if `j == m`, all characters of `needle` matched — return `i`.
3. **If no match found**, return `-1`.

## Dry Run

**Example Input:** `haystack = "sadbutsad"`, `needle = "sad"`

`n = 9`, `m = 3`. Loop runs from `i = 0` to `i = 6`.

| i | j progression                     | j == m? | Action    |
|---|-----------------------------------|---------|-----------|
| 0 | s==s(j=1), a==a(j=2), d==d(j=3) | Yes (3) | return 0  |

**Output:** `0`

**Example Input:** `haystack = "leetcode"`, `needle = "leeto"`

| i | match attempt | j == 5? |
|---|---------------|---------|
| 0 | l,e,e,t → 'c' != 'o', stop at j=4 | No |
| 1 | 'e' != 'l', stop at j=0 | No |
| ... | no match | — |

**Output:** `-1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n × m) | For each of n-m+1 positions, up to m character comparisons |
| **Space** | O(1) | No extra data structures beyond integer indices |
