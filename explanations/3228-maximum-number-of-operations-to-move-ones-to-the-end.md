# Problem 3228 - Maximum Number of Operations to Move Ones to the End

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
**Language:** C++

---

## Problem Statement

Given a binary string `s`, in one operation you can pick any `'1'` that is immediately followed by a `'0'` and swap them. Return the maximum number of such operations you can perform.

## Approach: Count Ones Before Each Group of Zeros

Each time a `'1'` passes through a `'0'`, it counts as one operation. When we encounter a group of consecutive `'0'`s, every `'1'` that currently sits to the left (counted so far) will need to pass through this group. So the contribution of each `'0'` group to the total operations equals the number of `'1'`s seen before it.

We scan left to right: when we see a `'0'`, we know all `ones` collected so far will each perform one swap for this group. We add `ones` to the result for each contiguous block of zeros encountered.

## Code Walkthrough (Step by Step)

1. **Initialize** `res = 0`, `ones = 0`, `i = 0`.

2. **Scan string:**
   - If `s[i] == '0'`: add `ones` to `res` (all accumulated ones swap past this zero group). Then skip the entire contiguous block of `'0'`s (inner while loop).
   - If `s[i] == '1'`: increment `ones`, advance `i`.

3. **Return** `res`.

## Dry Run

**Example Input:** `s = "1001101"`

| i | s[i] | ones | action | res |
|---|------|------|--------|-----|
| 0 | '1' | 1 | ones++ | 0 |
| 1 | '0' | 1 | res+=1, skip zeros (i→3) | 1 |
| 3 | '1' | 2 | ones++ | 1 |
| 4 | '1' | 3 | ones++ | 1 |
| 5 | '0' | 3 | res+=3, skip zeros (i→6) | 4 |
| 6 | '1' | 4 | ones++ | 4 |

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each character visited at most twice (inner+outer loop) |
| **Space** | O(1) | Only a few counters |
