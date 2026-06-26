# Problem 1404 - Number of Steps to Reduce a Number in Binary Representation to One

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
**Language:** C++

---

## Problem Statement

Given a binary string `s` representing a positive integer, return the number of steps to reduce it to 1 under the rules: if the number is even, divide by 2; if odd, add 1.

## Approach: Simulate with Carry Propagation (Right to Left)

The key insight is to process the binary string from the least significant bit (right) to the most significant bit (left), simulating the operations. A '1' bit plus any carry means the number is odd → add 1 (2 steps: add then right-shift), producing a carry. A '0' bit with no carry → just right-shift (1 step). We accumulate all carries from the leftmost bit.

## Code Walkthrough (Step by Step)

1. **Initialize `steps = 0`, `carry = 0`.**
2. **Iterate from `i = s.length()-1` down to `i = 1`** (stop before index 0, the most significant bit).
3. **Check `(s[i] - '0' + carry) % 2 == 1`:** If the current bit plus carry is odd (value is 1), it means the number is odd at this position — we add 1 (carries up) and divide by 2. That's **2 steps** and we set `carry = 1`.
4. **Otherwise (even):** Just divide by 2 — **1 step**, no carry change.
5. **Return `steps + carry`:** The remaining carry at the end adds 1 more step if the MSB needs incrementing.

## Dry Run

**Example Input:** `s = "1101"`

- i=3: bit='1', carry=0 → odd → steps+=2=2, carry=1
- i=2: bit='0', carry=1 → (0+1)%2=1 → odd → steps+=2=4, carry=1
- i=1: bit='1', carry=1 → (1+1)%2=0 → even → steps+=1=5, carry stays 1
- Return 5 + 1 (carry) = **6**

**Output:** `6`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the binary string |
| **Space** | O(1) | Only step and carry counters |
