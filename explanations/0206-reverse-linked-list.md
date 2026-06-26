# Problem 206 - Reverse Linked List

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/reverse-linked-list/
**Language:** C++

---

## Problem Statement

Given the head of a singly linked list, reverse the list, and return the reversed list's head. For example, the list `1 -> 2 -> 3 -> 4 -> 5` becomes `5 -> 4 -> 3 -> 2 -> 1`.

## Approach: Iterative Three-Pointer Reversal

The key insight is to reverse the direction of each `next` pointer as we traverse the list. We maintain three pointers:
- `prev`: the node that the current node's `next` should point to (starts as `NULL` since the new tail points to nothing).
- `curr`: the node currently being processed.
- `next`: a temporary save of `curr->next` before we overwrite it.

We process each node by redirecting its `next` to `prev`, then advancing all three pointers forward.

## Code Walkthrough (Step by Step)

1. **Initialize:** `prev = NULL`, `curr = head`, `next = NULL`.

2. **Loop while `curr != NULL`:**
   - **Save next:** `next = curr->next`. We must save the forward pointer before overwriting it.
   - **Reverse the link:** `curr->next = prev`. Point the current node backward.
   - **Advance `prev`:** `prev = curr`. The current node is now the new "previous" for the next iteration.
   - **Advance `curr`:** `curr = next`. Move to the originally saved next node.

3. **Update head:** `head = prev`. After the loop, `curr` is `NULL` and `prev` points to the last node (new head).

4. **Return `head`**.

## Dry Run

**Example Input:** `1 -> 2 -> 3 -> NULL`

| Step | prev | curr | next | Action |
|------|------|------|------|--------|
| init | NULL | 1 | NULL | — |
| 1 | NULL | 1 | 2 | 1->NULL, prev=1, curr=2 |
| 2 | 1 | 2 | 3 | 2->1, prev=2, curr=3 |
| 3 | 2 | 3 | NULL | 3->2, prev=3, curr=NULL |
| end | 3 | NULL | — | head=prev=3 |

Result: `3 -> 2 -> 1 -> NULL`

**Output:** `3 -> 2 -> 1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each of the n nodes is visited exactly once |
| **Space** | O(1) | Only three pointer variables; no extra data structures |
