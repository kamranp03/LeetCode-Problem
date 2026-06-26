# Problem 83 - Remove Duplicates from Sorted List

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-list/
**Language:** C++

---

## Problem Statement

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well. Unlike Problem 82, here the first occurrence of each value is kept — only the extra copies are removed.

## Approach: Single Pass In-Place Pointer Manipulation

Because the list is already sorted, all duplicates of any value are consecutive. We can use a single pointer `current` that walks through the list. Whenever `current->val == current->next->val`, we skip the next node by setting `current->next = current->next->next`. If they differ, we simply advance `current`. No extra space is needed.

## Code Walkthrough (Step by Step)

1. **Edge case:** If `head == NULL`, the list is empty — return `head` immediately.

2. **Initialize pointer:** Set `current = head`. We start from the first node.

3. **Walk the list:** Loop while `current->next != NULL` (we need a next node to compare).

4. **Duplicate detected:** If `current->val == current->next->val`, set `current->next = current->next->next`. This effectively removes the duplicate node. We do NOT advance `current` here because there might be more duplicates after the removed node (e.g., three consecutive equal values).

5. **No duplicate:** If values differ, advance: `current = current->next`.

6. **Return head:** The original head is returned since we modified the list in place (the first node is never removed in this problem).

## Dry Run

**Example Input:** `1 -> 1 -> 2 -> 3 -> 3`

| `current` val | `next` val | Action |
|---|---|---|
| 1 | 1 | Duplicate! `current->next` skips to node(2). List: `1 -> 2 -> 3 -> 3` |
| 1 | 2 | Different. Advance `current` to node(2). |
| 2 | 3 | Different. Advance `current` to node(3). |
| 3 | 3 | Duplicate! `current->next` skips to NULL. List: `1 -> 2 -> 3` |
| 3 | NULL | Loop ends. |

**Output:** `1 -> 2 -> 3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through all n nodes |
| **Space** | O(1) | Only one extra pointer; modification is in-place |
