# Problem 144 - Binary Tree Preorder Traversal

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-tree-preorder-traversal/
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, return the preorder traversal of its nodes' values as a vector. Preorder traversal visits nodes in the order: Root → Left subtree → Right subtree.

## Approach: Recursive DFS (Preorder)

The key insight is that preorder traversal has a natural recursive structure: first record the current node's value, then recursively traverse the left subtree, then recursively traverse the right subtree. A helper function carries the result vector by reference so all recursive calls share the same accumulator.

## Code Walkthrough (Step by Step)

1. **Public entry point `preorderTraversal`:** Create an empty `res` vector and call the helper `preorderPrint(root, res)`. Return whatever the helper returns (the same `res` vector by reference).

2. **Helper function `preorderPrint`:**
   - **Base case:** If `root == NULL`, the subtree is empty — return `res` without adding anything.
   - **Visit root FIRST:** Push `root->val` into `res` immediately. This is what makes it "pre"-order.
   - **Go left:** Recurse on `root->left` to traverse the entire left subtree.
   - **Go right:** Recurse on `root->right` to traverse the entire right subtree.
   - **Return `res`**.

3. The contrast with inorder: here `res.push_back(root->val)` happens BEFORE the recursive calls, not between them.

## Dry Run

**Example Input:**
```
    1
     \
      2
     /
    3
```

- `preorderPrint(1, res)`:
  - Push 1 → `res = [1]`
  - `preorderPrint(NULL, res)` → returns (left of 1 is null)
  - `preorderPrint(2, res)`:
    - Push 2 → `res = [1, 2]`
    - `preorderPrint(3, res)`:
      - Push 3 → `res = [1, 2, 3]`
      - `preorderPrint(NULL, res)` → returns
      - `preorderPrint(NULL, res)` → returns
    - `preorderPrint(NULL, res)` → returns (right of 2 is null)

**Output:** `[1, 2, 3]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Every node is visited exactly once |
| **Space** | O(h) | Recursion stack depth equals tree height h (O(n) worst case for skewed tree) |
