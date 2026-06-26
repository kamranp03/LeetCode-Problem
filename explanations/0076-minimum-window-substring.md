# Problem 76 - Minimum Window Substring

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/minimum-window-substring/
**Language:** C++

---

## Problem Statement

Given two strings `s` and `t`, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return an empty string `""`. The answer is guaranteed to be unique when it exists.

## Approach: Sliding Window with Frequency Arrays

The key insight is to use a variable-size sliding window over string `s`. We expand the right boundary to include characters, and whenever the current window satisfies all character requirements (contains every character of `t` with sufficient frequency), we try to shrink from the left to minimize the window size. Two frequency arrays of size 256 track what characters we "need" and what we currently "have".

## Code Walkthrough (Step by Step)

1. **Build the `need` array:** Iterate over string `t` and count how many times each character is needed. `need[t[i]]++` for every character in `t`.

2. **Expand the window with `high`:** Move the right pointer `high` across `s`, adding each character to the `have` array: `have[s[high]]++`.

3. **Check if window is valid (`fun`):** The helper function `fun` loops over all 256 ASCII slots and returns `true` only if `have[i] >= need[i]` for every slot — meaning the window currently covers all requirements.

4. **Shrink from the left:** While `fun` returns `true`, compute the window length `high - low + 1`. If it is smaller than the current best (`res`), record this length and starting index. Then shrink: decrement `have[s[low]]` and advance `low`.

5. **Return the result:** After scanning, if `res` was never updated it remains `INT_MAX`, so return `""`. Otherwise return `s.substr(start, res)`.

## Dry Run

**Example Input:** `s = "ADOBECODEBANC"`, `t = "ABC"`

- `need`: A=1, B=1, C=1
- Expand right until window `"ADOBEC"` (indices 0-5): `have` satisfies `need`.
  - Window length = 6, `res=6`, `start=0`. Shrink left → remove 'A', `low=1`.
  - Window `"DOBEC"` fails (no A). Stop shrinking.
- Continue expanding... at index 9 window `"DOBECODEBA"` add 'A'.
  - `have` satisfies need again. Window = `"DOBECODEBA"` → length 10 > 6, no update. Shrink left.
  - Keep shrinking: `"OBECODEBA"`, `"BECODEBA"`, `"ECODEBA"`, `"CODEBA"` — check each. `"CODEBA"` length 6, no improvement. Remove 'C' → `"ODEBA"` fails.
- At index 12 add 'C'. Window `"ODEBANC"` satisfies. Length=7 > 6, no improvement. Shrink: remove 'O' `"DEBANC"` satisfies length=6 no improvement. Remove 'D' `"EBANC"` satisfies length=5 < 6 → `res=5`, `start=8`. Remove 'E' → `"BANC"` length=4 < 5 → `res=4`, `start=9`. Remove 'B' → `"ANC"` — no B, fails.

**Output:** `"BANC"`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(256 * n) = O(n) | Each character is added/removed at most once; `fun` scans 256 slots each call |
| **Space** | O(256) = O(1) | Two fixed-size frequency arrays of size 256 |
