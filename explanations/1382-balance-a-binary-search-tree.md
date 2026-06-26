# Problem 1382 - Balance a Binary Search Tree

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/balance-a-binary-search-tree/
**Language:** C++

---

## Problem Statement

Given the root of a binary search tree (BST), return a balanced BST with the same node values. A balanced BST is one where the depth of the two subtrees of every node never differs by more than 1. If there is more than one answer, return any of them.

## Approach: Inorder Traversal + Build from Sorted Array

The key insight is that an inorder traversal of a BST produces a sorted array. Once we have a sorted array, we can build a height-balanced BST by always picking the middle element as the root — this ensures the left and right subtrees have equal (or near-equal) sizes.

## Code Walkthrough (Step by Step)

1. **`storeInorder(root, nodes)`:** Performs an inorder (left → node → right) traversal of the BST and appends each node's value to the `nodes` vector. The result is a sorted array.
2. **`buildBalancedTree(nodes, start, end)`:** Recursively builds a balanced BST from the sorted slice `[start, end]`.
   - Base case: if `start > end`, return `nullptr`.
   - Pick `mid = (start + end) / 2` as the root.
   - Recursively build left subtree from `[start, mid-1]` and right from `[mid+1, end]`.
3. **`balanceBST(root)`:** Orchestrates both steps — stores inorder values, then builds and returns the balanced tree.

## Dry Run

**Example Input:** Skewed BST: 1 → 2 → 3 → 4 (right-skewed)

- Inorder: `[1, 2, 3, 4]`
- Build: mid=1 (value 2), left from [0,0] (value 1), right from [2,3]
  - Right mid=2 (value 3), right-right from [3,3] (value 4)
- Result: balanced tree with 2 as root, 1 as left, 3 as right, 4 as right of 3

**Output:** Balanced BST

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Inorder traversal O(n) + build O(n) |
| **Space** | O(n) | Sorted array of n nodes + recursion stack |
