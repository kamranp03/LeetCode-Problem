# Problem 3606 - Coupon Code Validator

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/coupon-code-validator/
**Language:** C++

---

## Problem Statement

Given arrays of coupon `code`, `businessLine`, and `isActive` flags, filter and sort valid coupons. A coupon is valid if: it is active (`isActive[i] == true`), its business line is one of {"electronics", "grocery", "pharmacy", "restaurant"}, and its code is non-empty with only alphanumeric characters or underscores. Return valid coupon codes sorted by business line priority first, then lexicographically.

## Approach: Filter and Sort

Apply each validity condition in sequence, discard invalid coupons, then sort valid ones by (businessLine priority, code) using a pair to leverage default pair sorting.

## Code Walkthrough (Step by Step)

1. **Define** a set of valid business lines and a priority map (electronics=0, grocery=1, pharmacy=2, restaurant=3).
2. **For each coupon:**
   a. Skip if `isActive[i]` is false.
   b. Skip if `businessLine[i]` is not in valid lines.
   c. Skip if `code[i]` is empty.
   d. Skip if `code[i]` contains any character that is not alphanumeric or `_`.
   e. Push `{priority, code}` into `validCoupons`.
3. **Sort** `validCoupons` (sorts by priority first, then lexicographically by code).
4. **Extract** codes from sorted pairs and return.

## Dry Run

**Example Input:**
- code = ["SAVE10", "DEAL!", "PROMO_1"], businessLine = ["grocery", "electronics", "pharmacy"], isActive = [true, true, true]

- "SAVE10": active, grocery (valid), non-empty, only alnum → push {1, "SAVE10"}.
- "DEAL!": active, electronics (valid), '!' is invalid char → skip.
- "PROMO_1": active, pharmacy (valid), only alnum/_ → push {2, "PROMO_1"}.

- Sorted: [(1,"SAVE10"), (2,"PROMO_1")].

**Output:** `["SAVE10", "PROMO_1"]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * L + m log m) | m coupons, L = max code length; sorting m items |
| **Space** | O(m) | Storing valid coupons |
