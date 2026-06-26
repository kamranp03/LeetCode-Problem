# Problem 94 - Binary Tree Inorder Traversal

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-tree-inorder-traversal/
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, return the inorder traversal of its nodes' values as a vector. Inorder traversal visits nodes in the order: Left subtree → Root → Right subtree.

## Approach: Recursive DFS (Inorder)

The key insight is that inorder traversal has a natural recursive structure: to traverse a tree, first traverse its entire left subtree, then record the root's value, then traverse the entire right subtree. A helper function carries the result vector by reference so that all recursive calls share the same accumulator.

## Code Walkthrough (Step by Step)

1. **Public entry point `inorderTraversal`:** Create an empty `res` vector and call the helper `inorderPrint(root, res)`. Return whatever the helper returns (which is the same `res` vector).

2. **Helper function `inorderPrint`:**
   - **Base case:** If `root == NULL`, the subtree is empty — return `res` immediately without adding anything.
   - **Go left:** Recurse on `root->left` to visit the entire left subtree first.
   - **Visit root:** Push `root->val` into `res`. This happens after the full left subtree is processed.
   - **Go right:** Recurse on `root->right` to visit the entire right subtree.
   - **Return `res`:** Return the accumulated result vector.

3. The `res` vector is passed by reference (`vector<int>& res`), so all recursive calls append to the same vector in the correct inorder sequence.

## Dry Run

**Example Input:**
```
    1
     \
      2
     /
    3
```

- `inorderPrint(1, res)`:
  - `inorderPrint(NULL, res)` → returns (left of 1 is null)
  - Push 1 → `res = [1]`
  - `inorderPrint(2, res)`:
    - `inorderPrint(3, res)`:
      - `inorderPrint(NULL, res)` → returns
      - Push 3 → `res = [1, 3]`
      - `inorderPrint(NULL, res)` → returns
    - Push 2 → `res = [1, 3, 2]`
    - `inorderPrint(NULL, res)` → returns

**Output:** `[1, 3, 2]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Every node is visited exactly once |
| **Space** | O(h) | Recursion stack depth equals tree height h (O(n) worst case for skewed tree) |
