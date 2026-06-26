# Problem 110 - Balanced Binary Tree

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/balanced-binary-tree/
**Language:** C++

---

## Problem Statement

Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is one in which the left and right subtrees of every node differ in height by no more than 1. This condition must hold for every node in the tree, not just the root.

## Approach: Recursive Height Computation + Balanced Check

The key insight is to decompose the problem into two steps: (1) compute the height of a subtree recursively, and (2) use that height function to verify the balance condition at each node. For a node to be balanced, its left and right subtrees must differ in height by at most 1, AND both subtrees must themselves be balanced (recursive requirement).

## Code Walkthrough (Step by Step)

1. **`height(node)` function:**
   - Base case: if `node == NULL`, return 0 (empty tree has height 0).
   - Recursively compute `height(node->left)` and `height(node->right)`.
   - Return `1 + max(leftHeight, rightHeight)`.

2. **`isBalanced(root)` function:**
   - Base case: if `root == NULL`, an empty tree is balanced — return `true`.
   - Compute `lHeight = height(root->left)` and `rHeight = height(root->right)`.
   - If `abs(lHeight - rHeight) > 1`, the current node violates the balance condition — return `false`.
   - Otherwise, recursively check: return `isBalanced(root->left) && isBalanced(root->right)`. Both subtrees must also be balanced.

**Note:** This approach recomputes heights multiple times (O(n log n) for balanced trees). An optimized O(n) approach would combine height and balance checking in a single pass.

## Dry Run

**Example Input:**
```
      3
     / \
    9   20
       /  \
      15   7
```

- `isBalanced(3)`:
  - `lHeight = height(9) = 1`
  - `rHeight = height(20) = 2`
  - `|1 - 2| = 1` ≤ 1 ✓
  - `isBalanced(9)`: lH=0, rH=0, diff=0 ✓, both children null → true
  - `isBalanced(20)`: lH=1, rH=1, diff=0 ✓, both children balanced → true
  - returns true

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2) worst case | `height` is called repeatedly for each node; O(n log n) for balanced trees |
| **Space** | O(h) | Recursion stack depth equals tree height h |
