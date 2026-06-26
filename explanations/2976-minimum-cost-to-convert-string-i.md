# Problem 2976 - Minimum Cost to Convert String I

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-cost-to-convert-string-i/
**Language:** C++

---

## Problem Statement

Given strings `source` and `target` of equal length, and arrays `original`, `changed`, `cost` defining single-character conversions with associated costs, return the minimum total cost to convert `source` into `target`. If conversion is impossible for any character, return `-1`.

## Approach: Floyd-Warshall All-Pairs Shortest Path on 26 Characters

We model the 26 lowercase letters as nodes in a weighted directed graph. Each conversion rule `(original[i], changed[i], cost[i])` is a directed edge. We apply **Floyd-Warshall** to compute the minimum cost to convert any letter `a` to any letter `b` (possibly via intermediate letters). Then for each position where `source[i] != target[i]`, we look up the precomputed minimum cost.

## Code Walkthrough (Step by Step)

1. **Build adjacency matrix:** Initialize a 26x26 matrix `adjMat` with `INT_MAX`. For each conversion rule, update `adjMat[s][t] = min(adjMat[s][t], cost[i])` (keep cheapest direct conversion).

2. **Floyd-Warshall:** For every intermediate letter `k`, update `adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j])`. After this, `adjMat[i][j]` holds the minimum cost to convert letter `i` to letter `j`.

3. **Compute answer:** Scan source and target. If `source[i] == target[i]`, skip (no cost). Otherwise, if `adjMat[source[i]-'a'][target[i]-'a'] == INT_MAX`, return `-1`. Else add the cost to `ans`.

4. **Return** `ans`.

## Dry Run

**Example Input:** `source="abcd"`, `target="acbe"`, `original=['a','b','c','c']`, `changed=['b','c','b','e']`, `cost=[2,5,5,2]`

After Floyd-Warshall, min costs include:
- a→b: 2, a→c: 7, a→e: 9
- b→c: 5, c→b: 5, c→e: 2

Position costs:
- a→a: 0, b→c: 5, c→b: 5, d→e: impossible → return -1

Wait, let's use a simpler example. `source="ab"`, `target="ba"`, with rules a→b cost 1, b→a cost 2.
- adjMat[a][b]=1, adjMat[b][a]=2. Answer = 1+2 = 3.

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(26^3 + n) | Floyd-Warshall on 26 nodes + one pass over string |
| **Space** | O(26^2) | The adjacency matrix |
