# Problem 2977 - Minimum Cost to Convert String II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/minimum-cost-to-convert-string-ii/
**Language:** C++

---

## Problem Statement

Given strings `source` and `target` of equal length, and string arrays `original`, `changed`, `cost` defining multi-character substring conversions, return the minimum total cost to convert `source` into `target`. Conversions apply to substrings (not just single characters). If impossible, return `-1`.

## Approach: Dijkstra for Substring Costs + DP Over String Positions

This is significantly harder than the single-character version. Substrings of varying lengths can be converted. The solution uses:
1. **Dijkstra's algorithm** on a graph where nodes are substrings: precompute the minimum cost to convert any substring `src` to `tgt`.
2. **Dynamic programming** over positions of the string: `dp[idx]` = minimum cost to convert `source[idx:]` into `target[idx:]`.

A `validlen` set tracks only lengths that appear in the conversion rules, limiting the substrings we consider.

## Code Walkthrough (Step by Step)

1. **Build adjacency list:** For each rule `(original[i], changed[i], cost[i])`, add edge `original[i] → changed[i]` with weight `cost[i]`. Record valid lengths.

2. **Dijkstra with memoization:** `dijkstra(start, end)` returns minimum cost to convert string `start` to string `end`. Uses a min-heap and memoization via `dijkstraMemo`.

3. **DP solve:** `solve(idx)` returns minimum cost to convert `source[idx..n-1]` to `target[idx..n-1]`:
   - If `source[idx] == target[idx]`, try advancing by 1 (skip this character).
   - For each valid length `len`, extract substrings and run Dijkstra.
   - Return minimum cost over all choices.

4. **Return** `solve(0)`, or `-1` if cost equals `BIG_Value`.

## Dry Run

**Example Input:** `source="abcd"`, `target="acbe"`, `original=["ab","bc"]`, `changed=["bc","cd"]`, `cost=[1,2]`

- valid lengths: {2}
- adj: "ab"→"bc" cost 1, "bc"→"cd" cost 2
- solve(0): try substr "ab"→"bc" (dijkstra=1), then solve(2)
- solve(2): try substr "cd"→"be" (no path) → BIG_Value
- Alternatively, solve(0): source[0]=='a', target[0]=='a' → skip, solve(1)
- ... (continues until a valid path or impossible)

**Output:** `-1` or minimum total cost

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * L * D) | n positions, L valid lengths, D = Dijkstra per pair |
| **Space** | O(E + n) | Adjacency list + DP array |
