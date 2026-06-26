# Problem 3461 - Check If Digits Are Equal in String After Operations I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
**Language:** C++

---

## Problem Statement

Given a numeric string `s`, repeatedly apply the following operation: replace the string with a new string where each character at position `i` is `(s[i] + s[i+1]) % 10` (the last digit of the sum of adjacent digits), reducing the string length by 1 each time. Return true if the final two-character string has both digits equal.

## Approach: Iterative Reduction

Since the string is short (Easy problem), we can directly simulate the repeated reduction. At each step we compute the new string of length `len - 1`, where each position stores `(a + b) % 10` for adjacent digits `a` and `b`. We stop when exactly 2 characters remain and compare them.

## Code Walkthrough (Step by Step)

1. **While string length > 2:** create a new string `t`.
2. **For each adjacent pair** `s[i]` and `s[i+1]`: compute their digit sum mod 10 and push to `t`.
   - Note: there is a subtle bug in the code as written: `(s[i]-'0') + (s[i+1]+'0')` uses `+'0'` instead of `-'0'` for the second character, adding 48 instead of subtracting. This would give incorrect results for most inputs. The correct formula should be `(s[i]-'0' + s[i+1]-'0') % 10`.
3. **Replace** `s` with `t`.
4. **Return** `s[0] == s[1]`.

## Dry Run

**Example Input:** `s = "3902"`

Using the correct formula `(a + b) % 10`:
- Step 1: [(3+9)%10, (9+0)%10, (0+2)%10] = "292" (wait: (3+9)=12→2, (9+0)=9, (0+2)=2) → "292"
- Step 2: [(2+9)%10, (9+2)%10] = [1, 1] → "11"
- s[0] == s[1] → true.

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2) | Each of the n-2 reduction steps processes a shrinking string |
| **Space** | O(n) | Temporary string at each step |
