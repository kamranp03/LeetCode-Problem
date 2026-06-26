# Problem 101 - Symmetric Tree

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/symmetric-tree/
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center). A tree is symmetric if the left subtree is a mirror reflection of the right subtree: corresponding nodes must have equal values, and the left child of the left subtree mirrors the right child of the right subtree (and vice versa).

## Approach: Recursive Mirror Check

The key insight is that a tree is symmetric if its left and right subtrees are mirrors of each other. Two subtrees are mirrors if: their roots have the same value, AND the left child of one mirrors the right child of the other (and vice versa). This is a subtle twist compared to "same tree" — instead of comparing `left` with `left` and `right` with `right`, we compare `left` with `right` and `right` with `left`.

## Code Walkthrough (Step by Step)

1. **Entry point `isSymmetric`:** Extract the root's left child as `p` and right child as `q`, then call `isSym(p, q)` to check if they mirror each other.

2. **Helper `isSym(p, q)`:**
   - **Both null:** If both `p` and `q` are `NULL`, this position is symmetric — return `true`.
   - **One null:** If only one is `NULL`, the structure is asymmetric — return `false`.
   - **Values differ:** If `p->val != q->val`, they don't mirror — return `false`.
   - **Recurse with crossed children:** Return `isSym(p->left, q->right) && isSym(p->right, q->left)`.
     - `p->left` must mirror `q->right` (outer pair)
     - `p->right` must mirror `q->left` (inner pair)

## Dry Run

**Example Input:**
```
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

- `isSym(2_left, 2_right)`:
  - values 2==2 ✓
  - `isSym(3_left, 3_right)`: both null → true (outer)... wait, let me redo:
  - `isSym(p->left=3, q->right=3)`: 3==3 → recurse on nulls → true
  - `isSym(p->right=4, q->left=4)`: 4==4 → recurse on nulls → true
  - returns true

**Output:** `true`

**Counter Example:** `[1,2,2,null,3,null,3]` → `isSym(3, null)` → one null → false → not symmetric.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each node pair is visited once; total visits = n/2 pairs |
| **Space** | O(h) | Recursion stack depth equals tree height h |
