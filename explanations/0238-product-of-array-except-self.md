# Problem 238 - Product of Array Except Self

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/product-of-array-except-self/
**Language:** C++

---

## Problem Statement
Given an integer array `nums`, return an array `answer` such that `answer[i]` equals the product of all elements in `nums` except `nums[i]`. You must solve it in O(n) time without using the division operation.

## Approach: Prefix Product + Suffix Product (Single Array)

The key insight is that the product of everything except `nums[i]` equals `(product of all elements to the left of i)` times `(product of all elements to the right of i)`. We first fill `ans` with prefix products (left pass), then multiply each position by its suffix product (right pass using a running variable). No extra array is needed for the suffix.

## Code Walkthrough (Step by Step)

1. **Initialize `ans`** as an array of size `n` filled with 1.

2. **Left pass (prefix products):** For each index `i` from 1 to n-1, set `ans[i] = ans[i-1] * nums[i-1]`. After this pass, `ans[i]` holds the product of all elements to the LEFT of index `i`.

3. **Right pass (suffix products):** Maintain a running variable `suffix = 1`. Traverse from index `n-2` down to 0:
   - Multiply `suffix` by `nums[i+1]` (the element to the right of current i).
   - Multiply `ans[i]` by `suffix`.

4. **Return `ans`:** Each `ans[i]` now holds left-product × right-product = product of all except self.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 4]`

After left pass:
- `ans[0] = 1` (no left elements)
- `ans[1] = 1 * 1 = 1`
- `ans[2] = 1 * 2 = 2`
- `ans[3] = 2 * 3 = 6`

`ans = [1, 1, 2, 6]`

Right pass (suffix starts at 1):
- `i=2`: suffix = 1 * 4 = 4, ans[2] = 2 * 4 = 8
- `i=1`: suffix = 4 * 3 = 12, ans[1] = 1 * 12 = 12
- `i=0`: suffix = 12 * 2 = 24, ans[0] = 1 * 24 = 24

**Output:** `[24, 12, 8, 6]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two linear passes over the array |
| **Space** | O(1) | Output array doesn't count as extra; only one suffix variable used |
