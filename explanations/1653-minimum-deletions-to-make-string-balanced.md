# Problem 1653 - Minimum Deletions to Make String Balanced

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
**Language:** C++

---

## Problem Statement

Given a string `s` consisting of only 'a' and 'b', return the minimum number of deletions needed to make `s` balanced, meaning no 'b' appears before any 'a' (i.e., all 'a's come before all 'b's).

## Approach: Greedy DP — Track B-Count

The key insight is: as we scan left to right, for each 'a' we encounter, we have two choices — either delete this 'a' (cost: `ans + 1`) or delete all 'b's seen so far (cost: `bCount`). We take the minimum. This greedy/DP decision at each 'a' ensures we minimize deletions.

## Code Walkthrough (Step by Step)

1. **Initialize `bCount = 0`** (number of 'b's seen so far) and `ans = 0` (minimum deletions).
2. **Iterate over each character `c` in `s`:**
   - If `c == 'b'`: increment `bCount` (a 'b' has been placed; it might need to be removed if 'a' comes after it).
   - If `c == 'a'`: update `ans = min(ans + 1, bCount)`. Either delete this 'a' (ans+1) or delete all preceding 'b's (bCount).
3. **Return `ans`.**

## Dry Run

**Example Input:** `s = "aababbab"`

| char | bCount | ans | Reasoning |
|------|--------|-----|-----------|
| 'a' | 0 | min(1,0)=0 | delete 0 b's |
| 'a' | 0 | min(1,0)=0 | still 0 |
| 'b' | 1 | 0 | count b |
| 'a' | 1 | min(1,1)=1 | delete 1 'b' or this 'a' |
| 'b' | 2 | 1 | count b |
| 'b' | 3 | 1 | count b |
| 'a' | 3 | min(2,3)=2 | delete this 'a' |
| 'b' | 4 | 2 | count b |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the string |
| **Space** | O(1) | Only two integer variables |
