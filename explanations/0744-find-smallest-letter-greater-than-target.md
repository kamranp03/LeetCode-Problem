# Problem 744 - Find Smallest Letter Greater Than Target

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/find-smallest-letter-greater-than-target/
**Language:** C++

---

## Problem Statement
Given a sorted array of characters `letters` and a character `target`, return the smallest character in `letters` that is strictly greater than `target`. The letters wrap around — if no letter is greater, return the first letter in the array.

## Approach: Binary Search for Upper Bound

The key insight is that since `letters` is sorted, we can binary search for the leftmost character strictly greater than `target`. We initialize `ans = letters[0]` to handle the wrap-around case. During binary search, whenever we find `letters[mid] > target`, we update `ans` and search left for a potentially smaller valid answer. If `letters[mid] <= target`, we search right.

## Code Walkthrough (Step by Step)

1. **Initialize:** `ans = letters[0]` — this handles the wrap-around case where all letters are <= target, returning the first (smallest) letter.

2. **Binary search** with `low = 0`, `high = n - 1`.

3. **Compute `mid = low + (high - low) / 2`.**

4. **If `letters[mid] > target`:**
   - This is a candidate answer → save `ans = letters[mid]`.
   - Search left half for a smaller valid letter: `high = mid - 1`.

5. **Else (`letters[mid] <= target`):**
   - This letter is too small → search right: `low = mid + 1`.

6. **Return `ans`** — the smallest letter strictly greater than target (or `letters[0]` if none found).

## Dry Run

**Example Input:** `letters = ['c', 'f', 'j']`, `target = 'c'`

n=3, ans='c' (initial), low=0, high=2

- mid=1: letters[1]='f' > 'c' → ans='f', high=0
- mid=0: letters[0]='c' > 'c'? No (not strictly greater) → low=1
- low > high → stop

**Output:** `'f'`

**Example Input:** `letters = ['c', 'f', 'j']`, `target = 'j'`

n=3, ans='c', low=0, high=2

- mid=1: 'f' > 'j'? No → low=2
- mid=2: 'j' > 'j'? No → low=3
- low > high → stop

ans stays 'c' (wrap-around)

**Output:** `'c'`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(log n) | Binary search halves the search space each iteration |
| **Space** | O(1) | Only index variables and one answer character |
