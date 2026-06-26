# Problem 1306 - Jump Game III

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/jump-game-iii/
**Language:** C++

---

## Problem Statement

Given an array of non-negative integers `arr` and a `start` index, you can jump from index `i` to either `i + arr[i]` or `i - arr[i]`. Return `true` if you can reach any index with value 0, starting from `start`, otherwise return `false`.

## Approach: DFS with Visited Array

The key insight is to model this as a graph traversal problem. Each index is a node, and the two possible jumps are edges. We do a DFS from `start`, marking visited nodes to avoid cycles, and stop as soon as we reach an index with value 0.

## Code Walkthrough (Step by Step)

1. **Base cases:** If index `i` is out of bounds, return false. If already visited (`vis[i] == 1`), return false (cycle detected). If `arr[i] == 0`, return true (goal reached).
2. **Mark visited:** Set `vis[i] = 1` to prevent revisiting.
3. **Recurse:** Try both jumps — to `i + arr[i]` and `i - arr[i]`. Return true if either branch succeeds.
4. **Main function:** Initialize the `vis` array of zeros, then call `dfs(arr, start, vis)`.

## Dry Run

**Example Input:** `arr = [4,2,3,0,3,1,2]`, `start = 5`

- dfs(5): arr[5]=1, jump to 6 or 4; mark vis[5]=1
- dfs(6): arr[6]=2, jump to 8 (out of bounds) or 4; mark vis[6]=1
- dfs(4): arr[4]=3, jump to 7 (out of bounds) or 1; mark vis[4]=1
- dfs(1): arr[1]=2, jump to 3 or -1 (OOB); mark vis[1]=1
- dfs(3): arr[3]=0 → return **true**

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each index is visited at most once |
| **Space** | O(n) | Visited array + recursion call stack |
