# Problem 234 - Palindrome Linked List

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/palindrome-linked-list/
**Language:** C++

---

## Problem Statement
Given the head of a singly linked list, return `true` if it is a palindrome, or `false` otherwise. A palindrome reads the same forwards and backwards.

## Approach: Find Middle + Reverse Second Half + Compare

The key insight is to split the list into two halves, reverse the second half in place, and then compare both halves node by node. This works in O(n) time and O(1) space. The fast/slow pointer technique finds the midpoint without knowing the list length.

## Code Walkthrough (Step by Step)

1. **Edge case:** If the list has 0 or 1 node, it is trivially a palindrome.

2. **Find middle (slow/fast pointers):** `slow` advances one step at a time, `fast` advances two steps at a time. When `fast` reaches the end, `slow` is at the start of the second half.

3. **Reverse second half:** Call `reverse(slow)` which iteratively reverses the second half of the list by flipping `next` pointers. Returns the new head of the reversed second half.

4. **Compare halves:** Walk `first` (from original head) and `second` (from reversed head) simultaneously. If any values differ, return `false`.

5. **Return true** if all values matched.

**Helper `reverse(head)`:** Uses three pointers — `prev`, `curr` (head), and `next`. Iteratively reverses each node's `next` pointer to point to `prev`, then advances all three pointers.

## Dry Run

**Example Input:** `1 -> 2 -> 2 -> 1`

Step 1 — Find middle: slow/fast start at node 1.
- Iteration 1: slow=2, fast=2 (second)
- Iteration 2: slow=2 (third), fast=NULL (past end)

Middle = node with value 2 (third node).

Step 2 — Reverse `2 -> 1`: becomes `1 -> 2`.

Step 3 — Compare:
- first=1, second=1 → match
- first=2, second=2 → match

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | One pass to find middle, one pass to reverse, one pass to compare |
| **Space** | O(1) | Only a constant number of pointers used |
