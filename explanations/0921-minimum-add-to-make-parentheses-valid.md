# Problem 921 - Minimum Add to Make Parentheses Valid

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
**Language:** C++

---

## Problem Statement
Given a string of parentheses (only '(' and ')'), find the minimum number of parentheses you must add (anywhere) to make the string valid. A valid string has every opening parenthesis matched with a closing one in the correct order.

## Approach: Greedy Counter

Use two counters: `open` tracks unmatched opening parentheses seen so far, and `ans` counts the required additions. For each ')' without a matching '(' (i.e., `open == 0`), we must add a '(' — increment `ans`. For each unmatched '(' remaining after scanning, we must add a ')' — add `open` to `ans` at the end.

## Code Walkthrough (Step by Step)

1. **Initialize:** `open = 0`, `ans = 0`.

2. **Scan each character `ch`:**
   - If `ch == '('`: increment `open` (we have a pending open parenthesis).
   - If `ch == ')'`:
     - If `open > 0`: match it with a previous '(' — decrement `open`.
     - Else: no matching '(' available — we need to add one, increment `ans`.

3. **After the loop:** `open` holds the count of unmatched '(' — each needs a ')'. Return `ans + open`.

## Dry Run

**Example Input:** `s = "())"`

| ch  | open | ans |
|-----|------|-----|
| '(' | 1    | 0   |
| ')' | 0    | 0   |
| ')' | 0    | 1   |

Return `ans + open = 1 + 0 = 1`

**Output:** `1`

**Example Input:** `s = "((("`

| ch  | open | ans |
|-----|------|-----|
| '(' | 1    | 0   |
| '(' | 2    | 0   |
| '(' | 3    | 0   |

Return `0 + 3 = 3`

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single linear scan of the string |
| **Space** | O(1) | Only two integer counters |
