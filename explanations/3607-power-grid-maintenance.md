# Problem 3607 - Power Grid Maintenance

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/power-grid-maintenance/
**Language:** C++

---

## Problem Statement

Given `c` power grid nodes connected by undirected edges (forming connected components), process two types of queries: type 1 — find the smallest node ID still active in the same component as the given node; type 2 — deactivate the given node (remove it from its component's active set). Return answers to all type-1 queries.

## Approach: DFS for Component Identification + Ordered Set per Component

Use DFS to identify connected components and assign each node to a component. Each component maintains an ordered `set<int>` of active nodes. For type-1 queries, check if the node itself is still in the set (return it) or return the smallest element in the set. For type-2 queries, erase the node from its component's set.

## Code Walkthrough (Step by Step)

1. **Build adjacency list** from connections.
2. **DFS:** visit each unvisited node, assign it a component ID (the ID of the first node that started the DFS of that component), add to `mp[id]`.
3. **Process queries:**
   - Type 1: get component ID of `node`. If `node` is still in `mp[id]`, return `node`. Otherwise return `*mp[id].begin()` (smallest active node in that component).
   - Type 2: erase `node` from `mp[nodeId[node]]`.
4. **Return** results of all type-1 queries.

## Dry Run

**Example Input:** `c=4`, connections=`[[1,2],[3,4]]`, queries=`[[1,1],[2,1],[1,1]]`

- Components: {1,2} with id=1; {3,4} with id=3.
- Query [1,1]: node=1, in mp[1]={1,2}? Yes → return 1.
- Query [2,1]: deactivate 1. mp[1]={2}.
- Query [1,1]: node=1, in mp[1]={2}? No → return *begin = 2.

**Output:** `[1, 2]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O((c + edges) + q log c) | DFS for components; q queries each O(log c) |
| **Space** | O(c + edges) | Adjacency list, visited array, sets |
