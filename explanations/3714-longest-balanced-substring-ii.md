# Problem 3714 - Longest Balanced Substring II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/longest-balanced-substring-ii/
**Language:** C++

---

## Problem Statement

Given a string `s` containing only 'a', 'b', and 'c', find the length of the longest substring where every character that appears has the same frequency. Handle the larger constraints efficiently.

## Approach: Case Analysis with Prefix Difference Maps

Split into cases based on which characters appear in the balanced substring:

1. **Single character runs:** e.g., "aaaa" — find the longest run of identical characters.
2. **Two-character pairs (a,b), (a,c), (b,c):** for each pair, use a sliding window with prefix count difference. If `cnt1 - cnt2 == 0` the substring is balanced. Store first occurrence of each difference using a hash map; when seen again, the range between them is balanced.
3. **All three characters (a,b,c):** Track `cntA`, `cntB`, `cntC`. Balance requires `cntA == cntB == cntC`. Use a 2D difference key `(cntA-cntB, cntA-cntC)` stored in a map; when seen again, the range is balanced. Also handle the case where all three counts are equal directly.

## Code Walkthrough (Step by Step)

1. **Case 1:** scan for max run of same character. Update `maxL`.
2. **Case 2:** call `helper(s, ch1, ch2)` for each of the 3 pairs. The helper resets on encountering any character outside the pair.
3. **Case 3:** sweep once tracking `cntA`, `cntB`, `cntC`. Use string key `"difAB_difAC"` in a map. Update maxL when key repeats or all three counts equal.
4. **Return** `maxL`.

## Dry Run

**Example Input:** `s = "aabbc"`

- Case 1: max run = 2 ("aa" or "bb").
- Case 2 (a,b): cntA=cntB=2 at i=3, maxL=4.
- Case 3 (a,b,c): cntA=cntB=1,cntC=1 at some prefix. Key "0_0" → maxL=3.

**Output:** `4` (substring "aabb")

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each of the 4 cases is a single linear scan |
| **Space** | O(n) | Hash maps storing prefix differences |
