# Problem 865 - Smallest Subtree with all the Deepest Nodes

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
**Language:** C++

---

## Problem Statement
Given a binary tree, find the smallest subtree that contains all the deepest nodes. The deepest nodes are those at the maximum depth in the tree. Return the root of the smallest subtree that has all deepest leaves as descendants.

## Approach: DFS Returning (Depth, Node) Pairs

The key insight is: for any node, if its left and right subtrees have the same maximum depth, then this node is the LCA (lowest common ancestor) of all deepest leaves in its subtree — it is the answer for this subtree. If one side is deeper, the answer lies entirely in that deeper subtree. A single post-order DFS propagates both depth and the candidate node upward simultaneously.

## Code Walkthrough (Step by Step)

1. **Base case:** If `root == NULL`, return `{0, NULL}` — depth 0, no node.

2. **Recurse** on both children to get `(left_depth, left_node)` and `(right_depth, right_node)`.

3. **Compare depths:**
   - If `left.first == right.first`: both subtrees are equally deep. The current `root` is the LCA of all deepest leaves in this subtree. Return `{left.first + 1, root}`.
   - If `left.first > right.first`: deepest leaves are all in the left subtree. Return `{left.first + 1, left.second}`.
   - If `right.first > left.first`: deepest leaves are all in the right subtree. Return `{right.first + 1, right.second}`.

4. **Call** `dfs(root)` and return the `.second` (node) from the result.

## Dry Run

**Example Input:**
```
        3
       / \
      5   1
     / \
    6   2
```
- dfs(6) = {1, node6}, dfs(2) = {1, node2}
- dfs(5): left=1, right=1 equal → return {2, node5}
- dfs(1) = {1, node1}
- dfs(3): left=2, right=1, left deeper → return {3, node5}

**Output:** node with value `5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Each node visited exactly once in post-order DFS |
| **Space** | O(H) | Recursion stack depth equals tree height H |
