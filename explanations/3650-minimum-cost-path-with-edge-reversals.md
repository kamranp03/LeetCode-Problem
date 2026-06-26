# Problem 3650 - Minimum Cost Path with Edge Reversals

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
**Language:** C++

---

## Problem Statement

Given a directed weighted graph of `n` nodes, find the minimum cost path from node 0 to node `n-1`. You can traverse any edge in its original direction at cost `w`, or reverse it and traverse it at cost `2w`. Return the minimum total cost, or -1 if unreachable.

## Approach: Modified Dijkstra with Two Edge Weights

Model the graph as follows: for each original directed edge `(u, v, w)`:
- Add a forward edge `u → v` with cost `w` (use as-is).
- Add a reverse edge `v → u` with cost `2w` (reversing the edge).

Then run standard Dijkstra from node 0 to find the shortest path to node `n-1`.

## Code Walkthrough (Step by Step)

1. **Build adjacency list:** for each edge `(u, v, w)`, add `u→v` with weight `w` and `v→u` with weight `2w`.
2. **Dijkstra** from node 0: use a min-heap priority queue `(cost, node)`.
3. **Initialize** `ans[0]=0`, all others `INT_MAX`.
4. **Process** each node: for each neighbor, if `weight + dist < ans[nd]`, update and push to queue.
5. **Return** `ans[n-1]`, or -1 if still `INT_MAX`.

## Dry Run

**Example Input:** `n=3`, `edges=[[0,1,1],[1,2,2]]`

- Build: 0→1 (w=1), 1→0 (w=2), 1→2 (w=2), 2→1 (w=4).
- Dijkstra from 0: dist[0]=0. Process 0 → dist[1]=1. Process 1 → dist[2]=3. Process 2 (done).
- ans[2]=3.

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O((n + E) log n) | Dijkstra with priority queue |
| **Space** | O(n + E) | Adjacency list and distance array |
