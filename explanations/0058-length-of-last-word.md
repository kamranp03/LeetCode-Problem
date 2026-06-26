# Problem 0058 - Length of Last Word

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/length-of-last-word/
**Language:** C++

---

## Problem Statement

Given a string `s` consisting of words and spaces, return the length of the last word. A word is a maximal substring consisting solely of non-space characters. Trailing spaces should be ignored.

## Approach: Reverse Traversal

The key insight is to traverse the string from right to left in two phases: first skip any trailing spaces (since the last word might be followed by spaces), then count characters until the next space or the beginning of the string. This avoids splitting the string or any extra memory allocation.

## Code Walkthrough (Step by Step)

1. **Initialize** `i = s.size() - 1` (start from the last character) and `cnt = 0` (character counter).
2. **Phase 1 — Skip trailing spaces:** while `i >= 0` and `s[i] == ' '`, decrement `i`.
3. **Phase 2 — Count the last word:** while `i >= 0` and `s[i] != ' '`, increment `cnt` and decrement `i`.
4. **Return `cnt`.**

## Dry Run

**Example Input:** `s = "Hello World"`

Phase 1: `i = 10` ('d' is not a space) → no trailing spaces to skip.

Phase 2 — count from right:
| i  | s[i] | cnt |
|----|------|-----|
| 10 | d    | 1   |
| 9  | l    | 2   |
| 8  | r    | 3   |
| 7  | o    | 4   |
| 6  | W    | 5   |
| 5  | ' '  | stop|

**Output:** `5`

**Example Input:** `s = "   fly me   "`

Phase 1: skip trailing spaces at i=12,11,10 → i=9 ('e').
Phase 2: count 'e','m',' '→stop → cnt=2.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | In the worst case we scan the whole string (all spaces + last word) |
| **Space** | O(1) | Only two integer variables |
