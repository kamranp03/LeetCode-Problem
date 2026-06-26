# Problem 145 - Binary Tree Postorder Traversal

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-tree-postorder-traversal/
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, return the postorder traversal of its nodes' values as a vector. Postorder traversal visits nodes in the order: Left subtree → Right subtree → Root. The root is always visited last.

## Approach: Recursive DFS (Postorder)

The key insight is that postorder traversal's recursive structure processes children before the parent. First recurse on the left subtree, then recurse on the right subtree, and only after both subtrees are fully processed do we record the current node's value. A helper function carries the result vector by reference.

## Code Walkthrough (Step by Step)

1. **Public entry point `postorderTraversal`:** Create an empty `res` vector and call `postorderPrint(root, res)`. Return the result.

2. **Helper function `postorderPrint`:**
   - **Base case:** If `root == NULL`, the subtree is empty — return `res` without adding anything.
   - **Go left:** Recurse on `root->left` to process the entire left subtree first.
   - **Go right:** Recurse on `root->right` to process the entire right subtree next.
   - **Visit root LAST:** Push `root->val` into `res`. This is what makes it "post"-order — the current node is recorded only after both subtrees are done.
   - **Return `res`**.

3. Comparison with pre/in order:
   - Preorder: root → left → right
   - Inorder: left → root → right
   - Postorder: left → right → **root**

## Dry Run

**Example Input:**
```
    1
     \
      2
     /
    3
```

- `postorderPrint(1, res)`:
  - `postorderPrint(NULL, res)` → returns (left of 1 is null)
  - `postorderPrint(2, res)`:
    - `postorderPrint(3, res)`:
      - `postorderPrint(NULL, res)` → returns
      - `postorderPrint(NULL, res)` → returns
      - Push 3 → `res = [3]`
    - `postorderPrint(NULL, res)` → returns (right of 2 is null)
    - Push 2 → `res = [3, 2]`
  - Push 1 → `res = [3, 2, 1]`

**Output:** `[3, 2, 1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Every node is visited exactly once |
| **Space** | O(h) | Recursion stack depth equals tree height h (O(n) for a skewed tree) |
