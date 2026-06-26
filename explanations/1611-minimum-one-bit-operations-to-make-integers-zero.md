# Problem 1611 - Minimum One Bit Operations to Make Integers Zero

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
**Language:** C++

---

## Problem Statement

Given an integer `n`, return the minimum number of operations to reduce it to 0. In one operation, you can either flip the rightmost bit, or flip the bit immediately to the right of the rightmost '1' bit.

## Approach: Gray Code / Bit DP

The key insight comes from recognizing that the minimum steps to go from `2^i` to 0 is `f[i] = 2*f[i-1] + 1` (a Gray code distance formula). For an arbitrary `n`, we decompose it bit by bit from the most significant bit and alternate adding/subtracting the precomputed `f[i]` values, using a toggling sign.

## Code Walkthrough (Step by Step)

1. **Base case:** If `n == 0`, return 0.
2. **Precompute `f[i]`:** `f[0] = 1`, `f[i] = 2*f[i-1] + 1`. This gives minimum steps to zero from `2^i`.
3. **Process bits of n from bit 30 down to bit 0:**
   - Check if bit `i` is set in `n` using `(1 << i) & n`.
   - If set, add or subtract `f[i]` based on the current `sign` (alternating +/-).
   - Toggle the sign after each set bit.
4. **Return `result`.**

## Dry Run

**Example Input:** `n = 3` (binary: 11)

- f[0]=1, f[1]=3
- Bit 1 is set: result += f[1] = 3; sign becomes -1
- Bit 0 is set: result -= f[0] = 3-1 = 2; sign becomes +1
- Return **2**

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Process at most 31 bits of n |
| **Space** | O(1) | Fixed array of size 31 |
