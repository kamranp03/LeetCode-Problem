# Problem 3510 - Minimum Pair Removal to Sort Array II

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/
**Language:** C++

---

## Problem Statement

Same as Problem 3507 but for large arrays — repeatedly merge the adjacent pair with the minimum sum until the array is non-decreasing. Return the minimum number of merge operations needed.

## Approach: Doubly Linked List + Ordered Set

The brute force O(n^3) approach is too slow for large inputs. The optimized solution uses:
- A **doubly linked list** (via arrays `nextIndex` and `prevIndex`) to efficiently remove merged elements without shifting.
- A **sorted set** `set<pair<ll, int>>` keyed by (pairSum, leftIndex) to always find the minimum-sum adjacent pair in O(log n).
- A **`badPairs` counter** tracking how many adjacent pairs are currently in decreasing order; when it hits 0, we're done.

## Code Walkthrough (Step by Step)

1. **Initialize** the linked list, `badPairs` count, and the min-pair set with all adjacent pairs.
2. **While `badPairs > 0`:**
   a. Extract the pair `(first, second)` with minimum sum from the set.
   b. **Adjust `badPairs`:** remove counts for old pairs (first_left→first, first→second, second→second_right).
   c. **Remove stale entries** from the set for pairs involving the merged elements.
   d. **Merge:** `temp[first] += temp[second]`, update linked list pointers.
   e. **Re-add new pairs** (first_left→first and first→second_right) to the set, updating `badPairs`.
   f. Increment `operations`.
3. **Return** `operations`.

## Dry Run

**Example Input:** `nums = [5, 2, 3, 1]`

- bad pairs: (5,2) and (3,1) → badPairs=2.
- Set: {(4,2), (7,0), (5,1)}. Min pair: sum=4 at idx=2 (pair 3,1).
- Merge idx 2 and 3: temp=[5,2,4]. Update bad: remove (3,1) bad→1, (2,3) was good. New pair (2,4) is good. badPairs=1.
- Min pair now: (7,0) → pair (5,2). Merge: temp=[5,6]. badPairs=0. operations=2.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Each of at most n merges does O(log n) set operations |
| **Space** | O(n) | Linked list arrays and pair set |
