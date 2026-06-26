# Problem 0061 - Rotate List

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/rotate-list/
**Language:** C++

---

## Problem Statement

Given the head of a singly linked list and an integer `k`, rotate the list to the right by `k` places. Rotating right by 1 means the last node becomes the new head.

## Approach: Make Circular + Find New Tail

The key insight is that rotating right by `k` is equivalent to making the last `k % len` nodes the new front. Instead of actually moving nodes, we: (1) connect the tail to the head to form a circle, (2) find the new tail (which is at position `len - k` from the original head), and (3) break the circle there. Reducing `k` modulo `len` handles cases where `k >= len`.

## Code Walkthrough (Step by Step)

1. **Handle edge cases:** return immediately if the list is empty, has one node, or `k == 0`.
2. **Find length and tail:** traverse to the last node, counting length.
3. **Reduce k:** `k = k % len`. If `k == 0` after reduction, return `head` (full rotations, no change).
4. **Make circular:** `tail->next = head`.
5. **Find new tail:** the new tail is `len - k` steps from the original `head`. Traverse `len - k - 1` steps (since we start at head which is step 1).
6. **Break the circle:** `newHead = newTail->next`, then `newTail->next = NULL`.
7. **Return `newHead`.**

## Dry Run

**Example Input:** `1 → 2 → 3 → 4 → 5`, `k = 2`

- Length = 5, tail = node(5)
- k = 2 % 5 = 2
- Make circular: 5 → 1 (circle)
- steps = len - k = 5 - 2 = 3; traverse 2 steps from head:
  - Start at node(1) [step 1], advance to node(2) [step 2], advance to node(3) [step 3]
  - newTail = node(3)
- newHead = node(3)->next = node(4)
- node(3)->next = NULL

Result: `4 → 5 → 1 → 2 → 3`

**Output:** `4 → 5 → 1 → 2 → 3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two traversals: one to find length/tail, one to find new tail |
| **Space** | O(1) | Only pointer variables |
