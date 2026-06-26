# Problem 349 - Intersection of Two Arrays

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/intersection-of-two-arrays/
**Language:** C++

---

## Problem Statement
Given two integer arrays `nums1` and `nums2`, return an array of their intersection — elements that appear in both arrays. Each element in the result must be unique (no duplicates in the output), and the result can be in any order.

## Approach: Hash Set Lookup

The key insight is that set membership lookup is O(1) on average. We put all elements of `nums1` into a hash set (`seen`). Then we scan `nums2` and for each element found in `seen`, we add it to a result set (`res`). Using a result set automatically deduplicates the output.

## Code Walkthrough (Step by Step)

1. **Build `seen` set:** Initialize `seen` from `nums1` using its begin/end iterators. This stores all unique values of `nums1`.

2. **Scan `nums2`:** For each `num` in `nums2`, check `seen.count(num)` — if non-zero (element exists in nums1), insert it into the result set `res`.

3. **Using `res` as a set:** This ensures that even if the same value appears multiple times in `nums2`, it is only added once to the output.

4. **Convert to vector:** Return `vector<int>(res.begin(), res.end())`.

## Dry Run

**Example Input:** `nums1 = [4, 9, 5]`, `nums2 = [9, 4, 9, 8, 4]`

`seen = {4, 9, 5}`

Scan nums2:
- 9: in seen → res = {9}
- 4: in seen → res = {9, 4}
- 9: in seen → res = {9, 4} (already there, set deduplicates)
- 8: not in seen → skip
- 4: in seen → res = {9, 4} (already there)

Convert res to vector: `[9, 4]` (order may vary)

**Output:** `[9, 4]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m + n) | O(m) to build seen set, O(n) to scan nums2 |
| **Space** | O(m + k) | seen holds up to m elements; res holds up to k unique intersection elements |
