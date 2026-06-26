# Problem 540 - Single Element in a Sorted Array

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/single-element-in-a-sorted-array/
**Language:** C++

---

## Problem Statement
Given a sorted array where every element appears exactly twice except for one element that appears only once, find and return that single element. You must solve it in O(log n) time and O(1) space.

## Approach: Binary Search on Index Parity

The key insight is based on index parity. In the sorted array before the single element, each pair starts at an even index (0, 2, 4...). After the single element, pairs start at odd indices. So if we look at index `mid`:
- If `mid` is even and `a[mid] == a[mid+1]`, the single element is to the right → search right half.
- If `mid` is odd and `a[mid] == a[mid-1]`, the single element is to the right → search right half.
- Otherwise, search left half (single element is at or before mid).

## Code Walkthrough (Step by Step)

1. **Edge case:** If `n == 1`, the only element is the single one — return it.

2. **Binary search** with `st = 0` and `end = n-1`.

3. **Compute `mid`** each iteration.

4. **Boundary checks first:**
   - If `mid == 0` and `a[0] != a[1]`: `a[0]` is the single element.
   - If `mid == n-1` and `a[n-1] != a[n-2]`: `a[n-1]` is the single element.

5. **Mid is the single element check:** If `a[mid]` differs from both neighbors, return `a[mid]`.

6. **Parity check to narrow search:**
   - If `(mid % 2 == 0 && a[mid] == a[mid+1])` OR `(mid % 2 == 1 && a[mid] == a[mid-1])`: single element is to the RIGHT → `st = mid + 1`.
   - Else: single element is to the LEFT → `end = mid - 1`.

## Dry Run

**Example Input:** `a = [1, 1, 2, 3, 3, 4, 4, 8, 8]`, n=9

- st=0, end=8, mid=4 → a[4]=3, a[3]=3, a[5]=4. mid=4 (even), a[4]==a[3] but a[4]!=a[5]. Condition: mid%2==0 AND a[mid]==a[mid+1]? 3!=4 → false. mid%2==1? 4%2==0, no. So check else: end=3.
- Wait, mid=4 is even: a[4]=3, a[mid+1]=a[5]=4. 3!=4. So neither parity condition holds → end=mid-1=3.
- st=0, end=3, mid=1. a[1]=1, a[0]=1, a[2]=2. mid%2==1 AND a[1]==a[0]: YES → st=2.
- st=2, end=3, mid=2. a[2]=2, a[1]=1, a[3]=3. a[2]!=a[1] and a[2]!=a[3] → return a[2]=2.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Binary search halves the search space each iteration |
| **Space** | O(1) | Only index variables used |
