# Problem 287 - Find the Duplicate Number

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/find-the-duplicate-number/
**Language:** C++

---

## Problem Statement
Given an array of `n + 1` integers where each integer is between 1 and `n` inclusive, there is exactly one repeated number. Find and return that duplicate without modifying the array.

## Approach: Hash Set Membership Check

The key insight is to track which numbers we have already seen using an unordered set. As we scan the array, the first number we encounter that is already in the set must be the duplicate. This approach is simple and runs in linear time.

## Code Walkthrough (Step by Step)

1. **Initialize empty set `m`:** This will store all numbers we have seen so far.

2. **Scan array:** For each number `x` in `nums`:
   - Check if `x` is already in `m` using `m.find(x) != m.end()`.
   - If yes: `x` is the duplicate — return `x` immediately.
   - If no: Insert `x` into `m` and continue.

3. **Return -1** as a fallback (should never be reached given valid input).

## Dry Run

**Example Input:** `nums = [1, 3, 4, 2, 2]`

| Step | x | Set m | Action |
|------|---|-------|--------|
| 1 | 1 | {} | not found → insert 1 → {1} |
| 2 | 3 | {1} | not found → insert 3 → {1,3} |
| 3 | 4 | {1,3} | not found → insert 4 → {1,3,4} |
| 4 | 2 | {1,3,4} | not found → insert 2 → {1,3,4,2} |
| 5 | 2 | {1,3,4,2} | FOUND → return 2 |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each element is processed once; hash set operations are O(1) average |
| **Space** | O(n) | The set stores up to n elements before finding the duplicate |
