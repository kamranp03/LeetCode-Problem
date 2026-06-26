# Problem 3719 - Longest Balanced Subarray I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/longest-balanced-subarray-i/
**Language:** C++

---

## Problem Statement

Given an integer array `nums`, find the length of the longest subarray where the number of distinct even values equals the number of distinct odd values. A "balanced" subarray has equal counts of distinct even and distinct odd elements.

## Approach: Brute Force with Distinct Sets

For the Easy version with small constraints, try every subarray `nums[i..j]`. Maintain two sets — one for even values seen, one for odd values seen. A subarray is balanced when `even.size() == odd.size()`.

Note: There is a naming quirk in the code — `odd` set stores even values (nums[j]%2==0) and `even` set stores odd values. Despite the variable naming swap, the logic is the same: count distinct elements of each parity and compare the set sizes.

## Code Walkthrough (Step by Step)

1. **Outer loop `i`:** starting position.
2. **Inner loop `j`:** for each `nums[j]`:
   - If `nums[j] % 2 == 0` → insert into `odd` set (tracks distinct even values).
   - If `nums[j] % 2 != 0` → insert into `even` set (tracks distinct odd values).
   - If `odd.size() == even.size()` → update `maxlen`.
3. **Return** `maxlen`.

## Dry Run

**Example Input:** `nums = [1, 2, 3, 4]`

- i=0:
  - j=0: val=1 (odd), even={1}. sizes 0!=1. No.
  - j=1: val=2 (even), odd={2}. sizes 1==1. maxlen=2.
  - j=2: val=3 (odd), even={1,3}. sizes 1!=2. No.
  - j=3: val=4 (even), odd={2,4}. sizes 2==2. maxlen=4.

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n^2 log n) | O(n^2) substrings, each set insert is O(log n) |
| **Space** | O(n) | Two sets per starting position |
