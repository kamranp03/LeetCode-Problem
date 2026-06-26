# Problem 2833 - Furthest Point From Origin

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/furthest-point-from-origin/
**Language:** C++

---

## Problem Statement

You are given a string `moves` consisting of characters `'L'` (left), `'R'` (right), and `'_'` (can go either left or right). Starting at position `0` on a number line, return the maximum distance from the origin you can reach after performing all the moves.

## Approach: Count and Assign Dashes Greedily

The `'_'` (dash) moves can be freely chosen as either left or right. The net displacement without dashes is `|left - right|`. To maximize the final distance, all dashes should be assigned to whichever direction is larger (or either, if equal). Thus the answer is simply `|left - right| + dash`.

## Code Walkthrough (Step by Step)

1. **Initialize** counters `left = 0`, `right = 0`, `dash = 0`.

2. **Single pass** over `moves`:
   - If character is `'L'`: increment `left`.
   - If character is `'R'`: increment `right`.
   - Otherwise: increment `dash`.

3. **Compute result:** The fixed moves give a net displacement of `|left - right|`. Every dash extends that displacement by 1 in the optimal direction. Return `|left - right| + dash`.

## Dry Run

**Example Input:** `moves = "L_RL__R"`

- Scanning: L→left=1, _→dash=1, R→right=1, L→left=2, _→dash=2, _→dash=3, R→right=2
- left=2, right=2, dash=3
- |2 - 2| + 3 = 0 + 3 = 3

**Output:** `3`

**Example Input:** `moves = "LL"`

- left=2, right=0, dash=0
- |2 - 0| + 0 = 2

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass over the moves string |
| **Space** | O(1) | Three integer counters only |
