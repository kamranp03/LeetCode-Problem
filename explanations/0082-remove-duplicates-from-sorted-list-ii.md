# Problem 82 - Remove Duplicates from Sorted List II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
**Language:** C++

---

## Problem Statement

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well. Unlike Problem 83, here even a single occurrence of a number must be removed if any duplicate of it exists.

## Approach: Frequency Map + Dummy Node Rebuild

The key insight is to make two passes: first count the frequency of each value using a hash map, then rebuild the list by only including nodes whose value appears exactly once (frequency == 1). A dummy head node simplifies edge cases where the actual head must be removed.

## Code Walkthrough (Step by Step)

1. **Count frequencies:** Traverse the entire list with pointer `temp`, incrementing `mp[temp->val]` for each node. After this pass, `mp` holds how many times each value appears.

2. **Create dummy node:** Allocate a `dummy` node with value 0 and a `tail` pointer starting there. The final answer will be `dummy->next`.

3. **Rebuild list:** Do a second pass with `temp` from the original head. For each node, check `mp[temp->val] == 1`. If true (value appeared only once), attach it to `tail->next` and advance `tail`.

4. **Terminate the list:** After the loop, set `tail->next = NULL` to properly end the new list (important since nodes still have their original `next` pointers).

5. **Return:** Return `dummy->next`, which is the head of the cleaned list.

## Dry Run

**Example Input:** `1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5`

- Frequency pass: `mp = {1:1, 2:1, 3:2, 4:2, 5:1}`
- Rebuild pass:
  - Node 1: freq=1 → include. List: `1`
  - Node 2: freq=1 → include. List: `1 -> 2`
  - Node 3: freq=2 → skip.
  - Node 3: freq=2 → skip.
  - Node 4: freq=2 → skip.
  - Node 4: freq=2 → skip.
  - Node 5: freq=1 → include. List: `1 -> 2 -> 5`
- Set `tail->next = NULL`.

**Output:** `1 -> 2 -> 5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two linear passes over the list |
| **Space** | O(n) | Hash map stores frequency of each unique value |
