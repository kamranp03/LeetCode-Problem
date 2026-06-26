# Problem 1545 - Find Kth Bit in Nth Binary String

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
**Language:** C++

---

## Problem Statement

The binary string S_n is defined recursively: S_1 = "0", and S_{n} = S_{n-1} + "1" + reverse(invert(S_{n-1})). Given `n` and `k`, find the `k`-th bit (1-indexed) in S_n.

## Approach: Recursive Divide and Conquer

The key insight is that S_n has length `2^n - 1`, with a middle bit always equal to '1', a left half identical to S_{n-1}, and a right half that is the reverse-invert of S_{n-1}. We can recursively determine the answer without constructing the full string:
- If k equals the middle position, return '1'.
- If k is in the left half, recurse into S_{n-1} at the same position.
- If k is in the right half, map it to its mirror in S_{n-1} and flip the result.

## Code Walkthrough (Step by Step)

1. **Base case:** `n == 1` → S_1 = "0", return '0'.
2. **Compute length:** `len = (1 << n) - 1` and `mid = (len + 1) / 2`.
3. **If `k == mid`:** Return '1' (the inserted middle bit).
4. **If `k < mid`:** Recurse with `findKthBit(n-1, k)` — same position in smaller string.
5. **If `k > mid`:** Mirror position in S_{n-1} is `len - k + 1`. Recurse and flip the result (invert: '0'↔'1').

## Dry Run

**Example Input:** `n = 3`, `k = 1`

- S_3 = "0111001", len=7, mid=4
- k=1 < mid=4 → recurse to S_2, k=1
- S_2 = "011", len=3, mid=2
- k=1 < mid=2 → recurse to S_1, k=1
- S_1 base case → return **'0'**

**Output:** `'0'`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Recursion depth is at most n |
| **Space** | O(n) | Recursion call stack of depth n |
