# Problem 1189 - Maximum Number of Balloons

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/maximum-number-of-balloons/
**Language:** C++

---

## Problem Statement
Given a string `text`, find the maximum number of times the word "balloon" can be formed using the characters from `text`. Each character in `text` can be used only once.

## Approach: Character Frequency Count

Count the frequency of each character in `text`. The word "balloon" requires: 1 'b', 1 'a', 2 'l's, 2 'o's, 1 'n'. The maximum number of times we can spell "balloon" is limited by the scarcest required character. Since 'l' and 'o' each appear twice in "balloon", divide their counts by 2. Return the minimum across all required character counts.

## Code Walkthrough (Step by Step)

1. **Count frequencies:** Use an `unordered_map<char, int>` to count occurrences of each character in `text`.

2. **Compute the answer:** Return `min` of:
   - `st['b']` — count of 'b'
   - `st['a']` — count of 'a'
   - `st['l'] / 2` — 'l' appears twice per "balloon"
   - `st['o'] / 2` — 'o' appears twice per "balloon"
   - `st['n']` — count of 'n'

3. Missing characters default to 0 in `unordered_map`, so no special handling needed.

## Dry Run

**Example Input:** `text = "nlaebolko"`

Frequency count:
- 'n':1, 'l':2, 'a':1, 'e':1, 'b':1, 'o':2, 'k':1

Answer = min(1, 1, 2/2, 2/2, 1) = min(1, 1, 1, 1, 1) = 1

**Output:** `1`

**Example Input:** `text = "loonbalxballpoon"`

- 'b':2, 'a':2, 'l':4, 'o':4? (l:3, o:4)
- count: b=2,a=2,l=3,o=4,n=2
- min(2, 2, 3/2=1, 4/2=2, 2) = 1

**Output:** `2`... let me recount: "loonbalxballpoon" → l:4,o:4,n:2,b:2,a:2,x:1,p:1 → min(2,2,4/2=2,4/2=2,2)=2

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single pass to build frequency map |
| **Space** | O(1) | Map holds at most 26 characters |
