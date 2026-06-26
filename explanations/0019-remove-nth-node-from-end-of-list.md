# Problem 0019 - Remove Nth Node From End of List

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/
**Language:** C++

---

## Problem Statement

Given the head of a singly linked list, remove the n-th node from the end of the list and return the updated head. The list has at least one node, and `n` is always valid.

## Approach: Length Calculation (Two-Pass)

The key insight is that the n-th node from the end is the `(length - n + 1)`-th node from the beginning. We first traverse the entire list to find its length, then traverse again to the node just before the target and unlink it. A special case handles removing the head node.

## Code Walkthrough (Step by Step)

1. **Find the length** by traversing from `head` to the last node, counting steps.
2. **Handle head removal:** if `n == len`, the head must be deleted — advance `head` to `head->next`, free the old head, and return the new head.
3. **Find the predecessor:** compute `pos = len - n` (1-indexed position of the node to delete). Traverse from `head` for `pos - 1` steps to reach the node just before the target.
4. **Unlink the target node:** `temp->next = del->next` and `delete del`.
5. **Return `head`.**

## Dry Run

**Example Input:** `1 → 2 → 3 → 4 → 5`, `n = 2`

- Length = 5
- n != len, so no head removal
- `pos = 5 - 2 = 3` (we want to reach node at position 3, which is value 3)
- Traverse 2 steps from head: temp lands on node with value `3`
- `del = temp->next` = node `4`
- `temp->next = del->next` = node `5`
- Delete node `4`

**Output:** `1 → 2 → 3 → 5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two passes through the list (first for length, second to find position) |
| **Space** | O(1) | Only pointer variables; no extra data structures |
