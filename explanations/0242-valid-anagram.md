# Problem 242 - Valid Anagram

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/valid-anagram/
**Language:** C++

---

## Problem Statement
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise. An anagram uses the same characters as the original string, each the same number of times, but in a different order.

## Approach: Hash Map Character Frequency Comparison

The key insight is that two strings are anagrams if and only if they contain exactly the same characters with the same frequencies. We build two frequency maps — one for each string — and compare them character by character. An early length check avoids unnecessary work.

## Code Walkthrough (Step by Step)

1. **Length check:** If `s.size() != t.size()`, they cannot be anagrams — return `false` immediately.

2. **Build frequency map for `s`:** Iterate over each character in `s` and increment its count in the hash map `ss`.

3. **Build frequency map for `t`:** Same process for string `t` into hash map `tt`.

4. **Compare frequencies:** Iterate over each character in `s`. For each character `s[i]`, check if `ss[s[i]] != tt[s[i]]`. If any character count differs, return `false`.

5. **Return `true`** if all counts match.

## Dry Run

**Example Input:** `s = "anagram"`, `t = "nagaram"`

Length check: both have length 7, continue.

`ss` after counting s: `{a:3, n:1, g:1, r:1, m:1}`
`tt` after counting t: `{n:1, a:3, g:1, r:1, m:1}`

Comparing for each character in s (`a,n,a,g,r,a,m`):
- `a`: ss[a]=3, tt[a]=3 → match
- `n`: ss[n]=1, tt[n]=1 → match
- `g`: ss[g]=1, tt[g]=1 → match
- `r`: ss[r]=1, tt[r]=1 → match
- `m`: ss[m]=1, tt[m]=1 → match

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Three linear passes: build ss, build tt, compare |
| **Space** | O(1) | At most 26 distinct lowercase letters (fixed size maps) |
