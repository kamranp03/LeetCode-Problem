# Problem 868 - Binary Gap

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-gap/
**Language:** C++

---

## Problem Statement
Given a positive integer `n`, find the longest distance between any two consecutive 1-bits in the binary representation of `n`. If there are fewer than two 1-bits, return 0. The distance between two 1-bits at positions `i` and `j` (0-indexed from LSB) is `|i - j|`.

## Approach: Single Pass Bit Scan

Scan all 32 bit positions from LSB (bit 0) to MSB (bit 31). Keep track of the position of the most recently seen 1-bit (`prev`). Whenever a new 1-bit is found at position `curr`, compute `curr - prev` and update the running maximum. Then update `prev = curr` for the next gap calculation.

## Code Walkthrough (Step by Step)

1. **Initialize:** `prev = -1` (no previous 1-bit seen), `res = 0`.

2. **Loop `curr` from 0 to 31:**
   - Extract bit at position `curr` using `(n >> curr) & 1`.
   - If the bit is 1:
     - If `prev != -1`, update `res = max(res, curr - prev)`.
     - Set `prev = curr`.

3. **Return `res`** — the maximum gap between consecutive 1-bits.

## Dry Run

**Example Input:** `n = 22` (binary: `10110`)

| Bit Position | Bit Value | prev | res |
|-------------|-----------|------|-----|
| 0           | 0         | -1   | 0   |
| 1           | 1         | -1   | 0   → prev=1 |
| 2           | 1         | 1    | max(0,2-1)=1 → prev=2 |
| 3           | 0         | 2    | 1   |
| 4           | 1         | 2    | max(1,4-2)=2 → prev=4 |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Always loops exactly 32 times regardless of input |
| **Space** | O(1) | Only a few integer variables |
