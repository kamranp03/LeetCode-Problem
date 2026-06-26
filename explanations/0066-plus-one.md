# Problem 0066 - Plus One

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/plus-one/
**Language:** C++

---

## Problem Statement

Given a non-empty array of digits representing a non-negative integer (most significant digit first), increment the integer by one and return the resulting array. The digits do not contain any leading zero, except for the number zero itself.

## Approach: Reverse Traversal with Carry

The key insight is that adding one only causes a carry when the last digit is 9 (9 + 1 = 10, write 0, carry 1). We traverse from the least significant digit (rightmost) to the left: if the digit is not 9, simply increment it and return. If it is 9, set it to 0 and continue left with the carry. If all digits were 9, the loop ends with all zeros and we prepend a `1`.

## Code Walkthrough (Step by Step)

1. **Iterate `i` from `n-1` down to `0`:**
   - If `digits[i] != 9`: increment `digits[i]` by 1 and **return immediately** (no carry needed).
   - If `digits[i] == 9`: set `digits[i] = 0` and continue (carry propagates left).
2. **After the loop** (all digits were 9, e.g., 999 → 1000):
   - Insert `1` at the beginning of the array: `digits.insert(digits.begin(), 1)`.
3. **Return `digits`.**

## Dry Run

**Example Input:** `digits = [1, 2, 9]`

| i | digits[i] | Action                  | digits     |
|---|-----------|-------------------------|------------|
| 2 | 9         | set to 0, continue      | [1, 2, 0]  |
| 1 | 2         | not 9: 2+1=3, return    | [1, 2+1, 0] → [1, 3, 0] |

**Output:** `[1, 3, 0]`

**Example Input:** `digits = [9, 9, 9]`

| i | digits[i] | Action             | digits      |
|---|-----------|--------------------|-------------|
| 2 | 9         | set to 0, continue | [9, 9, 0]   |
| 1 | 9         | set to 0, continue | [9, 0, 0]   |
| 0 | 9         | set to 0, continue | [0, 0, 0]   |

Loop ends → insert 1 at front → `[1, 0, 0, 0]`

**Output:** `[1, 0, 0, 0]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | At most one full traversal of the digits array |
| **Space** | O(1) | Modified in-place (the prepend of '1' is O(n) in the worst case due to shifting) |
