# Problem 141 - Linked List Cycle

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/linked-list-cycle/
**Language:** C++

---

## Problem Statement

Given the head of a linked list, determine if the linked list has a cycle in it. A cycle exists if some node in the list can be reached again by continuously following the `next` pointer. Return `true` if a cycle exists, or `false` otherwise.

## Approach: Floyd's Cycle Detection (Slow and Fast Pointers)

The key insight is to use two pointers moving at different speeds: a slow pointer that advances one step at a time and a fast pointer that advances two steps at a time. If the list has no cycle, the fast pointer will reach `NULL`. If a cycle exists, the fast pointer will eventually "lap" the slow pointer and they will meet at the same node — like two runners on a circular track where one is faster.

## Code Walkthrough (Step by Step)

1. **Initialize:** Both `slow` and `fast` start at `head`.

2. **Advance and check:** Loop while `fast != NULL && fast->next != NULL` (ensures we can safely do `fast->next->next`):
   - Move `slow = slow->next` (one step).
   - Move `fast = fast->next->next` (two steps).
   - If `slow == fast`, a cycle is detected — return `true`.

3. **No cycle:** If the loop exits (fast reached `NULL`), the list has no cycle — return `false`.

## Dry Run

**Example Input:** `3 -> 2 -> 0 -> -4`, where `-4` points back to node `2` (cycle at index 1)

| Step | slow | fast |
|------|------|------|
| 0 | 3 | 3 |
| 1 | 2 | 0 |
| 2 | 0 | 2 (via -4→2) |
| 3 | -4 | -4 (via 0→-4) |
| 4 | 2 | 2 → slow == fast! |

**Output:** `true`

**No-cycle example:** `1 -> 2 -> NULL`
- slow=1, fast=1 → slow=2, fast=NULL → fast is NULL → loop ends → return `false`.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | In the worst case, the fast pointer traverses the list; if a cycle exists, they meet within one loop iteration of the cycle |
| **Space** | O(1) | Only two pointers regardless of list size |
