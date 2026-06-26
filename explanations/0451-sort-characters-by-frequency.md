# Problem 451 - Sort Characters By Frequency

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/sort-characters-by-frequency/
**Language:** C++

---

## Problem Statement
Given a string `s`, sort its characters in decreasing order based on their frequency of occurrence. Return the sorted string. If two characters have the same frequency, their relative order in the output does not matter.

## Approach: Hash Map + Custom Sort + Repeat Build

The key insight is to count character frequencies with a hash map, sort the characters by their counts in descending order, then reconstruct the string by repeating each character the number of times it appears. This is straightforward and easy to implement.

## Code Walkthrough (Step by Step)

1. **Count frequencies:** Build `unordered_map<char, int> freq` by iterating over every character in `s`.

2. **Convert to vector of pairs:** Copy the map into `vector<pair<char, int>> v` so it can be sorted.

3. **Sort by frequency (descending):** Use a lambda comparator that compares on `second` (the frequency) in descending order: `a.second > b.second`.

4. **Build result string:** For each pair `(char, count)` in the sorted vector, append the character repeated `count` times using `string(p.second, p.first)`.

5. **Return the result string.**

## Dry Run

**Example Input:** `s = "tree"`

Frequency map: `{t:1, r:1, e:2}`

Vector of pairs: `[(t,1), (r,1), (e,2)]`

After sorting by frequency descending: `[(e,2), (t,1), (r,1)]` (t and r tie — either order is valid)

Build result:
- (e, 2) → "ee"
- (t, 1) → "t"
- (r, 1) → "r"

**Output:** `"eetr"` (or `"eertr"` — any ordering of tied characters is accepted)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n + k log k) | O(n) to count, O(k log k) to sort k unique characters, O(n) to build result |
| **Space** | O(k) | Map and vector store at most k unique characters (k ≤ 26 for lowercase) |
