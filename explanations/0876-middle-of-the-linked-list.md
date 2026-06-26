# Problem 876 - Middle of the Linked List

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/middle-of-the-linked-list/
**Language:** C++

---

## Problem Statement
Given the head of a singly linked list, return the middle node of the list. If the list has an even number of nodes, return the second middle node (e.g., for a 6-node list, return node 4).

## Approach: Fast and Slow Pointer (Floyd's Technique)

Use two pointers: `slow` advances one step at a time, `fast` advances two steps at a time. When `fast` reaches the end, `slow` is at the middle. This avoids counting the length first. For even-length lists, there is a special check: if `fast->next->next == NULL`, there are two middle candidates — return `slow->next` (the second middle).

## Code Walkthrough (Step by Step)

1. **Initialize** both `slow` and `fast` to `head`.

2. **Loop while `fast->next != NULL`:**
   - **Even-length check:** If `fast->next->next == NULL`, return `slow->next` — this handles even-length lists where we want the second middle.
   - Advance `slow = slow->next` (one step).
   - Advance `fast = fast->next->next` (two steps).

3. **Return `slow`** — for odd-length lists, this is the exact middle.

## Dry Run

**Example Input:** `1 -> 2 -> 3 -> 4 -> 5`

| Step | slow | fast |
|------|------|------|
| Init | 1    | 1    |
| 1    | 2    | 3    |
| 2    | 3    | 5    |
| fast->next==NULL → exit loop |

Return `slow` = node(3)

**Output:** Node with value `3`

**Example Input (even):** `1 -> 2 -> 3 -> 4`

- Step 1: slow=2, fast=3; fast->next->next = NULL → return slow->next = node(3)

**Output:** Node with value `3` (second middle)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single pass through the list |
| **Space** | O(1) | Only two pointer variables |
