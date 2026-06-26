# Problem 0022 - Generate Parentheses

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/generate-parentheses/
**Language:** C++

---

## Problem Statement

Given `n` pairs of parentheses, generate all combinations of well-formed (valid) parentheses strings. A valid combination has exactly `n` opening and `n` closing parentheses, properly nested.

## Approach: Backtracking with Open/Close Counters

The key insight is that a valid combination can be built character by character using two rules: (1) we can add an opening `(` as long as we've used fewer than `n` opening brackets; (2) we can add a closing `)` only if the count of closing brackets is less than the count of opening brackets (ensuring proper nesting). These constraints prune the search space so only valid strings are generated.

## Code Walkthrough (Step by Step)

1. **Recursive function `fun(open, close, n, temp, res)`:**
   - `open` = number of `(` used so far.
   - `close` = number of `)` used so far.
   - `temp` = current string being built.
2. **Base case:** if `open == n && close == n`, we have a complete valid string — add `temp` to `res` and return.
3. **Add opening bracket:** if `open < n`, push `(`, recurse with `open+1`, then pop back (backtrack).
4. **Add closing bracket:** if `close < open`, push `)`, recurse with `close+1`, then pop back (backtrack).
5. **`generateParenthesis`** initializes `open=0`, `close=0`, `temp=""` and calls `fun`.

## Dry Run

**Example Input:** `n = 2`

```
fun(0,0): add '('
  fun(1,0): add '('
    fun(2,0): can't add '('; add ')'
      fun(2,1): add ')'
        fun(2,2): push "(())" ✓
  fun(1,0): add ')'
    fun(1,1): add '('
      fun(2,1): add ')'
        fun(2,2): push "()()" ✓
```

**Output:** `["(())", "()()"]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(4^n / sqrt(n)) | The number of valid combinations is the n-th Catalan number |
| **Space** | O(n) | Recursion depth is at most 2n (n opening + n closing) |
