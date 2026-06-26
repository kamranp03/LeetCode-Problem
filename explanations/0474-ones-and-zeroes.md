# Problem 474 - Ones and Zeroes

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/ones-and-zeroes/
**Language:** C++

---

## Problem Statement
Given an array of binary strings `strs` and integers `m` and `n`, find the maximum number of strings from `strs` you can form using at most `m` zeros and `n` ones. Each string can only be used once.

## Approach: 3D Dynamic Programming with Memoization (Top-Down)

This is a 0/1 knapsack problem in 2D: we have two resources (zeros budget `m` and ones budget `n`) and must decide for each string whether to take it or skip it. The recursive function `solve(count, m, n, i)` returns the maximum strings we can pick from index `i` onwards given `m` zeros and `n` ones remaining. Results are cached in a 3D memoization table `t[m][n][i]`.

## Code Walkthrough (Step by Step)

1. **Preprocessing:** For each string in `strs`, count its zeros (`cZ`) and ones (`cO`). Store as pairs in `count`.

2. **Memoization table:** `t[101][101][601]` is initialized to -1. Dimensions are `m+1` by `n+1` by `size+1`.

3. **`solve(count, m, n, i)` — recursive function:**
   - **Base case:** If `i >= count.size()` or both `m == 0` and `n == 0`, return 0.
   - **Cache hit:** If `t[m][n][i] != -1`, return cached value.
   - **Take:** If `count[i].first <= m` AND `count[i].second <= n`, we can take string `i`. Gain 1 + recurse with reduced budgets.
   - **Skip:** Always an option — recurse with same budgets, advance `i`.
   - **Return** `max(take, skip)` and cache it.

4. **Entry point:** Initialize `t` with `memset`, precompute `count`, call `solve(count, m, n, 0)`.

## Dry Run

**Example Input:** `strs = ["10","0001","111001","1","0"]`, `m = 5`, `n = 3`

Count pairs: [(1,1), (3,1), (2,4), (0,1), (1,0)]

Starting `solve(count, 5, 3, 0)`:
- String "10" (1 zero, 1 one): take → solve(4,2,1) or skip → solve(5,3,1)
- At each step we choose max between taking and skipping, working down to base cases

The optimal solution picks "10","0001","1","0" → 4 strings using 5 zeros, 3 ones.

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m × n × L) | L = number of strings; each unique (m, n, i) state computed once |
| **Space** | O(m × n × L) | Memoization table size; plus O(L) recursion stack |
