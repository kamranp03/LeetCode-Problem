# Problem 717 - 1-bit and 2-bit Characters

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/1-bit-and-2-bit-characters/
**Language:** C++

---

## Problem Statement
We have a special encoding where:
- A 1-bit character is represented by a single `0`.
- A 2-bit character is represented by `10` or `11`.

Given a binary array `bits` that always ends with `0`, determine if the last character must be a 1-bit character. Return `true` if the last character is a 1-bit character, `false` otherwise.

## Approach: Greedy Linear Scan

The key insight is to simulate the decoding greedily from left to right. Whenever we see a `1`, it must start a 2-bit character, so we skip the next bit too (advance by 2). When we see a `0`, it is a 1-bit character (advance by 1). If we land exactly on the last index `n-1`, the last character was a 1-bit character.

## Code Walkthrough (Step by Step)

1. **Initialize:** `i = 0` (current position), `n = bits.size()`.

2. **Loop while `i < n - 1`** (stop before the last element — we're checking if the last element is reached as a 1-bit char):
   - If `bits[i] == 1`: This is a 2-bit character. Skip 2 positions: `i += 2`.
   - If `bits[i] == 0`: This is a 1-bit character. Skip 1 position: `i += 1`.

3. **Return `i == n - 1`:** If we stopped exactly at the last index, it means the last character was a standalone 0 (1-bit). If we overshot (i == n), it was consumed as part of a 2-bit character.

## Dry Run

**Example Input:** `bits = [1, 0, 0]`, n=3

- i=0: bits[0]=1 → 2-bit char → i=2
- i=2: i is NOT < n-1 (2 is not < 2) → stop
- i == n-1 → 2 == 2 → return `true`

**Example Input:** `bits = [1, 1, 0]`, n=3

- i=0: bits[0]=1 → 2-bit char → i=2
- i=2: stop (i not < 2)
- return 2 == 2 → `true`? Wait: the last char is the 0 at position 2 but it was reached standalone after the 2-bit "11". So yes: `true`.

**Example Input:** `bits = [1, 0]`, n=2

- i=0: bits[0]=1 → i=2
- i=2: stop (2 not < 1)
- return 2 == 1? → `false` (the 0 was consumed as part of the 2-bit "10")

**Output:** `true` for [1,0,0], `false` for [1,0]

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single left-to-right scan, each bit visited at most once |
| **Space** | O(1) | Only one index variable |
