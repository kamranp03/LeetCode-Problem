# Problem 1161 - Maximum Level Sum of a Binary Tree

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
**Language:** C++

---

## Problem Statement
Given the root of a binary tree, find the level (1-indexed) with the maximum sum of node values. If there are multiple levels with the same maximum sum, return the smallest level number.

## Approach: BFS Level-Order Traversal

Perform a standard BFS (Breadth-First Search) level by level. At each level, sum all node values. Track the maximum sum seen and the corresponding level number. Since we process levels in order and only update when strictly greater, ties naturally resolve to the smallest level.

## Code Walkthrough (Step by Step)

1. **Initialize:** Push `root` into queue. Set `level = 1`, `ansLevel = 1`, `maxSum = LLONG_MIN`.

2. **BFS loop** while queue not empty:
   - Record `size = q.size()` — number of nodes at current level.
   - Compute `currSum = 0`. Process all `size` nodes:
     - Pop node, add its value to `currSum`.
     - Push its left and right children (if they exist) for the next level.
   - If `currSum > maxSum`: update `maxSum = currSum` and `ansLevel = level`.
   - Increment `level`.

3. **Return `ansLevel`.**

## Dry Run

**Example Input:**
```
        1
       / \
      7   0
     / \
    7  -8
```

| Level | Nodes       | Sum | maxSum | ansLevel |
|-------|-------------|-----|--------|----------|
| 1     | [1]         | 1   | 1      | 1        |
| 2     | [7, 0]      | 7   | 7      | 2        |
| 3     | [7, -8]     | -1  | 7      | 2        |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Each node enqueued and processed exactly once |
| **Space** | O(W) | Queue holds at most one full level; W = max tree width |
