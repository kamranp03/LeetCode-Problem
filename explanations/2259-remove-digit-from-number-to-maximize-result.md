# Problem 2259 - Remove Digit From Number to Maximize Result

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
**Language:** C++

---

## Problem Statement
Given a string `number` and a character `digit`, remove exactly one occurrence of `digit` from `number` to maximize the resulting number. Return the resulting number as a string.

## Approach: Greedy — Remove Leftmost Occurrence Where Next Digit Is Larger

The key insight is: to maximize the resulting number, remove the leftmost occurrence of `digit` where the next character is strictly greater than `digit`. Removing such a position brings a larger digit "forward," increasing the number. If no such position exists (every occurrence of `digit` is followed by an equal or smaller digit, or is the last character), remove the last occurrence of `digit` (which minimizes the "damage" since the remaining suffix is non-increasing).

## Code Walkthrough (Step by Step)

1. **Initialize `idx = -1`** (tracks the best index to remove).
2. **Loop through `number`**:
   - If `number[i] == digit`: update `idx = i` (track the latest occurrence seen so far).
   - If additionally `number[i+1] > number[i]` (next digit is larger): record this `idx` and `break` — this is the optimal removal point.
3. **Erase** character at `idx` from `number`.
4. **Return `number`**.

## Dry Run

**Example Input:** `number = "123", digit = '3'`

- i=0: '1' != '3', skip
- i=1: '2' != '3', skip
- i=2: '3' == '3' → idx=2. No next character (i+1 out of bounds, condition false). Loop ends.
- Erase index 2.

**Output:** `"12"`

**Another Example:** `number = "1231", digit = '1'`

- i=0: '1'=='1' → idx=0. number[1]='2' > '1' → break immediately.
- Erase index 0.

**Output:** `"231"` (better than erasing the last '1' to get "123")

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single linear scan through the string + O(n) erase |
| **Space** | O(1) | In-place modification; only one index variable |
