# Problem 3120 - Count the Number of Special Characters I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-the-number-of-special-characters-i/
**Language:** C++

---

## Problem Statement

A letter is "special" if it appears in both lowercase and uppercase forms somewhere in the string `word`. Return the count of such special letters.

## Approach: Boolean Presence Array Using ASCII Offsets

We use a boolean array `f` of size 58 (covering ASCII codes for 'A'=65 to 'z'=122, offset by 'A'=65 so indices 0..57). For each character `c`, we set `f[c - 'A'] = true`. To check if both `'a'` and `'A'` are present for letter at index `i` (where lowercase occupies index `i+32`), we check `f[i]` (uppercase present) and `f[i+32]` (lowercase present, since lowercase ASCII = uppercase ASCII + 32).

## Code Walkthrough (Step by Step)

1. **Initialize** `f` as a boolean vector of 58 `false` values.

2. **Mark presence:** For each character `c` in `word`, set `f[c - 'A'] = true`. This marks both uppercase (indices 0-25) and lowercase (indices 32-57) correctly within the same array.

3. **Count special letters:** Loop `i` from 32 to 57 (lowercase letter indices). If `f[i]` (lowercase present) AND `f[i - 32]` (corresponding uppercase present), increment `cnt`.

4. **Return** `cnt`.

## Dry Run

**Example Input:** `word = "aaAbcBC"`

Marking:
- 'a' (97-65=32) → f[32]=true
- 'a' → f[32]=true (already)
- 'A' (65-65=0) → f[0]=true
- 'b' (98-65=33) → f[33]=true
- 'c' (99-65=34) → f[34]=true
- 'B' (66-65=1) → f[1]=true
- 'C' (67-65=2) → f[2]=true

Count (i from 32 to 57):
- i=32: f[32]=true(a), f[0]=true(A) → cnt=1
- i=33: f[33]=true(b), f[1]=true(B) → cnt=2
- i=34: f[34]=true(c), f[2]=true(C) → cnt=3
- Others: not both present

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass over the string |
| **Space** | O(1) | Fixed-size array of 58 booleans |
