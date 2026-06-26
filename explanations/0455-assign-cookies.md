# Problem 455 - Assign Cookies

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/assign-cookies/
**Language:** C++

---

## Problem Statement
You have children with greed factors in array `g` and cookies of sizes in array `s`. A cookie of size `s[j]` can satisfy a child with greed `g[i]` only if `s[j] >= g[i]`. Each child gets at most one cookie. Maximize the number of content children and return that number.

## Approach: Greedy Two-Pointer (Smallest Cookie that Satisfies)

The key insight is the greedy strategy: sort both arrays, then try to satisfy the least greedy child first with the smallest available cookie. If the current cookie is large enough, assign it and advance both pointers. If not, try the next (bigger) cookie. This greedy pairing is optimal because using a larger cookie on a less-greedy child would waste capacity.

## Code Walkthrough (Step by Step)

1. **Sort both arrays** in ascending order.

2. **Initialize pointers** `i = 0` (child pointer) and `j = 0` (cookie pointer), and counter `satis = 0`.

3. **Two-pointer loop:** While both pointers are in bounds:
   - If `g[i] <= s[j]`: The current cookie satisfies the current child. Increment `satis`, and advance both `i` and `j`.
   - Else: The cookie is too small for this child. Try the next (larger) cookie by advancing `j`.

4. **Return `satis`** — the total number of satisfied children.

## Dry Run

**Example Input:** `g = [1, 2, 3]`, `s = [1, 1]`

After sorting: g=[1,2,3], s=[1,1]

| i | j | g[i] | s[j] | Action | satis |
|---|---|------|------|--------|-------|
| 0 | 0 | 1 | 1 | 1<=1: satisfy, i=1, j=1 | 1 |
| 1 | 1 | 2 | 1 | 2>1: cookie too small, j=2 | 1 |
| 1 | 2 | - | - | j out of bounds, stop | 1 |

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n + m log m) | Sorting both arrays; the two-pointer scan is O(n + m) |
| **Space** | O(1) | Only two index variables and a counter |
