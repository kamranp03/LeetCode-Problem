# Problem 2011 - Final Value of Variable After Performing Operations

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
**Language:** C++

---

## Problem Statement
There is a variable `X` initialized to 0. You are given an array of strings `operations` where each string is one of `"++X"`, `"X++"`, `"--X"`, or `"X--"`. Apply each operation in order and return the final value of `X`.

## Approach: Linear Scan — Check for Increment or Decrement

The key insight is that any operation containing `"++"` increments X by 1, and any containing `"--"` decrements X by 1. Since each string is exactly 3 characters and the variable name can be uppercase or lowercase, we just need to detect whether the operation is an increment or decrement.

## Code Walkthrough (Step by Step)

1. **Initialize `total = 0`**: Represents variable X.
2. **Loop** through each operation string `op[i]`:
   - If `op[i]` is `"++x"`, `"++X"`, `"x++"`, or `"X++"`: increment `total` by 1.
   - Otherwise (it's a decrement operation): decrement `total` by 1.
3. **Return `total`**.

## Dry Run

**Example Input:** `operations = ["--X", "X++", "X++"]`

| i | op    | action      | total |
|---|-------|-------------|-------|
| 0 | --X   | decrement   | -1    |
| 1 | X++   | increment   | 0     |
| 2 | X++   | increment   | 1     |

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single linear scan through all n operations |
| **Space** | O(1) | Only one integer counter maintained |
