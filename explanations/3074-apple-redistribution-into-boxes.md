# Problem 3074 - Apple Redistribution into Boxes

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/apple-redistribution-into-boxes/
**Language:** C++

---

## Problem Statement

You have packs of apples where `apple[i]` is the number of apples in the i-th pack. You also have boxes with capacities given in `capacity`. You must put all the apples into the minimum number of boxes. Each box can only hold up to its capacity. Return the minimum number of boxes needed.

## Approach: Greedy - Sort Boxes Descending and Fill Largest First

To minimize the number of boxes used, we should fill the largest boxes first. By sorting `capacity` in descending order and greedily filling each box until we've placed all apples, we use the fewest boxes possible.

## Code Walkthrough (Step by Step)

1. **Sum all apples:** Compute `total` by summing all values in `apple`.

2. **Sort `capacity` descending:** Largest boxes come first.

3. **Greedily fill boxes:** Maintain `used` (apples placed so far) and `count` (boxes used). For each box capacity `c`, add `c` to `used` and increment `count`. Stop as soon as `used >= total`.

4. **Return** `count`.

## Dry Run

**Example Input:** `apple = [1, 3, 2]`, `capacity = [4, 3, 1, 5, 2]`

- total = 1 + 3 + 2 = 6
- Sorted capacity descending: [5, 4, 3, 2, 1]
- Fill box 1 (cap=5): used=5, count=1. 5 < 6, continue.
- Fill box 2 (cap=4): used=9, count=2. 9 >= 6, stop.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting the capacity array |
| **Space** | O(1) | Only scalar variables beyond the sorted array |
