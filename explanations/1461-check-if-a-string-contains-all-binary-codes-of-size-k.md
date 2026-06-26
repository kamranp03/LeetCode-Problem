# Problem 1461 - Check If a String Contains All Binary Codes of Size K

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
**Language:** C++

---

## Problem Statement

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. There are `2^k` possible binary codes of length `k`.

## Approach: Sliding Window with Hash Set

The key insight is to extract all substrings of length `k` from `s` and insert them into an unordered_set. Since the set only stores unique strings, at the end we just check if the set size equals `2^k` (all possible binary codes of length k are present).

## Code Walkthrough (Step by Step)

1. **Edge case:** If `s.size() < k`, it's impossible to have any length-k substring, return `false`.
2. **Sliding window:** Iterate `i` from 0 to `s.size() - k` (inclusive), extracting each substring `s.substr(i, k)` of length `k`.
3. **Insert into set `st`** — duplicates are automatically ignored.
4. **Final check:** Return `st.size() == (1 << k)`. `1 << k` equals `2^k`, the total number of distinct binary strings of length k.

## Dry Run

**Example Input:** `s = "00110110"`, `k = 2`

- Substrings of length 2: "00", "01", "11", "11", "10", "11", "10"
- Set: {"00", "01", "11", "10"} → size = 4
- 2^2 = 4 → 4 == 4 → **true**

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * k) | n substrings of length k each inserted into set |
| **Space** | O(2^k * k) | Set stores up to 2^k strings of length k |
