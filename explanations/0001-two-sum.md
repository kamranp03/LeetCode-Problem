# Problem 0001 - Two Sum

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/two-sum/
**Language:** C++

---

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to `target`. Each input has exactly one solution, and you may not use the same element twice.

## Approach: Hash Map (One-Pass)

The key insight is that for every element `nums[i]`, we need its complement `target - nums[i]`. Instead of checking every pair (O(n²)), we store each number and its index in a hash map as we go. Before inserting `nums[i]`, we check if its complement already exists in the map — if so, we've found our pair in O(1) lookup time.

## Code Walkthrough (Step by Step)

1. **Create an empty hash map** `mp` mapping integer values to their indices.
2. **Iterate through the array** with index `i`.
3. **Compute the complement** `need = target - nums[i]` — this is the value we're looking for.
4. **Check if `need` is already in the map.** If yes, return `{mp[need], i}` (the stored index and the current index).
5. **If not found**, store `nums[i]` → `i` in the map for future lookups.
6. **Return `{}`** if no solution found (won't happen per problem constraints).

## Dry Run

**Example Input:** `nums = [2, 7, 11, 15]`, `target = 9`

| i | nums[i] | need (9 - nums[i]) | mp contains need? | mp after step |
|---|---------|---------------------|-------------------|---------------|
| 0 | 2       | 7                   | No                | {2→0}         |
| 1 | 7       | 2                   | Yes (index 0)     | return {0, 1} |

**Output:** `[0, 1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through the array; each hash map lookup/insert is O(1) average |
| **Space** | O(n) | Hash map stores at most n elements |
