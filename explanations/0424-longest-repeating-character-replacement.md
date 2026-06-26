# Problem 424 - Longest Repeating Character Replacement

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/longest-repeating-character-replacement/
**Language:** C++

---

## Problem Statement
Given a string `s` and an integer `k`, you can replace any `k` characters in the string with any letter. Return the length of the longest substring containing only one distinct character that you can achieve after at most `k` replacements.

## Approach: Sliding Window with Max Frequency Tracking

The key insight is: within a window `[low, high]`, if we keep the most frequent character and replace everything else, we need `(window length - max frequency)` replacements. If this count exceeds `k`, the window is invalid and we shrink it from the left. We track the frequency of all characters in the current window using an array `f[256]` and find the max frequency by scanning it.

## Code Walkthrough (Step by Step)

1. **Initialize** frequency array `f[256]` to 0, pointers `low=0` and `high=0`, and result `res = INT_MIN`.

2. **Expand window (high pointer):** For each new character `s[high]`, increment `f[s[high]]`.

3. **Find max frequency:** Call `find(f)` which scans all 256 entries to get the highest frequency in the current window.

4. **Check validity:** `diff = (high - low + 1) - maxcnt`. If `diff > k`, the window needs more than `k` replacements — shrink from left:
   - Decrement `f[s[low]]` and advance `low`.
   - Recalculate `maxcnt` and `diff` until valid.

5. **Update result:** `res = max(res, high - low + 1)` after ensuring the window is valid.

6. **Return `res`** after processing all characters.

## Dry Run

**Example Input:** `s = "AABABBA"`, `k = 1`

| high | char | window | maxcnt | len | diff | action |
|------|------|--------|--------|-----|------|--------|
| 0 | A | A | 1 | 1 | 0 | res=1 |
| 1 | A | AA | 2 | 2 | 0 | res=2 |
| 2 | B | AAB | 2 | 3 | 1 | res=3 |
| 3 | A | AABA | 3 | 4 | 1 | res=4 |
| 4 | B | AABAB | 3 | 5 | 2>1 | shrink: low=1, window=ABAB, maxcnt=2, diff=2>1, shrink: low=2, window=BAB, maxcnt=2,diff=1 |
| 4 | - | BAB | 2 | 3 | 1 | res=4 |
| 5 | B | BABB | 3 | 4 | 1 | res=4 |
| 6 | A | BABBA | 3 | 5 | 2>1 | shrink to ABBA, still 2>1, shrink to BBA, diff=1 |
| 6 | - | BBA | 2 | 3 | 1 | res=4 |

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n × 256) | Each character is added/removed once; finding max scans 256 entries each time |
| **Space** | O(256) = O(1) | Fixed-size frequency array |
