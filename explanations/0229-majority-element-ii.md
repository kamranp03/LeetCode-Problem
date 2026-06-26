# Problem 229 - Majority Element II

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/majority-element-ii/
**Language:** C++

---

## Problem Statement
Given an integer array of size `n`, find all elements that appear more than `n/3` times. There can be at most two such elements. Return them in any order.

## Approach: Sort + Sliding Window Check

After sorting the array, any element that appears more than `n/3` times must span a contiguous block of at least `f = n/3 + 1` positions. We start at index `f-1` and check whether the element at that index equals the element `f-1` positions before it (i.e., the same element fills a window of size `f`). If yes, it is a majority element. We then skip all duplicates to avoid counting the same element twice.

## Code Walkthrough (Step by Step)

1. **Sort** the array so equal elements are grouped together.

2. **Compute threshold `f`:** `f = (n/3) + 1` — the minimum frequency needed to be a majority element.

3. **Start at index `i = f - 1`:** This is the first index at which a window of size `f` is complete.

4. **Check window:** If `nums[i] == nums[i - f + 1]`, the element at index `i` (and `i - f + 1`) appears in a block of at least `f` elements. Add it to the answer.

5. **Skip duplicates:** After recording a majority element, advance `i` until the value changes to avoid adding it multiple times.

6. **Otherwise:** Just advance `i` by 1.

## Dry Run

**Example Input:** `nums = [3, 2, 3]`, `n = 3`

After sorting: `[2, 3, 3]`

`f = 3/3 + 1 = 2`, start at `i = 1`

- `i=1`: `nums[1]=3`, `nums[0]=2` → `3 != 2`, advance `i=2`
- `i=2`: `nums[2]=3`, `nums[1]=3` → `3 == 3`, add 3 to answer, skip duplicates → `i=3`, loop ends

**Output:** `[3]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Dominated by the sort; the scan is O(n) |
| **Space** | O(1) | Only a few integer variables used (ignoring output) |
