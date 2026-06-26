# Problem 0020 - Valid Parentheses

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/valid-parentheses/
**Language:** C++

---

## Problem Statement

Given a string `s` containing only the characters `(`, `)`, `{`, `}`, `[`, and `]`, determine if the input string is valid. A string is valid if every open bracket is closed by the same type of bracket in the correct order, and every close bracket has a corresponding open bracket.

## Approach: Stack

The key insight is that brackets must be closed in LIFO (Last-In, First-Out) order — the most recently opened bracket must be the first one closed. A stack is the perfect data structure for this: push every opening bracket, and when we see a closing bracket, check if the top of the stack is the matching opening bracket. If at any point the match fails or the stack is empty, the string is invalid.

## Code Walkthrough (Step by Step)

1. **Create an empty stack** `st` of characters.
2. **Iterate through each character** in the string:
   - If it is an **opening bracket** `(`, `[`, or `{`: push it onto the stack.
   - If it is a **closing bracket**:
     - If the stack is **empty**: there's no matching opener — return `false`.
     - If the **top of the stack matches** the corresponding opener (`(` for `)`, `{` for `}`, `[` for `]`): pop the stack.
     - Otherwise: mismatch — return `false`.
3. **After the loop**, return `st.size() == 0` — if the stack is empty all brackets were matched; otherwise some were left unclosed.

## Dry Run

**Example Input:** `s = "{[()]}"`

| i | char | Stack State    | Action          |
|---|------|----------------|-----------------|
| 0 | {    | {              | push            |
| 1 | [    | {[             | push            |
| 2 | (    | {[(            | push            |
| 3 | )    | {[             | top='(' matches, pop |
| 4 | ]    | {              | top='[' matches, pop |
| 5 | }    | (empty)        | top='{' matches, pop |

Stack is empty → **Output:** `true`

**Example Input:** `s = "([)]"`

At index 2 `]`, top of stack is `(` which does not match `]` → **Output:** `false`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the string |
| **Space** | O(n) | Stack can hold at most n/2 opening brackets |
