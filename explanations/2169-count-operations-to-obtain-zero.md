# Problem 2169 - Count Operations to Obtain Zero

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/count-operations-to-obtain-zero/
**Language:** C++

---

## Problem Statement
Given two non-negative integers `num1` and `num2`, in each operation subtract the smaller from the larger (or equivalently, take the larger modulo the smaller). Count the number of operations needed until one of them becomes 0.

## Approach: Optimized Subtraction Using Division (GCD-like)

The key insight is that repeatedly subtracting `num2` from `num1` is equivalent to computing `num1 / num2` operations at once (adding the quotient to count and replacing `num1` with `num1 % num2`). This is the Euclidean algorithm for GCD, and it's dramatically faster than doing one subtraction at a time.

## Code Walkthrough (Step by Step)

1. **Initialize `count = 0`**.
2. **While both `num1 != 0` and `num2 != 0`**:
   - If `num1 >= num2`: perform `count += num1 / num2` operations at once, set `num1 = num1 % num2`.
   - Else: perform `count += num2 / num1` operations, set `num2 = num2 % num1`.
3. **Return `count`** once one of them hits 0.

## Dry Run

**Example Input:** `num1 = 2, num2 = 3`

| Step | num1 | num2 | condition  | ops added | count |
|------|------|------|------------|-----------|-------|
| 1    | 2    | 3    | num2>num1  | 3/2=1     | 1     |
|      |      |      |            | num2=3%2=1|       |
| 2    | 2    | 1    | num1>=num2 | 2/1=2     | 3     |
|      |      |      |            | num1=2%1=0|       |

num1=0, loop ends.

**Output:** `3`

**Verification:** Starting from (2,3):
- op1: 3>2 → 3-2=1 → (2,1)
- op2: 2>1 → 2-1=1 → (1,1)
- op3: 1>=1 → 1-1=0 → (0,1) ✓

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log(min(num1, num2))) | Same as GCD via Euclidean algorithm — exponentially faster than naive subtraction |
| **Space** | O(1) | Only a counter and the two numbers |
