# Problem 0017 - Letter Combinations of a Phone Number

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/letter-combinations-of-a-phone-number/
**Language:** C++

---

## Problem Statement

Given a string `digits` containing digits from 2–9, return all possible letter combinations that the number could represent on a phone keypad (like T9). Return the answer in any order. If `digits` is empty, return an empty list.

## Approach: Backtracking (Recursive DFS)

The key insight is that at each position `idx` in the digit string, we have a fixed set of choices (the letters mapped to that digit). We build the combination character by character using recursion: add one letter at the current position, recurse for the next position, then remove the letter (backtrack) and try the next letter. This explores all combinations systematically.

## Code Walkthrough (Step by Step)

1. **Map each digit** to its phone letters using an `unordered_map<char, string> f`.
2. **Recursive function `phone(digits, n, idx, diary, res)`:**
   - **Base case:** if `idx == n`, we've filled all positions — push `diary` into `res` and return.
   - **Get choices:** `choice = f[digits[idx]]` — the letters for the current digit.
   - **Loop through each letter** in `choice`:
     - Push the letter onto `diary`.
     - Recurse with `idx+1`.
     - Pop the letter from `diary` (backtrack).
3. **`letterCombinations`** initializes an empty `diary` and calls `phone` starting at `idx=0`.

## Dry Run

**Example Input:** `digits = "23"`

Digit map: '2' → "abc", '3' → "def"

```
phone(idx=0): choices = "abc"
  take 'a' → diary="a"
    phone(idx=1): choices = "def"
      take 'd' → diary="ad" → push "ad"
      take 'e' → diary="ae" → push "ae"
      take 'f' → diary="af" → push "af"
  take 'b' → diary="b"
    → push "bd", "be", "bf"
  take 'c' → diary="c"
    → push "cd", "ce", "cf"
```

**Output:** `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(4^n × n) | At most 4 letters per digit; n digits; each combination has length n |
| **Space** | O(n) | Recursion depth equals the number of digits; diary string is length n |
