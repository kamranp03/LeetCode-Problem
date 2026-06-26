# Problem 1123 - Lowest Common Ancestor of Deepest Leaves

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
**Language:** C++

---

## Problem Statement
Given the root of a binary tree, find the lowest common ancestor (LCA) of all the deepest leaves. The deepest leaves are those at the maximum depth. The LCA is the deepest node that has all deepest leaves as descendants (or is one itself).

## Approach: DFS Returning (Depth, Node) Pairs

This problem is identical in logic to problem 865. A post-order DFS returns a pair `(max_depth_in_subtree, lca_node)`. The key rules are:
- If both subtrees have equal depth, the current node is the LCA for all deepest leaves in its subtree.
- If one subtree is deeper, the LCA is inherited from that deeper subtree.

This elegantly finds the LCA in a single traversal.

## Code Walkthrough (Step by Step)

1. **Base case:** `dfs(NULL)` returns `{0, NULL}`.

2. **Recurse** on both children to get `(left_depth, left_lca)` and `(right_depth, right_lca)`.

3. **Decision at each node:**
   - **`left.first == right.first`:** Deepest leaves are equally deep on both sides — current node is the LCA. Return `{left.first + 1, root}`.
   - **`left.first > right.first`:** All deepest leaves are in left subtree — LCA is `left.second`. Return `{left.first + 1, left.second}`.
   - **`right.first > left.first`:** All deepest leaves are in right subtree — LCA is `right.second`. Return `{right.first + 1, right.second}`.

4. **Return** `dfs(root).second`.

## Dry Run

**Example Input:**
```
    3
   / \
  5   1
 / \
6   2
   / \
  7   4
```
- dfs(7)={1,7}, dfs(4)={1,4}
- dfs(2): left=right=1 → {2, node2}
- dfs(6)={1,6}
- dfs(5): left=1 (from 6), right=2 (from 2). right deeper → {3, node2}
- dfs(1)={1,1}
- dfs(3): left=3, right=1. left deeper → {4, node2}

**Output:** Node with value `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single post-order DFS visiting every node once |
| **Space** | O(H) | Call stack depth equals tree height |
