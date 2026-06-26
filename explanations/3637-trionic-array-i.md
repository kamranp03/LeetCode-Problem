# Problem 3637 - Trionic Array I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/trionic-array-i/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, return true if the array is "trionic" — meaning it consists of exactly three phases: strictly increasing, then strictly decreasing, then strictly increasing again, with each phase containing at least one step. The array must have at least 4 elements.

## Approach: Three-Phase Sequential Scan

Scan through the array tracking which phase we're in. Phase 1: strictly increasing. Phase 2: strictly decreasing. Phase 3: strictly increasing again. All phases must be non-empty, and the entire array must be consumed.

## Code Walkthrough (Step by Step)

1. **Return false** if `n < 4` (can't have 3 non-empty phases with at least 1 step each).
2. **Phase 1 (increasing):** advance `i` while `nums[i] < nums[i+1]`. If `i == 0`, no increase happened → return false.
3. **Phase 2 (decreasing):** advance `i` while `nums[i] > nums[i+1]`. This phase can be empty only if i == n-1 — but check after.
4. **Check:** if `i == n-1` after phase 2, the third phase is missing → return false.
5. **Phase 3 (increasing again):** advance `i` while `nums[i] < nums[i+1]`, set `thirdIncrease = true`.
6. **Return** `thirdIncrease && i == n-1` (third phase existed and we consumed all elements).

## Dry Run

**Example Input:** `nums = [1, 3, 5, 4, 2, 3, 6]`

- Phase 1: 1<3<5, i=2. (i>0, ok)
- Phase 2: 5>4>2, i=4. (i<n-1=6)
- Phase 3: 2<3<6, thirdIncrease=true, i=6=n-1.
- Return true.

**Example Input:** `nums = [1, 2, 3, 2]`

- Phase 1: 1<2<3, i=2.
- Phase 2: 3>2, i=3=n-1. Return false (no third phase).

**Output:** `true` and `false` respectively.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single linear scan |
| **Space** | O(1) | Only index and boolean variables |
