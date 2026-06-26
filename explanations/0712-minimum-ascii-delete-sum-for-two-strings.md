# Problem 712 - Minimum ASCII Delete Sum for Two Strings

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
**Language:** C++

---

## Problem Statement
Given two strings `s1` and `s2`, return the lowest ASCII sum of deleted characters needed to make both strings equal. You can delete characters from either string; the cost of deleting a character is its ASCII value.

## Approach: 2D Dynamic Programming (Similar to Edit Distance)

The key insight is that this is a variant of the Longest Common Subsequence problem. Instead of maximizing matches, we minimize deletion costs. `dp[i][j]` = minimum ASCII delete cost to make `s1[0..i-1]` and `s2[0..j-1]` equal. If characters match, no deletion needed; otherwise, we choose the cheaper deletion.

## Code Walkthrough (Step by Step)

1. **Initialize table:** `dp` is `(m+1) x (n+1)` filled with 0.

2. **Base cases:**
   - `dp[i][0]`: To make `s1[0..i-1]` match empty string, delete all characters in s1. `dp[i][0] = dp[i-1][0] + s1[i-1]` (accumulate ASCII costs).
   - `dp[0][j]`: Similarly, `dp[0][j] = dp[0][j-1] + s2[j-1]`.

3. **Fill table for i=1..m, j=1..n:**
   - If `s1[i-1] == s2[j-1]`: Characters match → no deletion needed from this pair. `dp[i][j] = dp[i-1][j-1]`.
   - Else: Choose the cheaper option:
     - Delete `s1[i-1]`: cost = `dp[i-1][j] + s1[i-1]`
     - Delete `s2[j-1]`: cost = `dp[i][j-1] + s2[j-1]`
     - `dp[i][j] = min(both options)`

4. **Return `dp[m][n]`** — minimum cost to make both strings equal.

## Dry Run

**Example Input:** `s1 = "sea"`, `s2 = "eat"`

Base cases:
- dp[1][0] = 's' = 115
- dp[2][0] = 115 + 'e' = 115+101=216
- dp[3][0] = 216 + 'a' = 216+97=313
- dp[0][1] = 'e' = 101
- dp[0][2] = 101+'a'=198
- dp[0][3] = 198+'t'=314

Fill:
- dp[1][1]: s1[0]='s' vs s2[0]='e' → differ → min(dp[0][1]+115, dp[1][0]+101) = min(216, 216) = 216
- dp[2][1]: s1[1]='e' == s2[0]='e' → dp[1][0] = 115
- dp[2][2]: s1[1]='e' vs s2[1]='a' → differ → min(dp[1][2]+101, dp[2][1]+'a') = min(dp[1][2]+101, 115+97)
- ... continuing through the table...

Final dp[3][3] = 231

**Output:** `231` (delete 's' from "sea" = 115, delete 't' from "eat" = 116; 115+116=231)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m × n) | Fill every cell of the (m+1) × (n+1) table once |
| **Space** | O(m × n) | The full DP table is stored |
