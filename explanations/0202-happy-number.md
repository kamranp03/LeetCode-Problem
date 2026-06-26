# Problem 202 - Happy Number

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/happy-number/
**Language:** C++

---

## Problem Statement

A happy number is defined by the following process: starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number either equals 1 (happy) or loops endlessly in a cycle that never includes 1 (not happy). Return `true` if `n` is a happy number, and `false` otherwise.

## Approach: Floyd's Cycle Detection on the Digit-Square Sequence

The key insight is that the "sum of squares of digits" process either terminates at 1 or enters a cycle. This is the same structure as a linked list with a cycle! We apply Floyd's slow/fast pointer algorithm: the slow pointer applies the transformation once, and the fast pointer applies it twice. If they meet at 1, the number is happy. If they meet at any other value, a cycle is detected (not happy).

## Code Walkthrough (Step by Step)

1. **`sqr(n)` helper:** Computes the sum of squares of digits of `n`.
   - Extract the last digit: `d = n % 10`.
   - Add `d * d` to `sum`.
   - Remove the last digit: `n = n / 10`.
   - Repeat until `n > 0`. Return `sum`.

2. **`isHappy(n)` main function:**
   - Initialize `slow = n`, `fast = n`.
   - Enter an infinite loop:
     - `slow = sqr(slow)` — one step.
     - `fast = sqr(sqr(fast))` — two steps.
     - If `fast == 1`, the sequence reached 1 → return `true`.
     - If `slow == fast` (and fast != 1), a non-1 cycle detected → return `false`.

## Dry Run

**Example Input:** `n = 19`

- sqr(19) = 1² + 9² = 1 + 81 = 82
- sqr(82) = 64 + 4 = 68
- sqr(68) = 36 + 64 = 100
- sqr(100) = 1

Floyd's trace:
| Step | slow | fast |
|------|------|------|
| start | 19 | 19 |
| 1 | sqr(19)=82 | sqr(sqr(19))=sqr(82)=68 |
| 2 | sqr(82)=68 | sqr(sqr(68))=sqr(100)=1 |
| — | — | fast==1 → return true |

**Output:** `true`

**Example 2:** `n = 2` → sequence: 2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 (cycle!) → returns `false`.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) per step, O(k) steps | Each sqr call takes O(log n) for digit extraction; cycle length k is bounded by the number of states |
| **Space** | O(1) | Only two pointers; no extra storage |
