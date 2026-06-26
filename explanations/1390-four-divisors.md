# Problem 1390 - Four Divisors

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/four-divisors/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer, return 0.

## Approach: Trial Division with Early Exit

The key insight is to find divisors by iterating up to the square root. For each divisor `fact`, we find its pair `other = num / fact`. We track the count and sum of divisors. If the count ever exceeds 4, we exit early. At the end, if the count is exactly 4, we add the sum to the result.

## Code Walkthrough (Step by Step)

1. **`findFact(num)`:** Iterates `fact` from 1 to sqrt(num).
   - If `fact` divides `num`: if `fact == other` (perfect square), add 1 divisor; else add 2 divisors (both `fact` and `other`).
   - **Early exit:** If `divisor > 4`, return 0 (too many divisors).
2. **After loop:** Return `sum` if `divisor == 4`, else return 0.
3. **`sumFourDivisors(nums)`:** Calls `findFact` for each element and accumulates the results into `res`.

## Dry Run

**Example Input:** `nums = [21, 4]`

- num=21: divisors are 1, 3, 7, 21 → count=4, sum=32 → qualifies
- num=4: divisors are 1, 2, 4 → count=3 → does not qualify
- Result = 32

**Output:** `32`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * sqrt(max_val)) | For each number, iterate up to its square root |
| **Space** | O(1) | Only counters and sums used |
