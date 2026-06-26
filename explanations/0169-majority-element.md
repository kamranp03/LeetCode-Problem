# Problem 169 - Majority Element

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/majority-element/
**Language:** C++

---

## Problem Statement

Given an array `nums` of size `n`, return the majority element. The majority element is the element that appears more than `n / 2` times. You may assume that the majority element always exists in the array.

## Approach: Frequency Map (Hash Map Counting)

The key insight is to count the frequency of each element using a hash map (here a `map<int,int>`), then scan the map to find the element whose count exceeds `n/2`. Since the majority element is guaranteed to exist, exactly one element will satisfy this condition.

## Code Walkthrough (Step by Step)

1. **Count frequencies:** Iterate over `nums` with index `i`. For each element, increment `mp[nums[i]]`. After the loop, `mp` maps each distinct value to its occurrence count.

2. **Find the majority:** Iterate over the map entries (`it.first` = value, `it.second` = count). If `it.second > n/2`, this is the majority element — return `it.first`.

3. **Fallback return `-1`:** Unreachable in valid inputs since the problem guarantees a majority element exists.

**Note:** A more optimal approach is Boyer-Moore Voting (O(n) time, O(1) space), but this frequency map approach is clear and correct.

## Dry Run

**Example Input:** `nums = [3, 2, 3]`, n=3

- Count pass: `mp = {3:2, 2:1}`
- Check map:
  - `{2, 1}`: 1 > 3/2=1? No (1 is not > 1).
  - `{3, 2}`: 2 > 1? Yes! Return 3.

**Output:** `3`

**Example 2:** `nums = [2, 2, 1, 1, 1, 2, 2]`, n=7

- `mp = {1:3, 2:4}`
- 4 > 7/2=3 → return 2.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | One pass to build the map + one pass over distinct values (at most n) |
| **Space** | O(n) | Map stores at most n distinct elements |
