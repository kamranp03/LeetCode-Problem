# Problem 0013 - Roman to Integer

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/roman-to-integer/
**Language:** C++

---

## Problem Statement

Given a string `s` representing a Roman numeral, convert it to an integer. Roman numerals use the symbols I(1), V(5), X(10), L(50), C(100), D(500), M(1000), and apply a subtraction rule when a smaller value precedes a larger one (e.g., IV = 4, IX = 9).

## Approach: Single-Pass with Previous Value Tracking

The key insight is that in a valid Roman numeral, a character should be subtracted (not added) only when the previous character's value is less than the current character's value. We track the previously seen value (`scndLst`) and if the current value is greater, we correct by subtracting twice the previous value (once to undo the addition we already made, once for the actual subtraction).

## Code Walkthrough (Step by Step)

1. **Initialize** `ans = 0`, `scndLst = 0` (previous character value), `curr = 0`.
2. **Iterate through each character `c` in `s`:**
   - **Map the character** to its integer value and store in `curr`.
   - **Add `curr` to `ans`** (assume additive).
   - **Check for subtraction rule:** if `scndLst < curr`, it means the previous character should have been subtracted. Correct: `ans -= 2 * scndLst` (undo the previous addition and apply subtraction).
   - **Update `scndLst = curr`** for the next iteration.
3. **Return `ans`.**

## Dry Run

**Example Input:** `s = "XIV"` (= 14)

| char | curr | ans before correction | scndLst < curr? | correction | ans after | scndLst |
|------|------|-----------------------|-----------------|------------|-----------|---------|
| X    | 10   | 10                    | 0 < 10? Yes     | -2*0=0     | 10        | 10      |
| I    | 1    | 11                    | 10 < 1? No      | none       | 11        | 1       |
| V    | 5    | 16                    | 1 < 5? Yes      | -2*1=-2    | 14        | 5       |

**Output:** `14`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the string |
| **Space** | O(1) | Only a fixed number of integer variables |
