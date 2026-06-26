# Problem 100 - Same Tree

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/same-tree/
**Language:** C++

---

## Problem Statement

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical and the nodes have the same values at every position.

## Approach: Recursive DFS with Three-Case Check

The key insight is that two trees are equal if and only if: (1) both are empty, or (2) both are non-empty, have the same root value, AND their left subtrees are equal AND their right subtrees are equal. Recursion naturally handles this: we check the current node pair and delegate the subtree checks to recursive calls.

## Code Walkthrough (Step by Step)

1. **Both null:** If `p == NULL && q == NULL`, both trees are empty at this position — they match. Return `true`.

2. **Exactly one null:** If only one of `p` or `q` is `NULL` (but not both — we already handled that above), the structures differ. Return `false`.

3. **Values differ:** If `p->val != q->val`, the current nodes disagree. Return `false`.

4. **Recurse on subtrees:** If we reach this point, both nodes exist and have the same value. Return the logical AND of:
   - `isSameTree(p->left, q->left)` — left subtrees must also match
   - `isSameTree(p->right, q->right)` — right subtrees must also match

   The short-circuit AND means we stop as soon as any mismatch is found.

## Dry Run

**Example Input:**
```
Tree p:    Tree q:
    1          1
   / \        / \
  2   3      2   3
```

- `isSameTree(1, 1)`: values equal → recurse
  - `isSameTree(2, 2)`: values equal → recurse
    - `isSameTree(NULL, NULL)` → true
    - `isSameTree(NULL, NULL)` → true
    - returns true
  - `isSameTree(3, 3)`: values equal → recurse
    - `isSameTree(NULL, NULL)` → true
    - `isSameTree(NULL, NULL)` → true
    - returns true
  - returns true && true = true

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each node is visited at most once; n = min(nodes in p, nodes in q) |
| **Space** | O(h) | Recursion stack depth equals the tree height h |
