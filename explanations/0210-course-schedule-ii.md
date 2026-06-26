# Problem 210 - Course Schedule II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/course-schedule-ii/
**Language:** C++

---

## Problem Statement
Given `n` courses labeled `0` to `n-1` and a list of prerequisite pairs, return the ordering in which you should take the courses to finish all of them. If it is impossible to finish all courses (due to a cycle), return an empty array.

## Approach: DFS Cycle Detection + Topological Sort

The key insight is that a valid course ordering is a topological sort of a directed graph where each edge `[a, b]` means "b must be taken before a". If the graph contains a cycle, no valid ordering exists. We first check for cycles using DFS path tracking, then perform a DFS-based topological sort by pushing each node onto a stack after all its neighbors are visited.

## Code Walkthrough (Step by Step)

1. **Build adjacency list:** For each prerequisite pair `[dest, src]`, add an edge `src -> dest` (if src must come before dest).

2. **Cycle detection (`isCycle`):** Run DFS from every unvisited node. Maintain two arrays — `vis` (globally visited) and `path` (nodes on the current DFS path). If we reach a node that is already on the current path, a cycle exists. After exploring all neighbors of a node, remove it from the path (`path[src] = false`).

3. **If a cycle is found:** Return an empty result immediately.

4. **Reset `vis`** and run topological sort.

5. **Topological sort (`topo`):** Standard DFS post-order. Push each node onto a stack only after all its neighbors have been fully explored.

6. **Build result:** Pop all elements from the stack into the result vector — this gives the correct ordering (prerequisites first).

## Dry Run

**Example Input:** `n = 4`, `prerequisites = [[1,0],[2,0],[3,1],[3,2]]`

Build adjacency list:
- `0 -> [1, 2]`
- `1 -> [3]`
- `2 -> [3]`

Cycle check: No cycles found.

Topological DFS (from node 0):
- Visit 0 -> Visit 1 -> Visit 3 -> push 3 -> back to 1 -> push 1 -> back to 0 -> Visit 2 -> (3 already visited) -> push 2 -> push 0

Stack (top to bottom): `0, 2, 1, 3`

Result after popping: `[0, 2, 1, 3]`

**Output:** `[0, 2, 1, 3]` (one valid ordering)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(V + E) | Each node and edge is visited once during cycle detection and once during topological sort |
| **Space** | O(V + E) | Adjacency list, visited arrays, and recursion stack |
