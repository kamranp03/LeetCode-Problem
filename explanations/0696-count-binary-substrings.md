# Problem 696 - Count Binary Substrings

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-binary-substrings/
**Language:** C++

---

## Problem Statement
Given a binary string `s`, return the number of substrings that have an equal number of consecutive 0s and 1s, and all the 0s and 1s in the substring are grouped together (e.g., "0011", "01", "10", "1100"). Each occurrence is counted separately.

## Approach: Group Counting (Previous vs Current Run Length)

The key insight is to think in terms of consecutive groups: whenever we transition from one character to the other, we start a new group. For each position, if the current group's run length is at most the previous group's run length, we've found a valid substring (they have equal adjacent groups). We track `previous` (length of the last completed run) and `current` (length of the ongoing run).

## Code Walkthrough (Step by Step)

1. **Initialize:** `ans = 0`, `previous = 0`, `current = 1` (the first character forms a run of length 1).

2. **Scan from index 1:**
   - If `s[i] == s[i-1]`: Same character continues — increment `current`.
   - Else: Transition to new character — save `previous = current`, reset `current = 1`.

3. **After updating:** If `current <= previous`, a new valid substring exists (the current run can be matched against an equal-length portion of the previous run). Increment `ans`.

4. **Return `ans`.**

## Dry Run

**Example Input:** `s = "00110011"`

| i | s[i] | prev | curr | curr<=prev? | ans |
|---|------|------|------|-------------|-----|
| 1 | 0 | 0 | 2 | 2<=0? No | 0 |
| 2 | 1 | 2 | 1 | 1<=2? Yes | 1 |
| 3 | 1 | 2 | 2 | 2<=2? Yes | 2 |
| 4 | 0 | 2 | 1 | 1<=2? Yes | 3 |
| 5 | 0 | 2 | 2 | 2<=2? Yes | 4 |
| 6 | 1 | 2 | 1 | 1<=2? Yes | 5 |
| 7 | 1 | 2 | 2 | 2<=2? Yes | 6 |

**Output:** `6` (substrings: "0011","01","10","1100","01","10" counted by position)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the string |
| **Space** | O(1) | Only three integer variables |
