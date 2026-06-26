# Problem 1513 - Number of Substrings with Only 1s

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/number-of-substrings-with-only-1s/
**Language:** C++

---

## Problem Statement

Given a binary string `s`, return the number of substrings with all characters equal to '1'. Since the answer may be too large, return it modulo 10^9 + 7.

## Approach: Counting Consecutive 1s

The key insight is that a run of `n` consecutive 1's contributes exactly `n*(n+1)/2` substrings — but we don't need to compute that directly. Instead, for each new '1' we encounter, all substrings ending at this position (of any length) are valid. If there are `count` consecutive 1's ending here, we add `count` to the result — this is equivalent to summing 1+2+3+...+n over the run.

## Code Walkthrough (Step by Step)

1. **Initialize `count = 0`** (current run of 1's) and `res = 0` (total substrings).
2. **Iterate over each character `i` in `s`:**
   - If `i == '1'`: increment `count`, add `count` to `res` (with modulo). Every new '1' adds `count` new substrings — one for each length 1 through `count`.
   - If `i == '0'`: reset `count = 0` (break in consecutive 1's).
3. **Return `res % MOD`.**

## Dry Run

**Example Input:** `s = "0110111"`

- '0': count=0, res=0
- '1': count=1, res=1
- '1': count=2, res=3
- '0': count=0, res=3
- '1': count=1, res=4
- '1': count=2, res=6
- '1': count=3, res=9

**Output:** `9`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the string |
| **Space** | O(1) | Only count and result variables |
