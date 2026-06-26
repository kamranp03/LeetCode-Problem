# Problem 0069 - Sqrt(x)

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/sqrtx/
**Language:** C++

---

## Problem Statement

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer (i.e., the floor of the square root). You must not use any built-in exponent function or operator.

## Approach: Standard Library `sqrt`

This solution directly delegates to the C++ standard library `sqrt` function from `<cmath>`, which computes the floating-point square root and returns it. The implicit conversion from `double` to `int` truncates toward zero, giving the floor value.

Note: A more interview-appropriate approach (if the problem forbids `sqrt`) would be binary search: find the largest integer `m` such that `m * m <= x`. Binary search over the range `[0, x]` gives an O(log x) solution.

## Code Walkthrough (Step by Step)

1. Call `sqrt(x)` — computes the floating-point square root.
2. Return the result (implicitly cast to `int` by the function return type, which truncates the decimal part).

**Alternative Binary Search Approach (for reference):**
```
int low = 0, high = x, ans = 0;
while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (mid * mid <= x) { ans = mid; low = mid + 1; }
    else high = mid - 1;
}
return ans;
```

## Dry Run

**Example Input:** `x = 8`

`sqrt(8) = 2.828...` → truncate to `int` → `2`

**Output:** `2` (since 2² = 4 ≤ 8 < 9 = 3²)

**Example Input:** `x = 4`

`sqrt(4) = 2.0` → `2`

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Single library call (constant time) |
| **Space** | O(1) | No extra memory |

*Binary search alternative: O(log x) time, O(1) space.*
