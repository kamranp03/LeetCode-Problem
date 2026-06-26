# Problem 3217 - Delete Nodes From Linked List Present in Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and the head of a linked list, delete all nodes from the linked list whose value exists in `nums`. Return the head of the modified linked list.

## Approach: Hash Set for O(1) Lookup + Dummy Head Pattern

We first load all values from `nums` into an unordered set for O(1) membership checking. Then we traverse the linked list using a dummy head node (to handle edge cases where the head itself needs deletion) and unlink any node whose value is in the set.

## Code Walkthrough (Step by Step)

1. **Build hash set:** Insert all elements of `nums` into `toDelete` (unordered_set) for O(1) lookups.

2. **Create dummy node:** `dummy` points to `head`. Use `curr = dummy` as the traversal pointer.

3. **Traverse linked list:**
   - While `curr->next != nullptr`:
     - If `curr->next->val` is in `toDelete`: set `curr->next = curr->next->next` (skip the node, effectively deleting it).
     - Else: advance `curr = curr->next`.

4. **Return** `dummy->next` (the new head, skipping any originally-deleted head nodes).

## Dry Run

**Example Input:** `nums = [1, 2, 3]`, list: `1 → 2 → 3 → 4 → 5`

- Set: {1, 2, 3}
- dummy → 1 → 2 → 3 → 4 → 5
- curr=dummy: next=1, in set → skip. dummy → 2 → 3 → 4 → 5
- curr=dummy: next=2, in set → skip. dummy → 3 → 4 → 5
- curr=dummy: next=3, in set → skip. dummy → 4 → 5
- curr=dummy: next=4, not in set → advance curr=4
- curr=4: next=5, not in set → advance curr=5
- curr=5: next=null → stop

**Output:** `4 → 5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n + m) | n = array size for set build, m = list length for traversal |
| **Space** | O(n) | Hash set stores all values from nums |
