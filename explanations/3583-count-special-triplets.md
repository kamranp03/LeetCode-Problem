# Problem 3583 - Count Special Triplets

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-special-triplets/
**Language:** C++

---

## Problem Statement

Count the number of "special" triplets `(i, j, k)` with `i < j < k` in array `nums` such that `nums[j] == 2 * nums[i]` and `nums[j] == 2 * nums[k]` (equivalently, `nums[i] == nums[k] == nums[j] / 2`). Return the count modulo `10^9 + 7`.

## Approach: One-Pass with Two Hash Maps

The key insight: for the middle element at index `j` with value `v`, we need:
- `i[v/2]`: count of elements equal to `v/2` seen before `j` (left side).
- `j[v]`: count of pairs where a left element matches, i.e., prefix that can pair with future right elements.

We sweep left to right, maintaining:
- `i[num]`: how many times `num` appeared so far.
- `j[num]`: how many valid (i, j) pairs ending with value `num` have been seen.

When we see element `num`:
1. If `num` is even, add `j[num/2]` to result (num is the middle of a valid triplet with a right element).
2. Update `j[num] += i[num*2]` (num can be the right element for any previous middle of value `num*2`).
3. Increment `i[num]`.

## Dry Run

**Example Input:** `nums = [1, 2, 1, 4, 2]`

- num=1: even? no. j[1]+=i[2]=0 → j[1]=0. i[1]=1.
- num=2: even, res+=j[1]=0. j[2]+=i[4]=0 → j[2]=0. i[2]=1.
- num=1: even? no. j[1]+=i[2]=1 → j[1]=1. i[1]=2.
- num=4: even, res+=j[2]=0. j[4]+=i[8]=0. i[4]=1.
- num=2: even, res+=j[1]=1 → res=1. j[2]+=i[4]=1 → j[2]=1. i[2]=2.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass with O(1) hash map lookups |
| **Space** | O(n) | Two hash maps storing element frequencies |
