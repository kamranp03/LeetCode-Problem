# Problem 2872 - Maximum Number of K-Divisible Components

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/maximum-number-of-k-divisible-components/
**Language:** C++

---

## Problem Statement

Given a tree with `n` nodes, each node has an integer value from `vals`. You can remove any number of edges. After removal, each connected component's sum of values must be divisible by `k`. Return the maximum number of components you can create.

## Approach: Post-Order DFS with Subtree Sum

We perform a post-order DFS (process children before parent). For each node, we compute the sum of values in its subtree modulo `k`. If this sum is `0 mod k`, the subtree itself forms a valid component — we "cut" it off (increment `components` and return `0` to parent). Otherwise, we return the remainder to be accumulated by the parent.

The key insight is that if a subtree's total value is divisible by `k`, cutting it off is always optimal (the rest of the tree's divisibility is unaffected).

## Code Walkthrough (Step by Step)

1. **Build adjacency list** from the edges array (undirected tree).

2. **DFS from node 0** with parent tracking to avoid revisiting the parent:
   - Compute `sum = values[node]`.
   - Recursively add each child's returned value to `sum`.
   - If `sum % k == 0`: increment `components` and return `0` (this subtree is a separate component).
   - Otherwise: return `sum % k` to propagate the remainder up.

3. **Return `components`** — the total number of valid k-divisible components found.

## Dry Run

**Example Input:** `n=5`, `edges=[[0,2],[1,2],[1,3],[2,4]]`, `vals=[1,8,1,4,4]`, `k=6`

Tree (rooted at 0):
```
    0(1)
     |
    2(1)
   / \
  1(8) 4(4)
  |
  3(4)
```

DFS from 0:
- Node 3: sum=4, 4%6≠0 → return 4
- Node 1: sum=8+4=12, 12%6=0 → components=1, return 0
- Node 4: sum=4, 4%6≠0 → return 4
- Node 2: sum=1+0+4=5, 5%6≠0 → return 5
- Node 0: sum=1+5=6, 6%6=0 → components=2, return 0

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each node visited once in DFS |
| **Space** | O(n) | Adjacency list and recursion stack |
