# Problem 226 - Invert Binary Tree

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/invert-binary-tree/
**Language:** C++

---

## Problem Statement
Given the root of a binary tree, invert the tree (mirror it) and return its root. Inverting means every node's left child becomes its right child and vice versa, all the way down the tree.

## Approach: Recursive DFS (Pre-order Swap)

The key insight is that inverting a tree is self-similar: to invert a tree, swap the left and right children of the current node, then recursively invert both subtrees. The base case is when the node is `NULL` — nothing to do. We swap first (pre-order), then recurse into the already-swapped children.

## Code Walkthrough (Step by Step)

1. **Base case:** If `root == NULL`, return immediately.

2. **Swap children:** Use `swap(root->left, root->right)` to exchange the two child pointers of the current node.

3. **Recurse left:** Call `invertTree(root->left)` to invert the left subtree (which was originally the right subtree).

4. **Recurse right:** Call `invertTree(root->right)` to invert the right subtree.

5. **Return root:** The root is the same node; only its subtree structure has changed.

## Dry Run

**Example Input:**
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

- At node 4: swap children → left=7, right=2
- At node 7: swap children → left=9, right=6
- At node 9: no children, return
- At node 6: no children, return
- At node 2: swap children → left=3, right=1
- At node 3: no children, return
- At node 1: no children, return

**Output:**
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Every node is visited exactly once |
| **Space** | O(h) | Recursion stack depth equals tree height h; O(n) worst case for skewed trees |
