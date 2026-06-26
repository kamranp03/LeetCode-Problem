# Problem 207 - Course Schedule

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/course-schedule/
**Language:** C++

---

## Problem Statement

There are `n` courses labeled 0 to n-1. You are given an array `prerequisites` where `prerequisites[i] = [a, b]` means you must take course `b` before course `a`. Return `true` if you can finish all courses, or `false` if it is impossible (due to a circular dependency). In other words, determine if the directed graph of prerequisites contains a cycle.

## Approach: DFS Cycle Detection on Directed Graph

The key insight is that it is impossible to finish all courses if and only if there is a cycle in the prerequisite dependency graph. We model this as a directed graph: an edge from `src` to `dest` means course `src` requires course `dest`. Then we run DFS with a recursion path tracker: if we visit a node that is currently on the DFS path (i.e., it is an ancestor in the current DFS tree), a cycle exists.

## Code Walkthrough (Step by Step)

1. **Build adjacency list:** For each prerequisite `[src, dest]`, add `dest` to `adj[src]`.

2. **Initialize tracking arrays:**
   - `vis[n]`: tracks if a node has been fully processed.
   - `path[n]`: tracks if a node is on the current DFS path (recursion stack).

3. **DFS for each unvisited node:** For every node `i`, if not yet visited, call `isCycle(i, vis, path, adj)`. If it returns `true`, a cycle exists → return `false`.

4. **`isCycle` function:**
   - Mark `vis[src] = true` and `path[src] = true` (enter node).
   - For each neighbor `neigh` of `src`:
     - If `neigh` is not visited: recurse. If recursion finds a cycle, propagate `true`.
     - If `neigh` is visited AND `path[neigh]` is true: `neigh` is an ancestor in the current path → cycle found! Return `true`.
   - On exit, unmark `path[src] = false` (backtrack from current path).
   - Return `false` (no cycle through this node).

5. **Return `true`** if no cycle was found.

## Dry Run

**Example Input:** `n = 2`, `prerequisites = [[1,0]]`

- adj: `0 → []`, `1 → [0]`
- DFS from 0: vis[0]=T, path[0]=T. No neighbors. path[0]=F. → no cycle.
- DFS from 1: vis[1]=T, path[1]=T. Neighbor 0: vis[0]=T, path[0]=F → not a cycle. path[1]=F. → no cycle.
- Return `true`.

**Cycle example:** `n=2`, `prerequisites=[[1,0],[0,1]]`
- adj: `0→[1]`, `1→[0]`
- DFS from 0: visit 0 (path=[0]). Visit 1 (path=[0,1]). Neighbor 0: vis[0]=T, path[0]=T → cycle! Return `false`.

**Output:** `true` (first example)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(V + E) | Each node and edge is visited at most once in DFS |
| **Space** | O(V + E) | Adjacency list + vis/path arrays + recursion stack |
