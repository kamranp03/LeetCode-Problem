# Problem 1625 - Lexicographically Smallest String After Applying Operations

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
**Language:** C++

---

## Problem Statement

Given a string `s` of even length consisting of digits, and two integers `a` and `b`, you can apply two operations any number of times: (1) add `a` to all odd-indexed digits (mod 10), (2) rotate the string right by `b` positions. Return the lexicographically smallest string obtainable.

## Approach: BFS over All Reachable States

The key insight is that the total number of distinct reachable strings is finite (bounded by the period of operations). We treat each unique string as a state and use BFS to explore all states reachable via the two operations. The smallest string seen across all visited states is the answer.

## Code Walkthrough (Step by Step)

1. **`addOperation(str)`:** Adds `a` to each digit at odd indices (0-indexed) modulo 10.
2. **`rotateOperation(str)`:** Returns `str.substr(n-b) + str.substr(0, n-b)` — a right rotation by `b`.
3. **BFS:** Start with `s` in the queue and visited set. Track `smallest = s`.
4. **Each iteration:** Pop `cur`, update `smallest` if `cur < smallest`. Apply both operations; if the result is new (not in visited), add to queue and visited.
5. **Return `smallest`** when the queue is empty.

## Dry Run

**Example Input:** `s = "5525"`, `a = 9`, `b = 2`

- Start: "5525", smallest="5525"
- Add to odd indices: "5525" → "5924" (indices 1,3 get +9 mod 10)
- Rotate by 2: "2555"... BFS explores all reachable states
- Eventual smallest: **"2050"**

**Output:** `"2050"`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(10 * n * n) | At most O(10n) unique states, each O(n) to process |
| **Space** | O(states * n) | Visited set stores all reachable string states |
