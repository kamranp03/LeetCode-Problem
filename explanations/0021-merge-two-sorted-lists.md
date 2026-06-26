# Problem 0021 - Merge Two Sorted Lists

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/merge-two-sorted-lists/
**Language:** C++

---

## Problem Statement

Given the heads of two sorted singly linked lists `list1` and `list2`, merge them into one sorted linked list and return the head of the merged list. The merged list should be made by splicing together the nodes of the two input lists.

## Approach: Recursion

The key insight is that merging two sorted lists is a naturally recursive problem: the smaller of the two current head values becomes the head of the merged list, and its `next` pointer is set to the result of merging the rest. The recursion bottoms out when one list is empty — simply return the other.

## Code Walkthrough (Step by Step)

1. **Base case:** if either `head1` or `head2` is `NULL`, return the other one (the non-null list). This handles empty lists and the end of either list during recursion.
2. **Compare the two heads:**
   - If `head1->val <= head2->val`: `head1` is the smaller node. Set `head1->next = mergeTwoLists(head1->next, head2)` and return `head1`.
   - Otherwise: `head2` is the smaller node. Set `head2->next = mergeTwoLists(head1, head2->next)` and return `head2`.
3. The recursion builds the merged list in-place by rewiring `next` pointers.

## Dry Run

**Example Input:** `list1 = 1→3→5`, `list2 = 2→4→6`

```
merge(1→3→5, 2→4→6)
  1 <= 2 → head1=1, 1.next = merge(3→5, 2→4→6)
    3 > 2 → head2=2, 2.next = merge(3→5, 4→6)
      3 <= 4 → head1=3, 3.next = merge(5, 4→6)
        5 > 4 → head2=4, 4.next = merge(5, 6)
          5 <= 6 → head1=5, 5.next = merge(null, 6)
            head1 is null → return 6
          5.next = 6 → return 5
        4.next = 5→6 → return 4
      3.next = 4→5→6 → return 3
    2.next = 3→4→5→6 → return 2
  1.next = 2→3→4→5→6 → return 1
```

**Output:** `1 → 2 → 3 → 4 → 5 → 6`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m + n) | Every node from both lists is visited exactly once |
| **Space** | O(m + n) | Recursion stack depth equals total number of nodes |
