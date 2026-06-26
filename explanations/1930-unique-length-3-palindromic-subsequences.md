# Problem 1930 - Unique Length-3 Palindromic Subsequences

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
**Language:** C++

---

## Problem Statement
Given a string `s`, return the number of unique palindromes of length 3 that are subsequences of `s`. A palindrome of length 3 has the form `"aba"` where the first and third characters are the same.

## Approach: First and Last Occurrence + Middle Character Set

The key insight is that every length-3 palindrome has the form `c ? c` where `c` is the outer character. For each of the 26 possible outer characters, find its first and last occurrence in the string. Any character that appears strictly between those positions can be the middle character. Count unique middle characters using a set — the number of valid middle characters equals the number of unique palindromes with that outer character.

## Code Walkthrough (Step by Step)

1. **Build `ind[26]`**: A pair array where `ind[i].first` = first index of character `'a'+i` and `ind[i].second` = last index of character `'a'+i`. Initialize both to -1.
2. **Single pass over `s`**: For each character, if it has no first occurrence yet, record it. Always update the last occurrence.
3. **For each of the 26 characters**:
   - Let `left = ind[i].first`, `right = ind[i].second`.
   - If `left == -1` (character not in string), skip.
   - Use an `unordered_set<char>` to collect all distinct characters between positions `left+1` and `right-1`.
   - Add `set.size()` to the result — each unique middle character forms a unique palindrome.
4. **Return `res`**.

## Dry Run

**Example Input:** `s = "aabca"`

Build first/last occurrences:
- 'a': first=0, last=4
- 'b': first=2, last=2
- 'c': first=3, last=3

Process 'a' (left=0, right=4): middle chars in s[1..3] = {'a', 'b', 'c'} → contributes 3
Process 'b' (left=2, right=2): left == right, no characters between → contributes 0
Process 'c' (left=3, right=3): same → contributes 0

Total res = 3 (palindromes: "aaa", "aba", "aca")

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(26 * n) = O(n) | For each of 26 characters, scan at most n characters between first and last |
| **Space** | O(26) = O(1) | Fixed-size pair array for 26 characters; set holds at most 26 chars |
