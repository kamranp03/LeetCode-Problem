# Problem 236 - Lowest Common Ancestor of a Binary Tree

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
**Language:** C++

---

## Problem Statement
Given a binary tree and two nodes `p` and `q`, find their lowest common ancestor (LCA). The LCA is defined as the deepest node that has both `p` and `q` as descendants (a node can be a descendant of itself).

## Approach: DFS Count-Based LCA

The key insight is to count how many of the target nodes (`p` and `q`) are present in each subtree. A node is the LCA when the total count reaching it equals 2 for the first time. The helper `lca()` returns the count of target nodes found in the subtree rooted at the current node (0, 1, or 2). When the count hits 2 and `ans` hasn't been set yet, the current node is the LCA.

## Code Walkthrough (Step by Step)

1. **Base case:** If `root == NULL`, return 0 (no targets found here).

2. **Recurse left and right:** Get counts from left subtree (`left`) and right subtree (`right`).

3. **Check self:** `self = 1` if the current node is `p` or `q`, else 0.

4. **Compute total:** `total = left + right + self`.

5. **Check if LCA:** If `total == 2` and `ans` is not yet set, this node is the LCA. Set `ans = root`.

6. **Return total** for the parent to accumulate.

7. **Entry point `lowestCommonAncestor`:** Calls `lca(root, p, q)` and returns the stored `ans`.

## Dry Run

**Example Input:**
```
        3
       / \
      5   1
     / \
    6   2
```
`p = 5`, `q = 1`

- lca(6): left=0, right=0, self=0 → return 0
- lca(2): left=0, right=0, self=0 → return 0
- lca(5): left=0, right=0, self=1 (5==p) → total=1 → return 1
- lca(1): left=0, right=0, self=1 (1==q) → total=1 → return 1
- lca(3): left=1 (from 5), right=1 (from 1), self=0 → total=2 → ans=3 → return 2

**Output:** Node 3

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Every node is visited exactly once |
| **Space** | O(h) | Recursion stack height equals tree height; O(n) worst case |
