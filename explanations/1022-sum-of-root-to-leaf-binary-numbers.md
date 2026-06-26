# Problem 1022 - Sum of Root To Leaf Binary Numbers

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
**Language:** C++

---

## Problem Statement
Given a binary tree where each node has value 0 or 1, each root-to-leaf path represents a binary number (MSB at root). Return the sum of all these binary numbers across all root-to-leaf paths.

## Approach: DFS with Accumulated Value

As we traverse from root to leaf, we maintain the current binary number formed so far. At each node, shift the accumulated value left by one bit (multiply by 2) and add the current node's value: `val = 2 * val + node->val`. At a leaf node, this accumulated value is the complete binary number for that path. Sum up all leaf values.

## Code Walkthrough (Step by Step)

1. **`solve(root, val)` function:**
   - If `root == NULL`: return 0 (no path here).
   - Update: `val = (2 * val) + root->val` — append the current bit.
   - **Leaf check:** If both children are NULL, return `val` — this path's binary number.
   - **Recurse:** Return `solve(root->left, val) + solve(root->right, val)`.

2. **Main:** Call `solve(root, 0)`.

## Dry Run

**Example Input:**
```
      1
     / \
    0   1
   / \   \
  0   1   1
```

- Path 1-0-0: val = 0→1→2→4. Leaf value = 4 (binary 100)
- Path 1-0-1: val = 0→1→2→5. Leaf value = 5 (binary 101)
- Path 1-1-1: val = 0→1→3→7. Leaf value = 7 (binary 111)
- Sum = 4 + 5 + 7 = 16

**Output:** `22` (for the standard example `[1,0,1,0,1,0,1]`)

Let me use the standard LeetCode example:
```
    1
   / \
  0   1
 / \
0   1
```
- Path 1-0-0: 100 = 4
- Path 1-0-1: 101 = 5
- Path 1-1: 11 = 3
- Sum = 4+5+3 = 12

**Output:** `12`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Each node visited exactly once in DFS |
| **Space** | O(H) | Recursion stack depth equals tree height H |
