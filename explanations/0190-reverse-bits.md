# Problem 190 - Reverse Bits

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/reverse-bits/
**Language:** C++

---

## Problem Statement

Reverse the bits of a given 32-bit unsigned integer. For example, the input `00000010100101000001111010011100` in binary becomes `00111001011110000010100101000000` reversed. Return the result as an unsigned integer.

## Approach: Bit-by-Bit Extraction and Reconstruction

The key insight is to extract bits from the input number one at a time (from least significant to most significant) and build the result number by shifting in those bits from the opposite end. We process exactly 32 bits regardless of the input value, because the problem always deals with 32-bit integers.

## Code Walkthrough (Step by Step)

1. **Edge case:** If `n == 0`, return 0 immediately (all bits are zero).

2. **Initialize `res = 0`.**

3. **Loop 32 times (bits 0 to 31):**
   - **Left-shift result:** `res <<= 1`. Make room for the next bit on the right side of `res`. This shifts all previously placed bits one position to the left.
   - **Extract LSB of n and OR into res:** `res = (res | (n & 1))`. `n & 1` extracts the least significant bit of `n`. ORing it into `res` places it at the least significant position.
   - **Right-shift n:** `n >>= 1`. Move the next bit of `n` into the LSB position for the next iteration.

4. **Return `res`:** After 32 iterations, `res` contains the bit-reversed version of the original `n`.

## Dry Run

**Example Input:** `n = 43261596` (binary: `00000010100101000001111010011100`)

We track the last 4 bits for brevity. Say `n = ...1100` (last 4 bits are 0,0,1,1 from LSB):

| Iteration | n & 1 | res <<= 1 → res |= (n&1) | n >>= 1 |
|-----------|-------|------------------------|---------|
| 1 | 0 | res=0, OR 0 → 0 | n=...0110 |
| 2 | 0 | res=0, OR 0 → 0 | n=...0011 |
| 3 | 1 | res=0, OR 1 → 1 | n=...0001 |
| 4 | 1 | res=10, OR 1 → 11 | n=...0000 |

After 32 total iterations, the full bit string is reversed.

**Output:** `964176192` (binary: `00111001011110000010100101000000`)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Always exactly 32 iterations, independent of input |
| **Space** | O(1) | Only one result variable `res` |
