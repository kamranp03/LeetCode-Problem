# Problem 1018 - Binary Prefix Divisible By 5

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-prefix-divisible-by-5/
**Language:** C++

---

## Problem Statement
Given a binary array `nums` representing binary digits, for each prefix of the array (treating it as a binary number), determine whether that binary number is divisible by 5. Return a boolean array where `answer[i]` is true if the binary number formed by `nums[0..i]` is divisible by 5.

## Approach: Running Modular Arithmetic

The key insight is that we only need the remainder modulo 5 — not the full number (which can be astronomically large). When we append a new bit, the number becomes `prev * 2 + bit`. So the remainder updates as `rem = (rem * 2 + bit) % 5`. If `rem == 0`, the current prefix is divisible by 5.

## Code Walkthrough (Step by Step)

1. **Initialize:** `rem = 0` (empty prefix is 0, divisible by 5).

2. **Iterate** over each `bit` in `nums`:
   - Update: `rem = (rem * 2 + bit) % 5`.
     - `rem * 2` shifts the current number left by one bit.
     - `+ bit` appends the new bit.
     - `% 5` keeps only the remainder.
   - Push `rem == 0` to `ans`.

3. **Return `ans`.**

## Dry Run

**Example Input:** `nums = [0, 1, 1, 1, 1, 1]`

| i | bit | rem = (rem*2+bit)%5 | rem==0? |
|---|-----|---------------------|---------|
| 0 | 0   | (0*2+0)%5 = 0       | true    |
| 1 | 1   | (0*2+1)%5 = 1       | false   |
| 2 | 1   | (1*2+1)%5 = 3       | false   |
| 3 | 1   | (3*2+1)%5 = 2       | false   |
| 4 | 1   | (2*2+1)%5 = 0       | true    |
| 5 | 1   | (0*2+1)%5 = 1       | false   |

Binary prefixes: 0(0), 01(1), 011(3), 0111(7), 01111(15), 011111(31)
Divisible by 5: 0(yes), 1(no), 3(no), 7(no), 15(no)... wait: 0÷5=0 (yes), 15÷5=3 (yes)

**Output:** `[true, false, false, false, true, false]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | Single pass through the array |
| **Space** | O(N) | Output boolean array of size N |
