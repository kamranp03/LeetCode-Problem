# Problem 142 - Linked List Cycle II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/linked-list-cycle-ii/
**Language:** C++

---

## Problem Statement

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return `null`. The cycle start node is the specific node where the `next` pointer of some later node points back to, creating the loop.

## Approach: Floyd's Cycle Detection + Mathematical Reset

This is a two-phase extension of the cycle detection algorithm (Problem 141). Phase 1 detects whether a cycle exists using slow/fast pointers. Phase 2 finds the cycle entry point using a mathematical property: after the meeting point is found, if one pointer is reset to `head` and both advance one step at a time, they will meet exactly at the cycle's entry node.

**Why this works (math):** Let `L` = distance from head to cycle start, `C` = cycle length, `K` = distance from cycle start to meeting point. When they meet: slow traveled `L + K`, fast traveled `L + K + n*C`. Since fast = 2 * slow: `L + K = n*C`, so `L = n*C - K`. Resetting slow to head and advancing both one step means they travel `L` more steps and arrive at the cycle start simultaneously.

## Code Walkthrough (Step by Step)

1. **Phase 1 — Detect cycle:** Move `slow` one step and `fast` two steps until they meet or `fast` reaches NULL. Set `isCycle = true` if they meet.

2. **No cycle check:** If `!isCycle`, return `NULL`.

3. **Phase 2 — Find entry:** Reset `slow = head`. Keep `fast` at the meeting point. Now advance both `slow` and `fast` one step at a time until they meet again.

4. **Return the meeting node:** This is the cycle entry point.

## Dry Run

**Example Input:** List `3 -> 2 -> 0 -> -4`, cycle at node `2` (pos=1). L=1, C=3, K=2.

Phase 1:
| Step | slow | fast |
|------|------|------|
| start | 3 | 3 |
| 1 | 2 | 0 |
| 2 | 0 | 2 |
| 3 | -4 | -4 (meeting point!) |

Phase 2: Reset slow=3(head). fast=-4. L=1.
- Step 1: slow=2, fast=2 → they meet! Node 2 is the cycle start.

**Output:** Node with value `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Both phases make at most O(n) steps total |
| **Space** | O(1) | Only a constant number of pointers used |
