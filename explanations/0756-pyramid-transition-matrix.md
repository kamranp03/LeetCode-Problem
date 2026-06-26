# Problem 756 - Pyramid Transition Matrix

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/pyramid-transition-matrix/
**Language:** C++

---

## Problem Statement
Given a bottom row string and a list of allowed triples, determine whether it is possible to build a full pyramid by stacking rows where each pair of adjacent characters from a lower row produces one character on the row above it. Each allowed triple "ABC" means characters A and B can produce character C. Return true if the pyramid can be completed.

## Approach: DFS with Memoization (Backtracking + Top-Down DP)

The key insight is to build the pyramid row by row. For each row, iterate through all consecutive pairs and try every valid character that can be placed above that pair (using the allowed map). When one row is fully built, recurse to build the row above it. Memoization caches (current_row, current_index, partial_above_row) states to avoid recomputation.

## Code Walkthrough (Step by Step)

1. **Preprocessing:** Build a map from every two-character prefix to a list of characters that can sit above it (from the allowed triples).

2. **`solve(curr, mp, idx, above)` function:**
   - If `curr` has length 1, the pyramid is complete — return `true`.
   - Build a memoization key from `curr`, `idx`, and `above`.
   - If `idx == curr.length()-1`, the `above` row is complete — recurse with `above` as the new bottom and reset `idx=0`.
   - Look up the pair `curr[idx..idx+1]` in the map. If missing, return `false`.
   - Try every candidate character for `above`, append it, recurse, and backtrack if it fails.

3. **Main function:** Call `solve(bottom, mp, 0, "")`.

## Dry Run

**Example Input:** `bottom = "BCD"`, `allowed = ["BCG","CDB","DBB","GCB"]`

- Map: "BC"->['G'], "CD"->['B'], "DB"->['B'], "GC"->['B']
- Row "BCD": pair "BC"->'G', pair "CD"->'B' → row above = "GB"
- Row "GB": pair "GB" not in map → false
- Backtrack, no other options → return false

**Output:** `false`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N * 7^N) | At each position up to 7 characters possible; memoization prunes many branches |
| **Space** | O(N^2) | Memoization table stores string-based keys for each pyramid level |
