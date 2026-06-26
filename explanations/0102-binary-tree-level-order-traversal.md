# Problem 102 - Binary Tree Level Order Traversal

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/binary-tree-level-order-traversal/
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, return the level order traversal of its nodes' values (i.e., from left to right, level by level) as a vector of vectors. Each inner vector contains all node values at one level of the tree.

## Approach: BFS with Queue (Level-by-Level Processing)

The key insight is to use a queue for Breadth-First Search. At the start of each iteration, the queue contains exactly all the nodes at the current level. By recording `level = q.size()` at the start of each outer loop iteration, we know exactly how many nodes to dequeue for the current level. After processing those nodes, the queue naturally contains all nodes of the next level.

## Code Walkthrough (Step by Step)

1. **Edge case:** If `root == NULL`, return an empty result `{}`.

2. **Initialize BFS:** Push `root` into the queue `q`. Create the result vector `res`.

3. **Outer while loop:** Continue while the queue is not empty.

4. **Capture level size:** `int level = q.size()` — this is how many nodes are at the current level.

5. **Process current level:** Create a temporary vector `tmp`. Loop `level` times:
   - Dequeue the front node `t` with `q.front(); q.pop()`.
   - Push `t->val` into `tmp`.
   - If `t->left` is not NULL, push it into the queue (will be in the next level).
   - If `t->right` is not NULL, push it into the queue.

6. **Store level result:** Push `tmp` into `res`.

7. **Return `res`** after all levels are processed.

## Dry Run

**Example Input:**
```
      3
     / \
    9   20
       /  \
      15   7
```

- Initial queue: `[3]`
- Level 1: size=1. Dequeue 3, tmp=[3]. Enqueue 9, 20. Queue: `[9,20]`. res=`[[3]]`
- Level 2: size=2. Dequeue 9, tmp=[9]. Enqueue nothing. Dequeue 20, tmp=[9,20]. Enqueue 15,7. Queue: `[15,7]`. res=`[[3],[9,20]]`
- Level 3: size=2. Dequeue 15, tmp=[15]. Dequeue 7, tmp=[15,7]. Queue empty. res=`[[3],[9,20],[15,7]]`

**Output:** `[[3],[9,20],[15,7]]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each node is enqueued and dequeued exactly once |
| **Space** | O(w) | Queue holds at most w nodes, where w is the maximum tree width |
