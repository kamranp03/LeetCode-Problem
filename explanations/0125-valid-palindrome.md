# Problem 125 - Valid Palindrome

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/valid-palindrome/
**Language:** C++

---

## Problem Statement

A phrase is a palindrome if, after converting all uppercase letters to lowercase and removing all non-alphanumeric characters, it reads the same forward and backward. Given a string `s`, return `true` if it is a palindrome, or `false` otherwise. Alphanumeric characters include letters and numbers.

## Approach: Filter then Two-Pointer Check

The key insight is to first clean the string — keep only alphanumeric characters and convert them to lowercase — and then use the classic two-pointer palindrome check. One pointer starts at the front and one at the back; if all corresponding characters match as the pointers converge, the string is a palindrome.

## Code Walkthrough (Step by Step)

1. **Filter the string:** Iterate over every character `ch` in `s`. Use `isalnum(ch)` to check if it is a letter or digit. If so, convert it to lowercase with `tolower(ch)` and append it to the new string `ss`.

2. **Set up two pointers:** `i = 0` (left pointer, start of `ss`) and `j = ss.size() - 1` (right pointer, end of `ss`).

3. **Compare from both ends:** While `i < j`:
   - If `ss[i] != ss[j]`, the characters don't match — return `false`.
   - Otherwise, move both pointers inward: `i++`, `j--`.

4. **Return `true`:** If the loop completes without a mismatch, the string is a palindrome.

## Dry Run

**Example Input:** `s = "A man, a plan, a canal: Panama"`

- After filtering and lowercasing: `ss = "amanaplanacanalpanama"`
- Two pointers:
  - i=0 'a', j=19 'a' → match, i=1, j=18
  - i=1 'm', j=18 'm' → match, i=2, j=17
  - i=2 'a', j=17 'a' → match, ...
  - ... all characters match until i >= j.

**Output:** `true`

**Counter Example:** `s = "race a car"` → `ss = "raceacar"`
- i=0 'r', j=7 'r' → match
- i=1 'a', j=6 'a' → match
- i=2 'c', j=5 'c' → match
- i=3 'e', j=4 'a' → mismatch → return `false`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | One pass to filter + one pass to check, both O(n) |
| **Space** | O(n) | Filtered string `ss` can be up to length n |
