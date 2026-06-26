# Problem 977 - Squares of a Sorted Array

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/squares-of-a-sorted-array/
**Language:** C++

---

## Problem Statement
Given an integer array sorted in non-decreasing order (may contain negative numbers), return a new array of the squares of each number, also sorted in non-decreasing order.

## Approach: Split, Square, and Merge

The solution splits the array into negative and positive parts, squares each part, reverses the negative part (so negatives squared are in ascending order), then merges the two sorted arrays using the standard two-pointer merge. This avoids sorting after squaring.

## Code Walkthrough (Step by Step)

1. **Split:** Separate elements into `pos` (>= 0) and `neg` (< 0).

2. **Edge cases:**
   - If `neg` is empty: square all elements in-place and return.
   - If `pos` is empty: square all elements, reverse (since negatives sorted ascending get squared into descending order), and return.

3. **Square both arrays:**
   - Square all elements in `pos` (already ascending when squared).
   - Square all elements in `neg` and reverse (neg sorted descending by value → ascending after squaring).

4. **Merge:** Use two pointers `i` (for `pos`) and `j` (for reversed `neg`). At each step, pick the smaller squared value and advance that pointer.

5. **Drain remaining** elements from either array.

6. **Return** the merged result `res`.

## Dry Run

**Example Input:** `nums = [-4, -1, 0, 3, 10]`

- neg = [-4, -1], pos = [0, 3, 10]
- pos squared: [0, 9, 100]
- neg squared: [16, 1], reversed: [1, 16]
- Merge [0,9,100] and [1,16]:
  - 0<1 → [0], i=1
  - 9>1 → [0,1], j=1
  - 9<16 → [0,1,9], i=2
  - 100>16 → [0,1,9,16], j=2 (done)
  - Drain pos: [0,1,9,16,100]

**Output:** `[0, 1, 9, 16, 100]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N) | One pass to split, one pass to square, one pass to merge |
| **Space** | O(N) | pos, neg, and result arrays total O(N) |
