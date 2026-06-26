# Problem 0003 - Longest Substring Without Repeating Characters

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/longest-substring-without-repeating-characters/
**Language:** C++

---

## Problem Statement

Given a string `s`, find the length of the longest substring that contains no repeating characters. A substring is a contiguous sequence of characters within the string.

## Approach: Sliding Window with Hash Map

The key insight is to maintain a window `[l, h]` that always contains unique characters. We expand the right boundary `h` one character at a time. When a duplicate appears (detected when the map size is smaller than the window size), we shrink from the left `l` until all characters in the window are unique again. The map tracks character counts inside the current window.

## Code Walkthrough (Step by Step)

1. **Initialize** `l = 0` (left pointer), `res = INT_MIN` (result), and an empty map `mp`.
2. **Expand right pointer `h`** across every character in the string.
3. **Add `s[h]` to the map** (increment its count).
4. **Compute window size** `k = h - l + 1`.
5. **Detect duplicates:** If `mp.size() < k`, the window has a duplicate. Shrink from the left: decrement count of `s[l]`, erase from map if count reaches 0, increment `l`, recalculate `k`.
6. **Update result:** After the window is valid, update `res = max(res, k)`.
7. **Handle empty string:** If `res` is still `INT_MIN`, return 0.

## Dry Run

**Example Input:** `s = "abcab"`

| h | s[h] | mp (char→count) | l | k | res |
|---|------|-----------------|---|---|-----|
| 0 | a    | {a:1}           | 0 | 1 | 1   |
| 1 | b    | {a:1,b:1}       | 0 | 2 | 2   |
| 2 | c    | {a:1,b:1,c:1}   | 0 | 3 | 3   |
| 3 | a    | {a:2,b:1,c:1}   | 0 | 4 — size(3)<4, shrink: remove a(count→1, keep), l=1, k=3 | 3 |
| 4 | b    | {a:1,b:2,c:1}   | 1 | 4 — size(3)<4, shrink: remove b(count→1, keep), l=2, k=3 | 3 |

**Output:** `3` (substring "abc")

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each character is added and removed from the window at most once |
| **Space** | O(min(n, m)) | Map holds at most the size of the character set m (e.g., 26 for lowercase letters) |
