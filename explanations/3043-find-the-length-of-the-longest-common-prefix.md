# Problem 3043 - Find the Length of the Longest Common Prefix

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
**Language:** C++

---

## Problem Statement

Given two integer arrays `arr1` and `arr2`, find the longest common prefix between any number in `arr1` and any number in `arr2` (comparing their decimal string representations). Return the length of the longest such common prefix.

## Approach: Hash Set of All Prefixes from arr1

We convert every number in `arr1` to a string and insert all its prefixes (as strings) into a hash set. Then for every number in `arr2`, we convert it to a string and check each of its prefixes against the set. Whenever a prefix is found in the set, we update the answer with that prefix's length.

This approach avoids a brute-force O(n*m) pairwise comparison by precomputing all prefixes once.

## Code Walkthrough (Step by Step)

1. **Build prefix set from arr1:** For each number `x` in `arr1`, convert to string `s`. Build cumulative prefix strings (e.g., "1", "12", "123") and insert each into hash set `st`.

2. **Query prefixes from arr2:** For each number `x` in `arr2`, convert to string `s`. Build each prefix and check if it exists in `st`. If yes, update `ans = max(ans, prefix.size())`.

3. **Return** `ans`.

## Dry Run

**Example Input:** `arr1 = [1, 10, 100]`, `arr2 = [1000]`

Prefixes from arr1:
- 1 → {"1"}
- 10 → {"1", "10"}
- 100 → {"1", "10", "100"}
- Set: {"1", "10", "100"}

Query arr2:
- 1000 → prefix "1" → in set, ans=1
        → prefix "10" → in set, ans=2
        → prefix "100" → in set, ans=3
        → prefix "1000" → not in set

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * d1 + m * d2) | n, m = array sizes; d1, d2 = max digit lengths |
| **Space** | O(n * d1) | Hash set stores all prefixes of arr1 numbers |
