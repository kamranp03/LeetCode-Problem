# Problem 344 - Reverse String

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/reverse-string/
**Language:** C++

---

## Problem Statement
Write a function that reverses a string. The input is given as a vector of characters `s`, and you must reverse it in-place with O(1) extra memory.

## Approach: Two-Pointer In-Place Swap

The key insight is to use two pointers starting at opposite ends of the array — one at the leftmost character (`i`) and one at the rightmost (`j`). We repeatedly swap the characters at these positions and move the pointers toward each other until they meet in the middle. This achieves a complete reversal in a single pass.

## Code Walkthrough (Step by Step)

1. **Initialize pointers:** `i = 0` (start), `j = s.size() - 1` (end).

2. **Loop while `i < j`:** As long as the left pointer is to the left of the right pointer, there are still characters to swap.

3. **Swap characters:** Store `s[i]` in a temp variable `t`, assign `s[i] = s[j]`, then `s[j] = t`.

4. **Advance pointers:** Increment `i` and decrement `j` to move inward.

5. **Termination:** When `i >= j`, the string is fully reversed. The function modifies `s` in-place.

## Dry Run

**Example Input:** `s = ['h', 'e', 'l', 'l', 'o']`

| i | j | Before Swap | After Swap |
|---|---|-------------|------------|
| 0 | 4 | h...o | o...h → ['o','e','l','l','h'] |
| 1 | 3 | e...l | l...e → ['o','l','l','e','h'] |
| 2 | 2 | i==j, stop | |

**Output:** `['o', 'l', 'l', 'e', 'h']`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each element is visited at most once (n/2 swaps) |
| **Space** | O(1) | Only one temporary character variable; reversal is in-place |
