# Problem 1339 - Maximum Product of Splitted Binary Tree

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, split it into two non-empty subtrees by removing one edge. Return the maximum product of the sums of the two resulting subtrees, modulo 10^9 + 7. The product is maximized before taking the modulo.

## Approach: Two-Pass DFS (Total Sum + Subtree Sums)

The key insight is that when we cut any edge, one part has sum `subTree` and the other has sum `total - subTree`. The product is `subTree * (total - subTree)`. We first compute the total sum of the tree, then do a DFS to compute every possible subtree sum and track the maximum product.

## Code Walkthrough (Step by Step)

1. **`getTotal(root)`:** Recursively sums all node values to get the full tree sum `total`.
2. **`dfs(root)`:** Post-order traversal. For each node, compute `subTree = node->val + leftSum + rightSum`.
3. **Compute product:** `product = subTree * (total - subTree)` and update `maxP`.
4. **Return subtree sum** up the call stack so parent nodes can use it.
5. **`maxProduct(root)`:** Call `getTotal`, then `dfs`, and return `maxP % MOD`.

## Dry Run

**Example Input:** Tree with values `[1,2,3,4,5,6]`

- Total sum = 1+2+3+4+5+6 = 21
- Subtree rooted at node 2 (with 4,5): subTree = 2+4+5 = 11 → product = 11 * (21-11) = 11*10 = 110
- Subtree rooted at node 3 (with 6): subTree = 3+6 = 9 → product = 9*12 = 108
- Maximum product = **110**

**Output:** `110`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two full DFS traversals of the tree |
| **Space** | O(h) | Recursion stack where h is tree height |
