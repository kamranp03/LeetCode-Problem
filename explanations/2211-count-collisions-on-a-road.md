# Problem 2211 - Count Collisions on a Road

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-collisions-on-a-road/
**Language:** C++

---

## Problem Statement
There are `n` cars on a road, each moving left (`'L'`), right (`'R'`), or stationary (`'S'`). When two cars collide, they both stop. Count the total number of collisions that will occur.

## Approach: Trim Edges + Count Non-Stationary in Middle

The key insight is that:
- Cars moving `'L'` at the leftmost side will never collide (they drive off the edge).
- Cars moving `'R'` at the rightmost side will never collide (they drive off the edge).
- Every remaining non-stationary car (`'L'` or `'R'`) in the effective region must eventually collide and become stationary. So the number of collisions equals the number of non-`'S'` characters in the trimmed region.

## Code Walkthrough (Step by Step)

1. **Trim left**: Advance pointer `i` from the left while `directions[i] == 'L'` (these cars go left and never collide).
2. **Trim right**: Advance pointer `j` from the right while `directions[j] == 'R'` (these cars go right and never collide).
3. **Count non-`'S'` characters** in the range `[i, j]`: every `'L'` or `'R'` in this middle section will participate in a collision.
4. **Return `coll`**.

## Dry Run

**Example Input:** `directions = "RLRSLL"`

- Trim left: i=0, directions[0]='R' (not 'L'), stop. i=0.
- Trim right: j=5, directions[5]='L' (not 'R'), stop. j=5.
- Count non-'S' in [0,5]: R,L,R,S,L,L → 'R'=1, 'L'=1, 'R'=1, 'S'=skip, 'L'=1, 'L'=1 → coll=5.

**Output:** `5`

**Another Example:** `directions = "LLRR"`
- Trim left: skip L at 0, skip L at 1. i=2.
- Trim right: skip R at 3. j=2.
- Range [2,2]: 'R' → coll=1.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Three linear passes (trim left, trim right, count middle) |
| **Space** | O(1) | Only two index pointers and a counter |
