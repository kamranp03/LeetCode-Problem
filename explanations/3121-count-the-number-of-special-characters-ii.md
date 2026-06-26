# Problem 3121 - Count the Number of Special Characters II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-the-number-of-special-characters-ii/
**Language:** C++

---

## Problem Statement

A letter is "special" if all occurrences of its lowercase form appear before all occurrences of its uppercase form in the string. Return the number of such special letters. (Both forms must be present.)

## Approach: Track Last Lowercase Index and First Uppercase Index

For each letter, we need to verify: (1) it has at least one lowercase occurrence, (2) it has at least one uppercase occurrence, and (3) the last occurrence of the lowercase precedes the first occurrence of the uppercase.

We track `lastLower[26]` (last index of each lowercase letter) and `firstUpper[26]` (first index of each uppercase letter). Then count letters where both are set and `lastLower[i] < firstUpper[i]`.

## Code Walkthrough (Step by Step)

1. **Initialize** `lastLower` and `firstUpper` arrays of size 26, filled with `-1`.

2. **Single pass** over `word`:
   - For lowercase `ch`: update `lastLower[ch - 'a'] = i` (keep updating to get the last occurrence).
   - For uppercase `ch`: set `firstUpper[ch - 'A'] = i` only if not yet set (keep first occurrence).

3. **Count special:** For each letter `i` (0-25): if `lastLower[i] != -1` AND `firstUpper[i] != -1` AND `lastLower[i] < firstUpper[i]`, increment count.

4. **Return** count.

## Dry Run

**Example Input:** `word = "abBCbA"`

Scan:
- i=0, 'a': lastLower[0]=0
- i=1, 'b': lastLower[1]=1
- i=2, 'B': firstUpper[1]=2
- i=3, 'C': firstUpper[2]=3
- i=4, 'b': lastLower[1]=4
- i=5, 'A': firstUpper[0]=5

Check:
- 'a': lastLower[0]=0, firstUpper[0]=5 → 0 < 5 ✓ (special)
- 'b': lastLower[1]=4, firstUpper[1]=2 → 4 < 2? No (not special, lowercase appears after uppercase)
- 'c': lastLower[2]=-1 → skip

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass over the string |
| **Space** | O(1) | Two fixed arrays of size 26 |
