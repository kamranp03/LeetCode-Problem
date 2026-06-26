# Problem 0067 - Add Binary

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/add-binary/
**Language:** C++

---

## Problem Statement

Given two binary strings `a` and `b`, return their sum as a binary string. The input strings are non-empty and contain only `'0'` or `'1'` characters.

## Approach: Bit-by-Bit Addition with Carry

The key insight is to simulate binary addition exactly as you would do it by hand — from right to left (least significant bit to most significant). We use a single `carry` variable that accumulates the sum of the two current bits plus any carry from the previous position. `carry % 2` gives the current result bit, and `carry / 2` gives the new carry. After processing all bits, we reverse the result string (since we built it right-to-left).

## Code Walkthrough (Step by Step)

1. **Initialize** `carry = 0`, `i = a.length() - 1`, `j = b.length() - 1`, and an empty `res` string.
2. **Loop while `i >= 0` or `j >= 0` or `carry != 0`:**
   - If `i >= 0`: add `a[i] - '0'` to `carry` (converts char digit to int), decrement `i`.
   - If `j >= 0`: add `b[j] - '0'` to `carry`, decrement `j`.
   - Append `(carry % 2) + '0'` to `res` (current result bit as a character).
   - Update `carry = carry / 2` (0 if sum was 0 or 1; 1 if sum was 2 or 3).
3. **Reverse `res`** (since we appended from LSB to MSB).
4. **Return `res`.**

## Dry Run

**Example Input:** `a = "11"`, `b = "1"`

`i = 1`, `j = 0`, `carry = 0`

| Iteration | i  | j  | carry before | bits added  | carry after | res bit | res    |
|-----------|----|----|--------------|-------------|-------------|---------|--------|
| 1         | 1  | 0  | 0            | a[1]='1'→1, b[0]='1'→1 | 2 | 2%2=0 → '0' | "0" |
| 2         | 0  | -1 | 1 (carry=2/2=1) | a[0]='1'→1 | 2 | 2%2=0 → '0' | "00" |
| 3         | -1 | -1 | 1 (carry=2/2=1) | none | 1 | 1%2=1 → '1' | "001" |
| 4         | loop ends (carry=0)  |

Reverse "001" → "100"

**Output:** `"100"` (which is 3 in decimal: 2+1=3 ✓)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(max(m, n)) | We process as many bits as the longer of the two strings |
| **Space** | O(max(m, n)) | Result string is at most one bit longer than the longer input |
